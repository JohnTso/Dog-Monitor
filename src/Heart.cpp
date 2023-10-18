#include "Heart.h"


const int THRESHOLD = 6;
int total_beat = 0, BPM = 0;
float total_time = 0;

bool checkHeartBeat(int beat, int prev_beat) {

  if (prev_beat - beat >= THRESHOLD) {
    total_beat++;
    return true;
  }
  return false;
}

void updateHeartBeat() {
  total_time += .1; // .1 second passes
  BPM = (total_beat/total_time) * 30;
  if (total_time == 60) {
    total_time = 0;
    total_beat = 0;
  }
}

int getBPM() {
  return BPM;
}
