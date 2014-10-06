(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")
(require 'loli-obj "loli-obj")
(require 'loli-eval "loli-eval")

(in-package #:loli)

(format *standard-output* "~A~%" (sub-type-p (loli-obj-loli-type loli-true) *type-key*))

(format *standard-output* "~A~%" (loli-simple-eval loli-false))
