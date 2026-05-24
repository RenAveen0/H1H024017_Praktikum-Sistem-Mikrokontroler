# Source Code - Percobaan 3B: Inter-Integrated Circuit (I2C)

Folder ini berisi kode program untuk membaca nilai analog dari komponen potensiometer menggunakan fitur ADC dan menampilkan hasilnya secara *real-time* ke layar LCD 16x2 melalui protokol komunikasi I2C.

## 📄 Penjelasan Logika Program

Kode pada program ini bekerja dengan mengonversi tegangan analog menjadi data digital, kemudian mengirimkannya ke display eksternal. Berikut adalah alur logikanya:

1. Inisialisasi Awal:
   * Program mengimpor library komunikasi `Wire.h` dan library display `LiquidCrystal_I2C.h`.
   * Alamat I2C untuk modul LCD diatur (antara 0x27 atau 0x3F) untuk memulai dan mengaktifkan lampu latar (*backlight*) LCD.

2. Pembacaan Analog (ADC):
   * Di dalam fungsi `loop()`, mikrokontroler membaca pin analog A0 menggunakan fungsi `analogRead()`. Tegangan analog (0-5V) dari potensiometer diubah menjadi nilai digital 10-bit dengan rentang angka 0 hingga 1023.

3. Pemetaan dan Pembaruan Data:
   * Nilai mentah ADC (0-1023) dipetakan ulang menjadi panjang karakter batang (0-16 karakter) untuk memuat visualisasi grafik pada baris kedua LCD.
   * Nilai teks numerik ADC ditampilkan di baris pertama LCD, sedangkan grafik batang (*bar level*) dicetak di baris kedua. Seluruh proses ini diulang secara berkala dengan jeda *non-blocking* selama 200 ms agar responsif.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| LCD I2C (SDA) | Pin A4 | `I2C` | Jalur komunikasi data serial (*Serial Data*). |
| LCD I2C (SCL) | Pin A5 | `I2C` | Jalur komunikasi detak serial (*Serial Clock*). |
| Potensiometer (Kaki Tengah) | Pin A0 | `INPUT` | Masukan tegangan variabel untuk pembacaan nilai ADC. |
| VCC (LCD & Potensiometer) | Pin 5V | `POWER` | Sumber tegangan daya positif +5V dari Arduino. |
| GND (LCD & Potensiometer) | Pin GND | `POWER` | Jalur Ground bersama untuk menutup sirkuit. |