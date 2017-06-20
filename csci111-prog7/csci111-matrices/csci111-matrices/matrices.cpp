//Joel Cressy
/*
Also, I'm trying some new stuff since it's extra credit.
I'll experiment and go beyond some of the requirements of the 
assignment.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
//setup shortcut for defining 2-D vector (matrices)
typedef vector<vector<int>> Matrix;

void readem(Matrix&,Matrix&,ifstream&);
void writeMatrix(Matrix&,ofstream&);
Matrix add(Matrix&,Matrix&);
Matrix subtract(Matrix&,Matrix&);
Matrix scalarMulti(Matrix&,int);
Matrix matrixMulti(Matrix&,Matrix&);
void println(int, char, ofstream&);

int main()
{
	ifstream inf("matrices.dat");
	ofstream outf("matrices.ot");
	outf.setf(ios::fixed);
	outf.precision(2);
	Matrix A, B;
	readem(A, B, inf);
	//output matrices
	outf << "Matrix A:" << endl;
	writeMatrix(A, outf);
	outf << "Matrix B:" << endl;
	writeMatrix(B, outf);
	println(15, '=', outf);
	//add matrices
	outf << "Matrix A + B:" << endl;
	writeMatrix(add(A, B), outf);
	println(15, '=', outf);
	//subtract matrices
	outf << "Matrix A - B:" << endl;
	writeMatrix(subtract(A, B), outf);
	println(15, '=', outf);
	//scalar multiplication
	outf << "Matrix A * 5:" << endl;
	writeMatrix(scalarMulti(A, 5), outf);
	println(15, '=', outf);
	outf << "Matrix B * 5:" << endl;
	writeMatrix(scalarMulti(B, 5), outf);
	println(15, '=', outf);
	//matrix multiplication
	outf << "Matrix A * B:" << endl;
	writeMatrix(matrixMulti(A, B), outf);
	return 0;
}

void readem(Matrix &va, Matrix &vb, ifstream &inf)
{
	while (!inf.eof())
	{
		string str,line;
		stringstream ss;
		while (getline(inf, line) && line != "") {
			ss << line;
			vector<int> newRow;
			while (getline(ss, str,'\t')) 
			{
				newRow.push_back(stoi(str));
			}
		va.push_back(newRow);
		ss.clear();
		line.clear();
		str.clear();
		}
		//input file separated matrices with empty lines, 
		//to allow for dynamically sized matrices, 
		//however only two matrices are allowed to be specified.
		while (getline(inf, line) && line != "") {
			ss << line;
			vector<int> newRow;
			while (getline(ss, str, '\t')) {
				newRow.push_back(stoi(str));
			}
			vb.push_back(newRow);
			ss.clear();
			line.clear();
			str.clear();
		}
	}
}

void writeMatrix(Matrix &a, ofstream &outf)
{
	for (int i = 0; i < a.size(); i++) 
	{
		for (int j = 0; j < a[i].size(); j++)
			outf << right << setw(4) << a[i][j];
		outf << endl;
	}
}

Matrix add(Matrix &va, Matrix &vb)
{
	Matrix out;
	if ((va.size() == vb.size()) && (va[0].size() == vb[0].size()))
	{
		int rows = va.size();
		int columns = va[0].size();
		for (int i = 0; i < rows; i++) 
		{
			vector<int> newRow;
			for (int j = 0; j < columns; j++)
				newRow.push_back(va[i][j] + vb[i][j]);
			out.push_back(newRow);
		}
	}
	else
		out.push_back({ 0 });
	return out;
}

Matrix subtract(Matrix &va, Matrix &vb)
{
	Matrix out;
	if ((va.size() == vb.size()) && (va[0].size() == vb[0].size()))
	{
		int rows = va.size();
		int columns = va[0].size();
		for (int i = 0; i < rows; i++)
		{
			vector<int> newRow;
			for (int j = 0; j < columns; j++)
				newRow.push_back(va[i][j] - vb[i][j]);
			out.push_back(newRow);
		}
	}
	else
		out.push_back({ 0 });
	return out;
}

Matrix scalarMulti(Matrix &a, int n)
{
	Matrix out;
	for (int i = 0; i < a.size(); i++)
	{
		vector<int> newRow;
		for (int j = 0; j < a[i].size(); j++)
			newRow.push_back(a[i][j] * n);
		out.push_back(newRow);
	}
	return out;
}

Matrix matrixMulti(Matrix &va, Matrix &vb)
{
	Matrix out;
	if (va[0].size() == vb.size()) {
		for (int x = 0; x < va[0].size(); x++)
		{
			vector<int> newRow;
			for (int y = 0; y < vb.size(); y++)
			{
				int n = 0;
				for (int z = 0; z < va[0].size(); z++)
					n += va[x][z] * vb[z][y];
				newRow.push_back(n);
			}
			out.push_back(newRow);
			newRow.clear();
		}
	}
	else
		out.push_back({ 0 });
	return out;
}

void println(int n, char ch, ofstream &outf)
{
	for (int i = 0; i < n; i++)
		outf << ch;
	outf << endl;
}
