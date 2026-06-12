# Percobaan 2: Komunikasi Task Menggunakan Queue

Dokumentasi ini memuat detail pelaksanaan Percobaan 5B mengenai implementasi konsep komunikasi antar-task (*inter-task communication*) secara konkuren menggunakan fitur antrean (*Queue*) pada FreeRTOS di Arduino Uno.

## 🎯 Tujuan
1. Memahami konsep multitasking dan mekanisme manajemen komunikasi serta pertukaran data antar-task pada sistem tertanam menggunakan FreeRTOS.
2. Mengimplementasikan fungsi `xQueueCreate()` untuk membuat objek antrean baru dan mengalokasikan ukuran memori data yang aman di dalam kernel.
3. Menerapkan fungsi `xQueueSend()` dan `xQueueReceive()` untuk mengirim serta menerima data terstruktur melalui jalur antrean secara sinkron.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Jalur komunikasi serial dibuka pada kecepatan 9600 bps. Objek antrean `my_queue` diinisialisasi untuk menampung data berukuran `struct readings` , serta task `read_data` dan `display` berhasil didaftarkan ke dalam sistem.
* Aliran Multitasking & Scheduler: Penjadwal tugas (*kernel scheduler*) berfungsi dengan baik untuk membagi waktu eksekusi secara konkuren antara task pengirim dan task penerima data.
* Pengiriman Data Antrean: Task `read_data` secara periodik mampu mengemas data indikator dan mengirimkan struktur data tersebut ke dalam antrean.
* Output Visual Monitor: Task `display` berhasil menangkap paket data dari antrean secara sukses (`pdPASS`) dan menampilkannya sebagai output informasi suhu serta kelembapan pada layar Serial Monitor secara statis.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras: Siapkan papan Arduino Uno dan hubungkan ke komputer menggunakan kabel USB sebagai debugger dan media output data, karena percobaan antrean awal ini hanya memanfaatkan komunikasi internal sistem.
2. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program lengkap yang memuat library `#include <Arduino_FreeRTOS.h>` dan `#include <queue.h>`, deklarasi tipe `struct readings`, pembuatan fungsi pengirim `read_data`, serta fungsi penerima data `display`.
3. Inisialisasi Sistem: Pastikan perintah pembuatan antrean `xQueueCreate()` dan pendaftaran tugas `xTaskCreate()` sudah dikonfigurasi dengan tepat di dalam fungsi `setup()`, serta fungsi `loop()` dibiarkan kosong karena kendali penuh dialihkan ke kernel FreeRTOS.
4. Unggah Program: Lakukan kompilasi (*compile*) program untuk memastikan seluruh baris kode bebas dari kesalahan, simpan sketch dengan nama file `modul6_taskqueue`, kemudian unggah (*upload*) program ke dalam papan Arduino board.
5. Pengamatan dan Analisis: Buka Serial Monitor di Arduino IDE dengan kecepatan transmisi 9600 baud , perhatikan kesesuaian output data teks *temperature* dan *humidity* yang tercetak, lalu berikan analisis hasil percobaan tersebut untuk dituliskan pada Buku Catatan Praktikum.