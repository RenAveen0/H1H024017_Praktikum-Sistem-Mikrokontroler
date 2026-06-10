# Modul 5 : Real-Time Operating System (RTOS)

## 🎯 Tujuan Praktikum

1. Memahami prinsip kerja, arsitektur dasar, dan manajemen penjadwalan pada *Real-Time Operating System* (RTOS) di dalam perangkat tertanam.
2. Mengimplementasikan pustaka FreeRTOS pada lingkungan Arduino untuk membangun aplikasi terstruktur berbasis sistem operasi.
3. Membuat sistem multitasking dan komunikasi antar-task secara concurrent untuk mengoptimalkan efisiensi pemrosesan data tanpa penundaan.

## 📄 Dasar Teori

Real-Time Operating System (RTOS) merupakan sistem operasi khusus yang dirancang untuk memenuhi kebutuhan pemrosesan data secara langsung (*real-time*) pada perangkat tertanam tanpa adanya penundaan eksekusi (*buffer*).

1. RTOS (Real-Time Operating System)  
Sistem operasi yang bekerja secara konsisten untuk menyelesaikan tugas-tugas kritis tepat waktu, baik dari segi akurasi pewaktu (*timing*) maupun urutan beban kerja aplikasi yang dieksekusi.

2. Soft RTOS  
Jenis sistem RTOS yang hampir selalu menyelesaikan tugas sesuai target waktu. Jika terjadi kegagalan pemenuhan batas waktu (*deadline*), dampak yang ditimbulkan tidak fatal atau berbahaya bagi sistem keseluruhan, melainkan hanya menyebabkan penurunan performa sistem.

3. Hard RTOS  
Jenis sistem RTOS yang memastikan setiap tugas wajib diselesaikan sebelum batas waktu (*deadline*). Kegagalan sekecil apa pun dalam memenuhi target waktu eksekusi dapat berakibat fatal dan menyebabkan kerusakan sistem secara total.

4. FreeRTOS  
Salah satu jenis kernel RTOS yang bersifat open-source, gratis, dan sangat populer digunakan pada mikrokontroler karena efisiensinya yang tinggi serta kemudahan integrasinya dalam ekosistem Arduino.

5. Antrean Tugas (Task Queue)  
Mekanisme pengiriman data terstruktur menggunakan memori buffer berbasis antrean untuk memfasilitasi pertukaran informasi antar-task yang berjalan secara konkuren secara aman tanpa risiko tumpang-tindih data.

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)

## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr align="center">
    <th>Arduino Uno R3</th>
    <th>DHT22</th>
    <th>Potensiometer 10 kΩ</th>
    <th>Resistor 220 Ω</th>
    <th>LED</th>
    <th>Breadboard</th>
    <th>Kabel Jumper</th>
  </tr>

  <tr align="center">
    <td>
      <img width="150" height="150" alt="img1" src="../Modul 5/Laporan Praktikum/Komponen/arduino.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img2" src="../Modul 5/Laporan Praktikum/Komponen/dht22.jpg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img3" src="../Modul 5/Laporan Praktikum/Komponen/potensiometer.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img4" src="../Modul 5/Laporan Praktikum/Komponen/resistor.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img5" src="../Modul 5/Laporan Praktikum/Komponen/led.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img6" src="../Modul 5/Laporan Praktikum/Komponen/breadboard.jpeg"><br>
    </td>
    <td>
      <img width="150" height="150" alt="img7" src="../Modul 5/Laporan Praktikum/Komponen/kabel jumper.jpeg"><br>
    </td>
  </tr>
</table>
</div>

## 💻 Percobaan

Eksperimen pada modul ini dibagi menjadi dua skenario utama untuk menguji pembagian tugas kernel operasi dan komunikasi data terstruktur.

1. Percobaan 5A: Multitasking  
  * Menguji kemampuan pengelolaan multi-tugas secara concurrent menggunakan fungsi `xTaskCreate()`. Penjadwal (*Kernel Scheduler*) membagi alokasi waktu pemrosesan secara adil untuk mengendalikan kedipan dua buah LED dengan interval ritme berbeda bersamaan dengan operasi perhitungan *counter*.

