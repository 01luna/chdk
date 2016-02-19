#include "platform.h"
#include "module_def.h"

//==========================================================
// Data Structure to store camera specific information
// Used by modules to ensure module code is platform independent

_cam_sensor camera_sensor = { 
    MAKE_API_VERSION(1,0),

    CAM_SENSOR_BITS_PER_PIXEL, 
    CAM_BLACK_LEVEL, CAM_WHITE_LEVEL,
    CAM_RAW_ROWS, CAM_RAW_ROWPIX, (CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL)/8, CAM_RAW_ROWS * ((CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL)/8),
#if defined(CAM_ACTIVE_AREA_X1) && defined(CAM_JPEG_WIDTH)
    {{
        (CAM_ACTIVE_AREA_X2-CAM_ACTIVE_AREA_X1-CAM_JPEG_WIDTH)/2, (CAM_ACTIVE_AREA_Y2-CAM_ACTIVE_AREA_Y1-CAM_JPEG_HEIGHT)/2,
        CAM_JPEG_WIDTH, CAM_JPEG_HEIGHT
    }},
    { { CAM_ACTIVE_AREA_Y1, CAM_ACTIVE_AREA_X1, CAM_ACTIVE_AREA_Y2, CAM_ACTIVE_AREA_X2 } }, 
#else
    {{
        0, 0,
        0, 0
    }},
    { { 0, 0, 0, 0 } }, 
#endif
#if defined(CAM_DNG_LENS_INFO)
    CAM_DNG_LENS_INFO,
#else
    { 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_DNG_EXPOSURE_BIAS)
    { CAM_DNG_EXPOSURE_BIAS },
#else
    { -1 , 2 },
#endif
#if defined(cam_CFAPattern)
    cam_CFAPattern, 
#else
    0,
#endif
#if defined(CAM_COLORMATRIX1)
    cam_CalibrationIlluminant1,
    { CAM_COLORMATRIX1 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_COLORMATRIX2)
    cam_CalibrationIlluminant2,
    { CAM_COLORMATRIX2 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_CAMERACALIBRATION1)
    1,
    { CAM_CAMERACALIBRATION1 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_CAMERACALIBRATION2)
    1,
    { CAM_CAMERACALIBRATION2 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_FORWARDMATRIX1)
    1,
    { CAM_FORWARDMATRIX1 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_FORWARDMATRIX2)
    1,
    { CAM_FORWARDMATRIX2 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
    DNG_BADPIXEL_VALUE_LIMIT,
};

_cam_screen camera_screen =
{
    CAM_SCREEN_WIDTH, CAM_SCREEN_HEIGHT, CAM_SCREEN_WIDTH * CAM_SCREEN_HEIGHT,
    ASPECT_XCORRECTION(CAM_SCREEN_WIDTH),
    CAM_BITMAP_WIDTH, CAM_BITMAP_HEIGHT, CAM_BITMAP_WIDTH * CAM_BITMAP_HEIGHT,
    EDGE_HMARGIN, CAM_TS_BUTTON_BORDER,
#if defined(CAM_ZEBRA_NOBUF)
    1,
#else
    0,
#endif
#if defined(CAM_ZEBRA_ASPECT_ADJUST)
    1,
#else
    0,
#endif
#if defined(CAM_HAS_VARIABLE_ASPECT)
    1,
#else
    0,
#endif
    CAM_MENU_BORDERWIDTH,
};

_cam_info camera_info =
{
    MAKE_API_VERSION(1,0),

    {
#if defined(PARAM_CAMERA_NAME)
    PARAM_CAMERA_NAME,
#else
    0,
#endif
#if defined(PARAM_OWNER_NAME)
    PARAM_OWNER_NAME,
#else
    0,
#endif
#if defined(PARAM_ARTIST_NAME)
    PARAM_ARTIST_NAME,
#else
    0,
#endif
#if defined(PARAM_COPYRIGHT)
    PARAM_COPYRIGHT,
#else
    0,
#endif
    },
    {
    CAM_PROPSET,
#if defined(CAM_HAS_GPS)
    PROPCASE_GPS,
#else
    0,
#endif
    PROPCASE_ORIENTATION_SENSOR,
    PROPCASE_TV, PROPCASE_AV, PROPCASE_MIN_AV,
    PROPCASE_EV_CORRECTION_1, PROPCASE_EV_CORRECTION_2, 
    PROPCASE_FLASH_MODE, PROPCASE_FLASH_FIRE, 
    PROPCASE_METERING_MODE, PROPCASE_WB_ADJ,
#if defined(PROPCASE_ASPECT_RATIO)
    PROPCASE_ASPECT_RATIO,
#else
    0,
#endif
    PROPCASE_SHOOTING, PROPCASE_RESOLUTION, PROPCASE_QUALITY,
    },
    ROMBASEADDR, MAXRAMADDR, 0, CAM_UNCACHED_BIT,
#if defined(OPT_EXMEM_MALLOC) && !defined(OPT_EXMEM_TESTING)
    1,
#else
    0,
#endif
    0,0,0,0,0,
    PLATFORM, PLATFORMSUB,
    HDK_VERSION, BUILD_NUMBER, 
    HDK_VERSION" ver. "BUILD_NUMBER,
    BUILD_SVNREV, __DATE__, __TIME__,
#if defined(CAM_DRYOS)
    "dryos",
#else
    "vxworks",
#endif
#if CAM_EV_IN_VIDEO
    1,
#else
    0,
#endif
#if defined(CAM_HAS_ND_FILTER)
    1,
#else
    0,
#endif
#if defined(CAM_HAS_IRIS_DIAPHRAGM)
    1,
#else
    0,
#endif
#if defined(CAM_HAS_VIDEO_BUTTON)
    1,
#else
    0,
#endif
#if defined(CAM_HAS_ZOOM_LEVER)
    1,
#else
    0,
#endif
#if defined(CAM_HAS_MANUAL_FOCUS)
    1,
#else
    0,
#endif
#if defined(CAM_MULTIPART)
    1,
#else
    0,
#endif
#if defined(REMOTE_SYNC_STATUS_LED)
    REMOTE_SYNC_STATUS_LED,
#else
    0,
#endif
    CAM_KEY_PRESS_DELAY, CAM_KEY_RELEASE_DELAY, 
#if defined(CAM_KEY_CLICK_DELAY)
    CAM_KEY_CLICK_DELAY,
#else
    0,
#endif
};

//==========================================================