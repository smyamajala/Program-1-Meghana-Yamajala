// Include the Timer class definition from our header file
#include "timer.hpp"

// CONSTRUCTOR
// think of this as calling back to the timer "class" we created in the .hpp file

Timer::Timer() {
    Reset();  // Start the timer as soon as the object is created
}

// RESET FUNCTION
// we are defining WHAT the reset function will do now
void Timer::Reset() {
    // Capture the current time from the high-resolution clock
    // This becomes our new starting point for timing measurements
    start_time = std::chrono::high_resolution_clock::now(); // straight from assignment 
}


// CURRENT TIME 
// gets time "elapsed"

double Timer::CurrentTime() const {
    // Capture the current time to compare with our start time
    
    auto end = std::chrono::high_resolution_clock::now();
    
    // calculate the time difference between end and start
    // std::chrono::duration<double, std::micro> will allow us to get the time in milliseconds
    // just like we wanted
    return std::chrono::duration<double, std::micro>(end - start_time).count();

// all in all you can think of this like a difference problem where we first get the time at the beginning and the end and then
// find the total amount of change...
// it's just mixed with fancy wording for some reason
}
