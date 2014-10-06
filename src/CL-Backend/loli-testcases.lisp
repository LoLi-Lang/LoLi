(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")
(require 'loli-obj"loli-obj")

(in-package #:loli)

(format *standard-output* "~A" (is-from (loli-obj-loli-type loli-true) *type-bool*))
