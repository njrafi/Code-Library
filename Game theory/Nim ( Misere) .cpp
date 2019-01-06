
int main()
{

      
        int t,m,n,c=1,inp;
        sf(t);

        while(t--)
        {
                sf(n);
                i64 ans = 0;
                bool ok = 0;
                For(i,n)
                {

                        sf(inp);
                        ans ^= inp;
                        if(inp>1)
                                ok = 1;
                }
                CASE(c++);

                if(!ok)
                {
                        if(n%2)
                                cout << "Bob";
                        else
                                cout << "Alice";
                }
                else
                {
                        if(ans)
                                cout << "Alice";
                        else
                                cout << "Bob";
                }
                cout << endl;
        }

        return 0;
}

