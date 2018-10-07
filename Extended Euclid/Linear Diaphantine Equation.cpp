
/// Gives one x,y pair for the equation ax + by = gcd(a,b)
/// also returns the gcd

int extended_gcd(int a, int b, int &x, int &y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = extended_gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


/// Find one solution of ax + by = c in (x0,y0)
/// return 0 for no solution

bool find_any_solution(int a, int b, int c, int &x0, int &y0)
{
	int g = extended_gcd(abs(a), abs(b), x0, y0);
	if (c % g)
		return false;


	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)
		x0 = -x0;
	if (b < 0)
		y0 = -y0;
	return true;
}

/// print lim solutions
/// not tested
void print_some_solution(int a,int b,int c,int x,int y,int lim)
{
	int g = __gcd(a,b);

	For(i,lim)
	{
		cout << x + i * b / g << " ";
		cout << y - i * a / g << endl;
	}
}

int main()
{
	int a = 10, b = 17, c = 155, x, y, g;
	int lim = 50;

	/// 10x + 17y = 155

	while(1)
	{
		find_any_solution(a,b,c,x,y);
		print_some_solution(a,b,c,x,y,lim);
		cin >> a >> b >> c;
	}

	return 0;
}


