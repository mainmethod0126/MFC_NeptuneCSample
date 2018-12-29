
#pragma once

#if defined(_WINDOWS)
	#if defined(_NEPTUNE_EXPORTS)
		#define NEPTUNE_C_API __declspec(dllexport)
	#else
		#define NEPTUNE_C_API __declspec(dllimport)
		
		#pragma comment(lib, "NeptuneC_MD_VC100.lib")
	#endif
#endif


#pragma region NUMBER_DEFINE
#define MAX_NODE_LIST_COUNT				128	// for XML tree node
#define MAX_ENUM_LIST_COUNT				64	// for enumeration
#define MAX_XML_NODE_STRING_LENGTH		256
#define MAX_STRING_LENGTH				512
#define MAC_LENGTH						32
#define MAX_INTERFACE_NUM				140
#define	MAX_TRIGGER_PARAM				255
#define KNEE_POINT_TABLE_SIZE			4
#define USER_LUT_TABLE_SIZE				4096
#pragma endregion


#pragma region VARIABLE_DEFINE
typedef void*					NeptuneCamHandle;
typedef unsigned char			_bool8_t;
typedef char					_char_t;
typedef unsigned char			_uchar_t;
typedef __int8					_int8_t;
typedef unsigned __int8			_uint8_t;
typedef __int16					_int16_t;
typedef unsigned __int16		_uint16_t;
typedef __int32					_int32_t;
typedef unsigned __int32		_uint32_t;
typedef __int64					_int64_t;
typedef unsigned __int64		_uint64_t;
typedef long					_long32_t;
typedef unsigned long			_ulong32_t;
typedef long long				_long64_t;
typedef unsigned long long		_ulong64_t;
typedef double					_double_t;
typedef float					_float32_t;
#pragma endregion


