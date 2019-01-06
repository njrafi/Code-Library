
vs v;
pii ml[22][22],mr[22][22];
bool vis[22][22];



bool valid(int x,int y)
{
        if(x>=0 && x<v.sz && y>=0 && y<v[0].sz && v[x][y]=='*')
                return 1;
        return 0;
}

bool findmatch(int x,int y)
{
        vis[x][y] = 1;

        For(i,4)
        {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if(!valid(xx,yy))
                        continue;

                pii k = mr[xx][yy];


                if(mr[xx][yy].ff==-1 || (!vis[k.ff][k.ss] && findmatch(k.ff,k.ss)))
                {

                        ml[x][y] = mp(xx,yy);
                        mr[xx][yy] = mp(x,y);
                        return 1;
                }

        }

        return 0;
}


int bpm()
{
        int ans = 0;
        mem(ml,-1);
        mem(mr,-1);

        for(int i = 0; i < (int)v.sz ; i+=2)
                for(int j = 0; j < (int)v[0].sz ; j += 2)
                {
                        mem(vis,0);

                        if(v[i][j]=='*' && ml[i][j].ff==-1 && findmatch(i,j))
                                ans++;
                }


        for(int i = 1; i < (int)v.sz ; i+=2)
                for(int j = 1; j < (int)v[0].sz ; j += 2)
                {
                        mem(vis,0);

                        if(v[i][j]=='*' && ml[i][j].ff==-1 && findmatch(i,j))
                                ans++;
                }


        return ans;
}



int main()
{

        string s;
        int t , cs =  1 ;
        int n,m;
        sf(t);

        while(t--)
        {
                v.clr;
                sff(n,m);

                int gold = 0;
                while(n--)
                {
                        cin >> s;
                        For(i,s.sz)
                                if(s[i]=='*')
                                        gold++;
                        v.pb(s);
                }


                CASE(cs++);

                pfn(gold-bpm() );
        }

        return 0;
}

