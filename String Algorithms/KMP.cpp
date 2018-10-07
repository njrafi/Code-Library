
#define MAX 100005

int f[MAX];

void kmp_pre(string s)
{
    int j = 0;
    For(i,1,s.sz)
    {
        if(s[i]==s[j])
            f[i]=j+1,j++;
        else
        {
            while(j!=0)
            {
                j = f[j-1];
                if(s[i]==s[j])
                {
                    f[i] = j+1;
                    j++;
                    break;
                }
            }
        }
    }
}

int kmp(string text, string pattern)
{
    int cnt = 0;
    int j = 0;
    For(i,text.sz)
    {
        if(text[i]==pattern[j])
        {
            if(j==pattern.sz-1)
            {
                cnt++;
                j = f[j];
                continue;
            }
            j++;
        }
        else
        {
            while(j!=0)
            {
                j = f[j-1];
                if(text[i]==pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return cnt;
}


int main()
{
    int t;
    cin >> t;
    string st;
    Rep(tc,1,t)
    {
        getline(cin,st);
        string s1,s2;
        getline(cin,s1);
        string S;
        For(i,s1.sz)
        {
            if(s1[i]!=' ')
                S+=s1[i];
        }
        cin >> s2;
        mem(f,0);
        kmp_pre(s2);

        //For(i,s2.sz)
            //dbg(f[i]);
        CASE(tc);
        cout << kmp(S,s2) << endl;
    }

    return 0;
}
