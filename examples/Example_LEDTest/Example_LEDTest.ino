/***********************************************************************
 * Project      :     Example_LEDTest
 * Description  :     Test LED on esp32_iot_all_v3 board
 * Hardware     :     esp32_iot_all_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     25/06/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <esp32_iot_all_v3.h>

esp32_iot_all_v3 mcu; //define object

void setup() {
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_LEDTest ****\r\n");
  mcu.library_version();
}

void loop() {
  
  /**** RED LED ****/
  Serial.printf("RED LED => ON\r\n");
  mcu.RedLED(1);
  vTaskDelay(1000);
  Serial.printf("RED LED => OFF\r\n");
  mcu.RedLED(0);
  vTaskDelay(1000);

  /**** BLUE LED ****/
  Serial.printf("BLUE LED => ON\r\n");
  mcu.BlueLED(1);
  vTaskDelay(1000);
  Serial.printf("BLUE LED => OFF\r\n");
  mcu.BlueLED(0);
  vTaskDelay(1000);


  /**** BUILDIN LED ****/
  Serial.printf("BUILDIN LED => ON\r\n");
  mcu.BuildinLED(1);
  vTaskDelay(1000);
  Serial.printf("BUILDIN LED => OFF\r\n");
  mcu.BuildinLED(0);
  vTaskDelay(1000);  

}
