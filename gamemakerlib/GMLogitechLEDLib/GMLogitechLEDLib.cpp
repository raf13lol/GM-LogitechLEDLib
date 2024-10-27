#include "pch.h"
#include "framework.h"
#include "LogitechLEDLib.h"
#include "GMLogitechLEDLib.h"

// this is so horrible i apologise

#pragma region init stuff
GMLEDLIB_API double logiled_init()
{
	return LogiLedInit();
}

GMLEDLIB_API double logiled_init_with_name(string name)
{
	return LogiLedInitWithName(name);
}
#pragma endregion
#pragma region sdk/config stuff
GMLEDLIB_API double logiled_get_sdk_version()
{
	int maj = 0;
	int min = 0;
	int build = 0;
	LogiLedGetSdkVersion(&maj, &min, &build);
	return (maj << 16) + (min << 8) + build;
}

/* I got some errors that i'm too lazy to deal with
// https://stackoverflow.com/questions/8032080/how-to-convert-char-to-wchar-t
GMLEDLIB_API double logiled_get_config_option_number(string configPath)
{
	const size_t cSize = strlen(configPath) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, configPath, cSize);

	double num = 0;
	LogiLedGetConfigOptionNumber(wc, &num);
	delete[] wc;

	return num;
}

GMLEDLIB_API double logiled_get_config_option_bool(string configPath)
{
	const size_t cSize = strlen(configPath) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, configPath, cSize);

	bool num = 0;
	LogiLedGetConfigOptionBool(wc, &num);
	delete[] wc;

	return num;
}

GMLEDLIB_API double logiled_get_config_option_color(string configPath)
{
	const size_t cSize = strlen(configPath) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, configPath, cSize);

	int red = 0;
	int green = 0;
	int blue = 0;
	LogiLedGetConfigOptionColor(wc, &red, &green, &blue);
	delete[] wc;

	// this is how gm color format works !! 
	// this means we can use this immediately for colours
	return (blue << 16) + (green << 8) + red;
}

GMLEDLIB_API double logiled_get_config_option_rect(string configPath)
{
	const size_t cSize = strlen(configPath) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, configPath, cSize);

	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	LogiLedGetConfigOptionRect(wc, &x, &y, &width, &height);
	delete[] wc;

	return (x << 24) + (y << 16) + (width << 8) + height;
}*/
// do these 3 later
// logiled_get_config_option_string -> LogiLedGetConfigOptionString
// logiled_get_config_option_key_input -> LogiLedGetConfigOptionKeyInput
// logiled_get_config_option_label -> LogiLedSetConfigOptionLabel
#pragma endregion
#pragma region generic functions
// use LOGI_DEVICETYPE
GMLEDLIB_API double logiled_set_target_device(double targetDevice)
{
	return LogiLedSetTargetDevice((int)targetDevice);
}

GMLEDLIB_API double logiled_save_current_lighting()
{
	return LogiLedSaveCurrentLighting();
}

// 0-100
GMLEDLIB_API double logiled_set_lighting(double redPercentage, double greenPercentage, double bluePercentage)
{
	return LogiLedSetLighting((int)redPercentage, (int)greenPercentage, (int)bluePercentage);
}

GMLEDLIB_API double logiled_restore_lighting()
{
	return LogiLedRestoreLighting();
}

GMLEDLIB_API double logiled_flash_lighting(double redPercentage, double greenPercentage, double bluePercentage,
	double milliSecondsDuration, double milliSecondsInterval)
{
	return LogiLedFlashLighting((int)redPercentage, (int)greenPercentage, (int)bluePercentage,
		(int)milliSecondsDuration, (int)milliSecondsInterval);
}

GMLEDLIB_API double logiled_pulse_lighting(double redPercentage, double greenPercentage, double bluePercentage,
	double milliSecondsDuration, double milliSecondsInterval)
{
	return LogiLedPulseLighting((int)redPercentage, (int)greenPercentage, (int)bluePercentage,
		(int)milliSecondsDuration, (int)milliSecondsInterval);
}

