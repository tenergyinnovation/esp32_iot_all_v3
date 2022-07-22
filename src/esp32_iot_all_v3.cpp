/***********************************************************************
 * File         :     esp32_iot_all_v3.c
 * Description  :     Class for Hardware config and function for esp32_iot_all_v3 module
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     11 Dec 2021
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/
#include <esp32_iot_all_v3.h>
#include <Arduino.h>
#include <Ticker.h>
#include <esp32_iot_all_v3_Lib.h>
#include <SPI.h>
#include <RTClib.h>
#include <Wire.h>
#include <SSD1306Wire.h>
#include <images.h>
#include <OneWire.h>
// #include <DallasTemperature.h>

Ticker tickerRedLED;
Ticker tickerBlueLED;
Ticker tickerBuilinLED;
//rs485
// HardwareSerial rs485(1); //ทับกับ modbusRTU.h
HardwareSerial rs485(1);
HardwareSerial rs485_2(1);

RTC_DS3231 rtc; 
SSD1306Wire    display(0x3c, 21, 22);  //21 = SDA, 22 = SCL

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
// DallasTemperature sensors(&oneWire);
// arrays to hold device addresses
// DeviceAddress ds18b20_sensor[10];



/*** pre-define function(scope: protected) ***/
void tenergyImage();
void WiFiImage();
void WiFiOnImage();
void WiFiOffImage();
void HotspotImage();
void WiFiCoffeeImage();
void FacebookImage();
void BugImage();
void FixImage();
void drawProgressBarDemo();
void CameraImage();
void ClockImage();
void MotorImage();
void EepromImage();
void HomeImage();
void LedImage();
void MotionImage();
void RelayImage();
void Rs485Image();
void SteppingImage();
void TemperatureImage();
void Tmp1638Image();
void UltrasonicImage();
void UtenImage();
void PotentiometerImage();
void LdrImage();
void PayuthImage();
void Dip3swImage();
void MjuImage();
void InputImage();
void SwitchImage();
void NetpieImage();
void AmpereImage();
void BlynkImage();
void BatteryImage();
void HospitalImage();
void PoliceImage();
void ChaiImage();
void AddImage();
void ChatchatImage();
void WorkworkworkImage();
void ChawarojImage();
void ManopImage();
void ElleImage();
void PanImage();
void RboeImage();
void TleImage();    





esp32_iot_all_v3::esp32_iot_all_v3(/* args */)
{
    pinMode(OUTPUT_1,OUTPUT);
    pinMode(OUTPUT_2,OUTPUT);
    pinMode(OUTPUT_3,OUTPUT);
    pinMode(OUTPUT_4,OUTPUT);
    pinMode(BUTTON_SW1,INPUT);
    pinMode(BUTTON_SW2,INPUT);
    pinMode(SLID_SW,INPUT);
    pinMode(LED_BLUE,OUTPUT);
    pinMode(LED_RED,OUTPUT);
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(BUZZER,OUTPUT);
    // rs485.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

esp32_iot_all_v3::~esp32_iot_all_v3()
{

}


typedef void (*Demo)(void);
Demo demos[] = {tenergyImage, drawProgressBarDemo, WiFiImage, WiFiOnImage, WiFiOffImage, HotspotImage, WiFiCoffeeImage, FacebookImage, BugImage, FixImage,
                CameraImage, ClockImage, MotorImage, EepromImage, HomeImage, LedImage, MotionImage, RelayImage, Rs485Image, SteppingImage, TemperatureImage, Tmp1638Image,
                UltrasonicImage, UtenImage, PotentiometerImage, LdrImage, PayuthImage, Dip3swImage, MjuImage, InputImage,SwitchImage,NetpieImage,AmpereImage,BlynkImage,BatteryImage,
               HospitalImage,PoliceImage,ChaiImage,AddImage,ChatchatImage,WorkworkworkImage,ChawarojImage,ManopImage,ElleImage,PanImage,RboeImage,TleImage
               };
int demoMode = 0;
int counter = 1;
int demoLength = (sizeof(demos) / sizeof(Demo));

 /***********************************************************************
 * FUNCTION:    library_version
 * DESCRIPTION: Print out library version
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::library_version(void) 
{ 
    Serial.printf("library version: %s\r\n",version_c); 
}

 /***********************************************************************
 * FUNCTION:    Relay
 * DESCRIPTION: Control ON-OFF Relay
 * PARAMETERS:  0 or 1
 * RETURNED:    true,false
 ***********************************************************************/
bool esp32_iot_all_v3::Relay1(bool status)
{
    if(status == 0 || status == 1)
    {
        digitalWrite(OUTPUT_1,!status);
        return 1;
    }
    else
    {
        return 0;
    }
}

 /***********************************************************************
 * FUNCTION:    Relay
 * DESCRIPTION: Control ON-OFF Relay
 * PARAMETERS:  0 or 1
 * RETURNED:    true,false
 ***********************************************************************/
bool esp32_iot_all_v3::Relay2(bool status)
{
    if(status == 0 || status == 1)
    {
        digitalWrite(OUTPUT_2,!status);
        return 1;
    }
    else
    {
        return 0;
    }
}

 /***********************************************************************
 * FUNCTION:    Relay
 * DESCRIPTION: Control ON-OFF Relay
 * PARAMETERS:  0 or 1
 * RETURNED:    true,false
 ***********************************************************************/
bool esp32_iot_all_v3::Relay3(bool status)
{
    if(status == 0 || status == 1)
    {
        digitalWrite(OUTPUT_3,!status);
        return 1;
    }
    else
    {
        return 0;
    }

}

 /***********************************************************************
 * FUNCTION:    Relay
 * DESCRIPTION: Control ON-OFF Relay
 * PARAMETERS:  0 or 1
 * RETURNED:    true,false
 ***********************************************************************/
bool esp32_iot_all_v3::Relay4(bool status)
{
    if(status == 0 || status == 1)
    {
        digitalWrite(OUTPUT_4,!status);
        return 1;
    }
    else
    {
        return 0;
    }
}


 /***********************************************************************
 * FUNCTION:    Sw1
 * DESCRIPTION: Read button switch
 * PARAMETERS:  nothing
 * RETURNED:    0 or 1
 ***********************************************************************/
bool esp32_iot_all_v3::Sw1(void)
{
    return !digitalRead(BUTTON_SW1);

}

 /***********************************************************************
 * FUNCTION:    Sw2
 * DESCRIPTION: Read button switch
 * PARAMETERS:  nothing
 * RETURNED:    0 or 1
 ***********************************************************************/
bool esp32_iot_all_v3::Sw2(void)
{
    return !digitalRead(BUTTON_SW2);
}


 /***********************************************************************
 * FUNCTION:    Slid_sw
 * DESCRIPTION: Read slid switch
 * PARAMETERS:  nothing
 * RETURNED:    0 or 1
 ***********************************************************************/
bool esp32_iot_all_v3::Slid_sw(void)
{
    return !digitalRead(SLID_SW);
}

 /***********************************************************************
 * FUNCTION:    RedLED
 * DESCRIPTION: ON-OFF Red LED[pin4]
 * PARAMETERS:  0 or 1
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::RedLED(bool state){
    digitalWrite(LED_RED,state);
}

 /***********************************************************************
 * FUNCTION:    BlueLED
 * DESCRIPTION: ON-OFF Blue LED[pin12]
 * PARAMETERS:  0 or 1
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::BlueLED(bool state){
    digitalWrite(LED_BLUE,state);
}


 /***********************************************************************
 * FUNCTION:    BlueinLED
 * DESCRIPTION: ON-OFF Bulidin LED[pin2]
 * PARAMETERS:  0 or 1
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::BuildinLED(bool state){
    digitalWrite(LED_BUILTIN,state);
}


 /***********************************************************************
 * FUNCTION:    TickBlueLED
 * DESCRIPTION: Blink BlueLED[pin4]
 * PARAMETERS:  nothing
 * RETURNED:    0 = Off, 1 < blink 
 ***********************************************************************/
void esp32_iot_all_v3::TickBlueLED(float second)
{
    if(second<=0){
        tickerBlueLED.detach();
        BlueLED(0);
    }
    else{
        tickerBlueLED.attach(second,TickBlueLED_blink);
    }
}

 /***********************************************************************
 * FUNCTION:    TickRedLED
 * DESCRIPTION: Blink RedLED[pin12]
 * PARAMETERS:  nothing
 * RETURNED:    0 = Off, 1 < blink 
 ***********************************************************************/
void esp32_iot_all_v3::TickRedLED(float second)
{
    if(second<=0){
        tickerRedLED.detach();
        RedLED(0);
    }
    else{
        tickerRedLED.attach(second,TickRedLED_blink);
    }
}

 /***********************************************************************
 * FUNCTION:    BuildinLED
 * DESCRIPTION: Blink BuildinLED[pin2]
 * PARAMETERS:  nothing
 * RETURNED:    0 = Off, 1 < blink 
 ***********************************************************************/
void esp32_iot_all_v3::TickBuildinLED(float second) 
{
    if(second<=0){
        tickerBuilinLED.detach();
        BuildinLED(0);
    }
    else{
        tickerBuilinLED.attach(second,TickBuildinLED_blink);
    }
}



 /***********************************************************************
 * FUNCTION:    buzzer_beep
 * DESCRIPTION: buzzer sound beep[pin13]
 * PARAMETERS:  times
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::buzzer_beep(int times){
  #define PLUSE_BUZZER
//#define DC_BUZZER
    
  for(int _i=0; _i < times; _i++){
        #ifdef PLUSE_BUZZER
        #define dt  50 //0.1sec

         int _j;
         for(_j = dt ; _j > 0; _j--){
               digitalWrite(BUZZER,HIGH);
               vTaskDelay(1);
               digitalWrite(BUZZER,LOW);
               vTaskDelay(1);

         }
         vTaskDelay(100);
        #endif

        #ifdef DC_BUZZER
            digitalWrite(BUZZER,HIGH);
            vTaskDelay(70);
            digitalWrite(BUZZER,LOW);
            vTaskDelay(70);
        #endif  
  }
}  

 /***********************************************************************
 * FUNCTION:    beginTime
 * DESCRIPTION: Inital DS3231 RTC
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
 void esp32_iot_all_v3::beginTime(void)
 {
    /* Intial DS3231 Real Time rtc (rtc) */
    if (! rtc.begin()) {
        Serial.println("Couldn't find rtc");
        Serial.flush();
        while (1) delay(10);
    }
 }

 /***********************************************************************
 * FUNCTION:    setDateTime
 * DESCRIPTION: set Date and Time to DS3231
 * PARAMETERS:  year, month, day,hour, min, sec
 * RETURNED:    true,false
 ***********************************************************************/
 bool esp32_iot_all_v3::setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
 {
     rtc.adjust(DateTime(year,month,day,hour,min,sec));
     return 1;
 }

 
 /***********************************************************************
 * FUNCTION:    getTime
 * DESCRIPTION: Get Time from DS3231
 * PARAMETERS:  referance hour, min, sec
 * RETURNED:    nothing
 ***********************************************************************/
 void esp32_iot_all_v3::getTime(uint8_t &_hour, uint8_t &_min, uint8_t &_sec)
 {
     DateTime now = rtc.now();
    
     _hour = now.hour();
     _min = now.minute();
     _sec = now.second();

 }

 /***********************************************************************
 * FUNCTION:    getDate
 * DESCRIPTION: Get Date from DS3231
 * PARAMETERS:  referance year, month, day
 * RETURNED:    nothing
 ***********************************************************************/
 void esp32_iot_all_v3::getDate(uint16_t &_year, uint8_t &_month, uint8_t &_day)
 {
    DateTime now = rtc.now();
    _year = now.year();
    _month = now.month();
    _day = now.day();
 }


 /***********************************************************************
 * FUNCTION:    getDateTime
 * DESCRIPTION: Get DateTime from DS3231
 * PARAMETERS:  referance year, month, day,hour, min, sec
 * RETURNED:    nothing
 ***********************************************************************/
 void esp32_iot_all_v3::getDateTime(uint16_t &_year, uint8_t &_month, uint8_t &_day, uint8_t &_hour, uint8_t &_min, uint8_t &_sec)
 {
     DateTime now = rtc.now();
    _year = now.year();
    _month = now.month();
    _day = now.day();
    _hour = now.hour();
    _min = now.minute();
    _sec = now.second();
 }

 /***********************************************************************
 * FUNCTION:    getdayOfTheWeekChar
 * DESCRIPTION: Get Day of Week from DS3231
 * PARAMETERS:  nothing
 * RETURNED:    "Sunday", "Monday", "Tuesday", "Wednesday", 
 *              "Thursday", "Friday", "Saturday"
 ***********************************************************************/
 char* esp32_iot_all_v3::getdayOfTheWeekChar(void)
 {
     DateTime now = rtc.now();
     return daysOfTheWeek[now.dayOfTheWeek()];

 }


 /***********************************************************************
 * FUNCTION:    getdayOfTheWeekNum
 * DESCRIPTION: Get Day of Week from DS3231
 * PARAMETERS:  nothing
 * RETURNED:    number 0 - 6 [Sunday-Saturday]
 ***********************************************************************/
 uint8_t esp32_iot_all_v3::getdayOfTheWeekNum(void)
 {
     DateTime now = rtc.now();
     return now.dayOfTheWeek();
 }

 /***********************************************************************
 * FUNCTION:    getTemperature
 * DESCRIPTION: Get temperature from DS3231
 * PARAMETERS:  nothing
 * RETURNED:    temperature
 ***********************************************************************/
 float esp32_iot_all_v3::getTemperature(void)
 {
     return rtc.getTemperature();
 }

 /***********************************************************************
 * FUNCTION:    getTimestamp
 * DESCRIPTION: Get Timestemp from DS3231
 * PARAMETERS:  nothing
 * RETURNED:    Timestamp begin from minute
 ***********************************************************************/
