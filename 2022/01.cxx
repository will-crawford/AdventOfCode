
#include <cstdlib>
#include <iostream>

int main () {
	vector<int> calories( 1, 0 );
	string line;
	int c;
	while (cin.getline(line)) {
		if (line.length())
			line >> c;
	}

	return EXIT_SUCCESS;
}

