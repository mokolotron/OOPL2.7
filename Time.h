#pragma once
#include <string>
#include <map>
#include <time.h>
#include <sstream>
using namespace std;

class Time
{
private:
	map<string, int> time;

	void init(int hour, int minute, int second) {
		this->time = {
			{ "hour", hour},
			{ "minute", minute },
			{ "second", second }
		};
	}

	tm toTm(int seconds) {
		time_t ltime(seconds);
		struct tm  newtime;
		localtime_s(&newtime, &ltime);
		return newtime;
	}
public:
	const int toSeconds() {
		 int s = (time["hour"] * 60 * 60) + time["minute"] * 60 + time["second"];
		 return s;
	}

	int toMinutes() {
		int s = (time["hour"] * 60 ) + time["minute"] ;
		
		//rounding
		if (time["second"] >= 30)
			s += 1;

		return s;
	}

	Time(int hour, int minute, int second){
		this->init ( hour,  minute,  second);
	}

	Time(string str) {
		istringstream stm(str);
		string word;
		string arr[3];
		for (int i = 0; i < 3; i++) {
			stm >> word;
			arr[i] = word;
		}

		int hour = stoi(arr[0]);
		int minute = stoi(arr[1]);
		int second = stoi(arr[2]);

		init( hour, minute, second );
		
	}

	Time(int seconds){
	    struct tm  newtime = toTm(seconds);
		init(newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
	}

	Time( Time& obj)  {
		time = obj.time;
	}

	int operator - (Time obj){
		return this->toSeconds() - obj.toSeconds();
	}

	void add(int seconds) {
		tm oldtime = toTm( toSeconds() );
		tm addtime = toTm(seconds);

		tm newtime = toTm((mktime(&oldtime) - mktime(&addtime)));
		init(newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
	}



	void decrease(int seconds) {
		tm oldtime = toTm(toSeconds());
		tm addtime = toTm(seconds);
		tm newtime = toTm(abs(mktime(&oldtime) - mktime(&addtime)));;
	
		init(newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
	}

	bool operator > (Time obj) {
		if (toSeconds() > obj.toSeconds())
			return true;
		else 
			return false;
	}

	string toString() {
		
		string s = to_string(this->time["hour"]) + ':';

		s += to_string(this->time["minute"]) + ':' ;
		s += to_string(this->time["second"]) ;
		return s;
	}



	


};

