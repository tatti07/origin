#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

struct bad_length {};

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    int forbidden = 0;
    std::wcout << L"Введите запрещённую длину: ";
    std::wcin >> forbidden;

    while (true) {
        std::wcout << L"Введите слово: ";
        std::wstring word;
        if (!(std::wcin >> word)) break;

        try {
            int len = static_cast<int>(word.size());
            if (len == forbidden) throw bad_length{};
            std::wcout << L"Длина слова \"" << word << L"\" равна " << len << L"\n";
        }
        catch (const bad_length&) {
            std::wcout << L"Вы ввели слово запрещённой длины! До свидания\n";
            break;
        }
    }
    return 0;
}