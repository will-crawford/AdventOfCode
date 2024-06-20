
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace ::std;

#define D(e) cerr << e << endl
#define E(e) #e << " = " << (e)
#define COMMA << ", "

ostream &operator<< ( ostream &os, vector<int8_t> const &v ) {
	auto i = begin(v), j = end(v);
	os << "{";
	if (i != j) {
		os << " " << int(*i);
		while (++i != j)
			os << ", " << int(*i);
	}
	return os << " }";
}

void CheckPoint ( auto &above, auto &current, auto &below, auto &counts, auto n ) {
	auto h = current[n];
	if ( h < above[n] && h < current[n-1] && h < current[n+1] && h < below[n] )
		++counts[h];
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	array<int, 10> counts; counts.fill(0);
	vector< vector<int8_t> > heights;

	// read data in, adding fake top and bottom lines to simplify checking above & below
	string line; cin >> line;	// read first line in so we can see length
	auto N = line.length();
	heights.emplace_back( N + 2, 9 );
	do {
		auto &row = heights.emplace_back( ); row.reserve( N + 2 );
		row.emplace_back( 9 );
		for ( auto &c : line )
			row.emplace_back( c - '0' );
		row.emplace_back( 9 );
	} while ( cin >> line );
	heights.emplace_back( N + 2, 9 );
	auto M = heights.size() - 2;
	D( E(M) COMMA E(N) );
	if (!M) throw "invalid input";

	auto above = begin(heights), current = next(above), below = next(current);
	for ( auto m = M; ; above = current, current = below, below = next(below) ) {
		for ( auto n = N; n; --n )
			CheckPoint( *above, *current, *below, counts, n );
		if (!--m)
			break;
	}

	// and now add (part 'a') or multiply (part 'b') the heights of the low spots
	int64_t total = 0;
	for ( int c = 10; --c >= 0; )
		for ( auto h = counts[c]; h; --h )
			total += ( c + 1 );

	cout << total << endl;
	return EXIT_SUCCESS;
}

