# Source Code - Percobaan 6A: External Interrupt

Folder ini berisi kode program untuk mengendalikan status aktif atau nonaktif lampu LED menggunakan mekanisme *external interrupt* melalui penekanan *push button*. Metode ini memungkinkan mikrokontroler untuk merespon input tombol secara instan (*real-time*) tanpa perlu melakukan pengecekan kondisi secara terus-menerus di dalam program utama (*polling*).

## 📄 Penjelasan Logika Program

Kode program bekerja dengan memanfaatkan pin interupsi fisik pada Arduino Uno untuk mengalihkan jalurnya secara otomatis saat mendeteksi perubahan logika. Berikut adalah alur logikanya:

1. Deklarasi Variabel Volatile:
   * Variabel `ledState` dideklarasikan menggunakan kata kunci `volatile`. Hal ini bertujuan untuk menginstruksikan *compiler* agar selalu membaca nilai variabel langsung dari RAM (bukan dari register CPU cache), karena nilainya diubah di dalam fungsi ISR yang berada di luar alur normal program utama.

2. Konfigurasi Perangkat Keras (`setup()`):
   * Pin Digital 13 diatur sebagai `OUTPUT` tempat kaki anoda lampu LED terhubung.
   * Pin Digital 2 diatur sebagai `INPUT_PULLUP`. Mode ini mengaktifkan resistor *pull-up* internal Arduino, memastikan pin bernilai `HIGH` (kondisi default) saat tombol dilepas dan beralih ke `LOW` saat tombol ditekan ke Ground.

3. Pendaftaran Fungsi Interrupt:
   * Fungsi `attachInterrupt(digitalPinToInterrupt(2), tombolInterrupt, FALLING)` digunakan untuk mendaftarkan Pin 2 sebagai jalur *external interrupt*. 
   * Mode pemicu diatur ke `FALLING`, yang berarti interupsi hanya akan aktif tepat pada momen transisi sinyal berubah dari tinggi ke rendah (`HIGH` ke `LOW`), yaitu saat *push button* ditekan.

4. Eksekusi ISR dan Siklus Utama (`loop()`):
   * Ketika tombol ditekan, program utama akan dihentikan sesaat oleh kernel untuk mengeksekusi fungsi ISR `tombolInterrupt()`. Di dalam fungsi ini, status logika `ledState` akan dibalik (*toggle*) dari `false` menjadi `true` atau sebaliknya.
   * Setelah fungsi ISR selesai, program kembali melanjutkan siklus di dalam fungsi `loop()` dan memperbarui kondisi fisik LED secara kontinu menggunakan perintah `digitalWrite(13, ledState)`.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| Push Button (Kaki Sinyal) | Pin 2 | `INPUT_PULLUP` | Pin input interupsi fisik (Interrupt 0) untuk mendeteksi penekanan tombol. |
| Push Button (Kaki Ground) | GND | — | Jalur referensi negatif untuk menarik sinyal menjadi `LOW` saat ditekan. |
| LED (Anoda) | Pin 13 | `OUTPUT` | Pin output digital untuk mengontrol status aktif/nonaktif LED. |
| LED (Katoda) | GND | — | Dihubungkan ke pin Ground melalui Resistor 220 Ω sebagai pembatas arus. |