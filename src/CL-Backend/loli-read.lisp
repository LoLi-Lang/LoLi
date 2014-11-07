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
