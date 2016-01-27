
(cl:in-package :asdf)

(defsystem "opencv_stuff-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "MyImage" :depends-on ("_package_MyImage"))
    (:file "_package_MyImage" :depends-on ("_package"))
  ))