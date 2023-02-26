#include "Hormiga4550.h"

int SPBRG_Register;
int main(void)
{
    configuracionInicial();
    setup();
    for(;;)
    {
        loop();
    }
    return 0;
}

void configuracionInicial(void)
{
    //ADC Module Configuration.
    TRISAbits.RA0 = 1;
    TRISAbits.RA1 = 1;
    TRISAbits.RA2 = 1;
    TRISAbits.RA3 = 1;
    ADCON0 = 0x01;  //Turning ON the A/D Converter
    ADCON1 = 0x0B;  //Setting the AN0,AN1, AN2, AN3 as Analog Inputs and GPIO others.
    ADCON2 = 0xAB;  //Left Justify, 12TAD, 64 TOSC
    //PWM Module Configuration
    PR2 = 0xFF;
    T2CON = 0x05; //Tmier 2 prescaler equals 
    CCPR2L = 0x00;
    CCPR1L = 0x00;
    CCP1CON = 0x0C;//0x4F; //0100 1111 //New Value 0000 1100
    CCP2CON = 0x0C;//0x4F;
    //IO Ports Configuration.
    asm("CLRF PORTA"); //All Terminal as Inputs. only RA4 as digital Inpuy
    asm("MOVLW 0x3F");
    asm("MOVWF TRISA");
    PORTB = 0x00;
    TRISB &= 0x00;
    PORTB = 0x00;
    //PORTC Configuration
    PORTC = 0x00;
    TRISC = 0x00;
    PORTC = 0x00;
    //PORTD Configuration
    asm("CLRF PORTD");
    asm("MOVLW 0x00");
    asm("MOVF TRISD");
    asm("CLRF PORTD");
    PORTE = 0x00;
    TRISE = 0x07;
}
void delay(const int milis)
{
    for(int j=0;j<milis;j++)
    {
        //Retardo de 1ms
        for(int i=0;i<400;i++)
        {
            asm("NOP");
        }
    }
}

void delayMicroseconds(const int micros)
{
    //Con un Cristal de 20MHz el retardo es en Multipos de 6.5uSegundos
    for(int i=0;i<micros;i++)
    {
        asm("NOP");
    }
    
}

void pinMode(char pin, char mode)
{
    switch(pin)
    {
        case 0:
            TRISAbits.RA4 = mode;
            break;
        case 1:
            TRISAbits.RA5 = mode;
            break;
        case 2:
            TRISCbits.RC0 = mode;
            break;
        case 3:
            TRISCbits.RC1 = mode;
            break;
        case 4:
            TRISCbits.RC2 = mode;
            break;
        case 5:
            TRISDbits.RD0 = mode;
            break;
        case 6:
            TRISDbits.RD1 = mode;
            break;
        case 7:
            TRISDbits.RD2 = mode;
            break;
        case 8:
            TRISDbits.RD3 = mode;
            break;
        case 9:
            TRISCbits.RC6 = mode;
            break;
        case 10:
            TRISCbits.RC7 = mode;
            break;
        case 11:
            TRISDbits.RD4 = mode;
            break;
        case 12:
            TRISDbits.RD5 = mode;
            break;
        case 13:
            TRISDbits.RD6 = mode;
            break;
        case 14:
            TRISDbits.RD7 = mode;
            break;
        case 15:
            TRISBbits.RB0 = mode;
            break;
        case 16:
            TRISBbits.RB1 = mode;
            break;
        case 17:
            TRISBbits.RB2 = mode;
            break;
        case 18:
            TRISBbits.RB3 = mode;
            break;
        case 19:
            TRISBbits.RB4 = mode;
            break;
        case 20:
            TRISBbits.RB5 = mode;
            break;
        case 21:
            TRISBbits.RB6 = mode;
            break;
        case 22:
            TRISBbits.RB7 = mode;
            break;
    }
}
void digitalWrite(char pin, char mode)
{
    switch(pin)
    {
       case 0:
           LATAbits.LA4 = mode;
            break;
        case 1:
            LATAbits.LA5 = mode;
            break;
        case 2:
            LATCbits.LC0 = mode;
            break;
        case 3:
            LATCbits.LC1 = mode;
            break;
        case 4:
            LATCbits.LC2 = mode;
            break;
        case 5:
            LATDbits.LD0 = mode;
            break;
        case 6:
            LATDbits.LD1 = mode;
            break;
        case 7:
            LATDbits.LD2 = mode;
            break;
        case 8:
            LATDbits.LD3 = mode;
            break;
        case 9:
            LATCbits.LC6 = mode;
            break;
        case 10:
            LATCbits.LC7 = mode;
            break;
        case 11:
            LATDbits.LD4 = mode;
            break;
        case 12:
            LATDbits.LD5 = mode;
            break;
        case 13:
            LATDbits.LD6 = mode;
            break;
        case 14:
            LATDbits.LD7 = mode;
            break;
        case 15:
            LATBbits.LB0 = mode;
            break;
        case 16:
            LATBbits.LB1 = mode;
            break;
        case 17:
            LATBbits.LB2 = mode;
            break;
        case 18:
            LATBbits.LB3 = mode;
            break;
        case 19:
            LATBbits.LB4 = mode;
            break;
        case 20:
            LATBbits.LB5 = mode;
            break;
        case 21:
            LATBbits.LB6 = mode;
            break;
        case 22:
            LATBbits.LB7 = mode;
            break;
    }
}
char digitalRead(char pin)
{
    switch(pin)
    {
       case 0:
           return PORTAbits.RA4;
            break;
        case 1:
            return PORTAbits.RA5;
            break;
        case 2:
            return PORTCbits.RC0;
            break;
        case 3:
            return PORTCbits.RC1;
            break;
        case 4:
            return PORTCbits.RC2;
            break;
        case 5:
            return PORTDbits.RD0;
            break;
        case 6:
            return PORTDbits.RD1;
            break;
        case 7:
            return PORTDbits.RD2;
            break;
        case 8:
            return PORTDbits.RD3;
            break;
        case 9:
            return PORTCbits.RC6;
            break;
        case 10:
            return PORTCbits.RC7;
            break;
        case 11:
            return PORTDbits.RD4;
            break;
        case 12:
            return PORTDbits.RD5;
            break;
        case 13:
            return PORTDbits.RD6;
            break;
        case 14:
            return PORTDbits.RD7;
            break;
        case 15:
            return PORTBbits.RB0;
            break;
        case 16:
            return PORTBbits.RB1;
            break;
        case 17:
            return PORTBbits.RB2;
            break;
        case 18:
            return PORTBbits.RB3;
            break;
        case 19:
            return PORTBbits.RB4;
            break;
        case 20:
            return PORTBbits.RB5;
            break;
        case 21:
            return PORTBbits.RB6;
            break;
        case 22:
            return PORTBbits.RB7;
            break;
    }
}
unsigned int analogRead(char pin)
{
    switch(pin)
    {
        case 0:
            ADCON0 = 0x03;
            while(ADCON0bits.GODONE != 0);
            return (ADRESH << 8)+ ADRESL;
            break;
        case 1:
            ADCON0 = 0x07;
            while(ADCON0bits.GODONE != 0);
            return (ADRESH << 8)+ ADRESL;
            break;
        case 2:
            ADCON0 = 0x0B;
            while(ADCON0bits.GODONE != 0);
            return (ADRESH << 8)+ ADRESL;
            break;
        case 3:
            ADCON0 = 0x0F;
            while(ADCON0bits.GODONE != 0);
            return (ADRESH << 8)+ ADRESL;
            break;
    }
}

