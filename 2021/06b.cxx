
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>
#include <numeric>
using namespace ::std;

istream &operator>> ( istream &is, char const &c ) {
	istream::sentry sentry (is);
	if (sentry) { if ( is.peek() == c ) is.get(); else is.setstate(ios_base::failbit); }
	return is;
}

using uint128_t = __int128_t;

int main () {
	uint128_t fish[9] = { 0, };
	for ( unsigned n; cin >> n; cin >> ',' ) {
		if ( n > 8 )
			throw "Unexpectedly big fish number";
		++fish[n];
	}

	for ( int i = 0; i < 256; ++i ) {
		rotate( fish + 0, fish + 1, fish + 9 );
		fish[6] += fish[8];
	}

	uint128_t sum = accumulate( fish + 0, fish + 9, uint128_t(0) );
	uint128_t divisor = uint128_t(1) * 1000 * 1000 * 1000;
	uint64_t high = sum / divisor, low = sum % divisor;
	cout << high << setfill('0') << setw(9) << low << endl;
}

