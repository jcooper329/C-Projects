#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//constant variables
const double conversion = 2.54;

const int inchesInFoot = 12;

double getLength();

int main() //main method
{
	//variables
	double feet;
	double inches;
	double centimeters;
	int hold;

	cout << fixed << showpoint << setprecision(2);
	
	cout << "Feet: ";
	feet = getLength();
	cout << endl;

	cout << "Inches: ";
	inches = getLength();
	cout << endl;

	centimeters = (inchesInFoot * feet + inches) * conversion;

	cout << "Centimeter: " << centimeters << endl;

	cin >> hold;
	return 0;
}

double getLength() //gets length
{
	//variables
	bool done = false;
	double number = 0;

	string str = "The input stream is in the fail state.";

	do
	{
		try //trys to run the code
		{
			cout << "(Enter a non-negative number): ";
			cin >> number;
			cout << endl;

			if (number < 0)
				throw - 1;

			if (!cin)
				throw str;

			done = true;
		}
		catch (int) //catches if the code fails
		{
			cout << "A non positive number is entered,, please re-enter." << endl;
			number = 0;
		}
		catch (string messageStr) //catches if the code fails
		{
			cout << messageStr << endl << "Restoring the input stream."
				<< endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!done);

	return number; //returns the number
}