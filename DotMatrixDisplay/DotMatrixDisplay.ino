#include "MaxMatrix.h"
#include "avr/pgmspace.h"

// 05110000044 Onurhan ÇELİK
// 05120000240 Onur TEMUROĞLU

PROGMEM prog_uchar CH[] = {
  3, 8, B0000000, B0000000, B0000000, B0000000, B0000000, // space
  1, 8, B1011111, B0000000, B0000000, B0000000, B0000000, // !
  3, 8, B0000011, B0000000, B0000011, B0000000, B0000000, // "
  5, 8, B0010100, B0111110, B0010100, B0111110, B0010100, // #
  4, 8, B0100100, B1101010, B0101011, B0010010, B0000000, // $
  5, 8, B1100011, B0010011, B0001000, B1100100, B1100011, // %
  5, 8, B0110110, B1001001, B1010110, B0100000, B1010000, // &
  1, 8, B0000011, B0000000, B0000000, B0000000, B0000000, // '
  3, 8, B0011100, B0100010, B1000001, B0000000, B0000000, // (
  3, 8, B1000001, B0100010, B0011100, B0000000, B0000000, // )
  5, 8, B0101000, B0011000, B0001110, B0011000, B0101000, // *
  5, 8, B0001000, B0001000, B0111110, B0001000, B0001000, // +
  2, 8, B10110000, B1110000, B0000000, B0000000, B0000000, // ,
  4, 8, B0001000, B0001000, B0001000, B0001000, B0000000, // -
  2, 8, B1100000, B1100000, B0000000, B0000000, B0000000, // .
  4, 8, B1100000, B0011000, B0000110, B0000001, B0000000, // /
  4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // 0
  3, 8, B1000010, B1111111, B1000000, B0000000, B0000000, // 1
  4, 8, B1100010, B1010001, B1001001, B1000110, B0000000, // 2
  4, 8, B0100010, B1000001, B1001001, B0110110, B0000000, // 3
  4, 8, B0011000, B0010100, B0010010, B1111111, B0000000, // 4
  4, 8, B0100111, B1000101, B1000101, B0111001, B0000000, // 5
  4, 8, B0111110, B1001001, B1001001, B0110000, B0000000, // 6
  4, 8, B1100001, B0010001, B0001001, B0000111, B0000000, // 7
  4, 8, B0110110, B1001001, B1001001, B0110110, B0000000, // 8
  4, 8, B0000110, B1001001, B1001001, B0111110, B0000000, // 9
  2, 8, B01010000, B0000000, B0000000, B0000000, B0000000, // :
  2, 8, B10000000, B01010000, B0000000, B0000000, B0000000, // ;
  3, 8, B0010000, B0101000, B1000100, B0000000, B0000000, // <
  3, 8, B0010100, B0010100, B0010100, B0000000, B0000000, // =
  3, 8, B1000100, B0101000, B0010000, B0000000, B0000000, // >
  4, 8, B0000010, B1011001, B0001001, B0000110, B0000000, // ?
  5, 8, B0111110, B1001001, B1010101, B1011101, B0001110, // @
  4, 8, B1111110, B0010001, B0010001, B1111110, B0000000, // A
  4, 8, B1111111, B1001001, B1001001, B0110110, B0000000, // B
  4, 8, B0111110, B1000001, B1000001, B0100010, B0000000, // C
  4, 8, B1111111, B1000001, B1000001, B0111110, B0000000, // D
  4, 8, B1111111, B1001001, B1001001, B1000001, B0000000, // E
  4, 8, B1111111, B0001001, B0001001, B0000001, B0000000, // F
  4, 8, B0111110, B1000001, B1001001, B1111010, B0000000, // G
  4, 8, B1111111, B0001000, B0001000, B1111111, B0000000, // H
  3, 8, B1000001, B1111111, B1000001, B0000000, B0000000, // I
  4, 8, B0110000, B1000000, B1000001, B0111111, B0000000, // J
  4, 8, B1111111, B0001000, B0010100, B1100011, B0000000, // K
  4, 8, B1111111, B1000000, B1000000, B1000000, B0000000, // L
  5, 8, B1111111, B0000010, B0001100, B0000010, B1111111, // M
  5, 8, B1111111, B0000100, B0001000, B0010000, B1111111, // N
  4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // O
  4, 8, B1111111, B0001001, B0001001, B0000110, B0000000, // P
  4, 8, B0111110, B1000001, B1000001, B10111110, B0000000, // Q
  4, 8, B1111111, B0001001, B0001001, B1110110, B0000000, // R
  4, 8, B1000110, B1001001, B1001001, B0110010, B0000000, // S
  5, 8, B0000001, B0000001, B1111111, B0000001, B0000001, // T
  4, 8, B0111111, B1000000, B1000000, B0111111, B0000000, // U
  5, 8, B0001111, B0110000, B1000000, B0110000, B0001111, // V
  5, 8, B0111111, B1000000, B0111000, B1000000, B0111111, // W
  5, 8, B1100011, B0010100, B0001000, B0010100, B1100011, // X
  5, 8, B0000111, B0001000, B1110000, B0001000, B0000111, // Y
  4, 8, B1100001, B1010001, B1001001, B1000111, B0000000, // Z
  2, 8, B1111111, B1000001, B0000000, B0000000, B0000000, // [
  4, 8, B0000001, B0000110, B0011000, B1100000, B0000000, // backslash
  2, 8, B1000001, B1111111, B0000000, B0000000, B0000000, // ]
  3, 8, B0000010, B0000001, B0000010, B0000000, B0000000, // hat
  4, 8, B1000000, B1000000, B1000000, B1000000, B0000000, // _
  2, 8, B0000001, B0000010, B0000000, B0000000, B0000000, // `
  4, 8, B0100000, B1010100, B1010100, B1111000, B0000000, // a
  4, 8, B1111111, B1000100, B1000100, B0111000, B0000000, // b
  4, 8, B0111000, B1000100, B1000100, B0101000, B0000000, // c
  4, 8, B0111000, B1000100, B1000100, B1111111, B0000000, // d
  4, 8, B0111000, B1010100, B1010100, B0011000, B0000000, // e
  3, 8, B0000100, B1111110, B0000101, B0000000, B0000000, // f
  4, 8, B10011000, B10100100, B10100100, B01111000, B0000000, // g
  4, 8, B1111111, B0000100, B0000100, B1111000, B0000000, // h
  3, 8, B1000100, B1111101, B1000000, B0000000, B0000000, // i
  4, 8, B1000000, B10000000, B10000100, B1111101, B0000000, // j
  4, 8, B1111111, B0010000, B0101000, B1000100, B0000000, // k
  3, 8, B1000001, B1111111, B1000000, B0000000, B0000000, // l
  5, 8, B1111100, B0000100, B1111100, B0000100, B1111000, // m
  4, 8, B1111100, B0000100, B0000100, B1111000, B0000000, // n
  4, 8, B0111000, B1000100, B1000100, B0111000, B0000000, // o
  4, 8, B11111100, B0100100, B0100100, B0011000, B0000000, // p
  4, 8, B0011000, B0100100, B0100100, B11111100, B0000000, // q
  4, 8, B1111100, B0001000, B0000100, B0000100, B0000000, // r
  4, 8, B1001000, B1010100, B1010100, B0100100, B0000000, // s
  3, 8, B0000100, B0111111, B1000100, B0000000, B0000000, // t
  4, 8, B0111100, B1000000, B1000000, B1111100, B0000000, // u
  5, 8, B0011100, B0100000, B1000000, B0100000, B0011100, // v
  5, 8, B0111100, B1000000, B0111100, B1000000, B0111100, // w
  5, 8, B1000100, B0101000, B0010000, B0101000, B1000100, // x
  4, 8, B10011100, B10100000, B10100000, B1111100, B0000000, // y
  3, 8, B1100100, B1010100, B1001100, B0000000, B0000000, // z
  3, 8, B0001000, B0110110, B1000001, B0000000, B0000000, // {
  1, 8, B1111111, B0000000, B0000000, B0000000, B0000000, // |
  3, 8, B1000001, B0110110, B0001000, B0000000, B0000000, // }
  4, 8, B0001000, B0000100, B0001000, B0000100, B0000000, // ~
};

