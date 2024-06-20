
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <numeric>
using namespace ::std;

istream &operator>> ( istream &is, char const &c ) {
	istream::sentry sentry (is);
	if (sentry) { if ( is.peek() == c ) is.get(); else is.setstate(ios_base::failbit); }
	return is;
}

int main () {
	uint64_t fish[9] = { 0, };
	for ( unsigned n; cin >> n; cin >> ',' ) {
		if ( n > 8 )
			throw "Unexpectedly big fish number";
		++fish[n];
	}

	for ( int i = 0; i < 80; ++i ) {
//		int expired = fish[0];
		rotate( fish + 0, fish + 1, fish + 9 );
		fish[6] += fish[8];
//		fish[6] += expired;
	}

	cout << accumulate( fish + 0, fish + 9, uint64_t(0) ) << endl;
}

