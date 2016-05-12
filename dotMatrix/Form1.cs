using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
namespace $safeprojectname$
{
    public partial class Form1 : Form
    {
        SerialPort sp; //SPI için gereken SerialPort sınıfından nesneyi yarattık.
        public Form1()
        {
            sp = new SerialPort("COM4", 9600); //sp SerialPort nesnesinin hangi porttan, kaçlık bir BaudRate ile gideceğini belirttik.
            sp.Open(); //Portu haberleşmeye açtık.

            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {   

        }

        private void singleCharTextBox_TextChanged(object sender, EventArgs e) //tek karaktere basıldıysa ilgili textBox'ta
        {
            String str = singleCharTextBox.Text; //karakter alınır
            byte[] bytes = new byte[str.Length]; 
            bytes = getBytes(str); //byte verilerine döndürülür alınan karakter
            sp.Write(bytes, 0, 1); //Daha sonra byte'lar şeklinde port'a veriler yazdırılır
            singleCharTextBox.SelectAll();
        }

        private void sendButton_Click(object sender, EventArgs e) //string şeklinde veri gönderilecekse
        {
            String str = stringTextBox.Text; //string alınır 
            byte[] bytes = new byte[str.Length];
            bytes = getBytes(str); //byte verilerine döndürülür
            sp.Write(bytes, 0, str.Length); //Porta yazdırılır.
        }

        private byte[] getBytes(String str) //gelen stringdeki karakterlerin byte'lara döndürülmesinis sağlayan fonksiyon
        {
            byte[] bytes = new byte[str.Length];
            for(int i=0; i<str.Length;i++) //Gelen stringin boyutu kadar for döngüsü döner.
            {
                if(str[i]=='ğ' || str[i] == 'ı' || str[i] == 'ş' || str[i] == 'Ğ' || str[i] == 'İ' || str[i] == 'Ş')
                { //Eğer sıradaki karakterin ASCII kodu 255'den fazlaysa ve de Türkçe karakterse
                    switch(str[i]){ //ASCII tablosunda kullanmadığımız kodlara(1-6 bu karakterler atanır. 
                        case 'ğ':
                            bytes[i] = (byte)1;
                            break;
                        case 'ı':
                            bytes[i] = (byte)2;
                            break;
                        case 'ş':
                            bytes[i] = (byte)3;
                            break;
                        case 'Ğ':
                            bytes[i] = (byte)4;
                            break;
                        case 'İ':
                            bytes[i] = (byte)5;
                            break;
                        case 'Ş':
                            bytes[i] = (byte)6;
                            break;
                    }
                }
                else //karakterler 32-127 yani normal bulunan karakterler ise direkt olarak byte'a döndürülür ve diziye eklenir.
                {
                    bytes[i] = (byte)str[i];
                }
            }
            return bytes; //oluşturulan byte dizisi döndürülür.
        }
    }
}
