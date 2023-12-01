#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int addLine(string input, int& n) {
	int first = 0, last = 0;
	string last5 = "";
	string last4 = "";
	string last3 = "";
	for (char b : input)
	{
		if (isdigit(b)) {
			last = int(b - '0');
		}

		last5.push_back(b);
		if (last5.length() > 5)
			//last5.erase(last5.begin()); this works! so does erase(0,1) but erase(0) clears out the whole string
			last5 = last5.substr(1);
			

		last4.push_back(b);
		if (last4.length() > 4)
			last4 = last4.substr(1);

		last3.push_back(b);
		if (last3.length() > 3)
			last3 = last3.substr(1);

		if (last5 == "three") last = 3;
		if (last5 == "seven") last = 7;
		if (last5 == "eight") last = 8;

		if (last4 == "four") last = 4;
		if (last4 == "five") last = 5;
		if (last4 == "nine") last = 9;

		if (last3 == "one") last = 1;
		if (last3 == "two") last = 2;
		if (last3 == "six") last = 6;

		if (first == 0 && last != 0) first = last;
	}

	n++;
	return (first * 10 + last);
}

int main()
{
	int sum = 0;
	int count = 0;
	int currentline = 0;
	ifstream file("input.txt");
	for (string line; getline(file, line);)
	{
		currentline = addLine(line, count);
		cout << currentline << endl;
		sum += currentline;
	}

	cout << "total is " << sum;

	return 0;
}