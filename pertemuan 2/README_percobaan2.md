1. Gambarkan rangkaian schematic yang digunakan pada percobaan!<br>
   Jawab: - Seven segment berhasil menampilkan angka 0–F<br>
          - Counter berjalan otomatis<br>
          - Push button dapat mengontrol nilai counter<br>
          - Sistem input-output berjalan dengan baik<br>
          
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
// Deklarasi pin tombol
const int btnUp = 2;      // tombol tambah
const int btnDown = 3;    // tombol kurang

int counter = 0;          // variabel counter

void setup() {
  pinMode(btnUp, INPUT_PULLUP);     // set tombol up sebagai input pullup
  pinMode(btnDown, INPUT_PULLUP);   // set tombol down sebagai input pullup

  // inisialisasi pin seven segment sebagai output
  for(int i = 4; i <= 11; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // jika tombol up ditekan
  if(digitalRead(btnUp) == LOW){
    counter++;               // tambah nilai
    if(counter > 15) counter = 0; // reset jika lebih dari 15
    delay(200);              // delay untuk debounce
  }

  // jika tombol down ditekan
  if(digitalRead(btnDown) == LOW){
    counter--;               // kurangi nilai
    if(counter < 0) counter = 15; // kembali ke 15 jika kurang dari 0
    delay(200);
  }

  tampilkanAngka(counter);   // tampilkan ke seven segment
}

// fungsi untuk menampilkan angka
void tampilkanAngka(int num){
  // (isi sesuai mapping segment kalian)
}
'''
---
