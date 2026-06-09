# Source Code - Percobaan 6B: Timer Menggunakan `millis()`

Folder ini berisi kode program untuk membuat lampu LED berkedip (*blinking*) secara periodik menggunakan fungsi pewaktu internal `millis()`. Pendekatan ini merupakan metode *non-blocking* yang efisien untuk menggantikan fungsi `delay()`, sehingga mikrokontroler tetap dapat memproses instruksi lain secara simultan tanpa mengalami pembekuan eksekusi program (*freezing*).

## 📄 Penjelasan Logika Program

Kode program bekerja dengan membandingkan selisih waktu berjalan terhadap interval target yang telah ditentukan. Berikut adalah alur logikanya:

1. Inisialisasi Variabel Global:
   * Variabel `previousMillis` dideklarasikan dengan tipe data `unsigned long` (kapasitas penyimpanan besar) untuk mencatat basis waktu terakhir saat LED berubah status.
   * Konstanta `interval` diatur pada nilai 1000 ms (1 detik) sebagai parameter durasi kondisi aktif dan mati dari LED.
   * Variabel `ledState` bertipe boolean diinisialisasi dengan nilai `false` sebagai penanda kondisi awal LED mati.

2. Konfigurasi Awal (`setup()`):
   * Pin Digital 13 dikonfigurasi sebagai `OUTPUT` tempat komponen lampu LED terpasang pada papan Arduino Uno.

3. Pengambilan Waktu Aktual (*Time Tracking*):
   * Di dalam fungsi `loop()`, mikrokontroler secara kontinu mengambil catatan waktu berjalan sejak sistem pertama kali dinyalakan menggunakan fungsi `millis()`. Nilai tersebut disimpan ke dalam variabel lokal `currentMillis`.

4. Pemeriksaan Kondisi dan Operasi Toggle:
   * Program melakukan evaluasi menggunakan operasi pengurangan: `if (currentMillis - previousMillis >= interval)`.
   * Jika selisih waktu aktual dengan waktu terakhir belum mencapai 1000 ms, program langsung melewati blok kondisi tersebut sehingga CPU bebas mengeksekusi kode program lainnya.
   * Jika selisih waktu sudah mencapai atau melewati 1000 ms, maka blok kondisi dieksekusi:
     * Nilai `previousMillis` diperbarui dengan nilai `currentMillis` saat ini untuk menyegarkan titik awal hitungan siklus berikutnya.
     * Status logika `ledState` dibalik (*toggle*) menggunakan operator ingkaran (`!ledState`), mengubah `false` menjadi `true` atau sebaliknya.
     * Perintah `digitalWrite(13, ledState)` mengirimkan sinyal daya digital baru ke pin 13 sehingga LED berkedip tepat waktu.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| LED (Anoda) | Pin 13 | `OUTPUT` | Pin digital output utama untuk mengontrol status aktif/nonaktif kedipan LED. |
| LED (Katoda) | GND | — | Dihubungkan ke pin Ground melalui Resistor 220 Ω sebagai pembatas arus. |