uint16_t esp32_iot_all_v3::getTimestamp(void) {
    DateTime now = rtc.now();
    uint16_t _year = now.year();
    uint8_t _month = now.month();
    uint8_t _day = now.day();
    uint8_t _hour = now.hour();
    uint8_t _min = now.minute();
    uint8_t _sec = now.second();
  uint16_t _numberofdays;
    if (_year >= 2000)
        _year -= 2000;
    uint16_t days = _day;
    for (uint8_t i = 1; i < _month; ++i)
        days += pgm_read_byte(daysInMonth + i - 1);
    if (_month > 2 && _year % 4 == 0)
        ++_day;
    _numberofdays = _day + 365 * _year + (_year + 3) / 4 - 1;    
    _numberofdays --;
    
    // Serial.printf("Debug: numberofminute = %d\r\n",(_numberofdays*24*60) + (h*60) + mi);
    return (_numberofdays*24*60) + (_hour*60) + _min;
}

/***********************************************************************
 * FUNCTION:    TimeStamp_minute_encode
 * DESCRIPTION: number of days since 2000/01/01, valid for 2001..2099
 * PARAMETERS:  y, m, d, h, mi (Example: 2020,8,13,22,55)
 * RETURNED:    minute
 ***********************************************************************/
uint16_t esp32_iot_all_v3::TimeStamp_minute_encode(uint16_t y, uint8_t m, uint8_t d, uint8_t h, uint8_t mi) {
  uint16_t _numberofdays;
    if (y >= 2000)
        y -= 2000;
    uint16_t days = d;
    for (uint8_t i = 1; i < m; ++i)
        days += pgm_read_byte(daysInMonth + i - 1);
    if (m > 2 && y % 4 == 0)
        ++days;
    _numberofdays = days + 365 * y + (y + 3) / 4 - 1;    
    _numberofdays --;
    
    // Serial.printf("Debug: numberofminute = %d\r\n",(_numberofdays*24*60) + (h*60) + mi);
    return (_numberofdays*24*60) + (h*60) + mi;
}

/***********************************************************************
 * FUNCTION:    TimeStamp_24hr_encode
 * DESCRIPTION: Encoding time stamp
 * PARAMETERS:  h, mi (Example: 22,55)
 * RETURNED:    tempstamp
 ***********************************************************************/
uint16_t esp32_iot_all_v3::TimeStamp_24hr_encode(uint16_t h, uint16_t mi)
{
    return ((h*60) + mi);
}

/***********************************************************************
 * FUNCTION:    TimeStamp_hour_minute_decode
 * DESCRIPTION: Decoding time stamp
 * PARAMETERS:  timestemp
 * RETURNED:    hour, minute
 ***********************************************************************/
void esp32_iot_all_v3::TimeStamp_hour_minute_decode(uint16_t timestemp, uint16_t &h, uint16_t &mi)
{
    h=timestemp/60;
    mi=timestemp%60;
}


/***********************************************************************
 * FUNCTION:    beginOled
 * DESCRIPTION: Initial OLED display
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::beginOled(void)
{
    display.init();
    display.flipScreenVertically();
    
}


/***********************************************************************
 * FUNCTION:    logoOled
 * DESCRIPTION: Slow Logo on OLED
 * PARAMETERS:  pic_xxx 
 *              Example : pic_tenergy
 *                      : pic_clear <clear screen>
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::picOled(int pic_xxx)
{
    display.flipScreenVertically();
    display.clear();
    if(pic_xxx != pic_clear)
    {
        demos[pic_xxx]();
    }
    display.display();
}

/***********************************************************************
 * FUNCTION:    stringOled
 * DESCRIPTION: Draw string to screen
 * PARAMETERS:  X-position, Y-position, Font Size[1-3], String
 * RETURNED:    true, false
 ***********************************************************************/
bool esp32_iot_all_v3::stringOled(int16_t xMove, int16_t yMove, uint8_t fontSize, String strUser)
{
    if(fontSize==1)
    {
        display.setFont(ArialMT_Plain_10);        
    }
    else if(fontSize==2)
    {
        display.setFont(ArialMT_Plain_16);
    }
    else if(fontSize==3)
    {
        display.setFont(ArialMT_Plain_24);
    }
    else
    {
        Serial.printf("Error: fontSize must be [1-3]\r\n");
        return 0;
    }

    display.drawString(xMove,yMove,strUser);
    display.display();
    return 1;

}

/***********************************************************************
 * FUNCTION:    clearOled
 * DESCRIPTION: Clear screen
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::clearOled(void)
{
    display.clear();
    display.display();
}


 /***********************************************************************
 * FUNCTION:    syncTimeServer
 * DESCRIPTION: sync Time(DS2321) from server
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
bool esp32_iot_all_v3::syncTimeServer(void)
{
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // struct tm timeinfo;
  // if(!getLocalTime(&timeinfo)){
  //   // Serial.println("Error: Failed to time sync");
  //   return 0;
  // }
  // else
  // {
  //   rtc.adjust(DateTime(timeinfo.tm_year-100,timeinfo.tm_mon+1,timeinfo.tm_mday,timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec));
  //   // Serial.printf("Info: Success sync time server\r\n");
  //   return 1;
  // }
  
}


 /***********************************************************************
 * FUNCTION:    adjustTime
 * DESCRIPTION: Adjust Time(DS2321) from computer during upload program*
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void esp32_iot_all_v3::adjustTime(void)
{
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //Date and Time are value during upload program to esp32_iot_all board
}


/***********************************************************************
 * FUNCTION:    PWN_Setup
 * DESCRIPTION: Pulse Width Mod setting up
 * PARAMETERS:  channel[0-15], frequency(Hz), resolution[1-15], pin
 * RETURNED:    0 = error, 1 = pass 
 ***********************************************************************/
bool esp32_iot_all_v3::PWM_Setup(uint8_t channel, double freq, uint8_t resolution_bit, uint8_t pin){
        if(channel>15 || channel<0 || resolution_bit>15 || resolution_bit<1)
        {
            Serial.printf("Error: wrong parameter!!\r\n");
            return 0;
        }
        ledcSetup(channel,freq,resolution_bit);
        ledcAttachPin(pin,channel);
        _resolution_bit = resolution_bit;
        return 1;
}

 /***********************************************************************
 * FUNCTION:    PWM_Drive
 * DESCRIPTION: Pulse Width Mod drive
 * PARAMETERS:  channel[0-15], percentage[0-100]
 * RETURNED:    0 = error, 1 = pass 
 ***********************************************************************/
bool esp32_iot_all_v3::PWM_Drive(uint8_t channel,uint8_t percentage){
    double _duty=0;

    if(percentage>100 || percentage<0)
    {
        Serial.printf("Error: Out of range parameter\r\n");
        return 0;
    }
    else
    {
        // Serial.printf("_resolution_bit = %d\r\n",_resolution_bit);
        // Serial.printf("percentage = %d\r\n",percentage);

        if(_resolution_bit==1) _duty = (double)percentage*0.02;
        else if(_resolution_bit==2) _duty = (double)percentage*0.04;
        else if(_resolution_bit==3) _duty = (double)percentage*0.08;
        else if(_resolution_bit==4) _duty = (double)percentage*0.16;
        else if(_resolution_bit==5) _duty = (double)percentage*0.32;
        else if(_resolution_bit==6) _duty = (double)percentage*0.64;
        else if(_resolution_bit==7) _duty = (double)percentage*1.28;
        else if(_resolution_bit==8) _duty = (double)percentage*2.56;
        else if(_resolution_bit==9) _duty = (double)percentage*5.12;
        else if(_resolution_bit==10) _duty = (double)percentage*10.24;
        else if(_resolution_bit==11) _duty = (double)percentage*20.48;
        else if(_resolution_bit==12) _duty = (double)percentage*40.96;
        else if(_resolution_bit==13) _duty = (double)percentage*81.92;
        else if(_resolution_bit==14) _duty = (double)percentage*163.84;
        else if(_resolution_bit==15) _duty = (double)percentage*327.68;

        ledcWrite(channel,_duty);
        // Serial.printf("Debug: duty = %f\r\n",_duty);
        return 1;   
    }
}


 /***********************************************************************
 * FUNCTION:    Frequency_Out
 * DESCRIPTION: Generate Frequency to pin 5,18,23,19 but else not allow
 * PARAMETERS:  pin=[5,18,23 and 19], freq=0-19500Hz
 * RETURNED:    0 = error, 1 = pass 
 ***********************************************************************/
bool esp32_iot_all_v3::Frequency_Out(uint8_t pin, double freq)
{

  uint8_t _channel;

  /* check pin */
  if( (pin != 5) && (pin != 18) && (pin != 23) && (pin != 19) )
  {
    Serial.printf("Error: parameter input pin must be 5,18,23,19 but else is not allow\r\n");
    return 0;
  }
  else
  {
    /* define channel */
    switch (pin)
    {
    case 5:
      _channel=1;
      break;
    case 18:
      _channel=3;
      break;
    case 23:
      _channel=5;
      break;
    case 19:
      _channel=7;
      break;
    default:
      break;
    }
  }

  /* check frequency */
  if( (freq < 0) || (freq > 19500) )
  {
    Serial.printf("Error: Out of range frequency [0-19500Hz]\r\n");
    return 0;
  }


  /* set 0 Hz */
  if(freq == 0)
  {
        Serial.printf("Info: pin = %d, channel = %d, frequency = %.0fHz\r\n",pin,_channel,freq);
        ledcSetup(_channel,1,12);
        ledcAttachPin(pin,_channel);
        ledcWrite(pin,0);
        vTaskDelay(300);
        return 1;
  }
  else
  {
        Serial.printf("Info: pin = %d, channel = %d, frequency = %.0fHz\r\n",pin,_channel,freq);
        ledcSetup(_channel,freq,12);
        ledcAttachPin(pin,_channel);
        ledcWrite(_channel,4095/2);
        vTaskDelay(300);
        
        ledcSetup(_channel,freq,12); //<- Fix bug by need to re-run command
        ledcAttachPin(pin,_channel);
        ledcWrite(_channel,4095/2);
        vTaskDelay(300);
        return 1;
  }
  
}

