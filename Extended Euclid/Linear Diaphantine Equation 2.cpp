
/// Copied from Shakil Aust Github
/// Gives one x,y pair for the equation ax + by = gcd(a,b)
/// also returns the gcd

i64 x, y, d;

void extEuclid(i64 a, i64 b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		d = a;
		return;
	}
	extEuclid(b, a % b);
	x = x - (a / b) * y;
	swap(x, y);
}


/// Find number of solution for x1 <= x <= x2 and y1 <= y <= y2

i64 find_all_solutions(int a, int b, int c, i64 x1, i64 x2, i64 y1, i64 y2)
{

	extEuclid(a, b);

	if (!a && !b)
	{
		if (c)
			return 0;
		return (x2 - x1 + 1) * (i64)(y2 - y1 + 1);
	}
	else if (!a)
	{
		if (c % b)
			return 0;
		c = -c / b;
		if (y1 <= c && c <= y2)
			return (x2 - x1 + 1);
		return 0;
	}
	else if (!b)
	{
		if (c % a)
			return 0;
		c = -c / a;
		if (x1 <= c && c <= x2)
			return (y2 - y1 + 1);
		return 0;
	}
	if (c % d == 0)
	{
		//d = abs(d);
		x *= (-c / d);
		y *= (-c / d);
		b /= d;
		a /= d;
		swap(a, b); // x + ka, y - kb
		double p = (x1 - x) / (double)a, q = (x2 - x) / (double)a;
		if (p > q)
			swap(p, q);
		x1 = (i64)ceil(p);
		x2 = (i64)floor(q);

		p = (y - y1) / (double)b;
		q = (y - y2) / (double)b;
		if (p > q)
			swap(p, q);
		y1 = (i64)ceil(p);
		y2 = (i64)floor(q);

		x1 = max(x1, y1);
		x2 = min(x2, y2);
		
		return max(0LL, x2 - x1 + 1);
	}
	return 0;
}


int main()
{
	int t,cs = 1,a,b,c,x1,x2,y1,y2;
	sf(t);
	while(t--)
	{
		sfff(a,b,c);
		sff(x1,x2);
		sff(y1,y2);

        CASE(cs++);
		cout << find_all_solutions(a,b,c,x1,x2,y1,y2) << endl;
	}



	return 0;
}



