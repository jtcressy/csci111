//Joel Cressy
#include <iostream>
#include <fstream>
#include <iomanip>
//unused #include <string>

using namespace std;

const int linewidth = 85;

void printchar(char ch, int n, ofstream &outf)
{
     for (int i = 1; i <= n; i++)
     {
          outf << ch;
     }
}

void printtitles(ofstream &outf)
{
     outf << endl << right << setw(54) << "Mesa Manufacturing Company Payroll" << endl << endl;
     outf << right << setw(15) << "|" << setw(30) << "-=Hours Payable=-" << setw(15) << "|" 
		 << setw(9) << "Total" << setw(5) << "|" << endl;
     outf << left << setw(9) << " Emp#  |" << setw(5) << "Rate" << setw(9) << "|  Mon" << setw(7) 
		 << "Tues" << setw(7) << " Wed" << setw(7) << "Thurs" << setw(8) << " Fri" << setw(7) 
		 << "Total" << setw(15) << "| Nearest Qtr |" << setw(11) << "  Salary  |" << endl;
     printchar('=', linewidth, outf);
}

int sumhhmm(int a, int b)
{
     int hh = (a / 100) + (b / 100);
     int mm = (a % 100) + (b % 100);
     if (mm >= 60)
     {
          hh += mm / 60;
          mm = mm % 60;
     }
     return hh * 100 + mm;
}

double hhmmtodouble(int hhmm)
{
     int mm = hhmm % 100;
     int hh = hhmm / 100;
     if (mm <= 7) return hh * 1.0;
     else if (mm <= 22) return hh + 0.25;
     else if (mm <= 37) return hh + 0.5;
     else if (mm <= 52) return hh + 0.75;
     else return hh + 1.0;
}

double getsalary(double rate, double hours)
{
     double overtime;
     if (hours > 40)
     {
          overtime = hours - 40.0;
          return overtime * rate * 1.5 + 40.0 * rate;
     }
     else return hours * rate;
}

double roundem(double a)
{
     int b = (a * 100) + 0.5;
     return b / 100.0;
}

int main()
{
     int empnum, mon, tues, wed, thurs, fri;
     int tmon = 0, ttues = 0, twed = 0, tthurs = 0, tfri = 0, thours, gthhmm = 0;
     double tnqtr, gtnqtr, tsalary, salary;
     double payRate;
     ifstream inf;
     ofstream outf;
     inf.open("hhmmpayroll.dat");
     outf.open("hhmmpayroll.ot");
     outf.setf(ios::fixed);
     outf.precision(2);
     printtitles(outf);
     outf << endl;
     while (!inf.eof())
     {
          inf >> empnum >> payRate >> mon >> tues >> wed >> thurs >> fri;
          if (!inf.eof())
          {
               thours = sumhhmm(sumhhmm(sumhhmm(mon, tues), sumhhmm(wed, thurs)), fri);
               tnqtr = hhmmtodouble(thours);
               tmon = sumhhmm(tmon, mon);
               ttues = sumhhmm(ttues, tues);
               twed = sumhhmm(twed, wed);
               tthurs = sumhhmm(tthurs, thurs);
               tfri = sumhhmm(tfri, fri);
               gthhmm = sumhhmm(gthhmm, thours);
               gtnqtr = gtnqtr + tnqtr;
               salary = roundem(getsalary(payRate, tnqtr));
               tsalary += salary;
               outf << right << setw(6) << empnum << setw(8) << payRate << setw(6) << mon 
				   << setw(7) << tues << setw(7) << wed << setw(7) << thurs << setw(7) << fri 
				   << setw(9) << thours << setw(14) << tnqtr << setw(12) << salary << endl;
          }
     }
     printchar('=', 85, outf);
     outf << endl;
     outf << left << setw(15) << "Totals:" << right << setw(5) << tmon << setw(7) << ttues 
		 << setw(7) << twed << setw(7) << tthurs << setw(7) << tfri << setw(2) << "|" << setw (7) 
		 << gthhmm << setw(3) << "|" << setw(11) << gtnqtr << "  |" << setw(9) << tsalary << endl;
     return 0;
}
