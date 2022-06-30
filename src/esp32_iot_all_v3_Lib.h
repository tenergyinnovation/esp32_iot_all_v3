/***********************************************************************
 * File         :     esp32_iot_all_v3_Lib.h
 * Description  :     Library for Hardware config and function for esp32_iot_all_v3 module
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     24 June 2022
 * Revision     :     1.0
 * Rev1.0       :     Original
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/
#include <esp32_iot_all_v3.h>

/**************************************/
/*           GPIO define              */
/**************************************/
#define BUTTON_SW1      34
#define BUTTON_SW2      35
#define LED_RED         12
#define LED_BLUE        4
#define BUZZER          13
#define SLID_SW         39
#define INPUT_1         2
#define OUTPUT_1        32
#define OUTPUT_2        33
#define OUTPUT_3        25
#define OUTPUT_4        15
#define ONE_WIRE_BUS    14
#define RXD2            16
#define TXD2            17
#define RXD3            26
#define TXD3            27


static const uint8_t daysInMonth [] PROGMEM = { 31,28,31,30,31,30,31,31,30,31,30,31 };
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};





 /***********************************************************************
 * FUNCTION:    TickBlueLED_blink
 * DESCRIPTION: ON-OFF Red LED
 * PARAMETERS:  bool state
 * RETURNED:    nothing
 ***********************************************************************/
void TickBlueLED_blink(void){
    bool _state = digitalRead(LED_BLUE);
    digitalWrite(LED_BLUE, !_state);
}

 /***********************************************************************
 * FUNCTION:    TickRedLED_blink
 * DESCRIPTION: ON-OFF Red LED
 * PARAMETERS:  bool state
 * RETURNED:    nothing
 ***********************************************************************/
void TickRedLED_blink(void){
    bool _state = digitalRead(LED_RED);
    digitalWrite(LED_RED, !_state);
}



 /***********************************************************************
 * FUNCTION:    void TickBuildinLED_blink(void){
 * DESCRIPTION: ON-OFF Buildin LED
 * PARAMETERS:  bool state
 * RETURNED:    nothing
 ***********************************************************************/
void TickBuildinLED_blink(void){
        bool _state = digitalRead(BUILTIN_LED);
        digitalWrite(BUILTIN_LED, !_state);
}


