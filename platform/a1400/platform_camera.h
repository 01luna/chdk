// Camera - A1400 - platform_camera.h

// This file contains the various settings values specific to the A1400 camera.
// This file is referenced via the 'include/camera.h' file and should not be loaded directly.

// If adding a new settings value put a suitable default in 'include/camera.h',
// along with documentation on what the setting does and how to determine the correct value.
// If the setting should not have a default value then add it in 'include/camera.h'
// using the '#undef' directive along with appropriate documentation.

// Override any default values with your camera specific values in this file. Try and avoid
// having override values that are the same as the default value.

// When overriding a setting value there are two cases:
// 1. If removing the value, because it does not apply to your camera, use the '#undef' directive.
// 2. If changing the value it is best to use an '#undef' directive to remove the default value
//    followed by a '#define' to set the new value.

// When porting CHDK to a new camera, check the documentation in 'include/camera.h'
// for information on each setting. If the default values are correct for your camera then
// don't override them again in here.

    #define CAM_DRYOS                       1
    #define CAM_PROPSET                     6

    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher

    #define CAM_RAW_ROWPIX                  4704    // Found @0xff943780
    #define CAM_RAW_ROWS                    3504    // Found @0xff94378c

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff831d9c

    #define CAM_JPEG_WIDTH                  4608
    #define CAM_JPEG_HEIGHT                 3456
    #define CAM_ACTIVE_AREA_X1              16
    #define CAM_ACTIVE_AREA_Y1              26
    #define CAM_ACTIVE_AREA_X2              4640
    #define CAM_ACTIVE_AREA_Y2              3486

    #define CAM_DNG_LENS_INFO               { 50,10, 250,10, 28,10, 69,10 } // See comments in camera.h

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define cam_CFAPattern                  0x01000201   // [Green Blue Red Green]

    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

    // no separate erase button
    #undef  CAM_HAS_ERASE_BUTTON

    #define CAM_ZEBRA_NOBUF                 1

    #define PARAM_CAMERA_NAME               3       // parameter number for GetParameterData

    #define CAM_HAS_ND_FILTER               1

    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_CAN_MUTE_MICROPHONE         1

    #define DNG_VERT_RLE_BADPIXELS          1

    #define CAM_DATE_FOLDER_NAMING          0x80

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_IS                              // Camera does not have an image stabilizer

    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_USE_ZOOM_FOR_MF

    #define CAM_LOAD_CUSTOM_COLORS          1   // Enable loading CHDK colors into the camera palette memory/hardware

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720   // Actual width of bitmap screen in bytes

    #define  CAM_ADJUSTABLE_ALT_BUTTON      1   // ALT-button can be set from menu
    #define CAM_ALT_BUTTON_NAMES            { "Playback", "Help" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PLAYBACK, KEY_HELP }
    #undef  CAM_HAS_DISP_BUTTON
    #define CAM_DISP_BUTTON_NAME            "Video"
    #define SHORTCUT_TOGGLE_RAW             KEY_VIDEO

    #define CAM_HAS_FILEWRITETASK_HOOK      1
    #define CAM_FILEWRITETASK_SEEKS         1

    #define CAM_NEED_SET_ZOOM_DELAY         300  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS 1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoom
    #define CAM_USE_ALT_SET_ZOOM_POINT      1    // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1    // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()

    #define CAM_FILE_COUNTER_IS_VAR         1       // file counter is variable file_counter_var in stubs, not a param

    #define CAM_QUALITY_OVERRIDE            1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define MKDIR_RETURN_ONE_ON_SUCCESS     1       // mkdir() return 1 on success, 0 on fail.

    #define REMOTE_SYNC_STATUS_LED          0xC0220120  //specifies an LED that turns on while camera waits for USB remote to sync

    #undef  CAM_AF_LED
    #define CAM_AF_LED                      2      // Index of AF led in camera_set_led function

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY             120  // delay after a press - Required by zoom_in/zoom_out buttons

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

//--------------------------------------------------
