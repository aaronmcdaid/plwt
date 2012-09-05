#include<iostream>
using namespace std;
#include "plwt.hpp"

namespace x{
PLWT( add, x, y )( return x+y; );
PLWT( sub, w, z )( return w-z; );
}

struct Noisy {
	int x_;
	Noisy(int x) : x_(x) {
		cout << "Noisy() " << x_ << endl;
	}
	Noisy(const Noisy &n) : x_(n.x_+1) {
		cout << "Noisy(const Noisy &) " << x_ << endl;
	}
	Noisy(const Noisy &&n) : x_(n.x_+1) {
		cout << "Noisy(const Noisy &&) " << x_ << endl;
	}
};
Noisy operator+ (const Noisy& l, const Noisy& r) {
	return Noisy(l.x_ + r.x_);
}

int main() {
	cout << x :: add(5,"skip_the_start") << endl;
	cout << x :: add("skip_the_start",5) << endl;
	cout << x :: sub(5.5,4.4) << endl;
	cout << x :: sub("skip_the_start"+5,4) << endl;
	cout << x :: add(Noisy(10), Noisy(200)).x_ << endl;
	Noisy noisy10(10);
	Noisy noisy200(200);
	cout << x :: add(noisy10, noisy200).x_ << endl;
}