#pragma region  OLED PICTURE

/***********************************************************************
   FUNCTION:    drawProgressBarDemo
   DESCRIPTION: drawProgressBarDemo
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void drawProgressBarDemo() {
  int progress = (counter / 5) % 100;
  // draw the progress bar
  display.drawProgressBar(0, 32, 120, 10, progress);

  // draw the percentage as String
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 15, String(progress) + "%");
}


/***********************************************************************
  FUNCTION:    tenergyImage
  DESCRIPTION: tenergyImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void tenergyImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, Tenergy_Logo_width, Tenergy_Logo_height, Tenergy_Logo_bits);
}

/***********************************************************************
  FUNCTION:    WiFiImage
  DESCRIPTION: WiFiImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void WiFiImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(34, 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
}

/***********************************************************************
  FUNCTION:    hotspotImage
  DESCRIPTION: hotspotImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void WiFiOnImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(34, 14, WiFi_on_Logo_width, WiFi_on_Logo_height, WiFi_on_bits);
}


/***********************************************************************
  FUNCTION:    hotspotoffImage
  DESCRIPTION: hotspotoffImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void WiFiOffImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(47, 16, WiFi_off_Logo_width, WiFi_off_Logo_height, WiFi_off_bits);
}

/***********************************************************************
  FUNCTION:    HotspotImage
  DESCRIPTION: HotspotImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void HotspotImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 15, hotspot_Logo_width, hotspot_Logo_height, hotspot_bits);
}


/***********************************************************************
  FUNCTION:    WiFiCoffeeImage
  DESCRIPTION: WiFiCoffeeImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void WiFiCoffeeImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 14, wificoffee_Logo_width, wificoffee_Logo_height, wificoffee_bits);
}


/***********************************************************************
  FUNCTION:    FacebookImage
  DESCRIPTION: FacebookImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void FacebookImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(45, 19, facebook_Logo_width, facebook_Logo_height, facebook_bits);
}

/***********************************************************************
  FUNCTION:    BugImage
  DESCRIPTION: BugImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void BugImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(45, 19, bug_Logo_width, bug_Logo_height, bug_bits);
}

/***********************************************************************
  FUNCTION:    FixImage
  DESCRIPTION: FixImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void FixImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(45, 15, maintenance_Logo_width, maintenance_Logo_height, maintenance_bits);
}


/***********************************************************************
  FUNCTION:    CameraImage
  DESCRIPTION: CameraImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void CameraImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(30, 10, camera_Logo_width, camera_Logo_height, camera_bits);
}

/***********************************************************************
  FUNCTION:    ClockImage
  DESCRIPTION: ClockImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void ClockImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(35, 10, clock_Logo_width, clock_Logo_height, clock_bits);
}

/***********************************************************************
  FUNCTION:    MotorImage
  DESCRIPTION: MotorImage
  PARAMETERS:  nothing
  RETURNED:    nothing
***********************************************************************/
void MotorImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(35, 10, motor_dc_Logo_width, motor_dc_Logo_height, motor_dc_bits);
}

/***********************************************************************
   FUNCTION:    EepromImage
   DESCRIPTION: EepromImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void EepromImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(30, 6, eeprom_Logo_width, eeprom_Logo_height, eeprom_bits);
}

/***********************************************************************
   FUNCTION:    HomeImage
   DESCRIPTION: HomeImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void HomeImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 15, home_Logo_width, home_Logo_height, home_bits);
}

/***********************************************************************
   FUNCTION:    LedImage
   DESCRIPTION: LedImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void LedImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 15, led_Logo_width, led_Logo_height, led_bits);
}

/***********************************************************************
   FUNCTION:    MotionImage
   DESCRIPTION: MotionImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void MotionImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 15, motion_Logo_width, motion_Logo_height, motion_bits);
}

/***********************************************************************
   FUNCTION:    RelayImage
   DESCRIPTION: RelayImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void RelayImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(45, 10, relay_Logo_width, relay_Logo_height, relay_bits);
}

/***********************************************************************
   FUNCTION:    Rs485Image
   DESCRIPTION: Rs485Image
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void Rs485Image() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(38, 10, rs485_Logo_width, rs485_Logo_height, rs485_bits);
}

/***********************************************************************
   FUNCTION:    SteppingImage
   DESCRIPTION: SteppingImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void SteppingImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(45, 15, stepping_Logo_width, stepping_Logo_height, stepping_bits);
}

/***********************************************************************
   FUNCTION:    TemperatureImage
   DESCRIPTION: TemperatureImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void TemperatureImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
//  display.drawXbm(45, 15, temperature_Logo_width, temperature_Logo_height, temperature_bits); //center
  display.drawXbm(45, 3, temperature_Logo_width, temperature_Logo_height, temperature_bits); //top
}

/***********************************************************************
   FUNCTION:    Tmp1638Image
   DESCRIPTION: Tmp1638Image
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void Tmp1638Image() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(12, 5, tmp1638_Logo_width, tmp1638_Logo_height, tmp1638_bits);
}

/***********************************************************************
   FUNCTION:    UltrasonicImage
   DESCRIPTION: UltrasonicImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void UltrasonicImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(35, 8, ultrasonic_Logo_width, ultrasonic_Logo_height, ultrasonic_bits);
}


/***********************************************************************
   FUNCTION:    UtenImage
   DESCRIPTION: UtenImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void UtenImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, uten_Logo_width, uten_Logo_height, uten_bits);
}

/***********************************************************************
   FUNCTION:    UtenImage
   DESCRIPTION: UtenImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void PotentiometerImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 5, potentiometer_Logo_width, potentiometer_Logo_height, potentiometer_bits);
}

/***********************************************************************
   FUNCTION:    LdrImage
   DESCRIPTION: LdrImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void LdrImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(40, 5, ldr_Logo_width, ldr_Logo_height, ldr_bits);
}

/***********************************************************************
   FUNCTION:    PayuthImage
   DESCRIPTION: PayuthImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void PayuthImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, payuth_Logo_width, payuth_Logo_height, payuth_bits);
}

/***********************************************************************
   FUNCTION:    Dip3swImage
   DESCRIPTION: Dip3swImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void Dip3swImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(20, 3, dip3sw_Logo_width, dip3sw_Logo_height, dip3sw_bits);
}


/***********************************************************************
   FUNCTION:    MjuImage
   DESCRIPTION: MjuImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void MjuImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(15, 3, mju_Logo_width, mju_Logo_height, mju_bits);
}


/***********************************************************************
   FUNCTION:    InputImage
   DESCRIPTION: InputImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void InputImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, input_Logo_width, input_Logo_height, input_bits);
}

/***********************************************************************
   FUNCTION:    SwitchImage
   DESCRIPTION: SwitchImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void SwitchImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, switch_Logo_width, switch_Logo_height, switch_bits);
}

/***********************************************************************
   FUNCTION:    NetpieImage
   DESCRIPTION: NetpieImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void NetpieImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, netpie_Logo_width, netpie_Logo_height, netpie_bits);
}


/***********************************************************************
   FUNCTION:    AmpereImage
   DESCRIPTION: AmpereImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void AmpereImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, ampere_Logo_width, ampere_Logo_height, ampere_bits);
}

/***********************************************************************
   FUNCTION:    BlynkImage
   DESCRIPTION: BlynkImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void BlynkImage() {
  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  // on how to create xbm files
  display.drawXbm(0, 0, blynk_Logo_width, blynk_Logo_height, blynk_bits);
}

/***********************************************************************
   FUNCTION:    BatteryImage
   DESCRIPTION: BatteryImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void BatteryImage() {
  display.drawXbm(0, 0, battery_Logo_width, battery_Logo_height, battery_bits);
}

/***********************************************************************
   FUNCTION:    HospitalImage
   DESCRIPTION: HospitalImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void HospitalImage() {
  display.drawXbm(0, 0, hospital_Logo_width, hospital_Logo_height, hospital_bits);
}

/***********************************************************************
   FUNCTION:    PoliceImage
   DESCRIPTION: PoliceImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void PoliceImage() {
  display.drawXbm(0, 0, police_Logo_width, police_Logo_height, police_bits);
}

/***********************************************************************
   FUNCTION:    ChaiImage
   DESCRIPTION: ChaiImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void ChaiImage() {
  display.drawXbm(0, 0, chai_Logo_width, chai_Logo_height, chai_bits);
}

/***********************************************************************
   FUNCTION:    AddImage
   DESCRIPTION: AddImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void AddImage() {
  display.drawXbm(0, 0, add_Logo_width, add_Logo_height, add_bits);
}

/***********************************************************************
   FUNCTION:    ChatchatImage
   DESCRIPTION: ChatchatImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void ChatchatImage() {
  display.drawXbm(0, 0, chatchat_Logo_width, chatchat_Logo_height, chatchat_bits);
}

/***********************************************************************
   FUNCTION:    WorkworkworkImage
   DESCRIPTION: WorkworkworkImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void WorkworkworkImage() {
  display.drawXbm(0, 0, workworkwork_Logo_width, workworkwork_Logo_height, workworkwork_bits);
}


/***********************************************************************
   FUNCTION:    ChawarojImage
   DESCRIPTION: ChawarojImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void ChawarojImage()
{
display.drawXbm(0, 0, chawaroj_Logo_width, chawaroj_Logo_height, chawaroj_bits);
}

/***********************************************************************
   FUNCTION:    ManopImage
   DESCRIPTION: ManopImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void ManopImage()
{
display.drawXbm(0, 0, manop_Logo_width, manop_Logo_height, manop_bits);
}

/***********************************************************************
   FUNCTION:    ElleImage
   DESCRIPTION: ElleImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void ElleImage()
{
display.drawXbm(0, 0, elle_Logo_width, elle_Logo_height,elle_bits);
}

/***********************************************************************
   FUNCTION:    PanImage
   DESCRIPTION: PanImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void PanImage()
{
display.drawXbm(0, 0, pan_Logo_width, pan_Logo_height, pan_bits);
}

/***********************************************************************
   FUNCTION:    RboeImage
   DESCRIPTION: RboeImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void RboeImage()
{
display.drawXbm(0, 0, rboe_Logo_width, rboe_Logo_height, rboe_bits);
}

/***********************************************************************
   FUNCTION:    TleImage
   DESCRIPTION: TleImage
   PARAMETERS:  nothing
   RETURNED:    nothing
 ***********************************************************************/
void TleImage()
{
display.drawXbm(0, 0, tle_Logo_width, tle_Logo_height, tle_bits);
}

#pragma endregion


/***********************************************************************
 * FUNCTION:    PZEM_016
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    true, false and reference parameter => volt, amp, power, energy, freq, pf
 ***********************************************************************/
