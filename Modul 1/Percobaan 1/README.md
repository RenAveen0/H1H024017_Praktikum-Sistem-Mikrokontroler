# Percobaan 1: Logika Percabangan (`if-else`)

Dokumentasi ini memuat detail pelaksanaan Percobaan 1 mengenai implementasi struktur kontrol percabangan tunggal dan ganda pada mikrokontroler Arduino Uno.

## 🎯 Tujuan
1. Memahami cara kerja dan sintaksis struktur kontrol `if` dan `if-else` dalam pemrograman mikrokontroler.
2. Mengimplementasikan logika percabangan untuk memanipulasi variabel interval waktu (`delay`) secara dinamis.
3. Mengamati dan menganalisis respons fisik output LED terhadap perubahan kondisi logika di dalam program.

## 💡 Spesifikasi yang Diharapkan
* Kondisi Awal: LED pada Pin Digital 6 berkedip dengan interval lambat sebesar 1000 ms (1 detik).
* Perubahan Dinamis: Setiap kali LED menyelesaikan satu siklus kedipan penuh (nyala-mati), nilai interval waktu (`timeDelay`) berkurang sebesar 100 ms secara bertahap, membuat kedipan LED tampak semakin cepat.
* Kondisi Batas & Reset: Ketika kecepatan kedipan sudah sangat cepat hingga mencapai nilai `timeDelay` $\le$ 100 ms, sistem akan mendeteksi kondisi tersebut, menahan posisi LED mati selama 3000 ms (3 detik) sebagai jeda pemisah, lalu mereset nilai interval kembali ke 1000 ms untuk memulai ulang pola.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan kaki Anoda (+) LED ke Pin Digital 6 pada Arduino Uno.
   * Hubungkan kaki Katoda (-) LED ke Resistor 220 $\Omega$, lalu hubungkan ujung resistor lainnya ke pin Ground (GND) Arduino.
2. Koneksi Perangkat: Hubungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Type B.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik atau muat kode program percabangan yang telah disiapkan pada berkas `code.ino`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada *error*, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan & Dokumentasi: Amati perubahan ritme kedipan LED dari lambat ke cepat hingga momen terjadinya reset (jeda 3 detik), lalu ambil dokumentasi berupa video atau GIF sebagai bukti hasil percobaan.