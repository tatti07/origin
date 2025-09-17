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
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    }
};

int main() {
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (!fin.is_open() || !fout.is_open()) {
        std::cout << "Ошибка открытия файлов!" << std::endl;
        return 1;
    }

    int n;
    fin >> n;
    fout << n << std::endl;

    Address** addresses = new Address*[n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int house, flat;

        fin >> city >> street >> house >> flat;
        addresses[i] = new Address(city, street, house, flat);
    }

    for (int i = n - 1; i >= 0; i--) {
        fout << addresses[i]->get_output_address() << std::endl;
        delete addresses[i];
    }

    delete[] addresses;
    fin.close();
    fout.close();

    return 0;
}