struct circle
{
        pair<double,double> c;
        double r;

        circle(){}
        circle(double x,double y,double rr)
        {
                r = rr;
                c = mp(x,y);
        }
};

double commonAreaCircle(circle a, circle b)
{
        double d = sqrt( sqr(a.c.ff - b.c.ff) + sqr(a.c.ss - b.c.ss ) );

        if(d >= a.r+b.r)                        // circles don't intersect
                return 0;
        else if(d<=abs(a.r-b.r))                // one circle inside another circle
                return pi * sqr(min(a.r,b.r));

        // sector1 + sector2 - triangle1 - triangle 2
        double y = a.r*a.r - b.r*b.r + d*d;
        y /= 2*d;

        double x = sqrt(a.r*a.r - y * y) * 2;

        return  acos(y/a.r)*a.r*a.r + acos( (d-y)/b.r) * b.r * b.r -  .5 * x * y - .5 * x * (d-y) ;
}

int main()
{

        int t , cs = 1;
        double x1,y1,r1,x2,y2,r2;

        cin >> t;
        while(t--)
        {
                cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
                CASE(cs++);
                cout << fixed << setprecision(10) << commonAreaCircle(circle(x1,y1,r1),circle(x2,y2,r2)) << endl;
        }

        return 0;
}

