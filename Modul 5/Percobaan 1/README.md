# Percobaan 1: Multitasking Menggunakan FreeRTOS

Dokumentasi ini memuat detail pelaksanaan Percobaan 5A mengenai implementasi konsep multitasking pada sistem embedded menggunakan FreeRTOS di Arduino Uno untuk menjalankan beberapa tugas (*task*) secara bersamaan (*concurrent*) di bawah manajemen penjadwalan *kernel scheduler*.

## 🎯 Tujuan
1. Memahami prinsip kerja, arsitektur dasar, dan mekanisme alokasi waktu eksekusi Real-Time Operating System (RTOS) pada perangkat tertanam.
2. Mengimplementasikan fungsi `xTaskCreate()` untuk membuat, mendaftarkan, dan mengalokasikan sumber daya memori untuk beberapa *task* mandiri.
3. Menerapkan manajemen penundaan waktu *non-blocking* menggunakan fungsi `vTaskDelay()` agar *Kernel Scheduler* dapat membagi siklus pemrosesan CPU secara efisien.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Komunikasi serial dikonfigurasi pada kecepatan transmisi 9600 bps. Pin Digital 8 dikonfigurasi sebagai output untuk LED Merah (Task1), Pin Digital 7 sebagai output untuk LED Kuning (Task2), dan fungsi Task3 diatur untuk kalkulasi counter interal.
* Eksekusi Bersamaan (*Concurrent*): Sistem mampu membagi penanganan tugas sehingga ketiga *task* utama dapat berjalan secara simultan tanpa saling menghentikan atau membekukan eksekusi *task* lainnya (*non-blocking*).
* Perilaku Aktuator Fisik:
  * LED Merah (Pin 8) berkedip secara periodik dengan jeda aktif dan mati masing-masing selama 200 ms.
  * LED Kuning (Pin 7) berkedip secara periodik dengan jeda aktif dan mati masing-masing selama 300 ms.
* Monitoring Data: Serial Monitor menampilkan log teks pemanggilan status "Task1" dan "Task2" secara bergantian, serta mencetak nilai variabel pencacah (*counter*) dari Task3 yang terus meningkat (*increment*) setiap interval 500 ms.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan kaki Anoda (+) LED Merah ke Pin Digital 8 pada Arduino Uno, lalu hubungkan kaki Katoda (-)-nya ke pin Ground (GND) melalui Resistor 220 Ω sebagai pembatas arus.
   * Hubungkan kaki Anoda (+) LED Kuning ke Pin Digital 7 pada Arduino Uno, lalu hubungkan kaki Katoda (-)-nya ke pin Ground (GND) melalui Resistor 220 Ω lainnya.
2. Koneksi Perangkat: Sambungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B sebagai jalur catu daya dan komunikasi data.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, pastikan pustaka FreeRTOS telah terpasang. Ketik kode program dengan menyertakan library `#include <Arduino_FreeRTOS.h>`, buat prototipe fungsi untuk ketiga *task*, inisialisasi parameter fungsi `xTaskCreate()` pada blok `setup()` dengan ukuran stack 128 kata dan tingkat prioritas 1, panggil fungsi `vTaskStartScheduler()`, biarkan fungsi `loop()` kosong, serta susun logika loop tak terbatas `while(1)` menggunakan penanda waktu `vTaskDelay()` pada masing-masing badan *task*.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada kesalahan penulisan kode atau kegagalan pemanggilan pustaka OS, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Buka Serial Monitor di Arduino IDE, pastikan pengaturan kecepatan berada di 9600 baud, amati keselarasan respons visual pergeseran ritme kedipan antara LED Merah dan LED Kuning, serta periksa ketepatan log nilai angka counter yang dicetak pada layar monitor.