(require 'loli-package "package")
(require 'loli-type-class "loli-typeclass")

(defstruct loli-obj
  value
  (type *type-obj* :type loli-type-class)
  env)

(provide 'loli-obj)
