/***********************************************************************
 * File         :     esp32_iot_all_v3.h
 * Description  :     Class for Hardware config and function for esp32_iot_all_v3 module
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     24 June 2022
 * Revision     :     1.0
 * Rev1.0       :     Original 
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/
#ifndef ESP32_IOT_ALL_V3_H
#define ESP32_IOT_ALL_V3_H
#include <Ticker.h>
#include <RTClib.h>
#include <Wire.h>
#include <SSD1306Wire.h>
#include <OneWire.h>


class esp32_iot_all_v3
{
private:
#define version_c  "1.0"

private:
/* RTC variable */
//sync date-time
const char* ntpServer = "asia.pool.ntp.org";
const long  gmtOffset_sec = 25200;
const int   daylightOffset_sec = 0;

private:
uint8_t _resolution_bit;
uint16_t crc16_update(uint16_t crc, uint8_t a);


/* data */
public:
    /**************************************/
    /*           GPIO define              */
    /**************************************/
    #define BUTTON_SW1      34
    #define BUTTON_SW2      35
    #define LED_RED         12
    #define LED_BLUE        4
    #define BUZZER          13
    #define SLID_SW         39
    #define INPUT_1         2
    #define OUTPUT_1        32
    #define OUTPUT_2        33
    #define OUTPUT_3        25
    #define OUTPUT_4        15
    #define ONE_WIRE_BUS    14
    #define RXD2            16
    #define TXD2            17
    #define RXD3            26
    #define TXD3            27
  

    #define TEMPERATURE_PRECISION 12 // Lower resolution



    //*** oled ***
    #define pic_tenergy       0
    #define pic_progressive   1
    #define pic_wifi          2
    #define pic_wifi_on       3
    #define pic_wifi_off      4
    #define pic_hotspot       5
    #define pic_wificoffee    6
    #define pic_facebook      7
    #define pic_bug           8
    #define pic_maintenance   9
    #define pic_camera        10
    #define pic_clock         11
    #define pic_motor         12
    #define pic_eeprom        13
    #define pic_home          14
    #define pic_led           15
    #define pic_motion        16
    #define pic_relay         17
    #define pic_rs485         18
    #define pic_stepping      19
    #define pic_temperature   20
    #define pic_tmp1638       21
    #define pic_ultrasonic    22
    #define pic_uten          23
    #define pic_potentiometer 24
    #define pic_ldr           25
    #define pic_payuth        26
    #define pic_dip3sw        27
    #define pic_mju           28
    #define pic_input         29
    #define pic_switch        30
    #define pic_netpie        31
    #define pic_ampere        32
    #define pic_blynk         33
    #define pic_battery       34
    #define pic_hospital      35
    #define pic_police        36
    #define pic_chai          37
    #define pic_add           38
    #define pic_clear         99  

    esp32_iot_all_v3(/* args */);
    ~esp32_iot_all_v3();
    bool Relay1(bool status);
    bool Relay2(bool status);
    bool Relay3(bool status);
    bool Relay4(bool status);
    bool Sw1(void);
    bool Sw2(void);
    bool Slid_sw(void);
    void buzzer_beep(int times);
    void RedLED(bool state);
    void BlueLED(bool state);
    void BuildinLED(bool state);
    void TickBlueLED(float second);
    void TickRedLED(float second);
    void TickBuildinLED(float second);
    void library_version(void);
    bool PWM_Setup(uint8_t channel, double freq, uint8_t resolution_bit, uint8_t pin);
    bool PWM_Drive(uint8_t channel, uint8_t percentage);

    //*** DS3231 ***//
    void beginTime(void);
    bool setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
    void getTime(uint8_t &_hour, uint8_t &_min, uint8_t &_sec);
    void getDate(uint16_t &_year, uint8_t &_month, uint8_t &_day);
    void getDateTime(uint16_t &_year, uint8_t &_month, uint8_t &_day, uint8_t &_hour, uint8_t &_min, uint8_t &_sec);
    char* getdayOfTheWeekChar(void);
    uint8_t getdayOfTheWeekNum(void);
    float getTemperature(void);
    uint16_t getTimestamp(void);
    bool syncTimeServer(void);
    void adjustTime(void);

    //*** timestamp ***/
    uint16_t TimeStamp_minute_encode(uint16_t y, uint8_t m, uint8_t d, uint8_t h, uint8_t mi);
    uint16_t TimeStamp_24hr_encode(uint16_t h, uint16_t mi);
    void TimeStamp_hour_minute_decode(uint16_t timestemp, uint16_t &h, uint16_t &mi);

    //*** Oled display ***//
    void beginOled(void);
    void picOled(int pic_xxx);
    bool stringOled(int16_t xMove, int16_t yMove, uint8_t fontSize,  String strUser);
    void clearOled(void);
};




#endif