bool esp32_iot_all_v3::PZEM_016(uint8_t id, float &volt, float &amp, float &power, uint16_t &energy, float &freq, float &pf)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 


       /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read volt ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      volt = (float)_temp_hex_16bit * 0.1;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: volt[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: volt[float] => %.1f\r\n",volt);
      #endif


      //**** Read Current ****
       _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[7];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[8]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      amp = (float)_temp_hex_32bit * 0.001;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: amp[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: amp[float] => %.1f\r\n",amp);
      #endif

      //**** Read Power ****
      _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[11];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[12]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[9];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[10]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      power = (float)_temp_hex_32bit * 0.1;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: power[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: power[float] => %.1f\r\n",power);
      #endif

      //**** Read Engergy ****
      _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[15];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[16]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[13];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[14]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      energy = (float)_temp_hex_32bit;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: energy[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: energy[float] => %.1f\r\n",energy);
      #endif

      //**** Read Frequency ****
      _temp_hex_16bit = _data_check[17];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[18]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      freq = (float)_temp_hex_16bit * 0.1;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: frequency[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: frequency[float] => %.1f\r\n",freq);
      #endif

      //**** Read power factor ****
      _temp_hex_16bit = _data_check[19];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[20]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      pf = (float)_temp_hex_16bit * 0.01;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: Power factor[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: Power factor[float] => %.01f\r\n",pf);
      #endif



       return 1;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    PZEM_016_Volt
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    volt
 ***********************************************************************/
float  esp32_iot_all_v3::PZEM_016_Volt(uint8_t id)
{
    float _volt;
    //#define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }    

    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read volt ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _volt = (float)_temp_hex_16bit * 0.1;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: volt[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: volt[float] => %.1f\r\n",_volt);
      #endif

      return _volt;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_016_Amp
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    amp
 ***********************************************************************/
float  esp32_iot_all_v3::PZEM_016_Amp(uint8_t id)
{
    float _amp;
    //#define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }

    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Current ****
       _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[7];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[8]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _amp = (float)_temp_hex_32bit * 0.001;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: amp[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: amp[float] => %.1f\r\n",_amp);
      #endif
      return _amp;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_016_Power
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    power
 ***********************************************************************/
float  esp32_iot_all_v3::PZEM_016_Power(uint8_t id)
{
   float _power;
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }    



    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Power ****
      _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[11];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[12]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[9];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[10]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _power = (float)_temp_hex_32bit * 0.1;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: power[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: power[float] => %.1f\r\n",_power);
      #endif

      return _power;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_016_Energy
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    energy
 ***********************************************************************/
int16_t esp32_iot_all_v3::PZEM_016_Energy(uint8_t id)
{
 
   uint16_t _energy;
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }    



    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Engergy ****
      _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[15];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[16]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[13];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[14]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _energy = (float)_temp_hex_32bit * 1;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: energy[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: energy[float] => %.1f\r\n",_energy);
      #endif

      return _energy;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}

/***********************************************************************
 * FUNCTION:    PZEM_016_Freq
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    freq
 ***********************************************************************/
float esp32_iot_all_v3::PZEM_016_Freq(uint8_t id)
{
   float _freq;
    //#define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      



      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }    


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Frequency ****
      _temp_hex_16bit = _data_check[17];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[18]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _freq = (float)_temp_hex_16bit * 0.1;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: frequency[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: frequency[float] => %.1f\r\n",_freq);
      #endif

      return _freq;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_016_PF
 * DESCRIPTION: Read value from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    pf
 ***********************************************************************/
float esp32_iot_all_v3::PZEM_016_PF(uint8_t id)
{
   float _pf;

    //#define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x0A;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<25; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<25; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }    


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read power factor ****
      _temp_hex_16bit = _data_check[19];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[20]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _pf = (float)_temp_hex_16bit * 0.01;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: Power factor[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: Power factor[float] => %.01f\r\n",_pf);
      #endif
      return _pf;


    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_016_ResetEnergy
 * DESCRIPTION: Reset Energy value for PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    true, false
 ***********************************************************************/
bool esp32_iot_all_v3::PZEM_016_ResetEnergy(uint8_t id) 
{
  // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;

    uint8_t _data_write[4];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[4];

    _data_write[0] = id;
    _data_write[1] = 0x42;


    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<4; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Byte count => %d\r\n",_byte_cnt);
        #endif
    } 

   
   if(_byte_cnt == 4){

     /*header data*/
      _data_check[0] = _data_read[0]; 
      _data_check[1] = _data_read[1]; 
      _data_check[2] = _data_read[2]; 
      _data_check[3] = _data_read[3];
  
      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
   if(_byte_cnt > 4){

    uint8_t _addcnt = _byte_cnt - 4;
    for(int i=0; i<4; i++)
    {
      _data_check[i] = _data_read[i+_addcnt]; 
    }

  
      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }    
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: PZEM-016 Reset Engergy Success\r\n");
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    } 

}

/***********************************************************************
 * FUNCTION:    PZEM_016_SetAddress
 * DESCRIPTION: Reset Energy value for PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  address id, new_id
 * RETURNED:   new_id
 ***********************************************************************/
int8_t esp32_iot_all_v3::PZEM_016_SetAddress(uint8_t id, uint8_t new_id)
{

    /*check parameter*/
    if(new_id >= 0x7F)
    {
      Serial.printf("Error: Address is out of the range[1-127]\r\n");
      return -1;
    }

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    _data_write[0] = id;
    _data_write[1] = 0x06;
    _data_write[2] = 0x00;
    _data_write[3] = 0x02;
    _data_write[4] = 0x00;
    _data_write[5] = new_id;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion




    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Byte Count = %d\r\n",_byte_cnt);
        #endif
    } 

    
   
   if(_byte_cnt == 8){

      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i];
      }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 8){

      uint8_t _addcnt = _byte_cnt - 8;
      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i+_addcnt]; 
      }



      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: Success to set new Address[%d]\r\n",new_id);
      return new_id;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_016_SearchAddress
 * DESCRIPTION: Search Address from PZEM-016 Modbus RTU power meter module
 * PARAMETERS:  nothing
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::PZEM_016_SearchAddress(void)
{

    uint8_t _id;

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

    /* Find ID from 1 to 127*/
    for(_id=1; _id<=127; _id++)
    {

        /*clear data*/
        _crc = 0xffff;
        _crc_r = 0xffff;
        _byte_cnt = 0;
        for(int i=0; i<sizeof(_data_check); i++)
        {
          _data_read[i]=0x00;
          _data_check[i]=0x00;
        }



        _data_write[0] = _id;
        _data_write[1] = 0x04;
        _data_write[2] = 0x00;
        _data_write[3] = 0x00;
        _data_write[4] = 0x00;
        _data_write[5] = 0x0A;

        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
            _crc = crc16_update(_crc, _data_write[_i]);
        } 

      // Insert CRC16 to data byte
        #ifdef modbusRTU_Debug
        Serial.printf("_crc = 0x%02X\r\n",_crc);
        #endif
        _data_write[sizeof(_data_write)-1] = _crc >> 8;          
        _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    #pragma region 
        /***** Debug monitor ****/
        #ifdef modbusRTU_Debug
        Serial.printf("Data write(%d): [ ",sizeof(_data_write));
        for(byte _i=0; _i<sizeof(_data_write); _i++){
          if( _data_write[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_write[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_write[_i]);
          } 
        }
        Serial.printf("]\r\n");
        #endif
    #pragma endregion


        /**** Write data ****/ 
        rs485.flush(); 
        for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
        
        vTaskDelay(300);


        /**** Read data ****/
        if(rs485.available()){

        for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
        _byte_cnt = 0;

        //correct data
          do{
              _data_read[_byte_cnt++] = rs485.read();
              if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
                  _byte_cnt =0;
              }
          // }while(rs485.available()>0);
          }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
          

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data read(%d): [ ",_byte_cnt);
            for(byte _i=0; _i<_byte_cnt; _i++){
                if( _data_read[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_read[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_read[_i]);
                } 
            }
            Serial.println("]");
            #endif
        } 

        
      
      if(_byte_cnt == 25){

          for(int i=0; i<25; i++)
          {
            _data_check[i] = _data_read[i];
          }

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data check(%d): [ ",sizeof(_data_check));
          for(byte _i=0; _i<sizeof(_data_check); _i++){
              if( _data_check[_i] > 0x0F ){
                Serial.printf("0x%X ",_data_check[_i]);
              }
              else{
                Serial.printf("0x0%X ",_data_check[_i]);
              } 
          }
          Serial.println("]");
          #endif


           /*** crc check for data read ***/ 
        _crc = 0xffff;
        _crc_r = 0xffff;
        
        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
            _crc = crc16_update(_crc, _data_check[_i]);
        } 
        #ifdef modbusRTU_Debug
        Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
        #endif

        // read crc byte from data_check
        _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
        _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
        _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
        #ifdef modbusRTU_Debug 
        Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
        #endif

        //return ON/OFF status
        if(_crc_r == _crc)
        {


          Serial.printf("\r\nInfo: the Address of this PZEM-016 => %d [Success]\r\n",_id);
          return _id;


        }  
        else
        {
          // Serial.printf("Error: crc16\r\n");
        } 


        
        
        }
      
      else if(_byte_cnt > 25)
      {
        
        uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง
        //Collect data
        for(int i=0; i<25; i++)
        {
          _data_check[i] = _data_read[i+_addcnt];
        }
          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data check(%d): [ ",sizeof(_data_check));
          for(byte _i=0; _i<sizeof(_data_check); _i++){
              if( _data_check[_i] > 0x0F ){
                Serial.printf("0x%X ",_data_check[_i]);
              }
              else{
                Serial.printf("0x0%X ",_data_check[_i]);
              } 
          }
          Serial.println("]");
          #endif


           /*** crc check for data read ***/ 
        _crc = 0xffff;
        _crc_r = 0xffff;
        
        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
            _crc = crc16_update(_crc, _data_check[_i]);
        } 
        #ifdef modbusRTU_Debug
        Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
        #endif

        // read crc byte from data_check
        _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
        _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
        _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
        #ifdef modbusRTU_Debug 
        Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
        #endif

        //return ON/OFF status
        if(_crc_r == _crc)
        {


          Serial.printf("\r\nInfo: the Address of this PZEM-016 => %d [Success]\r\n",_id);
          return _id;


        }  
        else
        {
          // Serial.printf("Error: crc16\r\n");
        } 

      }
      else
      {
        Serial.printf(".");

      }

    }

    Serial.printf("\r\nInfo: Finish searching .... Can't find PZEM-016 for this bus [fail]");
    return -1;

}



/***********************************************************************
 * FUNCTION:    PZEM_016_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::PZEM_016_begin(uint8_t rx, uint8_t tx)
{
  if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(9600, SERIAL_8N1, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }
  
}


/***********************************************************************
 * FUNCTION:    PZEM_003
 * DESCRIPTION: Read value from PZEM-003 Modbus RTU DC power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    true, false and reference parameter => volt, amp, power, energy
 ***********************************************************************/
bool esp32_iot_all_v3::PZEM_003(uint8_t id, float &volt, float &amp, float &power, uint16_t &energy)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    // uint8_t _data_read[21];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 21){

    //Collect data
    for(int i=0; i<21; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<21; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read volt ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      volt = (float)_temp_hex_16bit * 0.01;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: volt[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: volt[float] => %.1f\r\n",volt);
      #endif


      //**** Read current ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      amp = (float)_temp_hex_16bit * 0.01;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: amp[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: amp[float] => %.1fA\r\n",amp);
      #endif


      //**** Read Power ****
       _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[9];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[10]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[7];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[8]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      power = (float)_temp_hex_32bit * 0.1;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: power[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: power[float] => %.1f\r\n",power);
      #endif

      //**** Read Engergy ****
      _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[13];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[14]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[11];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[12]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      energy = _temp_hex_32bit;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: energy[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: energy[float] => %d\r\n",energy);
      #endif



       return 1;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    }    
}



/***********************************************************************
 * FUNCTION:    PZEM_003_Volt
 * DESCRIPTION: Read value from PZEM-003 Modbus RTU DC power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    volt
 ***********************************************************************/
float esp32_iot_all_v3::PZEM_003_Volt(uint8_t id)
{
    float _volt;
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 21){

    //Collect data
    for(int i=0; i<21; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<21; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read volt ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _volt = (float)_temp_hex_16bit * 0.01;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: volt[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: volt[float] => %.1f\r\n",_volt);
      #endif

      return _volt;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}


/***********************************************************************
 * FUNCTION:    PZEM_003_Amp
 * DESCRIPTION: Read value from PZEM-003 Modbus RTU DC power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    amp
 ***********************************************************************/
float esp32_iot_all_v3::PZEM_003_Amp(uint8_t id)
{
    float _amp;
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    /**** correct data to buffer variable ****/
    if(_byte_cnt == 21){

    //Collect data
    for(int i=0; i<21; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<21; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

    

    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {


      //**** Read current ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _amp = (float)_temp_hex_16bit * 0.01;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: amp[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: amp[float] => %.1fA\r\n",_amp);
      #endif

      return _amp;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}



/***********************************************************************
 * FUNCTION:    PZEM_003_Power
 * DESCRIPTION: Read value from PZEM-003 Modbus RTU DC power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    power
 ***********************************************************************/
float esp32_iot_all_v3::PZEM_003_Power(uint8_t id)
{
    float _power;
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 21){

    //Collect data
    for(int i=0; i<21; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<21; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

     


      //**** Read Power ****
       _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[9];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[10]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[7];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[8]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _power = (float)_temp_hex_32bit * 0.1;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: power[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: power[float] => %.1f\r\n",_power);
      #endif

      return _power;

     
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}


/***********************************************************************
 * FUNCTION:    PZEM_003_Energy
 * DESCRIPTION: Read value from PZEM-003 Modbus RTU DC power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    energy
 ***********************************************************************/
int16_t esp32_iot_all_v3::PZEM_003_Energy(uint8_t id)
{
    uint16_t _energy;
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;
    uint32_t _temp_hex_32bit = 0x00000000;

    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

    /**** correct data to buffer variable ****/
    if(_byte_cnt == 21){

    //Collect data
    for(int i=0; i<21; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<21; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

    
      //**** Read Engergy ****
      _temp_hex_32bit = 0x00000000; //clear buffer

      _temp_hex_16bit = _data_check[13];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[14]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _temp_hex_32bit = _temp_hex_32bit<<16; //Serial.printf("Debug: _temp_hex_32bit = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);

      _temp_hex_16bit = _data_check[11];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8; //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[12]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);

      _temp_hex_32bit = _temp_hex_32bit | _temp_hex_16bit; //Serial.printf("Debug: _temp_hex_32bit* = 0x%X(%d)\r\n",_temp_hex_32bit,_temp_hex_32bit);
      _energy = _temp_hex_32bit;
      
      #ifdef modbusRTU_Debug
      Serial.printf("Debug: energy[hex] => %.d\r\n",_temp_hex_32bit);
      Serial.printf("Debug: _energy[float] => %d\r\n",_energy);
      #endif

      return _energy;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}




/***********************************************************************
 * FUNCTION:    PZEM_003_ResetEnergy
 * DESCRIPTION: Reset Energy value for PZEM-003 Modbus RTU power meter module
 * PARAMETERS:  address(id)
 * RETURNED:    true, false
 ***********************************************************************/
bool esp32_iot_all_v3::PZEM_003_ResetEnergy(uint8_t id) 
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;

    uint8_t _data_write[4];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[4];

    _data_write[0] = id;
    _data_write[1] = 0x42;


    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion



    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<4; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Byte Count => %d\r\n",_byte_cnt);
        #endif
    } 

   
  if(_byte_cnt == 4){

    /*header data*/
    _data_check[0] = _data_read[0]; 
    _data_check[1] = _data_read[1]; 
    _data_check[2] = _data_read[2]; 
    _data_check[3] = _data_read[3];

    for(int i=0; i<_byte_cnt; i++)
    {
      _data_check[i] = _data_read[i]; 
    }

    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data check(%d): [ ",sizeof(_data_check));
    for(byte _i=0; _i<sizeof(_data_check); _i++){
        if( _data_check[_i] > 0x0F ){
          Serial.printf("0x%X ",_data_check[_i]);
        }
        else{
          Serial.printf("0x0%X ",_data_check[_i]);
        } 
    }
    Serial.println("]");
    #endif

  }
  else if( _byte_cnt > 4)
  {
    uint8_t _addcnt = _byte_cnt - 4;
    for(int i=0; i<4; i++)
    {
      _data_check[i] = _data_read[i+_addcnt]; 
    }

    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data check(%d): [ ",sizeof(_data_check));
    for(byte _i=0; _i<sizeof(_data_check); _i++){
        if( _data_check[_i] > 0x0F ){
          Serial.printf("0x%X ",_data_check[_i]);
        }
        else{
          Serial.printf("0x0%X ",_data_check[_i]);
        } 
    }
    Serial.println("]");
    #endif

  } 
  else
  {
    Serial.printf("Error: data error\r\n");
    return 0;
  }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      
      Serial.printf("Info: PZEM-003 Reset Engergy Success\r\n");
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    } 

}

/***********************************************************************
 * FUNCTION:    PZEM_003_SetAddress
 * DESCRIPTION: Reset Energy value for PZEM-003 Modbus RTU power meter module
 * PARAMETERS:  address id, new_id
 * RETURNED:   new_id
 ***********************************************************************/
int8_t esp32_iot_all_v3::PZEM_003_SetAddress(uint8_t id, uint8_t new_id)
{

    /*check parameter*/
    if(new_id >= 0x7F)
    {
      Serial.printf("Error: Address is out of the range[1-127]\r\n");
      return -1;
    }

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    _data_write[0] = id;
    _data_write[1] = 0x06;
    _data_write[2] = 0x00;
    _data_write[3] = 0x02;
    _data_write[4] = 0x00;
    _data_write[5] = new_id;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion




    /**** Write data ****/ 
    rs485_2.flush(); 
    for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485_2.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485_2.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485_2.available()>0);
      }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Byte count = %d\r\n",_byte_cnt);
        #endif
    } 

    
   
  if(_byte_cnt == 8){

 
      _data_check[0] = _data_read[0];
      _data_check[1] = _data_read[1];
      _data_check[2] = _data_read[2]; 

      _data_check[3] = _data_read[3];
      _data_check[4] = _data_read[4];

      _data_check[5] = _data_read[5];
      _data_check[6] = _data_read[6]; 
      _data_check[7] = _data_read[7];
     

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    } 
  else if( _byte_cnt > 8)
  {
    uint8_t _addcnt = _byte_cnt - 8;
    for(int i=0; i<8; i++)
    {
      _data_check[i] = _data_read[i+_addcnt]; 
    }

    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data check(%d): [ ",sizeof(_data_check));
    for(byte _i=0; _i<sizeof(_data_check); _i++){
        if( _data_check[_i] > 0x0F ){
          Serial.printf("0x%X ",_data_check[_i]);
        }
        else{
          Serial.printf("0x0%X ",_data_check[_i]);
        } 
    }
    Serial.println("]");
    #endif
    
  }   
  else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: Success to set new Address[%d]\r\n",new_id);
      return new_id;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}


/***********************************************************************
 * FUNCTION:    PZEM_003_SearchAddress
 * DESCRIPTION: Search Address from PZEM-003 Modbus RTU power meter module
 * PARAMETERS:  nothing
 * RETURNED:    Address
 ***********************************************************************/

int8_t esp32_iot_all_v3::PZEM_003_SearchAddress(void)
{

    uint8_t _id;

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

    /* Find ID from 1 to 127*/
    for(_id=1; _id<=127; _id++)
    {

        /*clear data*/
        _crc = 0xffff;
        _crc_r = 0xffff;
        _byte_cnt = 0;
        for(int i=0; i<sizeof(_data_check); i++)
        {
          _data_read[i]=0x00;
          _data_check[i]=0x00;
        }


      _data_write[0] = _id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
            _crc = crc16_update(_crc, _data_write[_i]);
        } 

      // Insert CRC16 to data byte
        #ifdef modbusRTU_Debug
        Serial.printf("_crc = 0x%02X\r\n",_crc);
        #endif
        _data_write[sizeof(_data_write)-1] = _crc >> 8;          
        _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    #pragma region 
        /***** Debug monitor ****/
        #ifdef modbusRTU_Debug
        Serial.printf("Data write(%d): [ ",sizeof(_data_write));
        for(byte _i=0; _i<sizeof(_data_write); _i++){
          if( _data_write[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_write[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_write[_i]);
          } 
        }
        Serial.printf("]\r\n");
        #endif
    #pragma endregion


        /**** Write data ****/ 
        rs485_2.flush(); 
        for(int _i=0; _i<8; _i++) rs485_2.write(_data_write[_i]);
        
        vTaskDelay(300);


        /**** Read data ****/
        if(rs485_2.available()){

        for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
        _byte_cnt = 0;

        //correct data
          do{
              _data_read[_byte_cnt++] = rs485_2.read();
              if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
                  _byte_cnt =0;
              }
          // }while(rs485_2.available()>0);
          }while(rs485_2.available()>0 && _byte_cnt<sizeof(_data_read));
          

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data read(%d): [ ",_byte_cnt);
            for(byte _i=0; _i<_byte_cnt; _i++){
                if( _data_read[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_read[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_read[_i]);
                } 
            }
            Serial.println("]");
            #endif
        } 

      /* Collect data to variable buffer */
      if(_byte_cnt == 21){

        for(int i=0; i<21; i++)
        {
          _data_check[i] = _data_read[i];
        }
     

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this PZEM-003 => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }
      } 

      else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<21; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this PZEM-003 => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }     


      }
      else
      {
        Serial.printf(".");

      }

    }

    Serial.printf("\r\nInfo: Finish searching .... Can't find PZEM-003 for this bus [fail]");

}


/***********************************************************************
 * FUNCTION:    PZEM_003_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::PZEM_003_begin(uint8_t rx, uint8_t tx)
{
  if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485_2.begin(9600, SERIAL_8N2, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }
  
}



/***********************************************************************
 * FUNCTION:    WTR10_E_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::WTR10_E_begin(uint8_t rx, uint8_t tx)
{
  if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(9600, SERIAL_8N1, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }
  
}


/***********************************************************************
 * FUNCTION:    WTR10_E
 * DESCRIPTION: Read value from WTR10-E
 * PARAMETERS:  address(id)
 * RETURNED:    true, false and reference parameter => temp, humidity
 ***********************************************************************/
bool esp32_iot_all_v3::WTR10_E(uint8_t id, float &temp, float &humi)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

      _data_write[0] = id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      temp = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temp[float] => %.1f\r\n",temp);
      #endif

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      humi = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",humi);
      #endif

      return 1;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    }    
}



/***********************************************************************
 * FUNCTION:    WTR10_E_tempeature
 * DESCRIPTION: Read tempeature from WTR10-E
 * PARAMETERS:  address(id)
 * RETURNED:    _temperture
 ***********************************************************************/
float esp32_iot_all_v3::WTR10_E_tempeature(uint8_t id)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

    _data_write[0] = id;
    _data_write[1] = 0x03;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x02;

    float _temperature;
  

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      _temperature = (float)_temp_hex_16bit/10;
      

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temperature[float] => %.1f\r\n",_temperature);
      #endif

      return _temperature; //return value here

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}



/***********************************************************************
 * FUNCTION:    WTR10_E_humidity
 * DESCRIPTION: Read humidity from WTR10-E
 * PARAMETERS:  address(id)
 * RETURNED:    _humidity
 ***********************************************************************/
float esp32_iot_all_v3::WTR10_E_humidity(uint8_t id)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

    _data_write[0] = id;
    _data_write[1] = 0x03;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = 0x02;

    float _humdity;
  

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _humdity = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",_humdity);
      #endif

      return _humdity; //return value here

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}




/***********************************************************************
 * FUNCTION:    XY_MD02_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::XY_MD02_begin(uint8_t rx, uint8_t tx)
{
  if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(9600, SERIAL_8N2, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }
  
}


/***********************************************************************
 * FUNCTION:    XY_MD02
 * DESCRIPTION: Read value from XY-MD02
 * PARAMETERS:  address(id)
 * RETURNED:    true, false and reference parameter => temp, humidity
 ***********************************************************************/
bool esp32_iot_all_v3::XY_MD02(uint8_t id, float &temp, float &humi)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x01;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      temp = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temp[float] => %.1f\r\n",temp);
      #endif

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      humi = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",humi);
      #endif

      return 1;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    }    
}



/***********************************************************************
 * FUNCTION:    XY_MD02_tempeature
 * DESCRIPTION: Read tempeature from XY-MD02
 * PARAMETERS:  address(id)
 * RETURNED:    _temperture
 ***********************************************************************/
float esp32_iot_all_v3::XY_MD02_tempeature(uint8_t id)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x01;
    _data_write[4] = 0x00;
    _data_write[5] = 0x02;

    float _temperature;
  

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      _temperature = (float)_temp_hex_16bit/10;
      

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temperature[float] => %.1f\r\n",_temperature);
      #endif

      return _temperature; //return value here

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}



/***********************************************************************
 * FUNCTION:    XY_MD02_humidity
 * DESCRIPTION: Read humidity from XY-MD02
 * PARAMETERS:  address(id)
 * RETURNED:    _humidity
 ***********************************************************************/
float esp32_iot_all_v3::XY_MD02_humidity(uint8_t id)
{
    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

    _data_write[0] = id;
    _data_write[1] = 0x04;
    _data_write[2] = 0x00;
    _data_write[3] = 0x01;
    _data_write[4] = 0x00;
    _data_write[5] = 0x02;

    float _humdity;
  

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _humdity = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",_humdity);
      #endif

      return _humdity; //return value here

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}

/***********************************************************************
 * FUNCTION:    XY_MD02_searchAddress
 * DESCRIPTION: Search Address from XY-MD02 Module [1-247]
 * PARAMETERS:  nothing
 * RETURNED:    Address
 ***********************************************************************/

int8_t esp32_iot_all_v3::XY_MD02_searchAddress(void)
{

    uint8_t _id;

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    /* Find ID from 1 to 247*/
    for(_id=1; _id<=247; _id++)
    {

        /*clear data*/
        _crc = 0xffff;
        _crc_r = 0xffff;
        _byte_cnt = 0;
        for(int i=0; i<sizeof(_data_check); i++)
        {
          _data_read[i]=0x00;
          _data_check[i]=0x00;
        }


      _data_write[0] = _id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x01;
      _data_write[3] = 0x01;
      _data_write[4] = 0x00;
      _data_write[5] = 0x01;

        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
            _crc = crc16_update(_crc, _data_write[_i]);
        } 

      // Insert CRC16 to data byte
        #ifdef modbusRTU_Debug
        Serial.printf("_crc = 0x%02X\r\n",_crc);
        #endif
        _data_write[sizeof(_data_write)-1] = _crc >> 8;          
        _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    #pragma region 
        /***** Debug monitor ****/
        #ifdef modbusRTU_Debug
        Serial.printf("Data write(%d): [ ",sizeof(_data_write));
        for(byte _i=0; _i<sizeof(_data_write); _i++){
          if( _data_write[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_write[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_write[_i]);
          } 
        }
        Serial.printf("]\r\n");
        #endif
    #pragma endregion


        /**** Write data ****/ 
        rs485.flush(); 
        for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
        
        vTaskDelay(300);


        /**** Read data ****/
        if(rs485.available()){

        for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
        _byte_cnt = 0;

        //correct data
          do{
              _data_read[_byte_cnt++] = rs485.read();
              if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
                  _byte_cnt =0;
              }
          // }while(rs485.available()>0);
          }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
          

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data read(%d): [ ",_byte_cnt);
            for(byte _i=0; _i<_byte_cnt; _i++){
                if( _data_read[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_read[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_read[_i]);
                } 
            }
            Serial.println("]");
            #endif
        } 

      

      /* Collect data to variable buffer */
      if(_byte_cnt == 7){

        for(int i=0; i<7; i++)
        {
          _data_check[i] = _data_read[i];
        }
     

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this XY-MD02 => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }
      } 

      else if(_byte_cnt > 7){

      uint8_t _addcnt = _byte_cnt - 7; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<7; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this XY-MD02 => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }     


      }
      else
      {
        Serial.printf(".");

      }

    }

    Serial.printf("\r\nInfo: Finish searching .... Can't find XY-MD02 for this bus [fail]");

}


/***********************************************************************
 * FUNCTION:    XY_MD02_SetAddress
 * DESCRIPTION: Setting new address to XY-MD02 Module
 * PARAMETERS:  address id, new_id
 * RETURNED:   new_id
 ***********************************************************************/
int8_t esp32_iot_all_v3::XY_MD02_SetAddress(uint8_t id, uint8_t new_id)
{

    /*check parameter*/
    if((new_id < 1) || (new_id >= 247)) 
    {
      Serial.printf("Error: Address is out of the range[1-247]\r\n");
      return -1;
    }

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    _data_write[0] = id;
    _data_write[1] = 0x06;
    _data_write[2] = 0x01;
    _data_write[3] = 0x01;
    _data_write[4] = 0x00;
    _data_write[5] = new_id;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion




    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Byte Count = %d\r\n",_byte_cnt);
        #endif
    } 

    
   
   if(_byte_cnt == 8){

      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i];
      }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 8){

      uint8_t _addcnt = _byte_cnt - 8;
      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i+_addcnt]; 
      }



      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: Success to set new Address[%d]\r\n",new_id);
      return new_id;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}



/***********************************************************************
 * FUNCTION:    PR3000_H_N01_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::PR3000_H_N01_begin(uint8_t rx, uint8_t tx)
{
  if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(4800, SERIAL_8N1, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }
  
}

/***********************************************************************
 * FUNCTION:    PR3000_H_N01
 * DESCRIPTION: Read Temperature and Humidity soil
 * PARAMETERS:  nothing
 * RETURNED:    true, false and reference parameter => temp, humidity
 ***********************************************************************/
bool esp32_iot_all_v3::PR3000_H_N01(float &temp, float &humi)
{

    uint8_t id = 1; //fix id

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

      _data_write[0] = id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      humi = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temp[float] => %.1f\r\n",temp);
      #endif

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      temp = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",humi);
      #endif

      return 1;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return 0;
    }    
}

/***********************************************************************
 * FUNCTION:    PR3000_H_N01_tempeature
 * DESCRIPTION: Read Humidity soil
 * PARAMETERS:  nothing
 * RETURNED:    Humidity
 ***********************************************************************/
float esp32_iot_all_v3::PR3000_H_N01_tempeature()
{
    uint8_t id = 1;
    float _temp,_humi;
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

      _data_write[0] = id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      _humi = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temp[float] => %.1f\r\n",temp);
      #endif

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _temp = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",humi);
      #endif

      return _temp;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}

/***********************************************************************
 * FUNCTION:    PR3000_H_N01_humidity
 * DESCRIPTION: Read Humidity soil
 * PARAMETERS:  nothing
 * RETURNED:    humidity
 ***********************************************************************/
float esp32_iot_all_v3::PR3000_H_N01_humidity()
{
    uint8_t id = 1;
    float _temp,_humi;
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

      _data_write[0] = id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<9; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      _humi = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: temp[float] => %.1f\r\n",temp);
      #endif

      //**** Read temperature ****
      _temp_hex_16bit = _data_check[5];  //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex_16bit = 0x%X\r\n",_temp_hex_16bit);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[6]; //Serial.printf("Debug: _temp_hex_16bit = 0x%X(%d)\r\n",_temp_hex_16bit,_temp_hex_16bit);
      _temp = (float)_temp_hex_16bit/10;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: humi[hex] => %.d\r\n",_temp_hex_16bit);
      Serial.printf("Debug: humi[float] => %.1f\r\n",humi);
      #endif

      return _humi;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}


/***********************************************************************
 * FUNCTION:    WATER_FLOW_METER_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::WATER_FLOW_METER_begin(uint8_t rx, uint8_t tx)
{

 if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(9600, SERIAL_8N1, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }

}



/***********************************************************************
 * FUNCTION:    WATER_FLOW_METER_searchAddress
 * DESCRIPTION: Search Address from WATER_FLOW_METER Module [1-252]
 * PARAMETERS:  nothing
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::WATER_FLOW_METER_searchAddress(void)
{
 uint8_t _id;

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    /* Find ID from 1 to 252*/
    for(_id=1; _id<=252; _id++)
    {

        /*clear data*/
        _crc = 0xffff;
        _crc_r = 0xffff;
        _byte_cnt = 0;
        for(int i=0; i<sizeof(_data_check); i++)
        {
          _data_read[i]=0x00;
          _data_check[i]=0x00;
        }


      _data_write[0] = _id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x01;

        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
            _crc = crc16_update(_crc, _data_write[_i]);
        } 

      // Insert CRC16 to data byte
        #ifdef modbusRTU_Debug
        Serial.printf("_crc = 0x%02X\r\n",_crc);
        #endif
        _data_write[sizeof(_data_write)-1] = _crc >> 8;          
        _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    #pragma region 
        /***** Debug monitor ****/
        #ifdef modbusRTU_Debug
        Serial.printf("Data write(%d): [ ",sizeof(_data_write));
        for(byte _i=0; _i<sizeof(_data_write); _i++){
          if( _data_write[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_write[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_write[_i]);
          } 
        }
        Serial.printf("]\r\n");
        #endif
    #pragma endregion


        /**** Write data ****/ 
        rs485.flush(); 
        for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
        
        vTaskDelay(300);


        /**** Read data ****/
        if(rs485.available()){

        for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
        _byte_cnt = 0;

        //correct data
          do{
              _data_read[_byte_cnt++] = rs485.read();
              if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
                  _byte_cnt =0;
              }
          // }while(rs485.available()>0);
          }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
          

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data read(%d): [ ",_byte_cnt);
            for(byte _i=0; _i<_byte_cnt; _i++){
                if( _data_read[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_read[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_read[_i]);
                } 
            }
            Serial.println("]");
            #endif
        } 

      

      /* Collect data to variable buffer */
      if(_byte_cnt == 7){

        for(int i=0; i<7; i++)
        {
          _data_check[i] = _data_read[i];
        }
     

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this WATER-FLOW-METER => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }
      } 

      else if(_byte_cnt > 7){

      uint8_t _addcnt = _byte_cnt - 7; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<7; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this WATER-FLOW-METER => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }     


      }
      else
      {
        Serial.printf(".");

      }

    }

    Serial.printf("\r\nInfo: Finish searching .... Can't find WATER-FLOW-METER for this bus [fail]");

}

/***********************************************************************
 * FUNCTION:    WATER_FLOW_METER_setAddress
 * DESCRIPTION: Set Address for WATER_FLOW_METER Module [1-252]
 * PARAMETERS:  id, new_id
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::WATER_FLOW_METER_SetAddress(uint8_t id, uint8_t new_id)
{
    
    /*check parameter*/
    if((new_id < 1) || (new_id >= 252)) 
    {
      Serial.printf("Error: Address is out of the range[1-252]\r\n");
      return -1;
    }

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    _data_write[0] = id;
    _data_write[1] = 0x06;
    _data_write[2] = 0x00;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = new_id;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion




    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Byte Count = %d\r\n",_byte_cnt);
        #endif
    } 

    
   
   if(_byte_cnt == 8){

      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i];
      }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 8){

      uint8_t _addcnt = _byte_cnt - 8;
      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i+_addcnt]; 
      }



      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: Success to set new Address[%d]\r\n",new_id);
      return new_id;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}

