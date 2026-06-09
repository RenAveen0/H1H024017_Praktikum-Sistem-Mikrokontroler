# Percobaan 1: Kontrol Motor Servo Menggunakan Potensiometer (ADC)

Dokumentasi ini memuat detail pelaksanaan Percobaan 4A mengenai implementasi fitur ADC (Analog to Digital Converter) untuk membaca input analog dari potensiometer dan sinyal kendali PWM (Pulse Width Modulation) untuk mengatur posisi sudut motor servo secara *real-time*.

## 🎯 Tujuan
1. Memahami prinsip kerja konversi sinyal analog ke digital (ADC) serta resolusi bit data pada mikrokontroler Arduino Uno.
2. Mengimplementasikan pustaka `<Servo.h>` dan fungsi `map()` untuk mentransformasikan nilai resolusi ADC menjadi parameter sudut derajat.
3. Mengendalikan komponen aktuator fisik (motor servo) secara linear dan presisi berdasarkan perubahan nilai resistansi potensiometer.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Komunikasi serial dikonfigurasi pada kecepatan transmisi 9600 baud, pin kontrol motor servo dipasangkan pada Pin Digital 9 (PWM), dan pin pembacaan potensiometer diatur pada Pin Analog A0.
* Pembacaan dan Konversi Data: Sistem mampu membaca nilai tegangan analog dari potensiometer dan mengubahnya menjadi data digital 10-bit (rentang 0-1023), kemudian memetakan nilai tersebut secara linear ke dalam rentang sudut operasional servo (0-180°).
* Pergerakan Aktual: Poros motor servo bergerak secara responsif, halus, dan stabil mengikuti arah serta tingkat perputaran tuas potensiometer.
* Monitoring Data: Serial Monitor secara berkala menampilkan log data interaktif yang memuat informasi nilai mentah ADC potensiometer dan hasil konversi sudut servo secara *real-time* dengan jeda stabilisasi sebesar 15 ms.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan dua kaki luar potensiometer masing-masing ke pin 5V dan Ground (GND) Arduino. Hubungkan kaki tengah (*wiper*) potensiometer ke Pin Analog A0 Arduino.
   * Hubungkan kabel sinyal (oranye/kuning) motor servo ke Pin Digital 9 Arduino. Hubungkan kabel daya (merah) ke pin 5V dan kabel ground (cokelat/hitam) ke pin GND Arduino.
2. Koneksi Perangkat: Sambungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B sebagai jalur catu daya dan komunikasi data.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program yang menyertakan library `#include <Servo.h>`, menginisialisasi objek servo, melakukan konfigurasi kecepatan serial 9600 baud pada `setup()`, serta memuat logika `analogRead()`, fungsi pemetaan `map()`, dan perintah `myservo.write()` pada fungsi `loop()`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada kesalahan penulisan kode atau pustaka, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Buka Serial Monitor di Arduino IDE, pastikan pengaturan kecepatan berada di 9600 baud, lakukan pengujian dengan memutar tuas potensiometer secara perlahan ke berbagai arah, lalu amati kesesuaian perubahan sudut poros motor servo fisik beserta pergerakan grafik/log angka yang ditampilkan pada layar monitor.