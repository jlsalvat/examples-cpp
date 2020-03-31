#include <iostream>
#include "Chrono.h"
using namespace std;


//test class Chrono 
int main() {
	//begin to test static counter of Chrono and use of destructor
	Chrono test;
	cout << "enter an time : format(hh:mm:ss) -> ";
	try {
		cin >> test;//test of function operator>>
	}
	catch (string s) {//test of n operator= with throw i
		cout << test << " " << s << ":" << "raz" << endl;
		test.raz();
	}
	try {
		test += Chrono(23,0,0);// test of operator+=(const Chrono &)
		test += 3601;// test of operator+=(int)
	}
	catch (string s) {
		cout << test << " " << s << ":" << "raz" << endl;
		test.raz();
	}
	cout << test << endl;
	try {
		test.add_second(82861).add_minute(1).add_heure(1);// test of add function
	}
	catch (string s) {
		cout << test << " " << s << ":" << "raz" << endl;
		test.raz();
	}
	cout << test << endl;
}
