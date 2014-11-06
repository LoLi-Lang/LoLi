(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-repl "loli-repl")
(require 'loli-type-class "loli-typeclass")
(require 'loli-prim "loli-prim")
(require 'loli-type-class "loli-typeclass")

(defun loli-read-list (lst &optional (env '()))
  (loli-cons (loli-read-single-obj (car lst) env)
             (loli-read-single-obj (cdr lst) env)))

(defun loli-read-single-obj (cl-obj &optional (env '()))
  (if (null cl-obj)
      loli-nil
      (typecase cl-obj
        (integer (to-loli-int cl-obj env))
        (float (to-loli-flt cl-obj env))
        (string (to-loli-string cl-obj env))
        (character (to-loli-char cl-obj env))
        (keyword (to-loli-key cl-obj env))
        (list (loli-read-list cl-obj env))
        (symbol (to-loli-sym cl-obj env)))))

(defun loli-read-from-string (str &optional (env '()))
  (loli-read-single-obj (read-from-string str) env))
