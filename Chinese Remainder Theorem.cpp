/*
Let we need to find L % m
where m = p1 * p2 * ...... * pn

let,
L % p1 = r1
L % p2 = r2
.
.
.
L % p2 = rn


now L % m = ( z1 * r1 * y1 + z2 * r2 * y2 + ...... + zn * rn * yn) % m

Here zi = m / pi;
and yi = modinverse(z,pi)       // the mod is pi

#why this is working?

first of all we need to make sure every p[i] is pairwise co prime with any other p[i]
now by deviding m with p[i] , the result is sure co prime with p[i] , so we can calculate the y[i]



# when m = p1^e1 * p2^e2 *.. * pn^en , what will be the approach?

same thing. just consider pi^ei as pi.
*/



i64 p[15] , r[15];

int main()
{

        int t , n  , cs = 1;

        sf(t);

        while(t--)
        {
                sf(n);
                i64 m = 1;
                For(i,n)
                {
                        sff(p[i],r[i]);
                        m *= p[i];
                }

                i64 l = 0;


                For(i,n)
                {
                        i64 yi = modinverse(m/p[i],p[i]) ;

                        l += (m/p[i]) * r[i] * yi;
                }

                CASE(cs++);
                pfn(l % m);
        }
        return 0;
}

