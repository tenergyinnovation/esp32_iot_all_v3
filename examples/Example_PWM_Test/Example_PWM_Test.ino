/***********************************************************************
 * Project      :     Example_PWM_Test
 * Description  :     Test PWM for esp32_iot_all_v3, for drive DC motor or LED
 * Hardware     :     esp32_iot_all_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     25/06/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <esp32_iot_all_v3.h>

/* define parameter */
#define CHANNEL           0  //channel [0-15]
#define FREQ              5000 //freequency(Hz)
#define RESOLUTION_BIT    8  //Resolution [1-15 bit]
#define PWM_PIN           2 //pin on esp32_iot_all_v3

esp32_iot_all_v3 mcu; //define object

String Percentage=""; //global string variable


void setup() {
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_PWM_Test ****\r\n");
  mcu.library_version();
  mcu.PWM_Setup(CHANNEL, FREQ, RESOLUTION_BIT, PWM_PIN); //initial function
}

void loop() {

    while(Serial.available()) //waiting percentage from serial
    {
      int inChar =Serial.read();
      if (isDigit(inChar)) 
      {
        Percentage += (char)inChar;
      }
      if (inChar == '\n') {
          int _percentage_int = Percentage.toInt();
      
          mcu.PWM_Drive(CHANNEL,_percentage_int);
          Serial.printf("PWM[%c] => %d\r\n",37,_percentage_int);
          Percentage = ""; //clear value
      }

    }

}
