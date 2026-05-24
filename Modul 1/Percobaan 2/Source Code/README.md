# Source Code - Percobaan 2A: Perulangan (`for`)

Folder ini berisi kode program untuk mengendalikan beberapa LED secara sekuensial guna menciptakan efek lampu berjalan (*running LED*) menggunakan struktur kontrol perulangan pada Arduino Uno.

## 📄 Penjelasan Logika Program

Kode pada `modul1_perulangan.ino` bekerja dengan memanfaatkan loop `for` untuk memanipulasi urutan pin digital secara otomatis dan efisien. Berikut adalah alur logikanya:

1. Inisialisasi Awal:
   * Program menggunakan loop `for` pada bagian `setup()` untuk mengonfigurasi Pin Digital 2 hingga Pin Digital 7 sebagai `OUTPUT` secara sekaligus tanpa menulis baris kode satu per satu.

2. Pergerakan Maju (Kiri ke Kanan):
   * Blok `for` pertama menggunakan logika penambahan (*incremental*). Variabel `ledPin` bergerak naik dari nilai 2 hingga kurang dari 8 (Pin 2 $\rightarrow$ 7).
   * Pada setiap iterasi, LED pada pin aktif akan dinyalakan (`HIGH`), ditahan sesuai durasi variabel `timer`, lalu dimatikan (`LOW`) sebelum berpindah ke pin berikutnya. Ini menciptakan efek visual cahaya berjalan ke kanan.

3. Pergerakan Mundur (Kanan ke Kiri):
   * Setelah loop pertama selesai, blok `for` kedua langsung dieksekusi dengan logika pengurangan (*decremental*). Variabel `ledPin` bergerak turun dari nilai 7 hingga lebih besar atau sama dengan 2 (Pin 7 $\rightarrow$ 2).
   * Proses penyalaan sekuensial ini membalikkan arah gerakan cahaya dari kanan kembali ke kiri, sehingga menghasilkan efek pantulan (*bounce effect*) yang berulang secara kontinu di dalam fungsi `loop()`.

## 🛠️ Konfigurasi Pin
| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| LED 1 (Kiri) | Pin 2 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |
| LED 2 | Pin 3 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |
| LED 3 | Pin 4 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |
| LED 4 | Pin 5 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |
| LED 5 | Pin 6 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |
| LED 6 (Kanan) | Pin 7 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |