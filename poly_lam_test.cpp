#include<iostream>
using namespace std;
#include "poly_lam.hpp"
using namespace poly_lam;

int main() {
	cout << pol(3,4) << endl;
	cout << pol(3.0,4.0) << endl;
	cout << pol(3.3,4.4) << endl;
	cout << pol(5,"skip_the_start") << endl;
	cout << pol("skip_the_start",5) << endl;
}
