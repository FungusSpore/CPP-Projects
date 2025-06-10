// #include <iostream>
// #include "Array.hpp"
//
// #define MAX_VAL 750
// int main(int, char**)
// {
//
// 		Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     // //SCOPE
//     // {
//     //     Array<int> tmp = numbers;
//     //     Array<int> test(tmp);
//     // }
//
// 		{
//
//
// 		}
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
// 			std::cout << "pass with same value" << std::endl;
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
//
#include <iostream>
#include <stdexcept>
#include "Array.hpp" // Your template class header

void test_default_constructor() {
    std::cout << "Test: Default Constructor\n";
    Array<int> arr;
    std::cout << "Size: " << arr.size() << "\n";
    try {
        arr[0]; // Should throw
    } catch (const std::exception &e) {
        std::cout << "Caught exception as expected: " << e.what() << "\n";
    }
}

void test_param_constructor() {
    std::cout << "\nTest: Parameterized Constructor\n";
    Array<int> arr(5);
    std::cout << "Size: " << arr.size() << "\n";
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
}

void test_copy_constructor() {
    std::cout << "\nTest: Copy Constructor\n";
    Array<int> original(3);
    for (unsigned int i = 0; i < original.size(); ++i)
        original[i] = i + 1;

    Array<int> copy = original;

    // Modify original
    original[0] = 100;

    std::cout << "Original[0]: " << original[0] << "\n";
    std::cout << "Copy[0]: " << copy[0] << " (should be unaffected)\n";
}

void test_assignment_operator() {
    std::cout << "\nTest: Assignment Operator\n";
    Array<std::string> a(2);
    a[0] = "Hello";
    a[1] = "World";

    Array<std::string> b;
    b = a;

    a[0] = "Changed";

    std::cout << "a[0]: " << a[0] << "\n";
    std::cout << "b[0]: " << b[0] << " (should be unaffected)\n";
}

void test_subscript_bounds() {
    std::cout << "\nTest: Subscript Operator with Bounds Checking\n";
    Array<int> arr(2);
    arr[0] = 10;
    arr[1] = 20;

    try {
        std::cout << arr[2]; // Out of bounds
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    try {
        std::cout << arr[-1]; // Invalid index (if operator[] uses int)
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
}

int main() {
    test_default_constructor();
    test_param_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_subscript_bounds();

    std::cout << "\nAll tests completed.\n";
    return 0;
}
