#include <iostream>
#include "iter.hpp"

void printInt(int &n) {
    std::cout << n << " ";
}

void doubleInt(int &n) {
    n *= 2;
}

void printStr(std::string &s) {
    std::cout << s << " ";
}

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

void printChar(char &c) {
    std::cout << c << " ";
}

void printSquare(int &n) {
    std::cout << n * n << " ";
}

int main() {
    // Print array
    std::cout << "=== Teste 1: Print ints ===" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    iter(arr, len, printInt);
    std::cout << std::endl;

    // Appy funtion doubleInt
    std::cout << "=== Teste 2: Dobrar ints ===" << std::endl;
    iter(arr, len, doubleInt);
    iter(arr, len, printInt);
    std::cout << std::endl;

    //Array de strings
    std::cout << "=== Teste 3: Print strings ===" << std::endl;
    std::string words[] = {"hello", "world", "42"};
    iter(words, 3, printStr);
    std::cout << std::endl;

    //ToUpper with array of chars
    std::cout << "=== Teste 4: toUpper chars ===" << std::endl;
    char letters[] = {'a', 'b', 'c', 'd'};
    iter(letters, 4, toUpper);
    iter(letters, 4, printChar);
    std::cout << std::endl;

    // Square of number
    std::cout << "=== Teste 5: Quadrado ===" << std::endl;
    int nums[] = {3, 4, 5};
    iter(nums, 3, printSquare);
    std::cout << std::endl;

    return 0;
}