# Jawaban Pertanyaan Praktikum
4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati),
ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang →
mati dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!\

# Dokumentasi Kode Arduino: LED Fade Speed Control

Program ini mengontrol kecepatan kedipan LED pada Pin 6 agar berubah dari lambat ke cepat, lalu kembali dari cepat ke lambat secara bertahap.

## Kode Program

```cpp
const int ledPin = 6;      // Menentukan pin digital 6 sebagai pin LED
int timeDelay = 1000;      // Inisialisasi delay awal 1000ms (lambat)
bool isSpeedingUp = true;  // Variabel penanda arah kecepatan (true = makin cepat)

void setup() {
    pinMode(ledPin, OUTPUT); // Mengatur ledPin sebagai OUTPUT
}

void loop() {
    // 1. Menyalakan LED
    digitalWrite(ledPin, HIGH);
    delay(timeDelay);

    // 2. Mematikan LED
    digitalWrite(ledPin, LOW);
    delay(timeDelay);

    // 3. Logika Perubahan Kecepatan
    if (isSpeedingUp) {
        // Jika sedang mempercepat, kurangi delay
        timeDelay -= 100;
        
        // Jika sudah mencapai batas paling cepat (100ms)
        if (timeDelay <= 100) {
            isSpeedingUp = false; // Ubah arah menjadi melambat
        }
    } else {
        // Jika sedang melambat, tambah delay
        timeDelay += 100;
        
        // Jika sudah kembali ke batas paling lambat (1000ms)
        if (timeDelay >= 1000) {
            delay(3000);         // Jeda 3 detik saat kondisi "Mati/Diam"
            isSpeedingUp = true; // Reset arah menjadi mempercepat lagi
        }
    }
}
```
| Fitur | Status | Deskripsi |
| :--- | :----: | ---: |
| Login | ✅ | Rata Kiri |
| Register | ⚠️ | Rata Tengah |
| Logout | ❌ | Rata Kanan |