2. Percobaan 5B: Komunikasi Task  
  * Menguji implementasi jalur komunikasi data terstruktur antar-task menggunakan objek antrean (`QueueHandle_t`). Skenario ini melibatkan proses pengiriman paket data parameter oleh satu task produsen menggunakan fungsi `xQueueSend()` yang diterima dan diekstrak secara sinkron oleh task display melalui fungsi `xQueueReceive()`.

## 📚 Pertanyaan Praktikum

### A. Multitasking
1. Apakah ketiga task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!
2. Bagaimana cara menambahkan task keempat? Jelaskan langkahnya!
3. Modifikasilah program dengan menambah sensor (misalnya potensiometer), lalu gunakan nilainya untuk mengontrol kecepatan LED! Bagaimana hasilnya? Jelaskan program pada file README.md.

**Jawaban**
1. Task berjalan secara bergantian (pseudo-simultan). Karena Arduino Uno menggunakan mikrokontroler single-core, CPU sebenarnya hanya bisa mengeksekusi satu instruksi pada satu waktu. Namun, Kernel Scheduler FreeRTOS melakukan pengalihan tugas (context switching) dari satu task ke task lain dengan sangat cepat berdasarkan prioritas dan jatah waktu (time-slicing), sehingga terlihat seolah-olah berjalan bersamaan.
2. Berikut langkah-langkahnya:
  * Langkah 1: Buat prototipe fungsi task baru di bagian atas kode (misal: void TaskEmpat(void *pvParameters);).
  * Langkah 2: Daftarkan fungsi tersebut di dalam fungsi setup() menggunakan perintah xTaskCreate() dengan menentukan nama task, ukuran stack, dan prioritasnya.
  * Langkah 3: Buat badan fungsi task tersebut dengan perulangan tak terbatas (while(1) atau for(;;)), dan wajib menyertakan fungsi vTaskDelay() agar task lain mendapat giliran eksekusi.
3. Berikut perubahan kodenya:

Kode Program

```cpp
#include <Arduino_FreeRTOS.h>

// ===================== PIN SETUP =====================
const int potPin = A0; // Pin analog untuk potensiometer

// ===================== GLOBAL VARIABLE =====================
// Menggunakan 'volatile' karena nilai ini akan diubah oleh satu task 
// dan dibaca oleh task lainnya.
volatile int sharedDelay = 200; 

// Prototipe Fungsi Task
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void Taskprint(void *pvParameters);

void setup() {
  // Inisialisasi komunikasi serial pada 9600 bps:
  Serial.begin(9600);

  // Membuat Task
  xTaskCreate(TaskBlink1, "task1", 128, NULL, 1, NULL);
  xTaskCreate(TaskBlink2, "task2", 128, NULL, 1, NULL);
  xTaskCreate(Taskprint,  "task3", 128, NULL, 1, NULL);

  // Memulai Scheduler
  vTaskStartScheduler();
}

void loop() {
  // Kosong karena logika utama sudah dijalankan oleh FreeRTOS task
}

void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while (1) {
    Serial.println("Task1");
    digitalWrite(8, HIGH);
    // Menggunakan variabel delay dinamis dari potensiometer
    vTaskDelay(sharedDelay / portTICK_PERIOD_MS); 
    digitalWrite(8, LOW);
    vTaskDelay(sharedDelay / portTICK_PERIOD_MS);
  }
}

void TaskBlink2(void *pvParameters) {
  pinMode(7, OUTPUT);

  while (1) {
    Serial.println("Task2");
    digitalWrite(7, HIGH);
    // Task2 dibuat sedikit lebih lambat (rentang delay dikali 1.5) agar ritmenya berbeda
    vTaskDelay((sharedDelay * 1.5) / portTICK_PERIOD_MS); 
    digitalWrite(7, LOW);
    vTaskDelay((sharedDelay * 1.5) / portTICK_PERIOD_MS);
  }
}

void Taskprint(void *pvParameters) {
  int counter = 0;

  while (1) {
    // 1. Baca nilai potensiometer (0-1023)
    int potValue = analogRead(potPin);
    
    // 2. Petakan nilai ADC ke rentang delay (100ms hingga 1000ms)
    // Supaya RTOS tidak crash, batasi delay minimum jangan sampai 0ms.
    sharedDelay = map(potValue, 0, 1023, 100, 1000); 

    // 3. Tampilkan data ke Serial Monitor
    counter++;
    Serial.print("Counter: ");
    Serial.print(counter);
    Serial.print(" | Kedipan Delay: ");
    Serial.print(sharedDelay);
    Serial.println(" ms");

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
```

