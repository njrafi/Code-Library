/// target
int tar[3][3];
pii tarpos[18];

/// starting state
int v[3][3];

/// checking the number of inversion
/// If its even then its solvable
bool solvable()
{
	int sum = 0;
	For(i,9)
	{

		Fre(j,i+1,9)
		{
			if(tar[j/3][j%3] < tar[i/3][i%3])
			{
				if(tar[j/3][j%3])
					sum++;
			}
		}
	}

	return ((sum%2)==0);
}

int pre()
{
	pii pos[9];
	For(i,3)
		For(j,3)
			tarpos[tar[i][j]] = mp(i,j);
}

int H()
{
	int ans = 0;
	For(i,3)
		For(j,3)
		if(v[i][j])
		{
			ans += abs(tarpos[v[i][j]].ff -  i);
			ans += abs(tarpos[v[i][j]].ss -  j);
		}

	return ans;
}


int ida_d, solved;

/// If u need path
int path[200];

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,+1,0};

bool valid(int x,int y)
{
	if(x>=0 && y>=0 && x<3 && y<3)
		return 1;
	return 0;
}

int ida(int lvl,int hv,int x,int y,int pre)
{

	if(!hv)
	{
		solved = 1;

                fastWrite(lvl);

                /// For Path Printing
//		For(i,lvl)
//			cout << (char)path[i];
//		cout << endl;

		return lvl;
	}

	if(lvl + hv> ida_d)
		return lvl + hv;
	int mn = inf;
	For(i,4)
	{
		if(pre+i==3)
			continue;

//		path[lvl] = movname[i];

		int xx = x + dx[i];
		int yy = y + dy[i];

		if(!valid(xx,yy))
			continue;

		swap(v[x][y],v[xx][yy]);

		mn = min(mn, ida( lvl + 1, H(),xx,yy,i) );

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
		For(i,3)
			For(j,3)
				v[i][j] = k++;
		v[2][2] = 0;

		int x,y;
		For(i,3)
			For(j,3)
				fastRead(&tar[i][j]);


		pre();

		CASE(cs++);

		if(!solvable())
		{
			puts("impossible");
			continue;
		}
		solved = 0;
		ida_d = H();
		while(!solved)
			ida_d = ida(0,H(),2,2,10);


		if(!solved)
		{
			puts("impossible");
			continue;
		}


	}

	return 0;
}


