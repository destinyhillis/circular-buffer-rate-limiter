# **Circular Buffer Rate Limiter**

## Introduction
This project aims to implement a Rate Limiter using a circular buffer in C++. A circular buffer is a fixed-size, cyclic data structure that overwrites the oldest elements when it becomes full to efficiently manage space and operations. The circular buffer in this application will efficiently track timestamps of recent actions, enforcing limits on operations within a defined time window.

Rate limiters are interesting because they are widely used in:
- Web Servers and APIs: To control client requests and prevent overloading.
- Gaming Platforms: To throttle user actions and ensure fairness.
- Authentication Systems: To limit login attempts and prevent brute-force attacks.

## Proposed Solution
The rate limiter will:
1. Track Events: Use a circular buffer to store timestamps of recent actions.
2. Enforce Limits: Block actions when the buffer contains the maximum allowed timestamps within the time window.
3. Optimize Operations: Leverage the circular buffer's constant-time insertions and deletions.

## Implementation Overview

### Data Structure:
- Implement a circular buffer to store timestamps as integers (e.g., nanoseconds since epoch).
- Use a pointer to track the oldest timestamp, enabling efficient overwriting.

### Key Algorithms:
- Insert: Add the current timestamp when an action occurs.
- Delete: Overwrite the oldest timestamp when the buffer is full.
- Validation: Check if all timestamps are within the defined time window. If so, block the action

## Stretch Goals
### Configurable Parameters:
- Maximum Actions: Limit the number of actions (e.g., 10 per minute).
- Time Window: Define the duration for tracking actions (e.g., 60 seconds).