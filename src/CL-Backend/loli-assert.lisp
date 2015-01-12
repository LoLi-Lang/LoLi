(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-type-class "loli-typeclass")
(require 'loli-prim "loli-prim")
(require 'loli-env "loli-env")

(in-package #:loli)

(defun type-id-list-to-typed-list (lst &optional (env *TOP-ENV*))
  (if (equalp (loli-head lst) loli-nil)
      loli-nil
      (loli-cons
       (loli-cons
        (loli-head (loli-head lst))
        (typed-lookup (loli-head (loli-head lst))
                      (type-id-to-type (loli-head (loli-tail (loli-head lst))))
                      env))
       (type-id-list-to-typed-list (loli-tail lst) env))))

(defun loli-assert
    (lst exp)


  )

(provide 'loli-assert)
