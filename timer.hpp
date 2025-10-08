#ifndef TIMER_H
#define TIMER_H

#include <chrono> // apparantly I need this built in 

// literally getting this straight from the assignment... 

class Timer {
private:
    std::chrono::high_resolution_clock::time_point start_time; 

public:

// this Timer will start the timer when an object is created
    Timer();
    
// this resets the timer before starting a new operation
// this is incredibly useful when looking at multiple search methods
// in the main function we will be implementing a switch case and in that switch case
// resetting the timer will be crucial 

    void Reset();
    
// this will tell us the time elapsed in milliseconds
// we are using a double here for the sake of precision
    double CurrentTime() const;
};

#endif // TIMER_H
