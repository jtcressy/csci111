//Joel Cressy
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int maxsales = 15;
const int maxm = 6;
//non-required constants
const int maxoutputwidth = 90;
const int textcolwidth = 10;
const int numcolwidth = 6;
//end non-required constants

struct salesType
{
    int id;
    string first;
    string last;
    int hired;
    double sales[maxm];
    double Q1, Q2, Total;
};
const salesType initrec = {-1, "whatsit", "tooya", 0, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, 0.0, 0.0, 0.0};

void initem(salesType s[], int &n)
{
    for (int i = 0; i < maxsales; i++)
        s[i] = initrec;
    n = 0;
}

void readem(salesType s[], int &n)
{
    ifstream inf;
    inf.open("sales.dat");
    int i = 0;
    while (!inf.eof() && i < maxsales)
    {
        inf >> s[i].id >> s[i].first >> s[i].last >> s[i].hired;
        for (int j = 0; j < maxm; j++)
            inf >> s[i].sales[j];
        i++;
    }
    n = i;
}

void calcTotal(salesType s[], salesType &tot, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < maxm; j++)
        {
            tot.sales[j] += s[i].sales[j];
        }
        tot.Q1 += s[i].Q1;
        tot.Q2 += s[i].Q2;
        tot.Total += s[i].Total;
    }
}

void calcem(salesType s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i].Q1 = 0;
        s[i].Q2 = 0;
        for (int j = 0; j <= 2; j++)
            s[i].Q1 += s[i].sales[j];
        for (int j = 3; j <= 5; j++)
            s[i].Q2 += s[i].sales[j];
        s[i].Total = s[i].Q1 + s[i].Q2;
    }
}

void swapem(salesType &a, salesType &b)
{
    salesType temp;
    temp = a;
    a = b;
    b = temp;
}

void sortem(salesType s[], int n)
{
    for (int j = 0; j < n - 1; j++)
        for (int i = 0; i < n - 1; i++)
            if (s[i].id > s[i + 1].id)
                swapem(s[i], s[i + 1]);
}

void SalesStars(salesType s[], int n, ofstream &outf)
{
    int Q1 = 0, Q2 = 0, tot = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i].Q1 > s[Q1].Q1)
        {
            Q1 = i;
        }
    }
    outf << "Our Q1 sales star is: " << s[Q1].first << " " << s[Q1].last << endl;

    for (int i = 1; i < n; i++)
    {
        if (s[i].Q2 > s[Q2].Q2)
            Q2 = i;
    }
    outf << "Our Q2 sales star is: " << s[Q2].first << " " << s[Q2].last << endl;

    for (int i = 1; i < n; i++)
    {
        if (s[i].Total > s[tot].Total)
            tot = i;
    }
    outf << "Our overall sales star is: " << s[tot].first << " " << s[tot].last << endl;
}

int linearSearch(salesType s[], int key, int n, ofstream &outf)
{
    for (int i = 0; i < n; i++)
        if (key == s[i].id)
            outf << left << setw(numcolwidth) << s[i].id
                 << setw(textcolwidth) << s[i].first
                 << setw(textcolwidth) << s[i].last
                 << endl;
}

void linearFindAll(salesType s[], string key, int n, ofstream &outf)
{
    for (int i = 0; i < n; i++)
        if (key == s[i].last)
            outf << left << setw(numcolwidth) << s[i].id
                 << setw(textcolwidth) << s[i].first
                 << setw(textcolwidth) << s[i].last
                 << endl;
}

void printLine(char ch, int n, ofstream &outf) {
    for (int i = 0; i < n; i++) outf << ch;
    outf << endl;
}

void printtitles(ofstream &outf)
{
    string title1 = "CMU Distributing";
    string title2 = "Sales Report";
    outf << endl
         << setw(maxoutputwidth / 2 + title1.length() / 2) << title1 << endl
         << endl
         << setw(maxoutputwidth / 2 + title2.length() / 2) << title2 << endl
         << endl
         << left
         << setw(numcolwidth) << "ID"
         << setw(textcolwidth) << "First"
         << setw(textcolwidth) << "Last"
         << right
         << setw(numcolwidth) << "Hired"
         << setw(numcolwidth) << "Jan"
         << setw(numcolwidth) << "Feb"
         << setw(numcolwidth) << "Mar"
         << setw(numcolwidth) << "Apr"
         << setw(numcolwidth) << "May"
         << setw(numcolwidth) << "June"
         << setw(numcolwidth) << "Q1"
         << setw(numcolwidth) << "Q2"
         << setw(numcolwidth) << "Total"
         << endl;
    printLine('=',maxoutputwidth,outf);
}

void printem(salesType s[], salesType tot, int n, ofstream &outf)
{
    printtitles(outf);
    for (int i = 0; i < n; i++)
    {
        outf << left << setw(numcolwidth) << s[i].id << setw(textcolwidth) << s[i].first
             << setw(textcolwidth) << s[i].last << right << setw(numcolwidth) << s[i].hired;
        outf.precision(0);
        for (int j = 0; j < maxm; j++)
        {
            outf << setw(numcolwidth) << s[i].sales[j];
        }
        outf.precision(0);
        outf << setw(numcolwidth) << s[i].Q1 << setw(numcolwidth) << s[i].Q2 << setw(numcolwidth) << s[i].Total << endl;
    }
    printLine('=',maxoutputwidth,outf);
    calcTotal(s, tot, n);
    outf << left << setw(32) << "Totals: " << right;
    for (int i = 0; i < maxm; i++)
        outf << setw(numcolwidth) << tot.sales[i];
    outf << setw(numcolwidth) << tot.Q1 << setw(numcolwidth) << tot.Q2 << setw(numcolwidth) << tot.Total << endl << endl;
    SalesStars(s, n, outf);
    outf << endl << "Search Results:" << endl;
    outf << "Entry matching ID 6072:" << endl;
    linearSearch(s, 6072, n, outf);
    outf << "Entries with last name 'Hudson':" << endl;
    linearFindAll(s, "Hudson", n, outf);
}

int main()
{
    salesType Sales[maxsales];
    salesType totals = initrec;
    int nums;
    ofstream outf;
    outf.open("sales.ot");
    outf.setf(ios::fixed);
    initem(Sales, nums);
    readem(Sales, nums);
    calcem(Sales, nums);
    sortem(Sales, nums);
    printem(Sales, totals, nums, outf);
    return 0;
}