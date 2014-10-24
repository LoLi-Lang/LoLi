(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defstruct loli-obj
  value
  (loli-type *type-obj* :type loli-type-class)
  env)

(defun to-loli-sym (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-sym*
   :env env))

(defun to-loli-fn (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-fn*
   :env env))

(defun to-loli-obj (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-obj*
   :env env))

(defun to-loli-flt (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-flt*
   :env env))

(defun to-loli-int (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-int*
   :env env))

(defun to-loli-key (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-key*
   :env env))

(defun to-loli-num (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-num*
   :env env))

(defun to-loli-bool (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-bool*
   :env env))

(defun to-loli-char (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-char*
   :env env))

(defun to-loli-string (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-string*
   :env env))

(defun to-loli-cons (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-cons*
   :env env))

(defun to-loli-lambda (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-lambda*
   :env env))

(defun to-loli-proc (value &optional (env '()))
  (make-loli-obj
   :value value
   :loli-type *type-proc*
   :env env))

(defconstant loli-nil
  (to-loli-sym 'nil '()))

(defconstant loli-t
  (to-loli-sym 't '()))

(defconstant loli-true
  (to-loli-bool :true '()))

(defconstant loli-false
  (to-loli-bool :false '()))

(provide 'loli-obj)
