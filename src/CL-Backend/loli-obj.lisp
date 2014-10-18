(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defstruct loli-obj
  value
  (loli-type *type-obj* :type loli-type-class)
  env)

(defun to-loli-sym (value env)
  (make-loli-obj
   :value value
   :loli-type *type-sym*
   :env env))

(defun to-loli-fn (value env)
  (make-loli-obj
   :value value
   :loli-type *type-fn*
   :env env))

(defun to-loli-obj (value env)
  (make-loli-obj
   :value value
   :loli-type *type-obj*
   :env env))

(defun to-loli-flt (value env)
  (make-loli-obj
   :value value
   :loli-type *type-flt*
   :env env))

(defun to-loli-int (value env)
  (make-loli-obj
   :value value
   :loli-type *type-int*
   :env env))

(defun to-loli-key (value env)
  (make-loli-obj
   :value value
   :loli-type *type-key*
   :env env))

(defun to-loli-num (value env)
  (make-loli-obj
   :value value
   :loli-type *type-num*
   :env env))

(defun to-loli-bool (value env)
  (make-loli-obj
   :value value
   :loli-type *type-bool*
   :env env))

(defun to-loli-char (value env)
  (make-loli-obj
   :value value
   :loli-type *type-char*
   :env env))

(defun to-loli-string (value env)
  (make-loli-obj
   :value value
   :loli-type *type-string*
   :env env))

(defun to-loli-cons (value env)
  (make-loli-obj
   :value value
   :loli-type *type-cons*
   :env env))

(defun to-loli-lambda (value env)
  (make-loli-obj
   :value value
   :loli-type *type-lambda*
   :env env))

(defun to-loli-proc (value env)
  (make-loli-obj
   :value value
   :loli-type *type-proc*
   :env env))

(defconstant loli-nil
  (to-loli-sym 'nil '()))

(defconstant loli-t
  (to-loli-sym 't '()))

(defconstant loli-true
  (make-loli-obj
   :value :true
   :loli-type *type-bool*
   :env '()))

(defconstant loli-false
  (make-loli-obj
   :value :false
   :loli-type *type-bool*
   :env '()))

(provide 'loli-obj)
