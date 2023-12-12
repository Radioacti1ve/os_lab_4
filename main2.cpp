#include <iostream>
#include <dlfcn.h>
#include "func.hpp"
#include <string>

int main(int argc, char const *argv[])
{
    std::cout << "0 - change realisation\n1 arg1 arg2 - GCF function\n2 your array - Sort function\n3 exit\n" << std::endl;
    int com;
    int a, b;
    int size;
    int *array = nullptr; 

    int lib = 1;
    void *library;

    char name1[] = "gcf";
    char name2[] = "sort"; 

    std::cout << "Input your command: ";
    std::cin >> com;

    library = dlopen("libreal1.so", RTLD_NOW);

    if(!library) {
        std::cerr << "dlopen error: " << dlerror() << std::endl;
        exit(1);
    }

    

    while(com != 3) {
        switch (com) {
        case 0:
            dlclose(library);
            if(lib == 1) {
                library = dlopen("libreal1.so", RTLD_NOW);
                lib = 2;
            } else {
                library = dlopen("libreal2.so", RTLD_NOW);
                lib = 1;
            }
            std::cout << "Realisation was changed.\n";
            std::cout << "Input your command: ";
            std::cin >> com;
            break;
        case 1:
            std::cout << "input a and b: ";
            std::cin >> a >> b;
            int (*func_gcf)(int, int); 
            func_gcf = reinterpret_cast<int (*)(int, int)>(dlsym(library, name1));

            if(!func_gcf) {
                std::cerr << "GCF error:" << dlerror() << "\n";
                exit(1);
            }
            if(lib == 1) {
                std::cout << "GCF realisation 1\n";
            } else {
                std::cout << "GCF realisation 2\n";
            }
            std::cout << (*func_gcf)(a, b) << std::endl;
            std::cout << "Input your command: ";
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

            void (*func_sort)(int*, int); 
            
            func_sort = reinterpret_cast<void (*)(int*, int)>(dlsym(library, name2));

            if (!func_sort) {
                std::cerr << "sort function error: " << dlerror() << "\n";
                exit(1);
            }
            if(lib == 1) {
                std::cout << "GCF realisation 1\n";
            } else {
                std::cout << "GCF realisation 2\n";
            }
            
            (*func_sort)(array, size);
            std::cout << "Sorted array: ";
            for (int i = 0; i < size; ++i) {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;

            delete[] array; 

            std::cout << "Input your command: ";
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
    dlclose(library);
}