/***********************************************************************
 * FUNCTION:    WATER_FLOW_METER_flowrate
 * DESCRIPTION: Set Address for WATER_FLOW_METER Module [1-252]
 * PARAMETERS:  id
 * RETURNED:    Flow water(m^3) cubic meters
 ***********************************************************************/
float esp32_iot_all_v3::WATER_FLOW_METER_flowrate(uint8_t id)
{
    // #define modbusRTU_Debug
    float _flowrate;
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[11];

      _data_write[0] = id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x03;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 11){

    //Collect data
    for(int i=0; i<11; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 11){

      uint8_t _addcnt = _byte_cnt - 11; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      //**** Read Humidity ****
      _temp_hex_16bit = _data_check[7];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[8]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      _flowrate = (float)_temp_hex_16bit/100;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp => %d\r\n",_temp_hex_16bit);
      #endif

      return _flowrate;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}

/***********************************************************************
 * FUNCTION:    PYR20_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::PYR20_begin(uint8_t rx, uint8_t tx)
{

 if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(9600, SERIAL_8N1, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }

}



/***********************************************************************
 * FUNCTION:    PYR20_searchAddress
 * DESCRIPTION: Search Address from PYR20 Module [1-255]
 * PARAMETERS:  nothing
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::PYR20_searchAddress(void)
{
 uint8_t _id;

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    /* Find ID from 1 to 252*/
    for(_id=1; _id<=255; _id++)
    {

        /*clear data*/
        _crc = 0xffff;
        _crc_r = 0xffff;
        _byte_cnt = 0;
        for(int i=0; i<sizeof(_data_check); i++)
        {
          _data_read[i]=0x00;
          _data_check[i]=0x00;
        }


      _data_write[0] = _id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x02;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x01;

        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
            _crc = crc16_update(_crc, _data_write[_i]);
        } 

      // Insert CRC16 to data byte
        #ifdef modbusRTU_Debug
        Serial.printf("_crc = 0x%02X\r\n",_crc);
        #endif
        _data_write[sizeof(_data_write)-1] = _crc >> 8;          
        _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    #pragma region 
        /***** Debug monitor ****/
        #ifdef modbusRTU_Debug
        Serial.printf("Data write(%d): [ ",sizeof(_data_write));
        for(byte _i=0; _i<sizeof(_data_write); _i++){
          if( _data_write[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_write[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_write[_i]);
          } 
        }
        Serial.printf("]\r\n");
        #endif
    #pragma endregion


        /**** Write data ****/ 
        rs485.flush(); 
        for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
        
        vTaskDelay(300);


        /**** Read data ****/
        if(rs485.available()){

        for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
        _byte_cnt = 0;

        //correct data
          do{
              _data_read[_byte_cnt++] = rs485.read();
              if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
                  _byte_cnt =0;
              }
          // }while(rs485.available()>0);
          }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
          

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data read(%d): [ ",_byte_cnt);
            for(byte _i=0; _i<_byte_cnt; _i++){
                if( _data_read[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_read[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_read[_i]);
                } 
            }
            Serial.println("]");
            #endif
        } 

      

      /* Collect data to variable buffer */
      if(_byte_cnt == 7){

        for(int i=0; i<7; i++)
        {
          _data_check[i] = _data_read[i];
        }
     

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this WATER-FLOW-METER => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }
      } 

      else if(_byte_cnt > 7){

      uint8_t _addcnt = _byte_cnt - 7; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<7; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this WATER-FLOW-METER => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }     


      }
      else
      {
        Serial.printf(".");

      }

    }

    Serial.printf("\r\nInfo: Finish searching .... Can't find WATER-FLOW-METER for this bus [fail]");

}

