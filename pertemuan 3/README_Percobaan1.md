1) Jelaskan proses dari input keyboard hingga LED menyala/mati!<br>
jawab:
- Input dari Keyboard<br>
Pengguna mengetikkan perintah seperti 1, 0, atau 2 pada Serial Monitor di Arduino IDE.<br>
- Pengiriman Data ke Arduino<br>
Data dikirim dari komputer ke Arduino melalui komunikasi serial menggunakan kabel USB.<br>
- Penerimaan Data oleh Arduino<br>
Arduino memeriksa apakah ada data masuk menggunakan Serial.available().<br>
- Pembacaan Data<br>
Jika data tersedia, Arduino membaca karakter menggunakan Serial.read().<br>
- Pemrosesan Perintah<br>
Arduino membandingkan data yang diterima dengan perintah yang telah diprogram:<br>
'1' → LED menyala.<br>
'0' → LED mati.<br>
'2' → LED berkedip.<br>
- Eksekusi Output<br>
Arduino mengirimkan sinyal ke pin digital yang terhubung dengan LED menggunakan digitalWrite().
- LED Menyala atau Mati<br>
Arus listrik mengalir melalui LED sehingga LED menyala atau berhenti sehingga LED mati.<br>

2) Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika
baris tersebut dihilangkan?<br>
jawab: Serial.available() digunakan untuk memeriksa apakah terdapat data yang tersedia di buffer serial sebelum dibaca oleh Arduino.<br>
sintax:<br>
if (Serial.available() > 0) {<br>
    data = Serial.read();<br>
}<br>
Alasan Penggunaan:<br>
Menghindari pembacaan data kosong.<br>
Mencegah kesalahan pembacaan.<br>
Memastikan program berjalan stabil dan efisien.<br>
Jika Dihilangkan:<br>
Tanpa Serial.available(), Arduino akan tetap mencoba membaca data meskipun tidak ada data yang masuk. Hal ini dapat menyebabkan Pembacaan tidak valid, Perilaku tidak terduga, Program tidak stabil, Pemborosan sumber daya.<br>

3) Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi
jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan
berikan penjelasan disetiap baris kode nya dalam bentuk README.md!<br>
jawab:
'''
// Menentukan pin LED
const int ledPin = 13;

// Variabel untuk menyimpan data dari serial
char dataMasuk;

// Variabel untuk status LED berkedip
bool modeBlink = false;

// Variabel untuk mengatur waktu kedip menggunakan millis()
unsigned long previousMillis = 0;
const long interval = 500; // Interval kedip 500 ms
bool ledState = LOW;

void setup() {
  // Mengatur pin LED sebagai output
  pinMode(ledPin, OUTPUT);

  // Memulai komunikasi serial
  Serial.begin(9600);

  // Menampilkan pesan pada Serial Monitor
  Serial.println("Masukkan perintah:");
  Serial.println("1 = LED ON");
  Serial.println("0 = LED OFF");
  Serial.println("2 = LED BLINK");
}

void loop() {
  // Mengecek apakah ada data yang masuk
  if (Serial.available() > 0) {
    // Membaca data dari Serial Monitor
    dataMasuk = Serial.read();

    // Jika menerima perintah '1'
    if (dataMasuk == '1') {
      digitalWrite(ledPin, HIGH); // Menyalakan LED
      modeBlink = false;          // Mematikan mode blink
      Serial.println("LED ON");
    }

    // Jika menerima perintah '0'
    else if (dataMasuk == '0') {
      digitalWrite(ledPin, LOW);  // Mematikan LED
      modeBlink = false;          // Mematikan mode blink
      Serial.println("LED OFF");
    }

    // Jika menerima perintah '2'
    else if (dataMasuk == '2') {
      modeBlink = true;           // Mengaktifkan mode blink
      Serial.println("LED BLINK");
    }
  }

  // Jika mode blink aktif
  if (modeBlink) {
    unsigned long currentMillis = millis();

    // Mengatur kedipan LED tanpa delay
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Mengubah status LED
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
}
---'''

5) Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap
sistem<br>
jawab:
