//Joel Cressy
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const int maxc = 100;
const int numwidth = 10;
const int alphawidth = 15;
const int twidth = 75;

void initem(int id[maxc], string first[maxc], string last[maxc], 
    double old[maxc], double pay[maxc], double purch[maxc], 
    double newBal[maxc], int filesize) 
{
    for (int i; i < maxc; i++) {
        id[i] = 0;
        first[i] = "Whatsit";
        last[i] = "Tooya";
        old[i] = 0;
        pay[i] = 0;
        purch[i] = 0;
        newBal[i] = 0;
        filesize = 0;
    }
}

double gettotal(double arr[], int filesize) 
{
    double total = 0.0;
    for (int i = 0; i < filesize; i++) {
        total += arr[i];
    }
    return total;
}

void readem(int id[maxc], string first[maxc], string last[maxc], 
    double old[maxc], double pay[maxc], double purch[maxc], 
    int &filesize, ifstream &inf)
{
    int i = 0;
    while (!inf.eof()) {
        inf >> id[i] >> first[i] >> last[i] >> old[i] 
            >> pay[i] >> purch[i];
        i++;
    }
    filesize = i;
}

void calcem(double old[maxc], double pay[maxc], double purch[maxc], 
    double newBal[maxc], int filesize) 
{
    for (int i = 0; i < filesize; i++) {
        newBal[i] = (old[i] + purch[i]) - pay[i];
    }
}
void swapem(int &a, int &b) 
{
    int c;
    c = a;
    a = b;
    b = c;
}
void swapem(double &a, double &b) 
{
    double c;
    c = a;
    a = b;
    b = c;
}
void swapem(string &a, string &b) 
{
    string c;
    c = a;
    a = b;
    b = c;
}
void sortem(int id[maxc], string first[maxc], string last[maxc], 
    double old[maxc], double pay[maxc], double purch[maxc], 
    double newBal[maxc], int filesize) 
{
    int i, j;
    for (j = 0; j < filesize - 1; j++) 
        for (i = 0; i < filesize - 1; i++)
            if (last[i] > last[i + 1])
            {
                swapem(last[i], last[i + 1]);
                swapem(id[i], id[i + 1]);
                swapem(first[i], first[i + 1]);
                swapem(old[i], old[i + 1]);
                swapem(pay[i], pay[i + 1]);
                swapem(purch[i], purch[i + 1]);
                swapem(newBal[i], newBal[i + 1]);
            }
}

void printtitles(ofstream &outf) 
{
    outf << endl << right << setw(37) << "A&B Variety" << endl << endl;
    outf << setw(46) << "Balances & Credits Report" << endl;
    for (int i = 0; i < twidth; i++) {
        outf << "\u2501";
    } outf << endl;
    outf << right << setw(41) << "Old" << setw(30) << "New" << endl;
    outf << left << setw(5) << " ID" << setw(alphawidth) << "First Name"
        << setw(alphawidth + 2) << "Last Name ↓" << right << setw(numwidth) << " Balance" 
        << setw(numwidth) << "Payments" << setw(numwidth) << "Purchases" 
        << setw(numwidth) << "Balance" << endl;
    for (int i = 0; i < twidth; i++) {
        outf << "\u2501";
    } outf << endl;
}

void printem(int id[maxc], string first[maxc], string last[maxc], 
    double old[maxc], double pay[maxc], double purch[maxc], 
    double newBal[maxc], int filesize, ofstream &outf) 
{
    printtitles(outf);
    for (int i = 0; i < filesize; i++) {
        outf << left << setw(5) << id[i] << setw(alphawidth) << first[i] 
            << setw(alphawidth) << last[i] << right << setw(numwidth) << old[i] 
            << setw(numwidth) << pay[i] << setw(numwidth) << purch[i] << setw(numwidth)
            << newBal[i] << endl;  
    }
    for (int i = 0; i < twidth; i++) {
        outf << "\u2501";
    } outf << endl;
    outf << left << setw(twidth - (numwidth*4)) << "Totals: " << right << setw(numwidth) 
        << gettotal(old, filesize) << setw(numwidth) << gettotal(pay, filesize) 
        << setw(numwidth) << gettotal(purch, filesize) << setw(numwidth) << gettotal(newBal, filesize) << endl;
}

int main() 
{
    string first[maxc], last[maxc];
    int id[maxc], filesize;
    double oldbalance[maxc], payments[maxc], purchases[maxc], newbalance[maxc]; 
    initem(id, first, last, oldbalance, payments, purchases, newbalance, filesize);
    ifstream inf;
    ofstream outf;
    inf.open("storecredit.dat");
    outf.open("storecredit.ot");
    outf.precision(2);
    outf.setf(ios::fixed);
    readem(id, first, last, oldbalance, payments, purchases, filesize, inf);
    calcem(oldbalance, payments, purchases, newbalance, filesize);
    sortem(id, first, last, oldbalance, payments, purchases, newbalance, filesize);
    printem(id, first, last, oldbalance, payments, purchases, newbalance, filesize, outf);
    return 0;
}