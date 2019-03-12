#include "DataToExcel.h"


DataToExcel::DataToExcel(std::string fileName)
{
	_filePath = fileName + ".csv";

	//Creates new excel file if one doesn't exist - clears file if it does
	_excelFile.open(_filePath);

	if (_excelFile.fail())
		return;

	_excelFile.clear();
	_excelFile << "Seed, Return Value\n";
	_excelFile.close();
}


DataToExcel::~DataToExcel()
{
}

void DataToExcel::writeDataToRow(std::vector<int> data)
{
	_excelFile.open(_filePath, std::ofstream::app);

	if (_excelFile.fail())
		return;

	for (int i = 0; i < data.size(); ++i)
		_excelFile << data[i] << ",";

	_excelFile << "\n";

	_excelFile.close();
}
