/***********************************************************************
 * Project      :     Example_RtcTest
 * Description  :     Test Real Time Clock IC (DS3231) on esp32_iot_all_v3 board
 * Hardware     :     esp32_iot_all_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     25/06/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <esp32_iot_all_v3.h>

esp32_iot_all_v3 mcu; //define object

/*** global variable ***/
uint16_t year;
uint8_t month; 
uint8_t day; 
uint8_t hour; 
uint8_t minute; 
uint8_t sec;
String dayofweek;
float temperature;
uint16_t timestamp;


void setup() {
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_RtcTest ****\r\n");
  mcu.library_version();

  mcu.beginTime();
  mcu.setDateTime(2022,6,25,22,12,30); //set date-time by parameter => year, month, day,hour, min, sec
}


void loop() {
  
    /*** get date-time ***/  
    //mcu.getDate(year,month,day); //get only date for RTC chip
    //mcu.getTime(hour,minute,sec); //get only time for RTC chip
    mcu.getDateTime(year,month,day,hour,minute,sec); //get date and time value from RTC chip
    Serial.printf("Date-Time => %d/%02d/%d  %02d:%02d:%02d\r\n",day,month,year,hour,minute,sec);

    /*** get day of week ***/
    dayofweek = mcu.getdayOfTheWeekChar();
    Serial.printf("Day => %s\r\n",dayofweek);

    /*** get tempeature from ds3231 rtc chip ***/
    temperature = mcu.getTemperature();
    Serial.printf("Temperature => %.1fC\r\n",temperature);

    /*** get time stamp ***/
    timestamp = mcu.getTimestamp();
    Serial.printf("Timestamp => %d\r\n",timestamp);

    vTaskDelay(1000);
}
