
#include <cstdlib>
#include <iostream>
#include <string>
// #include <string_view>
using namespace ::std;

int64_t f1p2 (string &s) {
	string::size_type l = s.length();
	if (!l) return 0LL;
	auto start = begin(s), p = start, q = p + l / 2, finish = end(s);
	int64_t total = 0;
	for ( char a, b; p != finish; ++p ) {
		a = *p, b = *q;
		if ( a == b )
			total += a - '0';
		if ( ++q == finish )
			q = start;
	}
	return total;
}

int main (int, const char **) {
	string s; cin >> s;
	cout << f1p2(s) << endl;
	return EXIT_SUCCESS;
}

