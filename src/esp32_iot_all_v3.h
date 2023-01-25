/***********************************************************************
 * File         :     esp32_iot_all_v3.h
 * Description  :     Class for Hardware config and function for esp32_iot_all_v3 module
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     24 June 2022
 * Revision     :     1.4
 * Rev1.0       :     Original 
 * Rev1.1       :     - Change pin RXD3, TXD3 
 *                    - Add Example_Uart2_Test
 * Rev1.2       :     Add picture of OLED  
 * Rev1.3       :     Frequency_Out function
 * Rev1.4       :     - Add PZEM-016 Energy Meter AC        
 *                    - Add PZEM-003 Energy Meter DC  
 *                    - Add WTR10_E(SHT20) temperature and humidity sensor (RS485)
 *                    - Add XY-MD02(SHT20) temperature and humidity sensor (RS485)    
 *                    - Add SOIL MOISTURE PR-3000-H-N01 sensor (RS485) fix id = 1, baud rate = 4800  
 *                    - Add RS485 Water Flow Meter RS485 MODBUS output  
 *                    - Add PYR20-Solar Radiation/Pyranometer Sensor, RS485, Modbus   
 *                    - Add tiny32 ModbusRTU communication    
 * Rev1.5       :     - Add MIZTEK-Fan 3phase ModbusRTU    
 * Rev1.5.1     :     Revise code for Add RS485 Water Flow Meter RS485 MODBUS output (Rev1.4)  
 * Rev1.6       :     Fix bug for pzem-016 and pzem-003  
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
#define version_c  "1.6"

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
    #define pic_chatchat      39
    #define pic_workworkwork  40
    #define pic_chawaroj      41
    #define pic_manop         42
    #define pic_elle          43
    #define pic_pan           44
    #define pic_rboe          45   
    #define pic_tle           46        
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
    bool Frequency_Out(uint8_t pin, double freq);

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


/* PZEM-016 Modbus RTU AC power meter module */
bool   PZEM_016(uint8_t id, float &volt, float &amp, float &power, uint32_t &engergy, float &freq, float &pf);
float  PZEM_016_Volt(uint8_t id);
float  PZEM_016_Amp(uint8_t id);
float  PZEM_016_Power(uint8_t id);
int32_t  PZEM_016_Energy(uint8_t id);
float  PZEM_016_Freq(uint8_t id);  
float  PZEM_016_PF(uint8_t id);
bool PZEM_016_ResetEnergy(uint8_t id);
int8_t PZEM_016_SetAddress(uint8_t id, uint8_t new_id);
int8_t PZEM_016_SearchAddress(void);
bool PZEM_016_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);



/* PZEM-003 Modbus RTU DC power meter module */
bool   PZEM_003(uint8_t id, float &volt, float &amp, float &power, uint32_t &engergy);
float  PZEM_003_Volt(uint8_t id);
float  PZEM_003_Amp(uint8_t id);
float  PZEM_003_Power(uint8_t id);
int32_t  PZEM_003_Energy(uint8_t id);
bool PZEM_003_ResetEnergy(uint8_t id);
int8_t PZEM_003_SetAddress(uint8_t id, uint8_t new_id);
int8_t PZEM_003_SearchAddress(void);
bool PZEM_003_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);


/* WTR10-E Modbus RTU Temperature and Humidity sensor module */
bool WTR10_E_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
bool WTR10_E(uint8_t id, float &temp, float &humi);
float WTR10_E_tempeature(uint8_t id);
float WTR10_E_humidity(uint8_t id);

/* XY-MD02 Modbus RTU Temperature and Humidity sensor module */
bool XY_MD02_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
bool XY_MD02(uint8_t id, float &temp, float &humi);
float XY_MD02_tempeature(uint8_t id);
float XY_MD02_humidity(uint8_t id);
int8_t XY_MD02_searchAddress(void);
int8_t XY_MD02_SetAddress(uint8_t id, uint8_t new_id);

/* SOIL MOISTURE PR-3000-H-N01 sensor (RS485) module */
bool PR3000_H_N01_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
bool PR3000_H_N01(float &temp, float &humi);
float PR3000_H_N01_tempeature();
float PR3000_H_N01_humidity();

/* RS485 Water Flow Meter RS485 MODBUS output  */
bool WATER_FLOW_METER_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
int8_t WATER_FLOW_METER_searchAddress(void);
int8_t WATER_FLOW_METER_SetAddress(uint8_t id, uint8_t new_id);
float WATER_FLOW_METER(uint8_t id);


/* PYR20-Solar Radiation/Pyranometer Sensor, RS485, Modbus */
bool PYR20_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
int8_t PYR20_searchAddress(void);
int8_t PYR20_SetAddress(uint8_t id, uint8_t new_id);
int16_t PYR20_read(uint8_t id);

/* tiny32 ModbusRTU communication*/
bool tiny32_ModbusRTU_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
int8_t tiny32_ModbusRTU_searchAddress(void);
int8_t tiny32_ModbusRTU_setAddress(uint8_t id, uint8_t new_id);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7, float &val8, float &val9, float &val10);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7, float &val8, float &val9);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7, float &val8);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3);
bool tiny32_ModbusRTU(uint8_t id, float &val1, float &val2);
bool tiny32_ModbusRTU(uint8_t id, float &val1);

/* Control Fan 3phase model Model:ECF(K)8D355-PLHDAL11-RF */
bool MIZTEK_Fan1p_ModbusRTU_begin(uint8_t rx = RXD2, uint8_t tx = TXD2);
int8_t MIZTEK_Fan1p_ModbusRTU_searchAddress(void);
int8_t MIZTEK_Fan1p_ModbusRTU_setAddress(uint8_t id, uint8_t new_id);
bool MIZTEK_Fan1p_ModbusRTU_CtlSpeed(uint8_t id, uint16_t speed);





};




#endif