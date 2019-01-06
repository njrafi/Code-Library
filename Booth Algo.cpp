
/// finds the rotation of a string possessing the lowest lexicographical order of all such rotations

#define mxn 4005

char s[mxn];
int fail[mxn];
int ssz;
int booth()
{

        s += s;
        mem(fail,-1);
        int k = 0;
        Fre(j,1,ssz)
        {
                int sj = s[j];
                int i = fail[j-k-1];
                while(i!=-1 && sj!=s[k+i+1])
                {
                        if(s[j]<s[k+i+1])
                                k = j-i-1;
                        i = fail[i];
                }

                if(s[j]!=s[k+i+1])
                {
                        if(sj<s[k])
                                k = j;
                        fail[j-k] = -1;
                }
                else
                        fail[j-k] = i+1;
        }

        return k;
}

int main()
{

        int t;
        sf(t);
        int ans = 0;
        char ss[mxn];
        while(t--)
        {
                scanf("%s",ss);
                strcpy(s,ss);
                strcat(s,ss);;
                ssz = strlen(s);
                int st = booth();
                int gg = 0;
                Fre(i,st,st+15)
                        gg += s[i]-'a'+1;
                ans += gg;
        }

        cout << ans << endl;
        return 0;
}

