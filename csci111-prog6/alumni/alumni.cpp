//Joel Cressy
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int maxArraySize = 100;
const char infDelim = '|';
const int maxOutputWidth = 85;
const int numWidth = 10;
const int nameWidth = 30;
const int addressWidth = 25;

struct alumniType {
	string whole;
	string first;
	char mi;
	string last;
	string street;
	string csz;
	string city;
	string state;
	string zip;
	int pledge;
};

const alumniType initrec = { 
	"none", 
	"none", 
	'x', 
	"none", 
	"none", 
	"none", 
	"none", 
	"none", 
	"none", 
	0 
};

void initem(alumniType a[], int &n) {
	for (int i = 0; i < maxArraySize; i++) {
		a[i] = initrec;
	}
	n = 0;
}

void readem(alumniType a[], int &n) {
	ifstream inf;
	inf.open("alumni.dat");
	int i = 0;
	while (!inf.eof()) {
		getline(inf, a[i].whole, infDelim);
		getline(inf, a[i].street, infDelim);
		getline(inf, a[i].csz, infDelim);
		inf >> a[i].pledge >> ws;
		i++;
	}
	n = i;
}

string numtostring(int input) {
	int digits = 0;
	string output = "";
	while (input > 0 && digits < 100)
	{
		int zero = '0';
		char ch = input % 10 + zero;
		string str;
		str.append(1, ch);
		output.insert(0, str);
		input /= 10;
		str.clear();
	}
	return output;
}

void println(ofstream &outf, int n, string ch) {
	for (int i = 0; i < n; i++) {
		outf << ch;
	}
	outf << endl;
}

void printcenter(string str, ofstream &outf) {
	outf << right << setw(maxOutputWidth / 2 + str.length() / 2) << str << endl;
}

void printtitles(ofstream &outf) {
	string title = "Marvel College";
	string subtitle = "Alumni Records";
	printcenter(title, outf);
	printcenter(subtitle, outf);
	outf << endl;
}

void splitstrings(alumniType a[], int n) {
	int placehold = 0;
	string tempstring = "";
	for (int i = 0; i < n; i++) {
		int period = a[i].whole.find('.');
		a[i].first = a[i].whole.substr(0, period - 2);
		a[i].mi = a[i].whole[period - 1];
		a[i].last = a[i].whole.substr(period + 2);
		a[i].city = a[i].csz.substr(0, a[i].csz.find(',', 0));
		placehold = a[i].csz.find(',', 0);
		a[i].state = a[i].csz.substr(placehold + 2, 2);
		a[i].zip = a[i].csz.substr(placehold + 5);
	}
}

void swapem(alumniType &a, alumniType &b) {
	alumniType temp;
	temp = a;
	a = b;
	b = temp;
}

void sortbylastname(alumniType a[], int n) {
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n - 1; i++)
			if (a[i].last > a[i + 1].last)
				swapem(a[i], a[i + 1]);
}

void sortbypledge(alumniType a[], int n) {
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n - 1; i++)
			if (a[i].pledge < a[i + 1].pledge)
				swapem(a[i], a[i + 1]);
}

void sortbyzip(alumniType a[], int n) {
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n - 1; i++)
			if (a[i].zip < a[i + 1].zip)
				swapem(a[i], a[i + 1]);
}

void printtable1(alumniType a[], int n, ofstream &outf) { 
	outf << left << setw(nameWidth) << " Name"
		<< right << setw(numWidth) << "Pledge"
		<< setw(maxOutputWidth - (nameWidth+numWidth)) << "Address" << endl;
	println(outf, maxOutputWidth, "\u2500");
	for (int i = 0; i < n; i++) {
		string address = a[i].street + ", " + a[i].csz;
		outf << left << setw(nameWidth) << a[i].whole 
			<< right << setw(numWidth) << a[i].pledge 
			<< setw(maxOutputWidth - (nameWidth + numWidth)) << address << endl;
	}
	println(outf, maxOutputWidth, "\u2500");
	println(outf, maxOutputWidth, "#");
}

void printtable2(alumniType a[], int n, ofstream &outf) {
	sortbylastname(a,n);
	int totalpledge = 0;
	outf << left << setw(nameWidth) << "Name" 
		<< right << setw(numWidth) << "Pledge" << endl;
	println(outf, maxOutputWidth, "\u2500");
	for (int i = 0; i < n; i++) {
		a[i].whole = a[i].last + ", " + a[i].first + " " + a[i].mi + ".";
		totalpledge += a[i].pledge;
		outf << left << setw(nameWidth) << a[i].whole 
			<< right << setw(numWidth) << a[i].pledge << endl;
	}
	println(outf, maxOutputWidth, "\u2500");
	outf << left << setw(nameWidth) << "Total Pledges:" 
		<< right << setw(numWidth) << totalpledge << endl;
	println(outf, maxOutputWidth, "#");
}

void printtable3(alumniType a[], int n, ofstream &outf) {
	sortbyzip(a,n);
	outf << left << setw(nameWidth) << "Name" 
		<< right << setw(numWidth) << "Zipcode" << endl;
	println(outf, maxOutputWidth, "\u2500");
	for (int i = 0; i < n; i++) {
		a[i].whole = a[i].last + ", " + a[i].first + " " + a[i].mi + ".";
		outf << left << setw(nameWidth) << a[i].whole 
			<< right << setw(numWidth) << a[i].zip << endl;
	}
	println(outf, maxOutputWidth, "\u2500");
	println(outf, maxOutputWidth, "#");
}

void printpledgeasString(alumniType a[], int n, ofstream &outf) {
	sortbylastname(a, n);
	outf << left << setw(nameWidth) << "Name" 
		<< right << setw(numWidth) << "Pledge" << endl;
	println(outf, maxOutputWidth, "\u2500");
	string pledge;
	int length;
	for (int i = 0; i < n; i++) {
		pledge = "$" + numtostring(a[i].pledge);
		if (pledge.length() > 4) 
		{   //minimum size of 3 digits +1 to include $
			//express length as the number of 3-digit groups
			length = (pledge.length()-1) / 3;
			//jump through string 3 digits at a time to add commas
			for (int j = length; j > 0; j--) 
				pledge.insert(pledge.length() - (j * 3), ",");
			//advance through string right-to-left to insert comma breaks
		}
		outf << left << setw(nameWidth) << a[i].whole 
			<< right << setw(numWidth) << pledge << endl;
	}
	println(outf, maxOutputWidth, "\u2500");
	println(outf, maxOutputWidth, "#");
}

int main() {
	alumniType alumni[maxArraySize];
	int filesize;
	ofstream outf;
	outf.open("alumni.ot");
	initem(alumni, filesize);
	readem(alumni, filesize);
	splitstrings(alumni, filesize);
	printtitles(outf);
	printtable1(alumni, filesize, outf);
	sortbypledge(alumni, filesize);
	printcenter("Sorted by Pledge Amount", outf);
	//print table 1 again but sorted
	printtable1(alumni, filesize, outf);
	printcenter("Sorted by Last Name", outf);
	//print table 2 sorted by last name with total pledge
	printtable2(alumni, filesize, outf);
	printcenter("Sorted by zipcode", outf);
	//print table 3 sorted by zip
	printtable3(alumni, filesize, outf);
	outf << endl << endl << endl;
	printcenter("Sorted by Last Name", outf);
	//convert pledge to string, concat with symbols, sort by last name
	printpledgeasString(alumni, filesize, outf);
	return 0;
}