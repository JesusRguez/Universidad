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
            fp, pathname, description = imp.find_module('_pyupm_xbee', [dirname(__file__)])
        except ImportError:
            import _pyupm_xbee
            return _pyupm_xbee
        if fp is not None:
            try:
                _mod = imp.load_module('_pyupm_xbee', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _pyupm_xbee = swig_import_helper()
    del swig_import_helper
else:
    import _pyupm_xbee
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


XBEE_DEFAULT_UART = _pyupm_xbee.XBEE_DEFAULT_UART
class XBee(_object):
    """
    API for the XBee modules.

    ID: xbee

    Name: XBee modules

    Category: wifi

    Manufacturer: sparkfun

    Connection: uart

    Link:https://www.sparkfun.com/products/11215  This is a generic UART
    driver for use with Digi XBee modules. It was tested with the XBee S1
    802.15.4 module and the XBee S6B WiFi module.

    It provides basic UART support for sending and receiving data to and
    from the device. It is controlled by an AT or API command set.

    It is connected at 9600 baud by default.

    These devices are typically configured using Digi's X-CTU windows
    software, however it is possible of course to configure them manually
    using AT commands. See the examples.

    XBee Sensor image provided by SparkFun* underCC BY-NC-SA-3.0.

    C++ includes: xbee.h 
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, XBee, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, XBee, name)
    __repr__ = _swig_repr
    def __init__(self, uart=0): 
        """
        __init__(upm::XBee self, int uart=0) -> XBee

        Parameters:
            uart: int

        __init__(upm::XBee self) -> XBee

        XBee(int
        uart=XBEE_DEFAULT_UART)

        XBee object constructor

        Parameters:
        -----------

        uart:  Default UART to use (0 or 1). Default is 0. 
        """
        this = _pyupm_xbee.new_XBee(uart)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _pyupm_xbee.delete_XBee
    __del__ = lambda self : None;
    def dataAvailable(self, *args):
        """
        dataAvailable(XBee self, unsigned int millis) -> bool

        Parameters:
            millis: unsigned int


        bool
        dataAvailable(unsigned int millis)

        Checks to see if there is data available for reading

        Parameters:
        -----------

        millis:  Number of milliseconds to wait; 0 means no waiting

        true if there is data available for reading 
        """
        return _pyupm_xbee.XBee_dataAvailable(self, *args)

    def readData(self, *args):
        """
        readData(XBee self, char * buffer, unsigned int len) -> int

        Parameters:
            buffer: char *
            len: unsigned int


        int readData(char
        *buffer, unsigned int len)

        Reads any available data into a user-supplied buffer. Note: the call
        blocks until data is available for reading. Use dataAvailable() to
        determine whether there is data available beforehand, to avoid
        blocking.

        Parameters:
        -----------

        buffer:  Buffer to hold the data read

        len:  Length of the buffer

        Number of bytes read 
        """
        return _pyupm_xbee.XBee_readData(self, *args)

    def readDataStr(self, *args):
        """
        readDataStr(XBee self, int len) -> std::string

        Parameters:
            len: int


        std::string
        readDataStr(int len)

        Reads any available data and returns it in a std::string. Note: the
        call blocks until data is available for reading. Use dataAvailable()
        to determine whether there is data available beforehand, to avoid
        blocking.

        Parameters:
        -----------

        len:  Maximum length of the data to be returned

        string containing the data read 
        """
        return _pyupm_xbee.XBee_readDataStr(self, *args)

    def writeData(self, *args):
        """
        writeData(XBee self, char * buffer, unsigned int len) -> int

        Parameters:
            buffer: char *
            len: unsigned int


        int writeData(char
        *buffer, unsigned len)

        Writes the data in the buffer to the device. If you are writing an AT
        command, be sure to terminate it with a carriage return ()

        Parameters:
        -----------

        buffer:  Buffer to hold the data to write

        len:  Length of the buffer

        Number of bytes written 
        """
        return _pyupm_xbee.XBee_writeData(self, *args)

    def writeDataStr(self, *args):
        """
        writeDataStr(XBee self, std::string data) -> int

        Parameters:
            data: std::string


        int
        writeDataStr(std::string data)

        Writes the std:string data to the device. If you are writing an AT
        command, be sure to terminate it with a carriage return ()

        Parameters:
        -----------

        data:  Buffer to write to the device

        Number of bytes written 
        """
        return _pyupm_xbee.XBee_writeDataStr(self, *args)

    def setBaudRate(self, baud=9600):
        """
        setBaudRate(XBee self, int baud=9600) -> mraa::Result

        Parameters:
            baud: int

        setBaudRate(XBee self) -> mraa::Result

        Parameters:
            self: upm::XBee *


        mraa::Result
        setBaudRate(int baud=9600)

        Sets the baud rate for the device. The default is 9600.

        Parameters:
        -----------

        baud:  Desired baud rate

        true if successful 
        """
        return _pyupm_xbee.XBee_setBaudRate(self, baud)

    def commandMode(self, cmdChars="+++", guardTimeMS=1000):
        """
        commandMode(XBee self, std::string cmdChars="+++", int guardTimeMS=1000) -> bool

        Parameters:
            cmdChars: std::string
            guardTimeMS: int

        commandMode(XBee self, std::string cmdChars="+++") -> bool

        Parameters:
            cmdChars: std::string

        commandMode(XBee self) -> bool

        Parameters:
            self: upm::XBee *


        bool
        commandMode(std::string cmdChars="+++", int guardTimeMS=1000)

        Attempts to enter AT Command Mode. When Idle, data sent to the device
        (assuming it is not in API mode) is silently transmitted to the
        configured destination. Running this command attempts to place the
        device into command mode, allowing you to send AT commands. Note,
        after a configurable period of inactivity, the device will exit
        command mode automatically (default 10 seconds).

        Both the cmdChars (+++) and the Guard Time can be configured on the
        device to different values using AT configuration commands.

        Parameters:
        -----------

        cmdChars:  The command mode characters, default "+++"

        guardTimeMS:  The number of milliseconds to wait before and after
        sending the command characters. Default is 1000 (1 second).

        true if successful (received an "OK"), false otherwise 
        """
        return _pyupm_xbee.XBee_commandMode(self, cmdChars, guardTimeMS)

    def stringCR2LF(self, *args):
        """
        stringCR2LF(XBee self, std::string str) -> std::string

        Parameters:
            str: std::string


        string
        stringCR2LF(std::string str)

        This is a convenience method that converts each CR () in a string to a
        LF ( ) and returns it. This is useful for outputting the response to
        an AT command for instance, which is typically CR terminated.

        Parameters:
        -----------

        str:  The string to convert

        The converted string 
        """
        return _pyupm_xbee.XBee_stringCR2LF(self, *args)

XBee_swigregister = _pyupm_xbee.XBee_swigregister
XBee_swigregister(XBee)

class charArray(_object):
    """Proxy of C++ charArray class"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, charArray, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, charArray, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        __init__(charArray self, size_t nelements) -> charArray

        Parameters:
            nelements: size_t

        """
        this = _pyupm_xbee.new_charArray(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _pyupm_xbee.delete_charArray
    __del__ = lambda self : None;
    def __getitem__(self, *args):
        """
        __getitem__(charArray self, size_t index) -> char

        Parameters:
            index: size_t

        """
        return _pyupm_xbee.charArray___getitem__(self, *args)

    def __setitem__(self, *args):
        """
        __setitem__(charArray self, size_t index, char value)

        Parameters:
            index: size_t
            value: char

        """
        return _pyupm_xbee.charArray___setitem__(self, *args)

    def cast(self):
        """
        cast(charArray self) -> char *

        Parameters:
            self: charArray *

        """
        return _pyupm_xbee.charArray_cast(self)

    def frompointer(*args):
        """
        frompointer(char * t) -> charArray

        Parameters:
            t: char *

        """
        return _pyupm_xbee.charArray_frompointer(*args)

    if _newclass:frompointer = staticmethod(frompointer)
    __swig_getmethods__["frompointer"] = lambda x: frompointer
charArray_swigregister = _pyupm_xbee.charArray_swigregister
charArray_swigregister(charArray)

def charArray_frompointer(*args):
  """
    charArray_frompointer(char * t) -> charArray

    Parameters:
        t: char *

    """
  return _pyupm_xbee.charArray_frompointer(*args)

# This file is compatible with both classic and new-style classes.


