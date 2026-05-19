# Modul 1 : Percabangan dan Perulangan

## 🎯 Tujuan Praktikum

1. Memahami konsep dasar percabangan (`if`, `if-else`) dan perulangan (`while`, `for`) pada mikrokontroler.
2. Mengimplementasikan struktur kontrol tersebut untuk mengendalikan komponen fisik (LED) secara responsif.

## 📄 Dasar Teori

Struktur kontrol digunakan untuk mengatur alur eksekusi program berdasarkan kondisi atau kebutuhan repetisi tertentu, yang diimplementasikan menggunakan indikator visual LED.

1. Percabangan \
Digunakan untuk mengambil keputusan jalurnya eksekusi kode berdasarkan evaluasi kondisi tertentu.
* `if` (Kondisi Tunggal): Aksi hanya dieksekusi jika kondisi bernilai benar (`true`).
  ```cpp
  if (kondisi) { // aksi }
  ```
* `if-else` (Dua Kondisi): Menyediakan jalur alternatif (`else`) jika kondisi utama tidak terpenuhi (`false`)
  ```cpp
  if (kondisi) { // aksi jika benar } else { // aksi jika salah }
  ```

2. Perulangan \
Digunakan untuk mengeksekusi blok kode secara berulang demi meningkatkan efisiensi dan meringkas penulisan kode.  
* `for`: Digunakan ketika jumlah iterasi sudah diketahui secara pasti (memiliki inisialisasi, syarat, dan perubahan nilai). 
  ```cpp
  for (inisialisasi; syarat; perubahan) { // aksi }
  ```
* `while`: Melakukan perulangan berdasarkan kondisi tertentu, di mana jumlah iterasinya tidak dapat ditentukan secara pasti di awal.
  ```cpp
  while (kondisi) { // aksi }
  ```

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)

## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>Breadboard</th>
    <th>LED</th>
    <th>Resistor</th>
    <th>Kabel Jumper</th>
    <th>Kabel USB Type B</th>
  </tr>

  <tr align="center">
    <td>
      <img width="150" height="150" alt="img1" src="../Modul 1/Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Modul 1/Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Modul 1/Laporan Praktikum/Komponen/led.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Modul 1/Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Modul 1/Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Modul 1/Laporan Praktikum/Komponen/kabel usb type b.jpeg"><br>
    </td>
  </tr>
</table>
</div>

## 💻 Percobaan

Eksperimen pada modul ini dibagi menjadi dua skenario utama untuk mengamati interaksi antara logika program komputer dengan respons fisik perangkat keras.

1. Percobaan 1A: Logika Percabangan (`if-else`)
Eksperimen ini menguji kemampuan mikrokontroler dalam mengambil keputusan secara dinamis berdasarkan perubahan nilai variabel internal.
* Skenario: Mengatur interval kedipan satu buah LED pada Pin Digital 6.
* Aliran Program: Nilai `timeDelay` berkurang 100 ms di setiap iterasi (kedipan makin cepat). Ketika `timeDelay` mencapai $\le 100\text{ ms}$, program mendeteksi kondisi batas melalui blok `if`, memberikan jeda konstan selama 3 detik, lalu mereset interval kembali ke 1000 ms.

2. Percobaan 2A: Logika Perulangan (`for`)
Eksperimen ini menguji efisiensi pengendalian banyak output digital secara sekuensial tanpa menuliskan baris kode yang berulang.
* Skenario: Mengendalikan urutan aktif 6 buah LED yang berjajar pada Pin Digital 2 sampai 7.
* Aliran Program:  Loop `for` pertama mengalirkan logika `HIGH` secara inkremental dari pin terkecil ke terbesar (efek gerakan dari kiri ke kanan).

## 📚 Pertanyaan Praktikum

### A. Percabangan
1. Pada kondisi apa program masuk ke blok if? 
2. Pada kondisi apa program masuk ke blok else? 
3. Apa fungsi dari perintah delay(timeDelay)? 
4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati), ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang → mati dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

**Jawaban**
1. Program masuk ke blok if saat nilai timeDelay mencapai 100 atau kurang. Ini berfungsi untuk memicu jeda panjang (3 detik) dan mereset kecepatan kedipan kembali ke awal (1000ms).
2. Program masuk ke blok else selama nilai timeDelay masih di atas 100. Di sini, program akan terus mengurangi nilai delay sebesar 100ms di setiap putaran agar kedipan LED semakin cepat.
3. Berfungsi untuk memberi jeda waktu (dalam milidetik) sesuai nilai variabel timeDelay. Perintah ini menentukan berapa lama LED tetap menyala atau mati, yang secara langsung mengatur kecepatan kedipan LED.
4. Program ini mengontrol kecepatan kedipan LED pada Pin 6 agar berubah dari lambat ke cepat, lalu kembali dari cepat ke lambat secara bertahap.

