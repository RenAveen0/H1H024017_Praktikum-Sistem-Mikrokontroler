# Modul 4 : Analog to Digital Converter (ADC) & Pulse Width Modulation (PWM)

## 🎯 Tujuan Praktikum

1. Memahami konsep, prinsip kerja, dan perbedaan antara sinyal analog kontinu dengan sinyal digital diskrit pada sistem mikrokontroler.
2. Mengimplementasikan fitur modul ADC internal untuk membaca variasi nilai tegangan dari komponen input analog (Potensiometer).
3. Menerapkan teknik kendali PWM (*Pulse Width Modulation*) untuk memanipulasi *duty cycle* dalam mengatur posisi sudut aktuator (Motor Servo) serta intensitas kecerahan komponen output (LED).

## 📄 Dasar Teori

Konversi data antara ranah analog dan digital sangat krusial dalam sistem tertanam untuk menjembatani interaksi antara mikrokontroler dengan dunia fisik.

1. ADC (Analog-to-Digital Converter)  
Modul internal mikrokontroler yang berfungsi mengubah sinyal tegangan kontinu analog (0–5V) menjadi bentuk data digital diskrit 10-bit. Proses sampling ini menghasilkan rentang nilai hitungan digital linear antara 0 hingga 1023.

2. PWM (Pulse Width Modulation)  
Metode yang digunakan untuk mensimulasikan keluaran analog dari pin digital dengan cara memanipulasi rasio waktu aktif (*HIGH*) terhadap waktu mati (*LOW*) dari suatu gelombang kotak secara konstan. Pada Arduino Uno, sinyal PWM memiliki resolusi 8-bit (rentang nilai 0–255).

3. Duty Cycle (Siklus Kerja)  
Persentase representasi durasi sinyal digital berada dalam kondisi *HIGH* dalam satu periode gelombang penuh. Tinggi rendahnya persentase *duty cycle* berbanding lurus dengan rata-rata tegangan efektif yang disalurkan ke komponen beban.

4. Motor Servo  
Perangkat aktuator putar (motor) yang dilengkapi dengan sistem umpan balik tertutup (*closed-loop*), memungkinkan pengaturan posisi sudut porosnya dikendalikan secara presisi (0° hingga 180°) menggunakan lebar pulsa sinyal PWM khusus.

5. Penskalaan Data (Fungsi `map()`)  
Fungsi linear bawaan pada ekosistem Arduino untuk mengonversi nilai dari suatu rentang resolusi ke rentang resolusi target lainnya. Sangat berguna untuk menyelaraskan input resolusi ADC (10-bit) menuju resolusi PWM (8-bit) atau kapasitas sudut derajat motor servo.

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)

## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>Servo</th>
    <th>Potensiometer 10 kΩ</th>
    <th>Resistor 220 Ω</th>
    <th>LED</th>
    <th>Breadboard</th>
    <th>Kabel Jumper</th>
  </tr>

  <tr align="center">
    <td>
      <img width="150" height="150" alt="img1" src="../Modul 4/Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Modul 4/Laporan Praktikum/Komponen/servo.jpg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Modul 4/Laporan Praktikum/Komponen/potensiometer.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Modul 4/Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Modul 4/Laporan Praktikum/Komponen/led.jpeg><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Modul 4/Laporan Praktikum/Komponen/breadboard.jpeg><br>
    </td>
    <td>
      <img width="150" height="150" alt="img7" src="../Modul 4/Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>

## 💻 Percobaan

Eksperimen pada modul ini dibagi menjadi dua skenario utama untuk menguji pengolahan data analog input menjadi aksi mekanis maupun visual.

1. Percobaan 4A: Kontrol Motor Servo Menggunakan Potensiometer  
  * Menguji kemampuan mikrokontroler dalam menangkap perubahan tegangan analog potensiometer lewat pin ADC A0, mengonversinya menjadi koordinat sudut derajat (0-180°), lalu mengirimkan sinyal kontrol PWM yang presisi untuk memosisikan poros motor servo.

2. Percobaan 4B: Pengaturan Kecerahan LED Menggunakan PWM  
  * Menguji integrasi konversi skala resolusi dari data input ADC 10-bit (0-1023) menuju data digital output PWM 8-bit (0-255). Sinyal ini diaplikasikan untuk mengatur variasi intensitas cahaya (*fading effect*) pada lampu LED secara halus.

## 📚 Pertanyaan Praktikum

### A. Analog to Digital Converter (ADC)
1. Apa fungsi perintah analogRead() pada rangkaian praktikum ini?
2. Mengapa diperlukan fungsi map() dalam program tersebut?
3. Modifikasi program berikut agar servo hanya bergerak dalam rentang 30° hingga 150°, meskipun potensiometer tetap memiliki rentang ADC 0–1023. Jelaskan program pada file README.md

**Jawaban**
1. Membaca tegangan analog kontinu (0–5V) dari potensiometer dan mengubahnya menjadi nilai digital diskrit 10-bit dengan rentang 0 hingga 1023.
2. Untuk menyelaraskan (mengonversi) rentang resolusi input yang besar (ADC: 0–1023) agar pas dengan rentang target output yang lebih kecil, seperti sudut motor servo (0–180) atau resolusi sinyal PWM (0–255).
3. Berikut perubahan kodenya:

