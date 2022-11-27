/***********************************************************************
 * Project      :     Example_Uart2_Test
 * Description  :     Test UART2 port on esp32_iot_all_v3 board
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
HardwareSerial Uart2(1);

void setup() {
  Serial.begin(115200);
  Uart2.begin(9600, SERIAL_8N1, RXD3, TXD3);
  Serial.printf("\r\n**** Example_Uart2_Test ****\r\n");
  mcu.library_version();
}

void loop() {
  Uart2.println("Hello World[Uart2]"); //must connect rs485 port to rs485 to usb converter https://www.allnewstep.com/product/572/usb-to-rs485-usb-485-converter-adapter
  Serial.println("Hello World[Serial]");
  vTaskDelay(1000);

}
