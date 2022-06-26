/***********************************************************************
 * Project      :     Example_OLEDTest
 * Description  :     OLED 128x64 I2C on esp32_iot_all_v3 board
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



void setup() {
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_OLEDTest ****\r\n");
  mcu.library_version();
  mcu.beginOled();  
  mcu.picOled(pic_tenergy);
  vTaskDelay(2000);
}


void loop() {
    mcu.clearOled();
    mcu.stringOled(0,0,3,"Hello World");
    mcu.stringOled(0,25,2,"Hello World");
    mcu.stringOled(0,45,1,"Hello World");
    vTaskDelay(1000);

    mcu.picOled(pic_payuth);
    vTaskDelay(1000);

    mcu.picOled(pic_facebook);
    vTaskDelay(1000);

    mcu.picOled(pic_wificoffee);
    vTaskDelay(1000);

    mcu.picOled(pic_maintenance);
    vTaskDelay(1000);

    mcu.picOled(pic_led);
    vTaskDelay(1000);

}
