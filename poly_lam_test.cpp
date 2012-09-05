#include<iostream>
using namespace std;
#include "poly_lam.hpp"
using namespace poly_lam;

POLY_LAM_FIRST( add, x, y, [](T0 x,T1 y){ return x+y;} );
template struct just_the_lambda_itself_add<int,int>;

int main() {
	cout << add(3,4) << endl;
	cout << add(3.0,4.0) << endl;
	cout << add(3.3,4.4) << endl;
	cout << add(5,"skip_the_start") << endl;
	cout << add("skip_the_start",5) << endl;
}
