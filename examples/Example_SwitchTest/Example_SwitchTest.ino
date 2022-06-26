/***********************************************************************
 * Project      :     Example_SwitchTest
 * Description  :     Test button and slid switch for esp32_iot_all_v3 board
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
  Serial.printf("\r\n**** Example_SwitchTest ****\r\n");
  mcu.library_version();
}

void loop() {
  
  /**** read switch status ****/
  boolean _sw1 = mcu.Sw1();
  boolean _sw2 = mcu.Sw2();
  boolean _slidSw = mcu.Slid_sw();

  /**** Show switch status ****/
  Serial.printf("SW1 => %d\r\n",_sw1);
  Serial.printf("SW2 => %d\r\n",_sw2);
  Serial.printf("SLID SW => %d\r\n",_slidSw);
  Serial.println("------------------------");
  vTaskDelay(1000);
}
