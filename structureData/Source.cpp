#include <iostream>
#include <time.h>
#include "myFunc.h"
#include <sstream>
#pragma warning(disable : 4996)
struct date1
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

int main() 
{
	std::string str;
	setlocale(LC_ALL, "");
	date1 strt;
	int choice, n = 0;
	std::cout << "1. Задача на диагонали массива\n2. Задача на время\n";
	std::cin >> choice;
	struct tm* u;
	const time_t now = time(NULL);
	tm* localTime = localtime(&now);
	char* dt = ctime(&now);
	switch (choice)
	{
	case 1:
	{
		std::cout << "Задача на массив\n";
		std::cout << "Введите размерность:\n";
		std::cin >> n;
		int** a = new int* [n];
		a[0] = new int[n * n];
		for (int i = 1; i < n; i++)
			a[i] = a[i - 1] + n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = 10 * (i + 1) + j + 1;
		printArr(a, n);
		short int choiceIn1Case;
		std::cout << "Единица это поменять значения диагональ,\nа Двоечка - ничего не делать и закрыть программу:\n";
		std::cin >> choiceIn1Case;
		switch (choiceIn1Case)
		{
		case 1:
		{
			swapDiagonal(a, n);
			printArr(a, n);
		}
		case 2: {return 0;}
		default:
			break;
		}
	}
	case 2:
	{
		short int choiceIn2Case;
		do
		{
			std::cout << "\n1. Время кампуктера\n2. Время с клавиатуры\n0. Выход\n";
			std::cin >> choiceIn2Case;
			std::cout.clear();
			switch (choiceIn2Case)
			{
			case 1:
			{
				short int choiceInData;
				std::cout << "1. Всё вместе\n2. Текущая секунда\n3. Текущая секунда\n4. Текущий час\n5. Текущий день\n6. Текущий месяц"
					<< "\n7. Текущий год\n0. Вернуться к предыдущему выбору\n";
				std::cin >> choiceInData;
				switch (choiceInData)
				{
				case 1: {
					std::string nmonth;
					std::string nsec;
					if(localTime->tm_mon < 10) 
					{
						std::stringstream ss;
						ss << localTime->tm_mon;
						std::string smonth = ss.str();
						std::string snull = "0";
						nmonth = "0" + smonth;
					}
					if (localTime->tm_sec < 10)
					{
						std::stringstream ss;
						ss << localTime->tm_mon;
						std::string ssec = ss.str();
						std::string snull = "0";
						nsec = "0" + ssec;
					}
					else 
					{
						std::stringstream ss;
						ss << localTime->tm_sec;
						nsec = ss.str();
					}
					std::cout << localTime->tm_mday << "." << nmonth << "." << localTime->tm_year + 1900
						<< "\t\t\t";
					std::cout << localTime->tm_hour << ":" << localTime->tm_min << ":" << nsec << std::endl;
					break;
					//std::cout << localTime->tm_hour
				}
				case 2: {
					std::cout << "Секунда:\t" << localTime->tm_sec << std::endl;
				}
				case 3: {
					std::cout << "Минута:\t" << localTime->tm_sec << std::endl;
				}
				case 4: {
					std::cout << "Час:\t" << localTime->tm_sec << std::endl;

				}
				case 5: {
					std::cout << "День:\t" << localTime->tm_sec << std::endl;

				}
				case 6: {
					std::cout << "Месяц:\t" << localTime->tm_sec << std::endl;

				}
				case 7: {
					std::cout << "Год:\t" << localTime->tm_year + 1900 << std::endl;

				}
				default:
					break;
				}
				std::cin.clear();
			}
			case 2:
			{

			}
			default:
				break;
			}
		} while (choiceIn2Case != 0);
	}
	default:
		break;
	}
	return 0;
}