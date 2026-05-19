# Percobaan 2: Logika Perulangan (`for`)

Dokumentasi ini memuat detail pelaksanaan Percobaan 2 mengenai implementasi struktur kontrol perulangan sekuensial (inkremental dan dekremental) menggunakan Arduino Uno.

## 🎯 Tujuan
1. Memahami cara kerja, sintaksis, dan efisiensi struktur kontrol perulangan `for` dalam pemrograman mikrokontroler.
2. Mengimplementasikan logika perulangan untuk mengendalikan banyak pin output secara berurutan (*sekuensial*).
3. Mengamati dan menganalisis efek pergerakan visual (*running LED*) yang dihasilkan oleh manipulasi urutan pin digital.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Pin: Mengendalikan 6 buah LED yang terhubung secara paralel pada Pin Digital 2 hingga Pin Digital 7.
* Efek Gerakan Maju (Kiri ke Kanan): Program memanfaatkan perulangan `for` pertama untuk mengalirkan status `HIGH` dan `LOW` secara bergantian dari pin terkecil (Pin 2) ke pin terbesar (Pin 7). Hal ini menghasilkan efek visual lampu berjalan maju.
* Efek Gerakan Mundur (Kanan ke Kiri): Program memanfaatkan perulangan `for` kedua dengan logika pengurangan untuk mengalirkan status dari pin terbesar (Pin 7) kembali ke pin terkecil (Pin 2). Kombinasi kedua perulangan ini menciptakan efek pantulan (*bounce effect*) yang bergerak terus-menerus.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras: 
   * Susun 6 buah LED secara berjajar pada *breadboard*.
   * Hubungkan masing-masing kaki Anoda (+) dari ke-6 LED tersebut ke Pin Digital 2, 3, 4, 5, 6, dan 7 pada Arduino Uno menggunakan kabel jumper.
   * Hubungkan setiap kaki Katoda (-) LED ke Resistor 220 $\Omega$, lalu hubungkan seluruh ujung resistor lainnya ke jalur massa/Ground (GND) Arduino.
2. Koneksi Perangkat: Hubungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Type B.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik atau muat kode program perulangan yang telah disiapkan pada berkas `code.ino`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk mengecek ada tidaknya kesalahan sintaksis, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan & Dokumentasi: Amati pergerakan cahaya LED yang berjalan bolak-balik dari kiri ke kanan lalu kanan ke kiri secara beraturan, kemudian ambil dokumentasi berupa video atau GIF sebagai bukti hasil percobaan.