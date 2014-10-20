(require 'loli-package "package")
(require 'loli-obj "loli-obj")

(in-package #:loli)

(defun tokenize (str)
  str
  (loop for i = 0 then (1+ j)
     as j = (position #\Space str :start i)
     collect (subseq str i j)
     while j))

(defun loli-parse (str &optional (env '()))
  (let ((trimed (string-trim '(#\Space #\Tab #\Newline) str)))
    (tokenize trimed)))

(provide 'loli-parser)
