#pragma once
#include <string>
#include <map>
using namespace std;
//use time class
class Time
{
private:
	map<string, int> time;
public:
	const int toSeconds() {
		 int s = (time["hour"] * 60 * 60) + time["minute"] * 60 + time["second"];
		 return s;
	}

	Time(int hour, int minute, int second){
		time = {
			{"hour", hour},
			{ "minute", minute },
			{ "second", second }
		};
	}

	Time(string str) {
		
	}

	Time(int seconds) {
		int hours = seconds % 60 % 60;
		int minutes = seconds % 60;
		int second = hours * 60 * 60 - minutes * 60;

		Time(hours, minutes, second);
	}

	Time(  Time& obj)  {
		time = obj.time;
	}


};

