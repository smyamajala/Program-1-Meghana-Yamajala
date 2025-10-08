// Include the Timer class definition from our header file
#include "timer.hpp"

/**
 * TIMER CONSTRUCTOR
 * 
 * Creates a Timer object and immediately starts timing
 * When you create a Timer, it automatically begins counting
 * from the moment of creation
 */
Timer::Timer() {
    Reset();  // Start the timer as soon as the object is created
}

/**
 * RESET METHOD
 * 
 * Restarts the timer by setting the start_time to the current moment
 * Use this when you want to begin timing a new operation
 * This is like pressing the "reset" button on a stopwatch
 */
void Timer::Reset() {
    // Capture the current time from the high-resolution clock
    // This becomes our new starting point for timing measurements
    start_time = std::chrono::high_resolution_clock::now();
}

/**
 * CURRENTTIME METHOD
 * 
 * Calculates how much time has elapsed since the last Reset()
 * Returns the time in microseconds (millionths of a second)
 * 
 * @return: elapsed time in microseconds as a double precision number
 */
double Timer::CurrentTime() const {
    // Capture the current time to compare with our start time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the time difference between end and start
    // std::chrono::duration<double, std::micro> means:
    // - Measure the duration as a double-precision number
    // - Convert it to microseconds (millionths of a second)
    // - .count() extracts the numerical value from the duration object
    return std::chrono::duration<double, std::micro>(end - start_time).count();
}
