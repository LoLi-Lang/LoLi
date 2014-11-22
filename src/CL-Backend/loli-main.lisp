(let* ((*standard-output* (make-broadcast-stream))
       (*error-output* *standard-output*))
  (require 'loli-package "package")
  (require 'loli-repl "loli-repl"))

(format *standard-output* "~%LoLi PRPR!~%LoLi is a Free Software and you can do whatever you want with it under ~%the licence GPLv3 or any later version. ~%")

(in-package #:loli)

(loli-repl)
