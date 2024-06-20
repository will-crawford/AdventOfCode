
#include <string>
#include <iostream>
using namespace ::std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int prev[3], i = 0, next, increases = 0;
	for ( cin >> prev[0] >> prev[1] >> prev[2]; cin >> next; prev[i++] = next, i %= 3 )
		if ( next > prev[i] )
			++increases;
	cout << increases << endl;

	return EXIT_SUCCESS;
}

