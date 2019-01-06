// By bruteforce this problem can be solved in O(3^18) by generating all subset sum of all elements
// But what we did is divide the elements in two different set and generated their subset sum in O(3^9+3^9)
// and then looped in one set and binary search in other set in O(3^9 x log2(3^9))
// So by this technique we changed the complexity from O(3^18) to O(3^9 x log2(3^9))


int inde[20],k;
vi v,w,sum1,sum2;

void call1(int st)
{
        if(st==v.sz)
        {
                int tem = 0;
                For(i,v.sz)
                        tem += v[i] * inde[i] ;
                if(tem<=k)
                        sum1.pb(tem);

                return;
        }
        For(j,3)
        {
                inde[st] = j;
                call1(st+1);
        }

}


void call2(int st)
{
        if(st==w.sz)
        {
                int tem = 0;
                For(i,w.sz)
                        tem += w[i] * inde[i] ;
                if(tem<=k)
                        sum2.pb(tem);

                return;

        }


        For(j,3)
        {
                inde[st] = j;
                call2(st+1);
        }
}

int main()
{

        int n,inp,t,cs = 1;
        sf(t);

        while(t--)
        {
                v.clr;
                w.clr;
                sum1.clr;
                sum2.clr;
                sff(n,k);

                int lim = n/2;

                For(i,lim)
                {
                        sf(inp);
                        v.pb(inp);
                }

                call1(0);

                Fre(i,lim,n)
                {
                        sf(inp);
                        w.pb(inp);
                }

                call2(0);

                sort(all(sum2));
                CASE(cs++);
                bool ok = 0;
                For(i,sum1.sz)
                {
                        int tem = k - sum1[i];

                        if(!tem || binary_search(sum2.begin(),sum2.end(),tem))
                        {
                                puts("Yes");
                                ok = 1;
                                break;
                        }
                }

                if(!ok)
                        puts("No");
        }
        return 0;
}


