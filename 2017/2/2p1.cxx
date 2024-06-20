
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

int Sheet::checksum () {
	int total = 0;
	for ( auto &row : rows ) {
		auto mm = minmax_element( begin(row), end(row) );
		total += *mm.second - *mm.first;
	}
	return total;
}

int main (int, const char **) {
	Sheet sheet; cin >> sheet;
	cout << sheet.checksum() << endl;
	return EXIT_SUCCESS;
}

