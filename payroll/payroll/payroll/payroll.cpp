//payroll
//Joel Cressy
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
  string name;
  char employeeType;
  double hourlyRate, hoursWorked;
  int overtime;
  double salary, taxesPaid, netPay, taxrate;
  int totalHours = 0;
  double totalPayroll = 0, totalTaxes = 0, totalNetPay = 0;
  ifstream inf;
  ofstream outf;
  inf.open("employeehours.dat");
  outf.open("payroll.ot");
  outf << right << setw(46) << "Hoity Toity Baby Furniture" << endl <<
    setw(42) << "Employee  Payroll" << endl << endl;
  outf << "  Name   | Type | Rate | Hours |  Salary  |  Taxes  |  NetPay  |" << endl;
  outf << "=========+======+======+=======+==========+=========+==========+" << endl;
  for (int i = 0; i < 10; i++) {
    inf >> name >> employeeType >> hourlyRate >> hoursWorked;
    if ( hoursWorked > 40 ) {
      overtime = hoursWorked - 40;
      salary = 40 * hourlyRate + overtime * hourlyRate * 1.50;
    }else{
      salary = hoursWorked * hourlyRate;
    }
    if ( employeeType == 'F' )
    {
      if ( salary >= 400 ) taxrate = 0.25;
      else if ( salary >= 250 ) taxrate = 0.15;
      else taxrate = 0;
    }
    else
    {
      if (salary >= 250) taxrate = 0.20;
      else if (salary >= 125 && salary < 250) taxrate = 0.10;
      else taxrate = 0;
    }
    netPay = salary * (1 - taxrate);
    taxesPaid = salary * taxrate;
    totalHours += hoursWorked;
    totalPayroll += salary;
    totalTaxes += taxesPaid;
    totalNetPay += netPay;
	  outf.setf(ios::fixed);
	  outf.precision(2);
	  outf << left << setw(13) << name << setw(1) << employeeType << right << setw(8) << hourlyRate << setw(8)
      << hoursWorked << setw(11) << salary << setw(10) << taxesPaid << setw(11) << netPay << endl;
  }
  for (int i = 0; i < 64; i++) outf << "=";
  outf << endl;
  outf << left << setw(22) << "Totals: " << right << setw(6) << totalHours << setw(13) << totalPayroll
    << setw(10) << totalTaxes << setw(11) << totalNetPay << endl;
  for (int i = 0; i < 64; i++) outf << "=";
  return 0;
}