PROGMEM prog_uchar TR_CH[] ={
  4,8,B00111110,B01000001,B11000001,B00100010,B00000000, //Ç
  4,8,B01111000,B10000101,B10100101,B01101000,B00000000, //Ğ
  3,8,B10000100,B11111101,B10000100,B00000000,B00000000, //İ
  4,8,B00111000,B01000101,B01000101,B00111000,B00000000, //Ö
  4,8,B01000110,B11001001,B01001001,B00110010,B00000000, //Ş
  4,8,B00111100,B01000001,B01000001,B00111100,B00000000, //Ü
  4,8,B00111000,B01000100,B11000100,B00101000,B00000000, //ç
  4,8,B10011000,B10100101,B10100101,B01111000,B00000000, //ğ
  3,8,B01001000,B01111000,B01000000,B00000000,B00000000, //ı
  4,8,B00110000,B01001010,B01001010,B00110000,B00000000, //ö
  4,8,B01001000,B11010100,B01010100,B00100100,B00000000, //ş
  4,8,B00111000,B01000010,B01000010,B01111000,B00000000, //ü
};
#define MAX_SIZE 50 //string olarak aldığımız girdinin maximum uzunluğunu 50 olarak belirledik, değiştirilebilir bu değer.

int data = PB_7; //ilgili pin atamaları
int cs = PA_3;
int clock = PB_4;

MaxMatrix m(data, cs, clock);

byte buffer[10];
char charArray[MAX_SIZE];

