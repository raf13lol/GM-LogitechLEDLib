#define GMLEDLIB_API extern "C" __declspec(dllexport) 
#define string const char*

GMLEDLIB_API double logiled_init();
GMLEDLIB_API double logiled_init_with_name(string name);


GMLEDLIB_API double logiled_get_sdk_version();
/* idk i'm getting strnage erros
GMLEDLIB_API double logiled_get_config_option_number(string configPath);
GMLEDLIB_API double logiled_get_config_option_bool(string configPath);
GMLEDLIB_API double logiled_get_config_option_color(string configPath);
GMLEDLIB_API double logiled_get_config_option_rect(string configPath);
*/

GMLEDLIB_API double logiled_set_target_device(double targetDevice);
GMLEDLIB_API double logiled_save_current_lighting();
GMLEDLIB_API double logiled_set_lighting(double redPercentage, double greenPercentage, double bluePercentage);
GMLEDLIB_API double logiled_restore_lighting();

GMLEDLIB_API double logiled_flash_lighting(double redPercentage, double greenPercentage, double bluePercentage,
	double milliSecondsDuration, double milliSecondsInterval);

GMLEDLIB_API double logiled_pulse_lighting(double redPercentage, double greenPercentage, double bluePercentage,
	double milliSecondsDuration, double milliSecondsInterval);

GMLEDLIB_API double logiled_stop_effects();


GMLEDLIB_API double logiled_set_lighting_from_bitmap(string bitmap);

GMLEDLIB_API double logiled_set_lighting_for_key_with_scan_code(double keyCode,
	double redPercentage, double greenPercentage, double bluePercentage);

GMLEDLIB_API double logiled_set_lighting_for_key_with_hid_code(double keyCode,
	double redPercentage, double greenPercentage, double bluePercentage);

GMLEDLIB_API double logiled_set_lighting_for_key_with_quartz_code(double keyCode,
	double redPercentage, double greenPercentage, double bluePercentage);

GMLEDLIB_API double logiled_set_lighting_for_key_with_key_name(double keyName,
	double redPercentage, double greenPercentage, double bluePercentage);

GMLEDLIB_API double logiled_save_lighting_for_key(double keyName);
GMLEDLIB_API double logiled_restore_lighting_for_key(double keyName);
GMLEDLIB_API double logiled_exclude_key_from_bitmap(double keyName);


GMLEDLIB_API double logiled_flash_single_key(double keyName,
	double redPercentage, double greenPercentage, double bluePercentage,
	double msDuration, double msInterval);

GMLEDLIB_API double logiled_pulse_single_key(double keyName,
	double startRedPercentage, double startGreenPercentage, double startBluePercentage,
	double finishRedPercentage, double finishGreenPercentage, double finishBluePercentage,
	double msDuration, double isInfinite);

GMLEDLIB_API double logiled_stop_effects_on_key(double keyName);


GMLEDLIB_API double logiled_set_lighting_for_target_zone(double deviceType, double zone,
	double redPercentage, double greenPercentage, double bluePercentage);


GMLEDLIB_API double logiled_shutdown();