### B. Komunikasi Task
1. Apakah kedua task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!
2. Apakah program ini berpotensi mengalami race condition? Jelaskan!
3. Modifikasilah program dengan menggunakan sensor DHT sesungguhnya sehingga informasi yang ditampilkan dinamis. Bagaimana hasilnya? Jelaskan program pada file README.md.

**Jawaban**
1. Task berjalan secara bergantian dan alurnya disinkronisasi oleh Queue. Ketika task read_data selesai mengisi antrean data, ia akan memasuki kondisi block atau tidur lewat perintah vTaskDelay(). Pada momen itulah scheduler memberikan giliran kepada task display untuk berjalan dan mengosongkan antrean menggunakan xQueueReceive().
2. Tidak berpotensi. Program ini aman dari race condition karena proses pertukaran data tidak menggunakan variabel global secara langsung, melainkan menggunakan fitur Queue bawaan FreeRTOS. Fungsi queue secara internal sudah dilengkapi dengan mekanisme proteksi critical section yang memastikan data hanya bisa diakses oleh satu task pada satu waktu secara aman.
3. Berikut perubahan kodenya:

Kode Program

```cpp
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h> 

#define DHTPIN 2     
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE); 

// Trik 1: Mengubah struct ke 'int' untuk menghemat RAM dan Stack
struct readings {
  int temp; // Nilai asli x 10 (Contoh: 25.4 C disimpan sebagai 254)
  int h;    // Nilai asli x 10 (Contoh: 60.5 % disimpan sebagai 605)
};

QueueHandle_t my_queue;

void setup() {
  Serial.begin(9600);
  
  // Trik 2: Menggunakan F() agar string menetap di Flash Memory
  Serial.println(F("=== SYSTEM STARTING ==="));
  
  dht.begin(); 

  my_queue = xQueueCreate(1, sizeof(struct readings));

  // Karena tidak menggunakan float, ukuran stack bisa diturunkan dengan aman ke 110
  xTaskCreate(read_data, "read sensors", 110, NULL, 1, NULL);
  xTaskCreate(display,   "display",      110, NULL, 1, NULL);
  
  Serial.println(F("=== TASKS CREATED ==="));
}

void loop() {
  // Kosong
}

void read_data(void *pvParameters) {
  struct readings x;

  for (;;) {
    float t = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    if (!isnan(t) && !isnan(humidity)) {
      // Ubah float ke int dengan mengalikan 10
      x.temp = (int)(t * 10);
      x.h = (int)(humidity * 10);
      xQueueSend(my_queue, &x, portMAX_DELAY);
    } else {
      Serial.println(F("Gagal membaca DHT22!"));
    }
    
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}

void display(void *pvParameters) {
  struct readings x;

  for (;;) {
    if (xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) {
      // Trik 3: Menampilkan koma desimal menggunakan pembagian matematika (bukan float)
      Serial.print(F("temp = "));
      Serial.print(x.temp / 10); // Angka depan koma
      Serial.print(F("."));
      Serial.print(abs(x.temp % 10)); // Angka belakang koma
      Serial.println(F(" C"));
      
      Serial.print(F("humidity = "));
      Serial.print(x.h / 10);    // Angka depan koma
      Serial.print(F("."));
      Serial.print(abs(x.h % 10));   // Angka belakang koma
      Serial.println(F(" %"));
      Serial.println(F("--------------------"));
    }
  }
}
```