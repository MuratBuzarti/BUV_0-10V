/*
 * File:   main.c
 * Author: buzar
 *
 * Created on 23 июля 2021 г., 10:17
 */

#define _XTAL_FREQ 8000000
#include "pic10f322.h"
#include "functions.h"
//#include "config.h"
#include "xc.h"

#define LowPower RA3
#define MidPower RA1
#define HighPower RA0


// Задание скважности
unsigned char PWM_set=0;

// Счётчик времени в количествах прерываний для измерения времени
unsigned int time_counter=0;

// Счётчик отсутствия команд
unsigned int NoCommandCounter=0;

void main()
{
    init();
//    GIE = 1; // Разрешение глобльных прерываний
    
    while(1)
    {
        
        /*
        PWM_high=18;
        __delay_ms(3000);
        PWM_high=12;
        __delay_ms(3000);
        PWM_high=8;
        __delay_ms(3000);
        PWM_high=0;
        __delay_ms(3000);
        */

        __delay_us(500);
        
        if(PWM2DCH<PWM_set)
        {
            __delay_ms(50);
            PWM2DCH++;
        }
        
        if(PWM2DCH>PWM_set)
        {
            __delay_ms(50);
            PWM2DCH--;
        }        
        
        if (LowPower == 0) {
            PWM_set = 50;
            NoCommandCounter = 0;
        }

        if (MidPower == 0) {
            PWM_set = 75;
            NoCommandCounter = 0;
        }

        if (HighPower == 0) {
            PWM_set =90;
            NoCommandCounter = 0;
        }

        
        if ((LowPower==1)&&(MidPower==1)&&(HighPower==1))
        {
            NoCommandCounter++;
            if (NoCommandCounter>=1000)
            {
                PWM2DCH = 0;
                NoCommandCounter=1000;
            }
        }
        
    }
    
}

// Обработчик прерывания
// Название tmr2Int придумывается самостоятельно
/*void __interrupt() tmr2Int()
{
    PWM_counter++;
    
    if(PWM_counter>=PWM_period)
    {
        RA2=1;
        PWM_counter=0;
    }
    
    if(PWM_counter>=PWM_high)
    {
        RA2=0;
    }
    
    TMR2IF=0;   // сброс флага прерывания
    return;
}
  */