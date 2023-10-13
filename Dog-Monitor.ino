#include <Arduino_HTS221.h>
#include <Arduino_LSM9DS1.h>

// float temp, humidity;
float ax, ay, az;
float gx, gy, gz;
int degreesX, degreesY;

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
  }

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1) {}
  }
}

void loop() {
  // temp = HTS.readTemperature();
  // humidity = HTS.readHumidity();

  // Serial.print("Temperature = "); Serial.print(temp); Serial.println(" C");

  // Serial.print("Humidity = "); Serial.print(humidity); Serial.println(" %");

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(ax, ay, az);
  }

  // Serial.print("ax: "); Serial.println(ax);
  // Serial.print("ay: "); Serial.println(ay);
  // Serial.print("az: "); Serial.println(az);

  // if (IMU.gyroscopeAvailable()) {
  //   IMU.readGyroscope(gx, gy, gz);
  // }

  // Serial.print("gx: "); Serial.println(gx);
  // Serial.print("gy: "); Serial.println(gy);
  // Serial.print("gz: "); Serial.println(gz);
  if (ax > 0.1) {
    ax = 100 * ax;
    degreesX = map(ax, 0, 97, 0, 90);
    Serial.print("Tilting up ");
    Serial.print(degreesX);
    Serial.println("  degrees");
  }
  if (ax < -0.1) {
    ax = 100 * ax;
    degreesX = map(ax, 0, -100, 0, 90);
    Serial.print("Tilting down ");
    Serial.print(degreesX);
    Serial.println("  degrees");
  }
  if (ay > 0.1) {
    ay = 100 * ay;
    degreesY = map(ay, 0, 97, 0, 90);
    Serial.print("Tilting left ");
    Serial.print(degreesY);
    Serial.println("  degrees");
  }
  if (ay < -0.1) {
    ay = 100 * ay;
    degreesY = map(ay, 0, -100, 0, 90);
    Serial.print("Tilting right ");
    Serial.print(degreesY);
    Serial.println("  degrees");
  }
  delay(1000);
}
