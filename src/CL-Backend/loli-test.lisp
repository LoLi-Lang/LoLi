(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-env "loli-env")

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

(loli-lookup (to-loli-sym "AAA")
             *TEST-ENV*)

(loli-lookup (to-loli-sym "A")
             *TEST-ENV*)
