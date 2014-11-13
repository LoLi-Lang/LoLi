(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-read "loli-read")

(in-package #:loli)

(define-condition loli-error (error)
  ())

(define-condition loli-err-symbol-not-bound (loli-error)
  ((err-obj :initarg :err-obj :reader err-obj)
   (err-env :initarg :err-env :reader err-env))
  (:report (lambda (condition stream)
             (format stream "Error: Symbol ~A is not bound"
                     (loli-obj-value (err-obj condition))))))

(defun handle-loli-symbol-not-bound (condition)
  (when (typep condition 'loli-err-symbol-not-bound)
    (loli-symbol-not-bound-debug (err-obj condition))))

(provide 'loli-error)
