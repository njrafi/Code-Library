


/*
Convex Hull implemention from Zubayer vai

*/

/// Change to double if needed
struct point
{
	int x, y, id;
};

inline double dist(const point &a, const point &b)
{
	return hypot((double)(a.x-b.x), (double)(a.y-b.y));
}

namespace ConvexHull
{
        int np,nc;
        // np = total number of points
        // nc = convex hull points

const int maxPoint =  100005;




point P[maxPoint], C[maxPoint], P0;

/// Triangle area from 3 points
inline i64 triArea2(const point &a, const point &b, const point &c)
{
	return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline i64 sqDist(const point &a, const point &b)
{
	return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}



inline bool comp(const point &a, const point &b)
{
	int d = triArea2(P0, a, b);
	if(d < 0)
		return false;
	if(!d && sqDist(P0, a) > sqDist(P0, b))
		return false;
	return true;
}

inline bool normal(const point &a, const point &b)
{
	return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b)
{
	return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np)
{
	sort(P, P+np, normal);
	np = unique(P, P+np, issame) - P;
}

void convexHull(int &np, int &nc)
{
	int i, j, pos = 0;
	for(i = 1; i < np; i++)
		if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
			pos = i;
	swap(P[0], P[pos]);
	P0 = P[0];
	sort(&P[1], &P[np], comp);
	for(i = 0; i < 3; i++)
		C[i] = P[i];
	for(i = j = 3; i < np; i++)
	{
		while(triArea2(C[j-2], C[j-1], P[i]) < 0)
			j--;
		C[j++] = P[i];
	}
	nc = j;
}

void compress(int &nc)
{
	int i, j, d;
	C[nc] = C[0];
	for(i=j=1; i < nc; i++)
	{
		d = triArea2(C[j-1], C[i], C[i+1]);
		if(d || (!d && C[j-1].id == C[i+1].id))
			C[j++] = C[i];
	}
	nc = j;
}


void input()
{
        scanf("%d", &np);
        For(i,np)
        {
                sff(P[i].x, P[i].y);
                P[i].id = i + 1;
        }
}


vector<point> get_hull()
{
        makeUnique(np);
        vector<point> v;


        /// handle properly
        if(np<3)
        {
                For(i,np)
                        v.pb(P[i]);
                return v;
        }

        convexHull(np, nc);
        compress(nc);

        For(i,nc)
                v.pb(C[i]);

        return v;
}



}
int main()
{
        int t;
	scanf("%d", &t);
	while(t--)
	{


		ConvexHull::input();
		vector<point> v = ConvexHull::get_hull();
		double perim = 0;

		if(v.sz==1)
		{
			printf("0.00\n");
			printf("%d\n", v[0].id);
		}
		else if(v.sz==2)
		{
			perim = 2.0 * dist(v[0], v[1]);
			printf("%.2f\n", perim + eps);
			printf("%d %d\n", v[0].id, v[1].id);
		}
		else
		{
                        perim = dist(v.back(),v[0]);
			For(i,v.sz-1)
				perim += dist(v[i], v[i+1]);
			printf("%.2f\n", perim + eps);
			printf("%d", v[0].id);
			Fre(i,1,v.sz)
				printf(" %d", v[i].id);
			printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}


