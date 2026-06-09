# Modul 3 : Protokol Komunikasi

## 🎯 Tujuan Praktikum

1. Memahami konsep, prinsip kerja, dan perbedaan dari protokol komunikasi serial (UART, I2C, dan SPI) pada mikrokontroler.
2. Mengimplementasikan fitur modul ADC (Analog-to-Digital Converter) internal untuk membaca perubahan tegangan linear dari sensor analog.
3. Menerapkan metode manajemen waktu *non-blocking* menggunakan fungsi `millis()` untuk membangun sistem kontrol multitasking yang responsif.

## 📄 Dasar Teori

Protokol komunikasi serial digunakan untuk memfasilitasi pertukaran data antar perangkat elektronik secara efisien dengan meminimalkan penggunaan pin fisik pada mikrokontroler.

1. UART (Universal Asynchronous Receiver-Transmitter) Protokol komunikasi serial asinkron yang bekerja tanpa sinyal *clock* bersama, melainkan menggunakan kesepakatan kecepatan data (*baud rate*). Transmisi data dilakukan melalui sepasang jalur pin utama, yaitu RX (Receiver) dan TX (Transmitter).

2. I2C (Inter-Integrated Circuit) Protokol serial sinkron berarsitektur *master-slave* yang menggunakan dua jalur bus, yaitu SDA (Serial Data) dan SCL (Serial Clock). Setiap perangkat *slave* memiliki alamat unik 7-bit, serta menggunakan konfigurasi saluran *open-drain* yang membutuhkan resistor *pull-up* eksternal/internal.

3. SPI (Serial Peripheral Interface) Protokol serial sinkron *full-duplex* (mengirim dan menerima data bersamaan) yang ideal untuk transfer data berkecepatan tinggi. Protokol ini menggunakan empat jalur pin: SCK (*Clock*), MOSI (*Master Out Slave In*), MISO (*Master In Slave Out*), dan SS (*Slave Select*).

4. ADC (Analog-to-Digital Converter) Modul internal mikrokontroler yang berfungsi mengubah sinyal tegangan kontinu analog (0–5V) menjadi representasi data digital diskrit 10-bit dengan rentang nilai hitungan antara 0 hingga 1023.

5. Manajemen Waktu (`delay()` vs `millis()`) * `delay()`: Bersifat *blocking* karena menghentikan total eksekusi siklus CPU, membuat program tidak responsif terhadap data atau input baru.
* `millis()`: Bersifat *non-blocking* dengan memanfaatkan pencacah waktu internal mikrokontroler sejak program pertama kali dijalankan, memungkinkan jalannya tugas multitasking.

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)

## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>LCD 16x2 I2C</th>
    <th>Potensiometer 10 kΩ</th>
    <th>Resistor 220 Ω</th>
    <th>LED</th>
    <th>Breadboard</th>
    <th>Kabel Jumper</th>
  </tr>

  <tr align="center">
    <td>
      <img width="150" height="150" alt="img1" src="../Modul 3/Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Modul 3/Laporan Praktikum/Komponen/lcd i2c.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Modul 3/Laporan Praktikum/Komponen/potensiometer.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Modul 3/Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Modul 3/Laporan Praktikum/Komponen/led.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Modul 3/Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Modul 3/Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>

## 💻 Percobaan

Eksperimen pada modul ini dibagi menjadi dua skenario utama untuk menguji efisiensi pertukaran data internal maupun eksternal sistem mikrokontroler.

1. Percobaan 3A: Komunikasi Serial (UART) 
  * Menguji respons interaktif mikrokontroler menerima bit data serial eksternal dari komputer. Karakter perintah '1' atau '0' dikirim via Serial Monitor untuk mengubah level logika output pin 8, sekaligus mengirimkan teks balasan kembali ke monitor komputer.

2. Percobaan 3B: Inter-Integrated Circuit (I2C) 
  * Menguji efisiensi pengiriman data terstruktur ke modul eksternal display. Nilai tegangan kontinu dari potensiometer dibaca oleh pin ADC A0 (skala 0-1023), kemudian dipetakan ke dalam format teks numerik beserta visualisasi grafik batang sepanjang 16 kolom pada layar LCD 16x2.

## 📚 Pertanyaan Praktikum

### A. Komunikasi Serial
1. Jelaskan proses dari input keyboard hingga LED menyala/mati!
2. Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika baris tersebut dihilangkan?
3. Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
4. Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem!

**Jawaban**
1. Data dari keyboard dikirim melalui Serial Monitor ke buffer Arduino, lalu dibaca oleh fungsi Serial.read() untuk dieksekusi menjadi perintah digitalWrite (HIGH/LOW) pada pin LED.
2. Fungsi ini memastikan ada data di buffer sebelum dibaca. Jika dihilangkan, Serial.read() akan terus mengambil nilai kosong (-1) di setiap siklus perulangan dan bisa mengacaukan logika program.
3. Berikut program yang sudah di modifikasi agar terus berkedip ketika menerima input 2.

Kode Program

