# Percobaan 2: Seven Segment dengan Push Button (Input)

Dokumentasi ini memuat detail pelaksanaan Percobaan 2B mengenai pembacaan input digital melalui push button untuk mengontrol nilai counter pada Seven Segment Display.

## 🎯 Tujuan
1. Memahami cara membaca data input digital dari komponen push button menggunakan pin GPIO Arduino.
2. Mengimplementasikan konfigurasi `INPUT_PULLUP` internal untuk menjaga kestabilan sinyal masukkan.
3. Menerapkan algoritma *edge detection* (deteksi transisi pulsa) untuk mengatasi masalah *bouncing* pada sakelar mekanis.

## 💡 Spesifikasi yang Diharapkan
* Kondisi Awal: Saat sistem dinyalakan, Seven Segment Display menampilkan karakter '0' dan status tombol berada pada kondisi default `HIGH` (tidak ditekan).
* Respons Kontrol: Setiap kali push button ditekan, sistem mendeteksi transisi perubahan sinyal dari `HIGH` ke `LOW` (*falling edge*) untuk menambah nilai counter tepat satu satuan (+1).
* Stabilitas Sistem: Angka atau karakter pada layar berubah secara stabil dan presisi tanpa adanya lonjakan nilai ganda atau *glitch* dalam sekali tekan.
* Kondisi Batas & Reset: Penghitungan berjalan dalam rentang heksadesimal (indeks 0-15). Ketika tombol ditekan saat display berada di karakter 'F', sistem akan otomatis mereset nilai counter kembali ke '0'.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Gunakan susunan komponen Seven Segment dari percobaan sebelumnya (Pin 4, 5, 6, 7, 8, 9, 10, 11).
   * Tambahkan satu buah push button pada breadboard. Hubungkan salah satu kaki tombol ke Pin Digital 2 Arduino, dan hubungkan kaki pasangannya langsung ke jalur Ground (GND).
2. Koneksi Perangkat: Hubungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program yang mengonfigurasi pin tombol sebagai `INPUT_PULLUP` serta memuat logika perbandingan variabel *state* tombol saat ini dengan *state* sebelumnya.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan struktur kode sudah benar, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan & Dokumentasi: Tekan tombol secara berkala untuk menguji keandalan sistem dari karakter 0 hingga F, pastikan transisi berjalan lancar, lalu ambil dokumentasi berupa foto atau video sebagai bukti hasil percobaan.