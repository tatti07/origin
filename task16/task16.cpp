#include <iostream>
#include <string>
#include <stdexcept>



int function(const std::string& s, int forbidden_length) {
    int len = static_cast<int>(s.size());
    if (len == forbidden_length) {
        throw std::invalid_argument("forbidden length");
    }
    return len;
}

int main() {
    
    std::cout << "Enter forbidden length: ";
    int forbidden = 0;
    if (!(std::cin >> forbidden)) return 0;

    while (true) {
        std::cout << "Enter a word: ";
        std::string word;
        if (!(std::cin >> word)) break;            

        try {
            int len = function(word, forbidden);   
            std::cout << "Length of \"" << word << "\" is " << len << "\n";
        }
        catch (const std::invalid_argument& e) {
    std::cout << "Error: " << e.what() << "\n";
    std::cout << "You entered a word of forbidden length. Bye!\n";
    break;
}
        catch (const std::exception& e) {          
            std::cout << "Unexpected error: " << e.what() << "\n";
            break;
        }
    }
    return 0;
}