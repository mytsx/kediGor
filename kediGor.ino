#define TRIG_PIN_1 10 // Birinci sensör için trig pini
#define ECHO_PIN_1 9  // Birinci sensör için echo pini
#define TRIG_PIN_2 6  // İkinci sensör için trig pini
#define ECHO_PIN_2 5  // İkinci sensör için echo pini
#define LED_PIN_1 2   // Birinci pencere için LED pini
#define LED_PIN_2 3   // İkinci pencere için LED pini
#define BUZZER_PIN 12 // Buzzer için pin

const float THRESHOLD_PERCENT = 8.0; // Mesafe değişim eşiği (%8)
const long MAX_VALID_DISTANCE = 75;   // Maksimum geçerli mesafe (cm)
bool isAlertActive1 = false;          // Birinci sensör alarm durumu
bool isAlertActive2 = false;          // İkinci sensör alarm durumu

void setup() {
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Mesafe ölçümü başlıyor...");
}

void loop() {
  // Birinci sensör için mesafe ölçümü
  long currentDistance1 = getDistance(TRIG_PIN_1, ECHO_PIN_1);

  // Geçersiz ölçüm kontrolü - Birinci sensör
  if (currentDistance1 > MAX_VALID_DISTANCE || currentDistance1 == 0) {
    Serial.println("Birinci sensör: Geçersiz ölçüm");
    deactivateAlert(1);
  } else {
    Serial.print("Birinci sensör mesafesi: ");
    Serial.print(currentDistance1);
    Serial.println(" cm");

    if (isSignificantChange(MAX_VALID_DISTANCE, currentDistance1)) {
      activateAlert(1);
    } else {
      deactivateAlert(1);
    }
  }

  // İkinci sensör için mesafe ölçümü
  long currentDistance2 = getDistance(TRIG_PIN_2, ECHO_PIN_2);

  // Geçersiz ölçüm kontrolü - İkinci sensör
  if (currentDistance2 > MAX_VALID_DISTANCE || currentDistance2 == 0) {
    Serial.println("İkinci sensör: Geçersiz ölçüm");
    deactivateAlert(2);
  } else {
    Serial.print("İkinci sensör mesafesi: ");
    Serial.print(currentDistance2);
    Serial.println(" cm");

    if (isSignificantChange(MAX_VALID_DISTANCE, currentDistance2)) {
      activateAlert(2);
    } else {
      deactivateAlert(2);
    }
  }

  delay(500); // Ölçümler arasında kısa bekleme
}

// Mesafeyi ölçen fonksiyon
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  // Yankının ölçülmediği durumda sıfır döndür
  if (duration == 0) {
    return MAX_VALID_DISTANCE + 1; // Geçersiz mesafe
  }

  long distance = duration * 0.034 / 2; // Mesafe cm cinsinden
  return distance;
}

// Mesafe değişim kontrolü
bool isSignificantChange(long baseline, long current) {
  float changePercent = abs(baseline - current) / (float)baseline * 100;
  return changePercent > THRESHOLD_PERCENT;
}

// Melodi için tanımlama
void playMelody() {
  int melody[] = {262, 262, 392, 392, 440, 440, 392}; // C, C, G, G, A, A, G
  int durations[] = {100, 100, 100, 100, 100, 100, 150}; // Nota süreleri (ms)

  for (int i = 0; i < 7; i++) {
    tone(BUZZER_PIN, melody[i]);
    delay(durations[i]);
    noTone(BUZZER_PIN);
    delay(150); // Nota arası kısa duraklama
  }
}

// Uyarıyı etkinleştirme
void activateAlert(int sensor) {
  if (sensor == 1 && !isAlertActive1) {
    isAlertActive1 = true;
    digitalWrite(LED_PIN_1, HIGH); // Birinci LED yanar
    playMelody(); // Melodi çalar
  }
  if (sensor == 2 && !isAlertActive2) {
    isAlertActive2 = true;
    digitalWrite(LED_PIN_2, HIGH); // İkinci LED yanar
    playMelody(); // Melodi çalar
  }
}

// Uyarıyı devre dışı bırakma
void deactivateAlert(int sensor) {
  if (sensor == 1 && isAlertActive1) {
    isAlertActive1 = false;
    digitalWrite(LED_PIN_1, LOW); // Birinci LED söner
    noTone(BUZZER_PIN);
  }
  if (sensor == 2 && isAlertActive2) {
    isAlertActive2 = false;
    digitalWrite(LED_PIN_2, LOW); // İkinci LED söner
    noTone(BUZZER_PIN);
  }
}
