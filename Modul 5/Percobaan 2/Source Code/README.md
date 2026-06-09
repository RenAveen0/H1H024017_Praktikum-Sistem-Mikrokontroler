# Source Code - Percobaan 5B: Komunikasi Task Menggunakan Queue

Folder ini berisi kode program untuk mengimplementasikan konsep komunikasi antar-task (*inter-task communication*) secara aman menggunakan fitur Queue (Antrean) pada FreeRTOS di Arduino Uno. Program ini mendemonstrasikan bagaimana data terstruktur dapat dikirim dari satu task produsen dan diterima oleh task konsumen tanpa risiko tumpang-tindih data.

## 📄 Penjelasan Logika Program

Kode program bekerja dengan memanfaatkan mekanisme antrean berbasis FIFO (*First In, First Out*) untuk melewatkan data berupa struktur (*struct*) antar-task. Berikut adalah alur logikanya:

1. Inisialisasi & Pembuatan Objek Queue:
   * Library `<Arduino_FreeRTOS.h>` dan `<queue.h>` disertakan untuk mengaktifkan fungsi penjadwalan OS dan manajemen antrean data.
   * Dibuat sebuah tipe data terstruktur (`struct readings`) yang memuat dua variabel integer, yaitu `temp` (suhu) dan `h` (kelembapan).
   * Pada fungsi `setup()`, antrean `my_queue` dibuat menggunakan perintah `xQueueCreate(1, sizeof(struct readings))` untuk menampung maksimal 1 paket data berukuran struktur tersebut. Dua task utama (`read_data` dan `display`) didaftarkan dengan prioritas setara (0).

2. Skenario Produksi Data (Task `read_data`):
   * Task ini berfungsi menyimulasikan pengambilan data sensor di dalam perulangan *infinite loop* (`for(;;)`). 
   * Nilai statis dimasukkan ke dalam variabel struktur `x` (`x.temp = 54` dan `x.h = 30`). Data tersebut kemudian dikirim masuk ke dalam antrean menggunakan fungsi `xQueueSend(my_queue, &x, portMAX_DELAY)`. 
   * Argumen `portMAX_DELAY` memastikan task akan menunggu (block) jika antrean penuh hingga ruang tersedia. Setelah berhasil mengirim, task dialihkan ke kondisi tidur selama 100 ms lewat fungsi `vTaskDelay()`.

3. Skenario Konsumsi & Visualisasi Data (Task `display`):
   * Task ini bertugas memantau dan mengambil data dari antrean secara terus-menerus menggunakan fungsi `xQueueReceive(my_queue, &x, portMAX_DELAY)`.
   * Jika fungsi mendeteksi adanya data masuk dan sukses mengambilnya (`pdPASS`), data di dalam struktur `x` akan diekstrak. Nilai `temp` dan `humidity` tersebut kemudian dicetak secara berurutan ke layar komputer melalui perintah komunikasi serial.

4. Siklus Kerja Sistem:
   * Fungsi `loop()` dikosongkan secara penuh karena manajemen alokasi waktu pemrosesan data dan pergantian eksekusi tugas sepenuhnya dikendalikan oleh kernel scheduler FreeRTOS.

## 🛠️ Konfigurasi Pin

*Catatan: Pada percobaan dasar komunikasi antrean ini, seluruh pemrosesan dan pertukaran data dilakukan secara internal di dalam sistem mikrokontroler sehingga tidak melibatkan pin I/O eksternal.*

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| Arduino Uno | Port USB | — | Jalur catu daya utama serta media penghubung data ke PC/Laptop. |
| Serial Monitor | RX / TX (Internal) | `9600 bps` | Antarmuka komunikasi serial untuk menampilkan output data suhu dan kelembapan secara *real-time*. |