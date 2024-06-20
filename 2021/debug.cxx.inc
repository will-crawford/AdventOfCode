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

