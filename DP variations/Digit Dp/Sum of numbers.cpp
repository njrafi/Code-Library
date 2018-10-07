

/*
Lets say we have to calculate the sum of numbers with certain properties in a range

Its easy to get the count of numbers

now how to get the sum from the count of numbers

Lets say in a state after placing a digit "d" ,we get count of numbers "cnt"

It means there will be "cnt" numbers where this particular digit in particular position

so we can just add the value "cnt" times

added value = ( d * base^idx) * cnt

*/


#define vecSize 32


vi vlo,vhi,vid;



void print(vi v)
{
        For(i,v.sz)
                cout << v[i] << " ";
        cout << endl;
}

void conv(int lo,int hi,int id)
{
        vlo.clr;
        vhi.clr;
        vid.clr;



        while(hi)
        {
                vhi.pb( hi % 2);
                hi /= 2;
        }

        while(vhi.sz!=vecSize)
                vhi.pb(0);

        reverse(all(vhi));


        while(lo)
        {
                vlo.pb( lo % 2 );
                lo /= 2;
        }

        while(vlo.sz!=vecSize)
                vlo.pb(0);

        reverse(all(vlo));


        while(id)
        {
                vid.pb( id % 2);
                id /= 2;
        }

        while(vid.sz!=vecSize)
                vid.pb(0);

        reverse(all(vid));

//        print(vhi);
//        print(vlo);
//        print(vid);
}


int Maxone , k;
pair<i64,int> dp[33][2][33][33][3][7];

/// Sum,number
pair<i64,int> f(int pos,bool eqlo,bool eqhi,int oneCnt,int miss,int div3,int div7)
{
        if(oneCnt>Maxone || miss>k)
                return mp(0,0);
        if(pos==vhi.sz)
        {

                if(!div3 && div7)
                        return mp(0,1);
                return mp(0,0);
        }
        if(!eqhi && dp[pos][eqlo][oneCnt][miss][div3][div7].ff!=-1)
                return dp[pos][eqlo][oneCnt][miss][div3][div7];

        int lo = 0 , hi = 1;

        if(eqlo)
                lo = vlo[pos];
        if(eqhi)
                hi = vhi[pos];

        pair<i64,int> ans = mp(0,0);

        Fre(i,lo,hi+1)
        {

                int ndiv3 = ( div3 * 2 + i) % 3;
                int ndiv7 = ( div7 * 2 + i) % 7;

                pair<i64,int> tem = f(pos+1, eqlo && (i==vlo[pos]) , eqhi && (i==vhi[pos]), oneCnt + (i==1), miss + (i!=vid[pos]), ndiv3, ndiv7 );

                int idx = vecSize - pos - 1;


                /// Adding the value this digit will contribute
                ans.ff += 1LL * (i * (1<<idx)) * tem.ss + tem.ff;

                ans.ss += tem.ss;

        }
        if(!eqhi)
                dp[pos][eqlo][oneCnt][miss][div3][div7] = ans;

        return ans;
}

int main()
{

        int t,cs = 1, lo , hi , id;

        sf(t);

        while(t--)
        {
                sfff(lo,hi,Maxone);
                sff(id,k);

                conv(lo,hi,id);
                mem(dp,-1);
                pair<i64,int> ans = f(0,1,1,0,0,0,0);

                CASE(cs++);
                printf("%lld\n",ans.ff);
//                cout << ans.ff << " " << ans.ss << endl;
        }













        return 0;
}


