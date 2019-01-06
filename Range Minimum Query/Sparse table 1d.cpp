
#define mxn 2000006

int n;
int a[mxn];
int p2[30];
int table[32][mxn];



int loggg(int n)
{
        int gg = log2(n);
        gg = max(gg-2,0);
        int ans = 0;
        Fre(i,gg,gg+6)
                if(p2[i]<=n)
                        ans = i;
        return ans;
}

void pre()
{
        For(i,25)
                p2[i] = po(2,i);
}

void build()
{
        For(i,n)
                table[0][i] = a[i];

        for(int j = 1 ; p2[j] <= n ; j++)
                for(int i = 0 ; i + p2[j-1] < n ; i++)
                        table[j][i] = min(table[j-1][i] , table[j-1][i+p2[j-1]]);

}

int query(int l,int r)
{
        int len = r - l + 1;
        int k = loggg(len);
        return min(table[k][l],table[k][r+1-p2[k]]);
}

int main()
{

        int t,q,l,r , cs = 1;
        pre();
        sf(t);
        while(t--)
        {
                sff(n,q);
                For(i,n)
                        sf(a[i]);
                build();
                CASE(cs++);
                while(q--)
                {
                        sff(l,r);
                        pfn(query(l-1,r-1));
                }
        }











        return 0;
}

