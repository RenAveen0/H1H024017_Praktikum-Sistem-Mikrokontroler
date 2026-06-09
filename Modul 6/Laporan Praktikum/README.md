# Modul

### 📋 Informasi Praktikum
Nama: Hana Nur Fathiyyah\ 
NIM: H1H024017\
Nama Asisten Praktikum: Billy Hermawan\
Tanggal Percobaan: 12 Mei 2026\
Ruangan: Laboratorium Baru\
Jurnal: 

### 🔍 Ringkasan Percobaan
1. Percobaan 6A: External Interrupt\
**Tujuan:** Mengendalikan status aktif/nonaktif LED menggunakan mekanisme *external interrupt* melalui penekanan *push button* tanpa memerlukan proses *polling* secara terus-menerus.\
**Hasil:** Sistem secara instan mampu menangkap perubahan sinyal digital (*falling edge*) pada pin input digital 2 saat tombol ditekan. Mikrokontroler berhasil menghentikan sementara alur program utama untuk mengeksekusi fungsi ISR (`tombolInterrupt`) yang melakukan operasi *toggle* pada variabel `volatile bool ledState`. Hal ini membuat status LED pada pin 13 berubah secara responsif dan efisien tanpa membebani kinerja CPU.

2. Percobaan 6B: Timer Menggunakan `millis()`\
**Tujuan:** Membuat lampu LED berkedip (*blinking*) secara periodik dengan memanfaatkan fungsi pewaktu internal `millis()` sebagai metode *non-blocking* pengganti fungsi `delay()`.\
**Hasil:** Sistem berhasil memantau pencatatan waktu berjalan sejak papan Arduino mulai dinyalakan. Melalui perhitungan selisih waktu konstan (`currentMillis - previousMillis >= interval`), program sukses mengontrol siklus kedipan LED pada pin 13 setiap 1000 ms secara presisi. Karena tidak menggunakan fungsi `delay()`, siklus eksekusi di dalam `loop()` tetap berjalan bebas sehingga sistem tetap responsif dalam menangani instruksi multitasking lainnya.

### 🛠️ Komponen Utama yang Digunakan
<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>Push Button</th>
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
      <img width="150" height="150" alt="img2" src="../Laporan Praktikum/Komponen/push button.jpg"><br>
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