#include "esp_camera.h"
#include <WiFi.h>

// WARNING!!! Make sure that you have either selected ESP32 Wrover Module,
//            or another board which has PSRAM enabled
// Select camera model

#define CAMERA_MODEL
const char* ssid = "Xperia XA1 Plus_1708"; //Xperia XA1 Plus_1708 // TP-Link_BC48
const char* password = "anderson12345"; //57294537

#if defined(CAMERA_MODEL)
#define PWDN_GPIO_NUM    -1
#define RESET_GPIO_NUM   -1//2
#define XCLK_GPIO_NUM    14//21
#define SIOD_GPIO_NUM    21//26
#define SIOC_GPIO_NUM    22//27
#define Y9_GPIO_NUM      34//35
#define Y8_GPIO_NUM      35//34
#define Y7_GPIO_NUM      36//32
#define Y6_GPIO_NUM      39
#define Y5_GPIO_NUM      23//19
#define Y4_GPIO_NUM      19//18
#define Y3_GPIO_NUM      18//5
#define Y2_GPIO_NUM      5//4
#define VSYNC_GPIO_NUM   32//25
#define HREF_GPIO_NUM    33//23
#define PCLK_GPIO_NUM    27//22

#else
#error "Camera model not selected"
#endif

void startCameraServer();

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  //init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  //drop down frame size for higher initial frame rate
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_QVGA);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000);
}
