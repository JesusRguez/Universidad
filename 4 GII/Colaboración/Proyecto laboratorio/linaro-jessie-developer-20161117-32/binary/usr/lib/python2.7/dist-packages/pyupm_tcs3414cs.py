# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.12
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_pyupm_tcs3414cs', [dirname(__file__)])
        except ImportError:
            import _pyupm_tcs3414cs
            return _pyupm_tcs3414cs
        if fp is not None:
            try:
                _mod = imp.load_module('_pyupm_tcs3414cs', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _pyupm_tcs3414cs = swig_import_helper()
    del swig_import_helper
else:
    import _pyupm_tcs3414cs
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


ADDR = _pyupm_tcs3414cs.ADDR
REG_CTL = _pyupm_tcs3414cs.REG_CTL
REG_TIMING = _pyupm_tcs3414cs.REG_TIMING
REG_INT = _pyupm_tcs3414cs.REG_INT
REG_INT_SOURCE = _pyupm_tcs3414cs.REG_INT_SOURCE
REG_ID = _pyupm_tcs3414cs.REG_ID
REG_GAIN = _pyupm_tcs3414cs.REG_GAIN
REG_LOW_THRESH_LOW_BYTE = _pyupm_tcs3414cs.REG_LOW_THRESH_LOW_BYTE
REG_LOW_THRESH_HIGH_BYTE = _pyupm_tcs3414cs.REG_LOW_THRESH_HIGH_BYTE
REG_HIGH_THRESH_LOW_BYTE = _pyupm_tcs3414cs.REG_HIGH_THRESH_LOW_BYTE
REG_HIGH_THRESH_HIGH_BYTE = _pyupm_tcs3414cs.REG_HIGH_THRESH_HIGH_BYTE
REG_BLOCK_READ = _pyupm_tcs3414cs.REG_BLOCK_READ
REG_GREEN_LOW = _pyupm_tcs3414cs.REG_GREEN_LOW
REG_GREEN_HIGH = _pyupm_tcs3414cs.REG_GREEN_HIGH
REG_RED_LOW = _pyupm_tcs3414cs.REG_RED_LOW
REG_RED_HIGH = _pyupm_tcs3414cs.REG_RED_HIGH
REG_BLUE_LOW = _pyupm_tcs3414cs.REG_BLUE_LOW
REG_BLUE_HIGH = _pyupm_tcs3414cs.REG_BLUE_HIGH
REG_CLEAR_LOW = _pyupm_tcs3414cs.REG_CLEAR_LOW
REG_CLEAR_HIGH = _pyupm_tcs3414cs.REG_CLEAR_HIGH
CTL_DAT_INIITIATE = _pyupm_tcs3414cs.CTL_DAT_INIITIATE
CLR_INT = _pyupm_tcs3414cs.CLR_INT
SYNC_EDGE = _pyupm_tcs3414cs.SYNC_EDGE
INTEG_MODE_FREE = _pyupm_tcs3414cs.INTEG_MODE_FREE
INTEG_MODE_MANUAL = _pyupm_tcs3414cs.INTEG_MODE_MANUAL
INTEG_MODE_SYN_SINGLE = _pyupm_tcs3414cs.INTEG_MODE_SYN_SINGLE
INTEG_MODE_SYN_MULTI = _pyupm_tcs3414cs.INTEG_MODE_SYN_MULTI
INTEG_PARAM_PULSE_COUNT1 = _pyupm_tcs3414cs.INTEG_PARAM_PULSE_COUNT1
INTEG_PARAM_PULSE_COUNT2 = _pyupm_tcs3414cs.INTEG_PARAM_PULSE_COUNT2
INTEG_PARAM_PULSE_COUNT4 = _pyupm_tcs3414cs.INTEG_PARAM_PULSE_COUNT4
INTEG_PARAM_PULSE_COUNT8 = _pyupm_tcs3414cs.INTEG_PARAM_PULSE_COUNT8
INTR_STOP = _pyupm_tcs3414cs.INTR_STOP
INTR_DISABLE = _pyupm_tcs3414cs.INTR_DISABLE
INTR_LEVEL = _pyupm_tcs3414cs.INTR_LEVEL
INTR_PERSIST_EVERY = _pyupm_tcs3414cs.INTR_PERSIST_EVERY
INTR_PERSIST_SINGLE = _pyupm_tcs3414cs.INTR_PERSIST_SINGLE
INT_SOURCE_GREEN = _pyupm_tcs3414cs.INT_SOURCE_GREEN
INT_SOURCE_RED = _pyupm_tcs3414cs.INT_SOURCE_RED
INT_SOURCE_BLUE = _pyupm_tcs3414cs.INT_SOURCE_BLUE
INT_SOURCE_CLEAR = _pyupm_tcs3414cs.INT_SOURCE_CLEAR
GAIN_1 = _pyupm_tcs3414cs.GAIN_1
GAIN_4 = _pyupm_tcs3414cs.GAIN_4
GAIN_16 = _pyupm_tcs3414cs.GAIN_16
GANI_64 = _pyupm_tcs3414cs.GANI_64
PRESCALER_1 = _pyupm_tcs3414cs.PRESCALER_1
PRESCALER_2 = _pyupm_tcs3414cs.PRESCALER_2
PRESCALER_4 = _pyupm_tcs3414cs.PRESCALER_4
PRESCALER_8 = _pyupm_tcs3414cs.PRESCALER_8
PRESCALER_16 = _pyupm_tcs3414cs.PRESCALER_16
PRESCALER_32 = _pyupm_tcs3414cs.PRESCALER_32
PRESCALER_64 = _pyupm_tcs3414cs.PRESCALER_64
HIGH = _pyupm_tcs3414cs.HIGH
LOW = _pyupm_tcs3414cs.LOW
class tcs3414sc_rgb_t(_object):
    """Proxy of C++ upm::tcs3414sc_rgb_t class"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, tcs3414sc_rgb_t, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, tcs3414sc_rgb_t, name)
    __repr__ = _swig_repr
    __swig_setmethods__["r"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_r_set
    __swig_getmethods__["r"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_r_get
    if _newclass:r = _swig_property(_pyupm_tcs3414cs.tcs3414sc_rgb_t_r_get, _pyupm_tcs3414cs.tcs3414sc_rgb_t_r_set)
    __swig_setmethods__["g"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_g_set
    __swig_getmethods__["g"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_g_get
    if _newclass:g = _swig_property(_pyupm_tcs3414cs.tcs3414sc_rgb_t_g_get, _pyupm_tcs3414cs.tcs3414sc_rgb_t_g_set)
    __swig_setmethods__["b"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_b_set
    __swig_getmethods__["b"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_b_get
    if _newclass:b = _swig_property(_pyupm_tcs3414cs.tcs3414sc_rgb_t_b_get, _pyupm_tcs3414cs.tcs3414sc_rgb_t_b_set)
    __swig_setmethods__["clr"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_clr_set
    __swig_getmethods__["clr"] = _pyupm_tcs3414cs.tcs3414sc_rgb_t_clr_get
    if _newclass:clr = _swig_property(_pyupm_tcs3414cs.tcs3414sc_rgb_t_clr_get, _pyupm_tcs3414cs.tcs3414sc_rgb_t_clr_set)
    def __init__(self): 
        """__init__(upm::tcs3414sc_rgb_t self) -> tcs3414sc_rgb_t"""
        this = _pyupm_tcs3414cs.new_tcs3414sc_rgb_t()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _pyupm_tcs3414cs.delete_tcs3414sc_rgb_t
    __del__ = lambda self : None;
tcs3414sc_rgb_t_swigregister = _pyupm_tcs3414cs.tcs3414sc_rgb_t_swigregister
tcs3414sc_rgb_t_swigregister(tcs3414sc_rgb_t)

class TCS3414CS(_object):
    """
    API for the TCS3414CS Color Sensor.

    ID: tcs3414cs

    Name: TCS3414CS Color Sensor

    Other Names: Grove Color Sensor

    Category: color

    Manufacturer: seeed

    Link:http://www.seeedstudio.com/wiki/Grove_-_I2C_Color_Sensor

    Connection: i2c  This module defines the TCS3414CS interface for the
    color sensor

    C++ includes: tcs3414cs.h 
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, TCS3414CS, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, TCS3414CS, name)
    __repr__ = _swig_repr
    def __init__(self): 
        """
        __init__(upm::TCS3414CS self) -> TCS3414CS

        TCS3414CS()

        Instantiates a TCS3414CS object

        Parameters:
        -----------

        bus:  Number of the used bus 
        """
        this = _pyupm_tcs3414cs.new_TCS3414CS()
        try: self.this.append(this)
        except: self.this = this
    def readRGB(self, *args):
        """
        readRGB(TCS3414CS self, tcs3414sc_rgb_t rgb)

        Parameters:
            rgb: upm::tcs3414sc_rgb_t *


        void
        readRGB(tcs3414sc_rgb_t *rgb)

        Gets the RGB value from the sensor.

        Parameters:
        -----------

        rgb:  Color values 
        """
        return _pyupm_tcs3414cs.TCS3414CS_readRGB(self, *args)

    def clearInterrupt(self):
        """
        clearInterrupt(TCS3414CS self)

        Parameters:
            self: upm::TCS3414CS *


        void
        clearInterrupt()

        Clears interrupts. 
        """
        return _pyupm_tcs3414cs.TCS3414CS_clearInterrupt(self)

    def name(self):
        """
        name(TCS3414CS self) -> std::string

        Parameters:
            self: upm::TCS3414CS *


        std::string name()

        Returns the name of the component 
        """
        return _pyupm_tcs3414cs.TCS3414CS_name(self)

    __swig_destroy__ = _pyupm_tcs3414cs.delete_TCS3414CS
    __del__ = lambda self : None;
TCS3414CS_swigregister = _pyupm_tcs3414cs.TCS3414CS_swigregister
TCS3414CS_swigregister(TCS3414CS)

# This file is compatible with both classic and new-style classes.


