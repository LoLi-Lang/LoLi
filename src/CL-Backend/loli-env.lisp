(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defparameter *TOP-ENV* loli-nil "The TOP-LEVEL Environment of LoLi")

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

;;INIT TOP ENV
(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym "nil")
                  loli-nil)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym "t")
                  loli-t)
       *TOP-ENV*))

(provide 'loli-env)
