#define SENSOR_PIN A0

bool checkHeartBeat(int beat, int prev_beat);

void updateHeartBeat();

int getBPM();

int getAverage();
