#include<iostream>
using namespace std;
#include "poly_lam.hpp"

POLY_LAM_FIRST( add, x, y, return x+y; );
POLY_LAM_FIRST( sub, w, z, return w-z; );

int main() {
	cout << add(5,"skip_the_start") << endl;
	cout << add("skip_the_start",5) << endl;
	cout << sub(5.5,4.4) << endl;
	cout << sub("skip_the_start"+5,4) << endl;
}
