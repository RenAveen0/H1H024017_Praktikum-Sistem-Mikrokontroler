# Source Code - Percobaan 3A: Komunikasi Serial (UART)

Folder ini berisi kode program untuk mengendalikan status menyala atau matinya lampu LED secara *real-time* melalui pengiriman karakter perintah dari Serial Monitor menggunakan protokol komunikasi serial UART.

## 📄 Penjelasan Logika Program

Kode program bekerja dengan memantau data yang dikirim oleh komputer melalui media komunikasi serial. Berikut adalah alur logikanya:

1. Inisialisasi Awal: 
   * Komunikasi serial diaktifkan pada fungsi `setup()` dengan kecepatan transmisi data sebesar 9600 baud menggunakan `Serial.begin(9600)`.
   * Pin Digital 8 dikonfigurasi sebagai `OUTPUT` tempat lampu LED terhubung.

2. Pengecekan Buffer Serial (Polling):
   * Di dalam fungsi `loop()`, mikrokontroler menggunakan perintah `Serial.available()` untuk memantau apakah ada data karakter baru yang masuk dan tersimpan di dalam circular buffer.

3. Evaluasi Karakter Perintah:
   * Jika data terdeteksi tersedia (`> 0`), program akan membaca karakter tersebut menggunakan fungsi `Serial.read()`.
   * Melalui struktur percabangan `if-else`, karakter yang terbaca dievaluasi:
     * Karakter `'1'`: Mengubah pin 8 menjadi `HIGH` (LED menyala) serta mengirimkan konfirmasi teks "LED ON" kembali ke Serial Monitor.
     * Karakter `'0'`: Mengubah pin 8 menjadi `LOW` (LED mati) serta mengirimkan konfirmasi teks "LED OFF" kembali ke Serial Monitor.
     * Karakter Lainnya: Mengabaikan input dan memunculkan pesan peringatan "Perintah tidak dikenal" pada layar Serial Monitor.

## 🛠️ Konfigurasi Pin

| Komponen | Pin Arduino | Modus | Keterangan |
|---|---|---|---|
| LED (Anoda) | Pin 8 | `OUTPUT` | Pin digital output untuk mengontrol status daya LED. |
| LED (Katoda) | GND | — | Dihubungkan ke pin Ground melalui Resistor 220 Ω sebagai pembatas arus. |