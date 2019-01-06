

/*
Let a number x = p1 ^ e1 * p2 ^ e2 * ..... pn ^ en
nod(x) = (e1+1) * (e2 + 1) * .... (en + 1)
sod(x) = ( (p1 ^ ( e1+1 ) - ) / (p1 - 1) ) * ... * ( (pn ^ ( en+1 ) - ) / (pn - 1) )

*/


/// Gives sod(n^m) % mod
/// Change a bit to get sod(n) or nod(n)

void sod(i64 n,i64 m)
{
        primefactor(n);

        /// fact contains (pi,ei) pair of n

        i64 ans = 1;
        For(i,fact.sz)
        {
                i64 up = fact[i].ss * m + 1;
                i64 down = fact[i].ff;
                i64 tem = (bigmod(down,up) - 1 + mod ) % mod;
                ans *= tem;
                ans %= mod;
                ans *= modinverse(fact[i].ff-1);
                ans %= mod;
        }


        fastWrite(ans);


}

