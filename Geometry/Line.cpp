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


/// returns Euclidean distance between 2 points
double dist(point p1, point p2)
{
        // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
        return hypot(p1.x - p2.x, p1.y - p2.y);
}


struct line {
        double a, b, c;

        line(){}
        line(double aa,double bb,double cc)
        {
                a = aa;
                b = bb;
                c = cc;
        }
};



/// given two point p1 and p2 output the line equation
line pointsToLine(point p1, point p2)
{
        line l;
        if (abs(p1.x - p2.x) < eps) // vertical line is fine
        {
                l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
        }
        else
        {
                l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
                l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
                l.c = -(double)(l.a * p1.x) - p1.y;
        }


        return l;
}


/// check if two lines are parallel
bool areParallel(line l1, line l2)      // check coefficients a & b
{
        return (abs(l1.a-l2.a) < eps) && (abs(l1.b-l2.b) < eps);
}

/// check if two lines are same
bool areSame(line l1, line l2)          // also check coefficient c
{
        return areParallel(l1 ,l2) && ( abs(l1.c - l2.c) < eps);
}

/// returns true (+ intersection point) if two lines intersect
/// Pass the point to hold the intersection point
bool areIntersect(line l1, line l2, point &p)
{
        if (areParallel(l1, l2)) return false; // no intersection
        // solve system of 2 linear algebraic equations with 2 unknowns
        p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
        // special case: test for vertical line to avoid division by zero
        if (abs(l1.b) > eps) p.y = -(l1.a * p.x + l1.c);
        else p.y = -(l2.a * p.x + l2.c);
        return true;
}


/// vector
struct vec
{       double x, y; // name: ‘vec’ is different from STL vector
        vec(double _x, double _y) : x(_x), y(_y) {}
};


/// convert 2 points to vector a->b
vec toVec(point a, point b)
{
        return vec(b.x - a.x, b.y - a.y);
}


vec scale(vec v, double s) // nonnegative s = [<1 .. 1 .. >1]
{
        return vec(v.x * s, v.y * s);
} // shorter.same.longer


/// translate p according to v
point translate(point p, vec v)
{
        return point(p.x + v.x , p.y + v.y);
}

/// dot product of 2 vector
double dot(vec a, vec b)
{
        return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v)
{
        return v.x * v.x + v.y * v.y;


}


/// returns the distance from p to the line defined by
/// two points a and b (a and b must be different)
/// the closest point is stored in the 4th parameter (byref)

double distToLine(point p, point a, point b, point &c)
{
        // formula: c = a + u * ab
        vec ap = toVec(a, p), ab = toVec(a, b);
        double u = dot(ap, ab) / norm_sq(ab);
        c = translate(a, scale(ab, u)); // translate a to c
        return dist(p, c);  // Euclidean distance between p and c
}


///  returns angle aob in rad
double angle(point a, point o, point b)
{
        vec oa = toVec(o, a), ob = toVec(o, b);
        return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

/// returns cross product of 2 vectors
double cross(vec a, vec b)
{
        return a.x * b.y - a.y * b.x;
}


/// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r)
{
        return cross(toVec(p, q), toVec(p, r)) > 0;
}

/// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r)
{
        return abs(cross(toVec(p, q), toVec(p, r))) < eps;
}

/// returns if point p is on line l
bool pointOnLine(point p,line l)
{
        double tot = l.a * p.x + l.b *p.y + l.c;
        if(abs(tot)<eps)
                return 1;
        return 0;
}

