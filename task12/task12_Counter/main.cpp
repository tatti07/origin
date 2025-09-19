#include <iostream>       
#include <string>         
#include <Windows.h>      
#include "counter.h"      

int main() {              
    
    SetConsoleOutputCP(65001);   
    SetConsoleCP(65001);        

    using std::cout;             
    using std::cin;              
    using std::string;           
    using std::endl;             

    
    cout << "¬ы хотите указать начальное значение счетчика? (да/нет): "; 
    string answer;                                                     
    cin >> answer;                                                     

    int start = 0;                                                     
    if (answer == "да" || answer == "ƒа" || answer == "y" || answer == "Y") { 
        cout << "¬ведите начальное значение: ";                        
        cin >> start;                                                  
    }

    Counter c(start);                                                  

    
    char cmd{};                                                        
    do {                                                               
        cout << "¬ведите команду ('+' Ч увеличить, '-' Ч уменьшить, '=' Ч показать, 'x' Ч выход): "; 
        cin >> cmd;                                                    

        switch (cmd) {                                                 
        case '+': c.increment(); break;                            
        case '-': c.decrement(); break;                            
        case '=': cout << c.get() << endl; break;                  
        case 'x':  break;                             
        default:  cout << "Ќеизвестна€ команда\n"; break;          
        }

    } while (cmd != 'x');                                              

    cout << "ƒо свидани€!\n";                                          
    return 0;                                                          
}