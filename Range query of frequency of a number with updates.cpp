
/// Query will give us the frequency of number x in [l,r]
/// Update will add v to all the numbers in [l,r]

#define off 200005
/// the lowest negative value

vi v;
int bSize;      /// Bucket Size
int freq[320][400015];  /// frequency of number j in bucket i
int added[400]; /// added value to the ith bucket
bool st[100005];        /// is index i start of a bucket?
int whichB[100005];     /// which bucket


void create_bucket()
{
//        mem(freq,0);
        mem(added,0);
        mem(st,0);


        For(i,v.sz)
        {

                if(i%bSize==0)
                        st[i] = 1;

                whichB[i] = i / bSize;


                freq[whichB[i]][v[i] + off]++;
        }


}


int query(int l,int r,int x)
{
        int ans = 0;
        int bench = 0;
        Fre(i,l,r+1)
        {
                if(st[i] && ( i + bSize - 1) <=r)
                {
                        int addedVal = added[whichB[i]];
                        int gg = x - addedVal + off;
                        if( 0 <= gg && gg < 400002)
                                ans += freq[whichB[i]][gg];
                        i += bSize - 1;


                }
                else
                        ans += (  ( v[i] + added[whichB[i]] )  == x );

        }

        return ans;
}

void update(int l,int r,int x)
{
        int bench = 0;
        Fre(i,l,r+1)
        {
                if(st[i] && ( i + bSize - 1) <=r)
                {
                        added[whichB[i]] += x;
                        i += bSize - 1;
                }
                else
                {
                        freq[whichB[i]][v[i] + off]--;
                        v[i] += x;
                        freq[whichB[i]][v[i] + off]++;
                }

        }

}


int main()
{
        int t,cs = 1 , n , q , op , l , r , x;
        sf(t);

        while(t--)
        {
                sff(n,q);
                v.clr;
                For(i,n)
                {
                        sf(x);
                        v.pb(x);
                }


                bSize = 800;

                create_bucket();

                CASE(cs++);
                while(q--)
                {
                        sf(op);
                        sfff(l,r,x);
                        l--;
                        r--;

                        if(op==2)
                                pfn(query(l,r,x));
                        else
                                update(l,r,x);
                }

                For(i,v.sz)
                        freq[whichB[i]][v[i] + off]--;
        }














        return 0;
}


