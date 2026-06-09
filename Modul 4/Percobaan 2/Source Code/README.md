# Source Code - Percobaan 4B: Pengaturan Kecerahan LED Menggunakan PWM (Pulse Width Modulation)

Folder ini berisi kode program untuk mengatur intensitas kecerahan (*brightness*) lampu LED secara dinamis dan *real-time* berdasarkan hasil pembacaan serta pemetaan (*mapping*) nilai analog input dari potensiometer.

## 📄 Penjelasan Logika Program

Kode program bekerja dengan mentransformasikan resolusi pembacaan tegangan analog menjadi durasi siklus kerja (*duty cycle*) sinyal kotak digital. Berikut adalah alur logikanya:

1. Inisialisasi Awal:
   * Pin Digital 9 dikonfigurasi sebagai komponen keluaran melalui perintah `pinMode(ledPin, OUTPUT)` tempat kaki anoda LED terhubung.
   * Jalur komunikasi serial dibuka pada fungsi `setup()` dengan kecepatan transimisi standar 9600 baud lewat perintah `Serial.begin(9600)`.

2. Pembacaan Sensor (ADC):
   * Pada fungsi `loop()`, mikrokontroler terus-menerus mengambil sampel tegangan analog dari pin A0 menggunakan perintah `analogRead(potPin)`. Proses ini menghasilkan representasi data digital 10-bit dalam rentang nilai nilai numerik 0-1023.

3. Pemrosesan & Pemetaan Data (Scaling):
   * Karena register `analogWrite()` pada Arduino Uno bekerja dengan resolusi sinyal PWM 8-bit (0-255), maka nilai mentah ADC (0-1023) dikonversi terlebih dahulu menggunakan fungsi `map(nilaiADC, 0, 1023, 0, 255)`. Langkah ini memastikan perubahan posisi tuas potensiometer berbanding lurus secara linear dengan regulasi daya ke LED.

4. Output PWM & Pemantauan Sistem:
   * Sinyal PWM hasil konversi dialirkan ke komponen target melalui instruksi `analogWrite(ledPin, pwm)`. Hal ini memicu efek peredupan atau penerangan (*fading*) pada fisik lampu LED.
   * Nilai variabel `nilaiADC` dan data hasil pemetaan `pwm` dikirim secara simultan ke Serial Monitor untuk mempermudah visualisasi serta debugging.
   * Eksekusi program diakhiri dengan instruksi `delay(50)` demi menjaga kestabilan sampling data pembacaan sensor dan mencegah *overhead* pemrosesan.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| Potensiometer (Wiper/Tengah) | Pin A0 | `INPUT` | Pin input analog untuk menangkap variasi tegangan pembagi. |
| LED (Anoda) | Pin 9 | `OUTPUT` | Pin digital output pendukung PWM untuk mengatur tingkat kecerahan LED. |
| LED (Katoda) | GND | — | Jalur Ground negatif yang dipasangkan Resistor 220 Ω sebagai pengaman arus berlebih. |
| Potensiometer (VCC) | 5V | — | Dihubungkan ke pin 5V Arduino sebagai pemberi tegangan referensi maksimal. |
| Potensiometer (GND) | GND | — | Dihubungkan ke pin Ground bersama (Common Ground). |