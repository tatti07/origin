#include <iostream>
#include <fstream>
#include <string>



class Address {
private:
    std::string city;
    std::string street;
    int house;
    int flat;

public:
    
    Address(std::string setCity, std::string setStreet, int setHouse, int setFlat)
        : city(setCity), street(setStreet), house(setHouse), flat(setFlat) {}

    
    std::string get_output_address() const {
        return city + ", " + street + ", "
             + std::to_string(house) + ", " + std::to_string(flat);
    }

    
    const std::string& get_city() const { return city; }
};

void sort(Address** addresses, int size) {
    if (size <= 1) return;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (addresses[j]->get_city() > addresses[j + 1]->get_city()) {
                
                Address* tmp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = tmp;
            }
        }
    }
}

int main() {
    std::ifstream fin("in.txt");   
    std::ofstream fout("out.txt"); 

    if (!fin.is_open() || !fout.is_open()) {
        std::cout << "Ошибка открытия файлов!\n";
        return 1;
    }

    int n = 0;
    fin >> n;                 
    fout << n << '\n';   
    Address** addresses = new Address*[n];

    
    for (int i = 0; i < n; ++i) {
        std::string city, street;
        int house = 0, flat = 0;
        fin >> city >> street >> house >> flat;      
        addresses[i] = new Address(city, street, house, flat);
    }

    
    sort(addresses, n);

    
    
    for (int i = 0; i < n; ++i) {
        fout << addresses[i]->get_output_address() << '\n';
        delete addresses[i]; 
    }

    delete[] addresses; 
    fin.close();
    fout.close();
    return 0;
}