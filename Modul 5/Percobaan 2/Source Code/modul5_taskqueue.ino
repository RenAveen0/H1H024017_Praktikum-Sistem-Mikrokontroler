#include <Arduino_FreeRTOS.h>
#include <queue.h>

// Struktur Data untuk Queue
struct readings {
  int temp;
  int h;
};

QueueHandle_t my_queue;

void setup() {
  Serial.begin(9600);

  // Membuat Queue
  my_queue = xQueueCreate(1, sizeof(struct readings));

  // Membuat Task
  xTaskCreate(read_data, "read sensors", 128, NULL, 0, NULL);
  xTaskCreate(display,   "display",      128, NULL, 0, NULL);
}

void loop() {
  // Kosong karena logika dijalankan oleh FreeRTOS task
}

/*
 * Blink task.
 * See Blink_AnalogRead example.
 */
void read_data(void *pvParameters) {
  struct readings x;

  for (;;) {
    x.temp = 54;
    x.h = 30;
    
    // Mengirim data ke queue
    xQueueSend(my_queue, &x, portMAX_DELAY);
    vTaskDelay(100 / portTICK_PERIOD_MS); 
  }
}

void display(void *pvParameters) {
  struct readings x;

  for (;;) {
    // Menerima data dari queue
    if (xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) {
      Serial.print("temp = ");
      Serial.println(x.temp);
      Serial.print("humidity = ");
      Serial.println(x.h);
    }
  }
}