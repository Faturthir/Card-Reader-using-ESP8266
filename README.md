# ESP8266 RFID Reader

Proyek ini menggunakan ESP8266 dan modul RFID MFRC522 untuk membaca kartu RFID dan menampilkan UID-nya melalui komunikasi serial. Selain itu, ESP8266 akan terhubung ke jaringan Wi-Fi.

## Perangkat yang Digunakan
- ESP8266 (misalnya, NodeMCU)
- Modul RFID MFRC522
- Kabel jumper

## Instalasi Perpustakaan
Sebelum mengunggah kode ke ESP8266, pastikan Anda telah menginstal pustaka berikut pada Arduino IDE:
- `MFRC522` (untuk modul RFID)
- `ESP8266WiFi` (untuk koneksi Wi-Fi)

Cara menginstal pustaka:
1. Buka Arduino IDE.
2. Pergi ke **Sketch** > **Include Library** > **Manage Libraries**.
3. Cari `MFRC522` dan `ESP8266WiFi`, lalu klik **Install**.

## Wiring
Hubungkan modul RFID ke ESP8266 seperti berikut:

|RFID MFRC522| ESP8266 |
|------------|---------|
| VCC        | 3.3V    |
| GND        | GND     |
| SDA (SS)   | D4      |
| SCK        | D5      |
| MOSI       | D7      |
| MISO       | D6      |
| RST        | D3      |

## Konfigurasi Wi-Fi
Ubah SSID dan password Wi-Fi pada kode berikut sebelum mengunggah ke ESP8266:
```cpp
const char* ssid = "Nama_WiFi";
const char* password = "Password_WiFi";
```

## Cara Penggunaan
1. Sambungkan ESP8266 ke komputer menggunakan kabel USB.
2. Buka Arduino IDE dan unggah kode ke ESP8266.
3. Buka Serial Monitor (Baudrate: 115200).
4. Tempelkan kartu RFID ke modul RFID MFRC522.
5. Lihat UID kartu yang terbaca di Serial Monitor.

## Output Contoh
Saat perangkat berhasil terhubung ke Wi-Fi, Serial Monitor akan menampilkan:
```
Menghubungkan ke WiFi...
Terhubung ke WiFi
Alamat IP: 192.168.1.100
Letakkan kartu RFID di dekat pembaca...
UID Kartu: 12 34 56 78
```

## Lisensi
Proyek ini bersifat open-source dan dapat digunakan untuk keperluan edukasi atau pengembangan lebih lanjut.

