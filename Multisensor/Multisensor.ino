#include "DHT.h"
#include "WiFi.h"
#include "HTTPClient.h"

//definisikan pin untuk dht11
#define DHTPIN 4 
#define DHTTYPE DHT11

//LDR DIPASANG DI PIN VP = A0

//OBJECT UNTUK DHT
DHT dht (DHTPIN, DHTTYPE);

//siapkan variable untuk WiFi hotspot dan password
const char* ssid = "KontrakanGJLS";
const char* pass = "KucingAnjing3060";

//siapkan variabel host/ server yang menampung aplikasi web dan database
const char* host = "192.168.1.15";

void setup() {
  Serial.begin(9600);
  dht.begin();

//koneksi ke WiFi
WiFi.begin (ssid, pass);
Serial.println("Connecting...");
while(WiFi.status() != WL_CONNECTED)
{
  Serial.print(".");
  delay(500);
  }

  //apabalia berhasil terkoneksi
  Serial.println("Connected");
}


void loop() {
 int suhu = dht.readTemperature();
 int kelembapan = dht.readHumidity();

 int ldr = analogRead( A0 ) ;

// Serial.println("Suhu : " + String(suhu));
 Serial.println("Suhu : " + String(suhu));
 Serial.println("Kelembapan : " + String(kelembapan));
 Serial.println("LDR : " + String(ldr));

//kirim data ke server
WiFiClient client ;
//insisialisasi port ke server
const int httpPort = 80;
if(!client.connect(host, httpPort) )
{
  Serial.println("Connection Failed");
  return;
}
//kondisi pasati terkoneksi
//kirim data sensor ke database / web

String Link ;
HTTPClient http ;

Link = "http://" + String(host) + "/multisensor/kirimdata.php?suhu=" + String(suhu) + "&kelembapan=" + String(kelembapan) + "&ldr=" + String(ldr);
// eksekusi alamat link
http.begin(Link) ;
http.GET();

//baca respin setelah berhasil kirim nilai sensor
String respon = http.getString();
Serial.println(respon);
http.end();

delay(1000);

}
