/*
 * lcd.c
 *
 *  Created on: 18 Eki 2021
 *      Author: Mahmut T. Kanbollu
 */

#include "stdbool.h"
#include "stdint.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "lcd.h"
void Lcd_ilk_ayarlar(){

SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); //portu kullanýma aç
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
GPIOPinTypeGPIOOutput(LCDPORT, 0xFF);        //portlarýn çýkýþ olarak kullanýlacaðýný belirt
GPIOPinTypeGPIOOutput(LCDPORTAYAR, 0xFF);
SysCtlDelay(50000);
GPIOPinWrite(LCDPORTAYAR, RS,  0x00 );
GPIOPinWrite(LCDPORT, D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7,  0x30 );
GPIOPinWrite(LCDPORTAYAR, E, 0x02);
SysCtlDelay(10);                 //bekle
GPIOPinWrite(LCDPORTAYAR, E, 0x00);
SysCtlDelay(50000);              //bekle
GPIOPinWrite(LCDPORT, D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7,  0x30 );
GPIOPinWrite(LCDPORTAYAR, E, 0x02);
SysCtlDelay(10);                 //bekle
GPIOPinWrite(LCDPORTAYAR, E, 0x00);
SysCtlDelay(50000);              //bekle
GPIOPinWrite(LCDPORT, D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7,  0x30 );
GPIOPinWrite(LCDPORTAYAR, E, 0x02);
SysCtlDelay(10);                 //bekle
GPIOPinWrite(LCDPORTAYAR, E, 0x00);
SysCtlDelay(50000);              //bekle
GPIOPinWrite(LCDPORT, D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7,  0x30 );
GPIOPinWrite(LCDPORTAYAR, E, 0x02);
SysCtlDelay(10);                 //bekle
GPIOPinWrite(LCDPORTAYAR, E, 0x00);
SysCtlDelay(50000);              //bekle
}
void Lcd_Komut_Gonder(unsigned char c) {
    GPIOPinWrite(LCDPORT, D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7, c );
    GPIOPinWrite(LCDPORTAYAR, RS,  0x00 );
    GPIOPinWrite(LCDPORTAYAR, E, 0x02);
    SysCtlDelay(10);                 //bekle
    GPIOPinWrite(LCDPORTAYAR, E, 0x00);
    SysCtlDelay(50000);
}
void Lcd_Tek_Karakter_Yaz(unsigned char d){
    GPIOPinWrite(LCDPORT, D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7, d );
    GPIOPinWrite(LCDPORTAYAR, RS,  0x01 );
    GPIOPinWrite(LCDPORTAYAR, E, 0x02);
    SysCtlDelay(10);                 //bekle
    GPIOPinWrite(LCDPORTAYAR, E, 0x00);
    SysCtlDelay(50000);
 }
void Lcd_Satir_Sutuna_Git(char x, char y){
    if (x%2==!0) { //x mod 2 eþit deðilse 0 a dallan
        Lcd_Komut_Gonder(0x80 + ((y-1) % 16)); //mod 16 ya kadar gider --- 80->8f örn: x=1 y=1 ==> 0x80+0x00 ==> ilk kare yazýldý [(y-1=0)]
            return;
        }
    Lcd_Komut_Gonder(0xC0 + ((y-1) % 16)); //deðilse zaten 2. kýsým ---- C0->Cf örn: x=2 y=1 ==> 0xC0+0x00 ==> ilk kare yazýldý [(y-1=0)]
}
void Lcd_Temizle(void){
    Lcd_Komut_Gonder(0x01); //LCD nin datasheetine göre temizlemek için gerekli olan veri
            SysCtlDelay(10);
}
void Lcd_Cok_Karakter_Yaz(unsigned char dizi[], int dizisayisi){
    int i;
       for (i=0; i<dizisayisi; i++) { //dizi sayýsýna eþit olana kadar diziyi yazdýr
               Lcd_Tek_Karakter_Yaz(dizi[i]);  //tek tek karakterlerle yaz !!
           }
}
