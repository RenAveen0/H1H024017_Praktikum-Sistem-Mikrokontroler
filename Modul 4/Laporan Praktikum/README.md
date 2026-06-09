# Modul

### 📋 Informasi Praktikum
Nama: Hana Nur Fathiyyah\ 
NIM: H1H024017\
Nama Asisten Praktikum: Billy Hermawan\
Tanggal Percobaan: 28 April 2026\
Ruangan: Laboratorium Baru\
Jurnal:

### 🔍 Ringkasan Percobaan
1. Percobaan 4A: Analog to Digital Converter (ADC)\
**Tujuan:** Membaca nilai tegangan analog dari potensiometer melalui pin ADC mikrokontroler dan menampilkan nilai digitalnya secara *real-time* pada Serial Monitor.\
**Hasil:** Sinyal analog dari perputaran potensiometer sukses dikonversi oleh pin input analog (A0) menjadi data digital 10-bit dengan rentang nilai 0-1023. Nilai tersebut berhasil ditampilkan pada Serial Monitor dengan respons yang lancar, di mana nilai 0 merepresentasikan tegangan minimum (0V) dan 1023 merepresentasikan tegangan maksimum (5V).

2. Percobaan 4B: Pulse Width Modulation (PWM)\
**Tujuan:** Mengatur intensitas kecerahan (*brightness*) LED secara dinamis menggunakan sinyal PWM berdasarkan hasil pemetaan (*mapping*) nilai analog input potensiometer.\
**Hasil:** Mikrokontroler berhasil membaca input analog, kemudian melakukan pemetaan nilai (*mapping*) dari resolusi ADC 10-bit (0-1023) ke resolusi PWM 8-bit (0-255). Sinyal PWM yang dikeluarkan melalui pin digital pendukung (seperti pin 9) sukses mengubah tingkat kecerahan LED secara halus (*fading*) dan linear sesuai dengan posisi tuas potensiometer.

### 🛠️ Komponen Utama yang Digunakan
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
      <img width="150" height="150" alt="img1" src="../Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Laporan Praktikum/Komponen/servo.jpg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Laporan Praktikum/Komponen/potensiometer.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Laporan Praktikum/Komponen/led.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img7" src="../Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>