#pragma region ENUMERATE_DEFINE
typedef enum _tagENeptuneError {
	NEPTUNE_ERR_Fail					= -1,
	NEPTUNE_ERR_Success					= 0,
	NEPTUNE_ERR_AlreadyInitialized		= -100,
	NEPTUNE_ERR_APINotInitialized		= -101,
	NEPTUNE_ERR_NotInitialized			= -102,
	NEPTUNE_ERR_GC						= -103,
	NEPTUNE_ERR_TimeOut					= -104,
	NEPTUNE_ERR_NotSupportedFunc		= -105,
	NEPTUNE_ERR_OpenXML					= -106,
	NEPTUNE_ERR_InvalidValue			= -107,
	NEPTUNE_ERR_EventChannel			= -108,
	NEPTUNE_ERR_NotReady				= -109,
	NEPTUNE_ERR_PacketResend			= -110,
	NEPTUNE_ERR_InvalidFeatureRange		= -111,
	NEPTUNE_ERR_TLInterface				= -112,
	NEPTUNE_ERR_TLDevOpen				= -113,
	NEPTUNE_ERR_TLDevPort				= -114,
	NEPTUNE_ERR_TLDevURL				= -115,
	NEPTUNE_ERR_GrabTimeout				= -116,
	NEPTUNE_ERR_DeviceNotExist			= -117,
	NEPTUNE_ERR_TLInitFail				= -200,
	NEPTUNE_ERR_NoInterface				= -201,
	NEPTUNE_ERR_DeviceCheck				= -202,
	NEPTUNE_ERR_InvalidParameter		= -203,
	NEPTUNE_ERR_NotSupport				= -204,
	NEPTUNE_ERR_AccessDenied			= -205,
	NEPTUNE_ERR_InvalidAddress			= -206,
	NEPTUNE_ERR_InvalidArraySize		= -207,
	NEPTUNE_ERR_Interface				= -208,
	NEPTUNE_ERR_DeviceInfo				= -209,
	NEPTUNE_ERR_MemoryAlloc				= -210,
	NEPTUNE_ERR_DeviceOpen				= -211,
	NEPTUNE_ERR_DevicePort				= -212,
	NEPTUNE_ERR_DeviceURL				= -213,
	NEPTUNE_ERR_DeviceWrite				= -214,
	NEPTUNE_ERR_DeviceXML				= -215,
	NEPTUNE_ERR_DeviceHeartbeat			= -216,
	NEPTUNE_ERR_DeviceClose				= -217,
	NEPTUNE_ERR_DeviceNotStreaming		= -218,
	NEPTUNE_ERR_InvalidXMLNode			= -300,
	NEPTUNE_ERR_StreamCount				= -303,
	NEPTUNE_ERR_AccessTimeOut			= -304,
	NEPTUNE_ERR_OutOfRange				= -305,
	NEPTUNE_ERR_InvalidChannel			= -306,
	NEPTUNE_ERR_InvalidBuffer			= -307,
	NEPTUNE_ERR_FileAccessError			= -400,
	NEPTUNE_ERR_GrabFrameDropped		= -450
} ENeptuneError;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneBoolean {
	NEPTUNE_BOOL_FALSE		= 0,
	NEPTUNE_BOOL_TRUE		= 1
} ENeptuneBoolean;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneEffect {
	NEPTUNE_EFFECT_NONE		= 0,
	NEPTUNE_EFFECT_FLIP		= 0x01,		// flip image
	NEPTUNE_EFFECT_MIRROR	= 0x02,		// mirror
	NEPTUNE_EFFECT_NEGATIVE	= 0x04		// negative
} ENeptuneEffect;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneAutoMode {
	NEPTUNE_AUTO_OFF				= 0,		// manual mode
	NEPTUNE_AUTO_ONCE				= 1,		// once(one-shot) mode
	NEPTUNE_AUTO_CONTINUOUS			= 2			// auto mode
} ENeptuneAutoMode;	
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptunePixelFormat {
	Unknown_PixelFormat			= -1,
	// 1394 Camera pixel format list.
	Format0_320x240_YUV422		= 0,
	Format0_640x480_YUV411		= 1,
	Format0_640x480_YUV422		= 2,
	Format0_640x480_Mono8		= 3,
	Format0_640x480_Mono16		= 4,
	Format1_800x600_YUV422		= 5,
	Format1_800x600_Mono8		= 6,
	Format1_1024x768_YUV422		= 7,
	Format1_1024x768_Mono8		= 8,
	Format1_800x600_Mono16		= 9,
	Format1_1024x768_Mono16		= 10,

	Format2_1280x960_YUV422		= 11,
	Format2_1280x960_Mono8		= 12,
	Format2_1600x1200_YUV422	= 13,
	Format2_1600x1200_Mono8		= 14,
	Format2_1280x960_Mono16		= 15,
	Format2_1600x1200_Mono16	= 16,

	Format7_Mode0_Mono8			= 17,
	Format7_Mode0_YUV411		= 18,
	Format7_Mode0_YUV422		= 19,
	Format7_Mode0_Mono16		= 20,
	Format7_Mode0_Raw8			= 21,
	Format7_Mode0_Raw16			= 22,
	Format7_Mode0_Mono12		= 23,
	Format7_Mode0_Raw12			= 24,

	Format7_Mode1_Mono8			= 25,
	Format7_Mode1_YUV411		= 26,
	Format7_Mode1_YUV422		= 27,
	Format7_Mode1_Mono16		= 28,
	Format7_Mode1_Raw8			= 29,
	Format7_Mode1_Raw16			= 30,
	Format7_Mode1_Mono12		= 31,
	Format7_Mode1_Raw12			= 32,

	Format7_Mode2_Mono8			= 33,
	Format7_Mode2_YUV411		= 34,
	Format7_Mode2_YUV422		= 35,
	Format7_Mode2_Mono16		= 36,
	Format7_Mode2_Raw8			= 37,
	Format7_Mode2_Raw16			= 38,
	Format7_Mode2_Mono12		= 39,
	Format7_Mode2_Raw12			= 40,

	// GigE/USB3 Camera pixel format list.
	Mono8						= 101,
	Mono10						= 102,
	Mono12						= 103,
	Mono16						= 104,
	BayerGR8					= 105,
	BayerGR10					= 106,		
	BayerGR12					= 107,		
	YUV411Packed				= 108,
	YUV422Packed				= 109,
	YUV422_8					= 110,
	BayerRG8					= 111,
	BayerRG12					= 112,
	BayerGB8					= 113,
	BayerGB12					= 114,
	BayerBG8					= 115,
	BayerBG12					= 116,
	Profile32					= 117
} ENeptunePixelFormat;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptunePixelType {
	NEPTUNE_PIXEL_MONO			= 1,
	NEPTUNE_PIXEL_BAYER			= 2,
	NEPTUNE_PIXEL_RGB			= 3,
	NEPTUNE_PIXEL_YUV			= 4,
	NEPTUNE_PIXEL_RGBPLANAR		= 5,
	NEPTUNE_PIXEL_YUV_8			= 6,
	NEPTUNE_PIXEL_MONO_OR_BAYER		= 7
} ENeptunePixelType;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneFrameRate {
	FPS_UNKNOWN			= -1,
	FPS_1_875			= 0,			// 1.875 frame (1394 camera)
	FPS_3_75			= 1,			// 3.75 frame (1394 camera)
	FPS_7_5				= 2,			// 7.5 frame (1394 camera)
	FPS_15				= 3,			// 15 frame (1394 camera)
	FPS_30				= 4,			// 30 frame (1394 camera)
	FPS_60				= 5,			// 60 frame (1394 camera)
	FPS_120				= 6,			// 120 frame (1394 camera)
	FPS_240				= 7,			// 240 frame (1394 camera)
	FPS_VALUE			= 20			// frame rate value(GigE and USB3 camera)
} ENeptuneFrameRate;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneBayerLayout {
	NEPTUNE_BAYER_GB_RG = 0,		// GB/RG layout
	NEPTUNE_BAYER_BG_GR = 1,		// BG/GR layout
	NEPTUNE_BAYER_RG_GB = 2,		// RG/GB layout
	NEPTUNE_BAYER_GR_BG = 3			// GR/BG layout
} ENeptuneBayerLayout;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneBayerMethod {
	NEPTUNE_BAYER_METHOD_NONE = 0,			// no bayer conversion
	NEPTUNE_BAYER_METHOD_BILINEAR = 1,		// bilinear conversion
	NEPTUNE_BAYER_METHOD_HQ = 2,			// HQ conversion
	NEPTUNE_BAYER_METHOD_NEAREST = 3		// nearest conversion
} ENeptuneBayerMethod;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneAcquisitionMode {
	NEPTUNE_ACQ_CONTINUOUS		= 0,			// continuous
	NEPTUNE_ACQ_MULTIFRAME		= 1,			// multi frame
	NEPTUNE_ACQ_SINGLEFRAME		= 2				// single frame
} ENeptuneAcquisitionMode;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneStreamMode {
	NEPTUNE_STRM_UNICAST	= 0,
	NEPTUNE_STRM_MULTICAST	= 1
} ENeptuneStreamMode;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneImageFormat
{
	NEPTUNE_IMAGE_FORMAT_UNKNOWN	= -1,
	NEPTUNE_IMAGE_FORMAT_BMP		= 0,
	NEPTUNE_IMAGE_FORMAT_JPG		= 1,
	NEPTUNE_IMAGE_FORMAT_TIF		= 2
} ENeptuneImageFormat;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneGrabFormat
{
	NEPTUNE_GRAB_RAW	= 0,
	NEPTUNE_GRAB_RGB	= 1,
	NEPTUNE_GRAB_RGB32	= 2
} ENeptuneGrabFormat;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneDeviceChangeState
{
	NEPTUNE_DEVICE_ADDED		= 0,	// camera count is increased
	NEPTUNE_DEVICE_REMOVED		= 1		// camera count is decreased
} ENeptuneDeviceChangeState;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneRotationAngle
{
	NEPTUNE_ROTATE_0		= 0,		// 0 degree
	NEPTUNE_ROTATE_90		= 1,		// 90 degree
	NEPTUNE_ROTATE_180		= 2,		// 180 degree
	NEPTUNE_ROTATE_270		= 3			// 270 degree
} ENeptuneRotationAngle;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneCameraListOpt
{
	NEPTUNE_CAMERALISTOPT_ONLYIMI = 0,
	NEPTUNE_CAMERALISTOPT_ALL = 1
} ENeptuneCameraListOpt;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneDisplayOption
{
	NEPTUNE_DISPLAY_OPTION_FIT = 0,
	NEPTUNE_DISPLAY_OPTION_ORIGINAL_CENTER = 1
} ENeptuneDisplayOption;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptune1394Foramt
{
	FORMAT_0 = 0,
	FORMAT_1 = 1,
	FORMAT_2 = 2,
	FORMAT_7 = 7
} ENeptune1394Foramt;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneDevType {
	NEPTUNE_DEV_TYPE_UNKNOWN	= -1,	// unknown camera
	NEPTUNE_DEV_TYPE_1394		= 0,	// 1394 camera
	NEPTUNE_DEV_TYPE_USB3		= 1,	// USB3 Vision camera
	NEPTUNE_DEV_TYPE_GIGE		= 2		// GigE camera
} ENeptuneDevType;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneDevAccess {
	NEPTUNE_DEV_ACCESS_UNKNOWN		= -1,
	NEPTUNE_DEV_ACCESS_EXCLUSIVE	= 0,
	NEPTUNE_DEV_ACCESS_CONTROL		= 1,
	NEPTUNE_DEV_ACCESS_MONITOR		= 2
} ENeptuneDevAccess;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneFeature {
	NEPTUNE_FEATURE_GAMMA				= 0,	// AnalogControls, Gamma
	NEPTUNE_FEATURE_GAIN				= 1,	// AnalogControls, Gain or GainRaw
	NEPTUNE_FEATURE_RGAIN				= 2,	// AnalogControls, Gain or GainRaw
	NEPTUNE_FEATURE_GGAIN				= 3,	// AnalogControls, Gain or GainRaw
	NEPTUNE_FEATURE_BGAIN				= 4,	// AnalogControls, Gain or GainRaw
	NEPTUNE_FEATURE_BLACKLEVEL			= 5,	// AnalogControls, BlackLevel or BlackLevelRaw
	NEPTUNE_FEATURE_SHARPNESS			= 6,	// AnalogControls, Sharpness or SharpnessRaw
	NEPTUNE_FEATURE_SATURATION			= 7,	// AnalogControls, Saturation or SaturationRaw
	NEPTUNE_FEATURE_AUTOEXPOSURE		= 8,	// AcquisitionControl, AutoExposure
	NEPTUNE_FEATURE_SHUTTER				= 9,	// AcquisitionControl, ExposureTime
	NEPTUNE_FEATURE_HUE					= 10,	// AnalogControls, Hue or HueRaw
	NEPTUNE_FEATURE_PAN					= 11,	// AcquisitionControl, PanCtrl
	NEPTUNE_FEATURE_TILT				= 12,	// AcquisitionControl, TiltCtrl
	NEPTUNE_FEATURE_OPTFILTER			= 13,	// AnalogControls, OpticalFilter
	NEPTUNE_FEATURE_AUTOSHUTTER_MIN		= 14,	// CustomControl, AutoShutterSpeedMin
	NEPTUNE_FEATURE_AUTOSHUTTER_MAX		= 15,	// CustomControl, AutoShutterSpeedMin
	NEPTUNE_FEATURE_AUTOGAIN_MIN		= 16,	// CustomControl, AutoGainMin
	NEPTUNE_FEATURE_AUTOGAIN_MAX		= 17,	// CustomControl, AutoGainMax
	NEPTUNE_FEATURE_TRIGNOISEFILTER		= 18,	// CustomControl, TriggerNoiseFilter
	NEPTUNE_FEATURE_BRIGHTLEVELIRIS		= 19,	// CustomControl, BrightLevelForIRIS (Read Only)
	NEPTUNE_FEATURE_SNOWNOISEREMOVE		= 20,	// CustomControl, SnowNosieRemoveControl
	NEPTUNE_FEATURE_WATCHDOG			= 21,	// CustomControl, WDGControl
	NEPTUNE_FEATURE_WHITEBALANCE		= 22,	// AnalogControls, BalanceWhiteAudo
	NEPTUNE_FEATURE_CONTRAST			= 23,	// CustomControl, Contrast
	NEPTUNE_FEATURE_LCD_BLUE_GAIN		= 24,	// CustomControl, LED_BLUE_GAIN
	NEPTUNE_FEATURE_LCD_RED_GAIN		= 25	// CustomControl, LED_RED_GAIN
} ENeptuneFeature;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneUserSet {
	NEPTUNE_USERSET_DEFAULT		= 0,
	NEPTUNE_USERSET_1			= 1,
	NEPTUNE_USERSET_2			= 2,
	NEPTUNE_USERSET_3			= 3,
	NEPTUNE_USERSET_4			= 4,
	NEPTUNE_USERSET_5			= 5,
	NEPTUNE_USERSET_6			= 6,
	NEPTUNE_USERSET_7			= 7,
	NEPTUNE_USERSET_8			= 8,
	NEPTUNE_USERSET_9			= 9,
	NEPTUNE_USERSET_10			= 10,
	NEPTUNE_USERSET_11			= 11,
	NEPTUNE_USERSET_12			= 12,
	NEPTUNE_USERSET_13			= 13,
	NEPTUNE_USERSET_14			= 14,
	NEPTUNE_USERSET_15			= 15
} ENeptuneUserSet;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneUserSetCommand {
	NEPTUNE_USERSET_CMD_LOAD	= 0,
	NEPTUNE_USERSET_CMD_SAVE	= 1
} ENeptuneUserSetCommand;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneAutoIrisMode {
	NEPTUNE_AUTOIRIS_MODE_MANUAL = 0,
	NEPTUNE_AUTOIRIS_MODE_AUTO	 = 1
} ENeptuneAutoIrisMode;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneSIOParity {
	NEPTUNE_SIO_PARITY_NONE		= 0,
	NEPTUNE_SIO_PARITY_ODD		= 1,
	NEPTUNE_SIO_PARITY_EVEN		= 2
} ENeptuneSIOParity;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneAutoAreaSelect {
	NEPTUNE_AUTOAREA_SELECT_AE		= 0,	// for AutoExposure
	NEPTUNE_AUTOAREA_SELECT_AWB		= 1,	// for AutoWhiteBalance
	NEPTUNE_AUTOAREA_SELECT_AF		= 2		// for AutoFocus
} ENeptuneAutoAreaSelect;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneAutoAreaSize {
	NEPTUNE_AUTOAREA_SIZE_SELECTED	= 0,	// selected size
	NEPTUNE_AUTOAREA_SIZE_FULL		= 1		// full image size
} ENeptuneAutoAreaSize;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneAFMode {
	NEPTUNE_AF_ORIGIN			= 0,		// set focus to origin point
	NEPTUNE_AF_ONEPUSH			= 1,		// one-push auto focus
	NEPTUNE_AF_STEP_FORWARD		= 2,		// move one step forward
	NEPTUNE_AF_STEP_BACKWARD	= 3			// move one step backward
} ENeptuneAFMode;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneTriggerSource {
	NEPTUNE_TRIGGER_SOURCE_LINE1	= 0,	// external(H/W trigger)
	NEPTUNE_TRIGGER_SOURCE_SW		= 7		// software trigger
} ENeptuneTriggerSource;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneTriggerMode {
	NEPTUNE_TRIGGER_MODE_0 = 0,		// trigger mode 0
	NEPTUNE_TRIGGER_MODE_1,			// trigger mode 1
	NEPTUNE_TRIGGER_MODE_2,			// trigger mode 2
	NEPTUNE_TRIGGER_MODE_3,			// trigger mode 3
	NEPTUNE_TRIGGER_MODE_4,			// trigger mode 4
	NEPTUNE_TRIGGER_MODE_5,			// trigger mode 5
	NEPTUNE_TRIGGER_MODE_6,			// trigger mode 6
	NEPTUNE_TRIGGER_MODE_7,			// trigger mode 7
	NEPTUNE_TRIGGER_MODE_8,			// trigger mode 8
	NEPTUNE_TRIGGER_MODE_9,			// trigger mode 9
	NEPTUNE_TRIGGER_MODE_10,		// trigger mode 10
	NEPTUNE_TRIGGER_MODE_11,		// trigger mode 11
	NEPTUNE_TRIGGER_MODE_12,		// trigger mode 12
	NEPTUNE_TRIGGER_MODE_13,		// trigger mode 13
	NEPTUNE_TRIGGER_MODE_14,		// trigger mode 14
	NEPTUNE_TRIGGER_MODE_15			// trigger mode 15
} ENeptuneTriggerMode;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneStrobe {
	NEPTUNE_STROBE0			= 0,
	NEPTUNE_STROBE1			= 1,
	NEPTUNE_STROBE2			= 2,
	NEPTUNE_STROBE3			= 3,
	NEPTUNE_STROBE4			= 4
} ENeptuneStrobe;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptunePolarity {
	NEPTUNE_POLARITY_RISINGEDGE		= 0,	// rising edge
	NEPTUNE_POLARITY_FALLINGEDGE	= 1,	// falling edge
	NEPTUNE_POLARITY_ANYEDGE		= 2,	// any edge
	NEPTUNE_POLARITY_LEVELHIGH		= 3,	// high level
	NEPTUNE_POLARITY_LEVELLOW		= 4		// low level
} ENeptunePolarity;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneNodeType {
	NEPTUNE_NODE_TYPE_UKNOWN		= -1,
	NEPTUNE_NODE_TYPE_CATEGORY		= 0,
	NEPTUNE_NODE_TYPE_COMMAND,				// command type node
	NEPTUNE_NODE_TYPE_RAW,					// raw node
	NEPTUNE_NODE_TYPE_STRING,				// string node
	NEPTUNE_NODE_TYPE_ENUM,					// enumeration node
	NEPTUNE_NODE_TYPE_INT,					// int type node
	NEPTUNE_NODE_TYPE_FLOAT,				// float type node
	NEPTUNE_NODE_TYPE_BOOLEAN				// boolean type node
} ENeptuneNodeType;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneNodeAccessMode {
	NEPTUNE_NODE_ACCESSMODE_NI			= 0,		// Not Implemented
	NEPTUNE_NODE_ACCESSMODE_NA			= 1,		// Not Available
	NEPTUNE_NODE_ACCESSMODE_WO			= 2,		// Write Only
	NEPTUNE_NODE_ACCESSMODE_RO			= 3,		// Read Only
	NEPTUNE_NODE_ACCESSMODE_RW			= 4,		// Read, Write
	NEPTUNE_NODE_ACCESSMODE_UNDEFINED	= 5			// undefined
} ENeptuneNodeAccessMode;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneNodeVisibility {
	NEPTUNE_NODE_VISIBLE_UNKNOWN		= -1,
	NEPTUNE_NODE_VISIBLE_BEGINNER		= 0,		// beginner
	NEPTUNE_NODE_VISIBLE_EXPERT			= 1,		// expert
	NEPTUNE_NODE_VISIBLE_GURU			= 2			// guru
} ENeptuneNodeVisibility;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneGPIO {
	NEPTUNE_GPIO_LINE0 = 0,		// GPIO 0
	NEPTUNE_GPIO_LINE1			// GPIO 1
} ENeptuneGPIO;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneGPIOSource {
	NEPTUNE_GPIO_SOURCE_STROBE = 0,	// strobe
	NEPTUNE_GPIO_SOURCE_USER		// user defined
} ENeptuneGPIOSource;
//////////////////////////////////////////////////////////////////////////
typedef enum _tagENeptuneGPIOValue {
	NEPTUNE_GPIO_VALUE_LOW = 0,		// low level
	NEPTUNE_GPIO_VALUE_HIGH			// high level
} ENeptuneGPIOValue;
#pragma endregion


