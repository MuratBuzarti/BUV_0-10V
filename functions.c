#include "pic10f322.h"
#include "functions.h"
#include "xc.h"


//--------------------------------------------//
// Инициализация периферии
// Порты
// Тактовый генератор
// Модуль ШИМ
// Модуль измерения температуры

void init()
{
    // Тактовый генератор
    OSCCON=0b01100000;
    
    // Порты
    PORTA=0;
    TRISA=0b00001011;
    ANSELA=0;
    WPUA=0;
    
    // Таймер 2 для генерации прерываний
    PR2=50;
    T2CON=0b00000100;
    
    // Прерывание
    PEIE=1;
    TMR2IE=1;
    
    return;
}
