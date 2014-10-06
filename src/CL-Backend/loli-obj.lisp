(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defstruct loli-obj
  value
  (loli-type *type-obj* :type loli-type-class)
  env)

(defconstant loli-nil
  (make-loli-obj
   :value 'nil
   :loli-type *type-sym*
   :env '()))

(defconstant loli-t
  (make-loli-obj
   :value 't
   :loli-type *type-sym*
   :env '()))

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
