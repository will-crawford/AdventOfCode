
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
// #include <string_view>
#include <vector>
#include <algorithm>
using namespace ::std;

struct Sheet {
	using row_t = vector<int>;
	vector<row_t> rows;
	void read (istream &is);
//	void write (ostream &os);
	int checksum ();
};
inline istream &operator>> (istream &is, Sheet &sheet) { sheet.read(is); return is; }

void Sheet::read (istream &is) {
	string s;
	while ( getline(is, s) ) {
		rows.emplace_back(0);
		row_t &row = rows.back();
		istringstream iss (s);
		int i;
		while ( iss >> i )
			row.push_back(i);
	}
}

// mutates the sequence, so take a copy if you need to preserve the original
int find_even_quotient ( vector<int> row ) {
	auto begin = row.begin(), end = row.end();
	if ( begin == end )
		return 0;
	sort( begin, end );
	for ( auto i = begin; ++i != end; ) {
		auto dividend = *i;
		for ( auto j = i; j != begin; ) {
			auto divisor = *--j;
			if ( ( dividend % divisor ) == 0 )
				return dividend / divisor;
		}
	}
	return 0;
}

int Sheet::checksum () {
	int total = 0;
	for ( auto &row : rows )
		total += find_even_quotient (row);
	return total;
}

int main (int, const char **) {
	Sheet sheet; cin >> sheet;
	cout << sheet.checksum() << endl;
	return EXIT_SUCCESS;
}

