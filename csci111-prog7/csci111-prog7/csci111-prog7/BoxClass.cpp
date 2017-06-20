//Joel Cressy
#include <fstream>
#include <iomanip>
using namespace std;

class BoxClass {
public:
	BoxClass();
	BoxClass(double l, double w, double h);
	void printem(ofstream&);
	double getLength();
	double getWidth();
	double getHeight();
	void setLength(double);
	void setWidth(double);
	void setHeight(double);
	double getVolumeInches();
	double getVolumeFeet();
	double getSurfaceInches();
	double getSurfaceFeet();
private:
	double length, width, height;
	double InchToFeet(double);
	double FeetToInch(double);
};

int main()
{
	ofstream outf("boxobject.ot");
	outf.setf(ios::fixed);
	outf.precision(3);
	BoxClass box1, box2(12.225, 11.500, 12);
	//printing box1
	outf << "Data for box1:" << endl;
	box1.printem(outf);
	//printing box2
	outf << "Data for box2:" << endl;
	box2.printem(outf);
	//set new values for box 1
	box1.setWidth(24.333);
	box1.setLength(34.125);
	box1.setHeight(13.500);
	//print new dimensions
	outf << "New dimensions for box1:" << endl;
	box1.printem(outf);
	//get volume in cubic inches for box1 and box2 and print
	outf << "Volume in cubic inches for box1: " << box1.getVolumeInches() << endl;
	outf << "Volume in cubic inches for box2: " << box2.getVolumeInches() << endl;
	//get volume in cubic feet for box1 and box2 and print
	outf << "Volume in cubic feet for box1: " << box1.getVolumeFeet() << endl;
	outf << "Volume in cubic feet for box2: " << box2.getVolumeFeet() << endl;
	//get surface area in square inches for both boxes and print
	outf << "Surface area in square inches for box1: " << box1.getSurfaceInches() << endl;
	outf << "Surface area in square inches for box2: " << box2.getSurfaceInches() << endl;
	//get surface area in square feet for both boxes and print
	outf << "Surface area in square feet for box1: " << box1.getSurfaceFeet() << endl;
	outf << "Surface area in square feet for box2: " << box2.getSurfaceFeet() << endl;
	//Scenario H
	outf << "Minimum amount of xmas wrapping paper (in sq.ft.) for both boxes: " << box1.getSurfaceFeet() + box2.getSurfaceFeet() << endl;
	//Scenario I
	outf << "Minimum amount of soil (in cu.ft) to fill same size boxes as planters: " << box1.getVolumeFeet() + box2.getVolumeFeet() << endl;
	return 0;
}

BoxClass::BoxClass()
{
	length = 0.0;
	width = 0.0;
	height = 0.0;
}

BoxClass::BoxClass(double l, double w, double h)
{
	length = l;
	width = w;
	height = h;
}

void BoxClass::printem(ofstream & outf)
{
	outf << "The box object has these dimensions :" << endl;
	outf << setw(15) << right << "Length = " << setw(8) << length << left << setw(8) << " inches" << endl;
	outf << setw(15) << right << "Width = " << setw(8) << width << left << setw(8) << " inches" << endl;
	outf << setw(15) << right << "Height = " << setw(8) << height << left << setw(8) << " inches" << endl;
}

double BoxClass::getLength()
{
	return length;
}

double BoxClass::getWidth()
{
	return width;
}

double BoxClass::getHeight()
{
	return height;
}

void BoxClass::setLength(double x)
{
	length = x;
}

void BoxClass::setWidth(double y)
{
	width = y;
}

void BoxClass::setHeight(double z)
{
	height = z;
}

double BoxClass::getVolumeInches()
{
	return length * width * height;
}

double BoxClass::getVolumeFeet()
{
	return InchToFeet(getVolumeInches());
}

double BoxClass::getSurfaceInches()
{
	return 2*((width*length) + (height*length) + (height*width));
}

double BoxClass::getSurfaceFeet()
{
	return InchToFeet(getSurfaceInches());
}

double BoxClass::InchToFeet(double in)
{
	return in/12.0;
}

double BoxClass::FeetToInch(double ft)
{
	return ft*12.0;
}