```cpp
const int PIN_LED = 12;
int mode = 0; // 0: Manual, 1: Blink
unsigned long previousMillis = 0;
const long interval = 500; // Kecepatan kedip (ms)
int ledState = LOW;

void setup() {
  Serial.begin(9600);
  Serial.println("Input: 1=ON, 0=OFF, 2=BLINK");
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    
    if (data == '1') {
      mode = 0;
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED ON");
    } 
    else if (data == '0') {
      mode = 0;
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED OFF");
    } 
    else if (data == '2') {
      mode = 1;
      Serial.println("BLINK MODE START");
    }
  }

  // Menjalankan Blink tanpa menghentikan pembacaan Serial
  if (mode == 1) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      ledState = !ledState; // Toggle status LED
      digitalWrite(PIN_LED, ledState);
    }
  }
}
```
<img width="500" alt="ss1" src="../Modul 3/Percobaan 1/Dokumentasi/SerialMonitorver2.gif">
<br>

4. Lebih baik menggunakan millis. Karena jika menggunakan fungsi delay(), akan terjadi Blocking dimana Arduino akan menghentikan seluruh aktivitas prosesor dan hanya "menunggu" sampai waktu habis. Jika menggunakan millis(), akan terjadi Non-Blocking, dimana Arduino tetap menjalankan perintah lain dalam perulangan loop() secara terus-menerus. Fungsi millis() hanya mengecek apakah selisih waktu saat ini dengan waktu sebelumnya sudah mencapai target.

### B. I2C
1. Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian tersebut! 
2. Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan pin kanan tertukar! 
3. Modifikasi program dengan menggabungkan antara UART dan I2C (keduanya sebagai output) sehingga:
    - Data tidak hanya ditampilkan di LCD tetapi juga di Serial Monitor
    - Adapun data yang ditampilkan pada Serial Monitor sesuai dengan table berikut:\
    <img src="Tabel Soal No 3.png" alt="Tabel Soal No 3" width="500">\
    Tampilan jika potensiometer dalam kondisi diputar paling kiri
    - ADC: 0 0% | setCursor(0, 0) dan Bar (level) | setCursor(0, 1)
    - Berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
4. Lengkapi table berikut berdasarkan pengamatan pada Serial Monitor
    |ADC|Volt (V)|Persen (%)|
    |:---:|:---:|:---:|
    |1| | |
    |21| | |
    |49| | |
    |74| | |
    |96| | |

**Jawaban**
1. Menggunakan dua jalur kabel utama: SDA (Serial Data) untuk mengirim data dan SCL (Serial Clock) untuk sinkronisasi waktu. Arduino bertindak sebagai Master yang mengirimkan alamat khusus (misal: 0x27) ke jalur bus. Modul I2C pada LCD yang memiliki alamat tersebut akan merespons sebagai Slave. Setelah koneksi terjalin, Arduino mengirimkan data teks atau perintah kontrol ke LCD secara berurutan bit-demi-bit melalui kabel SDA sesuai dengan detak jam dari SCL.
2. Jika pin kiri (VCC/5V) dan pin kanan (GND) tertukar, maka arah putaran potensiometer akan terbalik. Jika biasanya memutar ke kanan (searah jarum jam) membuat nilai ADC naik, setelah tertukar, memutar ke kanan justru akan membuat nilai ADC mengecil menuju nol. Secara teknis tidak merusak komponen, hanya merubah arah pembacaan nilai.
3. Berikut perubahan kodenya:

Kode Program

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int pinPot = A0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int nilai = analogRead(pinPot);
  
  // Perhitungan Volt dan Persentase
  float volt = (nilai / 1023.0) * 5.0;
  int persen = map(nilai, 0, 1023, 0, 100);
  int panjangBar = map(nilai, 0, 1023, 0, 16);

  // --- Output UART (Serial Monitor) ---
  Serial.print("ADC: "); Serial.print(nilai);
  Serial.print(" | Volt: "); Serial.print(volt); Serial.print(" V");
  Serial.print(" | Persen: "); Serial.print(persen); Serial.println("%");

  // --- Output I2C (LCD) ---
  // Baris 1: ADC dan Persentase
  lcd.setCursor(0, 0);
  lcd.print("ADC:"); lcd.print(nilai);
  lcd.print("   "); lcd.print(persen); lcd.print("% "); // Spasi untuk clear sisa

  // Baris 2: Bar Level
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < panjangBar) lcd.print((char)255);
    else lcd.print(" ");
  }

  delay(200);
}
```
<img width="500" alt="i2c" src="../Modul 3/Percobaan 2/Dokumentasi/LCDI2Cver2.gif">
<br>

4. Tabel Pengamatan
    |ADC|Volt (V)|Persen (%)|
    |:---:|:---:|:---:|
    |1|0.005 V|0.10 %|
    |21|0.103 V|2.05 %|
    |49|0.239 V|4.79 %|
    |74|0.362 V|7.23 %|
    |96|0.469 V|9.38 %|