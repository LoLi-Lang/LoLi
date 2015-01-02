(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-lambda "loli-lambda")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defparameter *TOP-ENV* loli-nil "The TOP-LEVEL Environment of LoLi")

(defun loli-lookup (sym &optional (env *TOP-ENV*))
  (if (sub-type-p (loli-obj-loli-type env) *type-cons*)
      (if (equalp (loli-obj-value sym)
                  (loli-obj-value (loli-head (loli-head env))))
          (loli-cons (loli-tail (loli-head env))
                     (loli-lookup sym
                                  (loli-tail env)))
          (loli-lookup sym
                       (loli-tail env)))
      loli-nil))

(defun get-typed (type loli-c)
  (if (equal (loli-obj-loli-type loli-c) *type-cons*)
      (if (sub-type-p (loli-obj-loli-type
                       (loli-head loli-c))
                      type)
          (loli-head loli-c)
          (get-typed type (loli-tail loli-c)))
      'NO-MATCHING-FOUND))

(defun typed-lookup (sym &optional (type *type-obj*) (env *TOP-ENV*))
  (get-typed type
             (loli-lookup sym env)))

;;INIT TOP ENV
(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'nil)
                  loli-nil)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 't)
                  loli-t)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'aa)
                  (to-loli-int 123))
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '+)
                  loli-add-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '-)
                  loli-sub-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '*)
                  loli-mul-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '/)
                  loli-div-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'quit)
                  loli-quit-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'exit)
                  loli-quit-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'cons)
                  loli-cons-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'head)
                  loli-head-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'tail)
                  loli-tail-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '\\)
                  loli-lambda-f)
       *TOP-ENV*))

(provide 'loli-env)
