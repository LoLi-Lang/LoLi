(require 'loli-package "package")
(require 'loli-eval "loli-eval")
(require 'loli-read "loli-read")

(in-package #:loli)

(defun rep (top-env type-env &optional (in-stream *standard-input*))
  (loli-simple-eval
   (loli-get-input in-stream)))

(provide 'loli-repl)
