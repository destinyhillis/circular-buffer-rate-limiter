# Circular Buffer Rate Limiter

This project implements a Rate Limiter using a circular buffer in C++. The circular buffer efficiently tracks timestamps of recent actions, enforcing limits on operations within a defined time window. For more information, please see the [project proposal](project-proposal.md).

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building the Project](#building-the-project)
    - [Using g++](#using-g)
    - [Using CMake](#using-cmake)
    - [Running the Program](#running-the-program)
- [Usage](#usage)
- [Code Overview](#code-overview)
  - [CircularBuffer Class](#circularbuffer-class)
- [Walkthrough Video](#walkthrough-video)

## Features

- **Circular Buffer**: Efficiently manages a fixed-size buffer that wraps around when it reaches the end.
- **Timestamp Tracking**: Each entry in the buffer is stored with a timestamp to track when the action occurred.
- **Rate Limiting**: Enforces a limit on the number of operations that can be performed within a specified time window.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- CMake (optional, for building the project)

### Building the Project

You can build the project using a C++ compiler or CMake.

#### Using g++

```sh
g++ -std=c++11 -o rate_limiter main.cpp
```

#### Using CMake
1. Create a build directory:
```sh
mkdir build
cd build
```

2. Run CMake and build:
```sh
cmake ..
make
```

3. Running the Program
After building the project with either g++ or CMake, you can run the program with the following command:
  
```sh
./rate_limiter
```

The program will prompt you to enter the size of the circular buffer (limit of attempts) and the time limit in seconds. You can then enter strings to simulate password attempts. The program will enforce the rate limit based on the provided parameters.

## Usage
Enter the limit of attempts: This sets the size of the circular buffer.
Enter the time limit in seconds: This sets the time window for rate limiting.
Enter strings (password attempts): The program will track these attempts and enforce the rate limit.
Example:
```sh
Enter the limit of attempts. This will be the size of the circular buffer: 5
Enter the time limit in seconds: 60
Enter password: password1
Enter password: password2
Enter password: password3
Enter password: password4
Enter password: password5
# Sixth attempt entered after 60 second limit will replace the oldest entry.
Enter password: password6
Oldest entry is older than 60 seconds and will be removed.
Buffer contents:
Item: password2, Timestamp: 1633024800 seconds since epoch
Item: password3, Timestamp: 1633024801 seconds since epoch
Item: password4, Timestamp: 1633024802 seconds since epoch
Item: password5, Timestamp: 1633024803 seconds since epoch
Item: password6, Timestamp: 1633024804 seconds since epoch
# Seventh attempt will be blocked due to rate limiting if it is attempted before the 60 second limit.
Enter password: password7
Too many failed attempts. Please restart program to try again.
```

## Code Overview

### CircularBuffer Class
- **Constructor**: Initializes the buffer with a specified size.
- **put**: Adds an item to the buffer with the current timestamp.
- **isEmpty**: Checks if the buffer is empty.
- **isFull**: Checks if the buffer is full.
- **size**: Returns the current number of items in the buffer.
- **isOldestEntryExpired**: Checks if the oldest entry is older than the specified time limit.
- **printBuffer**: Prints all the elements in the buffer along with their timestamps.

## Walkthrough Video
[![Walkthrough Video](https://img.youtube.com/vi/VIDEO-ID/0.jpg)](https://www.youtube.com/watch?v=VIDEO-ID)
