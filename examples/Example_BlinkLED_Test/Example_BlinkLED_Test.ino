/***********************************************************************
 * Project      :     Example_BlinkLED_Test
 * Description  :     Test Blink LED without relay time
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
  Serial.printf("\r\n**** Example_LEDTest ****\r\n");
  mcu.library_version();
}

void loop() {
  
  /**** RED LED Blink test  ****/
  Serial.printf("RED LED Blink (0.1sec)\r\n");
  mcu.TickRedLED(0.1);
  vTaskDelay(3000)
  ;
  Serial.printf("RED LED Blink (0.5sec)\r\n");
  mcu.TickRedLED(0.5);
  vTaskDelay(3000);

  Serial.printf("RED LED Blink (1sec)\r\n");
  mcu.TickRedLED(1);
  vTaskDelay(3000);

  Serial.printf("RED LED Blink (OFF)\r\n");
  mcu.TickRedLED(0);
  vTaskDelay(1000);


  /**** BLUE LED Blink test  ****/
  Serial.printf("BLUE LED Blink (0.1sec)\r\n");
  mcu.TickBlueLED(0.1);
  vTaskDelay(3000)
  ;
  Serial.printf("BLUE LED Blink (0.5sec)\r\n");
  mcu.TickBlueLED(0.5);
  vTaskDelay(3000);

  Serial.printf("BLUE LED Blink (1sec)\r\n");
  mcu.TickBlueLED(1);
  vTaskDelay(3000);

  Serial.printf("BLUE LED Blink (OFF)\r\n");
  mcu.TickBlueLED(0);
  vTaskDelay(1000);

  /**** BUILDIN LED Blink test  ****/
  Serial.printf("BUILDIN LED Blink (0.1sec)\r\n");
  mcu.TickBuildinLED(0.1);
  vTaskDelay(3000)
  ;
  Serial.printf("BUILDIN LED Blink (0.5sec)\r\n");
  mcu.TickBuildinLED(0.5);
  vTaskDelay(3000);

  Serial.printf("BUILDIN LED Blink (1sec)\r\n");
  mcu.TickBuildinLED(1);
  vTaskDelay(3000);

  Serial.printf("BUILDIN LED Blink (OFF)\r\n");
  mcu.TickBuildinLED(0);
  vTaskDelay(1000);


  Serial.printf("RED(0.1), BLUE(0.5), BUILDIN(1)\r\n");
  mcu.TickRedLED(0.1);
  mcu.TickBlueLED(0.5);
  mcu.TickBuildinLED(1);
  vTaskDelay(5000);

  Serial.printf("ALL LED OFF\r\n");
  mcu.TickRedLED(0);
  mcu.TickBlueLED(0);
  mcu.TickBuildinLED(0);
  vTaskDelay(1000);

  mcu.RedLED(0);
  mcu.BlueLED(0);
  mcu.BuildinLED(0);
}
