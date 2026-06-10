# Modul 6 : Interrupt dan Timer

## 🎯 Tujuan Praktikum

1. Memahami prinsip dasar, mekanisme kerja, dan keunggulan dari fungsi *hardware interrupt* serta komponen *internal timer* pada mikrokontroler Arduino Uno.
2. Mengimplementasikan *external interrupt* memanfaatkan media *push button* untuk mengontrol aktuator tanpa membebani performa CPU melalui proses *polling*.
3. Menerapkan metode manajemen waktu secara *non-blocking* menggunakan fungsi pewaktu `millis()` untuk membangun sistem perulangan berkala yang responsif.

## 📄 Dasar Teori

Mekanisme interupsi dan manajemen waktu mandiri sangat penting dalam pengembangan sistem tertanam *real-time* untuk menjamin efisiensi eksekusi program serta kecepatan respons terhadap perubahan kondisi lingkungan.

1. Interrupt (Interupsi)  
Mekanisme perangkat keras yang memungkinkan mikrokontroler untuk menghentikan sementara jalannya program utama guna menangani suatu kejadian mendesak dari luar, sebelum akhirnya melanjutkan kembali pekerjaan utama yang sempat tertunda.

2. Interrupt Service Routine (ISR)  
Fungsi khusus yang otomatis dipanggil dan dieksekusi ketika peristiwa interupsi terjadi. Struktur kode di dalam ISR harus dibuat seringkas dan sesingkat mungkin dengan menghindari fungsi-fungsi lambat seperti `delay()` atau `Serial.print()`.

3. Variabel Volatile  
Keyword (`volatile`) yang disematkan dalam deklarasi variabel untuk menginstruksikan *compiler* agar selalu memproses dan mengambil nilai data terbaru langsung dari memori RAM, karena nilainya dapat berubah sewaktu-waktu di luar kendali alur program normal (seperti di dalam fungsi ISR).

4. Timer Internalisasi  
Modul pencacah waktu internal di dalam mikrokontroler yang bekerja menghitung pulsa detak *clock* sistem secara independen. Komponen ini digunakan untuk keperluan pembangkitan sinyal PWM, kalkulasi durasi, hingga interupsi periodik.

5. Non-Blocking Time (`millis()`)  
Metode pelacakan waktu berjalan menggunakan fungsi `millis()` yang mengembalikan nilai durasi operasional Arduino sejak pertama kali aktif dalam satuan milidetik. Metode ini bersifat *non-blocking* sehingga CPU tetap aktif mengeksekusi tugas-tugas lain (multitasking).

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)

## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

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
      <img width="150" height="150" alt="img1" src="../Modul 6/Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Modul 6/Laporan Praktikum/Komponen/push button.jpg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Modul 6/Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Modul 6/Laporan Praktikum/Komponen/led.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Modul 6/Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img7" src="../Modul 6/Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>

## 💻 Percobaan

Eksperimen pada modul ini dibagi menjadi dua skenario utama untuk menguji sensitivitas interupsi eksternal dan efisiensi penjadwalan waktu non-blocking.

1. Percobaan 6A: External Interrupt  
  * Menguji responsivitas interupsi fisik murni melalui pin digital 2 (Interrupt 0) yang dipicu oleh mode transmisi jatuh (*FALLING edge*) dari tombol tekan. Skenario ini memproses fungsi ISR untuk melakukan operasi pembalikan status (*toggle*) logika daya LED pada pin 13 secara instan tanpa proses polling.

2. Percobaan 6B: Timer Menggunakan `millis()`  
  * Menguji penerapan fungsi pencatat waktu internal `millis()` untuk membuat sebuah siklus *blinking* LED pin 13 dengan interval periodik sebesar 1000 ms. Pendekatan ini memastikan alur eksekusi loop utama program tetap berjalan bebas dan responsif tanpa intervensi pembekuan CPU.

## 📚 Pertanyaan Praktikum

### A. External Interrupt
1. Jelaskan proses bagaimana tombol dapat mengubah kondisi LED menggunakan interrupt!
2. Apa fungsi attachInterrupt() pada program tersebut?
3. Mengapa pada ISR tidak disarankan menggunakan delay() dan Serial.print()?
4. Apa fungsi keyword volatile pada variabel ledState?
5. Pada percobaan digunakan mode interrupt FALLING. Modifikasikan program menggunakan mode interrupt lain (RISING,  CHANGE, atau LOW) kemudian:
  * Jelaskan perbedaan cara kerja masing-masing mode interrupt tersebut
  * Analisis perubahan perilaku LED yang terjadi pada setiap mode
  * Sertakan source code dan penjelasan program dalam bentuk README.md

