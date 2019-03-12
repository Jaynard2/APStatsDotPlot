#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
#include "DataToExcel.h"

int randomNum(int maxNum, int seed);

int main(int arg, char** argc)
{
	int maxNum;				//Highest value of the random number
	int testAmount;			//How many times to test each seed
	int totalTests;			//How many different seeds to test
	int seed;				//Starting seed
	std::string fileName;	//name of the file to save to

	std::cout << "File name: ";
	std::cin >> fileName;

	std::cout << "Max number: ";
	std::cin >> maxNum;

	std::cout << "Test amount: ";
	std::cin >> testAmount;

	std::cout << "Total tests: ";
	std::cin >> totalTests;

	std::cout << "Seed: ";
	std::cin >> seed;

	DataToExcel dataToExcel(fileName);

	for (int i = 0; i < totalTests; ++i)
	{
		std::cout << "Testing with seed " << seed << "... ";

		for (int x = 0; x < testAmount; ++x)
		{
			std::vector<int> data = { seed, randomNum(maxNum, seed) };
			dataToExcel.writeDataToRow(data);
		}
		std::cout << "Done\n";
		++seed;
	}
}

int randomNum(int maxNum, int seed)
{
	++maxNum;

	srand(seed * (GetTickCount() * 7));  //GetTickCount gets system time in Milliseconds. Was removed for the test without time
	Sleep(7.5);
	return rand() % maxNum;

}
