#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>

// Chapter 4 drill for Programming: Principles and Practice Using C++

using namespace std;

// convert all data type in cm.
double convert(double input, string unit)
{
	double convert_input = 0;
	double meters = 100; double inch = 2.54; double ft = 12 * inch;
	if (unit == "cm")
		convert_input = input;
	if (unit == "m")
		convert_input = input * meters;
	if (unit == "in")
		convert_input = input * inch;
	if (unit == "ft")
		convert_input = input * ft;
	return convert_input;

}
// Prompt user for data. Store them and print usefull thing like largest/smallest/sum and convert them. 
int main()
{		
	cout << "Enter your valor and unit (cm,m,in,ft). Format valor unit.Write 0 end to close the program.\n";
	// Variable declaration
	string unit;
	string good_unit[4] = {"cm","m","in","ft"};
	vector <double> data;
	double sum = 0;
	double min = numeric_limits<double>::max(); 
	double max = numeric_limits<double>::min();

	for (double input; cin >> input >> unit;)
	{
		bool check = false;
		// End of the loop and the program. Generate final results
		if (input == 0 && unit == "end") {
			sort(data.begin(), data.end());
			for (int i = 0; i < data.size(); i++) {
				cout << data[i] / 100 <<" m\n";
			}
			cout << "The largest: " << max / 100 << " m\nThe smallest: " << min /100 << " m\nThe number of values: " << data.size() << "\nThe sum of the values: " << sum / 100 << " m\n";
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			if (unit == good_unit[i])
				check = true;
		}
		if (check == false)
			cout << "Wrong unit type : cm,m,in,ft";
		if (check == true)
			input = convert(input, unit);
		if (input < min) {
			cout << "That's the smallest value so far\n";
			data.push_back(input);
			sum += input;
			min = input;
		}
		else if (input > max) {
			cout << "That's the larger value so far\n";
			data.push_back(input);
			sum += input;
			max = input;
		}
		else {
			data.push_back(input);
			sum += input;
		}
	}
}