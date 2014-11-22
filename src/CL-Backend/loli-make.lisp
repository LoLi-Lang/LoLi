(require 'loli-package "package")
(require 'loli-env "loli-env")
(require 'loli-obj "loli-obj")
(require 'loli-prim "loli-prim")
(require 'loli-read "loli-read")
(require 'loli-repl "loli-repl")
(require 'loli-type-class "loli-typeclass")

(compile-file "loli-main" :output-file #P"loli")

(sb-ext:exit)
