# Modul 5

### 📋 Informasi Praktikum
Nama: Hana Nur Fathiyyah\ 
NIM: H1H024017\
Nama Asisten Praktikum: Billy Hermawan\
Tanggal Percobaan: 5 Mei 2026\
Ruangan: Laboratorium Baru\
Jurnal: https://drive.google.com/file/d/11SHRkat3G648P_TGkrhL0GMlrwalOYbw/view?usp=drive_link

### 🔍 Ringkasan Percobaan
1. Percobaan 5A: Multitasking\
**Tujuan:** Memahami konsep multitasking pada sistem embedded menggunakan FreeRTOS di Arduino dan menjalankan beberapa task secara concurrent dengan fungsi `xTaskCreate()`.\
**Hasil:** Sistem berhasil mengeksekusi tiga task mandiri secara bersamaan (concurrent) di bawah manajemen *Kernel Scheduler*. Task1 sukses mengontrol kedipan LED Merah pada pin 8 dengan interval waktu 200 ms, Task2 mengontrol LED Kuning pada pin 7 dengan interval waktu 300 ms, dan Task3 secara berkala melakukan kalkulasi *increment* variabel counter lalu menampilkannya ke Serial Monitor setiap 500 ms menggunakan fungsi *non-blocking* `vTaskDelay()`.

2. Percobaan 5B: Komunikasi Task\
**Tujuan:** Memahami konsep manajemen komunikasi dan pengiriman pertukaran paket data antar task yang berjalan konkuren menggunakan fitur antrean (Queue) pada FreeRTOS.\
**Hasil:** Sistem berhasil menerapkan mekanisme *inter-task communication* secara aman lewat interaksi objek antrean `my_queue`. Task `read_data` sukses mengemas dan mengirimkan struktur data `readings` berupa data indikator suhu (54) serta kelembapan (30) menggunakan fungsi `xQueueSend()`, yang kemudian ditangkap secara responsif oleh task `display` melalui fungsi `xQueueReceive()` untuk divisualisasikan langsung ke Serial Monitor tanpa kendala tumpang-tindih data.


### 🛠️ Komponen Utama yang Digunakan
<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>DHT22</th>
    <th>Potensiometer 10 kΩ</th>
    <th>Resistor 220 Ω</th>
    <th>LED</th>
    <th>Breadboard</th>
    <th>Kabel Jumper</th>
  </tr>

  <tr align="center">
    <td>
      <img width="150" height="150" alt="img1" src="../Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Laporan Praktikum/Komponen/dht22.jpg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Laporan Praktikum/Komponen/potensiometer.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Laporan Praktikum/Komponen/led.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img7" src="../Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>