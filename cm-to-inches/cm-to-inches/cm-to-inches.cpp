// cm to inches conversion
// Joel Cressy
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	cout << "Convert centimeters to imperial units." << endl;
	double inchesDouble;
	int centimeters, yards, feet, inches;
	ifstream inf;
	ofstream outf;
	inf.open("centimeters.dat"); 
	outf.open("imperial.ot");
	cout << endl << "Calculating..." << endl << endl;
	cout << setw(16) << "| Centimeters | " << setw(8) << "Yards | " 
		<< setw(9) << " Feet  | " << setw(9) << "Inches | " << endl;
	outf << setw(16) << "| Centimeters | " << setw(8) << "Yards | " 
		<< setw(9) << " Feet  | " << setw(9) << "Inches | " << endl;
	cout << "+=============+=======+========+========+" << endl;
	outf << "+=============+=======+========+========+" << endl;
	for (int i = 0; i < 10; i++) {
		inf >> centimeters;
		inchesDouble = centimeters / 2.54;
		inches = inchesDouble + 0.5;
		yards = inches / 36; 
		inches = inches % 36; 
		feet = inches / 12;
		inches = inches % 12;
		cout << "| " << setw(11) << centimeters << " : "
			<< setw(5) << yards << " | " << setw(6) << feet << " | "
			<< setw(6) << inches << " | " << endl;
		outf << "| " << setw(11) << centimeters << " : "
			<< setw(5) << yards << " | " << setw(6) << feet << " | "
			<< setw(6) << inches << " | " << endl;
	}
	cout << endl << "Complete. Data saved to file" << endl;
	system("pause"); //I remove system("pause"); from the code when compiling for unix systems
	//and i use int main() for compatibility with unix systems. 
	//not yet sure why void main() doesnt work for g++ compilers
	return 0;
}