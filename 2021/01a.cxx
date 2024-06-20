
#include <string>
#include <iostream>
using namespace ::std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int prev, i, increases = 0;
	for ( cin >> prev; cin >> i; prev = i )
		if ( i > prev )
			++increases;
	cout << increases << endl;
	return EXIT_SUCCESS;
}

