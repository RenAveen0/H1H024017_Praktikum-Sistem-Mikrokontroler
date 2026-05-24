# Modul 3

### 📋 Informasi Praktikum
Nama: Hana Nur Fathiyyah\
NIM: H1H024017\
Nama Asisten Praktikum: Billy Hermawan\
Tanggal Percobaan: 14 April 2026\
Ruangan: Laboratorium Baru\
Jurnal: https://drive.google.com/file/d/1CK7eZ0flsvw8jXOYkBGwD-DfvygKqtRM/view?usp=sharing

### 🔍 Ringkasan Percobaan
1. Percobaan 3A: Komunikasi Serial (UART)\
**Tujuan:** Mengendalikan status aktif LED secara interaktif melalui pengiriman karakter perintah dari Serial Monitor.\
**Hasil:** Mikrokontroler secara responsif memantau buffer serial masuk menggunakan `Serial.available()`. Pengiriman karakter '1' sukses menyalakan LED (disertai log status "LED ON") dan karakter '0' mematikan LED (disertai log status "LED OFF"), sementara karakter di luar itu otomatis disaring dengan memunculkan pesan "Perintah tidak dikenal".

2. Percobaan 3B: Inter-Integrated Circuit (I2C)\
**Tujuan:** Membaca data tegangan analog potensiometer melalui ADC dan memvisualisasikannya ke layar LCD 16x2 via jalur I2C.\
**Hasil:** Perubahan nilai tegangan analog dari potensiometer berhasil dikonversi oleh pin analog A0 menjadi data digital digital (0-1023). Baris pertama LCD menampilkan nilai numerik ADC secara *real-time*, dan baris kedua menampilkan visualisasi grafik batang (*bar level*) sepanjang 0-16 karakter dengan interval pembaruan data yang lancar setiap 200 ms.

### 🛠️ Komponen Utama yang Digunakan
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
      <img width="150" height="150" alt="img1" src="../Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Laporan Praktikum/Komponen/lcd i2c.jpeg"><br>
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
      <img width="150" height="150" alt="img6" src="../Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>