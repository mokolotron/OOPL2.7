#include <iostream>
#include "Time.h"

int main() {
	cout << "t2 init as seconds \'1574791000\' " << endl;
	Time t(1574791000);
	cout << "t1 Seconds: " << t.toSeconds()<<endl;
	cout << "t1 Minutes: " << t.toMinutes()<<endl;
	
	cout << "t2 init as string \"12 24 11\" " <<endl;
	Time t2("12 24 11");

	cout << "t3 init by constructor copy with agr t2 " << endl;
	Time t3(t2);

	cout << "t4 init by 3 number - 11, 22, 33 " << endl;
	Time t4(11, 22, 33);

	cout << endl << "t1 = " << t.toString() << " t2 = " << t2.toString()
		<< " t3 = " << t3.toString() << " t4 = " << t4.toString() << endl;
	
	

	bool more = t > t2;
	cout<<endl << "t > t2 = " << boolalpha << more <<endl;
	
	cout << "t - t2 = " << t-t2  <<endl;

	t.add(t2.toSeconds());
	cout << "t.add(t2) = " << t.toString() <<endl;

	




	return 0;
}