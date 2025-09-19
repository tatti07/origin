#pragma once            
#include <iostream>     

class Counter {         
private:                
    int value;          
public:                 
    explicit Counter(int start = 0); 
    void increment();                
    void decrement();                
    int get() const;                 
};