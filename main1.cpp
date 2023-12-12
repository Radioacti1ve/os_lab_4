#include <iostream>
#include "func.hpp"


int main(int argc, char const *argv[])
{
    std::cout << "1 arg1 arg2 - GCF function\n2 - Sort function\n3 exit" << std::endl;
    int com;
    int a, b;
    int size;
    int *array = nullptr; 
    std::cout << "Input the command: ";
    std::cin >> com;
    while(com != 3) {
        switch (com)
        {
        case 1:
            std::cout << "Input a and b: ";
            std::cin >> a >> b;
            std::cout << "GCF(" << a << ',' << b << ") = " << gcf(a, b) << std::endl; 

            std::cout << "Input the command: ";
            std::cin >> com;
            break;
        case 2:
            std::cout << "Input the size of your array: ";
            std::cin >> size;
            array = new int[size]; 
            std::cout << "Input your array: ";
            for(int i = 0; i < size; ++i) {
                std::cin >> array[i];
            }
            sort(array, size);
            for(int i = 0; i < size; ++i) {
                std::cout << array[i] << std::endl;
            }
            delete[] array;
            std::cout << "Input the command: ";
            std::cin >> com;
            break;
        case 3:
            break; 

        default:
            std::cout << "Incorreact input\n";
            exit(1);
            break;
        }
    }
    return 0;
}
