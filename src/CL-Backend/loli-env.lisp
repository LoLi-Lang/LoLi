(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defparameter *TOP-ENV* nil "The TOP-LEVEL Environment of LoLi")

(defun loli-lookup (sym &optional (env *TOP-ENV*))
  (if (equal (loli-obj-loli-type env) *type-cons*)
      (if (equalp (loli-obj-value sym)
                  (loli-obj-value (loli-head (loli-head env))))
          (loli-cons (loli-tail (loli-head env))
                     (loli-lookup sym
                                  (loli-tail env)))
          (loli-lookup sym
                       (loli-tail env)))
      loli-nil))

(provide 'loli-env)
