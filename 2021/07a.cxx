
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
	for ( unsigned n; cin >> n; cin >> ',' )
		crabs.push_back(n);
	auto left = begin(crabs), middle = left + crabs.size() / 2, right = end(crabs);
	nth_element( left, middle, right );
	uint64_t median = *middle;
	uint64_t fuel = accumulate(
		left, middle, uint64_t(0),
		[=] ( auto x, auto y ) { return x + ( median - y ); }
	) + accumulate(
		middle, right, uint64_t(0),
		[=] ( auto x, auto y ) { return x + ( y - median ); }
	);
	cout << fuel << endl;
}

