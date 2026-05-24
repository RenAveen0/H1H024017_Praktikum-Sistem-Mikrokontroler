# Percobaan 2: Inter-Integrated Circuit (I2C) dan Analog-to-Digital Converter (ADC)

Dokumentasi ini memuat detail pelaksanaan Percobaan 3B mengenai implementasi protokol komunikasi serial sinkron I2C untuk menampilkan hasil konversi sinyal analog potensiometer (ADC) ke layar LCD 16x2.

## 🎯 Tujuan
1. Memahami prinsip kerja komunikasi data multi-device menggunakan arsitektur master-slave pada protokol I2C.
2. Mengimplementasikan fitur modul ADC 10-bit built-in Arduino untuk membaca perubahan tegangan linear dari sensor analog.
3. Mengonfigurasi dan mengendalikan modul display LCD 16x2 secara efisien hanya dengan menggunakan dua jalur pin GPIO utama (SDA dan SCL).

## 💡 Spesifikasi yang Diharapkan
* Pembacaan Resolusi Analog: Sistem mampu mengubah tegangan input variabel (0-5V) dari potensiometer menjadi data digital dalam rentang nilai 0 hingga 1023 secara akurat.
* Tampilan Data Dinamis: Baris pertama LCD memuat teks info nilai numerik raw ADC, sementara baris kedua menampilkan visualisasi perkembangan grafik batang proporsional (*bar level*) sepanjang 0 hingga 16 karakter.
* Efisiensi Jalur Komunikasi: Pengendalian penuh unit display eksternal berhasil diringkas secara optimal melalui bus I2C memanfaatkan pin A4 (SDA) dan pin A5 (SCL).
* Responsivitas Pembaruan: Data masukan analog diproses secara kontinu dan diperbarui ke layar LCD secara *real-time* dengan jeda interval waktu penyegaran (*refresh rate*) selama 200 ms.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan pin GND dan VCC pada modul LCD I2C ke jalur ground dan daya 5V Arduino Uno. Sambungkan pin SDA ke Pin Analog A4 dan pin SCL ke Pin Analog A5.
   * Pasang potensiometer pada breadboard: hubungkan kaki kiri ke GND, kaki kanan ke jalur 5V, dan kaki tengah (*wiper*) sebagai pin data ke Pin Analog A0 Arduino Uno.
2. Koneksi Perangkat: Hubungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, pastikan library `Wire.h` dan `LiquidCrystal_I2C.h` sudah terinstal, lalu ketik program untuk membaca fungsi `analogRead(A0)` serta logika fungsi pemetaan grafik batang.
4. Unggah Program: Pastikan parameter alamat I2C target (0x27 atau 0x3F) sudah sesuai, lakukan kompilasi (*verify*) program untuk memastikan bebas dari *error*, lalu klik *upload* untuk mengisi memori flash Arduino.
5. Pengamatan & Dokumentasi: Putar tuas potensiometer secara perlahan dari batas kiri ke batas kanan, amati sinkronisasi perubahan nilai angka dan grafik batang pada layar LCD 16x2, kemudian ambil dokumentasi sebagai bukti keberhasilan eksperimen.