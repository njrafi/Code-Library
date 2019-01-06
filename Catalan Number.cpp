/*

C(n) = (4 * (n-1) + 2 ) * C(n-1) / (n + 1)
C(n) = NcR(2 * n , n) - NcR(2 * n , n + 1 )
C(0) = 1

The first Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 
16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 
1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324


There are many applications ( refer to Wiki or PDF for more ). Some noteworthy are:

Parentheses Matching: 
Counts the number of expressions containing n pairs of parentheses which are correctly matched.

Polygon Triangulation: 
Number of different ways a convex polygon with n+2
sides can be cut into triangles by connecting vertices with straight lines.

Balanced Binary Tree: 
The number of full binary trees with n internal nodes is the 
nth Catalan number.

Rooted Binary Tree: 
Number of rooted binary tree with n nodes is Cn
Also, Cn is the number of rooted binary tree with height n.

Rooted Plane Tree:
 Number of rooted plane tree with  n + 1 nodes is Cn.

Non-Crossing Partitions: 
The number of noncrossing partitions of an n-element set is Cn
.
*/


i64 dp[500];

i64 f(int n)
{
        if(n<2)
                return 1;
        if(dp[n])
                return dp[n];

        i64 ans = ( 4 * (n-1) + 2) * f(n-1);
        ans /= n+1;

        return dp[n] =  ans;
}


int main()
{

        int n;
        while(cin >> n)
                cout << f(n) << endl;
        return 0;
}


