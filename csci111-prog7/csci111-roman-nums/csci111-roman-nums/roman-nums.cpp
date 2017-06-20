#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const struct {
	int M, D, C, L, X, V, I;
} roman_nums = { 1000,500,100,50,10,5,1 };
const int numwidth = 15;
const int romanwidth = 20;
const int outputwidth = numwidth + romanwidth;

void readem(ifstream&, vector<string>&);
void printem(ofstream&, vector<string>);
int romToArabic(string);
void println(ofstream&, char, int);

int main()
{
	ifstream inf("roman-nums.dat");
	ofstream outf("roman-nums.ot");
	vector<string> data;
	readem(inf, data);
	printem(outf, data);
	return 0;
}

void readem(ifstream &inf, vector<string> &strvec)
{
	string str;
	while (getline(inf, str, '\n'))
	{
		strvec.push_back(str);
		str.clear();
	}
}

void printem(ofstream &outf, vector<string> strvec)
{
	string title = "Conversion from Roman Numerals to Arabic";
	outf << setw(title.length() / 2 + outputwidth / 2) << left << title << endl << endl;
	println(outf, '=', outputwidth);
	outf << setw(romanwidth) << left << "Roman Numeral" << right << setw(numwidth) << "Output" << endl;
	println(outf, '-', outputwidth);
	for (int i = 0; i < strvec.size(); i++)
		outf << left << setw(romanwidth) << strvec[i] << right << setw(numwidth) << romToArabic(strvec[i]) << endl;
	println(outf, '=', outputwidth);
}

int romToArabic(string str)
{
	int out = 0;
	int j = 0;
	j++;
	if (j == 4)	cout << "wewlad" << endl;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case 'M':
			out += roman_nums.M;
			break;
		case 'D':
			out += roman_nums.D;
			break;
		case 'C':
			if (str[i + 1] == 'D' || str[i + 1] == 'M')
				out -= roman_nums.C;
			else
				out += roman_nums.C;
			break;
		case 'L':
			out += roman_nums.L;
			break;
		case 'X':
			if (str[i + 1] == 'D' || str[i + 1] == 'M' || str[i + 1] == 'C' || str[i + 1] == 'L')
				out -= roman_nums.X;
			else
				out += roman_nums.X;
			break;
		case 'V':
			out += roman_nums.V;
			break;
		case 'I':
			if (str[i + 1] == 'D' || str[i + 1] == 'M' || str[i + 1] == 'C' || str[i + 1] == 'L' || str[i + 1] == 'X' || str[i+1] == 'V')
				out -= roman_nums.I;
			else
				out += roman_nums.I;
			break;
		}
	}
	return out;
}

void println(ofstream &outf, char ch, int n)
{
	for (int i = 0; i < n; i++)
		outf << ch;
	outf << endl;
}
