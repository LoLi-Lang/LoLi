(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-type-class "loli-typeclass")
(require 'loli-env "loli-env")
(require 'loli-read "loli-read")

(in-package #:loli)

(defun loli-validate-input (str &optional (p 0) (q t))
  (format *standard-output* "~A~%" str)
  (loop for c across str
     do
       (cond
         ((equal c #\()
          (if q
              (setq p (1+ p))))
         ((equal c #\))
          (if q
              (if (>= p 1)
                  (setq p (1- p))
                  (return-from loli-validate-input 'UNMATCHED-PARENTHESIS))))
         ((equal c #\")
          (setq q (not q)))))
  (return-from loli-validate-input (and q (= 0 p))))

(defun loli-get-input (&optional (in-stream *standard-input*))
  (let* ((tmp (read-line in-stream))
         (stat (loli-validate-input tmp)))
    (if (equal stat 'UNMATCHED-PARENTHESIS)
        (return-from loli-get-input 'UNIMPLEMENTED-ERROR)
        (loop while (not stat)
           do (setq tmp (concatenate 'string tmp (read-line in-stream))
                    stat (loli-validate-input tmp))))
    (return-from loli-get-input tmp)))

(define-condition loli-error (error)
  ())

(defun loli-get-new-value ()
  (format *standard-output* "Enter a new value: ")
  (multiple-value-list (loli-read-from-string (loli-get-input))))

(define-condition loli-err-symbol-not-bound (loli-error)
  ((err-obj :initarg :obj :reader err-obj))
  (:report (lambda (condition stream)
             (format stream "Error: Symbol ~A is not bound"
                     (loli-obj-value (err-obj condition))))))

(defmacro loli-symbol-not-bound-debug (obj)
  `(restart-case
       (error 'loli-err-symbol-not-bound :obj ,obj)
     (use-new-value (new-value)
       :report "Enter a new value"
       :interactive loli-get-new-value
       (setq ,obj new-value))))

(defun loli-eval-sym (sym &optional (env '()))
  (cond
    ((equalp (loli-obj-value sym) 'nil)
     loli-nil)
    ((equalp (loli-obj-value sym) 't)
     loli-t)
    ((and (null env) (null (loli-obj-env sym)))
     (loli-symbol-not-bound-debug sym))
    ((not (null (loli-obj-env sym)))
     (let ((r (loli-lookup sym (loli-obj-env sym))))
       (if (not (equal r loli-nil))
           r)))
    ((not (null env))
     (let ((r (loli-lookup sym env)))
       (if (not (equal r loli-nil))
           r)))
    (t
     (loli-symbol-not-bound-debug sym))))

(defun loli-simple-eval (obj &optional (env '()))
  (cond
    ((sub-type-p (loli-obj-loli-type obj)
                 *type-sym*)
     (loli-eval-sym obj env))
    ((sub-type-p (loli-obj-loli-type obj)
                 *type-cons*)
     'CONS)
    (t obj)))

(defun loli-output (obj &optional (output-stream *standard-output*))
  (cond
    ((sub-type-p (loli-obj-loli-type obj)
                 *type-fn*)
     (cond
       ((sub-type-p (loli-obj-loli-type obj)
                    *type-proc*)
        (format output-stream "<Primitive Procedure ~{~A~^,~} => ~A>"
                (make-list
                 (loli-proc-struct-arity (loli-obj-value obj))
                 :initial-element
                 (loli-type-class-id
                  (loli-proc-struct-arg-type (loli-obj-value obj))))
                (loli-type-class-id
                 (loli-proc-struct-return-type (loli-obj-value obj)))))
       ((sub-type-p (loli-obj-loli-type obj)
                    *type-lambda*)
        (format output-stream "<Lambda Expression ~{~A~^,~} => ~A>"
                (loop for a in (loli-lambda-struct-arg-types (loli-obj-value obj))
                   collect (loli-type-class-id a))
                (loli-type-class-id
                 (loli-lambda-struct-return-type (loli-obj-value obj)))))
       (t
        (format output-stream "<Unknown Function>"))))
    ((sub-type-p (loli-obj-loli-type obj)
                 *type-cons*)
     (format output-stream "(")
     (loli-output (loli-head obj) output-stream)
     (if (sub-type-p (loli-obj-loli-type (loli-tail obj))
                     *type-cons*)
         (progn
           (format output-stream " ")
           (loli-output (loli-tail obj) output-stream)
           (format output-stream ")"))
         (progn
           (format output-stream " . ")
           (loli-output (loli-tail obj) output-stream)
           (format output-stream ")"))))
    (t
     (format output-stream "~A" (loli-obj-value obj)))))


(defmacro  loli-rep (&optional (in-stream *standard-input*) (env *TOP-ENV*) (out-stream *standard-output*))
  (let ((o (loli-simple-eval (loli-read-from-string
                              (loli-get-input in-stream)) env)))
    o))

(provide 'loli-repl)
