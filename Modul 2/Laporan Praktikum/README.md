# Modul 2

### 📋 Informasi Praktikum
Nama: Hana Nur Fathiyyah  
NIM: H1H024017  
Nama Asisten Praktikum: Billy Hermawan  
Tanggal Percobaan: 7 April 2026  
Ruangan: Laboratorium Baru  
Jurnal: https://drive.google.com/file/d/1OGMsz7hJJLecWxwEzNS-ZKS5PuGchHfE/view?usp=sharing

### 🔍 Ringkasan Percobaan
1. Percobaan 2A: Seven Segment (Output)  
**Tujuan:** Menampilkan karakter heksadesimal (0-F) secara sekuensial menggunakan Seven Segment Display.  
**Hasil:** Program berhasil mengiterasi array dua dimensi `digitPattern` untuk menyalakan kombinasi LED pada display dengan interval jeda 1 detik. Karena menggunakan tipe Common Anode, sistem bekerja dengan logika *active low* (segmen menyala saat diberi sinyal `LOW`).

2. Percobaan 2B: Seven Segment dengan Push Button (Input)  
**Tujuan:** Mengontrol perubahan nilai counter pada Seven Segment secara interaktif menggunakan tombol tekan.  
**Hasil:** Implementasi mode `INPUT_PULLUP` berhasil menstabilkan pin masukkan dari kondisi *floating*. Nilai counter bertambah tepat satu satuan setiap kali tombol ditekan berkat metode *edge detection* yang mencegah efek *bouncing*, dan otomatis mereset kembali ke angka 0 setelah melewati batas karakter F (nilai > 15).

### 🛠️ Komponen Utama yang Digunakan
<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>Seven Segment CA</th>
    <th>Push Button</th>
    <th>Resistor 220 Ω</th>
    <th>Breadboard</th>
    <th>Kabel Jumper</th>
  </tr>

  <tr align="center">
    <td>
      <img width="150" height="150" alt="img1" src="../Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Laporan Praktikum/Komponen/seven segment.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Laporan Praktikum/Komponen/push button.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>