/***********************************************************************
 * FUNCTION:    PYR20_setAddress
 * DESCRIPTION: Set Address for PYR20 Module [1-252]
 * PARAMETERS:  id, new_id
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::PYR20_SetAddress(uint8_t id, uint8_t new_id)
{
    
    /*check parameter*/
    if((new_id < 1) || (new_id >= 252)) 
    {
      Serial.printf("Error: Address is out of the range[1-252]\r\n");
      return -1;
    }

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    _data_write[0] = id;
    _data_write[1] = 0x06;
    _data_write[2] = 0x02;
    _data_write[3] = 0x00;
    _data_write[4] = 0x00;
    _data_write[5] = new_id;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion




    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Byte Count = %d\r\n",_byte_cnt);
        #endif
    } 

    
   
   if(_byte_cnt == 8){

      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i];
      }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 8){

      uint8_t _addcnt = _byte_cnt - 8;
      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i+_addcnt]; 
      }



      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: Success to set new Address[%d]\r\n",new_id);
      return new_id;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}

/***********************************************************************
 * FUNCTION:    PYR20_read
 * DESCRIPTION: read value from PYR20
 * PARAMETERS:  id
 * RETURNED:    W/m^2
 ***********************************************************************/
int16_t esp32_iot_all_v3::PYR20_read(uint8_t id)
{
    // #define modbusRTU_Debug
    uint16_t _pyranormeter;
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex_16bit = 0xffff;


    uint8_t _data_write[8];
    uint8_t _data_read[10];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[7];

      _data_write[0] = id;
      _data_write[1] = 0x03;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x01;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 


  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif



    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Debug: Count byte => %d\r\n",_byte_cnt);
        #endif
    } 

    
    /**** correct data to buffer variable ****/
    if(_byte_cnt == 7){

    //Collect data
    for(int i=0; i<7; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 7){

      uint8_t _addcnt = _byte_cnt - 7; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<7; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      _temp_hex_16bit = _data_check[3];  //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit<<8;   //Serial.printf("Debug: _temp_hex = 0x%X\r\n",_temp_hex);
      _temp_hex_16bit = _temp_hex_16bit | _data_check[4]; //Serial.printf("Debug: _temp_hex = 0x%X(%d)\r\n",_temp_hex,_temp_hex);
      _pyranormeter = _temp_hex_16bit;

      #ifdef modbusRTU_Debug
      Serial.printf("Debug: temp => %d\r\n",_temp_hex_16bit);
      #endif

      return _pyranormeter;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    }    
}



