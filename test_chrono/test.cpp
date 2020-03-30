// ConsoleApplication4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Chrono.h"
using namespace std;
std::ostream& operator<<(std::ostream& os, const Chrono& chrono) {
	return os << chrono.h() << ":" << chrono.m() << ":" << chrono.s();
}
std::istream& operator>>(std::istream& is, Chrono& chrono) {
	string s;
	is >> s;
	chrono = s; // conversion method from string to chrono
	return is;
}


int Chrono::nb_object = 0; //static variable need to be here !!!
//just to see the count up and count down with destructor
void test_function() {
	Chrono test{};
	cout << "in test function nb instance : " << Chrono::nb_instance() << endl;
}
//test class Chrono 
int main() {
	//begin to test static counter of Chrono and use of destructor
	Chrono test{};
	cout << "before test function nb instance : " << Chrono::nb_instance() << endl;
	test_function();
	cout << "after test function nb instance : " << Chrono::nb_instance() << endl;
	//test of function operator<<
	cout << "first objet test : " << test << endl;
	cout << "enter an time : format(hh:mm:ss) -> ";
	try {
		cin >> test;//test of function operator>>
	}
	catch (string s) {//test of n operator= with throw i
		cout << s << endl;
		test = "0:0:0";
		cout << "raz chronometer test  :" << test << endl;
	}
	Chrono test1("1:2:3");// test of Chrono(const string)
	Chrono test3("1:2:3");
	if (test1 == test3)// test of operator ==
		cout << "ok" << endl;
	int nb_seconds = test1;// test of operator int () const method
	cout << "1:2:3 = " << nb_seconds << " seconds" << endl;
	try {
		test += test1;// test of operator+=(const Chrono &)
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