/***********************************************************************
 * Project      :     Example_setClock
 * Description  :     Set Clock with SW1 and SW2
 *                    1. Can set clock by press and hold SW1 or SW2 during setup function (after reset)
 *                    SW = set value, SW2 = Enter
 *                    2. In loop function press SW1 and SW2 will Change status of Relay1 - Relay4
 *                    3. Slide switch will automatic change status of Relay1 - Relay4
 * Hardware     :     esp32_iot_all_V3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     19/02/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <esp32_iot_all_V3.h>

/**************************************/
/*        define object variable      */
/**************************************/
esp32_iot_all_v3 mcu; //define object


/**************************************/
/*        define global variable      */
/**************************************/
uint16_t year;
uint8_t month; 
uint8_t day; 
uint8_t hour; 
uint8_t minute; 
uint8_t sec;

/**************************************/
/*           define function          */
/**************************************/
void rtc_setting(void);

/***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {

  Serial.begin(115200);

  Serial.printf("\r\n**** Example_setClock ****\r\n");
  mcu.library_version();

  /*** OLED 128x64 i2c ***/
  mcu.beginOled();
  mcu.picOled(pic_clock);
  vTaskDelay(3000);

  /*** RTC (ds3231 ic) initial ***/
  mcu.beginTime();
  // mcu.adjustTime();  //Date and Time are value during upload program to esp32_iot_all board

  mcu.buzzer_beep(2); 
}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {

      static int8_t _rotate_relay = 0;
  
      String _data_str;
      char _time_str[30];

      /*** get date-time from RTC chip ***/
      mcu.getDateTime(year,month,day,hour,minute,sec); //get date and time value from RTC chip

      /*** show date-time to OLED display ***/
      mcu.clearOled();
      mcu.stringOled(0,5,2," ESP32_IOT_ALL");
      mcu.stringOled(0,20,1,"------------------------------------------");
      sprintf(_time_str,"       %02d:%02d:%02d",hour,minute,sec);
      mcu.stringOled(0,30,2,_time_str);
      sprintf(_time_str,"       [ %02d / %02d / %02d ]",day,month,year);
      mcu.stringOled(0,50,1,_time_str);


      /*** set clock by press SW1 or SW2 ***/
      if(mcu.Sw1() || mcu.Sw2())
      {
        mcu.picOled(pic_clock);
        mcu.buzzer_beep(3);
        while(mcu.Sw1() || mcu.Sw2());
        rtc_setting(); //call function setting RTC chip
      }

      vTaskDelay(1000);
  
}



 /***********************************************************************
 * FUNCTION:    rtc_setting
 * DESCRIPTION: Setting Time from DS3231
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void rtc_setting(void)
{
  Serial.println("Info: rtc  setting");  
  mcu.buzzer_beep(2);
    
  mcu.getDateTime(year,month,day,hour,minute,sec); //get date and time value from RTC chip
    
    mcu.clearOled();
    mcu.stringOled(10,10,3,"SET TIME");
    mcu.stringOled(0,20,3,"--------------------");
    while(mcu.Sw1()||mcu.Sw2());


    //*** setting hour ***
    do{      
        if(mcu.Sw1()){
            mcu.buzzer_beep(1);
            hour++; 
            if(hour>23) hour = 0;
            while(mcu.Sw1());
         }
        mcu.clearOled(); 
        mcu.stringOled(10,10,3,"SET TIME");
        mcu.stringOled(0,20,3,"--------------------");
        mcu.stringOled(35, 45,2,">" + String(hour) + "<:" + String(minute)); 
        delay(100);
      
      }while(!mcu.Sw2());
      while(mcu.Sw2());

       mcu.setDateTime(year,month,day,hour,minute,sec); //set date-time by parameter => year, month, day,hour, min, sec
      mcu.buzzer_beep(2);

    //*** setting minute ***
    do{
        if(mcu.Sw1()){
            mcu.buzzer_beep(1);
            minute++; 
            if(minute>59) minute = 0;
            while(mcu.Sw1());
         }

        mcu.clearOled();
        mcu.stringOled(10,10,3,"SET TIME");
        mcu.stringOled(0,20,3,"--------------------");
        mcu.stringOled(35, 45,2,String(hour) + ":>" + String(minute) + "<"); 
        delay(100);
      
      }while( !mcu.Sw2());
      while( mcu.Sw2() );    
       mcu.setDateTime(year,month,day,hour,minute,sec); //set date-time by parameter => year, month, day,hour, min, sec
      mcu.buzzer_beep(2);


    //*** setting day ***
    do{
        if(mcu.Sw1()){
            mcu.buzzer_beep(1);
            day++; 
            if(day>31) day = 1;
            while(mcu.Sw1());
         }
        mcu.clearOled();
        mcu.stringOled(10,10,3,"SET DATE");
        mcu.stringOled(0,20,3,"--------------------");
        mcu.stringOled(15, 45,2,">" + String(day) + "< / " + String(month) + " / " + String(year) );
        delay(100);
      
      }while( !mcu.Sw2());
      while( mcu.Sw2() );    
       mcu.setDateTime(year,month,day,hour,minute,sec); //set date-time by parameter => year, month, day,hour, min, sec
      mcu.buzzer_beep(2);      

      
    //*** setting month ***
    do{
        if(mcu.Sw1()){
            mcu.buzzer_beep(1);
            month++; 
            if(month>12) month = 1;
            while(mcu.Sw1());
         }

        mcu.clearOled();
        mcu.stringOled(10,10,3,"SET DATE");
        mcu.stringOled(0,20,3,"--------------------");
        mcu.stringOled(15, 45,2,String(day) + " / >" + String(month) + "< /" + String(year) );
        delay(100);
      
      }while( !mcu.Sw2());
      while( mcu.Sw2() );    
       mcu.setDateTime(year,month,day,hour,minute,sec); //set date-time by parameter => year, month, day,hour, min, sec
      mcu.buzzer_beep(2);  


    //*** setting year ***
    do{
        if(mcu.Sw1()){
            mcu.buzzer_beep(1);
            year++; 
            if(year>99) year = 1;
            while(mcu.Sw1());
         }
        mcu.clearOled();
        mcu.stringOled(10,10,3,"SET DATE");
        mcu.stringOled(0,20,3,"--------------------");
        mcu.stringOled(15, 45,2,String(day) + " / " + String(month) + " / >" + String(year) + "<" );
        delay(100);
      
      }while( !mcu.Sw2());
      while( mcu.Sw2() );    
      mcu.setDateTime(year,month,day,hour,minute,sec); //set date-time by parameter => year, month, day,hour, min, sec
      mcu.buzzer_beep(2);        
   
      mcu.clearOled();
      mcu.stringOled(10,10,3,"SET DATE");
      mcu.stringOled(0,20,3,"--------------------");
      mcu.stringOled(30, 45,2, "Finished");
      delay(500);  
}