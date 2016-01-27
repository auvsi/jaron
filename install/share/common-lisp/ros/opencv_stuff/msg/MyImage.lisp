; Auto-generated. Do not edit!


(cl:in-package opencv_stuff-msg)


;//! \htmlinclude MyImage.msg.html

(cl:defclass <MyImage> (roslisp-msg-protocol:ros-message)
  ((imageId
    :reader imageId
    :initarg :imageId
    :type cl:fixnum
    :initform 0)
   (image
    :reader image
    :initarg :image
    :type sensor_msgs-msg:Image
    :initform (cl:make-instance 'sensor_msgs-msg:Image)))
)

(cl:defclass MyImage (<MyImage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MyImage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MyImage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name opencv_stuff-msg:<MyImage> is deprecated: use opencv_stuff-msg:MyImage instead.")))

(cl:ensure-generic-function 'imageId-val :lambda-list '(m))
(cl:defmethod imageId-val ((m <MyImage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_stuff-msg:imageId-val is deprecated.  Use opencv_stuff-msg:imageId instead.")
  (imageId m))

(cl:ensure-generic-function 'image-val :lambda-list '(m))
(cl:defmethod image-val ((m <MyImage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_stuff-msg:image-val is deprecated.  Use opencv_stuff-msg:image instead.")
  (image m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MyImage>) ostream)
  "Serializes a message object of type '<MyImage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'imageId)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'image) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MyImage>) istream)
  "Deserializes a message object of type '<MyImage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'imageId)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'image) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MyImage>)))
  "Returns string type for a message object of type '<MyImage>"
  "opencv_stuff/MyImage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MyImage)))
  "Returns string type for a message object of type 'MyImage"
  "opencv_stuff/MyImage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MyImage>)))
  "Returns md5sum for a message object of type '<MyImage>"
  "2344f5b8ab970a363dd7f4dc1ca716cb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MyImage)))
  "Returns md5sum for a message object of type 'MyImage"
  "2344f5b8ab970a363dd7f4dc1ca716cb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MyImage>)))
  "Returns full string definition for message of type '<MyImage>"
  (cl:format cl:nil "uint8 imageId~%sensor_msgs/Image image~%~%~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of cameara~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MyImage)))
  "Returns full string definition for message of type 'MyImage"
  (cl:format cl:nil "uint8 imageId~%sensor_msgs/Image image~%~%~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of cameara~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MyImage>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'image))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MyImage>))
  "Converts a ROS message object to a list"
  (cl:list 'MyImage
    (cl:cons ':imageId (imageId msg))
    (cl:cons ':image (image msg))
))
