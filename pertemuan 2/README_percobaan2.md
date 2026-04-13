1. Gambarkan rangkaian schematic yang digunakan pada percobaan!<br>
   Jawab: https://www.tinkercad.com/things/38ocYfC7Nxj/editel?returnTo=%2Fdashboard&sharecode=dIzHYZJXhFBaOeXdah1mqTc-GbCO5NSwlsQOffpKUV8 <br>
          
2. Mengapa pada push button digunakan mode INPUT_PULLUP pada Arduino Uno? Apa keuntungannya dibandingkan rangkaian biasa?<br>
jawab: SMode INPUT_PULLUP digunakan untuk mengaktifkan resistor pull-up internal pada Arduino, sehingga pin input secara default berada pada kondisi HIGH.<br>

3. Jika salah satu LED segmen tidak menyala, apa saja kemungkinan penyebabnya dari sisi hardware maupun software?<br>
Jawab: Kemungkinan penyebab dari tidak menyala salah satu LED pada seven segment dapat berasal dari beberapa faktor. Salah <br> satunya adalah kesalahan pada wiring, seperti kabel yang tidak terhubung dengan benar atau terlepas dari rangkaian. Selain itu, LED pada segmen tersebut mungkin mengalami kerusakan sehingga tidak dapat menyala. Faktor lain yang dapat mempengaruhi adalah<br> resistor yang tidak terpasang dengan benar atau tidak sesuai nilai, sehingga arus yang mengalir tidak mencukupi. Selain dari sisi perangkat keras, kesalahan juga dapat terjadi pada logika program, misalnya terdapat kesalahan dalam penulisan kode yang menyebabkan segmen tertentu tidak mendapatkan sinyal yang sesuai.<br>

4. Modifikasi rangkaian dan program dengan dua push button (increment & decrement) + penjelasan kode (README.md)<br>
jawab:<br>
Konsep Rangkaian<br>
- Push button 1 → untuk increment (menambah nilai)<br>
- Push button 2 → untuk decrement (mengurangi nilai)<br>
- Keduanya menggunakan INPUT_PULLUP<br>
program:<br>
```cpp
#include <Arduino.h>

// Pin 7-Segment (a b c d e f g dp)
const int segmentPins[8] = {7, 6, 5, 11, 10, 8, 9, 4};

// Push button
const int btnUp = 2;     // tombol tambah
const int btnDown = 3;   // tombol kurang

// Counter
int counter = 0;

// State button
bool lastUpState = HIGH;
bool lastDownState = HIGH;

// Pola digit 0-F
byte digitPattern[16][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5 
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}, //9
  {1,1,1,0,1,1,1,0}, //A
  {0,0,1,1,1,1,1,0}, //b
  {1,0,0,1,1,1,0,0}, //C
  {0,1,1,1,1,0,1,0}, //d
  {1,0,0,1,1,1,1,0}, //E
  {1,0,0,0,1,1,1,0}  //F
};

// Tampilkan digit
void displayDigit(int num)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(segmentPins[i], !digitPattern[num][i]);
  }
}

void setup()
{
  for(int i=0; i<8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }

  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);

  displayDigit(counter);
}

void loop()
{
  bool currentUp = digitalRead(btnUp);
  bool currentDown = digitalRead(btnDown);

  // Tombol tambah
  if (lastUpState == HIGH && currentUp == LOW)
  {
    counter++;
    if(counter > 15) counter = 0;
    displayDigit(counter);
    delay(200);
  }

  // Tombol kurang
  if (lastDownState == HIGH && currentDown == LOW)
  {
    counter--;
    if(counter < 0) counter = 15;
    displayDigit(counter);
    delay(200);
  }

  lastUpState = currentUp;
  lastDownState = currentDown;
}



'''
---
