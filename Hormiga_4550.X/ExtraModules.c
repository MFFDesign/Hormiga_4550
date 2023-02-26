#include "Hormiga4550.h"
#include "ExtraModules.h"

unsigned long millis = 0;
void TMR0Config(char mode)
{
    switch(mode)
    {
        case ENABLE:
            //COnfiguracion para crear un desborde del registro del Timer 0 cada Milisegundo.
            T0CON = 0x17;
            INTCONbits.T0IE = 1;
            T0CONbits.TMR0ON = 1;
            T0CON = 0xC4;
            //OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
            //WriteTimer0(0x0000); //OverLFow a 1 Segundo
            TMR0L = 0x00;
            TMR0H = 0x00;
            INTCONbits.TMR0IF = 0;
            ei();
            break;
        case DISABLE:
            
            break;
    }
}
double Time(void)
{
    return (millis * 1.4)+(TMR0 * 0.000021);
}

void __interrupt() TimerOverflow(void)
{
    if(INTCONbits.TMR0IF == 1)
    {
        /* Procedure */
        millis++;
        INTCONbits.TMR0IF = 0;
        TMR0L = 0x00;
        TMR0H = 0x00;
        //WriteTimer0(0x0000); //  Overflow a 1 segundo
    }
}
void TMR1Config(void)
{
    T1CON = 0xB6;
}
double PulseIn(char pin)
{
    double dtime;
    double now = Time();
    while(digitalRead(pin) == 1);
    dtime = Time() - now;
    return dtime;
}
double Frequency(void)
{
    double now, lastTime, dtime, dData, freq;
    int nowData, lastData;
    double HighFrqK = 1.175;
    lastTime = now;
    now = Time();
    T1CONbits.TMR1ON = 1;
    delay(100);
    T1CONbits.TMR1ON = 0;
    nowData = TMR1L;
    nowData += TMR1H * 256;
    dData = lastData - nowData;
    dtime = now - lastTime;
    lastData = nowData;
    freq = dData / dtime;
    if(freq < 0)
    {
        return -HighFrqK * freq;
    }
    else
    {
           return HighFrqK * freq; 
    }
}

