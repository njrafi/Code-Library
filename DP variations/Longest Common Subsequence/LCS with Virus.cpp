

///  first two sequence , 3rd one virus
///  We have to find lcs of s1 and s2 
/// and it can't contais virus(s3) as substring

string s1,s2,s3;        
int z[2000006];

string s;

void calc()
{
        mem(z,0);
        int l=0,r=0;
        int len = s.sz;
        Fre(i,1,len)
        {
                if(i>r)
                {
                        l = r = i;
                        while(r<len && s[r]==s[r-l])
                                r++;
                        z[i] = r-l;
                        r--;
                }
                else
                {
                        if(z[i-l]<r-i+1)
                                z[i] = z[i-l];
                        else
                        {
                                l = i;
                                while(r<len && s[r]==s[r-l])
                                        r++;
                                z[i] = r-l;
                                r--;
                        }
                }
        }
}

void zf()
{

        s = s3 + '$' + s3;
        calc();
        For(i,s3.sz)
                z[i] = z[i+s3.sz+1];



}
struct info
{
        int l,r,idx;
};

int dp[105][105][105];
info dir[105][105][105];

int f(int l,int r,int idx)
{
//        cout << l << " " << r << " " << idx << endl;
        if(idx==s3.sz)
                return -inf;
        if(l==s1.sz || r==s2.sz)
                return 0;
        if(dp[l][r][idx]!=-1)
                return dp[l][r][idx];

        int ans = 0;
        if(s1[l]==s2[r])
        {

                int mx = 0;

                For(i,idx+1)
                        if(z[i]+i>=idx && s1[l]==s3[idx-i])
                                mx = max(mx,idx - i + 1);
                dir[l][r][idx] = {l+1,r+1,mx};
                ans = 1 + f(l+1,r+1,mx);

        }

        int tem1 = f(l,r+1,idx);
        int tem2 = f(l+1,r,idx);

        if(tem1>=ans)
        {
                ans = tem1;
                dir[l][r][idx] = {l,r+1,idx};
        }
        if(tem2>=ans)
        {
                ans = tem2;
                dir[l][r][idx] = {l+1,r,idx};
        }

        return dp[l][r][idx] = ans;
}

string ans;
int lala;
void print(int l,int r,int idx)
{

        if(l>=s1.sz || r>=s2.sz)
                return;
        info gg = dir[l][r][idx];
        if(gg.l==l+1 && gg.r==r+1)
                ans += s1[l];

        print(gg.l,gg.r,gg.idx);
}




int main()
{

        cin >> s1 >> s2 >> s3;
//        cout << s1.sz << " " << s2.sz << " " << s3.sz << endl;

        zf();
        mem(dp,-1);
        int szz = f(0,0,0);

//        dbg(szz);
        if(!szz)
        {
                cout << 0 << endl;
                return 0;
        }
        print(0,0,0);
        cout << ans << endl;










        return 0;
}