**Jawaban**
1. Saat push button ditekan, terjadi transisi level tegangan fisik pada pin digital 2 (pin interupsi). Sinyal perubahan ini langsung memicu perangkat keras mikrokontroler untuk menghentikan sementara baris kode yang sedang berjalan di program utama (loop()). CPU kemudian melompat untuk mengeksekusi fungsi khusus bernama ISR (tombolInterrupt()) yang membalikkan nilai logika variabel ledState. Setelah fungsi ISR selesai, CPU kembali melanjutkan baris program utama dan memperbarui status fisik LED pada pin 13 secara instan.
2. Fungsi attachInterrupt() digunakan untuk mendaftarkan dan mengonfigurasi interupsi eksternal pada pin tertentu. Fungsi ini bertugas memetakan pin fisik mikrokontroler yang mendukung interupsi, menentukan fungsi ISR mana yang harus dijalankan saat kejadian terjadi, serta menetapkan jenis transisi sinyal (mode) yang menjadi pemicunya.
3. Fungsi ISR harus dieksekusi sesingkat dan secepat mungkin agar sistem tetap stabil dan responsif. Fungsi delay() tidak dapat bekerja di dalam ISR karena ia mengandalkan interupsi timer internal yang otomatis ditangguhkan saat ISR lain sedang aktif. Sementara fungsi Serial.print() membutuhkan pengiriman data melalui buffer serial yang relatif lambat, sehingga berpotensi menyebabkan sistem mengalami pembekuan eksekusi (freeze) atau kehilangan data interupsi berikutnya.
4. Keyword volatile berfungsi untuk menginstruksikan compiler agar selalu membaca dan menulis nilai variabel tersebut langsung dari/ke memori RAM utama, bukan melalui optimasi register cache CPU. Hal ini sangat penting karena nilai variabel tersebut dimodifikasi di dalam fungsi ISR yang alur eksekusinya terjadi secara mendadak di luar kendali program utama.
5. Berikut adalah penjelasan, analisis perilaku, beserta modifikasi kode program untuk mode LOW, RISING, dan CHANGE:
  * Perbedaan Cara Kerja Mode Interrupt:
    - LOW: Interupsi akan terus-menerus dipicu secara berulang selama level tegangan pada pin interupsi bernilai rendah (LOW), yaitu selama tombol ditekan dan ditahan.
    - RISING: Interupsi hanya terpicu tepat pada momen transisi sinyal berubah dari rendah ke tinggi (LOW ke HIGH), yaitu sesaat ketika tombol dilepas.
    - CHANGE: Interupsi terpicu setiap kali terjadi perubahan status logika pada pin interupsi, baik saat transisi dari HIGH ke LOW maupun dari LOW ke HIGH (saat tombol ditekan dan saat dilepas).
  * Analisis Perubahan Perilaku LED:
    - Pada Mode LOW: Kondisi LED menjadi sangat tidak stabil saat tombol ditahan. Karena fungsi ISR terus dipicu jutaan kali per detik selama tombol bernilai LOW, status LED membalik (toggle) dengan sangat cepat sehingga LED akan terlihat berkedip beresolusi tinggi atau tampak meredup akibat efek osilasi cepat.
    - Pada Mode RISING: Status aktif/mati LED berubah secara responsif dan bersih hanya pada momen ketika kita mengangkat jari atau melepas tekanan dari push button.
    - Pada Mode CHANGE: LED akan merespon dua kali lipat lebih sensitif. LED akan berubah status saat tombol mulai ditekan, dan akan kembali berubah status saat tombol dilepas.

Kode Program

```cpp
// ==========================================
// KODE PROGRAM MODIFIKASI: MODE INTERRUPT LOW
// ==========================================
#include <Arduino.h>

volatile bool ledState = false;

void tombolInterrupt() {
  ledState = !ledState; // Toggle status LED dengan sangat cepat selama tombol LOW
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  
  // Daftarkan ISR pada pin 2, dipicu oleh mode LOW
  attachInterrupt(digitalPinToInterrupt(2), tombolInterrupt, LOW);
}

void loop() {
  digitalWrite(13, ledState);
}
```
```cpp
// =============================================
// KODE PROGRAM MODIFIKASI: MODE INTERRUPT RISING
// =============================================
#include <Arduino.h>

volatile bool ledState = false;

void tombolInterrupt() {
  ledState = !ledState; // Toggle status LED saat tombol dilepas
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  
  // Daftarkan ISR pada pin 2, dipicu oleh mode RISING
  attachInterrupt(digitalPinToInterrupt(2), tombolInterrupt, RISING);
}

void loop() {
  digitalWrite(13, ledState);
}
```
```cpp
// =============================================
// KODE PROGRAM MODIFIKASI: MODE INTERRUPT CHANGE
// =============================================
#include <Arduino.h>

volatile bool ledState = false;

void tombolInterrupt() {
  ledState = !ledState; // Toggle status LED saat tombol ditekan DAN dilepas
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  
  // Daftarkan ISR pada pin 2, dipicu oleh mode CHANGE
  attachInterrupt(digitalPinToInterrupt(2), tombolInterrupt, CHANGE);
}

void loop() {
  digitalWrite(13, ledState);
}
```

