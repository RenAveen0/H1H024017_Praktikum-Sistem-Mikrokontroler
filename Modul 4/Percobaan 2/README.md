# Percobaan 2: Pengaturan Kecerahan LED Menggunakan PWM (Pulse Width Modulation)

Dokumentasi ini memuat detail pelaksanaan Percobaan 4B mengenai implementasi sinyal PWM untuk mengatur intensitas kecerahan (*brightness*) lampu LED secara dinamis dan *real-time* berdasarkan nilai input analog dari potensiometer.

## 🎯 Tujuan
1. Memahami prinsip kerja, konsep *duty cycle*, dan regulasi daya menggunakan sinyal *Pulse Width Modulation* (PWM) pada mikrokontroler Arduino Uno.
2. Mengimplementasikan fungsi `map()` untuk mengonversi dan menyelaraskan perbedaan resolusi data antara ADC 10-bit dengan PWM 8-bit.
3. Mengendalikan intensitas cahaya komponen output fisik (LED) secara halus (*fading*) dan linear melalui fungsi `analogWrite()`.

## 💡 Spesifikasi yang Diharapkan
* Konfigurasi Awal: Komunikasi serial dikonfigurasi pada kecepatan transmisi 9600 baud, pin analog A0 digunakan sebagai input potensiometer, dan pin digital 9 dikonfigurasi sebagai `OUTPUT` pendukung PWM untuk LED.
* Pemrosesan Data (Scaling): Sistem mampu mentransformasikan nilai pembacaan tegangan analog dari rentang data 10-bit (0-1023) menjadi parameter lebar pulsa digital 8-bit (0-255) secara akurat.
* Efek Visual LED: Intensitas kecerahan lampu LED berubah secara halus dan linear seiring dengan perputaran tuas potensiometer, di mana nilai PWM 0 membuat LED mati total dan nilai PWM 255 membuat LED menyala dengan tingkat kecerahan maksimal.
* Monitoring & Stabilitas: Serial Monitor secara konsisten menampilkan log data interaktif yang memuat informasi nilai mentah ADC potensiometer berpasangan dengan nilai output PWM, didukung jeda waktu stabilisasi sistem sebesar 50 ms.

## ♻️ Langkah Percobaan
1. Persiapan Perangkat Keras:
   * Hubungkan dua kaki luar potensiometer masing-masing ke pin 5V dan Ground (GND) Arduino. Hubungkan kaki tengah (*wiper*) potensiometer ke Pin Analog A0 Arduino.
   * Hubungkan kaki Anoda (+) LED ke Pin Digital 9 (jalur PWM) pada Arduino Uno.
   * Hubungkan kaki Katoda (-) LED ke salah satu kaki Resistor 220 Ω, kemudian hubungkan kaki resistor lainnya ke pin Ground (GND) Arduino.
2. Koneksi Perangkat: Sambungkan papan Arduino Uno ke PC/Laptop menggunakan Kabel USB Tipe A-to-B sebagai jalur catu daya dan komunikasi data.
3. Penyusunan Kode: Buka aplikasi Arduino IDE, lalu ketik kode program yang mengonfigurasi pin komponen, mengaktifkan `pinMode(ledPin, OUTPUT)` serta `Serial.begin(9600)` pada fungsi `setup()`, serta memuat logika sampling `analogRead()`, penskalaan `map()`, luaran `analogWrite()`, dan pencetakan data pada fungsi `loop()`.
4. Unggah Program: Lakukan kompilasi (*verify*) untuk memastikan tidak ada kesalahan logika atau penulisan kode, kemudian unggah (*upload*) program ke papan Arduino Uno.
5. Pengamatan: Buka Serial Monitor di Arduino IDE dengan konfigurasi kecepatan 9600 baud, lakukan pengujian dengan memutar tuas potensiometer secara perlahan dari batas minimum hingga maksimum, lalu amati gradasi perubahan kecerahan fisik LED beserta keselarasan angka ADC dan PWM yang tercetak pada layar monitor.