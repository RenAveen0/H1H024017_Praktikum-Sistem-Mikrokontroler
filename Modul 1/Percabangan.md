# Pertanyaan Praktikum
4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati),
ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang →
mati dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!\

## Jawaban

Program ini mengontrol kecepatan kedipan LED pada Pin 6 agar berubah dari lambat ke cepat, lalu kembali dari cepat ke lambat secara bertahap.

### Kode Program

```cpp
const int ledPin = 6;      // Menentukan pin digital 6 sebagai pin LED
int timeDelay = 1000;      // Inisialisasi delay awal 1000ms (lambat)
bool isSpeedingUp = true;  // Variabel penanda arah kecepatan (true = makin cepat)

void setup() {
    pinMode(ledPin, OUTPUT); // Mengatur ledPin sebagai OUTPUT
}

void loop() {
    // Menyalakan LED
    digitalWrite(ledPin, HIGH);
    delay(timeDelay);

    // Mematikan LED
    digitalWrite(ledPin, LOW);
    delay(timeDelay);

    // Logika Perubahan Kecepatan
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
\
### Penjelasan Baris Kode
| Baris Kode | Fungsi dan Penjelasan |
| :---: | :---: |
| `const int ledPin = 6;` | Mendefinisikan nomor pin yang digunakan. Menggunakan const memastikan nilai ini tidak berubah secara tidak sengaja selama program berjalan. |
| `int timeDelay = 1000;` | Variabel untuk menyimpan durasi delay. Dimulai dari 1000ms (1 detik) untuk memberikan efek awal yang lambat. |
| `bool isSpeedingUp = true;` | Variabel Boolean (penanda) yang berfungsi untuk menentukan arah perubahan kecepatan (apakah nilai delay harus dikurangi atau ditambah). |
| `pinMode(ledPin, OUTPUT);` | Menginstruksikan Arduino agar memperlakukan Pin 6 sebagai output tegangan listrik. |
| `digitalWrite(ledPin, HIGH);` | Mengirimkan sinyal digital 5V ke Pin 6 untuk menyalakan LED. |
| `delay(timeDelay);` | Menahan eksekusi program selama nilai variabel `timeDelay`. Ini menentukan seberapa lama LED menyala atau mati. |
| `digitalWrite(ledPin, LOW);` | Memutus tegangan pada Pin 6 sehingga LED mati. |
| `if (isSpeedingUp)` | Mengecek status arah kecepatan. Jika true, program akan menjalankan instruksi pengurangan delay (mempercepat). |
| `timeDelay -= 100;` | Operator pengurangan bertahap. Setiap satu siklus kedip, jeda dikurangi 100ms agar kedipan berikutnya terasa lebih cepat. |
| `if (timeDelay <= 100)` | Batas keamanan agar delay tidak bernilai 0 atau negatif. Saat mencapai 100ms, arah diubah ke fase melambat. |
| `timeDelay += 100;` | Operator penambahan bertahap. Menambah durasi delay sehingga interval kedipan semakin lama (melambat). |
| `if (timeDelay >= 1000)` | Mengecek apakah kecepatan sudah kembali ke kondisi terlambat (1 detik). |
| `delay(3000);` | Memberikan jeda statis selama 3 detik sebelum mengulang siklus dari awal (mempercepat kembali). |
