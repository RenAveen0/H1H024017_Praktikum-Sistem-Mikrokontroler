# Percobaan 1: Komunikasi Serial (UART)

Dokumentasi ini memuat detail pelaksanaan Percobaan 3A mengenai implementasi protokol komunikasi serial asinkron UART untuk mengendalikan perangkat keras secara *real-time* via Serial Monitor.

## 🎯 Tujuan
1. Memahami prinsip kerja, struktur frame, dan konfigurasi baud rate pada komunikasi serial UART mikrokontroler Arduino Uno.
2. Mengimplementasikan fungsi `Serial.available()` dan `Serial.read()` untuk manajemen buffer data masuk dari komputer.
3. Mengendalikan komponen output fisik (LED) secara interaktif berdasarkan karakter perintah yang dikirimkan.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Komunikasi serial dikonfigurasi pada kecepatan transmisi 9600 baud, dan LED pada Pin Digital 8 diatur sebagai `OUTPUT`.
* Kondisi LED Menyala: Ketika karakter '1' dikirimkan melalui Serial Monitor, pin digital 8 bernilai `HIGH`, LED menyala, dan muncul teks konfirmasi "LED ON" pada monitor.
* Kondisi LED Mati: Ketika karakter '0' dikirimkan melalui Serial Monitor, pin digital 8 bernilai `LOW`, LED mati, dan muncul teks konfirmasi "LED OFF" pada monitor.
* Penanganan Validasi Input: Jika Serial Monitor menerima karakter di luar '1' atau '0', sistem akan menyaring input tersebut dan menampilkan pesan peringatan "Perintah tidak dikenal" tanpa mengubah status fisik LED.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan kaki Anoda (+) LED ke Pin Digital 8 pada Arduino Uno.
   * Hubungkan kaki Katoda (-) LED ke salah satu kaki Resistor 220 Ω, kemudian hubungkan kaki resistor lainnya ke pin Ground (GND) Arduino.
2. Koneksi Perangkat: Sambungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B sebagai jalur catu daya dan komunikasi data.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program yang menginisialisasi `Serial.begin(9600)` pada fungsi `setup()`, serta memuat fungsi pemeriksaan buffer serial dan struktur percabangan `if-else` pada fungsi `loop()`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada kesalahan penulisan kode, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Buka Serial Monitor di Arduino IDE, pastikan pengaturan kecepatan berada di 9600 baud, jalankan pengujian dengan mengirimkan karakter '1', '0', dan karakter acak lainnya, lalu amati kesesuaian respons visual LED beserta log teks yang ditampilkan.