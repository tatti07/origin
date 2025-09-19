#include "counter.h"            

Counter::Counter(int start)     
    : value(start)               
{
}                               

void Counter::increment() {      
    ++value;                     
}

void Counter::decrement() {      
    --value;                     
}

int Counter::get() const {       
    return value;                
}