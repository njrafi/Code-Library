
/*
Number of ways to place
N chess queens on an N×N chessboard 
so that no two queens attack each other
*/


int a[20][20];
int n;
vpi v;

void print()
{
        mem(a,0);
        For(i,v.sz)
                a[v[i].ff][v[i].ss] = 1;

        For(i,n)
                For(j,n)
                {
                        if(a[i][j])
                                printf("Q");
                        else
                                printf("-");
                        if(j==n-1)
                                puts("");
                        else
                                printf(" ");
                }
        puts("");
}


bool valid(int x,int y)
{
        For(i,v.sz)
                if(v[i].ff==x || abs(v[i].ff-x)==abs(v[i].ss-y))
                        return 0;
        return 1;
}

void f(int pos)
{
        if(v.sz==n)
        {
                print();
                return;
        }


        For(i,n)
                if(valid(i,pos))
                {
                        v.pb(mp(i,pos));
                        f(pos+1);
                        v.pop_back();
                }
}


int main()
{


        while(cin >> n)
                f(0);

        return 0;
}

