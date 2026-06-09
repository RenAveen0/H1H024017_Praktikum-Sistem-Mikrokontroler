# Source Code - Percobaan 4A: Kontrol Motor Servo Menggunakan Potensiometer (ADC)

Folder ini berisi kode program untuk mengendalikan posisi sudut motor servo secara *real-time* berdasarkan perubahan nilai resistansi potensiometer menggunakan fitur ADC (Analog to Digital Converter) dan sinyal kendali PWM (Pulse Width Modulation).

## 📄 Penjelasan Logika Program

Kode program bekerja dengan membaca sinyal analog dari potensiometer, mengonversinya menjadi sudut derajat, lalu menggerakkan motor servo secara linear. Berikut adalah alur logikanya:

1. Inisialisasi Awal: 
   * Library `<Servo.h>` disertakan untuk mengaktifkan fungsi khusus kendali motor, dan objek servo dibuat dengan nama `myservo`.
   * Komunikasi serial diaktifkan pada fungsi `setup()` dengan kecepatan transmisi data sebesar 9600 baud menggunakan `Serial.begin(9600)`.
   * Pin Digital 9 dikonfigurasi sebagai pin kontrol servo menggunakan perintah `myservo.attach(9)`.

2. Pembacaan ADC (Analog to Digital Converter):
   * Di dalam fungsi `loop()`, mikrokontroler menggunakan perintah `analogRead(potensioPin)` untuk membaca tegangan analog dari pin A0 yang terhubung ke potensiometer. Tegangan ini otomatis dikonversi menjadi nilai digital 10-bit dengan rentang 0 hingga 1023.

3. Konversi Data & Output Kendali (Mapping):
   * Melalui fungsi `map()`, nilai digital ADC (0-1023) dipetakan secara linear menjadi nilai rentang sudut operasional motor servo, yaitu 0 hingga 180 derajat.
   * Hasil konversi sudut tersebut dikirim ke motor servo menggunakan perintah `myservo.write(pos)` untuk menggerakkan poros servo secara presisi sesuai dengan putaran potensiometer.

4. Monitoring Data & Stabilisasi:
   * Data mentah ADC dari potensiometer beserta hasil konversi sudut servo dikirimkan kembali ke komputer melalui `Serial.print()` agar dapat dipantau langsung via Serial Monitor.
   * Program diberikan instruksi jeda singkat sebesar 15 ms menggunakan `delay(15)` untuk memberikan waktu fisik bagi motor servo bergerak menuju sudut target secara stabil sebelum pembacaan berikutnya dilakukan.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| Potensiometer (Wiper/Tengah) | Pin A0 | `INPUT` | Pin input analog untuk membaca perubahan nilai tegangan dari potensiometer. |
| Motor Servo (Signal) | Pin 9 | `OUTPUT` | Pin digital PWM untuk mengirimkan pulsa kontrol posisi sudut motor servo. |
| Potensiometer & Servo (VCC) | 5V | — | Jalur distribusi daya positif 5V dari papan Arduino Uno. |
| Potensiometer & Servo (GND) | GND | — | Jalur Ground bersama (Common Ground) sebagai referensi tegangan negatif. |