int tar[4][4];
pii tarpos[18];
int v[4][4];

bool solvable()
{
	int sum = 0, row, i, j;
	for(i = 0; i < 16; i++)
	{
		if(v[i/4][i%4] == 0)
		{
			row = i/4 + 1;
			continue;
		}
		for(j = i+1; j < 16; j++)
		{
			if(v[j/4][j%4] < v[i/4][i%4])
			{
				if(v[j/4][j%4])
					sum++;
			}
		}
	}

	/// sum in invertion count
	/// row is the row of zero
	return 1-(sum+row)%2;
}

int pre()
{
	pii pos[16];
                For(i,4)
                        For(j,4)
	tarpos[tar[i][j]] = mp(i,j);
}

int H()
{
	int ans = 0;
	For(i,4)
        For(j,4)
            if(v[i][j])
            {
                ans += abs(tarpos[v[i][j]].ff -  i);
                ans += abs(tarpos[v[i][j]].ss -  j);
            }

	return ans;
}


int ida_d, solved;
int path[200];
int movname[] = {'D','L','R','U'};

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,+1,0};

bool valid(int x,int y)
{
	if(x>=0 && y>=0 && x<4 && y<4)
		return 1;
	return 0;
}

int ida(int lvl,int hv,int x,int y,int pre)
{

	if(!hv)
	{
		solved = 1;
		For(i,lvl)
                        cout << (char)path[i];
		cout << endl;

		return lvl;
	}

	if(lvl + hv > ida_d)
		return lvl + hv;
	int mn = inf;
	For(i,4)
	{
		if(pre+i==3)
			continue;

		path[lvl] = movname[i];

		int xx = x + dx[i];
		int yy = y + dy[i];

		if(!valid(xx,yy))
			continue;

		swap(v[x][y],v[xx][yy]);

		mn = min(mn, ida( lvl + 1 , H() , xx , yy , i ) );

		swap(v[x][y],v[xx][yy]);

		if(solved)
			return mn;
	}
	return mn;
}
int main()
{


	int t,cs = 1;
	sf(t);

	while(t--)
	{
		int k = 1;
		For(i,4)
                        For(j,4)
                                tar[i][j] = k++;
                tar[3][3] = 0;

		int x,y;
		For(i,4)
            For(j,4)
            {
                    sf(v[i][j]);
                    if(!v[i][j])
                    {
                            x = i;
                            y = j;
                    }
            }

		pre();

		CASE(cs++);

		if(!solvable())
		{
			puts("This puzzle is not solvable.");
			continue;
		}
		solved = 0;
		ida_d = H();
		while(ida_d<=35)
		{

			ida_d = ida(0,H(),x,y,10);
			if(solved)
				break;
		}


		if(!solved)
		{
			puts("This puzzle is not solvable.");
			continue;
		}


	}

	return 0;
}


