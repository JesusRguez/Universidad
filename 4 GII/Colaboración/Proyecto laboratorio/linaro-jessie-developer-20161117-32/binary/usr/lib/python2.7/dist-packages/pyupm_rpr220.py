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
            fp, pathname, description = imp.find_module('_pyupm_rpr220', [dirname(__file__)])
        except ImportError:
            import _pyupm_rpr220
            return _pyupm_rpr220
        if fp is not None:
            try:
                _mod = imp.load_module('_pyupm_rpr220', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _pyupm_rpr220 = swig_import_helper()
    del swig_import_helper
else:
    import _pyupm_rpr220
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


class RPR220(_object):
    """
    API for the RPR220-based Grove IR Reflective Sensor.

    ID: rpr220

    Name: RPR220 IR Reflective Sensor

    Other Names: Grove IR Reflective Sensor

    Category: light

    Manufacturer: seeed

    Link:http://www.seeedstudio.com/wiki/Grove_-
    _Infrared_Reflective_Sensor

    Connection: gpio

    Kit: tsk hak  UPM module for the Grove IR reflective sensor. The
    sensitivity can be adjusted with the potentiometer on the sensor
    module. It has a range of approximately 15 mm, and a quick response
    time.

    It detects high-contrast dark areas on a light background.

    This module allows the user to determine the current status (black
    detected or not). Additionally, if desired, an interrupt service
    routine (ISR) can be installed that is called when black is detected.
    Either method can be used, depending on your use case.

    C++ includes: rpr220.h 
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, RPR220, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, RPR220, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        __init__(upm::RPR220 self, int pin) -> RPR220

        Parameters:
            pin: int


        RPR220(int pin)

        RPR220 constructor

        Parameters:
        -----------

        pin:  Digital pin to use 
        """
        this = _pyupm_rpr220.new_RPR220(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _pyupm_rpr220.delete_RPR220
    __del__ = lambda self : None;
    def blackDetected(self):
        """
        blackDetected(RPR220 self) -> bool

        Parameters:
            self: upm::RPR220 *


        bool
        blackDetected()

        Gets the status of the pin; true means black has been detected

        True if the sensor has detected black 
        """
        return _pyupm_rpr220.RPR220_blackDetected(self)

    def installISR(self, *args):
        """
        installISR(RPR220 self, void (*)(void *) isr, void * arg)

        Parameters:
            isr: void (*)(void *)
            arg: void *


        void
        installISR(void(*isr)(void *), void *arg)

        Installs an ISR to be called when black is detected

        Parameters:
        -----------

        fptr:  Pointer to a function to be called on interrupt

        arg:  Pointer to an object to be supplied as an argument to the ISR.

        """
        return _pyupm_rpr220.RPR220_installISR(self, *args)

    def uninstallISR(self):
        """
        uninstallISR(RPR220 self)

        Parameters:
            self: upm::RPR220 *


        void uninstallISR()

        Uninstalls the previously installed ISR 
        """
        return _pyupm_rpr220.RPR220_uninstallISR(self)

RPR220_swigregister = _pyupm_rpr220.RPR220_swigregister
RPR220_swigregister(RPR220)

# This file is compatible with both classic and new-style classes.


