/***********************************************************************
 * Project      :     Example_Fequency_Out_Test
 * Description  :     Generate frequency via pin 5,18,23,19, Not allow for else
 *                    frequency range 0-19500Hz
 * Hardware     :     esp32_iot_all_V3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     19/02/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <esp32_iot_all_V3.h>

esp32_iot_all_v3 mcu;

/***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {

  Serial.begin(115200);
  Serial.printf("\r\n**** Example_Fequency_Out_Test ****\r\n");
  
  mcu.library_version();
  mcu.Frequency_Out(5,10000);  //pin 5,18,23,19, Not allow for else 
}                              //frequency range 0-19500Hz

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {

  
}



