#include "Main.h"

CircularBuffer::CircularBuffer(int size) : buffer(size), max_size(size), head(0), tail(0), full(false) {}

void CircularBuffer::put(string item)
{
  auto now = system_clock::now();
  buffer[head] = make_pair(item, now);
  if (full)
  {
    tail = (tail + 1) % max_size;
  }
  head = (head + 1) % max_size;
  full = head == tail;
}

bool CircularBuffer::isEmpty()
{
  return (!full && (head == tail));
}

bool CircularBuffer::isFull()
{
  return full;
}

int CircularBuffer::size()
{
  int size = max_size;
  if (!full)
  {
    if (head >= tail)
    {
      size = head - tail;
    }
    else
    {
      size = max_size + head - tail;
    }
  }
  return size;
}

bool CircularBuffer::isOldestEntryExpired(int time_limit)
{
  if (isEmpty())
  {
    cout << ("Buffer is empty") << endl;
    return false;
  }
  auto now = system_clock::now();
  auto oldest = buffer[tail].second;
  auto diff = now - oldest;
  if (diff > seconds(time_limit))
    cout << "Oldest entry is " << duration_cast<seconds>(diff).count() << " seconds old and will be removed." << endl;
  // return true if the oldest entry is older than the time limit
  return diff > seconds(time_limit);
}

void CircularBuffer::printBuffer()
{
  if (isEmpty())
  {
    cout << "Buffer is empty" << endl;
    return;
  }

  int index = tail;

  cout << "Buffer: " << endl;

  while (true)
  {
    auto entry = buffer[index];
    auto time_since_epoch = entry.second.time_since_epoch();
    auto sec = duration_cast<seconds>(time_since_epoch).count();
    cout << "Item: " << entry.first << ", Timestamp: " << sec << " seconds since epoch" << endl;

    if (index == head && !full)
    {
      return;
    }
    // wraps around to the beginning of the buffer using the modulo if the index exceeds the max size
    index = (index + 1) % max_size;
    if (index == head && full)
    {
      return;
    }
  }
}

int main()
{
  // explain the program to the user
  cout << "This program simulates a password entry system and you are going to try a brute-force attack." << endl;
  cout << "To simulate multiple attempts to enter a password, you will be asked to enter any string multiple times until you hit the limit of attempts within the time limit. You will be asked to set both of these limits." << endl;
  cout << endl;

  // allow the user to set the size of the buffer and make that the limit of attempts
  int buffer_size;
  cout << "Enter the limit of attempts. This will be the size of the circular buffer: ";
  cin >> buffer_size;
  cin.ignore(); // To ignore the newline character left in the buffer

  int time_limit;
  cout << "Enter the time limit in seconds: ";
  cin >> time_limit;
  cin.ignore(); // To ignore the newline character left in the buffer

  // create a circular buffer with the size limit
  CircularBuffer cb(buffer_size);
  // create a string variable to store the user input
  string input;

  while (true)
  {
    // ask for input from user, make them enter a string, then hit enter
    cout << "Enter password: ";
    cin >> input;

    // check if the buffer is full
    // if not full, add the input to the buffer
    if (!cb.isFull())
    {
      cb.put(input);
    }
    else
    {
      // if buffer is full, check the timestamp of each entry
      // if the oldest entry is older than 1 minute, remove it, shift the rest of the entries, and add the new entry to head
      if (cb.isOldestEntryExpired(time_limit))
      {
        cb.put(input);
        cb.printBuffer();
      }
      else
      {
        // if the oldest entry is not older than 1 minute, print error message
        cout << "Too many failed attempts. Please restart program to try again." << endl;
        return 0;
      }
    }
  }
  return 0;
}