Kode Program

```cpp
#include <Servo.h> // library untuk servo motor

Servo myservo; // membuat objek servo

// ===================== PIN SETUP =====================
// Tentukan pin yang digunakan untuk potensiometer dan servo
const int potensioPin = A0;   // isi pin analog input (contoh A0)
const int servoPin = 9;      // isi pin digital untuk servo (PWM)

// ===================== VARIABEL =====================
// Variabel untuk menyimpan data ADC dan sudut servo
int pos = 0; // isi dengan tipe data dan inisialisasi awal
int val = 0; // isi dengan tipe data dan inisialisasi awal

void setup() {

  // Hubungkan servo ke pin yang sudah ditentukan
  myservo.attach(servoPin); // isi dengan servoPin

  // Aktifkan komunikasi serial untuk monitoring
  Serial.begin(9600); // isi baud rate (contoh 9600)

}

void loop() {

  // ===================== PEMBACAAN ADC =====================
  // Baca nilai dari potensiometer (rentang 0–1023)
  val = analogRead(potensioPin); // isi dengan potensioPin

  // ===================== KONVERSI DATA =====================
  // Ubah nilai ADC menjadi sudut servo (DIBATASI: 30–150 derajat)
  pos = map(val,
            0,      // nilai minimum ADC
            1023,   // nilai maksimum ADC
            30,     // MODIFIKASI: sudut minimum servo diubah ke 30°
            150);   // MODIFIKASI: sudut maksimum servo diubah ke 150°

  // ===================== OUTPUT SERVO =====================
  // Gerakkan servo sesuai hasil mapping
  myservo.write(pos); // isi dengan variabel sudut

  // ===================== MONITORING DATA =====================
  // Tampilkan data ADC dan sudut servo ke Serial Monitor
  Serial.print("ADC Potensio: ");
  Serial.print(val); // isi variabel ADC

  // Nilai sudut yang tampil di sini sekarang otomatis mentok di 30 atau 150
  Serial.print(" | Sudut Servo: ");
  Serial.println(pos); // isi variabel sudut

  // ===================== STABILISASI =====================
  // Delay untuk memberi waktu servo bergerak stabil
  delay(15); // isi dalam milidetik
}
```

### B. Pulse Width Modulation (PWM)
1. Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi analogWrite()!
2. Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?
3. Modifikasilah program berikut agar LED hanya menyala pada rentang kecerahan sedang, yaitu hanya ketika nilai PWM berada pada rentang 50 sampai 200. Jelaskan program pada file README.md.

**Jawaban**
1. Karena analogWrite() memanipulasi duty cycle (rasio lamanya waktu sinyal ON dibanding OFF). Perubahan duty cycle ini mengubah tegangan rata-rata yang diterima LED, sehingga menciptakan efek redup atau terang di mata kita.
2. Hubungannya berbanding lurus (linear) dengan rasio 4:1, yang merupakan hasil penskalaan dari resolusi data 10-bit ke 8-bit. Nilai PWM secara kasar didapat dari nilai ADC dibagi 4 ($1023 / 4 \approx 255$).
3. Berikut perubahan kodenya:

Kode Program

```cpp
// ===================== PIN SETUP =====================
const int potPin = A0;   // Pin analog untuk potensiometer
const int ledPin = 9;    // Pin digital PWM untuk LED

// ===================== VARIABEL =====================
int nilaiADC = 0;  // Variabel penyimpan nilai 10-bit (0-1023)
int pwm = 0;       // Variabel penyimpan nilai 8-bit (0-255)

void setup() {
  // ===================== OUTPUT SETUP =====================
  // Atur pin LED sebagai output
  pinMode(ledPin, OUTPUT);

  // ===================== SERIAL MONITOR =====================
  // Aktifkan komunikasi serial
  Serial.begin(9600); 
}

void loop() {
  // ===================== PEMBACAAN SENSOR =====================
  // Baca nilai analog dari potensiometer (0–1023)
  nilaiADC = analogRead(potPin);

  // ===================== PEMROSESAN DATA (SCALING) =====================
  // Ubah nilai ADC (10-bit) menjadi nilai PWM (8-bit)
  pwm = map(nilaiADC, 0, 1023, 0, 255);

  // ===================== LOGIKA PEMBATASAN (MODIFIKASI) =====================
  // LED hanya menyala jika nilai PWM berada di rentang 50 s/d 200
  if (pwm < 50 || pwm > 200) {
    pwm = 0; // Matikan PWM (LED mati) jika di luar rentang
  }

  // ===================== OUTPUT PWM =====================
  // Kirim sinyal PWM ke LED (akan bernilai 50-200, atau 0)
  analogWrite(ledPin, pwm); 

  // ===================== MONITORING DATA =====================
  Serial.print("ADC: ");
  Serial.print(nilaiADC); 

  Serial.print(" | PWM Output: ");
  Serial.println(pwm); 

  // ===================== STABILISASI SISTEM =====================
  delay(50); 
}
```