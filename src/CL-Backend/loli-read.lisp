(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defun loli-read-list (lst &optional (env '()))
  (loli-cons (loli-read-single-obj (car lst) env)
             (loli-read-single-obj (cdr lst) env)))

(defun loli-read-single-obj (cl-obj &optional (env '()))
  (if (null cl-obj)
      loli-nil
      (typecase cl-obj
        ((or integer
             bit
             bignum
             fixnum) (to-loli-int cl-obj env))
        ((or float
             single-float
             double-float
             short-float
             long-float) (to-loli-flt cl-obj env))
        (number (to-loli-num cl-obj env))
        (string (to-loli-string cl-obj env))
        (character (to-loli-char cl-obj env))
        (keyword (to-loli-key cl-obj env))
        (list (loli-read-list cl-obj env))
        (symbol (to-loli-sym cl-obj env)))))

(defun loli-read-from-string (str &optional (env '()))
  (loli-read-single-obj (read-from-string str) env))

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

(provide 'loli-read)
