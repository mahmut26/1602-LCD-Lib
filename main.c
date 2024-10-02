#include "stdint.h"
#include "stdbool.h"
#include "math.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/sysctl.c"
#include "driverlib/gpio.h"
#include "lcd.h"




int main(void)

{
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
    unsigned char metin[] = {'m', 'a','h','o'};
    Lcd_ilk_ayarlar();
    while(1){

        Lcd_Satir_Sutuna_Git(1, 1);
        Lcd_Tek_Karakter_Yaz('x'); // belki 'a' seklindedir.
        SysCtlDelay(80000/3);
        Lcd_Satir_Sutuna_Git(2, 1);
        Lcd_Cok_Karakter_Yaz(metin, 4);
    }
}


