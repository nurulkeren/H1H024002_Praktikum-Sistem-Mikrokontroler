## percobaan 1
Pertanyaan Praktikum:

1. Pada kondisi apa program masuk ke blok if?
Jawab:
Program masuk ke blok if ketika nilai variabel timeDelay <= 100.

Artinya:
Saat delay sudah semakin kecil (LED berkedip semakin cepat)
Dan mencapai batas minimum (100 ms atau kurang)   

2. Pada kondisi apa program masuk ke blok else?
Jawab:
Program masuk ke blok else ketika kondisi timeDelay > 100.

Artinya:
Selama delay masih di atas 100 ms
Program akan terus mempercepat kedipan LED dengan mengurangi timeDelay

3. Apa fungsi dari perintah delay(timeDelay)?
Jawab:
Fungsi delay(timeDelay) adalah:

- Memberikan jeda waktu (dalam milidetik)
- Mengatur kecepatan LED berkedip

Penjelasan:

- Semakin besar timeDelay → LED berkedip lambat
- Semakin kecil timeDelay → LED berkedip cepat

4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati),
ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang →
mati dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
Jawab:
Deskripsi Program
Program ini mengatur LED agar berkedip dengan pola:
mati → lambat → cepat → sedang → mati

Source Code
```cpp
const int ledPin = 6;      // Menentukan pin LED
int timeDelay = 1000;      // Delay awal (lambat)
bool kembali = false;      // Penanda untuk memperlambat kembali

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin LED sebagai output
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED nyala
  delay(timeDelay);            // Tunggu sesuai delay

  digitalWrite(ledPin, LOW);   // LED mati
  delay(timeDelay);            // Tunggu lagi

  if (!kembali) {              // Jika masih fase percepatan
    timeDelay -= 100;          // Percepat LED

    if (timeDelay <= 100) {    // Jika sudah cepat maksimal
      kembali = true;          // Ubah ke fase perlambatan
    }

  } else {                     // Jika fase perlambatan
    timeDelay += 100;          // Perlambat LED

    if (timeDelay >= 1000) {   // Jika sudah kembali lambat
      while (true);            // Berhenti (mati total)
    }
  }
}
```

Penjelasan Singkat

* Program awalnya mempercepat kedipan LED
* Setelah mencapai cepat maksimal, LED diperlambat kembali
* Saat kembali ke lambat, program berhenti (LED mati)

```
```





