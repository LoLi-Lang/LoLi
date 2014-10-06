(require 'loli-package "package")

(in-package #:loli)

(defun loli-validate-input (str &optional (p 0) (q t))
  (format *standard-output* "~A~%" str)
  (loop for c across str
     do
       (cond
         ((equal c #\()
          (if q
              (setq p (1+ p))))
         ((equal c #\))
          (if q
              (if (>= p 1)
                  (setq p (1- p))
                  (return-from loli-validate-input 'UNMATCHED-PARENTHESIS))))
         ((equal c #\")
          (setq q (not q)))))
  (return-from loli-validate-input (and q (= 0 p))))

(defun loli-get-input (&optional (in-stream *standard-input*))
  (let* ((tmp (read-line in-stream))
         (stat (loli-validate-input tmp)))
    (if (equal stat 'UNMATCHED-PARENTHESIS)
        (return-from loli-get-input 'UNIMPLEMENTED-ERROR)
        (loop while (not stat)
           do (setq tmp (concatenate 'string tmp (read-line in-stream))
                    stat (loli-validate-input tmp))))
    (return-from loli-get-input tmp)))

(provide 'loli-read)
