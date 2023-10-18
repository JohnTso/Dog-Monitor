#define SENSOR_PIN A0
#include "src/Imu.h"
#include "src/Heart.h"


void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  if (!initIMU()) {
    Serial.println("Failed to initialize IMU!");
  }
}

float ax, ay, az;
float gx, gy, gz;
int beat = 0, prev_beat = 7;
int delay_count = 0, tb = 0;
void loop() {
  getIMUValues(&ax, &ay, &az, &gx, &gy, &gz);
  // Serial.print("ax: "); Serial.println(ax);
  // Serial.print("ay: "); Serial.println(ay);
  // Serial.print("az: "); Serial.println(az);

  beat = analogRead(A0);
  checkHeartBeat(beat, prev_beat);
  // if (t) {
  //   tb++;
  //   Serial.print("total beat: "); Serial.println(tb);
  //   Serial.print(delay_count*100); Serial.println(" ms");
  //   delay_count = 0;
  // }
  updateHeartBeat();
  if (delay_count == 10) {
    Serial.print("BPM: "); Serial.println(getBPM());
    delay_count = 0;
  }
  delay_count++;
  prev_beat = beat;

  delay(100);
}
