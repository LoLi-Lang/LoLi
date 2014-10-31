(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")

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

(defun tokenize (str)
  (loop for i = 0 then (1+ j)
     as j = (position #\Space str :start i)
     collect (subseq str i j)
     while j))

(defun loli-parse (str &optional (env '()))
  (let* ((trimed (string-trim '(#\Space #\Tab #\Newline) str))
         (token-lst (remove-if #'(lambda (x) (equalp x ""))
                               (tokenize trimed))))
    token-lst))

(defun loli-eval-sym (sym &optional (env '()))
  (cond
    ((equalp (loli-obj-value sym) 'nil)
     loli-nil)
    ((equalp (loli-obj-value sym) 't)
     loli-t)
    ((null env)
     )
    )
  )

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
     'FUNCTION)
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


(defun rep (top-env type-env &optional (in-stream *standard-input*))
  (loli-output
   (loli-simple-eval
    (loli-parse
     (loli-get-input in-stream))
    top-env)))

(defun test-rep (&optional (in-stream *standard-input*))
  (loli-parse
   (loli-get-input in-stream)))

(provide 'loli-repl)
