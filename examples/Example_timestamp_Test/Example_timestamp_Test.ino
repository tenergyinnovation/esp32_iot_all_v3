/***********************************************************************
 * Project      :     Example_timestamp_Test
 * Description  :     Test Encoding and Decoding Time stamp
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
  Serial.printf("\r\n**** Example_timestamp_Test ****\r\n");
  mcu.library_version();
}

void loop() {
  uint16_t _timeStamp;
  uint16_t _hour;
  uint16_t _minute;

  _timeStamp = mcu.TimeStamp_minute_encode(2022, 2, 19, 10, 30); //at date-time = 19/02/2022 10:30
  Serial.printf("[19/02/2022 10:30] => %d\r\n",_timeStamp); //show encoding timestamp

  _timeStamp = mcu.TimeStamp_24hr_encode(10, 30); //at time = 10:30
  Serial.printf("[10:30] => %d\r\n",_timeStamp);  //show encoding timestamp

  mcu.TimeStamp_hour_minute_decode(_timeStamp, _hour, _minute);
  Serial.printf("[%d] => %d:%d\r\n",_timeStamp,_hour,_minute); //show decoding timestamp

  while(1);

}
