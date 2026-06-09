# Source Code - Percobaan 5A: Multitasking Menggunakan FreeRTOS

Folder ini berisi kode program untuk mengimplementasikan konsep multitasking pada sistem embedded menggunakan FreeRTOS pada Arduino Uno. Program ini menjalankan tiga buah task secara bersamaan (concurrent) untuk mengendalikan kedipan dua buah LED dengan interval berbeda serta melakukan kalkulasi counter secara *non-blocking*.

## 📄 Penjelasan Logika Program

Kode program bekerja dengan memanfaatkan *Kernel Scheduler* dari FreeRTOS untuk membagi waktu kerja CPU secara adil ke masing-masing task. Berikut adalah alur logikanya:

1. Inisialisasi Awal & Pembuatan Task: 
   * Library `<Arduino_FreeRTOS.h>` disertakan untuk menyediakan ekosistem Real-Time Operating System.
   * Komunikasi serial diaktifkan pada fungsi `setup()` dengan kecepatan data 9600 bps menggunakan `Serial.begin(9600)`.
   * Tiga buah fungsi task (`TaskBlink1`, `TaskBlink2`, dan `Taskprint`) didaftarkan ke sistem menggunakan perintah `xTaskCreate()`. Masing-masing diberikan alokasi stack sebesar 128 kata dan tingkat prioritas yang sama (1).
   * Penjadwal tugas dijalankan secara otomatis lewat perintah `vTaskStartScheduler()`. Fungsi `loop()` dibiarkan kosong karena manajemen siklus kerja sepenuhnya diambil alih oleh kernel FreeRTOS.

2. Eksekusi TaskBlink1 (LED Merah - Pin 8):
   * Pin Digital 8 dikonfigurasi sebagai `OUTPUT`. Di dalam loop tak terbatas (`while(1)`), task ini mengirimkan teks "Task1" ke Serial Monitor, mengubah status pin 8 menjadi `HIGH` (LED menyala), lalu mengalami masa *suspend* (jeda waktu tidur) selama 200 ms menggunakan fungsi *non-blocking* `vTaskDelay(200 / portTICK_PERIOD_MS)` sebelum akhirnya mematikan LED kembali dengan jeda yang sama.

3. Eksekusi TaskBlink2 (LED Kuning - Pin 7):
   * Pin Digital 7 dikonfigurasi sebagai `OUTPUT`. Memiliki struktur kerja yang sama dengan Task1, namun bekerja secara independen untuk mengontrol kedipan LED Kuning pada pin 7 dengan jeda waktu aktif dan mati masing-masing selama 300 ms (`vTaskDelay(300 / portTICK_PERIOD_MS)`).

4. Eksekusi Taskprint (Counter Data):
   * Variabel lokal `counter` diinisialisasi dari angka 0. Di dalam loop, nilai variabel ini akan terus bertambah secara bertahap (+1), dicetak langsung ke layar Serial Monitor, lalu ditunda selama 500 ms menggunakan `vTaskDelay(500 / portTICK_PERIOD_MS)` sebelum melakukan perulangan berikutnya.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| LED Merah (Anoda) | Pin 8 | `OUTPUT` | Pin digital output untuk mengontrol status daya kedipan LED Merah (Task1). |
| LED Kuning (Anoda) | Pin 7 | `OUTPUT` | Pin digital output untuk mengontrol status daya kedipan LED Kuning (Task2). |
| LED Merah & Kuning (Katoda) | GND | — | Dihubungkan ke pin Ground melalui Resistor 220 Ω sebagai pembatas arus. |