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
            fp, pathname, description = imp.find_module('_pyupm_si114x', [dirname(__file__)])
        except ImportError:
            import _pyupm_si114x
            return _pyupm_si114x
        if fp is not None:
            try:
                _mod = imp.load_module('_pyupm_si114x', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _pyupm_si114x = swig_import_helper()
    del swig_import_helper
else:
    import _pyupm_si114x
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


SI114X_I2C_BUS = _pyupm_si114x.SI114X_I2C_BUS
SI114X_DEFAULT_I2C_ADDR = _pyupm_si114x.SI114X_DEFAULT_I2C_ADDR
SI114X_HW_KEY = _pyupm_si114x.SI114X_HW_KEY
class SI114X(_object):
    """
    API for the SI1145 UV Light Sensor.

    ID: si114x

    Name: SI1145 UV Light Sensor

    Other Names: SI1146, SI1147

    Category: light

    Manufacturer: adafruit

    Link:https://www.adafruit.com/products/1777

    Connection: i2c  This module was tested with the Adafruit* UV Light
    Sensor

    This device is capable of measuring IR and visible ambient light as
    well. It also supports the ability to use externally attached LEDs to
    perform proximity detection on 3 separate channels.

    Currently, this class only supports the retrieving of the calculated
    UV index measured by the device, but enough infrastructure is provided
    to make it easy to enhance this driver in the future to support
    additional capabilities, including interrupt support.

    C++ includes: si114x.h 
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SI114X, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SI114X, name)
    __repr__ = _swig_repr
    REG_PART_ID = _pyupm_si114x.SI114X_REG_PART_ID
    REG_REV_ID = _pyupm_si114x.SI114X_REG_REV_ID
    REG_SEQ_ID = _pyupm_si114x.SI114X_REG_SEQ_ID
    REG_INT_CFG = _pyupm_si114x.SI114X_REG_INT_CFG
    REG_IRQ_ENABLE = _pyupm_si114x.SI114X_REG_IRQ_ENABLE
    REG_IRQ_MODE1 = _pyupm_si114x.SI114X_REG_IRQ_MODE1
    REG_IRQ_MODE2 = _pyupm_si114x.SI114X_REG_IRQ_MODE2
    REG_HW_KEY = _pyupm_si114x.SI114X_REG_HW_KEY
    REG_MEAS_RATE0 = _pyupm_si114x.SI114X_REG_MEAS_RATE0
    REG_MEAS_RATE1 = _pyupm_si114x.SI114X_REG_MEAS_RATE1
    REG_PS_LED21 = _pyupm_si114x.SI114X_REG_PS_LED21
    REG_PS_LED3 = _pyupm_si114x.SI114X_REG_PS_LED3
    REG_UCOEF0 = _pyupm_si114x.SI114X_REG_UCOEF0
    REG_UCOEF1 = _pyupm_si114x.SI114X_REG_UCOEF1
    REG_UCOEF2 = _pyupm_si114x.SI114X_REG_UCOEF2
    REG_UCOEF3 = _pyupm_si114x.SI114X_REG_UCOEF3
    REG_PARAM_WR = _pyupm_si114x.SI114X_REG_PARAM_WR
    REG_COMMAND = _pyupm_si114x.SI114X_REG_COMMAND
    REG_RESPONSE = _pyupm_si114x.SI114X_REG_RESPONSE
    REG_IRQ_STATUS = _pyupm_si114x.SI114X_REG_IRQ_STATUS
    REG_ALS_VIS_DATA0 = _pyupm_si114x.SI114X_REG_ALS_VIS_DATA0
    REG_ALS_VIS_DATA1 = _pyupm_si114x.SI114X_REG_ALS_VIS_DATA1
    REG_ALS_IR_DATA0 = _pyupm_si114x.SI114X_REG_ALS_IR_DATA0
    REG_ALS_IR_DATA1 = _pyupm_si114x.SI114X_REG_ALS_IR_DATA1
    REG_PS1_DATA0 = _pyupm_si114x.SI114X_REG_PS1_DATA0
    REG_PS1_DATA1 = _pyupm_si114x.SI114X_REG_PS1_DATA1
    REG_PS2_DATA0 = _pyupm_si114x.SI114X_REG_PS2_DATA0
    REG_PS2_DATA1 = _pyupm_si114x.SI114X_REG_PS2_DATA1
    REG_PS3_DATA0 = _pyupm_si114x.SI114X_REG_PS3_DATA0
    REG_PS3_DATA1 = _pyupm_si114x.SI114X_REG_PS3_DATA1
    REG_AUX_UVINDEX0 = _pyupm_si114x.SI114X_REG_AUX_UVINDEX0
    REG_AUX_UVINDEX1 = _pyupm_si114x.SI114X_REG_AUX_UVINDEX1
    REG_PARAM_READ = _pyupm_si114x.SI114X_REG_PARAM_READ
    REG_CHIP_STAT = _pyupm_si114x.SI114X_REG_CHIP_STAT
    REG_ANA_IN_KEY0 = _pyupm_si114x.SI114X_REG_ANA_IN_KEY0
    REG_ANA_IN_KEY1 = _pyupm_si114x.SI114X_REG_ANA_IN_KEY1
    REG_ANA_IN_KEY2 = _pyupm_si114x.SI114X_REG_ANA_IN_KEY2
    REG_ANA_IN_KEY3 = _pyupm_si114x.SI114X_REG_ANA_IN_KEY3
    PARAM_I2C_ADDDR = _pyupm_si114x.SI114X_PARAM_I2C_ADDDR
    PARAM_CHLIST = _pyupm_si114x.SI114X_PARAM_CHLIST
    PARAM_PSLED12_SEL = _pyupm_si114x.SI114X_PARAM_PSLED12_SEL
    PARAM_PSLED3_SEL = _pyupm_si114x.SI114X_PARAM_PSLED3_SEL
    PARAM_PS_ENCODING = _pyupm_si114x.SI114X_PARAM_PS_ENCODING
    PARAM_ALS_ENCODING = _pyupm_si114x.SI114X_PARAM_ALS_ENCODING
    PARAM_PS1_ADCMUX = _pyupm_si114x.SI114X_PARAM_PS1_ADCMUX
    PARAM_PS2_ADCMUX = _pyupm_si114x.SI114X_PARAM_PS2_ADCMUX
    PARAM_PS3_ADCMUX = _pyupm_si114x.SI114X_PARAM_PS3_ADCMUX
    PARAM_PS_ADC_COUNT = _pyupm_si114x.SI114X_PARAM_PS_ADC_COUNT
    PARAM_PS_ADC_GAIN = _pyupm_si114x.SI114X_PARAM_PS_ADC_GAIN
    PARAM_PS_ADC_MISC = _pyupm_si114x.SI114X_PARAM_PS_ADC_MISC
    PARAM_ALS_IR_ADCMUX = _pyupm_si114x.SI114X_PARAM_ALS_IR_ADCMUX
    PARAM_AUX_ADCMUX = _pyupm_si114x.SI114X_PARAM_AUX_ADCMUX
    PARAM_ALS_VIS_ADC_COUNT = _pyupm_si114x.SI114X_PARAM_ALS_VIS_ADC_COUNT
    PARAM_ALS_VIS_ADC_GAIN = _pyupm_si114x.SI114X_PARAM_ALS_VIS_ADC_GAIN
    PARAM_ALS_VIS_ADC_MISC = _pyupm_si114x.SI114X_PARAM_ALS_VIS_ADC_MISC
    PARAM_LED_REC = _pyupm_si114x.SI114X_PARAM_LED_REC
    PARAM_ALS_IR_ADC_COUNT = _pyupm_si114x.SI114X_PARAM_ALS_IR_ADC_COUNT
    PARAM_ALS_IR_ADX_GAIN = _pyupm_si114x.SI114X_PARAM_ALS_IR_ADX_GAIN
    PARAM_ALS_IR_ADC_MISC = _pyupm_si114x.SI114X_PARAM_ALS_IR_ADC_MISC
    CMD_NOOP = _pyupm_si114x.SI114X_CMD_NOOP
    CMD_RESET = _pyupm_si114x.SI114X_CMD_RESET
    CMD_BUSADDR = _pyupm_si114x.SI114X_CMD_BUSADDR
    CMD_PS_FORCE = _pyupm_si114x.SI114X_CMD_PS_FORCE
    CMD_GET_CAL = _pyupm_si114x.SI114X_CMD_GET_CAL
    CMD_ALS_FORCE = _pyupm_si114x.SI114X_CMD_ALS_FORCE
    CMD_PSALS_FORCE = _pyupm_si114x.SI114X_CMD_PSALS_FORCE
    CMD_PS_PAUSE = _pyupm_si114x.SI114X_CMD_PS_PAUSE
    CMD_ALS_PAUSE = _pyupm_si114x.SI114X_CMD_ALS_PAUSE
    CMD_PSALS_PAUSE = _pyupm_si114x.SI114X_CMD_PSALS_PAUSE
    CMD_PS_AUTO = _pyupm_si114x.SI114X_CMD_PS_AUTO
    CMD_ALS_AUTO = _pyupm_si114x.SI114X_CMD_ALS_AUTO
    CMD_PSALS_AUTO = _pyupm_si114x.SI114X_CMD_PSALS_AUTO
    CMD_PARAM_QUERY = _pyupm_si114x.SI114X_CMD_PARAM_QUERY
    CMD_PARAM_SET = _pyupm_si114x.SI114X_CMD_PARAM_SET
    CHLIST_EN_PS1 = _pyupm_si114x.SI114X_CHLIST_EN_PS1
    CHLIST_EN_PS2 = _pyupm_si114x.SI114X_CHLIST_EN_PS2
    CHLIST_EN_PS3 = _pyupm_si114x.SI114X_CHLIST_EN_PS3
    CHLIST_EN_ALS_VIS = _pyupm_si114x.SI114X_CHLIST_EN_ALS_VIS
    CHLIST_EN_ALS_IR = _pyupm_si114x.SI114X_CHLIST_EN_ALS_IR
    CHLIST_EN_AUX = _pyupm_si114x.SI114X_CHLIST_EN_AUX
    CHLIST_EN_UV = _pyupm_si114x.SI114X_CHLIST_EN_UV
    ERR_NONE = _pyupm_si114x.SI114X_ERR_NONE
    ERR_INVALID_SET = _pyupm_si114x.SI114X_ERR_INVALID_SET
    ERR_PS1_ADC_OVER = _pyupm_si114x.SI114X_ERR_PS1_ADC_OVER
    ERR_PS2_ADC_OVER = _pyupm_si114x.SI114X_ERR_PS2_ADC_OVER
    ERR_PS3_ADC_OVER = _pyupm_si114x.SI114X_ERR_PS3_ADC_OVER
    ERR_ALS_VIS_ADC_OVER = _pyupm_si114x.SI114X_ERR_ALS_VIS_ADC_OVER
    ERR_ALS_IR_ADC_OVER = _pyupm_si114x.SI114X_ERR_ALS_IR_ADC_OVER
    ERR_AUX_ADC_OVER = _pyupm_si114x.SI114X_ERR_AUX_ADC_OVER
    IRQEN_ALS_IE = _pyupm_si114x.SI114X_IRQEN_ALS_IE
    IRQEN_PS1_IE = _pyupm_si114x.SI114X_IRQEN_PS1_IE
    IRQEN_PS2_IE = _pyupm_si114x.SI114X_IRQEN_PS2_IE
    IRQEN_PS3_IE = _pyupm_si114x.SI114X_IRQEN_PS3_IE
    def __init__(self, *args): 
        """
        __init__(upm::SI114X self, int bus, uint8_t address=0x60) -> SI114X

        Parameters:
            bus: int
            address: uint8_t

        __init__(upm::SI114X self, int bus) -> SI114X

        Parameters:
            bus: int


        SI114X(int bus, uint8_t
        address=SI114X_DEFAULT_I2C_ADDR)

        SI114X constructor

        Parameters:
        -----------

        bus:  I2C bus to use

        address:  Address for this device 
        """
        this = _pyupm_si114x.new_SI114X(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _pyupm_si114x.delete_SI114X
    __del__ = lambda self : None;
    def writeByte(self, *args):
        """
        writeByte(SI114X self, uint8_t reg, uint8_t byte) -> bool

        Parameters:
            reg: uint8_t
            byte: uint8_t


        bool writeByte(uint8_t
        reg, uint8_t byte)

        Writes a byte value into a register

        Parameters:
        -----------

        reg:  Register location to write into

        byte:  Byte to write

        True if successful 
        """
        return _pyupm_si114x.SI114X_writeByte(self, *args)

    def readByte(self, *args):
        """
        readByte(SI114X self, uint8_t reg) -> uint8_t

        Parameters:
            reg: uint8_t


        uint8_t
        readByte(uint8_t reg)

        Reads a byte value from a register

        Parameters:
        -----------

        reg:  Register location to read from

        Value in a specified register 
        """
        return _pyupm_si114x.SI114X_readByte(self, *args)

    def readWord(self, *args):
        """
        readWord(SI114X self, uint8_t reg) -> uint16_t

        Parameters:
            reg: uint8_t


        uint16_t
        readWord(uint8_t reg)

        Reads a word value from a register

        Parameters:
        -----------

        reg:  Register location to read from

        Value in a specified register 
        """
        return _pyupm_si114x.SI114X_readWord(self, *args)

    def reset(self):
        """
        reset(SI114X self)

        Parameters:
            self: upm::SI114X *


        void reset()

        Disables interrupts and auto-measuring, issues a device reset, and
        then sets the hardware key. 
        """
        return _pyupm_si114x.SI114X_reset(self)

    def setUVCalibration(self, *args):
        """
        setUVCalibration(SI114X self, uint8_t uvcoeff0, uint8_t uvcoeff1, uint8_t uvcoeff2, uint8_t uvcoeff3)

        Parameters:
            uvcoeff0: uint8_t
            uvcoeff1: uint8_t
            uvcoeff2: uint8_t
            uvcoeff3: uint8_t


        void
        setUVCalibration(uint8_t uvcoeff0, uint8_t uvcoeff1, uint8_t uvcoeff2,
        uint8_t uvcoeff3)

        Sets UV calibration values. The constructor sets default values for
        you, so you only need this function if you need different values for
        your device and situation. If you set new values here, be sure to do
        so before calling initialize().

        Parameters:
        -----------

        uvcoeff0:  Coefficient for REG_UCOEF0

        uvcoeff1:  Coefficient for REG_UCOEF1

        uvcoeff2:  Coefficient for REG_UCOEF2

        uvcoeff3:  Coefficient for REG_UCOEF3 
        """
        return _pyupm_si114x.SI114X_setUVCalibration(self, *args)

    def writeParam(self, *args):
        """
        writeParam(SI114X self, upm::SI114X::SI114X_PARAM_T param, uint8_t value)

        Parameters:
            param: enum upm::SI114X::SI114X_PARAM_T
            value: uint8_t


        void
        writeParam(SI114X_PARAM_T param, uint8_t value)

        Writes a value to the parameter memory.

        Parameters:
        -----------

        param:  SI114X_PARAM_T register to write

        value:  Value to write 
        """
        return _pyupm_si114x.SI114X_writeParam(self, *args)

    def readParam(self, *args):
        """
        readParam(SI114X self, upm::SI114X::SI114X_PARAM_T param) -> uint8_t

        Parameters:
            param: enum upm::SI114X::SI114X_PARAM_T


        uint8_t
        readParam(SI114X_PARAM_T param)

        Reads a value from the parameter memory

        Parameters:
        -----------

        param:  SI114X_PARAM_T register to read

        Value 
        """
        return _pyupm_si114x.SI114X_readParam(self, *args)

    def initialize(self):
        """
        initialize(SI114X self)

        Parameters:
            self: upm::SI114X *


        void initialize()

        Resets and initializes the device and starts auto-sampling 
        """
        return _pyupm_si114x.SI114X_initialize(self)

    def update(self):
        """
        update(SI114X self)

        Parameters:
            self: upm::SI114X *


        void update()

        Updates stored values. You should call this before calling
        getUVIndex() 
        """
        return _pyupm_si114x.SI114X_update(self)

    def getUVIndex(self):
        """
        getUVIndex(SI114X self) -> float

        Parameters:
            self: upm::SI114X *


        float getUVIndex()

        Reads the currently measured UV index value

        UV index value 
        """
        return _pyupm_si114x.SI114X_getUVIndex(self)

SI114X_swigregister = _pyupm_si114x.SI114X_swigregister
SI114X_swigregister(SI114X)

# This file is compatible with both classic and new-style classes.


