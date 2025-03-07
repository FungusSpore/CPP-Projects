// #include <iostream>
//
// using namespace std;
//
// namespace first {
// 	int val = 500; void func() {
// 		cout << "first" << endl;
// 	}
// 	namespace second {
// 		int val = 399;
// 		void func()
// 		{
// 			cout << "second" << endl;
// 		}
// 	}
// }
//
// using namespace first :: second;
// int main()
// {
// 	// cout << "Hello World!" << 1;
// 	// char s[] = "Welcome at GFG";
// 	// char c = '1';
// 	//
// 	// cout.write(s, 6);
// 	// cout.put(c);
// 	// func();	
// 	// first :: second :: func();
// 	// first  :: func();
// 	cout << val << endl;
// }
// C++ Program to demonstrate the working of
// getline(), push_back() and pop_back()
// #include <iostream>
// #include <string> // for string class
// using namespace std;
//
// // Driver Code
// int main()
// {
//     // Declaring string
//     string str;
//
//     // Taking string input using getline()
//     getline(cin, str);
//
//     // Displaying string
//     cout << "The initial string is : ";
//     cout << str << endl;
//
//     // Inserting a character
//     str.push_back('s');
//
//     // Displaying string
//     cout << "The string after push_back operation is : ";
//     cout << str << endl;
//
//     // Deleting a character
//     str.pop_back();
//     // Displaying string
//     cout << "The string after pop_back operation is : ";
//     cout << str << endl;
//
//     return 0;
// }
//
// #include <iostream>
// class Example {
// public:
//     int number;            // in-class initializer
//     std::string text;          // std::string's default constructor makes it an empty string
//
//     // Default constructor (could be omitted if no other constructors are defined)
//     Example() {
//         // Additional initialization if needed
//     }
// 		Example(int number)
// 		{
//
// 		}
// };
// int main(void)
// {
// 	Example test;
// 	if (*(test.text.c_str()) == '\0')
// 		std::cout << "true";
// 	std::string str = "Hello";
// 	std::cout << str;
// 	std::cout << str.length();
// }

#include <iostream>
#include <ctime>

using namespace std;

int main (void)
{
	time_t now = time(0);

	tm *ltm = localtime(&now);
	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", ltm);
	cout << buffer << endl;

}
