// Generated by gencpp from file fcu_common/FW_Waypoint.msg
// DO NOT EDIT!


#ifndef FCU_COMMON_MESSAGE_FW_WAYPOINT_H
#define FCU_COMMON_MESSAGE_FW_WAYPOINT_H


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
struct FW_Waypoint_
{
  typedef FW_Waypoint_<ContainerAllocator> Type;

  FW_Waypoint_()
    : w()
    , chi_d(0.0)
    , chi_valid(false)
    , Va_d(0.0)
    , set_current(false)  {
      w.assign(0.0);
  }
  FW_Waypoint_(const ContainerAllocator& _alloc)
    : w()
    , chi_d(0.0)
    , chi_valid(false)
    , Va_d(0.0)
    , set_current(false)  {
      w.assign(0.0);
  }



   typedef boost::array<float, 3>  _w_type;
  _w_type w;

   typedef float _chi_d_type;
  _chi_d_type chi_d;

   typedef uint8_t _chi_valid_type;
  _chi_valid_type chi_valid;

   typedef float _Va_d_type;
  _Va_d_type Va_d;

   typedef uint8_t _set_current_type;
  _set_current_type set_current;




  typedef boost::shared_ptr< ::fcu_common::FW_Waypoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fcu_common::FW_Waypoint_<ContainerAllocator> const> ConstPtr;

}; // struct FW_Waypoint_

typedef ::fcu_common::FW_Waypoint_<std::allocator<void> > FW_Waypoint;

typedef boost::shared_ptr< ::fcu_common::FW_Waypoint > FW_WaypointPtr;
typedef boost::shared_ptr< ::fcu_common::FW_Waypoint const> FW_WaypointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fcu_common::FW_Waypoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fcu_common::FW_Waypoint_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fcu_common::FW_Waypoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fcu_common::FW_Waypoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fcu_common::FW_Waypoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7fa894c36e1adfc4bdc28e11056871e8";
  }

  static const char* value(const ::fcu_common::FW_Waypoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7fa894c36e1adfc4ULL;
  static const uint64_t static_value2 = 0xbdc28e11056871e8ULL;
};

template<class ContainerAllocator>
struct DataType< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fcu_common/FW_Waypoint";
  }

  static const char* value(const ::fcu_common::FW_Waypoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# New waypoint, input to path manager\n\
\n\
# @warning w and set_current always have to be valid; the chi_d is optional.\n\
float32[3] w		# Waypoint in local NED (m)\n\
float32 chi_d		# Desired course at this waypoint (rad)\n\
bool chi_valid		# Desired course valid\n\
float32 Va_d		# Desired airspeed (m/s)\n\
bool set_current	# Sets this waypoint to be executed now!\n\
";
  }

  static const char* value(const ::fcu_common::FW_Waypoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.w);
      stream.next(m.chi_d);
      stream.next(m.chi_valid);
      stream.next(m.Va_d);
      stream.next(m.set_current);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct FW_Waypoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fcu_common::FW_Waypoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fcu_common::FW_Waypoint_<ContainerAllocator>& v)
  {
    s << indent << "w[]" << std::endl;
    for (size_t i = 0; i < v.w.size(); ++i)
    {
      s << indent << "  w[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.w[i]);
    }
    s << indent << "chi_d: ";
    Printer<float>::stream(s, indent + "  ", v.chi_d);
    s << indent << "chi_valid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.chi_valid);
    s << indent << "Va_d: ";
    Printer<float>::stream(s, indent + "  ", v.Va_d);
    s << indent << "set_current: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.set_current);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FCU_COMMON_MESSAGE_FW_WAYPOINT_H
