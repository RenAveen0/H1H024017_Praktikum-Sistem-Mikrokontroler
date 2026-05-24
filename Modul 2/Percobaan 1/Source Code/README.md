# Source Code - Percobaan 2A: Seven Segment (Output)

Folder ini berisi kode program untuk menampilkan karakter heksadesimal (0-F) secara berurutan menggunakan array pola segmen pada Seven Segment Display berbasis Arduino Uno.

## 📄 Penjelasan Logika Program

Kode program bekerja dengan memanfaatkan array untuk menyimpan pola biner yang akan direpresentasikan menjadi informasi visual pada layar seven segment. Berikut adalah alur logikanya:

1. Inisialisasi Awal:
   * Seluruh pin digital Arduino yang terhubung ke segmen display dikonfigurasi sebagai `OUTPUT`.
   * Pola logika biner untuk menampilkan karakter 0 hingga F disimpan dalam array dua dimensi `digitPattern[16][8]`.
   * Variabel `currentDigit` diatur dengan nilai awal 0.

2. Siklus Tampilan (Looping):
   * Program mengambil pola bit dari array konstanta berdasarkan indeks `currentDigit` dan menyalakannya melalui fungsi `displayDigit()`.
   * Karena menggunakan display tipe Common Anode, program menerapkan logika *active low* dengan operator NOT (`!`) sehingga segmen akan menyala saat pin Arduino mengirimkan sinyal `LOW`.
   * Setiap karakter ditampilkan dengan interval jeda (delay) tertentu sebelum berpindah ke karakter selanjutnya.

3. Evaluasi Kondisi:
   * Nilai variabel `currentDigit` akan bertambah satu (increment) pada setiap akhir siklus perulangan.
   * Ketika nilai `currentDigit` melebihi 15, program akan mereset nilainya kembali ke 0. Proteksi ini berfungsi untuk mencegah error akibat mengakses indeks memori di luar jangkauan array (*out-of-bounds access*).

## 🛠️ Konfigurasi Pin
| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| Segmen a | Pin 7 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen b | Pin 6 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen c | Pin 5 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen d | Pin 11 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen e | Pin 10 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen f | Pin 8 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen g | Pin 9 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |
| Segmen dp | Pin 4 | `OUTPUT` | Dihubungkan melalui resistor 220 Ω pembatas arus. |