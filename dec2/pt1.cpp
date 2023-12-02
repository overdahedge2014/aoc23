#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool gamePoss(int rMax, int gMax, int bMax, string line)
{
	int i = 0;
	string format[25];
	size_t start = line.find_first_of(":");
	line.erase(0, start + 2);
	while (!line.empty())
	{
		size_t sep = line.find_first_of(",;", 0);
		
		// if only one 'x colour' remains (no separator) (find_first_of returns npos (-1)):
		if (sep == -1) {
			format[i] = line;
			line.clear();
		}

		// if there are multiple left (at least 1 separator left) take the first:
		else {
			format[i] = line.substr(0, sep);
			line.erase(0, sep + 2);
		}
		i++;
	}

	// so now format should be an array with (i-1) strings of format "nn xxxxx", can work with this
	for (int j = 0; j < i; j++)
	{
		// fetch string
		string test = format[j];

		int space = test.find(" ");

		string num = test.substr(0, space);
		int cubes = stoi(num);
		
		string colour = test.substr(space + 1);
		if (colour == "green")
			if (cubes > gMax) return false;
		if (colour == "blue")
			if (cubes > bMax) return false;
		if (colour == "red")
			if (cubes > rMax) return false;
	}

	// if we got here then everything worked so the game is possible so return true!
	return true;
}

int main1()
{
	ifstream file("input.txt");
	int idTotal = 0;
	int id = 1;
	for (string line; getline(file, line);)
	{
		cout << "game " << id << ": ";

		if (gamePoss(12, 13, 14, line)) {
			cout << "possible" << endl;
			idTotal += id;
		}
		else {
			cout << "impossible" << endl;
		}
		id++;
	}
	cout << "total: " << idTotal;

	return 0;
}