# Percobaan 1: Seven Segment (Output)

Dokumentasi ini memuat detail pelaksanaan Percobaan 2A mengenai pemrograman GPIO pada Arduino Uno untuk mengendalikan Seven Segment Display secara sekuensial.

## 🎯 Tujuan
1. Memahami konsep dasar General Purpose Input/Output (GPIO) sebagai fungsi output digital pada mikrokontroler Arduino.
2. Mengimplementasikan penggunaan array dua dimensi untuk menyimpan dan memetakan pola biner karakter heksadesimal.
3. Mengendalikan Seven Segment Display untuk menampilkan karakter heksadesimal (0-F) secara berurutan dengan jeda waktu tertentu.

## 💡 Spesifikasi yang Diharapkan
* Tampilan Karakter: Sistem mampu menampilkan karakter heksadesimal dari 0-9 dilanjutkan dengan A, b, C, d, E, dan F secara berurutan dan stabil.
* Interval Jeda: Perpindahan antar karakter terjadi secara otomatis dengan interval waktu (*delay*) selama 1000 ms (1 detik).
* Sistem Logika: Menggunakan logika *active low* (Common Anode), di mana segmen display akan menyala saat pin digital Arduino mengirimkan sinyal `LOW` (operator `!`).
* Proteksi Memori: Terdapat pembatasan nilai indeks (*boundary check*) maksimal hingga 15. Jika nilai counter melebihi 15, sistem akan otomatis mereset nilai kembali ke 0 untuk mencegah error akses memori (*out-of-bounds access*).

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Siapkan komponen berupa Arduino Uno, Seven Segment Display, Breadboard, Resistor 220 Ω, dan Kabel Jumper.
   * Hubungkan pin segmen display ke pin digital Arduino dengan pemetaan: segmen a ➔ Pin 7, b ➔ Pin 6, c ➔ Pin 5, d ➔ Pin 11, e ➔ Pin 10, f ➔ Pin 8, g ➔ Pin 9, dan dp ➔ Pin 4.
   * Pasang resistor 220 Ω pada setiap jalur segmen sebagai pembatas arus untuk melindungi LED dari kerusakan.
2. Koneksi Perangkat: Hubungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program yang memanfaatkan struktur array `digitPattern[16][8]` dan fungsi `displayDigit()` untuk memanggil pola karakter.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada *error* pada kode, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Amati tampilan Seven Segment untuk memastikan semua karakter dari 0 hingga F muncul secara berurutan, lalu kembali mereset ke angka 0 setelah siklus selesai.