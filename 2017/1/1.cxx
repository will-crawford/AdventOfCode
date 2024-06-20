
#include <cstdlib>
#include <iostream>
#include <string>
// #include <string_view>
using namespace ::std;

int64_t f1 (string &s) {
	auto p = begin(s), q = end(s);
	if ( q == p )
		return 0;
	int64_t total = 0;
	for ( char a, b = *p; ; ) {
		a = *--q;
		if ( a == b )
			total += a - '0';
		if ( q == p )
			break;
		b = a;
	}
	return total;
}

int main (int, const char **) {
	string s; cin >> s;
	cout << f1(s) << endl;
	return EXIT_SUCCESS;
}

