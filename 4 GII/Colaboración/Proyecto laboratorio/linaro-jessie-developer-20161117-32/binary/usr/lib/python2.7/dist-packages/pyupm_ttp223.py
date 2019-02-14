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
            fp, pathname, description = imp.find_module('_pyupm_ttp223', [dirname(__file__)])
        except ImportError:
            import _pyupm_ttp223
            return _pyupm_ttp223
        if fp is not None:
            try:
                _mod = imp.load_module('_pyupm_ttp223', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _pyupm_ttp223 = swig_import_helper()
    del swig_import_helper
else:
    import _pyupm_ttp223
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


class TTP223(_object):
    """
    API for the TTP223 Touch Sensor.

    ID: ttp223

    Name: TTP223 Touch Sensor

    Other Names: Grove Touch Sensor

    Category: touch

    Manufacturer: seeed

    Link:http://www.seeedstudio.com/depot/Grove-Touch-Sensor-p-747.html

    Connection: gpio  This touch sensor detects when a finger is near the
    metallic pad by the change in capacitance. It can replace a more
    traditional push button. The touch sensor can still function when
    placed under a non- metallic surface like glass or plastic.

    C++ includes: ttp223.h 
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, TTP223, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, TTP223, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        __init__(upm::TTP223 self, unsigned int pin) -> TTP223

        Parameters:
            pin: unsigned int


        TTP223(unsigned int pin)

        TTP223 constructor

        Parameters:
        -----------

        pin:  GPIO pin where the sensor is connected 
        """
        this = _pyupm_ttp223.new_TTP223(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _pyupm_ttp223.delete_TTP223
    __del__ = lambda self : None;
    def name(self):
        """
        name(TTP223 self) -> std::string

        Parameters:
            self: upm::TTP223 *


        std::string name()

        Returns the name of this sensor

        Name of this sensor 
        """
        return _pyupm_ttp223.TTP223_name(self)

    def value(self):
        """
        value(TTP223 self) -> int

        Parameters:
            self: upm::TTP223 *


        int value()

        Gets the value from the GPIO pin

        Value from the GPIO pin 
        """
        return _pyupm_ttp223.TTP223_value(self)

    def isPressed(self):
        """
        isPressed(TTP223 self) -> bool

        Parameters:
            self: upm::TTP223 *


        bool isPressed()

        Determines whether the touch sensor is being touched

        True if touched, false otherwise 
        """
        return _pyupm_ttp223.TTP223_isPressed(self)

    def installISR(self, *args):
        """
        installISR(TTP223 self, mraa::Edge level, void (*)(void *) isr, void * arg)

        Parameters:
            level: mraa::Edge
            isr: void (*)(void *)
            arg: void *


        void
        installISR(mraa::Edge level, void(*isr)(void *), void *arg)

        Installs an interrupt service routine (ISR) to be called when the
        button is activated or deactivated.

        Parameters:
        -----------

        fptr:  Pointer to a function to be called on interrupt

        arg:  Pointer to an object to be supplied as an argument to the ISR.

        """
        return _pyupm_ttp223.TTP223_installISR(self, *args)

    def uninstallISR(self):
        """
        uninstallISR(TTP223 self)

        Parameters:
            self: upm::TTP223 *


        void uninstallISR()

        Uninstalls the previously installed ISR 
        """
        return _pyupm_ttp223.TTP223_uninstallISR(self)

TTP223_swigregister = _pyupm_ttp223.TTP223_swigregister
TTP223_swigregister(TTP223)

# This file is compatible with both classic and new-style classes.


