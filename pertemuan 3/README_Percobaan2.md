1. Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian
tersebut!<br>
jawab:<br>
Komunikasi I2C (Inter-Integrated Circuit) memungkinkan Arduino berkomunikasi dengan LCD menggunakan hanya dua kabel:<br>
- SDA (Serial Data): Mengirim dan menerima data.<br>
- SCL (Serial Clock): Mengirim sinyal sinkronisasi.<br>

Alur Kerja:<br>
- Arduino bertindak sebagai master, sedangkan LCD sebagai slave.<br>
- Arduino mengirimkan alamat perangkat I2C (misalnya 0x27 atau 0x3F).<br>
- Jika alamat sesuai, LCD merespons dengan sinyal ACK (Acknowledgement).<br>
- Arduino mengirim data berupa karakter atau perintah tampilan.<br>
- Modul I2C mengubah data tersebut menjadi sinyal paralel yang dipahami LCD.<br>
- Teks atau simbol ditampilkan pada layar LCD.<br>

2. Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan
pin kanan tertukar!<br>
jawab: Ya, penyambungan harus sesuai.<br>
- Jika Pin Kiri dan Kanan Tertukar:<br>
Sistem tetap berfungsi normal.<br>
- Arah pembacaan terbalik:<br>
Putar ke kanan maka nilai mengecil.<br>
Putar ke kiri maka nilai membesar.<br>

3. Modifikasi program dengan menggabungkan antara UART dan I2C (keduanya sebagai
output) sehingga:<br>
- Data tidak hanya ditampilkan di LCD tetapi juga di Serial Monitor<br>
- Adapun data yang ditampilkan pada Serial Monitor sesuai dengan table berikut:<br>
ADC: 0 Volt: 0.00 V Persen: 0%<br>
Tampilan jika potensiometer dalam kondisi diputar paling kiri<br>
- ADC: 0 0% | setCursor(0, 0) dan Bar (level) | setCursor(0, 1)<br>
- Berikan penjelasan disetiap baris kode nya dalam bentuk README.md!<br>
jawab:<br>
```
#include <Wire.h>                  // Library untuk komunikasi I2C
#include <LiquidCrystal_I2C.h>     // Library untuk mengontrol LCD I2C

// Inisialisasi LCD dengan alamat I2C 0x27, ukuran 16 kolom dan 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pinPot = A0;                  // Menentukan pin analog A0 untuk potensiometer
int nilaiADC = 0;                 // Variabel untuk menyimpan nilai ADC (0–1023)
float tegangan = 0;               // Variabel untuk menyimpan hasil konversi tegangan
float persen = 0;                 // Variabel untuk menyimpan hasil dalam persen

void setup() {
  Serial.begin(9600);             // Memulai komunikasi serial (UART) dengan baudrate 9600
  lcd.init();                     // Inisialisasi LCD
  lcd.backlight();                // Menyalakan lampu latar LCD
}

void loop() {
  nilaiADC = analogRead(pinPot);          // Membaca nilai analog dari potensiometer (0–1023)

  tegangan = nilaiADC * 5.0 / 1023.0;     // Mengubah nilai ADC menjadi tegangan (0–5V)

  persen = nilaiADC * 100.0 / 1023.0;     // Mengubah nilai ADC menjadi persen (0–100%)

  // ================= OUTPUT KE SERIAL MONITOR =================
  Serial.print("ADC: ");         // Menampilkan teks "ADC: "
  Serial.print(nilaiADC);        // Menampilkan nilai ADC
  Serial.print(" | Volt: ");     // Menampilkan teks pemisah
  Serial.print(tegangan, 2);     // Menampilkan tegangan dengan 2 angka di belakang koma
  Serial.print(" V | Persen: "); // Menampilkan teks persen
  Serial.print(persen, 0);       // Menampilkan persen tanpa desimal
  Serial.println("%");           // Menampilkan simbol % dan pindah baris

  // ================= OUTPUT KE LCD =================
  lcd.setCursor(0, 0);           // Mengatur kursor di kolom 0 baris 0
  lcd.print("ADC:");             // Menampilkan teks "ADC:"
  lcd.print(nilaiADC);           // Menampilkan nilai ADC
  lcd.print(" ");                // Memberi spasi
  lcd.print(persen, 0);          // Menampilkan persen tanpa desimal
  lcd.print("% ");               // Menampilkan simbol persen

  // ================= BAR INDIKATOR =================
  int bar = map(nilaiADC, 0, 1023, 0, 16); // Mengubah nilai ADC menjadi panjang bar (0–16)

  lcd.setCursor(0, 1);           // Mengatur kursor ke baris kedua

  for (int i = 0; i < bar; i++) { // Perulangan untuk menampilkan bar sesuai nilai
    lcd.print((char)255);        // Menampilkan blok penuh (█)
  }

  for (int i = bar; i < 16; i++) { // Mengisi sisa kolom dengan kosong
    lcd.print(" ");              // Menampilkan spasi agar bar terlihat rapi
  }

  delay(500);                    // Delay 500 ms (setengah detik) sebelum loop berikutnya
}
```

4. Lengkapi table berikut berdasarkan pengamatan pada Serial Monitor<br>
jawab:<br>
| ADC | Volt (V) | Persen (%) |<br>
| --- | -------- | ---------- |<br>
| 1   | 0.00     | 0.10       |<br>
| 21  | 0.10     | 2.05       |<br>
| 49  | 0.24     | 4.79       |<br>
| 74  | 0.36     | 7.23       |<br>
| 96  | 0.47     | 9.38       |<br>

