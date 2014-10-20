(require 'loli-package "package")
(require 'loli-obj "loli-obj")

(in-package #:loli)

(defstruct loli-cons-struct
  (head loli-nil :type loli-obj)
  (tail loli-nil :type loli-obj))

(defun loli-cons (head &optional (tail loli-nil))
  (loli-cons-struct :head head :tail tail))

(defun loli-head (o)
  (if (loli-obj-p o)
      (if (loli-cons-struct-p (loli-obj-value o))
          (loli-cons-struct-head (loli-obj-value o))
          'ERR-NOT-LOLI-CONS)
      'ERR-NOT-LOLI-OBJ))

(defun loli-tail (o)
  (if (loli-obj-p o)
      (if (loli-cons-struct-p (loli-obj-value o))
          (loli-cons-struct-tail (loli-obj-value o))
          'ERR-NOT-LOLI-CONS)
      'ERR-NOT-LOLI-OBJ))

(provide 'loli-prim)
