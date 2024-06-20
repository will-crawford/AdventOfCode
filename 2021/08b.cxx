
#include <cstdint>
#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace ::std;

#define D(e) cerr << e << endl << flush
#define E(e) #e << " = " << (e)
#define COMMA << ", "

template< typename T, size_t N >
ostream &operator<< ( ostream &os, array< T, N > const &v ) {
	auto i = begin(v), j = end(v);
	os << "{";
	if (i != j) {
		os << " " << *i;
		while (++i != j)
			os << ", " << *i;
	}
	return os << " }";
}

istream &operator>> ( istream &is, char const &c ) {
	istream::sentry sentry (is);
	if (sentry) { if ( is.peek() == c ) is.get(); else is.setstate(ios_base::failbit); }
	return is;
}

array< int, 7 > bit2mask = { 1, 2, 4, 8, 16, 32, 64 };
array< array< bool, 7 >, 10 > digit2segments { {
	{ true, true, true, false, true, true, true },
	{ false, true, false, false, true, false, false },
	{ true, false, true, true, true, false, true },
	{ true, true, false, true, true, false, true },
	{ false, true, false, true, true, true, false },
	{ true, true, false, true, false, true, true },
	{ true, true, true, true, false, true, true },
	{ false, true, false, false, true, false, true },
	{ true, true, true, true, true, true, true },
	{ true, true, false, true, true, true, true }
} };

inline int string2mask ( const string &s ) {
	int value = 0;
	for ( auto const &c : s )
		value |= bit2mask[ c - 'a' ];
	return value;
}

using Patterns = array< int, 10 >;
using Map = map< array< int, 10>, array< int, 10 > >;
Map patternMappings;

void MakeMappings ( Map & mappings ) {
	array< int, 7 > permutation;
	iota( begin(permutation), end(permutation), 0 );
	array< int, 10 > digits;
	do {
		for ( int i = 0; i < 10; ++i ) {
			const auto &segments = digit2segments[i];
			int value = 0;
			for ( int j = 0; j < 7; ++j )
				if ( segments[j] )
					value |= bit2mask[ permutation[j] ];
			digits[i] = value;
		}
		array< int, 10 > sorted = digits;
		sort( begin(sorted), end(sorted) );
		mappings[ sorted ] = digits;
	} while ( next_permutation( begin(permutation), end(permutation) ) );
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	MakeMappings( patternMappings );

	array< string, 10 > distinct;
	array< string, 4 > output;
	uint64_t total = 0;

	while (cin.peek() && cin) {
		for ( auto &s : distinct )
			cin >> s;
		cin >> ws >> '|';
		for ( auto &s : output )
			cin >> s;
		cin >> ws;

		array< int, 10 > sorted;
		transform( begin(distinct), end(distinct), begin(sorted), string2mask );
		sort( begin(sorted), end(sorted) );

		auto pi = patternMappings.find( sorted );
		if ( pi == end(patternMappings) )
			throw "Failed to find input patterns in mappings";
		auto const &digits = pi->second;

		array< int, 128 > outputMapping;
		for ( int i = 0; i < 10; ++i )
			outputMapping[ digits[i] ] = i;
		int value = 0;
		for ( auto const &s : output )
			value = value * 10 + outputMapping[ string2mask(s) ];
		total += value;
	}

	cout << total << endl;
}

