
i64 dp[805][8005];
vector<i64> cum;
vi v;



/// for the row i we know that the jlth to jrth coloumn ans should be between the klth and krth col of the previous(or next) row
/// we select a mid point and compute dp[i][mid] in o(n)
/// then we know jl to mid-1 col result should be from kl to kBest
/// and mid+1 to jr col result should be from kBest to kr

void computeDp(int i,int jl,int jr,int kl,int kr)
{

        if(jl>jr)
                return;

        int mid = (jl+jr)/2;
        int kBest = kr;

        i64 ans = infll ;

        Fre(k, max(kl,mid+1) , kr+1)
        {

                i64 gg = dp[i-1][k] + ( cum[k] - cum[mid]) * (k-mid)  ;


                if(gg  < ans)
                {
                        ans = gg;
                        kBest = k;
                }
        }

        dp[i][mid] = ans;

        computeDp(i,jl,mid-1,kl,kBest);
        computeDp(i,mid+1,jr,kBest,kr);
}

int main()
{

        int l,g,inp;
        cum.pb(0);

        sff(l,g);
        if(g>l)
                g = l;

        For(i,l)
        {
                sf(inp);
                cum.pb(cum.back() + inp);
                v.pb(inp);
        }


        For(j,v.sz)
                dp[0][j] = infll;

        Fre(i,1,g+1)
                computeDp(i,0,v.sz,0,v.sz);



        cout << dp[g][0] << endl;

        return 0;
}


