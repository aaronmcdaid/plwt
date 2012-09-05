plwt_test: plwt.hpp plwt_test.cpp
	g++-4.6 plwt_test.cpp -Wall -Wextra -std=gnu++0x -o plwt_test
	#~/prefix-clang/clang+llvm-3.0-x86_64-linux-Ubuntu-11_04/bin/clang++ plwt_test.cpp -Wall -Wextra -std=c++0x -o plwt_test
	./plwt_test

