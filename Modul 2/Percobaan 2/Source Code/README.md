# Source Code - Percobaan 2B: Button Seven Segment (Input)

Folder ini berisi kode program untuk mengontrol perubahan nilai counter secara interaktif pada Seven Segment Display menggunakan input Push Button berbasis mikrokontroler Arduino Uno.

## 📄 Penjelasan Logika Program

Kode program bekerja dengan mendeteksi perubahan status tombol tekan secara *realtime* untuk menaikkan nilai hitungan. Berikut adalah alur logikanya:

1. Inisialisasi Awal: Pin digital yang terhubung ke segmen display dikonfigurasi sebagai `OUTPUT`. Sementara itu, pin tombol dikonfigurasi sebagai `INPUT_PULLUP` untuk mengaktifkan resistor internal Arduino agar sinyal input stabil dan tidak *floating*.
2. Pembacaan Tombol (Edge Detection): Di dalam `loop()`, program membandingkan status tombol saat ini dengan status sebelumnya (*lastButtonState*). Perubahan nilai hanya diproses jika terdeteksi transisi logika dari `HIGH` ke `LOW` (tombol baru saja ditekan). Metode ini efektif mencegah pembacaan palsu akibat *bouncing* mekanis.
3. Evaluasi Batas & Tampilan: Setiap kali tombol ditekan, variabel `currentDigit` akan bertambah satu (*increment*). Jika nilainya melebihi 15 (batas karakter F), program akan mereset nilainya kembali ke 0. Nilai terbaru ini kemudian langsung dikirim ke fungsi `displayDigit()` untuk diperbarui pada layar.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| Push Button | Pin 2 | `INPUT_PULLUP` | Dihubungkan langsung ke GND tanpa resistor eksternal. |
| Segmen a | Pin 7 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen b | Pin 6 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen c | Pin 5 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen d | Pin 11 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen e | Pin 10 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen f | Pin 8 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen g | Pin 9 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |
| Segmen dp | Pin 4 | `OUTPUT` | Dihubungkan melalui Resistor 220 Ω pembatas arus. |