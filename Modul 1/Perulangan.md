# Pertanyaan Praktikum
4. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

## Jawaban

Program ini mengontrol dua kelompok LED (3 kiri dan 3 kanan) untuk menyala secara bergantian menggunakan perulangan `for`.

### Kode Program
```cpp
int timer = 500; // Jeda waktu antar pergantian (0.5 detik)

void setup() {
    // Inisialisasi pin 2 sampai 7 sebagai OUTPUT menggunakan loop
    for (int ledPin = 2; ledPin < 8; ledPin++) {
        pinMode(ledPin, OUTPUT);
    }
}

void loop() {
    // --- LANGKAH 1: MENYALAKAN 3 LED KIRI (Pin 2, 3, 4) ---
    for (int i = 2; i <= 4; i++) {
        digitalWrite(i, HIGH); // Nyalakan pin 2, 3, 4
    }
    for (int i = 5; i <= 7; i++) {
        digitalWrite(i, LOW);  // Pastikan pin 5, 6, 7 mati
    }
    delay(timer);             // Tunggu selama 500ms

    // --- LANGKAH 2: MENYALAKAN 3 LED KANAN (Pin 5, 6, 7) ---
    for (int i = 2; i <= 4; i++) {
        digitalWrite(i, LOW);  // Matikan pin 2, 3, 4
    }
    for (int i = 5; i <= 7; i++) {
        digitalWrite(i, HIGH); // Nyalakan pin 5, 6, 7
    }
    delay(timer);             // Tunggu selama 500ms
}
```

### Penjelasan baris kode
| Baris Kode | Penjelasan |
| :---: | :---: |
| `int timer = 500;` | Menentukan variabel delay sebesar 500 milidetik. |
| `for (int ledPin = 2; ledPin < 8; ledPin++)` | Loop singkat untuk mengatur pin 2, 3, 4, 5, 6, dan 7 menjadi OUTPUT sekaligus. |
| `for (int i = 2; i <= 4; i++)` | Loop untuk mengakses kelompok "Kiri". Pin yang diproses adalah 2, 3, dan 4. |
| `digitalWrite(i, HIGH);` | Memberikan perintah nyala pada pin yang sedang aktif di dalam loop. |
| `delay(timer);` | Memberikan jeda agar mata manusia bisa menangkap perubahan nyala LED. |
| `digitalWrite(i, LOW);` | Memberikan perintah mati pada pin agar terjadi efek bergantian. |
