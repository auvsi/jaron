# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from fcu_common/FW_State.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class FW_State(genpy.Message):
  _md5sum = "68d0c7e8c59772a7dff6c1724b7b01b6"
  _type = "fcu_common/FW_State"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# Vehicle state 'x_hat' output from the estimator or from simulator 

# @warning roll, pitch and yaw have always to be valid, the quaternion is optional
float32[3] position	# north, east, down (m)
float32 Va		# Airspeed (m/s)
float32 alpha		# Angle of attack (rad)
float32 beta		# Slide slip angle (rad)
float32 phi		# Roll angle (rad)
float32 theta		# Pitch angle (rad)
float32 psi		# Yaw angle (rad)
float32 chi		# Course angle (rad)
float32 p		# Body frame rollrate (rad/s)
float32 q		# Body frame pitchrate (rad/s)
float32 r		# Body frame yawrate (rad/s)
float32 Vg		# Groundspeed (m/s)
float32 wn		# Windspeed north component (m/s)
float32 we		# Windspeed east component (m/s)
float32[4] quat		# Quaternion (wxyz, NED)
bool quat_valid		# Quaternion valid

"""
  __slots__ = ['position','Va','alpha','beta','phi','theta','psi','chi','p','q','r','Vg','wn','we','quat','quat_valid']
  _slot_types = ['float32[3]','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32','float32[4]','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       position,Va,alpha,beta,phi,theta,psi,chi,p,q,r,Vg,wn,we,quat,quat_valid

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(FW_State, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.position is None:
        self.position = [0.,0.,0.]
      if self.Va is None:
        self.Va = 0.
      if self.alpha is None:
        self.alpha = 0.
      if self.beta is None:
        self.beta = 0.
      if self.phi is None:
        self.phi = 0.
      if self.theta is None:
        self.theta = 0.
      if self.psi is None:
        self.psi = 0.
      if self.chi is None:
        self.chi = 0.
      if self.p is None:
        self.p = 0.
      if self.q is None:
        self.q = 0.
      if self.r is None:
        self.r = 0.
      if self.Vg is None:
        self.Vg = 0.
      if self.wn is None:
        self.wn = 0.
      if self.we is None:
        self.we = 0.
      if self.quat is None:
        self.quat = [0.,0.,0.,0.]
      if self.quat_valid is None:
        self.quat_valid = False
    else:
      self.position = [0.,0.,0.]
      self.Va = 0.
      self.alpha = 0.
      self.beta = 0.
      self.phi = 0.
      self.theta = 0.
      self.psi = 0.
      self.chi = 0.
      self.p = 0.
      self.q = 0.
      self.r = 0.
      self.Vg = 0.
      self.wn = 0.
      self.we = 0.
      self.quat = [0.,0.,0.,0.]
      self.quat_valid = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_3f.pack(*self.position))
      _x = self
      buff.write(_struct_13f.pack(_x.Va, _x.alpha, _x.beta, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.wn, _x.we))
      buff.write(_struct_4f.pack(*self.quat))
      buff.write(_struct_B.pack(self.quat_valid))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 12
      self.position = _struct_3f.unpack(str[start:end])
      _x = self
      start = end
      end += 52
      (_x.Va, _x.alpha, _x.beta, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.wn, _x.we,) = _struct_13f.unpack(str[start:end])
      start = end
      end += 16
      self.quat = _struct_4f.unpack(str[start:end])
      start = end
      end += 1
      (self.quat_valid,) = _struct_B.unpack(str[start:end])
      self.quat_valid = bool(self.quat_valid)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(self.position.tostring())
      _x = self
      buff.write(_struct_13f.pack(_x.Va, _x.alpha, _x.beta, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.wn, _x.we))
      buff.write(self.quat.tostring())
      buff.write(_struct_B.pack(self.quat_valid))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 12
      self.position = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 52
      (_x.Va, _x.alpha, _x.beta, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.wn, _x.we,) = _struct_13f.unpack(str[start:end])
      start = end
      end += 16
      self.quat = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=4)
      start = end
      end += 1
      (self.quat_valid,) = _struct_B.unpack(str[start:end])
      self.quat_valid = bool(self.quat_valid)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_4f = struct.Struct("<4f")
_struct_B = struct.Struct("<B")
_struct_3f = struct.Struct("<3f")
_struct_13f = struct.Struct("<13f")
