#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>  // Pustaka Wi-Fi untuk ESP8266
#define SS_PIN D4   // Pin SDA (gunakan D4 pada ESP8266)
#define RST_PIN D3  // Pin Reset (gunakan D3 pada ESP8266)

const char* ssid = "A53s";         // Ganti dengan SSID WiFi kamu
const char* password = "11111111"; // Ganti dengan password WiFi kamu

MFRC522 rfid(SS_PIN, RST_PIN);  // Membuat instance dari kelas MFRC522

void setup() {
  Serial.begin(115200);   // Inisialisasi komunikasi serial
  SPI.begin();            // Inisialisasi bus SPI
  rfid.PCD_Init();        // Inisialisasi pembaca MFRC522

  // Koneksi ke Wi-Fi
  Serial.print("Menghubungkan ke WiFi");
  WiFi.begin(ssid, password);

  // Menunggu sampai tersambung ke Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("Terhubung ke WiFi");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("Letakkan kartu RFID di dekat pembaca...");
}

void loop() {
  // Jika tidak ada kartu baru yang terdeteksi
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;  // Tidak ada kartu yang terdeteksi
  }

  // Membaca UID kartu
  Serial.print("UID Kartu: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Menghentikan PICC dan menghentikan enkripsi di PCD
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay(150);  // Penundaan kecil sebelum melakukan pembacaan berikutnya
}
