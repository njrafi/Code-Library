
i64 ten(string s,int base)
{
        i64 ans = 0;
        reverse(all(s));
        For(i,s.sz)
                if(s[i]>='0' && s[i]<='9')
                        ans += (s[i]-'0')*po(base,i);
                else
                        ans += (s[i]-'A'+10)*po(base,i);
        return ans;
}
string f(i64 num,int base)
{
        string ans ;
        int tem;
        if(!num)
                ans.pb('0');
        while(num)
        {
                tem = num % base;
                num /= base;
                if(tem<10)
                        ans.pb(tem+'0');
                else
                        ans.pb(tem-10+'A');
        }
        reverse(all(ans));
        return ans;
}

int main()
{

        int a,b;
        string s;
        while(cin >> s >> a >> b)  // s= number to convert , from base a to base b
                cout << f(ten(s,a),b) << endl;

        return 0;
}

