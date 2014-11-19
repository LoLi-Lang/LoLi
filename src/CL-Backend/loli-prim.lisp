(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defstruct loli-cons-struct
  (head loli-nil :type loli-obj)
  (tail loli-nil :type loli-obj))

(defun loli-cons (head &optional (tail loli-nil))
  (to-loli-cons
   (make-loli-cons-struct :head head :tail tail) '()))

(defun loli-head (o)
  (if (loli-obj-p o)
      (if (loli-cons-struct-p (loli-obj-value o))
          (loli-cons-struct-head (loli-obj-value o))
          'ERR-NOT-LOLI-CONS)
      'ERR-NOT-LOLI-OBJ))

(defun loli-tail (o)
  (if (loli-obj-p o)
      (if (loli-cons-struct-p (loli-obj-value o))
          (loli-cons-struct-tail (loli-obj-value o))
          'ERR-NOT-LOLI-CONS)
      'ERR-NOT-LOLI-OBJ))

(defstruct loli-proc-struct
  (return-type *type-obj* :type loli-type-class)
  (arg-type *type-obj* :type loli-type-class)
  (arity 0 :type integer)
  (cl-fn nil :type function))

(defstruct loli-lambda-struct
  (return-type *type-obj* :type loli-type-class)
  (arg-lst loli-nil :type loli-obj)
  (arg-types '() :type list)
  (exp loli-nil :type loli-obj))

(defconstant loli-cons-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-cons* :arg-type *type-obj* :arity 2 :cl-fn #'loli-cons)
   '()))

(defun loli-add (a b)
  (if (or (sub-type-p (loli-obj-loli-type a) *type-flt*)
          (sub-type-p (loli-obj-loli-type b) *type-flt*))
      (to-loli-flt
       (+ (loli-obj-value a) (loli-obj-value b))
       '())
      (to-loli-int
       (+ (loli-obj-value a) (loli-obj-value b))
       '())))

(defconstant loli-add-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-num* :arg-type *type-num* :arity 2 :cl-fn #'loli-add)
   '()))

(provide 'loli-prim)
