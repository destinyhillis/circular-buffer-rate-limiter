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
    // Constructor: Initializes the buffer with a specified size.
    CircularBuffer(int size);
    // put: Adds an item to the buffer with the current timestamp.
    void put(string item);
    // isEmpty: Checks if the buffer is empty.
    bool isEmpty();
  // isFull: Checks if the buffer is full.
    bool isFull();
    // size: Returns the current number of items in the buffer.
    int size();
    // isOldestEntryExpired: Checks if the oldest entry is older than the specified time limit.
    bool isOldestEntryExpired(int time_limit);
    // printBuffer: Prints all the elements in the buffer along with their timestamps.
    void printBuffer();
};

#endif // MAIN_H__