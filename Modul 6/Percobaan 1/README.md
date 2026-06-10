# Percobaan 1: External Interrupt

Dokumentasi ini memuat detail pelaksanaan Percobaan 6A mengenai implementasi mekanisme *external interrupt* menggunakan komponen *push button* untuk mengendalikan status aktif dan nonaktif lampu LED secara instan tanpa melalui proses pengecekan berulang (*polling*).

## 🎯 Tujuan
1. Memahami prinsip dasar, alur kerja, dan keunggulan mekanisme interupsi perangkat keras murni dibandingkan metode *polling* konvensional pada mikrokontroler Arduino Uno.
2. Mengimplementasikan fungsi *Interrupt Service Routine* (ISR) dan perintah `attachInterrupt()` untuk menangani kejadian luar secara responsif (*real-time*).
3. Memahami fungsi dan pentingnya penggunaan keyword `volatile` pada deklarasi variabel yang diakses di dalam fungsi interupsi.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Pin Digital 13 dikonfigurasi sebagai `OUTPUT` tempat beban LED terpasang, dan Pin Digital 2 diatur sebagai `INPUT_PULLUP` untuk mengaktifkan resistor pembatas internal pada jalur input tombol.
* Registrasi Interupsi: Fungsi ISR bernama `tombolInterrupt` didaftarkan secara presisi pada Pin 2 menggunakan perintah `attachInterrupt()` dengan pemicu kondisi transisi sinyal jatuh (*FALLING edge*).
* Efek Responsif Fisik: Ketika *push button* ditekan (sinyal berubah dari HIGH ke LOW), mikrokontroler secara instan menghentikan sementara program utama untuk mengeksekusi ISR yang bertugas membalikkan (*toggle*) nilai status logika LED secara akurat.
* Efisiensi CPU: Fungsi `loop()` program utama dibiarkan fokus hanya untuk memperbarui status fisik output, sehingga menghemat konsumsi daya dan waktu pemrosesan siklus CPU karena tidak dibebani instruksi pengecekan tombol secara kontinu.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan kaki Anoda (+) LED ke Pin Digital 13 pada papan Arduino Uno.
   * Hubungkan kaki Katoda (-) LED ke salah satu kaki Resistor 220 Ω, kemudian hubungkan kaki resistor pasangannya ke jalur Ground (GND) Arduino.
   * Hubungkan salah satu pin kaki saklar *push button* ke Pin Digital 2 (jalur Interrupt 0) dan kaki terminal pasangannya langsung menuju ke jalur Ground (GND).
2. Koneksi Perangkat: Sambungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B sebagai jalur distribusi daya listrik dan media komunikasi data.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu buat sketsa program baru. Ketik kode program dengan mendefinisikan variabel status bertipe `volatile bool ledState`, susun fungsi fungsi ringkas ISR `tombolInterrupt()` untuk membalik logika boolean, serta deklarasikan konfigurasi pin dan fungsi interupsi murni pada blok `setup()`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada kesalahan penulisan struktur logika ataupun keyword bahasa pemrograman, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Simpan sketch dengan nama file `modul6_interrupt`. Lakukan pengujian fisik dengan menekan dan melepaskan komponen tombol, lalu amati tingkat responsivitas perubahan visual kondisi LED pada pin 13 dan lakukan analisis kesesuaian sistem terhadap parameter spesifikasi operasional.