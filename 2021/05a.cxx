
#include <cstdlib>
#include <iostream>
#include <exception>
#include <utility>
#include <vector>
#include <map>
//#include <>
using namespace ::std;

istream &operator>> ( istream &is, char const &c ) {
	istream::sentry sentry (is);
	if (sentry) { if ( is.peek() == c ) is.get(); else is.setstate(ios_base::failbit); }
	return is;
}

istream &operator>> ( istream &is, char const *s ) {
	istream::sentry sentry (is);
	if (sentry) {
		for ( char c; is && (c = *s) != 0; ++s )
			if ( c == is.peek() ) is.get(); else is.setstate(ios_base::failbit);
	}
	return is;
}

struct Point { int x, y; };
istream &operator>> (istream &is, Point &p) { return is >> p.x >> ',' >> p.y; }
ostream &operator<< (ostream &os, Point const &p) { return os << p.x << ',' << p.y; }
bool operator< ( const Point &l, const Point &r ) { return l.x < r.x || l.x == r.x && l.y < r.y; }

using Line = pair< Point, Point >;
istream &operator>> (istream &is, Line &l) { return is >> l.first >> "->" >> l.second; }
ostream &operator<< (ostream &os, Line const &l) { return os << l.first << " -> " << l.second; }

int main () {

// first, read the data in
	vector <Line> lines;
	while (cin) {
		auto &line = lines.emplace_back();
		cin >> line;
		cin >> ws;
		cin.peek();
	}
	cerr << lines.size() << " lines found" << endl;

// "For now, only consider horizontal and vertical lines: lines where either x1 = x2 or y1 = y2."
	map< Point, int > points;
	int overlaps = 0;
	for ( auto const &line : lines ) {
		cerr << line << endl;
		Point p1 = line.first, p2 = line.second;
		if ( p1.x == p2.x ) {
			// vertical line
			if ( p1.y > p2.y ) swap (p1, p2);
			do
				if ( ++points[ p1 ] == 2 )
					++overlaps;
			while ( ++p1.y <= p2.y );
		} else if ( p1.y == p2.y ) {
			// horizontal line
			if ( p1.x > p2.x ) swap (p1, p2);
			do
				if ( ++points[ p1 ] == 2 )
					++overlaps;
			while ( ++p1.x <= p2.x );
		} else
			continue;
	}

	cerr << points.size() << " total points covered" << endl;
	cout << overlaps << " overlaps" << endl;

	return EXIT_SUCCESS;
}

