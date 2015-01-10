(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-lambda "loli-lambda")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defvar *TOP-ENV* loli-nil "The TOP-LEVEL Environment of LoLi")

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
       (loli-cons (to-loli-sym '=)
                  loli-num-eq-f)
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

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '>)
                  loli-num-greater-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym '<)
                  loli-num-less-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'and)
                  loli-and-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'or)
                  loli-or-f)
       *TOP-ENV*))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'not)
                  loli-not-f)
       *TOP-ENV*))

(defun loli-def (name value)
  (if (equalp (typed-lookup name (loli-obj-loli-type value))
              'NO-MATCHING-FOUND)
      (setf *TOP-ENV* (loli-cons (loli-cons name value) *TOP-ENV*))
      (format *standard-output* "Symbol bind already exists!~%")))

(defconstant loli-def-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-obj* :arg-type *type-obj*
                          :arity 2 :cl-fn #'loli-def)))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'def)
                  loli-def-f)
       *TOP-ENV*))

(defun loli-set (name value)
  (if (equalp (typed-lookup name (loli-obj-loli-type value))
              'NO-MATCHING-FOUND)
      (format *standard-output*
              "Error: the symbol ~A is not bound to the type ~A~%"
              (loli-obj-value name)
              (loli-type-class-id (loli-obj-loli-type value)))
      (setf (typed-lookup name (loli-obj-loli-type value))
            value)))

(defconstant loli-set-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-obj* :arg-type *type-obj*
                          :arity 2 :cl-fn #'loli-set)
   '()))

(setf *TOP-ENV*
      (loli-cons
       (loli-cons (to-loli-sym 'set!)
                  loli-set-f)
       *TOP-ENV*))

(provide 'loli-env)
