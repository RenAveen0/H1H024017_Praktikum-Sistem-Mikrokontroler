# Percobaan 2: Komunikasi Task Menggunakan Queue

[cite_start]Dokumentasi ini memuat detail pelaksanaan Percobaan 5B mengenai implementasi konsep komunikasi antar-task (*inter-task communication*) secara konkuren menggunakan fitur antrean (*Queue*) pada FreeRTOS di Arduino Uno[cite: 195, 242].

## 🎯 Tujuan
1. [cite_start]Memahami konsep multitasking dan mekanisme manajemen komunikasi serta pertukaran data antar-task pada sistem tertanam menggunakan FreeRTOS[cite: 197].
2. [cite_start]Mengimplementasikan fungsi `xQueueCreate()` untuk membuat objek antrean baru dan mengalokasikan ukuran memori data yang aman di dalam kernel[cite: 216].
3. [cite_start]Menerapkan fungsi `xQueueSend()` dan `xQueueReceive()` untuk mengirim serta menerima data terstruktur melalui jalur antrean secara sinkron[cite: 228, 234].

## 💡 Spesifikasi yang Diharapkan
* [cite_start]Konfigurasi Awal: Jalur komunikasi serial dibuka pada kecepatan 9600 bps[cite: 215]. [cite_start]Objek antrean `my_queue` diinisialisasi untuk menampung data berukuran `struct readings` [cite: 212, 216][cite_start], serta task `read_data` dan `display` berhasil didaftarkan ke dalam sistem[cite: 216].
* [cite_start]Aliran Multitasking & Scheduler: Penjadwal tugas (*kernel scheduler*) berfungsi dengan baik untuk membagi waktu eksekusi secara konkuren antara task pengirim dan task penerima data[cite: 199, 201].
* [cite_start]Pengiriman Data Antrean: Task `read_data` secara periodik mampu mengemas data indikator dan mengirimkan struktur data tersebut ke dalam antrean[cite: 224, 228].
* [cite_start]Output Visual Monitor: Task `display` berhasil menangkap paket data dari antrean secara sukses (`pdPASS`) [cite: 234] [cite_start]dan menampilkannya sebagai output informasi suhu serta kelembapan pada layar Serial Monitor secara statis[cite: 200, 235, 236, 237, 238, 242].

## ♻️ Langkah Percobaan
1. [cite_start]Persiapan Perangkat Keras: Siapkan papan Arduino Uno dan hubungkan ke komputer menggunakan kabel USB sebagai debugger dan media output data, karena percobaan antrean awal ini hanya memanfaatkan komunikasi internal sistem[cite: 205, 245].
2. [cite_start]Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program lengkap yang memuat library `#include <Arduino_FreeRTOS.h>` dan `#include <queue.h>` [cite: 207][cite_start], deklarasi tipe `struct readings` [cite: 208][cite_start], pembuatan fungsi pengirim `read_data` [cite: 223], serta fungsi penerima data `display`[cite: 231].
3. [cite_start]Inisialisasi Sistem: Pastikan perintah pembuatan antrean `xQueueCreate()` dan pendaftaran tugas `xTaskCreate()` sudah dikonfigurasi dengan tepat di dalam fungsi `setup()` [cite: 216][cite_start], serta fungsi `loop()` dibiarkan kosong karena kendali penuh dialihkan ke kernel FreeRTOS[cite: 217].
4. [cite_start]Unggah Program: Lakukan kompilasi (*compile*) program untuk memastikan seluruh baris kode bebas dari kesalahan [cite: 246][cite_start], simpan sketch dengan nama file `modul6_taskqueue` [cite: 243][cite_start], kemudian unggah (*upload*) program ke dalam papan Arduino board[cite: 246].
5. [cite_start]Pengamatan dan Analisis: Buka Serial Monitor di Arduino IDE dengan kecepatan transmisi 9600 baud [cite: 215][cite_start], perhatikan kesesuaian output data teks *temperature* dan *humidity* yang tercetak [cite: 235, 237][cite_start], lalu berikan analisis hasil percobaan tersebut untuk dituliskan pada Buku Catatan Praktikum[cite: 247].