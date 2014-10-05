(require 'loli-package "package")

(in-package #:loli)

(is-from *type-obj* *type-obj*)
(is-from *type-int* *type-obj*)
(is-from *type-int* *type-num*)
(is-from *type-flt* *type-num*)
(is-from *type-num* *type-flt*)
