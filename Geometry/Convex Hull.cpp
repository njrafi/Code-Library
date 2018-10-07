/// Note tested


struct point
{
    long long x, y; /// x*x or y*y should fit long long because of cross() function

    point() {}
    point(long long a, long long b)
    {
        x = a, y = b;
    }

    inline bool operator < (const point &p) const
    {
        return ((x < p.x) || (x == p.x && y < p.y));
    }
};


/// returns Euclidean distance between 2 points
double dist(point p1, point p2)
{
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

long long cross(const point &O, const point &A, const point &B)
{
    return ((A.x - O.x) * (B.y - O.y)) - ((A.y - O.y) * (B.x - O.x));
}


/// Polygon P convex or not, P is given in clock-wise of anti-clockwise order
bool isConvex(vector <point> P)
{
    int n = P.size();
    ///sort(P.begin(), P.end());
    if (n <= 2)
        return false; /// Line or point is not convex

    n++, P.push_back(P[0]); /// Last point = first point
    bool flag = (cross(P[0], P[1], P[2]) > 0);
    for (int i = 1; (i + 1) < n; i++)
    {
        bool cmp = (cross(P[i], P[i + 1], (i + 2) == n ? P[1] : P[i + 2]) > 0);
        if (cmp ^ flag)
            return false;
    }

    return true;
}

/// Convex hull using the monotone chain algorithm
vector <point> convex_hull (vector<point> P)
{
    int i, t, k = 0, n = P.size();
    vector<point> H(n << 1);
    sort(P.begin(), P.end()); /// Can be converted to O(n) using radix sort

    for (i = 0; i < n; i++)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    for (i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }

    H.resize(k - 1);

    /// Comment out this if the last point should be same as first point
    //H.push_back(H[0]);

    return H;
}

/// returns the perimeter, which is the sum of Euclidian distances
/// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P)
{
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++) // remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
    return result;
}



/// returns the area, which is half the determinant
double area(vector<point> &P)
{
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++)
    {
        x1 = P[i].x;
        x2 = P[i+1].x;
        y1 = P[i].y;
        y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return abs(result) / 2.0;
}

int main()
{

}
