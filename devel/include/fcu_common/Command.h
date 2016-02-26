// Generated by gencpp from file fcu_common/Command.msg
// DO NOT EDIT!


#ifndef FCU_COMMON_MESSAGE_COMMAND_H
#define FCU_COMMON_MESSAGE_COMMAND_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace fcu_common
{
template <class ContainerAllocator>
struct Command_
{
  typedef Command_<ContainerAllocator> Type;

  Command_()
    : normalized_roll(0.0)
    , normalized_pitch(0.0)
    , normalized_yaw(0.0)
    , normalized_throttle(0.0)
    , mode(0)  {
    }
  Command_(const ContainerAllocator& _alloc)
    : normalized_roll(0.0)
    , normalized_pitch(0.0)
    , normalized_yaw(0.0)
    , normalized_throttle(0.0)
    , mode(0)  {
    }



   typedef double _normalized_roll_type;
  _normalized_roll_type normalized_roll;

   typedef double _normalized_pitch_type;
  _normalized_pitch_type normalized_pitch;

   typedef double _normalized_yaw_type;
  _normalized_yaw_type normalized_yaw;

   typedef double _normalized_throttle_type;
  _normalized_throttle_type normalized_throttle;

   typedef uint8_t _mode_type;
  _mode_type mode;


    enum { MODE_ACRO = 0u };
     enum { MODE_ANGLE = 1u };
     enum { MODE_FIXED_WING = 2u };
 

  typedef boost::shared_ptr< ::fcu_common::Command_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fcu_common::Command_<ContainerAllocator> const> ConstPtr;

}; // struct Command_

typedef ::fcu_common::Command_<std::allocator<void> > Command;

typedef boost::shared_ptr< ::fcu_common::Command > CommandPtr;
typedef boost::shared_ptr< ::fcu_common::Command const> CommandConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fcu_common::Command_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fcu_common::Command_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fcu_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'fcu_common': ['/home/jaron/catkin_ws/src/fcu_common/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fcu_common::Command_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fcu_common::Command_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fcu_common::Command_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fcu_common::Command_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fcu_common::Command_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fcu_common::Command_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fcu_common::Command_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1696698a6cd6cd733fa0661497359dd2";
  }

  static const char* value(const ::fcu_common::Command_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1696698a6cd6cd73ULL;
  static const uint64_t static_value2 = 0x3fa0661497359dd2ULL;
};

template<class ContainerAllocator>
struct DataType< ::fcu_common::Command_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fcu_common/Command";
  }

  static const char* value(const ::fcu_common::Command_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fcu_common::Command_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Defines the control commands sent to the autopilot block\n\
\n\
float64 normalized_roll		# nomalized roll, roll rate, or aleraon deflection (-1 to 1)\n\
float64 normalized_pitch	# nomalized pitch, pitch rate or elevator deflection (-1 to 1)\n\
float64 normalized_yaw		# nomalized yaw rate or rudder deflection (-1 to 1)\n\
float64 normalized_throttle	# nomalized throttle (0 to 1)\n\
uint8 MODE_ACRO=0\n\
uint8 MODE_ANGLE=1\n\
uint8 MODE_FIXED_WING=2\n\
uint8 mode\n\
";
  }

  static const char* value(const ::fcu_common::Command_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fcu_common::Command_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.normalized_roll);
      stream.next(m.normalized_pitch);
      stream.next(m.normalized_yaw);
      stream.next(m.normalized_throttle);
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Command_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fcu_common::Command_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fcu_common::Command_<ContainerAllocator>& v)
  {
    s << indent << "normalized_roll: ";
    Printer<double>::stream(s, indent + "  ", v.normalized_roll);
    s << indent << "normalized_pitch: ";
    Printer<double>::stream(s, indent + "  ", v.normalized_pitch);
    s << indent << "normalized_yaw: ";
    Printer<double>::stream(s, indent + "  ", v.normalized_yaw);
    s << indent << "normalized_throttle: ";
    Printer<double>::stream(s, indent + "  ", v.normalized_throttle);
    s << indent << "mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FCU_COMMON_MESSAGE_COMMAND_H