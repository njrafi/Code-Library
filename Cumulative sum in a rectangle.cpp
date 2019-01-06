


/*
Cumulative sum in a rectangle in O(1)
good for problem with no update
*/

#define mxn 1005


/// The actual array
int a[mxn][mxn];
i64 cum[mxn][mxn];


int f(int x1,int y1,int x2,int y2)
{
//        x1++;
//        y1++;
//        x2++;
//        y2++;
        // if 1 based dont change anything
        // if 0 based array comment out + handle input
        return cum[x2][y2] - cum[x2][y1-1] - cum[x1-1][y2] + cum[x1-1][y1-1];
}

int main()
{

        int n,m,x1,y1,x2,y2;

        sff(n,m);

        Fre(i,1,n+1)
                Fre(j,1,m+1)
                        sf(a[i][j]);
        Fre(i,1,n+2)
                Fre(j,1,m+1)
                        cum[i][j] = cum[i][j-1] + a[i][j];

        Fre(i,1,n+2)
                Fre(j,1,m+2)
                        cum[i][j] += cum[i-1][j];

        while(1)
        {

                cin >> x1 >> y1 >> x2 >> y2;
                cout << f(x1,y1,x2,y2) << endl;
        }



        return 0;
}
