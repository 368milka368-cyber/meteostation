  #include <DHT.h>
  DHT dht(A2, DHT22);
  #include <BH1750.h> // подключаем библиотеку для датчика
  #include <Wire.h> // подключаем библиотеку для работы с I2C
  BH1750 lightMeter;
  void setup() {
    pinMode(A1, INPUT);
    Serial.begin(9600);
    dht.begin();
    Wire.begin(); // инициализируем шину I2C (библиотека BH1750 этого не делает автоматически)
    lightMeter.begin(); // инициализируем датчик
    Serial.println(F("BH1750 Test begin"));
  }

  void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // выводим температуру (t) и влажность (h) на жк дисплей
    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.print("Temperature: ");
    Serial.println(t);

    int sensorValue = analogRead(A0);

    Serial.print("Sensor ultraviolet = ");
    Serial.println(sensorValue);
    float lux = lightMeter.readLightLevel(); // считываем уровень освещённости
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
    int water = analogRead(A1);
    Serial.print("Water: ");
    Serial.println(water);
    Serial.println("===================================");
    delay(5000);
  }