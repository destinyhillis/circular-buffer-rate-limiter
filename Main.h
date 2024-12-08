#ifndef MAIN_H__
#define MAIN_H__

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

class CircularBuffer {
  private:
    vector<pair<string, system_clock::time_point>> buffer;
    int max_size;
    int head;
    int tail;
    bool full;

  public:
    CircularBuffer(int size);
    void put(string item);
    vector<pair<string, system_clock::time_point>> getBuffer();
    bool isEmpty();
    bool isFull();
    int size();
    bool isOldestEntryExpired(int time_limit);
    void printBuffer();
};

#endif // MAIN_H__