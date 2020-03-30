#include "Chrono.h"
using namespace std;

	//2 constructors with nb_object counter and overflow detection
	Chrono::Chrono(int heure = 0, int minute = 0, int seconde = 0) :
		_h(heure), _m(minute), _s(seconde) {
		nb_object++;
		if (is_overflow()) {
			throw string("error overflow ");
		}
	}
	Chrono::Chrono(const string heure) {
		nb_object++;
		*this = string_to_chrono(heure);
	}
	//destructor for count down object counter
	Chrono::~Chrono() {
		nb_object--;
	}
	Chrono& Chrono::operator+=(const Chrono& heure) {
		(*this).add_second(heure.s()).add_minute(heure.m()).add_heure(heure.h());
		return *this;
	}
	Chrono& Chrono::operator+=(const int second) {
		(*this).add_second(second);
		return *this;
	}
	Chrono& Chrono::operator=(const std::string heure) {
		(*this) = string_to_chrono(heure);
		return *this;
	}

	//add function
	Chrono& Chrono::add_second(int value) {
		_s = (_s + value) % SEC_PER_MINUTE;
		_m = _m + (value / SEC_PER_MINUTE) % MINUTE_PER_HOUR;
		_h = _h + value / (MINUTE_PER_HOUR*SEC_PER_MINUTE);
		if (is_overflow())
			raz();
		return *this;
	}
	Chrono& Chrono::add_minute(int value) {
		_m += (_m + value) % MINUTE_PER_HOUR;
		_h = _h + _m / MINUTE_PER_HOUR;
		if (is_overflow())
			raz();
		return *this;
	}
	Chrono& Chrono::add_heure(int value) {
		_h += value;
		if (is_overflow())
			raz();
		return *this;
	}

	// string to Chrono conversion with throw error
	Chrono& Chrono::string_to_chrono(string heure) {
		int first_separator = heure.find(':');
		int second_separator = heure.rfind(':');
		if (first_separator > 2 || (heure.size() - second_separator) > 2)
			throw string("error format :") + heure;
		string h = heure.substr(0, first_separator);
		string m = heure.substr(first_separator + 1, 2);
		string s = heure.substr(second_separator + 1, heure.size());
		(*this)._h = stoi(h); (*this)._m = stoi(m); (*this)._s = stoi(s);
		if (is_overflow()) {
			throw string("error overflow ");
		}
		return *this;
	}


