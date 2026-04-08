1. Uraikan hasil tugas pada praktikum yang telah dilakukan pada setiap percobaan!<br>
   Jawab: - Seven segment berhasil menampilkan angka 0–F<br>
          - Counter berjalan otomatis<br>
          - Push button dapat mengontrol nilai counter<br>
          - Sistem input-output berjalan dengan baik<br>
          
2. Bagaimana prinsip kerja dari Seven Segment Display dalam menampilkan angka dan
karakter?<br>
jawab: Seven segment terdiri dari 7 LED (a–g):<br>
Setiap angka dibentuk dari kombinasi LED<br>
Contoh:<br>
0 → semua kecuali g<br>
1 → b dan c<br>
Arduino mengatur HIGH/LOW untuk tiap segment<br>

3. Jelaskan bagaimana sistem counter bekerja pada program tersebut!<br>
Jawab: - Variabel count menyimpan nilai<br>
       - Nilai berubah:<br>
          Otomatis (loop)<br>
          Atau dari tombol (input)<br>
       - Nilai dikirim ke fungsi display<br>
       - Seven segment menampilkan sesuai pola<br>