GMLEDLIB_API double logiled_stop_effects()
{
	return LogiLedStopEffects();
}
#pragma endregion
#pragma region perkey functions => PERKEY_RGB
GMLEDLIB_API double logiled_set_lighting_from_bitmap(string bitmap)
{
	// apparently this works?? i just looked around
	unsigned char* bitm = const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(bitmap));
	return LogiLedSetLightingFromBitmap(bitm);
}

GMLEDLIB_API double logiled_set_lighting_for_key_with_scan_code(double keyCode,
	double redPercentage, double greenPercentage, double bluePercentage)
{
	return LogiLedSetLightingForKeyWithScanCode((int)keyCode,
		(int)redPercentage, (int)greenPercentage, (int)bluePercentage);
}

GMLEDLIB_API double logiled_set_lighting_for_key_with_hid_code(double keyCode,
	double redPercentage, double greenPercentage, double bluePercentage)
{
	return LogiLedSetLightingForKeyWithHidCode((int)keyCode,
		(int)redPercentage, (int)greenPercentage, (int)bluePercentage);
}

GMLEDLIB_API double logiled_set_lighting_for_key_with_quartz_code(double keyCode,
	double redPercentage, double greenPercentage, double bluePercentage)
{
	return LogiLedSetLightingForKeyWithQuartzCode((int)keyCode,
		(int)redPercentage, (int)greenPercentage, (int)bluePercentage);
}

GMLEDLIB_API double logiled_set_lighting_for_key_with_key_name(double keyName,
	double redPercentage, double greenPercentage, double bluePercentage)
{
	return LogiLedSetLightingForKeyWithKeyName((LogiLed::KeyName)keyName,
		(int)redPercentage, (int)greenPercentage, (int)bluePercentage);
}

GMLEDLIB_API double logiled_save_lighting_for_key(double keyName)
{
	return LogiLedSaveLightingForKey((LogiLed::KeyName)keyName);
}

GMLEDLIB_API double logiled_restore_lighting_for_key(double keyName)
{
	return LogiLedRestoreLightingForKey((LogiLed::KeyName)keyName);
}

GMLEDLIB_API double logiled_exclude_key_from_bitmap(double keyName)
{
	return LogiLedExcludeKeysFromBitmap((LogiLed::KeyName*)&keyName, 1);
}
#pragma endregion
#pragma region perkey effects (also => PERKEY_RGB)
GMLEDLIB_API double logiled_flash_single_key(double keyName,
	double redPercentage, double greenPercentage, double bluePercentage,
	double msDuration, double msInterval)
{
	return LogiLedFlashSingleKey((LogiLed::KeyName)keyName,
		(int)redPercentage, (int)greenPercentage, (int)bluePercentage,
		(int)msDuration, (int)msInterval);
}

GMLEDLIB_API double logiled_pulse_single_key(double keyName,
	double startRedPercentage,  double startGreenPercentage,  double startBluePercentage,
	double finishRedPercentage, double finishGreenPercentage, double finishBluePercentage,
	double msDuration, double isInfinite)
{
	return LogiLedPulseSingleKey((LogiLed::KeyName)keyName,
		(int)startRedPercentage,  (int)startGreenPercentage,  (int)startBluePercentage,
		(int)finishRedPercentage, (int)finishGreenPercentage, (int)finishBluePercentage,
		(int)msDuration, (bool)isInfinite);
}

GMLEDLIB_API double logiled_stop_effects_on_key(double keyName)
{
	return LogiLedStopEffectsOnKey((LogiLed::KeyName)keyName);
}
#pragma endregion
#pragma region zonal functions => devices with zones
GMLEDLIB_API double logiled_set_lighting_for_target_zone(double deviceType, double zone,
	double redPercentage, double greenPercentage, double bluePercentage)
{
	return LogiLedSetLightingForTargetZone((LogiLed::DeviceType)deviceType, (int)zone,
		(int)redPercentage, (int)greenPercentage, (int)bluePercentage);
}
#pragma endregion
#pragma region Shutdown
GMLEDLIB_API double logiled_shutdown()
{
	LogiLedShutdown();
	return 0;
}
#pragma endregion