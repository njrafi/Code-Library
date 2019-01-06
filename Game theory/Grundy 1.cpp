

/// Grundy number is the mex of the child states
/// If child states have more than one node 
/// then the value for that child state is the ex-or of the states


int g[10024];

void f(int s)
{

        bool flag[10024] = {0};

        for(int i = 1; s-i > i ; i++)
                flag[ g[i] ^ g[s-i] ] = 1;

        For(i,200)
                if(!flag[i])
                {
                        g[s] = i;
                        break;
                }
}

int main()
{

       
        g[0] = g[1] = g[2] = 0;
        Fre(i,3,10003)
                f(i);
      
        int t , c = 1 , n , inp;

        sf(t);

        while(t--)
        {
                sf(n);
                i64 ans = 0;
                while(n--)
                {
                        sf(inp);
                        ans ^= g[inp];
                }
                CASE(c++);
                if(!ans)
                        puts("Bob");
                else
                        puts("Alice");
        }



        return 0;
}