Kode Program

```cpp
const int ledPin = 6;
int timeDelay = 100; // Mulai dari 100ms (paling cepat)

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Menyalakan LED
    digitalWrite(ledPin, HIGH);
    delay(timeDelay);
    
    // Mematikan LED
    digitalWrite(ledPin, LOW);
    delay(timeDelay);

    // Logika Perubahan Kecepatan
    if (timeDelay >= 1000) {
        // Jika sudah mencapai 1000ms (paling lambat)
        delay(3000);        // Berhenti sejenak selama 3 detik dalam kondisi mati
        timeDelay = 100;    // Reset kembali ke 100ms (cepat)
    } else {
        // Jika belum mencapai 1000ms, tambah delay-nya
        timeDelay += 100;   // Menambah 100ms setiap putaran (makin lambat)
    }
}
```
<img width="600" height="300" alt="img1" src="../Modul 1/Percobaan 1/Dokumentasi/Percabanganver2.gif">

### B. Perulangan
1. Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan! 
2. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan! 
3. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri!
4. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

**Jawaban**
1. Setiap LED disusun secara paralel dengan urutan:
 - Anoda (+): Terhubung ke Pin Digital Arduino (Pin 2 hingga Pin 7).
 - Katoda (-): Terhubung ke Resistor 220 $\Omega$, lalu ke Ground (GND).
2. Efek ini dihasilkan oleh perulangan for dengan logika penambahan (++):
 - Kode: ```for (int ledPin = 2; ledPin < 8; ledPin++)```
 - Cara Kerja: Program menyalakan LED satu per satu mulai dari nomor pin kecil ke besar (2 $\rightarrow$ 3 $\rightarrow$ 4 $\rightarrow$ 5 $\rightarrow$ 6 $\rightarrow$ 7). Secara fisik, ini menciptakan gerakan cahaya dari kiri ke kanan.
3. Efek ini dihasilkan oleh perulangan for dengan logika pengurangan (--):
 - Kode: ```for (int ledPin = 7; ledPin >= 2; ledPin--)```
 - Cara Kerja: Program menyalakan LED mulai dari nomor pin besar ke kecil (7 $\rightarrow$ 6 $\rightarrow$ 5 $\rightarrow$ 4 $\rightarrow$ 3 $\rightarrow$ 2). Secara fisik, arah cahaya akan tampak berbalik dari kanan kembali ke kiri.
4. Program ini mengontrol dua kelompok LED (3 kiri dan 3 kanan) untuk menyala secara bergantian menggunakan perulangan `for`.

Kode Program
```cpp
int timer = 500; // Menentukan durasi kedipan (500ms agar perpindahan terlihat jelas)

void setup() {
    // Inisialisasi pin 2 sampai 7 sebagai output menggunakan loop
    for (int ledPin = 2; ledPin < 8; ledPin++) {
        pinMode(ledPin, OUTPUT); // Mengatur pin ledPin (2-7) sebagai OUTPUT
    }
}

void loop() {
    // Tahap 1: Menyalakan tiga LED kiri (Pin 2, 3, 4)
    
    for (int ledPin = 2; ledPin <= 4; ledPin++) {
        digitalWrite(ledPin, HIGH); // Menghidupkan LED di pin 2, 3, dan 4
    }
    for (int ledPin = 5; ledPin <= 7; ledPin++) {
        digitalWrite(ledPin, LOW);  // Memastikan LED di pin 5, 6, dan 7 mati
    }
    delay(timer); // Menahan posisi ini selama waktu di variabel timer


    // Tahap 2: Menyalakan tiga LED kanan (Pin 5, 6, 7)
    
    for (int ledPin = 2; ledPin <= 4; ledPin++) {
        digitalWrite(ledPin, LOW);  // Mematikan LED di pin 2, 3, dan 4
    }
    for (int ledPin = 5; ledPin <= 7; ledPin++) {
        digitalWrite(ledPin, HIGH); // Menghidupkan LED di pin 5, 6, dan 7
    }
    delay(timer); // Menahan posisi ini selama waktu di variabel timer
}
```
<img width="600" height="300" alt="img2" src="../Modul 1/Percobaan 2/Dokumentasi/Perulanganver2.gif">