void setup()
{
  Serial.begin(9600);
  m.init();
  m.setIntensity(0);
  printCharSequential(); //Cihaz ilk açıldığında ABC...abc..012.. karakterlerini sırayla 1 kere yazdırır.
}

void loop()
{
  if(Serial.available()>0) //eğer seri yoldan veri varsa
  {
    clearCharArray(); //charArray değişkenini sıfırlıyor her yeni gelen veri dizisi için.
    Serial.readBytes(charArray,MAX_SIZE);
    delay(500);
  }
  int i;
  for(i=0;i<MAX_SIZE;i++)
  {
    m.clear(); //dot matrix'i sıfırlıyor yeni gelen verilerin yazımı için
    if(charArray[i]=='\0') //string'in sonuna kadar dizimize verileri ekliyoruz 50 karakterden az da olabilir, bu durumda kesiyoruz for döngümüzü
      break;
    printCharacter((int)(charArray[i])); //sırayla karakterleri dot matrix'e yazdırmak için ilgili fonksiyonu çağırıyor.
    delay(500);  //birden fazla karakter geldiyse, 500ms boyunca her bir karakter görünür.
  }
}

void printString(char s) //ascii table'daki default karakterleri yazdıran fonksiyon
{
  char c = s - 32; //ascii numaralarına göre yaptığımız dizide ascii numaraları 32-127 aralığındadır, değerlerinden 32 çıkararak dizideki indise karşığını ayarlıyoruz.
  memcpy_P(buffer, CH + 7*c, 7); //diziden karaktere ait verileri alıp buffer değişknenine atıyoruz.

  m.writeSprite(buffer); //buffer'daki verilere göre dot matrix'e yazdırma işlemini gerçekleştiren fonksiyonu çağıyoruz buffer verisiyle.
}

void clearCharArray() //gelen verileri tuttuğumuz dizimizi sıfırlayan metot.
{
  int i;
  for(int i=0; i<MAX_SIZE; i++)
  {
    if(charArray[i]=='\0')
      break;
    charArray[i]='\0';
  }
}

void printCharSequential() //ABC...abc..012.. karakterlerini sırayla yazdıran fonksiyon.
{
  char string[] = {
    'A','B','C','Ç','D','E','F','G','Ğ','H','I','İ','J','K','L','M','N','O','Ö','P','R','S','Ş','T','U','Ü','V','Y','Z',
    'a','b','c','ç','d','e','f','g','ğ','h','ı','i','j','k','l','m','n','o','ö','p','r','s','ş','t','u','ü','v','y','z',
    '0','1','2','3','4','5','6','7','8','9'};
  int i;
  int x=0;
  for(i=0;i<68;i++)
  {
    m.clear();
    switch(i)
    {
    case 3: //eğer sıradaki karakter Türkçe karakter ise türkçe karakter dizisi üzerinden işlem yapıyoruz
    case 8:
    case 11:
    case 18:
    case 22:
    case 25:
    case 32:
    case 37:
    case 39: 
    case 47:
    case 51:
    case 54:
      memcpy_P(buffer, TR_CH + 7*x, 7); //Türkçe karakter dizisinden ilgili veriyi buffer'a aldık
      m.writeSprite(buffer); //dot matrix'e yazdırmak için ilgili fonksiyonu çağırdık.
      x++;
      break;
    default: //Türkçe karakter dizisinden değil, normal ascii dizisindeyse sıradaki karakter, normal yazdırma işlemini yapıyoruz.
      printString(string[i]);
      break;
    }
    delay(500);
  }
}

void printCharacter(int ascii_code) //ascii_code'a göre karakteri algılayıp yazdırıyor.
{
  int x; //index of TR_CH
  switch(ascii_code) 
  { //eğer karakterin ascii code'u 32-127 aralığında değilse yani Türkçe karakter ise x değerine ilgili indisi atıyoruz.
  case 231: //ç 
    x=6; 
    break;
  case 1: //ğ
    x=7;
    break;
  case 2: //ı
    x=8;
    break;
  case 246: //ö
    x=9;
    break;
  case 3: //ş
    x=10;
    break;
  case 252: //ü
    x=11;
    break;
  case 199: //Ç  
    x=0;
    break;
  case 4: //Ğ
    x=1;
    break;
  case 5: //İ
    x=2;
    break;
  case 214: //Ö
    x=3;
    break;
  case 6: //Ş
    x=4;
    break;
  case 220: //Ü
    x=5;
    break;
  default: //karakterin ascii code'u 32-127 yani normal tablodaysa direk yazdırma normal yazdırma işlemi için gereken fonksiyonu çağırıyoruz.
    printString((char)ascii_code);
    return; //fonksiyondan çıkıyoruz
    break; 
  }
  memcpy_P(buffer, TR_CH + 7*x, 7); //Türkçe karakter ise switch-case'de ayarlanan x indisine göre yazdırma işlemlerini yapıyoruz.
  m.writeSprite(buffer); 
}





