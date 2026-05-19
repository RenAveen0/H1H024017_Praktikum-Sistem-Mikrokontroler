# Source Code - Percobaan 1A: Percabangan (`if-else`)

Folder ini berisi kode program untuk mengatur interval kedipan LED secara dinamis menggunakan struktur kontrol percabangan pada Arduino Uno.

## 📄 Penjelasan Logika Program

Kode pada `modul1_percabangan.ino` bekerja dengan memanipulasi variabel `timeDelay` secara bertahap setelah LED menyelesaikan satu siklus kedipan penuh (nyala-mati). Berikut adalah alur logikanya:

1. Inisialisasi Awal: LED dikonfigurasi pada Pin Digital 6 sebagai `OUTPUT`.
   * Variabel global `timeDelay` diatur pada nilai awal 1000 ms (1 detik).

2. Siklus Kedipan (Looping):
   * Program menyalakan LED (`HIGH`), menahan sesuai durasi `timeDelay`, lalu mematikan LED (`LOW`), dan menahannya kembali.

3. Evaluasi Kondisi (Percabangan):
   * Blok `else`: Jika `timeDelay` masih bernilai di atas 100 ms, program akan mengurangi nilainya sebanyak 100 ms pada setiap akhir siklus. Hal ini menyebabkan kedipan LED menjadi semakin cepat secara bertahap.
   * Blok `if`: Ketika kedipan sudah mencapai batas tercepat (nilai `timeDelay` $\le$ 100 ms), program akan memberikan jeda statis selama 3000 ms (3 detik) sebagai pemisah siklus. Setelah itu, nilai `timeDelay` akan direset kembali ke 1000 ms untuk memulai ulang pola dari awal.

## 🛠️ Konfigurasi Pin
| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| LED Merah | Pin 6 | `OUTPUT` | Dihubungkan melalui Resistor 220 $\Omega$ ke GND. |