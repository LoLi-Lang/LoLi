(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-type-class "loli-typeclass")
(require 'loli-prim "loli-prim")
(require 'loli-base "loli-base")

(in-package #:loli)

;;LoLi's Lambda:
;; (\\ :RETURN-TYPE (ARG-LST) EXP)

(defstruct loli-lambda-struct
  (return-type *type-obj* :type loli-type-class)
  (arg-lst loli-nil :type loli-obj)
  (arg-types '() :type list)
  (exp loli-nil :type loli-obj))

(defun arg-lst-to-sym-lst (arg-lst)
  (if (equalp (loli-obj-value arg-lst)
              'nil)
      loli-nil
      (if (sub-type-p (loli-obj-loli-type (loli-head arg-lst))
                      *type-cons*)
          (loli-cons (loli-head (loli-head arg-lst))
                     (arg-lst-to-sym-lst (loli-tail arg-lst)))
          (loli-cons (loli-head arg-lst)
                     (arg-lst-to-sym-lst (loli-tail arg-lst))))))

(defun arg-lst-to-type-lst (arg-lst)
  (if (equalp (loli-obj-value arg-lst)
              'nil)
      nil
      (if (sub-type-p (loli-obj-loli-type (loli-head arg-lst))
                      *type-cons*)
          (cons (loli-head (loli-tail (loli-head arg-lst)))
                (arg-lst-to-type-lst (loli-tail arg-lst)))
          (cons (to-loli-key :obj)
                (arg-lst-to-type-lst (loli-tail arg-lst))))))

(defun lookup-type-env (key &optional (env *TYPE-ENV*))
  (if (null env)
      *type-obj*
      (if (equalp (loli-obj-value key)
                  (loli-type-class-id (car env)))
          (car env)
          (lookup-type-env key (cdr env)))))

(defun loli-lambda (return-type arg-lst exp)
  (to-loli-lambda
   (make-loli-lambda-struct :return-type (lookup-type-env return-type)
                            :arg-lst (arg-lst-to-sym-lst arg-lst)
                            :arg-types (arg-lst-to-type-lst arg-lst)
                            :exp exp)
  '()))

(defconstant loli-lambda-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-lambda*
                          :arg-type *type-obj*
                          :arity 3
                          :cl-fn #'loli-lambda)
   '()))

(provide 'loli-lambda)
