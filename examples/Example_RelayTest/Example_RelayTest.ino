/***********************************************************************
 * Project      :     Example_RelayTest
 * Description  :     Test Relay on esp32_iot_all_v3 board
 * Hardware     :     esp32_iot_all_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     19/02/2022
 * Revision     :     1.1
 * Rev1.0       :     Initial
 * Rev1.1       :     Change message status between "ON" and "OFF"
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <esp32_iot_all_v3.h>

esp32_iot_all_v3 mcu; //define object

void setup() {
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_RelayTest ****\r\n");
  mcu.library_version();
  mcu.Relay1(0);
  mcu.Relay2(0);
  mcu.Relay3(0);
  mcu.Relay4(0);
}

void loop() {
  
  /*** Relay 1 ***/
  Serial.printf("Relay1 => ON\r\n");
  mcu.Relay1(1);
  vTaskDelay(1000);

  Serial.printf("Relay1 => OFF\r\n");
  mcu.Relay1(0); 
  vTaskDelay(1000);

  /*** Relay 2 ***/
  Serial.printf("Relay2 => ON\r\n");
  mcu.Relay2(1);
  vTaskDelay(1000);

  Serial.printf("Relay2 => OFF\r\n");
  mcu.Relay2(0); 
  vTaskDelay(1000);

  /*** Relay 3 ***/
  Serial.printf("Relay3 => ON\r\n");
  mcu.Relay3(1);
  vTaskDelay(1000);

  Serial.printf("Relay3 => OFF\r\n");
  mcu.Relay3(0); 
  vTaskDelay(1000);

  /*** Relay 4 ***/
  Serial.printf("Relay4 => ON\r\n");
  mcu.Relay4(1);
  vTaskDelay(1000);

  Serial.printf("Relay4 => OFF\r\n");
  mcu.Relay4(0); 
  vTaskDelay(1000);  
}
