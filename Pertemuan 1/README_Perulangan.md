1. Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan!
   link thinkercad: https://www.tinkercad.com/things/bJb43U88WzV/editel?returnTo=%2Fdashboard&sharecode=S5mK-roMe16TAB1YictsuJaH9p4c1ZoYpfkBRQ_yojs
2. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan!
   Jawab:
   Efek ini dibuat dengan perulangan:for (int ledPin = 2; ledPin < 8; ledPin++)
   Penjelasan:
   - Loop dimulai dari pin kecil (2) ke besar (7)
   - Setiap LED dinyalakan satu per satu
   - Ada delay → jadi terlihat seperti berjalan
3. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri!
   Jawab:
   Efek ini dibuat dengan: for (int ledPin = 7; ledPin >= 2; ledPin--)
   Penjelasan:
   - Loop dari pin besar ke kecil
   - LED menyala dari kanan ke kiri
   - Membuat efek bolak-balik
4. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian
dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
Jawab:
Deskripsi Program
Program ini menyalakan:
* 3 LED kiri (pin 2,3,4)
* lalu 3 LED kanan (pin 5,6,7)
  secara bergantian
Source Code
```cpp
void setup() {
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT); // Set semua pin sebagai output
  }
}

void loop() {
  // Nyalakan LED kiri
  for (int i = 2; i <= 4; i++) {
    digitalWrite(i, HIGH);
  }

  delay(500); // Tunggu

  for (int i = 2; i <= 4; i++) {
    digitalWrite(i, LOW); // Matikan LED kiri
  }

  // Nyalakan LED kanan
  for (int i = 5; i <= 7; i++) {
    digitalWrite(i, HIGH);
  }

  delay(500); // Tunggu

  for (int i = 5; i <= 7; i++) {
    digitalWrite(i, LOW); // Matikan LED kanan
  }
}
```

Penjelasan
* Loop pertama: menyalakan LED kiri
* Delay: memberi efek jeda
* Loop kedua: mematikan LED kiri
* Loop ketiga: menyalakan LED kanan
* Program berjalan terus menerus (loop)

```
```

