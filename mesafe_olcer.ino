// Pinleri tanımlıyoruz
 int trigPin = 9;
 int echoPin = 10;

// Değişkenleri tanımlıyoruz
long sure;
int uzaklik;

void setup() {
  // Seri iletişimi başlatıyoruz
  Serial.begin(9600);
  
  // Pin modlarını belirliyoruz
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trig pini kapalı
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  
  // Trig pini açık
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo pininden gelen darbe süresini ölçüyoruz
  sure = pulseIn(echoPin, HIGH);

  // Mesafeyi hesaplıyoruz (örneğin: ses hızı 340 m/s)
  uzaklik = sure * 0.034 / 2;

  // Serial monitore mesafeyi yazdırıyoruz
  Serial.print("Mesafe: ");
  Serial.print(uzaklik);
  Serial.println(" cm");
  
  delay(100); // Bir süre bekliyoruz
}
