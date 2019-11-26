#include <iostream>
#include "Time.h"

int main() {
	Time t(555442);
	cout << t.toSeconds();
	return 0;
}