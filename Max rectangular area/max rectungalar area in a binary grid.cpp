

/// given a binary grid gives max rectangular area of one

i64 getMaxAreaGrid(vector<string> grid)
{

        vector<i64> v;
        For(i,grid[0].sz)
                v.pb(grid[0][i] - '0');
        i64 mx = getMaxArea(v);

        Fre(i,1,grid.sz)
        {


                For(j,grid[i].sz)
                        if(grid[i][j]=='1')
                                v[j]++;
                        else
                                v[j] = 0;

                mx = max(mx,getMaxArea(v));
        }

        return mx;

}


int main()
{
        int t,cs = 1,n,inp,m;

        char ss[2002];
        sf(t);
        while(t--)
        {
                sff(n,m);
                vector<string> v;
                while(n--)
                {
                        scanf("%s",ss);
                        string s;
                        For(i,m)
                                s += '1' - ss[i] + '0';
                        v.pb(s);
                }

                CASE(cs++);
                cout << getMaxAreaGrid(v) << endl;
        }
        return 0;
}