### B. Timer Menggunakan `millis()`
1. Jelaskan bagaimana fungsi millis() bekerja pada program tersebut!
2. Apa perbedaan utama antara delay() dan millis()?
3. Mengapa metode millis() disebut non-blocking?
4. Modifikasi program agar:
  * LED pertama berkedip setiap 1 detik
  * LED kedua berkedip setiap 500 ms
  * Tanpa menggunakan delay()
  Berikan penjelasan setiap baris program dalam bentuk README.md.

**Jawaban**
1. Fungsi millis() bekerja sebagai akumulator waktu (stopwatch) internal mikrokontroler yang menghitung durasi waktu berjalan sejak Arduino pertama kali aktif dalam satuan milidetik. Di dalam program, nilai millis() diambil secara kontinu (currentMillis) lalu dikurangi dengan catatan waktu terakhir kondisi LED berubah (previousMillis). Jika hasil selisihnya telah mencapai atau melebihi variabel interval (1000 ms), program akan mengeksekusi perpindahan status LED dan memperbarui titik acuan waktu previousMillis.
2. Perbedaan utama terletak pada dampak penahanan eksekusi perintah CPU (blocking behavior). Fungsi delay() akan menghentikan secara total (blocking) seluruh aktivitas pengerjaan instruksi CPU selama durasi tertentu, sehingga sistem menjadi tidak responsif. Sebaliknya, fungsi millis() hanya membaca nilai register waktu saat ini tanpa menghentikan jalannya CPU (non-blocking), sehingga mikrokontroler tetap bebas mengeksekusi instruksi program lainnya secara simultan.
3. Metode millis() disebut non-blocking karena tidak mengunci alur jalannya eksekusi program pada satu baris tertentu. Mikrokontroler tetap dapat memutar siklus fungsi loop() secara bebas berulang-ulang untuk memproses baris logika pemrograman lainnya, sambil secara fleksibel melakukan pengecekan berkala terhadap pemenuhan target interval waktu.
4. Berikut adalah perubahan kode untuk mengontrol kedipan dua buah LED secara independen dengan interval waktu berbeda (1000 ms dan 500 ms) tanpa memicu pembekuan eksekusi program:

Kode Program

```cpp
#include <Arduino.h>

// Konfigurasi untuk LED pertama (Interval 1 detik / 1000 ms)
unsigned long prevMillisLED1 = 0; // Menyimpan waktu terakhir LED 1 berubah status
const long intervalLED1 = 1000;   // Parameter interval kedipan LED 1
bool ledState1 = false;           // Variabel status logika LED 1

// Konfigurasi untuk LED kedua (Interval 500 ms)
unsigned long prevMillisLED2 = 0; // Menyimpan waktu terakhir LED 2 berubah status
const long intervalLED2 = 500;    // Parameter interval kedipan LED 2
bool ledState2 = false;           // Variabel status logika LED 2

void setup() {
  // Mengonfigurasi pin digital 13 dan 12 sebagai output daya komponen
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // Mengambil data catatan waktu aktual berjalan dari sistem
  unsigned long currentMillis = millis();

  // Logika pengecekan selisih waktu untuk LED pertama (Pin 13)
  if (currentMillis - prevMillisLED1 >= intervalLED1) {
    prevMillisLED1 = currentMillis; // Memperbarui basis acuan waktu LED 1
    ledState1 = !ledState1;         // Membalikkan status logika LED 1
    digitalWrite(13, ledState1);    // Memperbarui kondisi fisik output LED 1
  }

  // Logika pengecekan selisih waktu untuk LED kedua (Pin 12)
  if (currentMillis - prevMillisLED2 >= intervalLED2) {
    prevMillisLED2 = currentMillis; // Memperbarui basis acuan waktu LED 2
    ledState2 = !ledState2;         // Membalikkan status logika LED 2
    digitalWrite(12, ledState2);    // Memperbarui kondisi fisik output LED 2
  }
}
```