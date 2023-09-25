/*
    1) strlen - std::string::length()
2) strcpy - std::strcpy() или std::string::assign()
3) strcmp - std::strcmp() или std::string::compare()
4) strcat - std::strcat() или std::string::append()
5) someString[index] - std::string::operator[] (получение символа по индексу)
6) push_back - std::string::push_back()
7) pop_back - std::string::pop_back()
*/

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // Удаление пробелов и пунктуационных знаков
    std::string cleanInput;
    for (char c : input) {
        if (std::isalpha(c)) {
            cleanInput.push_back(std::tolower(c));
        }
    }

    // Сортировка букв в алфавитном порядке
    std::sort(cleanInput.begin(), cleanInput.end());

    std::cout << "Строка после сортировки: " << cleanInput << std::endl;

    return 0;
}