char analogWrite(char pin, unsigned int value)
{
    switch(pin)
    {
        case 6://CCP2
            CCPR2L = value >> 2;
            DC2B1 = value & 2;
            DC2B0 = value & 1;  
            break;
        case 5://CCP1
            CCPR1L = value >> 2;
            DC1B1 = value & 2;
            DC1B0 = value & 1;
            break;
    }
    return 0;
}

void CCPDisable(void)
{
    CCP1M3 = 0;
    CCP1M2 = 0;
}

char PBRead(char pin)
{
    switch(pin)
    {
        case 0:
            if(PORTEbits.RE0)
            {
                delay(100);
                return (PORTEbits.RE0) ? 1 : 0;
            }
            else
            {
                return 0;
            }
            break;
        case 1:
            if(PORTEbits.RE1) 
            {
                delay(100);
                return (PORTEbits.RE1) ? 1 : 0;
            }
            else
            {
                return 0;
            }
            break;
        case 2:
            if(PORTEbits.RE2) 
            {
                delay(120);
                return (PORTEbits.RE2) ? 1 : 0;
            }
            else
            {
                return 0;
            }
            break;
    }
}

char SerialBegin(const long int BaudRate)
{
	/*
		BaudRate = _XTAL_FREQ / (64 * (SPBRG + 1))
	*/
	unsigned  int x;
	BRGH = 0;
	x = (_XTAL_FREQ / (64 * BaudRate)) - 1;
	if(x > 255)
	{
		BRGH = 1;
		x = (_XTAL_FREQ / (16 * BaudRate)) - 1;
		SPBRG = x;
		SYNC = 0;
		SPEN = 1;                                     //Enables Serial Port
		TRISC7 = 1;                                   //As Prescribed in Datasheet
		TRISC6 = 1;                                   //As Prescribed in Datasheet
		CREN = 1;                                     //Enables Continuous Reception
		TXEN = 1;
        TXREG = 0x00;
        RCREG = 0x00;
		return 0;
	}
	else
	{
		SPBRG = x;
		SYNC = 0;
		SPEN = 1;                                     //Enables Serial Port
		TRISC7 = 1;                                   //As Prescribed in Datasheet
		TRISC6 = 1;                                   //As Prescribed in Datasheet
		CREN = 1;                                     //Enables Continuous Reception
		TXEN = 1;
        TXREG = 0x00;
        RCREG = 0x00;
		return 1;
	}
}

char TxRegisterFull(void)
{
    return TRMT;
}
char SerialErrors(void)
{
    if((FERR == 1) && (FERR || OERR)) //Framing Error
    {
        return 1;
    }
    else if((OERR == 1) && (FERR || OERR)) //OverRun Error
    {
        return 2;
    }
    else if(OERR && FERR) 
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void SerialWrite(char dataWrite)
{
    while(!TXIF);
    TXREG = dataWrite;
}

char SerialWriteText(char *dataText)
{
    unsigned int i;
    for(i=0;dataText[i]!='\0';i++)
    {
       SerialWrite(dataText[i]); 
    }
}
void SerialPrint(char *dataText)
{
    for(unsigned int i=0;dataText[i]!='\0';i++)
    {
        SerialWrite(dataText[i]);
    }
}
void SerialPrintLn(char *dataText)
{
    unsigned int i;
        for(i=0;dataText[i]!='\0';i++)
        {
            SerialWrite(dataText[i]);
        }
        SerialWrite(0x0A);
}
char SerialAvailable(void)
{
    return RCIF || (TXIF && TRMT);
}

char SerialRead(void)
{
    while(!RCIF);
    return RCREG;
}

void SerialReadText(char *Output, unsigned int lenght)
{
    unsigned int i;
    for(i=0;i<lenght;i++)
    {
        Output[i] = SerialRead();
    }
}