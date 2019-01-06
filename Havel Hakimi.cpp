
/// Given input degrees of the nodes of a graph
/// no loop and multiedge
/// returns true if its possible to construct the graph


bool f(vi v)
{
        int odd = 0;
        pri p;

        For(i,v.sz)
        {
                p.push(v[i]);
                // degree can't be less than zero or greater than one
                if(v[i]<0 || v[i]>=v.sz)
                        return 0;

                odd += v[i] % 2 ;
        }

        // from handshaking theory graph can't have odd vertices of odd degrees
        if(odd%2)
                return 0;

        while(!p.empty())
        {
                int k = p.top();
                p.pop();

                v.clr;

                For(i,k)
                {
                        v.pb(p.top()-1);
                        if(v.back()<0)
                                return 0;
                        p.pop();
                }

                For(i,v.sz)
                        p.push(v[i]);
        }

        return 1;
}


int main()
{

        int n,inp;

        while(sf(n)!=EOF)
        {
                vi v;;



                while(n--)
                {
                        sf(inp);
                        v.pb(inp);
                }


                if(f(v))
                        puts("1");
                else
                        puts("0");
        }


        return 0;
}


