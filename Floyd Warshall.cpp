
#define mxn 105

int main()
{

        int n,m,a,s,h,x,y,z,t,g[mxn][mxn];
        sf(t);
        while(t--)
        {
                For(i,105)
                        For(j,105)
                                if(i==j)
                                        g[i][j] = 0;
                                else
                                        g[i][j] = INT_MAX/3;

                sff(n,m);
                while(m--)
                {
                        sfff(x,y,z);
                        /// if there is more than one edge between 2 node
                        g[x][y] = min(z,g[x][y]);  
                        g[y][x] = min(z,g[y][x]);
                }

                // main algo to find all pair shortest path
                Fre(k,1,n+1)
                        Fre(i,1,n+1)
                                Fre(j,1,n+1)
                                        g[i][j] = min(g[i][j],g[i][k]+g[k][j]);


                int ans = INT_MIN;
                sfff(s,a,h);
                Fre(i,1,n+1)
                        if(i!=a && i!=h && i!=s)
                                ans = max(ans,g[s][i] + 2*g[a][i] + g[h][i]);

                cout << ans << endl;
        }
        return 0;
}