/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU_begin
 * DESCRIPTION: set RX and TX pin
 * PARAMETERS:  rx, tx
 * RETURNED:    true/ false
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU_begin(uint8_t rx, uint8_t tx)
{
  if( ((tx== TXD2) || (tx== TXD3)) && ((rx== RXD2) || (rx== RXD3)) )
  {
    rs485.begin(9600, SERIAL_8N1, rx, tx);
    return 1;
  }
  else
  {
    Serial.printf("Error: Fail to define RS485 port!!\r\n");
    return 0;
  }
  
}

/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-10]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7, float &val8, float &val9, float &val10)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[45];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x14;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 45){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 45){

      uint8_t _addcnt = _byte_cnt - 45; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val5 process */
      _sResult = _data_check[21];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[22];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[19];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[20];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val5 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val6 process */
      _sResult = _data_check[25];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[26];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[23];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[24];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val6 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val7 process */
      _sResult = _data_check[29];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[30];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[27];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[28];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val7 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val8 process */
      _sResult = _data_check[33];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[34];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[31];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[32];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val8 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val9 process */
      _sResult = _data_check[37];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[38];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[35];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[36];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val9 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val10 process */
      _sResult = _data_check[41];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[42];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[39];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[40];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val10 = (*(float*)&_sResult); //**Floating point 16bit convert  

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);
          Serial.printf("Debug: val5 => %.2f\r\n",val5);
          Serial.printf("Debug: val6 => %.2f\r\n",val6);
          Serial.printf("Debug: val7 => %.2f\r\n",val7);
          Serial.printf("Debug: val8 => %.2f\r\n",val8);
          Serial.printf("Debug: val9 => %.2f\r\n",val9);
          Serial.printf("Debug: val10 => %.2f\r\n",val10);
      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}

/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-9]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7, float &val8, float &val9)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[41];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x12;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 41){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 41){

      uint8_t _addcnt = _byte_cnt - 41; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val5 process */
      _sResult = _data_check[21];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[22];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[19];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[20];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val5 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val6 process */
      _sResult = _data_check[25];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[26];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[23];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[24];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val6 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val7 process */
      _sResult = _data_check[29];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[30];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[27];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[28];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val7 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val8 process */
      _sResult = _data_check[33];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[34];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[31];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[32];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val8 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val9 process */
      _sResult = _data_check[37];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[38];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[35];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[36];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val9 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);
          Serial.printf("Debug: val5 => %.2f\r\n",val5);
          Serial.printf("Debug: val6 => %.2f\r\n",val6);
          Serial.printf("Debug: val7 => %.2f\r\n",val7);
          Serial.printf("Debug: val8 => %.2f\r\n",val8);
          Serial.printf("Debug: val9 => %.2f\r\n",val9);
      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-8]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7, float &val8)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[37];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x10;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 37){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 37){

      uint8_t _addcnt = _byte_cnt - 37; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val5 process */
      _sResult = _data_check[21];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[22];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[19];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[20];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val5 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val6 process */
      _sResult = _data_check[25];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[26];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[23];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[24];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val6 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val7 process */
      _sResult = _data_check[29];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[30];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[27];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[28];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val7 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val8 process */
      _sResult = _data_check[33];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[34];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[31];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[32];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val8 = (*(float*)&_sResult); //**Floating point 16bit convert


      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);
          Serial.printf("Debug: val5 => %.2f\r\n",val5);
          Serial.printf("Debug: val6 => %.2f\r\n",val6);
          Serial.printf("Debug: val7 => %.2f\r\n",val7);
          Serial.printf("Debug: val8 => %.2f\r\n",val8);
      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-7]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6, float &val7)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[33];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x0E;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 33){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 33){

      uint8_t _addcnt = _byte_cnt - 33; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val5 process */
      _sResult = _data_check[21];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[22];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[19];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[20];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val5 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val6 process */
      _sResult = _data_check[25];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[26];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[23];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[24];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val6 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val7 process */
      _sResult = _data_check[29];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[30];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[27];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[28];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val7 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);
          Serial.printf("Debug: val5 => %.2f\r\n",val5);
          Serial.printf("Debug: val6 => %.2f\r\n",val6);
          Serial.printf("Debug: val7 => %.2f\r\n",val7);
      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-6]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5, float &val6)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[29];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x0C;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 29){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 29){

      uint8_t _addcnt = _byte_cnt - 29; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val5 process */
      _sResult = _data_check[21];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[22];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[19];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[20];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val5 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val6 process */
      _sResult = _data_check[25];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[26];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[23];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[24];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val6 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);
          Serial.printf("Debug: val5 => %.2f\r\n",val5);
          Serial.printf("Debug: val6 => %.2f\r\n",val6);

      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-5]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4, float &val5)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[25];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x0A;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 25){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 25){

      uint8_t _addcnt = _byte_cnt - 25; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val5 process */
      _sResult = _data_check[21];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[22];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[19];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[20];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val5 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);
          Serial.printf("Debug: val5 => %.2f\r\n",val5);

      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}



