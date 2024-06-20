
#include <string>
#include <iostream>
using namespace ::std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string d; int i, position = 0, depth = 0, aim = 0;
	while ( cin >> d >> i ) {
		switch (d[0]) {
		  case 'f': position += i; depth += aim * i; break;
		  case 'u': aim -= i; break;
		  case 'd': aim += i; break;
		  default: ;
		}
	}

	cerr << "aim = " << aim << ", position = " << position << ", depth = " << depth << endl;
	cout << ( position * depth ) << endl;

	return EXIT_SUCCESS;
}

