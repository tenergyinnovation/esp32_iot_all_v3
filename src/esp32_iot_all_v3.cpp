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