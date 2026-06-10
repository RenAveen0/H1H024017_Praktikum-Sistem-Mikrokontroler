# Percobaan 2: Timer Menggunakan `millis()`

Dokumentasi ini memuat detail pelaksanaan Percobaan 6B mengenai implementasi fitur pewaktu internal `millis()` pada mikrokontroler Arduino Uno untuk membuat sistem *blinking* LED secara *non-blocking*.

## 🎯 Tujuan
1. Memahami prinsip kerja register penunjuk waktu (*time tracking*) `millis()` bawaan mikrokontroler Arduino Uno yang menghitung durasi sejak sistem aktif.
2. Mengimplementasikan metode kalkulasi selisih waktu aktual terhadap interval target sebagai alternatif efisien pengganti fungsi *blocking* `delay()`.
3. Membangun fondasi arsitektur sistem multitasking sederhana pada perangkat tertanam agar CPU tetap responsif dalam mengeksekusi berbagai instruksi secara simultan.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Pin Digital 13 dikonfigurasi sebagai `OUTPUT` tempat komponen LED terpasang, serta variabel pencatat waktu diinisialisasi menggunakan tipe data berkapasitas besar `unsigned long`.
* Metode *Non-Blocking Time*: Sistem melakukan pemantauan waktu aktual secara konstan di dalam loop utama tanpa menghentikan atau membekukan putaran eksekusi siklus kerja CPU.
* Perilaku Aktuator Fisik: Lampu LED pada pin 13 berhasil melakukan transisi perubahan status (*toggle*) secara periodik dan presisi setiap interval waktu 1000 ms (1 detik).
* Stabilitas dan Responsivitas: Papan mikrokontroler tetap mempertahankan tingkat responsivitas tinggi untuk mengeksekusi baris perintah lain di luar blok percabangan pengondisian waktu tanpa terpengaruh oleh jeda kedipan LED.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan kaki Anoda (+) LED ke Pin Digital 13 pada papan Arduino Uno.
   * Hubungkan kaki Katoda (-) LED ke salah satu kaki Resistor 220 Ω, kemudian hubungkan kaki resistor pasangannya langsung ke jalur Ground (GND) Arduino.
2. Koneksi Perangkat: Sambungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B sebagai jalur distribusi daya listrik dan media komunikasi data program.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu buat sketsa program baru. Ketik kode program dengan mendefinisikan konstanta parameter rentang durasi `interval = 1000`, variabel penampung `previousMillis`, serta bangun struktur pengondisian berbasis perbandingan selisih waktu aktual di dalam fungsi `loop()`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk menguji keabsahan dan memastikan tidak ada kesalahan penulisan struktur logika program, simpan sketch dengan nama file `modul6_timer`, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Amati ritme kedipan fisik lampu LED pada pin 13 secara langsung. Lakukan analisis terhadap ketepatan durasi aktif/mati LED agar sesuai dengan interval waktu 1 detik yang diharapkan, serta pastikan program utama tetap berjalan lancar tanpa mengalami pembekuan eksekusi.