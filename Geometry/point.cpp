
/// Written from CP3

struct point
{

        /// change to int/long long if needed
        double x, y;

        /// default Constructor
        point() { x = y = 0.0; }

        point(double _x, double _y)
        {
                x = _x;
                y = _y;
        }

        /// sort by x co-ordinate then y co-ordinate

        bool operator < (point other) const
        {
                if (abs(x - other.x) > eps)
                        return x < other.x;
                return y < other.y;
        }


        /// to check if two points are equal
        bool operator == (point other) const
        {
                return ( ( abs(x - other.x) < eps) &&  (abs(y - other.y) < eps) );
        }
};

/// convert degree to radian
double DEG_to_RAD(double theta)
{
        return theta * pi / 180.0;
}


/// returns Euclidean distance between 2 points
double dist(point p1, point p2)
{
        // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
        return hypot(p1.x - p2.x, p1.y - p2.y);
}

/// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r)
{
        return cross(toVec(p, q), toVec(p, r)) > 0;
}


/// rotate point p by theta degrees counter clockwise w.r.t point c
point rotate_point(point c,double angle,point p)
{
	angle *= pi / 180.0;
	double s = sin(angle);
	double ccc = cos(angle);

	// translate point back to origin:
	p.x -= c.x;
	p.y -= c.y;

	// rotate point
	double xnew = p.x * ccc - p.y * s;
	double ynew = p.x * s + p.y * ccc;

	// translate point back:
	p.x = xnew + c.x;
	p.y = ynew + c.y;
	return p;
}


int main()
{

        point p1(0,0) , p2(0,0) , p3(0,1);

        cout << (p1==p2) << endl;
        cout << (p1==p3) << endl;
        return 0;
}


