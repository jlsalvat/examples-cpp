#pragma once
#include <string>
#include <iostream>

class Chrono {
	//private properties
	int _h=0, _m=0, _s=0; //hour:minute:second
	static int nb_object;//how many Chrono object use ?
//for calculs
	static const int MINUTE_PER_HOUR = 60;
	static const int SEC_PER_MINUTE = 60;
public:
	//2 constructors with nb_object counter and overflow detection
	Chrono(int heure, int minute, int seconde);
	Chrono() = default;
	Chrono(const std::string heure);
	//destructor for count down object counter
	~Chrono();

	//add function
	Chrono& add_second(int value);
	Chrono& add_minute(int value);
	Chrono& add_heure(int value);
	void raz() {
		_h = _m = _s = 0;
	}
	Chrono& operator+=(const Chrono& heure); 
	Chrono& operator+=(const int second); 
	Chrono& operator=(const std::string heure); 
	bool operator==(const Chrono& heure) const {
		return (_h == heure.h() && _m == heure.m() && _s == heure.s());
	}
	//getter 
	int      s() const { return _s; }
	int       m() const { return _m; }
	int       h() const { return _h; }
	operator int() const {
		return _h * MINUTE_PER_HOUR*SEC_PER_MINUTE + _m * SEC_PER_MINUTE + _s;
	}
	//static function
	static int nb_instance() {
		return nb_object;
	}
private:
	//method only for method of the class
	bool is_overflow() {
		return(_h > 23 || _m > MINUTE_PER_HOUR || _s > SEC_PER_MINUTE);
	}
	// string to Chrono conversion with throw error
	Chrono& string_to_chrono(std::string heure);
};

