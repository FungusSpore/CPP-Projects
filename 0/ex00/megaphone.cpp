#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < (int)strlen(argv[i]); j++)
		{
			char letter = argv[i][j];
			if (islower(letter))
				letter = letter - 32;
			std::cout << letter;
		}
	}
	std::cout << std::endl;
	return (0);
}
