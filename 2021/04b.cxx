
#include <cstdlib>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <map>
using namespace ::std;

#define D(e) cerr << e << endl
#define E(e) #e << " = " << (e)
#define COMMA << ", "

template <typename T>
ostream &operator<< ( ostream &os, vector<T> const &v ) {
	auto i = begin(v), j = end(v);
	os << "{";
	if (i != j) {
		os << " " << *i;
		while (++i != j)
			os << ", " << *i;
	}
	return os << " }";
}

using Numbers = vector< int >;
using Marks = uint32_t;
struct Card {
	array< int, 25 > cells;
	Marks marks;
	bool won;
	Card () : marks (0), won(false) { /* cells.fill(0) */ }
	void mark ( int offset ) { marks |= ( 1U << offset ); }
	bool marked ( int offset ) { return marks & ( 1U << offset ); }
	bool check_ ( int offset, int stride ) {
		for ( int i = 5; --i >= 0; offset += stride )
			if ( !marked(offset) )
				return false;
		return won = true;
	}
	// bool has_won { return won; }	// can just read it
	bool check ( int offset ) {
		int column = offset % 5;
		return check_( offset - column, 1 ) || check_( column, 5 );
	}
	bool mark_and_check ( int offset ) {
		mark (offset);
		return check (offset);
	}
	int final_score ( int last_called ) {
		int sum_unmarked = 0;
		for ( int i = 0; i < 25; ++i )
			if ( !marked(i) )
				sum_unmarked += cells[i];
		return sum_unmarked * last_called;
	}
};
ostream & operator<< (ostream &os, const Card &c ) {
	for ( int i = 5, j, k = 0; i--; ) {
		for ( j = 5; j--; )
			os << '\t' << c.cells[k++];
		os << endl;
	}
	// os << endl;
	return os;
}
struct Location { int card, offset; };

using Cards = vector< Card >;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Numbers numbers;
	Cards cards;

// read list of numbers
	{
		string s; cin >> s; stringstream ss ( move (s) ); int i;
		do { ss >> i; numbers.push_back(i); } while ( ss.peek() == ',' && ss.get() );
	}

// read cards
	cin >> ws;
	while (cin) {
		cards.push_back( Card {} );
		for ( auto &cell : cards.back().cells )
			cin >> cell;
		cin >> ws;
		cin.peek();	// needed to detect EOF, it seems, *despite* the >> ws above *grrrr*
	}

// construct a helpful hash
	map< int, vector<Location> > locations;
	for ( int i = 0; i < cards.size(); ++i ) {
		Card &card = cards[i];
		for ( int j = 0; j < 25; ++j )
			locations[ card.cells[j] ].emplace_back( i, j );
	}

// NOW, loop over the numbers, check each card for full row or column
	vector< pair< int, int > > winners;
	for ( auto i : numbers ) {
		auto &matches = locations[i];
		for ( auto &location : matches ) {
			auto &card = cards[ location.card ];
			if ( !card.won && card.mark_and_check( location.offset ) )
				winners.emplace_back( location.card, card.final_score(i) );
		}
		if ( winners.size() == cards.size() ) {
			break;
		}
	}

	auto const w = winners.back();
	cout << "Losing card " << w.first << ", total " << w.second << endl;
	return EXIT_SUCCESS;
}

