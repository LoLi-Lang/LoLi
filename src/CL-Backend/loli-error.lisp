(require 'loli-package "package")
(require 'loli-obj "loli-obj")
(require 'loli-read "loli-read")

(in-package #:loli)

(define-condition loli-error (error)
  ())

(define-condition loli-err-symbol-not-bound (loli-error)
  ((err-obj :initarg :err-obj :reader err-obj))
  (:report (lambda (condition stream)
             (format stream "Error: Symbol ~A is not bound"
                     (loli-obj-value (err-obj condition))))))

(defun handle-loli-symbol-not-bound (condition)
  (when (typep condition 'loli-err-symbol-not-bound)
    (loli-symbol-not-bound-debug (err-obj condition))))

(defstruct loli-err
  (error-info "" :type string)
  (error-obj loli-nil :type loli-obj)
  (error-env loli-nil :type loli-obj)
  (restarts '() :type list))

(defstruct loli-restarts
  (desc "" :type string)
  (fn nil :type function))

(defun loli-debug (err)
  (if (equal (type-of err) 'loli-err)
      (progn
        (format *standard-output* "ERROR: ~A~%Restarts:~%" (loli-err-error-info err))
        (loop for a from 1 to (length (loli-err-restarts err))
           do (format *standard-output* "[~D] ~A~%" a (loli-restarts-desc (nth a (loli-err-restarts err)))))
        (format *standard-output* "Debug: ")
        (let ((s (loli-read-from-string (loli-get-input))))
          (if (sub-type-p (loli-obj-loli-type s) *type-int*)
              'CALL-NTH-FN
              'PLEASE-INPUT-INTEGER
              )
          )
        )
      'NOT-AN-ERROR))

(provide 'loli-error)
