
// SOS dp link: https://codeforces.com/blog/entry/45223
/*
We can iterate submasks in 3^n https://cp-algorithms.com/algebra/all-submasks.html
But if we need the sum of sumbasks we can reduce it to n * 2 ^ n
*/
// Problem link: https://toph.co/p/captain-shoaib-civil-war

#define maxbit 20

int cnt[(1 << maxbit) + 5];

int main() {
    int n,inp;
    sf(n);
    vi v;
    For(i,n) {
        sf(inp);
        v.pb(inp);
        cnt[inp]++;
    }

    n = maxbit;
    int allBitSet = (1 << n) - 1;
    for(int bit = 0; bit < n ; bit++)
        for (int mask = 0; mask < (1<<n); mask++)
            if(checkbit(mask,bit))
                cnt[mask] += cnt[mask^(1<<bit)];


    bool ok = false;
    For(i,v.sz) {
        if(cnt[allBitSet ^ v[i]]) {
                pfs(i);
                ok = true;
        }
    }
    if(!ok) cout << -1;
    cout << endl;


    return 0;
}

