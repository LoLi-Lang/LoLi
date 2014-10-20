(require 'loli-package "package")
(require 'loli-eval "loli-eval")
(require 'loli-read "loli-read")
(require 'loli-parser "loli-parser")

(in-package #:loli)

(defun rep (top-env type-env &optional (in-stream *standard-input*))
  (loli-simple-eval
   (loli-get-input in-stream)))

(defun test-rep (&optional (in-stream *standard-input*))
  (loli-parse
   (loli-get-input in-stream)))

(provide 'loli-repl)
