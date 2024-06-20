
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <cstdlib>
using namespace ::std;

istream &operator>> ( istream &is, char const &c ) {
	istream::sentry sentry (is);
	if (sentry) { if ( is.peek() == c ) is.get(); else is.setstate(ios_base::failbit); }
	return is;
}

int main () {
	vector<int> crabs;
	for ( int n; cin >> n; cin >> ',' )
		crabs.push_back(n);
	auto left = begin(crabs), right = end(crabs);
	int lwm, hwm;
	{ auto [li, hi] = minmax_element(left, right); lwm = *li, hwm = *hi; }
	vector<uint64_t> costs(hwm - lwm + 1);
	iota( begin(costs), end(costs), 0 );
	partial_sum( begin(costs), end(costs), begin(costs) );
	uint64_t fuel = numeric_limits<uint64_t>::max();
	for ( int n = lwm; n <= hwm; ++n ) {
		uint64_t cost = accumulate(
			left, right, uint64_t(0),
			[=] ( auto x, auto y ) { return x + costs[ std::abs( n - y ) ]; }
		);
		if ( cost < fuel )
			fuel = cost;
	}
	cout << fuel << endl;
}

