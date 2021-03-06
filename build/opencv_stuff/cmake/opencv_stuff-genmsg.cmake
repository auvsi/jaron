# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "opencv_stuff: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iopencv_stuff:/home/jaron/catkin_ws/src/opencv_stuff/msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(opencv_stuff_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg" NAME_WE)
add_custom_target(_opencv_stuff_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "opencv_stuff" "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg" "std_msgs/Header:sensor_msgs/Image"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(opencv_stuff
  "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_stuff
)

### Generating Services

### Generating Module File
_generate_module_cpp(opencv_stuff
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_stuff
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(opencv_stuff_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(opencv_stuff_generate_messages opencv_stuff_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg" NAME_WE)
add_dependencies(opencv_stuff_generate_messages_cpp _opencv_stuff_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_stuff_gencpp)
add_dependencies(opencv_stuff_gencpp opencv_stuff_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_stuff_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(opencv_stuff
  "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_stuff
)

### Generating Services

### Generating Module File
_generate_module_lisp(opencv_stuff
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_stuff
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(opencv_stuff_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(opencv_stuff_generate_messages opencv_stuff_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg" NAME_WE)
add_dependencies(opencv_stuff_generate_messages_lisp _opencv_stuff_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_stuff_genlisp)
add_dependencies(opencv_stuff_genlisp opencv_stuff_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_stuff_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(opencv_stuff
  "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_stuff
)

### Generating Services

### Generating Module File
_generate_module_py(opencv_stuff
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_stuff
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(opencv_stuff_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(opencv_stuff_generate_messages opencv_stuff_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaron/catkin_ws/src/opencv_stuff/msg/MyImage.msg" NAME_WE)
add_dependencies(opencv_stuff_generate_messages_py _opencv_stuff_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_stuff_genpy)
add_dependencies(opencv_stuff_genpy opencv_stuff_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_stuff_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_stuff)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_stuff
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(opencv_stuff_generate_messages_cpp sensor_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_stuff)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_stuff
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(opencv_stuff_generate_messages_lisp sensor_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_stuff)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_stuff\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_stuff
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(opencv_stuff_generate_messages_py sensor_msgs_generate_messages_py)
