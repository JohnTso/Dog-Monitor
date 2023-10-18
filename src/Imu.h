#include <Arduino_LSM9DS1.h>

bool initIMU();

bool getIMUValues(float *ax, float*ay, float*az, float *gx, float*gy, float*gz);