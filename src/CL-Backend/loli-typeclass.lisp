(require 'loli-package "package")

(in-package #:loli)

(defstruct loli-type-class
  name
  id
  parent)

(defparameter *type-obj*
  (make-loli-type-class :name "Object" :id :OBJ :parent nil) "The Basic Type of LoLi")
(defparameter *type-num*
  (make-loli-type-class :name "Number" :id :NUM :parent *type-obj*) "The Generic Type Of Number in LoLi")
(defparameter *type-int*
  (make-loli-type-class :name "Integer" :id :INT :parent *type-num*) "The Integer Type in LoLi")
(defparameter *type-flt*
  (make-loli-type-class :name "Float" :id :FLT :parent *type-num*) "The Float Type in LoLi")
(defparameter *type-sym*
  (make-loli-type-class :name "Symbol" :id :SYM :parent *type-obj*) "The Symbol Type in LoLi")
(defparameter *type-key*
  (make-loli-type-class :name "Keyword" :id :KEY :parent *type-obj*) "The Keyword Type in LoLi")
(defparameter *type-cons*
  (make-loli-type-class :name "Cons" :id :CONS :parent *type-obj*) "The CONS (Pair) Type in LoLi")
(defparameter *type-fn*
  (make-loli-type-class :name "Function" :id :FN :parent *type-obj*) "The Generic Type of Function in LoLi")
(defparameter *type-lambda*
  (make-loli-type-class :name "Lambda" :id :LAMBDA :parent *type-fn*) "The Lambda Type in LoLi")
(defparameter *type-proc*
  (make-loli-type-class :name "Procedure" :id :PROC :parent *type-fn*) "The Primitive Procedure Type in LoLi")
(defparameter *type-char*
  (make-loli-type-class :name "Character" :id :CHAR :parent *type-obj*) "The Character Type in LoLi")
(defparameter *type-string*
  (make-loli-type-class :name "String" :id :STR :parent *type-obj*) "The String Type in LoLi")
(defparameter *type-bool*
  (make-loli-type-class :name "Boolean" :id :BOOL :parent *type-key*) "The Boolean Type in LoLi")

(defun is-from (type-a type-b)
  (if (equal type-b *type-obj*)
      t
      (if (equal type-a *type-obj*)
          nil
          (if (equal type-a type-b)
              t
              (is-from (loli-type-class-parent type-a) type-b)))))

(provide 'loli-type-class)
