#ifndef LCD_H_
#define LCD_H_

    #define LCDPORT                          GPIO_PORTB_BASE // DATA i�in se�ilen port
    #define LCDPORTAYAR                      GPIO_PORTF_BASE
    #define RS                               GPIO_PIN_0      //register select i�in pin se�imi
    #define E                                GPIO_PIN_1      //enable i�in pin se�imi

    // 4 bit olacaksa sadece bunlar.
    #define D4                               GPIO_PIN_4      //LCD D4
    #define D5                               GPIO_PIN_5      //LCD D5
    #define D6                               GPIO_PIN_6      //LCD D6
    #define D7                               GPIO_PIN_7      //LCD D7

    // 8 bit olacaksa asagidaki baglantilari da ekle.
    #define D0                               GPIO_PIN_0      //kullan�lam�yor, RS ile �ak���yor
    #define D1                               GPIO_PIN_1      //kullan�lam�yor, E ile �ak���yor
    #define D2                               GPIO_PIN_2      //D1 ve D2 sebebiyle kullan�lam�yor
    #define D3                               GPIO_PIN_3      //D1 ve D2 sebebiyle kullan�lam�yor


    // fonksiyon prototipleri
    void Lcd_ilk_ayarlar();                                  //lcd selamlama
    void Lcd_Komut_Gonder(unsigned char c) ;                 //lcd ye komut g�nderme
    void Lcd_Tek_Karakter_Yaz(unsigned char d) ;             //lcd de tek karakter yaz�m�
    void Lcd_Satir_Sutuna_Git(char x, char y);               //lcd kurs�r ayar�
    void Lcd_Temizle(void);                                  //lcd temizleme
    void Lcd_Cok_Karakter_Yaz(unsigned char  dizi[], int dizisayisi); //lcd de diziden veri al�p tek tek yazma

#endif /* LCD_H_ */
