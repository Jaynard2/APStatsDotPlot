#pragma once
#include <string>
#include <vector>
#include <fstream>

class DataToExcel
{
public:
	DataToExcel(std::string fileName);
	~DataToExcel();

	void writeDataToRow(std::vector<int> data);

private:
	std::string _filePath;
	std::ofstream _excelFile;
};

