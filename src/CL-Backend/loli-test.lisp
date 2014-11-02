(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-env "loli-env")
(require 'loli-repl "loli-repl")
(require 'loli-type-class "loli-typeclass")

(in-package #:loli)

(defparameter *TEST-ENV* loli-nil)

(setf *TEST-ENV*
      (loli-cons
       (loli-cons (to-loli-sym "TEST")
                  (to-loli-int 151))
       *TEST-ENV*))

(setf *TEST-ENV*
      (loli-cons
       (loli-cons (to-loli-sym "AAA")
                  (to-loli-sym "AAA"))
       *TEST-ENV*))

(setf *TEST-ENV*
      (loli-cons
       (loli-cons (to-loli-sym "AAA")
                  (to-loli-int "111"))
       *TEST-ENV*))

(loli-lookup (to-loli-sym "AAA")
             *TEST-ENV*)

(loli-lookup (to-loli-sym "A")
             *TEST-ENV*)

(defparameter *TEST-LAMBDA*
  (to-loli-lambda
   (make-loli-lambda-struct :return-type *type-obj*
                            :arg-types (list *type-obj* *type-int*))))
