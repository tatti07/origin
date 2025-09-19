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

    
    cout << "�� ������ ������� ��������� �������� ��������? (��/���): "; 
    string answer;                                                     
    cin >> answer;                                                     

    int start = 0;                                                     
    if (answer == "��" || answer == "��" || answer == "y" || answer == "Y") { 
        cout << "������� ��������� ��������: ";                        
        cin >> start;                                                  
    }

    Counter c(start);                                                  

    
    char cmd{};                                                        
    do {                                                               
        cout << "������� ������� ('+' � ���������, '-' � ���������, '=' � ��������, 'x' � �����): "; 
        cin >> cmd;                                                    

        switch (cmd) {                                                 
        case '+': c.increment(); break;                            
        case '-': c.decrement(); break;                            
        case '=': cout << c.get() << endl; break;                  
        case 'x':  break;                             
        default:  cout << "����������� �������\n"; break;          
        }

    } while (cmd != 'x');                                              

    cout << "�� ��������!\n";                                          
    return 0;                                                          
}