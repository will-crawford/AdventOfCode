
#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace ::std;

#define D(e) cerr << e << endl
#define E(e) #e << " = " << (e)
#define COMMA << ", "

template <typename T, typename Container>
ostream &operator<< ( ostream &os, Container const &v ) {
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

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	array< string, 10 > distinct;
	array< string, 4 > output;
	int oneFourSevenEight = 0;

	while (cin.peek() && cin) {
		for ( auto &s : distinct )
			cin >> s;
		cin >> ws >> '|';
		for ( auto &s : output )
			cin >> s;
		cin >> ws;
		for ( auto const &s : output ) {
			switch (s.length()) {
				case 2: case 3: case 4: case 7:
					++ oneFourSevenEight;
					break;
				default:
					;
			}
		}
	}

	cout << oneFourSevenEight << endl;
}

