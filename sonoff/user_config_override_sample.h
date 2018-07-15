/*
  user_config_override.h - user configuration overrides user_config.h for Sonoff-Tasmota

  Copyright (C) 2018  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is inlcuded
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *         ie2 : enable in file platformio.ini "build_flags = -Wl,-Tesp8266.flash.1m0.ld -DUSE_CONFIG_OVERRIDE"
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/


// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        6661                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "Ubernet"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "BDD5A42641"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "192.168.0.6" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "home"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "HAss7412369"         // [MqttPassword] Optional password

#undef SAVE_STATE
#define SAVE_STATE             0                // [SetOption0] Save changed power state to Flash (0 = disable, 1 = enable)

#undef NTP_SERVER1
#define NTP_SERVER1            "192.168.0.1"

#undef TIME_STD_HEMISPHERE
#define TIME_STD_HEMISPHERE    South 
#undef TIME_STD_OFFSET
#define TIME_STD_OFFSET        +120

#undef APP_TIMEZONE
#define APP_TIMEZONE           +2    

#undef LATITUDE
#undef LONGITUDE
#define LATITUDE               -26.1060610         // [Latitude] Your location to be used with sunrise and sunset
#define LONGITUDE              28.004          // [Longitude] Your location to be used with sunrise and sunset

#undef MQTT_LIBRARY_TYPE
#define MQTT_LIBRARY_TYPE      MQTT_TASMOTAMQTT

#undef USE_DOMOTICZ 

#define USE_KNX  

#undef USE_I2C  

#undef USE_EMULATION

#undef USE_MHZ19
#undef USE_SENSEAIR
#undef USE_PMS5003                              // Add support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
#undef USE_NOVA_SDS                             // Add support for SDS011 and SDS021 particle concentration sensor (+0k7 code)
#undef USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef USE_SDM120                               // Add support for Eastron SDM120-Modbus energy meter (+1k7 code)
#undef USE_SDM630

#define USE_SERIAL_MQTT         

#undef USE_IR_REMOTE
#undef USE_IR_RECEIVE

#undef USE_ARILUX_RF  
#undef USE_SR04

#endif  // _USER_CONFIG_OVERRIDE_H_