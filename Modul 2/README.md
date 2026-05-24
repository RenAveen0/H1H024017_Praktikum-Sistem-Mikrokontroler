# Modul 2 : Pemrograman GPIO

## 🎯 Tujuan Praktikum

## 📄 Dasar Teori

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

## 📚 Pertanyaan Praktikum

### A. Seven Segment
1. Gambarkan rangkaian schematic yang digunakan pada percobaan!
2. Apa yang terjadi jika nilai num lebih dari 15?
3. Apakah program ini menggunakan common cathode atau common anode? Jelaskan alasannya!
4. Modifikasi program agar tampilan berjalan dari F ke 0 dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

**Jawaban**
1. Berikut adalah penggambaran schematic Seven Segment.\
<img width="500" alt="ss1" src="../Modul 2/Percobaan 1/Dokumentasi/Seven Segment.jpg">

2. Jika nilai num lebih besar dari 15 (misalnya 16, 17, dst.), maka akan terjadi Array Out of Bounds (akses di luar batas array). Dalam bahasa C/C++ (dasar Arduino), array digitPattern didefinisikan dengan ukuran [16][8]. Jika program mencoba mengakses indeks ke-16 atau lebih, ia akan mengambil data dari alamat memori yang tidak seharusnya.
3. Program ini menggunakan jenis Common Anode (CA). Alasannya: Program ini menggunakan Common Anode karena penggunaan operator NOT (!) pada fungsi displayDigit menyebabkan segmen menyala saat pin Arduino mengirimkan sinyal LOW.
4. Berikut adalah kode yang telah dimodifikasi agar hitungan berjalan mundur dari F ke 0.

Kode Program

```cpp
//7-Segment Display (Efficient Version)
//Display 69 and AF

// Pin mapping segment
const int segmentPins[8] = {7, 6, 5, 10, 11, 8, 9, 4};
// a b c d e f g dp

// Segment pattern for e-F
// urutan segmen: a b c d e f g dp
byte digitPattern[16][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5 
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}, //9
  {1,1,1,0,1,1,1,0}, //A
  {0,0,1,1,1,1,1,0}, //b
  {1,0,0,1,1,1,0,0}, //C
  {0,1,1,1,1,0,1,0}, //d
  {1,0,0,1,1,1,1,0}, //E
  {1,0,0,0,1,1,1,0} //F
};

// Fungsi menampilkan digit
void displayDigit(int num)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(segmentPins[i], !digitPattern[num][i]);
  }
}

void setup()
{
  for(int i=0 ;i<8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop()
{
  for(int i=15; i>=0; i--) // Perubahan disini untuk menampilkan F ke 0
  {
    displayDigit(i);
    delay(1000);
  }
}
```
<img width="600" height="300" alt="ss2" src="../Modul 2/Percobaan 1/Dokumentasi/SevenSegmentver2.gif">

### B. Button Seven Segment
1. Gambarkan rangkaian schematic yang digunakan pada percobaan!
2. Mengapa pada push button digunakan mode INPUT_PULLUP pada Arduino Uno? Apa keuntungannya dibandingkan rangkaian biasa?
3. Jika salah satu LED segmen tidak menyala, apa saja kemungkinan penyebabnya dari sisi hardware maupun software?
4. Modifikasi rangkaian dan program dengan dua push button yang berfungsi sebagai penambahan (increment) dan pengurangan (decrement) pada sistem counter dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

**Jawaban**
1. Berikut adalah penggambaran schematic Button Seven Segment.\
<img width="500" alt="ss3" src="../Modul 2/Percobaan 2/Dokumentasi/Button Seven Segment.jpg">

2. Karena INPUT_PULLUP digunakan untuk mengaktifkan resistor internal dalam menjaga stabilitas sinyal (mencegah floating) dan menyederhanakan rangkaian tanpa perlu tambahan resistor fisik.
3. Bisa disebabkan oleh kerusakan komponen/kabel kendor (hardware) atau kesalahan pemetaan pin dan pola bit dalam kode (software).
4. Berikut adalah kode yang telah dimodifikasi untuk mendukung penambahan (increment) dan pengurangan (decrement).

Kode Program

```cpp
const int segmentPins[8] = {7, 6, 5, 10, 11, 8, 9, 4};
const int btnUp = 3;
const int btnDown = 2; // Menambah tombol Down di pin 2

byte digitPattern[16][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5 
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}, //9
  {1,1,1,0,1,1,1,0}, //A
  {0,0,1,1,1,1,1,0}, //b
  {1,0,0,1,1,1,0,0}, //C
  {0,1,1,1,1,0,1,0}, //d
  {1,0,0,1,1,1,1,0}, //E
  {1,0,0,0,1,1,1,0}  //F
};

int currentDigit = 0;
bool lastUpState = HIGH;
bool lastDownState = HIGH;

void displayDigit(int num) {
  for(int i=0; i<8; i++) {
    digitalWrite(segmentPins[i], !digitPattern[num][i]); 
  }
}

void setup() {
  // Semua pin output segmen
  for(int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  pinMode(btnUp, INPUT_PULLUP); // Inisialisasi tombol Up
  pinMode(btnDown, INPUT_PULLUP); // Inisialisasi tombol Down

  // Menampilkan angka awal (0) saat pertama kali nyala
  displayDigit(currentDigit);
}

void loop() {
  bool upState = digitalRead(btnUp);
  bool downState = digitalRead(btnDown);

  /// Logika Tombol Up
  if(lastUpState == HIGH && upState == LOW) {
    currentDigit++;
    if(currentDigit > 15) currentDigit = 0; // Reset ke 0 jika lebih dari F
    displayDigit(currentDigit);
  }

  // Logika Tombol Down
  if(lastDownState == HIGH && downState == LOW) {
    currentDigit--;
    if(currentDigit < 0) currentDigit = 15; // Lompat ke F jika kurang dari 0
    displayDigit(currentDigit);
  }

  lastUpState = upState;
  lastDownState = downState;
}
```
<img width="600" height="300" alt="ss4" src="../Modul 2/Percobaan 2/Dokumentasi/ButtonSevenSegmentver2.gif">