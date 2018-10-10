
/// for class is same
struct cplex
{

        int a,b;
        cplex()
        {
                a = b = 0;
        }
        cplex(int aa,int bb)
        {
                a = aa;
                b = bb;
        }
        cplex operator + (cplex const &gg) const
        {
                return cplex(a + gg.a,b + gg.b);
        }

};

/// equiv to the prev one
cplex operator + (cplex const& v1,cplex const& v2)
{
	cplex v;
	v.a = v1.a + v2.a;
	v.b = v1.b + v2.b;
	return v;
}

/// Overloading for output
ostream& operator << (ostream& os,cplex const &gg)
{
        os << gg.a << "+i" << gg.b;
        return os;
}

int main()
{
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        cplex gg1 = cplex(a,b);
        cplex gg2 = cplex(c,d);
        cplex gg = gg1 + gg2;
        cout << gg << endl;
        cout << gg1 << " " << gg2 << " " << gg1 + gg2 << endl;

        return 0;
}


