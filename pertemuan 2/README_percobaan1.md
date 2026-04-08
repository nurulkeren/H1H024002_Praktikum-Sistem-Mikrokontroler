1. Gambarkan rangkaian schematic yang digunakan pada percobaan!<br>
   Jawab:
2. Apa yang terjadi jika nilai num lebih dari 15?
   Jawab:
Tidak ada pola segment yang cocok,
Tampilan bisa:
- Kosong (blank)
- Menampilkan pola tidak jelas (acak) Atau tetap di angka terakhir (tergantung kode)
3. Apakah program ini menggunakan common cathode atau common anode? Jelaskan
alasanya!
Jawab: Common Cathode,
Alasan:
- Segment menyala saat diberi HIGH (1)
- Arduino mengirim logika HIGH → LED menyala
4. Modifikasi program agar tampilan berjalan dari F ke 0 dan berikan penjelasan disetiap
baris kode nya dalam bentuk README.md!
Jawab:

```cpp
#include <Arduino.h> // library utama Arduino

// 7-Segment Common Anode

// Pin mapping segment: a b c d e f g dp
const int segmentPins[8] = {7, 6, 5, 11, 10, 8, 9, 4}; // array pin untuk setiap segment

byte digitPattern[16][8] = {
  {1,1,1,1,1,1,0,0}, //0 → semua segment nyala kecuali g dan dp
  {0,1,1,0,0,0,0,0}, //1 → hanya b dan c
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3 
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8 → semua nyala
  {1,1,1,1,0,1,1,0}, //9
  {1,1,1,0,1,1,1,0}, //A
  {0,0,1,1,1,1,1,0}, //b
  {1,0,0,1,1,1,0,0}, //C
  {0,1,1,1,1,0,1,0}, //d
  {1,0,0,1,1,1,1,0}, //E
  {1,0,0,0,1,1,1,0}  //F
};

// Fungsi untuk menampilkan angka ke seven segment
void displayDigit(int num) // parameter num = angka yang ditampilkan
{
  for(int i=0; i<8; i++) // looping untuk setiap segment (a–dp)
  {
    digitalWrite(segmentPins[i], !digitPattern[num][i]); // kirim sinyal ke pin (dibalik karena common anode)
  }
}

void setup()
{
  for(int i=0; i<8; i++) // loop semua pin segment
  {
    pinMode(segmentPins[i], OUTPUT); // set pin sebagai output
  }
}

void loop()
{
  for(int i=15; i>=0; i--) // loop dari 15 (F) sampai 0 (mundur)
  {
    displayDigit(i); // tampilkan angka sesuai nilai i
    delay(1000); // jeda 1 detik
  }
}
```

---
