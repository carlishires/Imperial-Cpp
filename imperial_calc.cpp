// Carli Shires
// Started April 7, 2019
/* This program can add, subtract, multiply and divide
	different imperial units of measurement (inches, feet, yards and miles)*/

	//System includes:
#include <vector>
#include <iostream>
#include <algorithm>

// Using Declarations
using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::string;
using std::transform;

struct length {
	double num;
	string unit;
	char oper;
	length(double num, string unit, char oper) // length constructor
		: num(num), unit(unit), oper(oper) {}
};

// Function Prototypes
void
convertToIn(vector<length>& v);

void
convertToFt(vector<length>& v);

void
convertToYrd(vector<length>& v);

void
convertToMi(vector<length>& v);

double
calculate(vector<length>& v);

/************/



int
main(int argc, char* argv[]) {
	vector<length> v;
	string endUnit;
	cout << "This program can add, subtract, multiply and divide imperial units of length" << endl;
	cout << "Unit of Length: "; // what the final calculation is displayed in
	cin >> endUnit;
	transform(endUnit.begin(), endUnit.end(), endUnit.begin(), ::tolower);
	if (endUnit != "inches" && endUnit != "feet" && endUnit != "yards" && endUnit != "miles") {
		cout << "Error: Invalid unit type" << endl;
		return -1;
	}
	char oper;
	double num;
	string unit;
	while (oper != '=') {
		cout << "Measurement number: ";
		cin >> num;
		if (!cin) {
			cout << "Error: Not a valid input" << endl;
		}

		cout << "Measurement type: ";
		cin >> unit;
		transform(unit.begin(), unit.end(), unit.begin(), ::tolower);
		if (unit != "inch" && unit != "foot" && unit != "yard" && unit != "mile" && unit != "inches" && unit != "feet" && unit != "yards" && unit != "miles") {
			cout << "Error: Not a valid input" << endl;
			break;
		}
		if (unit == "inch")
			unit = "inches";
		else if (unit == "foot")
			unit = "feet";
		else if (unit == "yard")
			unit = "yards";
		else if (unit == "mile")
			unit = "miles";

		cout << "oper: ";
		cin >> oper;
		if (oper != '+' && oper != '-' && oper != '*' && oper != '/' && oper != '=') {
			cout << "Error: Invalid Operator" << endl;
			break;
		}
		v.push_back(length(num, unit, oper));
	}
	/* converts all cells in v to the unit of measurement
	that the user inputed as the final unit */

	if (endUnit == "inches")
		convertToIn(v);
	else if (endUnit == "feet")
		convertToFt(v);
	else if (endUnit == "yards")
		convertToYrd(v);
	else  // endUnit == miles
		convertToMi(v);

	double answer = calculate(v);
	cout << answer << " ";
	cout << endUnit << endl;
}

void
convertToIn(vector<length> & v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].unit == "feet") {
			// ft to in
			v[i].num = v[i].num * 12;
			v[i].unit = "inches";
		}
		else if (v[i].unit == "yards") {
			// yrd to in
			v[i].num = v[i].num * 36;
			v[i].unit = "inches";
		}
		else if (v[i].unit == "miles") {
			// mi to in
			v[i].num = v[i].num * 63360;
			v[i].unit = "inches";
		}
	}
}

void
convertToFt(vector<length> & v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].unit == "inches") {
			// in to ft
			v[i].num = v[i].num / 12;
			v[i].unit = "feet";
		}
		else if (v[i].unit == "yards") {
			// yrd to ft
			v[i].num = v[i].num * 3;
			v[i].unit = "feet";
		}
		else if (v[i].unit == "miles") {
			// mi to ft
			v[i].num = v[i].num * 5280;
			v[i].unit = "feet";
		}
	}
}

void
convertToYrd(vector<length> & v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].unit == "inches") {
			// in to yrd
			v[i].num = v[i].num / 36;
			v[i].unit = "yards";
		}
		else if (v[i].unit == "feet") {
			// ft to yrd
			v[i].num = v[i].num / 3;
			v[i].unit = "yards";
		}
		else if (v[i].unit == "miles") {
			// mi to yard
			v[i].num = v[i].num * 1760;
			v[i].unit = "yards";
		}
	}
}

void
convertToMi(vector<length> & v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].unit == "inches") {
			// in to mi
			v[i].num = v[i].num / 63360;
			v[i].unit = "miles";
		}
		else if (v[i].unit == "feet") {
			// ft to mi
			v[i].num = v[i].num / 5280;
			v[i].unit = "miles";
		}
		else if (v[i].unit == "yards") {
			// yrd to mi
			v[i].num = v[i].num / 1760;
			v[i].unit = "miles";
		}
	}
}

double
calculate(vector<length> & v) {
	double answer = v[0].num;
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].oper == '+')
			answer = answer + v[i + 1].num;

		else if (v[i].oper == '-')
			answer = answer - v[i + 1].num;

		else if (v[i].oper == '*')
			answer = answer * v[i + 1].num;

		else if (v[i].oper == '/') {
			if (v[i + 1].num == 0) {
				cout << "Error: Can not divide by 0" << endl;
				exit(0);
			}
			answer = answer / v[i + 1].num;
		}

		else // if oper = '='
			break;

		//cout << i << " " << answer << endl;
	}
	return answer;
}


