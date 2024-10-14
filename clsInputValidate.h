#pragma once

#include <iostream>
#include <string>
#include "clsString.h";
#include "clsDate.h";

class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		//this solution
		/*if (Number < From || Number > To)
			return false;
		else
			return true;*/

		//Or this solution is the same results
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	bool IsStringLengthBetween(string S1, int FromLength, int ToLength)
	{
		if (S1.length() < FromLength || S1.length() > ToLength)
		{
			return false;
		}
		return true;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date >= From && Date <= To
		if (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From) 
			&&
			clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
		{
			return true;
		}

		//Date >= To && Date <= From
		if (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To) 
			&&
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
		{
			return true;
		}

		return false;

		/*if (clsDate::IsDate1AfterDate2(From, To))
		{
			clsDate::SwapDates(From, To);
		}

		clsPeriod Period1(From, To);

		if (!Period1.IsDateInPeriod(DateToCheck))
		{
			return false;
		}
		return true;*/
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid number, enter again\n")
	{
		int Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		//while (cin.fail())
		//{
		//	//user didn't input a number
		//	cin.clear();
		//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//	//"Invalid number, Enter a valid one"
		//	cout << MessageWrong << endl;
		//	cin >> Number;
		//}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Numer is not within range, enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid number, enter again\n")
	{
		double Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Numer is not within range, enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};
