/* 
 * File:   ExtraModules.h
 * Author: c4810
 *
 * Created on February 25, 2023, 10:19 PM
 */

#ifndef EXTRAMODULES_H
#define	EXTRAMODULES_H

#ifdef	__cplusplus
extern "C" {
#endif
#define ENABLE 1
#define DISABLE 0
void TMR0Config(char mode);
double Time(void);
unsigned long milliseconds( unsigned long mil);
void TMR1Config(void);
double PulseIn(char pin);
double Frequency(void);



#ifdef	__cplusplus
}
#endif

#endif	/* EXTRAMODULES_H */

