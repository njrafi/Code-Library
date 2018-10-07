
vector < vector<double> > co;            // contains the coeff,ans included
/// last col e constant


vector<double>  ans;

/// returns solution (0,1 or inf)
/// Ans contains the ans co-eff
int gauss()
{
        int n = (int) co.size();         // row size
        int m = (int) co[0].size() - 1;  // col size

        vector<int> where (m, -1);          // where[i] = -1 , row i zero, var i independent
        for (int col=0, row=0; col<m && row<n; ++col)
        {
                int sel = row;
                Fre(i,row,n)
                        if (abs (co[i][col]) > abs (co[sel][col]))
                                sel = i;
                if (abs (co[sel][col]) < eps)
                        continue;
                Fre(i,col,m+1)
                        swap (co[sel][i], co[row][i]);
                where[col] = row;

                For(i,n)
                        if (i != row)
                        {
                                double c = co[i][col] / co[row][col];
                                        Fre(j,col,m+1)
                                                co[i][j] -= co[row][j] * c;
                        }
                row++;
        }

        ans.assign (m, 0);
        For(i,m)
                if (where[i] != -1)
                        ans[i] = co[where[i]][m] / co[where[i]][i];


        /// checking
        For(i,n)
        {
                double sum = 0;
                For(j,m)
                    sum += ans[j] * co[i][j];
                if (abs (sum - co[i][m]) > eps)
                    return 0;
        }

        For(i,m)
                if (where[i] == -1)
                        return inf;
        return 1;
}


map<pii,int> id;

bool vis[400][400];
int now;


/// marking all the states in a map (id)
void f(int a,int b)
{
        if(vis[a][b])
                return;
         vis[a][b] = 1;


        id[mp(a,b)] = now++;
        if(!a && !b)
                return;
        int mn = min(a,b);
        f(a+mn,b-mn);
        f(a-mn,b+mn);
}


/// Making the equations
double calc1(int a,int b)
{
        co.clr;
        foreach(i,id)
        {
                vector<double> tem;
                For(j,now+1)
                        tem.pb(0);

                int a = (i->ff).ff;
                int b = (i->ff).ss;

                tem[id[mp(a,b)]] = 1;
                int mn = min(a,b);
                if(!a )
                {
                }
                else if(!b)
                        tem.back() = 1;
                else
                {
                        tem[id[mp(a+mn,b-mn)]] = -0.5;
                        tem[id[mp(a-mn,b+mn)]] = -0.5;

                }

                co.pb(tem);
        }


        gauss() ;

        return ans[id[mp(a,b)]];
}

/// Making the equations
double calc(int a,int b)
{
        co.clr;
        foreach(i,id)
        {
                vector<double> tem;
                For(j,now+1)
                        tem.pb(0);

                int a = (i->ff).ff;
                int b = (i->ff).ss;

                tem[id[mp(a,b)]] = 1;
                int mn = min(a,b);

                if(a && b)
                {
                        tem[id[mp(a+mn,b-mn)]] = -0.5;
                        tem[id[mp(a-mn,b+mn)]] = -0.5;
                        tem.back() = 1;
                }

                co.pb(tem);
        }

        gauss();

        return ans[id[mp(a,b)]];
}

int main()
{

        int t,a,b,cs = 1;
        sf(t);

        while(t--)
        {
                sff(a,b);

                id.clr;
                mem(vis,0);
                now = 0;

                f(a,b);


                CASE(cs++);
                cout << fixed << setprecision(6) << calc(a,b) << " " << calc1(a,b) << endl;
        }

        return 0;
}


