


#define mxn 2000006

/// Z array stores length of the longest substring starting from i which is also a prefix of S

int z[mxn];

char a[mxn],b[mxn],s[mxn];

void calc()
{
        mem(z,0);
        int l=0,r=0;
        int len = strlen(s);
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


/// number of occurence of b in a
int f()
{
        int len = strlen(b);
        strcpy(s,b);
        strcat(s,"$");
        strcat(s,a);;
        int slen = strlen(s);
  
        calc();

        int ans = 0;
        For(i,slen)
                if(z[i]==len)
                        ans++;
        return ans;
}


int main()
{

        int t,cs = 1;
        sf(t);

        while(t--)
        {
                scanf("%s %s",a,b);
                CASE(cs++);
                pfn(f());
        }

        return 0;
}

