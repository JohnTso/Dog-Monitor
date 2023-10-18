#include <Arduino_LSM9DS1.h>

bool initIMU() {
  return IMU.begin();
}

bool getIMUValues(float *ax, float*ay, float*az, float *gx, float*gy, float*gz) {

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(*ax, *ay, *az);
  } else {
    return false;
  }

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(*gx, *gy, *gz);
    return true;
  } 
  return false;
}