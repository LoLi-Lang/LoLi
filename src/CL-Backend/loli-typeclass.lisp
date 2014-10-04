(require 'loli-package "package")

(in-package #:loli)

(defstruct loli-type-class
  name
  id
  parent)

(defvar *type-obj* (make-loli-type-class :name "Object" :id :OBJ :parent nil))
(defvar *type-num* (make-loli-type-class :name "Number" :id :NUM :parent *type-obj*))
(defvar *type-int* (make-loli-type-class :name "Integer" :id :INT :parent *type-num*))
(defvar *type-flt* (make-loli-type-class :name "Float" :id :FLT :parent *type-num*))

(defun is-from (type-a type-b)
  (if (equal type-b *type-obj*)
      t
      (if (equal type-a *type-obj*)
          nil
          (if (equal type-a type-b)
              t
              (is-from (loli-type-class-parent type-a) type-b)))))

(provide 'loli-type-class)
