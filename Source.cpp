// Name: Zach Anger
// Date: 7/17/21
// Professor: Jeevan D'Souza
#include <iostream>
//set of functions to do common math operations
#include <cmath>
//helps manipulate output 
#include <iomanip>
#include <string>

using namespace std;
// Prints word of value in num
string inEnglish(double num);

int main() {
	double value;
	string date;
	string name;

	do {
		//Input for employee name
		cout << "\nEnter the Employee name: ";
		//accepts user input in multiple lines 
		getline(cin, name);
		//User Input for date
		cout << "\nPlease Enter the date: ";
		getline(cin, date);
		//check amount and validation
		cout << "\nEnter check amount: $";
		cin >> value;
		//Check amount up to $10,000
		while (value < 0 || value > 10000) {
			cout << "\nPlease enter the valid check amount: $";
			cin >> value;
		}
		//divides number into whole and fractional
		double intpart;
		double fractional = modf(value, &intpart);
		int cents = ceil(fractional * 100);
		// Takes check amount in numbers and makes it words 
		string words = inEnglish(intpart);
		cout << fixed << showpoint << setprecision(2); // float-pt format
		//Output
		cout << "----------------------------------------------------------------------------------\n";
		//Sets alignment
		cout << setw(70) << right;
		cout << "Date: " << date << "\n\n";
		//Name display on the left
		cout << "Pay to the order of: " << name;
		//Width
		cout << setw(70 - name.length() - 26) << right;
		cout << "$" << value << endl;
		cout << endl << left << words << " and " << cents << " cents" << endl;
		

	} while (value<=0);			
}
//Makes the number into a word
string inEnglish(double number) {
	string output = "";
	//get the numbers in thousand position,hundred position , tens position and one's position
	int thousands = number / 1000;
	int hundreds = (number - (thousands * 1000)) / 100;
	int tens = (number - (thousands * 1000) - (hundreds * 100)) / 10;
	int ones = (int)number % 10;
	//checking the numbers in switch case and appends the results into the string output
	switch (thousands) {
	case (9):
		output += "Nine thousand ";
		break;
	case (8):
		output += "Eight thousand ";
		break;
	case (7):
		output += "Seven thousand";
		break;
	case (6):
		output += "Six thousand";
		break;
	case (5):
		output += "Five thousand";
		break;
	case (4):
		output += "Four thousand";
		break;
	case (3):
		output += "Three thousand";
		break;
	case (2):
		output += "Two thousand ";
		break;
	case (1):
		output += "One thousand ";
		break;
	}

	switch (hundreds) {
	case (9):
		output += "Nine Hundred ";
		break;
	case (8):
		output += "Eight Hundred ";
		break;
	case (7):
		output += "Seven Hundred ";
		break;
	case (6):
		output += "Six Hundred ";
		break;
	case (5):
		output += "Five Hundred ";
		break;
	case (4):
		output += "Four Hundred ";
		break;
	case (3):
		output += "Three Hundred ";
		break;
	case (2):
		output += "Two Hundred ";
		break;
	case (1):
		output += "One Hundred ";
		break;
	}

	switch (tens) {
	case (9):
		output += "Ninety ";
		break;
	case (8):
		output += "Eighty ";
		break;
	case (7):
		output += "Seventy ";
		break;
	case (6):
		output += "Sixty ";
		break;
	case (5):
		output += "Fifty ";
		break;
	case (4):
		output += "Fourty ";
		break;
	case (3):
		output += "Thirty ";
		break;
	case (2):
		output += "Twenty ";
		break;

	case (1): {
		if (ones == 1) {
			output += "Eleven";
			break;
		}
		else if (ones == 2) {
			output += "Twelve";
			break;
		}
		else if (ones == 3) {
			output += "Thirteen";
			break;
		}
		else if (ones == 4) {
			output += "Fourteen";
			break;
		}
		else if (ones == 5) {
			output += "Fifteen";
			break;
		}
		else if (ones == 6) {
			output += "Sixteen";
			break;
		}
		else if (ones == 7) {
			output += "Seventeen";
			break;
		}
		else if (ones == 8) {
			output += "Eighteen";

			break;
		}
		else if (ones == 9) {
			output += "Nineteen";
			break;
		}
		else
			break;
	}

	}
	if (tens > 1 || number < 10) // if number greater than 19 or number less than 10
	{
		switch (ones) {
		case (9):
			output += "Nine";
			break;
		case (8):
			output += "Eight";
			break;
		case (7):
			output += "Seven";
			break;
		case (6):
			output += "Six";
			break;
		case (5):
			output += "Five";
			break;
		case (4):
			output += "Four";
			break;
		case (3):
			output += "Three";
			break;
		case (2):
			output += "Two";
			break;
		case (1):
			output += "One";
			break;
		}
	}
	return output;
}