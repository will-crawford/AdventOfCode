
#include <string>
#include <iostream>
using namespace ::std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string d; int i, position = 0, depth = 0;
	while ( cin >> d >> i ) {
		switch (d[0]) {
		  case 'f': position += i; break;
		  case 'u': depth -= i; break;
		  case 'd': depth += i; break;
		  default:
			cerr << "Unexpected character '" << d[0] << "'" << endl;
			return EXIT_FAILURE;
			;
		}
	}

	cerr << "position = " << position << ", depth = " << depth << endl;
	cout << ( position * depth ) << endl;

	return EXIT_SUCCESS;
}