/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-4]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3, float &val4)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[21];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x08;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 21){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 21){

      uint8_t _addcnt = _byte_cnt - 21; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val4 process */
      _sResult = _data_check[17];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[18];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[15];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[16];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val4 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
          Serial.printf("Debug: val4 => %.2f\r\n",val4);

      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}



/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-3]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2, float &val3)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[17];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x06;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 17){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 17){

      uint8_t _addcnt = _byte_cnt - 17; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val3 process */
      _sResult = _data_check[13];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[14];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[11];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[12];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val3 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
          Serial.printf("Debug: val3 => %.2f\r\n",val3);
        

      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1-2]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1, float &val2)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[13];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x04;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 13){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 13){

      uint8_t _addcnt = _byte_cnt - 13; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert

      /* val2 process */
      _sResult = _data_check[9];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[10];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[7];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[8];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val2 = (*(float*)&_sResult); //**Floating point 16bit convert

      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
          Serial.printf("Debug: val2 => %.2f\r\n",val2);
        
      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU
 * DESCRIPTION: tiny32 sensor read
 * PARAMETERS:  address
 * RETURNED:    referance variable [1]
 ***********************************************************************/
bool esp32_iot_all_v3::tiny32_ModbusRTU(uint8_t id, float &val1)
{
  // #define modbusRTU_Debug
    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint16_t _temp_hex = 0xffff;
    unsigned long _sResult;
    // float _floatResult;

    uint8_t _data_write[8];
    uint8_t _data_read[50];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

      _data_write[0] = id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x00;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

          // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion


    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<sizeof(_data_write); _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        #endif
    } 

        /**** correct data to buffer variable ****/
    if(_byte_cnt == 9){

    //Collect data
    for(int i=0; i<=44; i++)
    {
      _data_check[i] = _data_read[i];
    }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return 0;
    }

   
    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    // Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      /* val1 process */
      _sResult = _data_check[5];                   //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[6];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[3];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult << 8;                 //Serial.print(">>"); Serial.println(_sResult,HEX);  
      _sResult = _sResult + _data_check[4];        //Serial.print(">>"); Serial.println(_sResult,HEX);  
      val1 = (*(float*)&_sResult); //**Floating point 16bit convert



      #ifdef modbusRTU_Debug
          Serial.printf("Debug: val1 => %.2f\r\n",val1);
      #endif
      return 1;

    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
      return 0;
    }    
}



/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU_searchAddress
 * DESCRIPTION: Search Address from PYR20 Module [1-253]
 * PARAMETERS:  nothing
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::tiny32_ModbusRTU_searchAddress(void)
{
 uint8_t _id;

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[20];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[9];

    /* Find ID from 1 to 253*/
    for(_id=1; _id<=253; _id++)
    {

        /*clear data*/
        _crc = 0xffff;
        _crc_r = 0xffff;
        _byte_cnt = 0;
        for(int i=0; i<sizeof(_data_check); i++)
        {
          _data_read[i]=0x00;
          _data_check[i]=0x00;
        }


      _data_write[0] = _id;
      _data_write[1] = 0x04;
      _data_write[2] = 0x00;
      _data_write[3] = 0x20;
      _data_write[4] = 0x00;
      _data_write[5] = 0x02;

        // Generate CRC16
        for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
            _crc = crc16_update(_crc, _data_write[_i]);
        } 

      // Insert CRC16 to data byte
        #ifdef modbusRTU_Debug
        Serial.printf("_crc = 0x%02X\r\n",_crc);
        #endif
        _data_write[sizeof(_data_write)-1] = _crc >> 8;          
        _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  



    #pragma region 
        /***** Debug monitor ****/
        #ifdef modbusRTU_Debug
        Serial.printf("Data write(%d): [ ",sizeof(_data_write));
        for(byte _i=0; _i<sizeof(_data_write); _i++){
          if( _data_write[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_write[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_write[_i]);
          } 
        }
        Serial.printf("]\r\n");
        #endif
    #pragma endregion


        /**** Write data ****/ 
        rs485.flush(); 
        for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
        
        vTaskDelay(300);


        /**** Read data ****/
        if(rs485.available()){

        for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
        _byte_cnt = 0;

        //correct data
          do{
              _data_read[_byte_cnt++] = rs485.read();
              if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
                  _byte_cnt =0;
              }
          // }while(rs485.available()>0);
          }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
          

          /***** Debug monitor ****/
          #ifdef modbusRTU_Debug
          Serial.printf("Data read(%d): [ ",_byte_cnt);
            for(byte _i=0; _i<_byte_cnt; _i++){
                if( _data_read[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_read[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_read[_i]);
                } 
            }
            Serial.println("]");
            #endif
        } 

      

      /* Collect data to variable buffer */
      if(_byte_cnt == 9){

        for(int i=0; i<9; i++)
        {
          _data_check[i] = _data_read[i];
        }
     

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this tiny32_MobusRTU_client => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }
      } 

      else if(_byte_cnt > 9){

      uint8_t _addcnt = _byte_cnt - 9; //ตัวแปรชดเชยการอ่านค่าผิดตำแหน่ง

      //Collect data
      for(int i=0; i<9; i++)
      {
        _data_check[i] = _data_read[i+_addcnt];
      }

            /***** Debug monitor ****/
            #ifdef modbusRTU_Debug
            Serial.printf("Data check(%d): [ ",sizeof(_data_check));
            for(byte _i=0; _i<sizeof(_data_check); _i++){
                if( _data_check[_i] > 0x0F ){
                  Serial.printf("0x%X ",_data_check[_i]);
                }
                else{
                  Serial.printf("0x0%X ",_data_check[_i]);
                } 
            }
            Serial.println("]");
            #endif


            /*** crc check for data read ***/ 
          _crc = 0xffff;
          _crc_r = 0xffff;
          
          // Generate CRC16
          for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
              _crc = crc16_update(_crc, _data_check[_i]);
          } 
          #ifdef modbusRTU_Debug
          Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
          #endif

          // read crc byte from data_check
          _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
          _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
          #ifdef modbusRTU_Debug 
          Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
          #endif

          //return ON/OFF status
          if(_crc_r == _crc)
          {


            Serial.printf("\r\nInfo: the Address of this tiny32_MobusRTU_client => %d [Success]\r\n",_id);
            return _id;


          }  
          else
          {
            // Serial.printf("Error: crc16\r\n");
            return -1;
          }     


      }
      else
      {
        Serial.printf(".");

      }

    }

    Serial.printf("\r\nInfo: Finish searching .... Can't find tiny32_MobusRTU_client for this bus [fail]");

}


/***********************************************************************
 * FUNCTION:    tiny32_ModbusRTU_setAddress
 * DESCRIPTION: Set Address for tiny32_ModbusRTU Module [1-252]
 * PARAMETERS:  id, new_id
 * RETURNED:    Address
 ***********************************************************************/
int8_t esp32_iot_all_v3::tiny32_ModbusRTU_setAddress(uint8_t id, uint8_t new_id)
{
    
    /*check parameter*/
    if((new_id < 1) || (new_id >= 253)) 
    {
      Serial.printf("Error: Address is out of the range[1-253]\r\n");
      return -1;
    }

    // #define modbusRTU_Debug

    uint16_t _crc = 0xffff;
    uint16_t _crc_r = 0xffff;
    uint8_t _data_write[8];
    uint8_t _data_read[40];
    uint8_t _byte_cnt = 0;
    uint8_t _data_check[8];

    _data_write[0] = id;
    _data_write[1] = 0x06;
    _data_write[2] = 0x00;
    _data_write[3] = 0x20;
    _data_write[4] = 0x00;
    _data_write[5] = new_id;

    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_write)-2; _i++){
        _crc = crc16_update(_crc, _data_write[_i]);
    } 

  // Insert CRC16 to data byte
    #ifdef modbusRTU_Debug
    Serial.printf("_crc = 0x%02X\r\n",_crc);
    #endif
    _data_write[sizeof(_data_write)-1] = _crc >> 8;          
    _data_write[sizeof(_data_write)-2]= _crc - _data_write[sizeof(_data_write)-1]*0x0100 ;  


#pragma region 
    /***** Debug monitor ****/
    #ifdef modbusRTU_Debug
    Serial.printf("Data write(%d): [ ",sizeof(_data_write));
    for(byte _i=0; _i<sizeof(_data_write); _i++){
      if( _data_write[_i] > 0x0F ){
        Serial.printf("0x%X ",_data_write[_i]);
      }
      else{
        Serial.printf("0x0%X ",_data_write[_i]);
      } 
    }
    Serial.printf("]\r\n");
    #endif
#pragma endregion




    /**** Write data ****/ 
    rs485.flush(); 
    for(int _i=0; _i<8; _i++) rs485.write(_data_write[_i]);
    
    vTaskDelay(300);


    /**** Read data ****/
    if(rs485.available()){

    for(byte _i=0; _i<sizeof(_data_read); _i++) _data_read[_i] = 0x00; //clear buffer
    _byte_cnt = 0;

    //correct data
      do{
          _data_read[_byte_cnt++] = rs485.read();
          if(_data_read[0] == 0x00){ //แก้ไช bug เนื่องจากอ่านค่าแรกได้ 0x00
              _byte_cnt =0;
          }
      // }while(rs485.available()>0);
      }while(rs485.available()>0 && _byte_cnt<sizeof(_data_read));
      

      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data read(%d): [ ",_byte_cnt);
        for(byte _i=0; _i<_byte_cnt; _i++){
            if( _data_read[_i] > 0x0F ){
              Serial.printf("0x%X ",_data_read[_i]);
            }
            else{
              Serial.printf("0x0%X ",_data_read[_i]);
            } 
        }
        Serial.println("]");
        Serial.printf("Byte Count = %d\r\n",_byte_cnt);
        #endif
    } 

    
   
   if(_byte_cnt == 8){

      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i];
      }


      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else if(_byte_cnt > 8){

      uint8_t _addcnt = _byte_cnt - 8;
      for(int i=0; i<8; i++)
      {
        _data_check[i] = _data_read[i+_addcnt]; 
      }



      /***** Debug monitor ****/
      #ifdef modbusRTU_Debug
      Serial.printf("Data check(%d): [ ",sizeof(_data_check));
      for(byte _i=0; _i<sizeof(_data_check); _i++){
          if( _data_check[_i] > 0x0F ){
            Serial.printf("0x%X ",_data_check[_i]);
          }
          else{
            Serial.printf("0x0%X ",_data_check[_i]);
          } 
      }
      Serial.println("]");
      #endif
    }
    else
    {
      Serial.printf("Error: data error\r\n");
      return -1;
    }


    /*** crc check for data read ***/ 
    _crc = 0xffff;
    _crc_r = 0xffff;
    
    // Generate CRC16
    for(byte _i=0; _i < sizeof(_data_check)-2; _i++){
        _crc = crc16_update(_crc, _data_check[_i]);
    } 
    #ifdef modbusRTU_Debug
    Serial.printf("Debug: _crc = 0x%X\r\n",_crc);
    #endif

    // read crc byte from data_check
    _crc_r = _data_check[sizeof(_data_check)-1]; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r <<8; //Serial.print(">>"); Serial.println(_crc_r,HEX);
    _crc_r = _crc_r + _data_check[sizeof(_data_check)-2]; //Serial.print(">>"); Serial.println(_crc_r,HEX);      
    #ifdef modbusRTU_Debug 
    Serial.printf("Debug: _crc_r = 0x%X\r\n",_crc_r);
    #endif

    //return ON/OFF status
    if(_crc_r == _crc)
    {

      Serial.printf("Info: Success to set new Address[%d]\r\n",new_id);
      return new_id;
    }  
    else
    {
      Serial.printf("Error: crc16\r\n");
       return -1;
    } 
}
