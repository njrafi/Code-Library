
#define ld long double
ld PI = acos(-1);

struct cplx
{
	ld a, b;

	cplx(ld a = 0, ld b = 0) : a(a), b(b) {}

	const cplx operator + (const cplx &c) const
		{ return cplx(a + c.a, b + c.b); }

	const cplx operator - (const cplx &c) const
		{ return cplx(a - c.a, b - c.b); }

	const cplx operator * (const cplx &c) const
		{ return cplx(a * c.a - b * c.b, a * c.b + b * c.a); }
};



typedef vector<cplx> vc;

void fft(vc &p, bool inv = 0) {
	int n = p.size(), i = 0;
	for(int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
		if(j < i) swap(p[i], p[j]);
	}
	for(int m = 2; m <= n; m <<= 1) {
		int mh = m >> 1;
		cplx wn = cplx(cos(2 * PI / m), sin(2 * PI / m));
		if(inv) wn = cplx(cos(2 * PI / m), -sin(2 * PI / m));
		for(int j = 0; j < n; j += m) {
			cplx w(1, 0);
			for(int k = 0; k < mh; ++k) {
				int pos = j + k;
				cplx t = w * p[pos + mh];
				p[pos + mh] = p[pos] - t;
				p[pos] = p[pos] + t;
				w = w * wn;
			}
		}
	} if(inv) for(int i = 0; i < n; i++) p[i].a /= n, p[i].b /= n;
}


/// let (1 + 2x + 3x^2) * (3 + 2x + x^2) = (3 + 8x + 14x^2 + 8x^3 + 3x^4)
/// we input (1,2,3) and (3,2,1) and get (3,8,14,6,3)

vector<i64> multiply(vector<int> &a, vector<int> &b) {
	int n = a.size(), m = b.size(), t = n + m - 1, SZ = 1;
	while(SZ < t) SZ <<= 1;
	vc x(SZ), y(SZ), z(SZ);
	for(int i = 0 ; i < SZ; ++i) {
		x[i] = i < a.size() ? cplx(a[i], 0) : cplx(0, 0);
		y[i] = i < b.size() ? cplx(b[i], 0) : cplx(0, 0);
	} fft(x), fft(y);
	for(int i = 0; i < SZ; ++i) z[i] = x[i] * y[i];
	fft(z, 1);
	vector<i64> ret(t + 1);
	for(int i = 0; i <= t; ++i) ret[i] = z[i].a + 0.5;
	return ret;
}

int main() {
    vector<int> a = {1, 2, 3}, b = {3, 2, 1};
    vector<i64> x = multiply(a,b);
    for(int i=0; i<x.size(); i++) cout << x[i] << ' ' ; cout << endl;
}
