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
          (format t "~A is not loli-cons" o))
      'ERR-NOT-LOLI-OBJ))

(defun loli-tail (o)
  (if (loli-obj-p o)
      (if (loli-cons-struct-p (loli-obj-value o))
          (loli-cons-struct-tail (loli-obj-value o))
          (format t "~A is not loli-cons" o))
      'ERR-NOT-LOLI-OBJ))

(defstruct loli-proc-struct
  (return-type *type-obj* :type loli-type-class)
  (arg-type *type-obj* :type loli-type-class)
  (arity 0 :type integer)
  (cl-fn nil :type function))

(defun loli-num-eq (a b)
  (if (and (sub-type-p (loli-obj-loli-type a) *type-num*)
           (sub-type-p (loli-obj-loli-type b) *type-num*))
    (if (= (loli-obj-value a) (loli-obj-value b))
        loli-true
        loli-false)))

(defun loli-add (a b)
  (if (or (sub-type-p (loli-obj-loli-type a) *type-flt*)
          (sub-type-p (loli-obj-loli-type b) *type-flt*))
      (to-loli-flt
       (+ (loli-obj-value a) (loli-obj-value b))
       '())
      (to-loli-int
       (+ (loli-obj-value a) (loli-obj-value b))
       '())))

(defun loli-sub (a b)
  (if (or (sub-type-p (loli-obj-loli-type a) *type-flt*)
          (sub-type-p (loli-obj-loli-type b) *type-flt*))
      (to-loli-flt
       (- (loli-obj-value a) (loli-obj-value b))
       '())
      (to-loli-int
       (- (loli-obj-value a) (loli-obj-value b))
       '())))

(defun loli-mul (a b)
  (if (or (sub-type-p (loli-obj-loli-type a) *type-flt*)
          (sub-type-p (loli-obj-loli-type b) *type-flt*))
      (to-loli-flt
       (* (loli-obj-value a) (loli-obj-value b))
       '())
      (to-loli-int
       (* (loli-obj-value a) (loli-obj-value b))
       '())))

(defun loli-div (a b)
  (if (or (sub-type-p (loli-obj-loli-type a) *type-flt*)
          (sub-type-p (loli-obj-loli-type b) *type-flt*))
      (to-loli-flt
       (/ (loli-obj-value a) (loli-obj-value b))
       '())
      (to-loli-int
       (/ (loli-obj-value a) (loli-obj-value b))
       '())))

(defconstant loli-add-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-num* :arg-type *type-num*
                          :arity 2 :cl-fn #'loli-add)
   '()))

(defconstant loli-sub-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-num* :arg-type *type-num*
                          :arity 2 :cl-fn #'loli-sub)
   '()))

(defconstant loli-mul-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-num* :arg-type *type-num*
                          :arity 2 :cl-fn #'loli-mul)
   '()))

(defconstant loli-div-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-num* :arg-type *type-num*
                          :arity 2 :cl-fn #'loli-div)
   '()))

(defconstant loli-quit-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-obj* :arg-type *type-obj*
                          :arity 0 :cl-fn #'sb-ext:exit)
   '()))

(defconstant loli-cons-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-cons* :arg-type *type-obj*
                          :arity 2 :cl-fn #'loli-cons)
   '()))

(defconstant loli-head-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-obj* :arg-type *type-cons*
                          :arity 1 :cl-fn #'loli-head)
   '()))

(defconstant loli-tail-f
  (to-loli-proc
   (make-loli-proc-struct :return-type *type-obj* :arg-type *type-cons*
                          :arity 1 :cl-fn #'loli-tail)
   '()))

(defconstant loli-num-eq-f
             (to-loli-proc
               (make-loli-proc-struct :return-type *type-bool* :arg-type *type-num* :arity 2 :cl-fn #'loli-num-eq)
               '()))

(provide 'loli-prim)
