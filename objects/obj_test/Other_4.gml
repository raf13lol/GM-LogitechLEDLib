var sdkver = logiled_get_sdk_version();
show_debug_message(
"major: " +  string(sdkver >> 16) + ", " +
"minor: " +  string((sdkver >> 8) & 0xff) + ", " +
"build: " +  string(sdkver  & 0xff)
);

logiled_set_lighting(100, 0, 100);
logiled_set_lighting_for_target_zone(DeviceType.Mouse, 0, 100, 100, 100);