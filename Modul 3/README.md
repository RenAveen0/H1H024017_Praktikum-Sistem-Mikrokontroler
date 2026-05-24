# Modul ... : 

## 🎯 Tujuan Praktikum

## 📄 Dasar Teori

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)

## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr>
    <th>Arduino</th>
    <th>Potensiometer</th>
    <th>Motor Servo</th>
    <th>LED</th>
  </tr>

  <tr align="center">
    <td>
      <img width="192" height="136,1" alt="arduino_uno" src="https://github.com/user-attachments/assets/3e61e208-bb23-42aa-bbef-0ac539279ce0" /><br>
    </td>
    <td>
      <img width="179,5" height="175,75" alt="image" src="https://github.com/user-attachments/assets/f44c78e5-fd37-47e0-a2f4-0a5af2b6c86a" />
    </td>
    <td>
      <img width="318" height="260" alt="image" src="https://github.com/user-attachments/assets/e54280b7-5fd3-4ce7-b4f8-41163ed3bed3" /><br>
    </td>
    <td>
      <img width="54" height="134" alt="RedLED_Fritzing" src="https://github.com/user-attachments/assets/80556570-c129-43fa-904b-39eac5677a2d" />
    </td>
  </tr>

  <tr align="center">
    <td>Arduino Uno, atau lainnya</td>
    <td>Potensiometer</td>
    <td>Motor Servo</td>
    <td>LED Merah</td>
  </tr>
</table>
</div>

## 💻 Percobaan

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