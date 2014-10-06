(require 'loli-package "package")
(require 'loli-typeclass "loli-typeclass")
(require 'loli-obj "loli-obj")

(in-package #:loli)

(defun loli-simple-eval (obj)
  (cond
    ((sub-type-p (loli-obj-loli-type obj)
              *type-fn*)
     'FUNCTION)
    ((sub-type-p (loli-obj-loli-type obj)
              *type-cons*)
     'CONS)
    (t (loli-obj-value obj))))

(provide 'loli-eval)
