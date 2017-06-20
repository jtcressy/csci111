#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string str1, str2, str3;
	int len1, len2, len3;
	char ch1, ch2, ch3;
	int comma1, comma2, comma3;
	string sub1, sub2, sub3;
	ifstream inf;
	ofstream outf;
	inf.open("in.dat");
	outf.open("out.ot");

	// step 1
	outf << endl << endl << "::Step 1:: Read all lines and output" << endl << endl;
	getline(inf, str1);
	getline(inf, str2);
	getline(inf, str3);
	outf << "Strings 1-3:" << endl
		<< str1 << endl
		<< str2 << endl
		<< str3 << endl;

	// step 2
	outf << endl << endl << "::Step 2:: Get lengths of strings" << endl << endl;
	len1 = str1.length();
	len2 = str2.length();
	len3 = str3.length();
	outf << "Length of string 1: " << len1 << endl
		<< "Length of string 2: " << len2 << endl
		<< "Length of string 3: " << len3 << endl;

	// step 3
	outf << endl << endl << "::Step 3:: Find index of first comma" << endl << endl;
	comma1 = str1.find(',', 0);
	comma2 = str2.find(',', 0);
	comma3 = str3.find(',', 0);
	outf << "Index Location of comma in string 1: " << comma1 << endl
		<< "Index Location of comma in string 2: " << comma2 << endl
		<< "Index Location of comma in string 3: " << comma3 << endl;

	// step 4
	outf << endl << endl << "::Step 4:: Read char two space before comma position" << endl << endl;
	ch1 = str1[comma1 - 2];
	ch2 = str2[comma2 - 2];
	ch3 = str3[comma3 - 2];
	outf << "Char two spaces before first comma in string 1: " << ch1 << endl
		<< "Char two spaces before first comma in string 2: " << ch2 << endl
		<< "Char two spaces before first comma in string 3: " << ch3 << endl;

	// step 5
	outf << endl << endl << "::Step 5:: Read substring two spaces after first comma to the end of line" << endl << endl;
	sub1 = str1.substr(comma1 + 2, 100);
	sub2 = str2.substr(comma2 + 2, 100);
	sub3 = str3.substr(comma3 + 2, 100);
	outf << "Substring two spaces after first comma to end of string 1: " << sub1 << endl
		<< "Substring two spaces after first comma to end of string 2: " << sub2 << endl
		<< "Substring two spaces after first comma to end of string 3: " << sub3 << endl;

	// step 6
	outf << endl << endl << "::Step 6:: erase the first comma in each string" << endl << endl;
	str1.erase(comma1, 1);
	str2.erase(comma2, 1);
	str3.erase(comma3, 1);
	outf << "Strings with first comma deleted:" << endl
		<< str1 << endl
		<< str2 << endl
		<< str3 << endl;

	// step 7
	outf << endl << endl << "::Step 7:: insert \"TGIT\" into each string at same position of the first comma" << endl << endl;
	str1.insert(comma1, "TGIT");
	str2.insert(comma2, "TGIT");
	str3.insert(comma3, "TGIT");
	outf << "Inserted \"TGIT\" into each string at first comma location: " << endl
		<< str1 << endl
		<< str2 << endl
		<< str3 << endl;
	return 0;
}