#include <iostream>
#include <string>


struct Address {
    std::string city;     
    std::string street;   
    int house;            
    int flat;             
    int index;            
};
void printAddress(const Address& addr) {
    std::cout << "Город: " << addr.city << std::endl;
    std::cout << "Улица: " << addr.street << std::endl;
    std::cout << "Номер дома: " << addr.house << std::endl;
    std::cout << "Номер квартиры: " << addr.flat << std::endl;
    std::cout << "Индекс: " << addr.index << std::endl;
}
int main() {
    Address addr1;  
    

    
    std::cout << "Введите город: ";
    std::cin >> addr1.city;
    std::cout << "Введите улицу: ";
    std::cin >> addr1.street;
    std::cout << "Введите номер дома: ";
    std::cin >> addr1.house;
    std::cout << "Введите номер квартиры: ";
    std::cin >> addr1.flat;
    std::cout << "Введите индекс: ";
    std::cin >> addr1.index;

    

    std::cout << "\n Адрес:\n";
    printAddress(addr1);

    
    return 0;
}
