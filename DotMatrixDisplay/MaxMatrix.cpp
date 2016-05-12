#include "Arduino.h"
#include "MaxMatrix.h"

MaxMatrix::MaxMatrix(byte _data, byte _cs, byte _clock) 
{
  data = _data;
  cs = _cs;
  clock = _clock;
}

void MaxMatrix::init()
{
  pinMode(data,  OUTPUT); //ilgili DIN,CLK,CS pinlerinin output olarak kullanılacağını ayarladık.
  pinMode(clock, OUTPUT);
  pinMode(cs,  OUTPUT);
  digitalWrite(clock, HIGH); 

  setCommand(OP_SCANLIMIT, 0x07);      
  setCommand(OP_DECODEMODE, 0x00);  // decode mode'u, led matrix'i kullanmak için ayarlanır.
  setCommand(OP_SHUTDOWN, 0x01);    // shutdown modunda olmadığını belirtiyoruz.
  setCommand(OP_DISPLAYTEST, 0x00); // herhangi bir display test durumunda olmadığını ayarlıyoruz.

  // empty registers, turn all LEDs off
  clear(); //clear fonksiyonuyla dot matrix'i temizledik.

  setIntensity(0x08);    //dot matrix'in parlaklık ayarını yaptık. 0-16 arasında değer verebiliyoruz.
}

void MaxMatrix::setIntensity(byte intensity) //parlaklık ayarını yapmayı sağlayan fonksiyon, parametre olarak parlaklık değerini alır.
{
  setCommand(OP_INTENSITY, intensity); //gelen değerle birlikte parlaklık ayarı opcode'uyla ilgili fonksiyonu çağırır.
}

void MaxMatrix::clear() //dot matrix'teki tüm ledleri söndürür.
{
  for (int i=0; i<8; i++) 
    setColumnAll(i,0);
}

void MaxMatrix::setColumnAll(byte col, byte value) //8x8'lik dot matrix'teki tüm led'lere aynı değeri atmayı sağlayan fonksiyon, clear fonksiyonu tarafından kullanılır.
{
  digitalWrite(cs, LOW);    

  shiftOut(data, clock, MSBFIRST, col + 1);
  shiftOut(data, clock, MSBFIRST, value);

  digitalWrite(cs, HIGH);
}

void MaxMatrix::setCommand(byte command, byte value) //gelen komut ve değere göre dot matrix üzerindeki ilgili komutu gerçekleştirir.
{
  digitalWrite(cs, LOW); //dot matrix'e veri göndermeden önce CS pinini low yaptık. Daha sonra High yaparız. Pulse işlemini sağlamış oluruz.

  shiftOut(data, clock, MSBFIRST, command); //shiftOut fonksiyonu ile komutu yolladık
  shiftOut(data, clock, MSBFIRST, value); //daha sonra komutun ihtiyaç duyduğu değeri shiftOut ile yolladık.

  digitalWrite(cs, HIGH);
}

void MaxMatrix::setColumn(byte col, byte value) //dot matrix'te hangi sütunun hangi verilerle yanacağını yapan fonksiyon
{
  digitalWrite(cs, LOW);    //gönderim öncesi CS low alınır, daha sonra high ayarlanır tekrardan.

  shiftOut(data, clock, MSBFIRST, col + 1); //komut olarak sütun numarası yollandı, yani dot matrix yazdırma işlemi yapacağını bu kodla anlar
  shiftOut(data, clock, MSBFIRST, value); //ayarlanan sütuna yazdırılacak olan veri yollanır

  digitalWrite(cs, HIGH);
}

void MaxMatrix::writeSprite(const byte* sprite) //dizi olarak gelen yazdırılacak karakterin ilgili verilerini alıp yazdırmayı sağlayan fonksiyon.
{
  int w = sprite[0]; //kaç sütunu kullanacaksa ilk değerden sütun sayısı alınır.
  int h = sprite[1];

  for (int i=0; i<w; i++) //sütun sayısı for döngüsü ile veriler ilgili sütunlara gönderilir yazdırılmak üzere.
  {
    setColumn(i, sprite[i+2]);
  }
}


