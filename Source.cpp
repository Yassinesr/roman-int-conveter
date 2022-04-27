#include<bits/stdc++.h>
using namespace std;

int rmn_to_int(string rmn_char) {
	map<char, int> rmn_cnvrtr;
	rmn_cnvrtr['I'] = 1;
	rmn_cnvrtr['V'] = 5;
	rmn_cnvrtr['X'] = 10;
	rmn_cnvrtr['L'] = 50;
	rmn_cnvrtr['C'] = 100;
	rmn_cnvrtr['D'] = 500;
	rmn_cnvrtr['M'] = 1000;
	int number = 0, i = 0;

	//If input is only one character
	if (rmn_char.length() <= 1) {
		return rmn_cnvrtr[rmn_char.at(0)];
	}
	else {
		while (i < rmn_char.size()) {
			if (rmn_cnvrtr[rmn_char[i]] < rmn_cnvrtr[rmn_char[i + 1]]) {
				number += rmn_cnvrtr[rmn_char[i + 1]] - rmn_cnvrtr[rmn_char[i]];
				i += 2;  // is at i so it skips i+1 bcs we already added it
			}
			else {
				number += rmn_cnvrtr[rmn_char[i]];
				i++;
			}
		}
		return number;
	}
}


string int_to_rmn(int n)
{

	string roman_numbers[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int according_values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

	string  result = "";

	for (int i = 0; i < 13; ++i)
	{
		while (n - according_values[i] >= 0)
		{
			result += roman_numbers[i];
			n -= according_values[i];
		}

	}
	return result;
}





int main() {
	int test; int number; string roman;
	cout << "Enter 1 to convert from integer to roman and 2 to convert from roman to integer: ";
	cin >> test;
	if (test == 1) {
		cout << "Enter integer form ";
		cin >> number;
			cout << "Roman form of " << number << " is: "
			<< int_to_rmn(number) << endl;
	}
	else {
		cout << "Enter Roman form(CAPS ONLY) ";
		cin >> roman;
		cout << "Integer form of "<< roman <<" Roman Numeral is: "
			<< rmn_to_int(roman) << endl;
	}
	return 0;

}