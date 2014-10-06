(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")

(in-package :loli)

(defparameter *TOP-ENV* nil "The TOP-LEVEL Environment of LoLi")
(defparameter *TYPE-ENV*
  (list
   *type-obj*
   *type-fn*
   *type-flt*
   *type-int*
   *type-key*
   *type-num*
   *type-sym*
   *type-bool*
   *type-char*
   *type-string*
   *type-cons*
   *type-lambda*
   *type-proc*)
  "The Global Environment Contains All Types of LoLi")

(provide 'loli-base)
