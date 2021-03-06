// Generated by gencpp from file fcu_common/GPS.msg
// DO NOT EDIT!


#ifndef FCU_COMMON_MESSAGE_GPS_H
#define FCU_COMMON_MESSAGE_GPS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace fcu_common
{
template <class ContainerAllocator>
struct GPS_
{
  typedef GPS_<ContainerAllocator> Type;

  GPS_()
    : header()
    , fix(false)
    , NumSat(0)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , speed(0.0)
    , ground_course(0.0)  {
    }
  GPS_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , fix(false)
    , NumSat(0)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , speed(0.0)
    , ground_course(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _fix_type;
  _fix_type fix;

   typedef int16_t _NumSat_type;
  _NumSat_type NumSat;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _altitude_type;
  _altitude_type altitude;

   typedef double _speed_type;
  _speed_type speed;

   typedef double _ground_course_type;
  _ground_course_type ground_course;




  typedef boost::shared_ptr< ::fcu_common::GPS_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fcu_common::GPS_<ContainerAllocator> const> ConstPtr;

}; // struct GPS_

typedef ::fcu_common::GPS_<std::allocator<void> > GPS;

typedef boost::shared_ptr< ::fcu_common::GPS > GPSPtr;
typedef boost::shared_ptr< ::fcu_common::GPS const> GPSConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fcu_common::GPS_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fcu_common::GPS_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fcu_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'fcu_common': ['/home/jaron/catkin_ws/src/fcu_common/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fcu_common::GPS_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fcu_common::GPS_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fcu_common::GPS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fcu_common::GPS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fcu_common::GPS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fcu_common::GPS_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fcu_common::GPS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f23fa2d74b6f1796439ab348a1575c7a";
  }

  static const char* value(const ::fcu_common::GPS_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf23fa2d74b6f1796ULL;
  static const uint64_t static_value2 = 0x439ab348a1575c7aULL;
};

template<class ContainerAllocator>
struct DataType< ::fcu_common::GPS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fcu_common/GPS";
  }

  static const char* value(const ::fcu_common::GPS_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fcu_common::GPS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
bool fix\n\
int16 NumSat\n\
float64 latitude\n\
float64 longitude\n\
float64 altitude\n\
float64 speed\n\
float64 ground_course\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::fcu_common::GPS_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fcu_common::GPS_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.fix);
      stream.next(m.NumSat);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.altitude);
      stream.next(m.speed);
      stream.next(m.ground_course);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct GPS_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fcu_common::GPS_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fcu_common::GPS_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "fix: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fix);
    s << indent << "NumSat: ";
    Printer<int16_t>::stream(s, indent + "  ", v.NumSat);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "altitude: ";
    Printer<double>::stream(s, indent + "  ", v.altitude);
    s << indent << "speed: ";
    Printer<double>::stream(s, indent + "  ", v.speed);
    s << indent << "ground_course: ";
    Printer<double>::stream(s, indent + "  ", v.ground_course);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FCU_COMMON_MESSAGE_GPS_H