#pragma region STRUCT_DEFINE
#pragma pack(push, 1)
typedef struct _tagNEPTUNE_CAM_INFO {
	_char_t				strVendor[MAX_STRING_LENGTH];	// camera vendor name
	_char_t				strModel[MAX_STRING_LENGTH];	// camera model name
	_char_t				strSerial[MAX_STRING_LENGTH];	// camera serial number
	_char_t				strUserID[MAX_STRING_LENGTH];	// user ID
	_char_t				strIP[MAX_STRING_LENGTH];		// IP address(GigE camera)
	_char_t				strMAC[MAC_LENGTH];				// MAC address(GigE camera)
	_char_t				strSubnet[MAX_STRING_LENGTH];	// Subnet address(GigE camera)
	_char_t				strGateway[MAX_STRING_LENGTH];	// Gateway address(GigE camera)
	_char_t				strCamID[MAX_STRING_LENGTH];	// unique Camera ID

	_tagNEPTUNE_CAM_INFO() {
		memset(strVendor, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strModel, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strSerial, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strUserID, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strIP, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strMAC, 0, sizeof(_char_t)*MAC_LENGTH);
		memset(strSubnet, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strGateway, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strCamID, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
	}
} NEPTUNE_CAM_INFO, *PNEPTUNE_CAM_INFO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_IMAGE_SIZE {
	_int32_t		nStartX;	// start point of X coordinate(width direction)
	_int32_t		nStartY;	// start point of Y coordinate(height direction)
	_int32_t		nSizeX;		// width 
	_int32_t		nSizeY;		// height

	_tagNEPTUNE_IMAGE_SIZE() {
		nStartY = 0;
		nStartY = 0;
		nSizeX = 0;
		nSizeY = 0;
	}
} NEPTUNE_IMAGE_SIZE, *PNEPTUNE_IMAGE_SIZE;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_IMAGE {
	_uint32_t 				uiWidth;		// image data width
	_uint32_t 				uiHeight;		// image data height
	_uint32_t 				uiBitDepth;		// data bits per pixel
	_uchar_t*				pData;			// image buffer
	_uint32_t				uiSize;			// buffer length
	_uint32_t				uiIndex;		// buffer index
	_uint64_t 				uiTimestamp;	// data timestamp
	_uchar_t				bFrameValid;	// flag for frame state : 1(Valid), 0(Invalid)

	_tagNEPTUNE_IMAGE() {
		uiWidth = 0;
		uiHeight = 0;
		uiBitDepth = 0;
		pData = NULL;
		uiSize = 0;
		uiIndex = 0;
		uiTimestamp = 0;
		bFrameValid = 1;	
	}
} NEPTUNE_IMAGE, *PNEPTUNE_IMAGE;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_FEATURE {
	ENeptuneBoolean			bSupport;
	ENeptuneBoolean			bOnOff;				// on/off state, on/off control(SnowNoiseRemove only)
	_uint8_t				SupportAutoModes;	// bit flag for support(bit0:Off, bit1:Once, bit2:Continuous)
	ENeptuneAutoMode		AutoMode;			// current Auto mode, valid only when "SuporeAutoMode != 0"
	_int32_t				Min;				// minimum value
	_int32_t				Max;				// maximum value
	_int32_t				Inc;				// increment step
	_int32_t				Value;				// current value
	ENeptuneNodeAccessMode	ValueAccessMode;	// access state of the value		

	_tagNEPTUNE_FEATURE() {
		bOnOff = NEPTUNE_BOOL_TRUE;
		bSupport = NEPTUNE_BOOL_FALSE;
		SupportAutoModes = 0;
		AutoMode = NEPTUNE_AUTO_OFF;
		Min = 0;		// minimum value
		Max = 0;		// maximum value
		Inc = 0;		// increment step
		Value = 0;		// current value
		ValueAccessMode = NEPTUNE_NODE_ACCESSMODE_NA;
	}
} NEPTUNE_FEATURE, *PNEPTUNE_FEATURE;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_PACKAGE_FEATURE {
	_uint32_t Gain;	
	_uint32_t Sharpness;
	_uint32_t Shutter;	
	_uint32_t BlackLevel;
	_uint32_t Contrast;
	_uint32_t Gamma;
} NEPTUNE_PACKAGE_FEATURE, *PNEPTUNE_PACKAGE_FEATURE;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_USERSET {
	_uint16_t					SupportUserSet;		// bit flag for supported user set, 0 is "Default"
	ENeptuneUserSet				UserSetIndex;		// user set index to save or load
	ENeptuneUserSetCommand		Command;			// save or load

	_tagNEPTUNE_USERSET() {
		SupportUserSet = 0;
		UserSetIndex = NEPTUNE_USERSET_DEFAULT;
		Command = NEPTUNE_USERSET_CMD_LOAD;
	}
} NEPTUNE_USERSET, *PNEPTUNE_USERSET;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_POINT {
	_uint32_t	x;		// x-coordinate
	_uint32_t	y;		// y-coordinate

	_tagNEPTUNE_POINT() {
		x = 0;
		y = 0;
	}
} NEPTUNE_POINT, *PNEPTUNE_POINT;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_KNEE_LUT {
	NEPTUNE_POINT		Points[KNEE_POINT_TABLE_SIZE];		// 4 points
	ENeptuneBoolean		bEnable;							// enable/disable state/control

	_tagNEPTUNE_KNEE_LUT() {
		bEnable = NEPTUNE_BOOL_FALSE;
		memset(Points, 0, sizeof(NEPTUNE_POINT)*KNEE_POINT_TABLE_SIZE);
	}
} NEPTUNE_KNEE_LUT, *PNEPTUNE_KNEE_LUT;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_USER_LUT {
	_uint16_t			SupportLUT;					// bit Flag
	_uint16_t			LUTIndex;					// current LUT index
	ENeptuneBoolean		bEnable;					// enable/disable state/control
	_uint16_t			Data[USER_LUT_TABLE_SIZE];	// LUT data, valid only in Set function

	_tagNEPTUNE_USER_LUT() {
		SupportLUT = 0;
		LUTIndex = 0;
		bEnable = NEPTUNE_BOOL_FALSE;
		memset(Data, 0, sizeof(_uint16_t)*USER_LUT_TABLE_SIZE);
	}
} NEPTUNE_USER_LUT, *PNEPTUNE_USER_LUT;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_SIO_PROPERTY {
	ENeptuneBoolean		bEnable;	// RS232 enable
	_uint32_t			Baudrate;	// serial baudrate
	ENeptuneSIOParity	Parity;		// parity bit
	_uint32_t			DataBit;	// data bit
	_uint32_t			StopBit;	// stop bit

	_tagNEPTUNE_SIO_PROPERTY() {
		bEnable = NEPTUNE_BOOL_FALSE;
		Baudrate = 9600;
		Parity = NEPTUNE_SIO_PARITY_NONE;
		DataBit = 8;
		StopBit = 1;
	}
} NEPTUNE_SIO_PROPERTY, *PNEPTUNE_SIO_PROPERTY;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_SIO {
	_uint32_t		TextCount;		// should be smaller than or equal to 256
	_char_t			strText[256];	// RS232 data
	_uint32_t		TimeOut;		// in ms unit

	_tagNEPTUNE_SIO() {
		TextCount = 0;
		memset(strText, 0, sizeof(_char_t)*256);
		TimeOut = 100;
	}
} NEPTUNE_SIO, *PNEPTUNE_SIO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_AUTOAREA {
	ENeptuneBoolean			OnOff;
	ENeptuneAutoAreaSize	SizeControl;
	NEPTUNE_IMAGE_SIZE		AreaSize;

	_tagNEPTUNE_AUTOAREA() {
		OnOff = NEPTUNE_BOOL_FALSE;
		SizeControl = NEPTUNE_AUTOAREA_SIZE_FULL;
		memset(&AreaSize, 0, sizeof(NEPTUNE_IMAGE_SIZE));
	};
} NEPTUNE_AUTOAREA, *PNEPTUNE_AUTOAREA;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_TRIGGER_INFO {
	ENeptuneBoolean		bSupport;		// trigger support flag
	_uint16_t			nModeFlag;		// bit mask for trigger mode
	_uint16_t			nSourceFlag;	// bit mask for trigger source (bit0 = H/W, bit7 = S/W)
	_uint16_t			nPolarityFlag;	// bit mask for polarity
	_uint16_t			nParamMin;		// trigger parameter minimum value
	_uint16_t			nParamMax;		// trigger parameter maximum value

	_tagNEPTUNE_TRIGGER_INFO() {
		bSupport = NEPTUNE_BOOL_FALSE;
		nModeFlag = 0;
		nSourceFlag = 0;
		nPolarityFlag = 0;
		nParamMin = 0;
		nParamMax = 0;
	}
} NEPTUNE_TRIGGER_INFO, *PNEPTUNE_TRIGGER_INFO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_TRIGGER {
	ENeptuneTriggerSource		Source;		// trigger source value
	ENeptuneTriggerMode			Mode;		// trigger mode value
	ENeptunePolarity			Polarity;	// trigger polarity value
	ENeptuneBoolean				OnOff;		// trigger on/off
	_uint16_t					nParam;		// trigger parameter

	_tagNEPTUNE_TRIGGER() {
		OnOff = NEPTUNE_BOOL_FALSE;
		Mode = NEPTUNE_TRIGGER_MODE_0;
		Source = NEPTUNE_TRIGGER_SOURCE_LINE1;
		Polarity = NEPTUNE_POLARITY_FALLINGEDGE;
		nParam = 0;
	}
} NEPTUNE_TRIGGER, *PNEPTUNE_TRIGGER;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_TRIGGER_PARAM {
	_uint32_t		nFrameOrder;		// frame sequence number
	_uint32_t		nIncrement;			// end of table(0) or continuous(1)
	_uint32_t		nGainValue;			// gain feature value
	_uint32_t		nShutterValue;		// shutter feature value

	_tagNEPTUNE_TRIGGER_PARAM() {
		nShutterValue = 0;
		nGainValue = 0;
		nIncrement = 0;
		nFrameOrder = 0;
	}
} NEPTUNE_TRIGGER_PARAM, *PNEPTUNE_TRIGGER_PARAM;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_TRIGGER_TABLE {
	NEPTUNE_TRIGGER_PARAM	Param[MAX_TRIGGER_PARAM];	// trigger parameter : max 255
	_uint32_t				Index;		// 0 ~ 15

	_tagNEPTUNE_TRIGGER_TABLE() {
		Index = 0;
		memset(Param, 0, sizeof(NEPTUNE_TRIGGER_PARAM)*MAX_TRIGGER_PARAM);
	}
} NEPTUNE_TRIGGER_TABLE, *PNEPTUNE_TRIGGER_TABLE;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_STROBE_INFO {
	ENeptuneBoolean			bSupport;		// support of strobe
	_uint16_t				nStrobeFlag;	// support strobes bit flag
	_uint16_t				nPolarityFlag;	// strobe polarity support bit flag
	_uint16_t				nDurationMin;	// strobe duration minimum value
	_uint16_t				nDurationMax;	// strobe duration maximum value
	_uint16_t				nDelayMin;		// strobe delay minimum value
	_uint16_t				nDelayMax;		// strobe delay maximum value

	_tagNEPTUNE_STROBE_INFO() {
		bSupport = NEPTUNE_BOOL_FALSE;
		nStrobeFlag = 0;
		nDurationMin = 0;
		nDurationMax = 0;
		nDelayMin = 0;
		nDelayMax = 0;
		nPolarityFlag = 0;
	}
} NEPTUNE_STROBE_INFO, *PNEPTUNE_STROBE_INFO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_STROBE {
	ENeptuneBoolean				OnOff;		// strobe on/off control
	ENeptuneStrobe				Strobe;		// strobe index
	_uint16_t					nDuration;	// strobe duration value
	_uint16_t					nDelay;		// strobe delay value
	ENeptunePolarity			Polarity;	// strobe polarity

	_tagNEPTUNE_STROBE() {
		OnOff = NEPTUNE_BOOL_FALSE;
		Strobe = NEPTUNE_STROBE1;
		nDuration = 0;
		nDelay = 0;
		Polarity = NEPTUNE_POLARITY_LEVELHIGH;
	}
} NEPTUNE_STROBE, *PNEPTUNE_STROBE;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_XML_NODE_LIST {
	_uint32_t		nCount;												// number of nodes
	_char_t			pstrList[MAX_NODE_LIST_COUNT][MAX_XML_NODE_STRING_LENGTH];	// node list

	_tagNEPTUNE_XML_NODE_LIST() {
		nCount = MAX_NODE_LIST_COUNT;
		memset(pstrList, 0, sizeof(_char_t)*MAX_NODE_LIST_COUNT*MAX_XML_NODE_STRING_LENGTH);
	}
} NEPTUNE_XML_NODE_LIST, *PNEPTUNE_XML_NODE_LIST;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_XML_ENUM_LIST {
	_uint32_t		nCount;												// number of enumeration node string
	_char_t			pstrList[MAX_ENUM_LIST_COUNT][MAX_XML_NODE_STRING_LENGTH];		// enumeration node string list
	_uint32_t		nIndex;												// current index of the string list

	_tagNEPTUNE_XML_ENUM_LIST() {
		nCount = MAX_ENUM_LIST_COUNT;
		nIndex = 0;
		memset(pstrList, 0, sizeof(_char_t)*MAX_ENUM_LIST_COUNT*MAX_XML_NODE_STRING_LENGTH);
	}
} NEPTUNE_XML_ENUM_LIST, *PNEPTUNE_XML_ENUM_LIST;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_XML_NODE_INFO {
	ENeptuneNodeType			Type;			// node type(int, float, boolean, string, enumeration, command)
	ENeptuneNodeAccessMode		AccessMode;		// access mode
	ENeptuneNodeVisibility		Visibility;		// node visibility
	_bool8_t					bHasChild;	// has child ?
	_char_t						strDisplayName[MAX_STRING_LENGTH];	// node name
	_char_t						strTooltip[MAX_STRING_LENGTH];		// node tooltip
	_char_t						strDescription[MAX_STRING_LENGTH];	// node description

	_tagNEPTUNE_XML_NODE_INFO() {
		Type = NEPTUNE_NODE_TYPE_UKNOWN;
		AccessMode = NEPTUNE_NODE_ACCESSMODE_UNDEFINED;
		Visibility = NEPTUNE_NODE_VISIBLE_UNKNOWN;
		bHasChild = NEPTUNE_BOOL_FALSE;
		memset(strDisplayName, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strTooltip, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
		memset(strDescription, 0, sizeof(_char_t)*MAX_STRING_LENGTH);
	}
} NEPTUNE_XML_NODE_INFO, *PNEPTUNE_XML_NODE_INFO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_XML_INT_VALUE_INFO {
	_int64_t					nValue;				// current value
	_int64_t					nMin;				// minimum value supported
	_int64_t					nMax;				// maximum value supported
	_int64_t					nInc;				// increment step
	ENeptuneNodeAccessMode		AccessMode; 		// access mode

	_tagNEPTUNE_XML_INT_VALUE_INFO() {
		nValue = 0;
		nMin = 0;
		nMax = 0;
		nInc = 0;
		AccessMode = NEPTUNE_NODE_ACCESSMODE_UNDEFINED;
	}
} NEPTUNE_XML_INT_VALUE_INFO, *PNEPTUNE_XML_INT_VALUE_INFO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_XML_FLOAT_VALUE_INFO {
	_double_t					dValue;			// current value
	_double_t					dMin;			// minimum
	_double_t					dMax;			// maximum
	_double_t					dInc;			// increment
	ENeptuneNodeAccessMode		AccessMode;

	_tagNEPTUNE_XML_FLOAT_VALUE_INFO() {
		dValue = 0;
		dMin = 0;
		dMax = 0;
		dInc = 0.1;
		AccessMode = NEPTUNE_NODE_ACCESSMODE_UNDEFINED;
	}
} NEPTUNE_XML_FLOAT_VALUE_INFO, *PNEPTUNE_XML_FLOAT_VALUE_INFO;
//////////////////////////////////////////////////////////////////////////
typedef struct _tagNEPTUNE_GPIO {
	ENeptuneGPIO			Gpio;		// GPIO index
	ENeptuneGPIOSource		Source;		// GPIO source
	ENeptuneGPIOValue		Value;		// GPIO value

	_tagNEPTUNE_GPIO() {
		Gpio = NEPTUNE_GPIO_LINE1;
		Source = NEPTUNE_GPIO_SOURCE_STROBE;
		Value = NEPTUNE_GPIO_VALUE_LOW;
	}
} NEPTUNE_GPIO, *PNEPTUNE_GPIO;
#pragma pack(pop)
#pragma endregion


#pragma region CALLBACK_DEFINE
// device check callback
typedef void (CALLBACK *NeptuneCDevCheckCallback)(ENeptuneDeviceChangeState emState, void* pContext);
// camera unplug/plug callback
typedef void (CALLBACK *NeptuneCUnplugCallback)(void* pContext);
// image received callback
typedef void (CALLBACK *NeptuneCFrameCallback)(PNEPTUNE_IMAGE pImage, void* pContext);
// frame drop callback
typedef void (CALLBACK *NeptuneCFrameDropCallback)(void* pContext);
// receive frame timeout callback
typedef void (CALLBACK *NeptuneCRecvTimeoutCallback)(void* pContext);
#pragma endregion


#pragma region FUNCTION_DEFINE
#ifdef __cplusplus
extern "C"
{
#endif

/* 
	Description :
		initialize NeptuneC library
	Parameters :
		None
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcInit();

/* 
	Description :
		clear NeptuneC library
	Parameters :
		None
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcUninit();

/*
	Description :
		get number of cameras connected to the system
	Parameters :
		[OUT] puiCount : number of cameras
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetCameraCount(OUT _uint32_t* puiCount);

/* 
	Description :
		get information of connected cameras
	Parameters :
		[OUT] pCamInfo : camera information
		[IN] uiCount : number of NEPTUNE_CAM_INFO structure
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetCameraInfo(OUT PNEPTUNE_CAM_INFO pCameraInfo, IN _uint32_t uiCount);

/*
	Description :
		create camera handle to control. All other function needs camera handle
	Parameters :
		[IN] pszCameraID : strCamID of camera info
		[OUT] pCameraHandle : created camera handle 
		[IN] emAccessFlag : camera control level
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcOpen(IN _char_t* pszCameraID, OUT NeptuneCamHandle* phCameraHandle, IN ENeptuneDevAccess emAccessFlag = NEPTUNE_DEV_ACCESS_EXCLUSIVE);

/*
	Description :
		delete camera handle
	Parameters :
		[IN] hCameraHandle : camera handle to delete
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcClose(IN NeptuneCamHandle hCameraHandle);

/*
	Description :
		get the type(1394 or GigE) of camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemDevType : camera type
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetCameraType(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneDevType* pemDevType);

/*
	Description :
		get the list of pixel format supported by a camera. 
		The size of supported pixel format is returned when called ntcGetPixelFormatList(hCameraHandle, NULL, &nSize).
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemPixelFmtList : list of pixel format
		[IN/OUT] puiCount : size of the list
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetPixelFormatList(IN NeptuneCamHandle hCameraHandle, OUT ENeptunePixelFormat* pemPixelFmtList, IN OUT _uint32_t* puiCount);

/*
	Description :
		get the current pixel format of a camera as a string
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emPixelFmt : current pixel format enumeration value
		[OUT] pszBuffer : pixel format string value
		[IN] uiBufSize : size of the string
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetPixelFormatString(IN NeptuneCamHandle hCameraHandle, IN ENeptunePixelFormat emPixelFmt, OUT _char_t* pszBuffer, IN _uint32_t uiBufSize);

/*
	Description :
		get the current pixel format of a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemPixelFmt : current pixel format value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetPixelFormat(IN NeptuneCamHandle hCameraHandle, OUT ENeptunePixelFormat* pemPixelFmt);

/*
	Description :
		set pixel format to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emPixelFmt : pixel format to set to a camera
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetPixelFormat(IN NeptuneCamHandle hCameraHandle, IN ENeptunePixelFormat emPixelFmt);	

/*
	Description :
		get frame rate list supported by a camera.
		The size of supported pixel format is returned when called ntcGetFrameRateList(hCameraHandle, NULL, &nSize).
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemFPSList : list of frame rate supported by a camera
		[IN/OUT] puiCount : size of the list
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetFrameRateList(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneFrameRate* pemFPSList, IN OUT _uint32_t* puiCount);

/*
	Description :
		get frame rate value as a string
	Parameters :
		[IN] hCamHanle : camera handle to control
		[IN] emFPS : frame rate enumeration value
		[OUT] pszBuffer : frame rate string value converted
		[IN] uiBufSize ; size of the string
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetFrameRateString(IN NeptuneCamHandle hCameraHandle, IN ENeptuneFrameRate emFPS, OUT _char_t* pszBuffer, IN _uint32_t uiBufSize);

/*
	Description :
		get current frame rate enumeration value of a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemFPS : current frame rate value
		[OUT] pdbFPS : valid float value if the peRate is "FPS_VALUE" for GigE camera
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetFrameRate(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneFrameRate* pemFPS, OUT _double_t* pdbFPS);

/*
	Description :
		set frame rate to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emFPS : frame rate to set to a camera
		[IN] dbFPS : frame rate float value valid only if eRate is "FPS_VALUE" for GigE camera
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetFrameRate(IN NeptuneCamHandle hCameraHandle, IN ENeptuneFrameRate emFPS, IN _double_t dbFPS);

/*
	Description :
		get the real image data transfer rate
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pfRecvFPS : receive frame rate
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetReceiveFrameRate(IN NeptuneCamHandle hCameraHandle, OUT _float32_t* pfRecvFPS);

/*
	Description :
		get the maximum image size of the assigned pixel format
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pImageSize : max image size information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetMaxImageSize(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_IMAGE_SIZE pImageSize);

/*
	Description :
		get the current size information of an image
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pImageSize : image size information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetImageSize(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_IMAGE_SIZE pImageSize);

/*
	Description :
		set the image size. 
		Valid only if pixel format is Format7 for 1394 camera or GigE camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stImageSize : image size information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetImageSize(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_IMAGE_SIZE stImageSize);

/*
	Description :
		get current play status
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemState : play/stop state
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetAcquisition(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneBoolean* pemState);

/*
	Description :
		set camera play or stop
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emState : play/stop control
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAcquisition(IN NeptuneCamHandle hCameraHandle, IN ENeptuneBoolean emState);

/*
	Description :
		get the current acquisition mode of a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pemAcqMode : current acquisition mode
		[OUT] puiFrames : frame number(valid only if the peMode = NEPTUNE_ACQ_MULTIFRAME)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetAcquisitionMode(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneAcquisitionMode* pemAcqMode, OUT _uint32_t* puiFrames);

/*
	Description :
		set the acquisition mode to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emAcqMode : acquisition mode
		[IN] uiFrames : multi frame image count(valid only if the eMode = NEPTUNE_ACQ_MULTIFRAME)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAcquisitionMode(IN NeptuneCamHandle hCameraHandle, IN ENeptuneAcquisitionMode emAcqMode, IN _uint32_t uiFrames = 2);

/*
	Description :
		control camera to transfer a single image frame.
		Acquisition mode should be set as NEPTUNE_ACQ_SINGLEFRAME
	Parameters :
		[IN] hCameraHandle : camera handle to control
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcOneShot(IN NeptuneCamHandle hCameraHandle);

/*
	Description :
		control camera to transfer multiple image frames.
		Acquisition mode should be set as NEPTUNE_ACQ_MULTIFRAME
	Parameters :
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcMultiShot(IN NeptuneCamHandle hCameraHandle);

/*
	Description :
		get current bayer conversion information
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemMethod : bayer convert information(None or conversion method)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetBayerConvert(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneBayerMethod* pemMethod);

/*
	Description :
		set bayer convert control
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emMethod : bayer convert information(None or conversion method)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetBayerConvert(IN NeptuneCamHandle hCameraHandle, IN ENeptuneBayerMethod emMethod);

/*
	Description :
		get bayer pattern layout information
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemLayout : bayer pattern layout
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetBayerLayout(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneBayerLayout* pemLayout);

/*
	Description :
		set bayer patter layout control
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emLayout : bayer pattern layout
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetBayerLayout(IN NeptuneCamHandle hCameraHandle, IN ENeptuneBayerLayout emLayout);

/*
	Description :
		Get image rotation angle 
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemAngle : rotation angle
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetRotation(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneRotationAngle* pemAngle);

/*
	Description :
		Set image rotation angle 
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emAngle : rotation angle
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetRotation(IN NeptuneCamHandle hCameraHandle, IN ENeptuneRotationAngle emAngle);

/*
	Description :
		Get image effect(flip, mirror, negative).
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pnEffectFlag : use ENeptuneEffect (combination is possible)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetEffect(IN NeptuneCamHandle hCameraHandle, OUT _int32_t* pnEffectFlag);

/*
	Description :
		set image effect(flip, mirror, negative).
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] nEffectFlag : use ENeptuneEffect (combination is possible)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetEffect(IN NeptuneCamHandle hCameraHandle, IN _int32_t nEffectFlag);

/*
	Description :
		Get camera list option value.
	Parameters :
		[OUT] peCameraListOpt : Camera List Option
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetCameraListOpt(OUT ENeptuneCameraListOpt* pemCameraListOpt);

/*
	Description :
		Set camera list option value.
	Parameters :
		[IN] eCameraListOption : Camera List Option
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetCameraListOpt(IN ENeptuneCameraListOpt emCameraListOpt);

/*
	Description :
		Get image display option.
	Parameters :
		[OUT] pemDisplayOpt : Camera Display Option
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetDisplayOption(OUT ENeptuneDisplayOption* pemDisplayOpt);

/*
	Description :
		Set image display option.
	Parameters :
		[IN] emDisplayOpt : Camera Display Option
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetDisplayOption(IN ENeptuneDisplayOption emDisplayOpt);

/*
	Description :
		set display window to draw image
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] hWnd : window handle to display an image
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetDisplay(IN NeptuneCamHandle hCameraHandle, IN HWND hWnd);

/*
	Description :
		show the camera control dialog
	Parameters :
		[IN] hCameraHandle : camera handle to control
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcShowControlDialog(IN NeptuneCamHandle hCameraHandle);

/*
	Description :
		grab single image from a camera.
		return when a frame data is received and wait if no frame until nTimeOut value(in mili-second)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pImageInfo : image buffer and information
		[IN] emGrabFmt : grab data format(raw or RGB)
		[IN] uiTimeOut : timeout value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGrab(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_IMAGE pImageInfo, IN ENeptuneGrabFormat emGrabFmt, IN _uint32_t uiTimeOut = 1000);

/*
	Description :
		get the RGB image data, should be called in the FrameCallback function
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pBuffer : RGB image data
		[IN] uiBufSize : size of the buffer
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetRGBData(IN NeptuneCamHandle hCameraHandle, OUT _uchar_t* pBuffer, IN _uint32_t uiBufSize);

/*
	Description :
		get the RGB32 image data, should be called in the FrameCallback function
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pBuffer : RGB32 image data
		[IN] uiBufSize : size of the buffer
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetRGB32Data(IN NeptuneCamHandle hCameraHandle, OUT _uchar_t* pBuffer, IN _uint32_t uiBufSize);

/*
	Description :
		save snapshot to an image(jpg, tiff, bmp)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszFilePathName : image file name(image format is identified by the extension of the filename)
		[IN] uiQuality : jpeg image quality(valid only when save to JPEG)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSaveImage(IN NeptuneCamHandle hCameraHandle, IN _char_t* pszFilePathName, IN _uint32_t uiQuality = 80);

/*
	Description :
		start AVI stream capture
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszFilePathName : filename to save an AVI
		[IN] emCompress : not used
		[IN] uiBitrate : not used
		[IN] uiBitrate : not used
		[IN] fPlaySpeed : play speed
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcStartStreamCapture(IN NeptuneCamHandle hCameraHandle, IN _char_t* pszFilePathName, IN ENeptuneBoolean emCompress = NEPTUNE_BOOL_TRUE, IN _uint32_t uiBitrate = 1000, IN _float32_t fPlaySpeed = 1.0);

/*
	Description :
		stop AVI stream capture
	Parameters :
		[IN] hCameraHandle : camera handle to control
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcStopStreamCapture(IN NeptuneCamHandle hCameraHandle);

/*
	Description :
		get information of an selected feature
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emFeatureType : feature 
		[OUT] pFeatureInfo : feature information structure
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetFeature(IN NeptuneCamHandle hCameraHandle, IN ENeptuneFeature emFeatureType, OUT PNEPTUNE_FEATURE pFeatureInfo);

/*
	Description :
		set feature value and auto control if supported
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] eFeature : feature
		[IN] Info : feature information structure
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetFeature(IN NeptuneCamHandle hCameraHandle, IN ENeptuneFeature emFeatureType, IN NEPTUNE_FEATURE stFeatureInfo);

/*
	Description : 
	    get value to shutter, gamma, sharpness, contrast, black level, gain (Only GigE Camera)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pPackageFeature : Package feature Values
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetPackageFeature(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_PACKAGE_FEATURE pPackageFeature);

/*
	Description : 
	    set value to shutter, gamma, sharpness, contrast, black level, gain at the same time (Only GigE Camera)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stPackageFeature : Package feature Values
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetPackageFeature(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_PACKAGE_FEATURE stPackageFeature);

/*
	Description :
		Get exposure time value
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiMicroSec : exposure time
		[OUT] puiMin : min of range
		[OUT] puiMax : max of range
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetExposureTime(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiMicroSec, OUT _uint32_t* puiMin = NULL, OUT _uint32_t* puiMax = NULL);

/*
	Description :
		Set exposure time value
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] puiMicroSec : exposure time
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetExposureTime(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiMicroSec);

/*
	Description :
		set shutter value with a string like as "100 ms"
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszShutter : shutter value string
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetShutterString(IN NeptuneCamHandle hCameraHandle, IN _char_t* pszExposureTime);

/*
	Description :
		set exposure time and interval for trigger mode14 
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiExposure : exposure time for trigger mode14
		[IN] uiInterval : interval time for trigger mode14
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetTriggerMode14Exposure(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiExposure, IN _uint32_t uiInterval);

/*
	Description :
		get trigger information supported by a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pTriggerInfo : trigger information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetTriggerInfo(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_TRIGGER_INFO pTriggerInfo);

/*
	Description :
		get current trigger values
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pTrigger : trigger value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetTrigger(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_TRIGGER pTrigger);

/*
	Description :
		set trigger values to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stTrigger : trigger value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetTrigger(IN NeptuneCamHandle hCameraHandle, OUT NEPTUNE_TRIGGER stTrigger);

/*
	Description :
		get current trigger delay value
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiDelay : current trigger delay value
		[OUT] puiMin : minimum trigger value supported by a camera
		[OUT] puiMax : maximum trigger value supported by a camera
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetTriggerDelay(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiValue, OUT _uint32_t* puiMin = NULL, _uint32_t* puiMax = NULL);

/*
	Description :
		set trigger delay value to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] nDelay : trigger delay value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetTriggerDelay(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiValue);

/*
	Description :
		generate software trigger
	Parameters :
		[IN] hCameraHandle : camera handle to control
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcRunSWTrigger(IN NeptuneCamHandle hCameraHandle);

/*
	Description :
		generate software trigger
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiTimeout : timeout value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcRunSWTriggerEx(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiTimeout);

/*
	Description :
		read trigger table from a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pTriggerTable : trigger table
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcReadTriggerTable(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_TRIGGER_TABLE pTriggerTable);

/*
	Description :
		write and save trigger table to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stTriggerTable : trigger table
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSaveTriggerTable(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_TRIGGER_TABLE stTriggerTable);

/*
	Description :
		make camera to load specific trigger table
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] nIndex : index of trigger table to load
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcLoadTriggerTable(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiIndex);

/*
	Description :
		get the strobe information supported by a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pStrobeInfo : strobe information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetStrobeInfo(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_STROBE_INFO pStrobeInfo);

/*
	Description :
		read strobe value from a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pStrobe : strobe value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetStrobe(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_STROBE pStrobe);

/*
	Description :
		set strobe value to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stStrobe : strobe value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetStrobe(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_STROBE stStrobe);

/*
	Description :
		get information of area for auto function(AutoExposure, AutoWhiteBalance, AutoFocus)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emSelect : auto control feature to get information
		[OUT] pAutoArea : auto area information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetAutoAreaControl(IN NeptuneCamHandle hCameraHandle, IN ENeptuneAutoAreaSelect emSelect, OUT PNEPTUNE_AUTOAREA pAutoArea);

/*
	Description :
		set information of area for auto function(AutoExposure, AutoWhiteBalance, AutoFocus)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emSelect : auto control feature to get information
		[IN] stAutoArea : auto area information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAutoAreaControl(IN NeptuneCamHandle hCameraHandle, IN ENeptuneAutoAreaSelect emSelect, IN NEPTUNE_AUTOAREA stAutoArea);

/*
	Description :
		set Auto focus working mode
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emControlMode : auto focus control mode
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAFControl(IN NeptuneCamHandle hCameraHandle, IN ENeptuneAFMode emControlMode);

/*
	Description :
		set AutoIris mode
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emAutoIrisMode : AutoIris operation mode(Auto, Manual)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAutoIrisMode(IN NeptuneCamHandle hCameraHandle, IN ENeptuneAutoIrisMode emAutoIrisMode);

/*
	Description :
		get number of frames used for calculating brightness
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiValue : current AutoIris average frame value
		[OUT] puiMin : minimum AutoIris average frame value supported
		[OUT] puiMax : maximum AutoIris average frame value supported
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetAutoIrisAverageFrame(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiValue, OUT _uint32_t* puiMin = NULL, OUT _uint32_t* puiMax = NULL);

/*
	Description :
		get number of frames used for calculating brightness
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiValue : AutoIris average frame value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAutoIrisAverageFrame(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiValue);

/*
	Description :
		get target brightness level of AutoIris
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiValue : current AutoIris target value
		[OUT] puiMin : minimum AutoIris target value
		[OUT] puiMax : maximum AutoIris target value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetAutoIrisTargetValue(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiValue, OUT _uint32_t* puiMin = NULL, OUT _uint32_t* puiMax = NULL);

/*
	Description :
		set target brightness level of AutoIris
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiValue : AutoIris target value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetAutoIrisTargetValue(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiValue);

/*
	Description :
		get data bits per image pixel
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiValue : data bits per image pixel
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetBitsPerPixel(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiValue);

/*
	Description :
		get the byte per packet information(for 1394 camera Format7 only)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiValue : byte per packet value
		[OUT] puiMin : minimum byte per packet value supported
		[OUT] puiMax : maximum byte per packet value supported
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetBytePerPacket(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiValue, OUT _uint32_t* puiMin = NULL, OUT _uint32_t* puiMax = NULL);

/*
	Description :
		set the byte per packet to a camera(for 1394 camera Format7 only)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiValue : byte per packet value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetBytePerPacket(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiValue);

/*
	Description :
		get the current transfer packet size of GigE camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiValue : packet size value
		[OUT] puiMin : minimum packet size value supported
		[OUT] puiMax : maximum packet size value supported
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetPacketSize(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiValue, OUT _uint32_t* puiMin = NULL, OUT _uint32_t* puiMax = NULL);

/*
	Description :
		set the transfer packet size of GigE camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiValue : size of the packet
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetPacketSize(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiValue);

/*
	Description :
		Enable/Disable packet resend control
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emEnableResend : Enable/Disable flag
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetPacketResend(IN NeptuneCamHandle hCameraHandle, IN ENeptuneBoolean emEnable);

/*
	Description :
		get the number of image buffer of an NeptuneC API
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiCount : number of buffer
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetBufferCount(IN NeptuneCamHandle hCameraHandle, OUT _uint32_t* puiCount);

/*
	Description :
		set the number of image buffer of an NeptuneC API
		Default buffer count is 10.
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiCount : number of buffer
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetBufferCount(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiCount);

/*
	Description :
		set buffer count for trigger mode of USB camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] uiCount : number of buffers
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetUSBTriggerBufferCount(IN NeptuneCamHandle hCameraHandle, IN _uint32_t uiCount);

/*
	Description
		get the size of one frame image data
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] puiSize : size of an image data
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetBufferSize(IN NeptuneCamHandle hCameraHandle, IN _uint32_t* puiSize);

/*
	Description :
		Enable/Disable receiving dropped frame data
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emEnable : Enable/Disable flag
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetRecvDroppedFrame(IN NeptuneCamHandle hCameraHandle, IN ENeptuneBoolean emEnable);

/*
	Description :
		set the heartbeat time of GigE camera(GigE camera only)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] ulMilliSecTime : heartbeat time in millisecond unit
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetHeartbeatTime(IN NeptuneCamHandle hCameraHandle, IN _ulong32_t ulMilliSecTime);

/* 
	Description :
		set multicast address
	Parameter :
		[IN] hCameraHandle : camera handle to control
		[IN] pszAddress : multicast IP address
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetMulticastAddress(IN NeptuneCamHandle hCameraHandle, IN _char_t* pszAddress);

/*
	Description :
		get supported user set by a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pUserSet : user set information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetUserSet(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_USERSET pUserSet);

/*
	Description :
		save or load user set
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] UserSet : user set value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetUserSet(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_USERSET stUserSet);

/*
	Description :
		make specific user set as a default user set
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] eUserSet : user set value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetDefaultUserSet(IN NeptuneCamHandle hCameraHandle, IN ENeptuneUserSet emUserSet);

/*
	Description :
		make specific user set as a default user set when camera is power on
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] eUserSet : user set value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetPowerOnDefaultUserSet(IN NeptuneCamHandle hCameraHandle, IN ENeptuneUserSet emUserSet);

/*
	Description :
		save camera parameter to a file
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszFilePathName : file name to save camera parameter
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSaveCameraParameter(IN NeptuneCamHandle hCameraHandle, IN _char_t* pszFilePathName);

/*
	Description :
		load camera parameter from a file
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszFilePathName : file name from which to load camera parameter
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcLoadCameraParameter(IN NeptuneCamHandle hCameraHandle, IN _char_t* pszFilePathName);

/*
	Description :
		get 4-step knee table points
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pKneeLUT : 4-step knee table points
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetKneeLUT(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_KNEE_LUT pKneeLUT);

/*
	Description :
		set 4-step knee table points
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stKneeLUT : 4-step knee table points
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetKneeLUT(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_KNEE_LUT stKneeLUT);

/*
	Description :
		get user look-up-table value
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pUserLUT : user look-up-table value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetUserLUT(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_USER_LUT pUserLUT);

/*
	Description :
		set user look-up-table to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] stUserLUT : user look-up-table value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetUserLUT(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_USER_LUT stUserLUT);

/*
	Description :
		get frame save information from a camera (1394 camera only)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemOnOff : frame save on/off state
		[OUT] puiFrameRemained : number of frames remained in the camera memory
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetFrameSave(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneBoolean* pemOnOff, OUT _uint32_t* puiFrameRemained);

/*
	Description :
		control camera to transfer saved frames (1394 camera only)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emOnOff : frame save on/off control
		[IN] emTransfer : transfer control
		[IN] uiFrames : number of frames to transfer
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetFrameSave(IN NeptuneCamHandle hCameraHandle, IN ENeptuneBoolean emOnOff, IN ENeptuneBoolean emTransfer, IN _uint32_t uiFrames);

/*
	Description :
		set GPIO to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] Gpio : GPIO value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetGPIO(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_GPIO stGpio);

/*
	Description :
		read serial data from a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pData : serial data
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcReadSIO(IN NeptuneCamHandle hCameraHandle, OUT PNEPTUNE_SIO pData);

/*
	Description :
		write serial data to a camera
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] Data : serial data
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcWriteSIO(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_SIO stData);

/*
	Description :
		set camera's serial output port information
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] Property : serial information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetSIO(IN NeptuneCamHandle hCameraHandle, IN NEPTUNE_SIO_PROPERTY stProperty);

/*
	Description :
		read 4 bytes from a camera register
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] ulAddress : register address
		[OUT] pulValue : register value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcReadRegister(IN NeptuneCamHandle hCameraHandle, IN _ulong32_t ulAddress, OUT _ulong32_t* pulValue);

/*
	Description :
		write 4 bytes to a camera register
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] ulAddress : register address
		[IN] ulValue : value to write
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcWriteRegister(IN NeptuneCamHandle hCameraHandle, IN _ulong32_t ulAddress, IN _ulong32_t ulValue);

/*
	Description :
		read data a camera register
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] ulAddress : start register address
		[OUT] pBuffer : buffer to read data
		[IN/OUT] pulBufSize : number of bytes to read
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcReadBlock(IN NeptuneCamHandle hCameraHandle, IN _ulong32_t ulAddress, OUT _uint8_t* pBuffer, IN OUT _ulong32_t* pulBufSize);

/*
	Description :
		write data to a camera register
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] ulAddress : start register address
		[IN] pBuf : buffer to write
		[IN] nSize : size of the buffer
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcWriteBlock(IN NeptuneCamHandle hCameraHandle, IN _ulong32_t ulAddress, IN _uint8_t* pBuffer, IN _ulong32_t ulBufSize);

/*
	Description :
		write broadcast to 1394 cameras
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] ulAddress : register address
		[IN] ulValue : value to write
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcWriteBroadcast(IN NeptuneCamHandle hCameraHandle, IN _ulong32_t ulAddress, IN _ulong32_t ulValue);

/*
	Description :
		get current visibility value of XML tree
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[OUT] pemVisibility : visibility (Beginner, Expert, Guru, Invisible)
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeVisibility(IN NeptuneCamHandle hCameraHandle, OUT ENeptuneNodeVisibility* pemVisibility);

/*
	Description :
		set visibility of XML tree
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] emVisibility : visibility 
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeVisibility(IN NeptuneCamHandle hCameraHandle, IN ENeptuneNodeVisibility emVisibility);

/*
	Description :
		get child tree of a given XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszParentNodeName : node
		[OUT] pNodeInfoList : child node tree
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeList(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszParentNodeName, OUT PNEPTUNE_XML_NODE_LIST pNodeInfoList);

/*
	Description :
		get child tree of a given XML node (for C#)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszParentNodeName : node
		[OUT] pBuffer : child node tree
		[IN] uiStrLength : size of string
		[IN,OUT] puiCount : number of strings
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeListChar(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszParentNodeName, OUT _char_t* pBuffer, IN _uint32_t uiStrLength, IN OUT _uint32_t* puiCount);

/*
	Description :
		get information of a XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pNodeInfo : information of a XML node
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeInfo(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT PNEPTUNE_XML_NODE_INFO pNodeInfo);

/*
	Description :
		get information of integer type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pValueInfo : integer value information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeInt(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT PNEPTUNE_XML_INT_VALUE_INFO pValueInfo);

/*
	Description :
		set value to an integer type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[IN] nValue : integer value to write
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeInt(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, IN _int64_t nValue);

/*
	Description :
		get information of float type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pValueInfo : float value information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeFloat(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT PNEPTUNE_XML_FLOAT_VALUE_INFO pValueInfo);

/*
	Description :
		set value to a float type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[IN] dbValue : float value to write
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeFloat(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, IN _double_t dbValue);

/*
	Description :
		get information of enumeration type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pEnumList : enumeration value information
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeEnum(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT PNEPTUNE_XML_ENUM_LIST pEnumList);


/*
	Description :
		get information of enumeration type XML node(for C#)
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pBuffer : enumeration value information (size is nSize*pnCount)
		[IN] uiStrLength : should be 256
		[IN, OUT] puiCount : number of strings
		[OUT] puiIndex : current enumeration string index
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeEnumChar(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT _char_t* pBuffer, IN _uint32_t uiStrLength, IN OUT _uint32_t* puiCount, OUT _uint32_t* puiIndex);

/*
	Description :
		set value to an enumeration type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[IN] pszValue : enumeration string to write
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeEnum(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, IN const _char_t* pszValue);

/*
	Description :
		get information of string type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pBuffer : string value
		[IN/OUT] puiBufSize : size of string
		[OUT] pemAccessMode : access mode of a node
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeString(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT _char_t* pBuffer, IN OUT _uint32_t* puiBufSize, OUT ENeptuneNodeAccessMode* pemAccessMode);

/*
	Description :
		set value to a string type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[IN] pszValue : string value to write
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeString(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, IN const _char_t* pszValue);

/*
	Description :
		get value of boolean type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[OUT] pemState : boolean value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcGetNodeBoolean(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, OUT ENeptuneBoolean* pemState);

/*
	Description :
		set value to boolean type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
		[IN] emState : boolean value
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeBoolean(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName, IN ENeptuneBoolean emState);

/*
	Description :
		make execute command type XML node
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] pszNodeName : XML node
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetNodeCommand(IN NeptuneCamHandle hCameraHandle, IN const _char_t* pszNodeName);

/* 
	Description :
		set callback function called when number of device changed
	Parameters :
		[IN] callback : callback function
		[IN] pContext : user parameter passed to the callback function
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetDeviceCheckCallback(IN NeptuneCDevCheckCallback callback, IN void* pContext);

/*
	Description :
		register callback function which is called when selected camera is plugged off
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] callback : callback function
		[IN] pContext : user parameter passed to the callback function
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetUnplugCallback(IN NeptuneCamHandle hCameraHandle, IN NeptuneCUnplugCallback fpCallback, IN void* pContext);

/*
	Description :
		register callback function called when a new frame data is received
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] callback : callback function
		[IN] pContext : user parameter passed to the callback function
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetFrameCallback(IN NeptuneCamHandle hCameraHandle, IN NeptuneCFrameCallback fpCallback, IN void* pContext);

/*
	Description :
		register callback function called when a frame data is dropped
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] callback : callback function
		[IN] pContext : user parameter passed to the callback function
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetFrameDropCallback(IN NeptuneCamHandle hCameraHandle, IN NeptuneCFrameDropCallback fpCallback, IN void* pContext);

/*
	Description :
		register callback function called when a frame receive is timeout
	Parameters :
		[IN] hCameraHandle : camera handle to control
		[IN] callback : callback function
		[IN] pContext : user parameter passed to the callback function
*/
NEPTUNE_C_API ENeptuneError __stdcall ntcSetRecvTimeoutCallback(IN NeptuneCamHandle hCameraHandle, IN NeptuneCRecvTimeoutCallback fpCallback, IN void* pContext);


#ifdef	__cplusplus
};
#endif
#pragma endregion

