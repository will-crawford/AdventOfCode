
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace ::std;

#define D(e) cerr << e << endl
#define E(e) #e << " = " << (e)
#define COMMA << ", "

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int samples = 0, length = 0;
	string number;
	vector<int> bits ( 0, 0 );
	while ( cin >> number ) {
		// D( E(number) );
		int l = number.length();
		if ( l > length )
			bits.resize( length = l );
		reverse(begin(number), end(number));
		for ( int i = 0; i < l ; ++i )
			if ( number[i] & 1 )
				++bits[i];
		++samples;
	}
	D( E(samples) );
	for ( int i = 0; i < length; ++i ) D( E(bits[i]) );
	int threshold = ( samples + 1 ) / 2, gamma = 0, epsilon = 0;	// or something
	for ( int i = 0, bit = 1; i < length; ++i, bit += bit )
		if ( bits[i] >= threshold )
			gamma |= bit;
		else
			epsilon |= bit;

	// D( E(samples) COMMA E(length) COMMA E(epsilon) COMMA E(gamma) );
	cout << ( long(epsilon) * gamma ) << endl;

	return EXIT_SUCCESS;
}

