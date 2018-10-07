#define mxn 505

/// max x range and y range
int max_x;
int max_y;

/// Update in log(max_x)  * log(max_y)
/// Query in  log(max_x)  * log(max_y)

struct node
{
        /// For minimum,maximum ans sum
        int mn,mx,sum;
        node()
        {
                mn = inf;
                mx = -inf;
                sum = 0;
        }
        node(int val)
        {
                mx = mn = sum = val;
        }
};

node tree[4 * mxn][4 * mxn];
int grid[mxn][mxn];

/// merging node
node merge(node a,node b)
{
        a.mn = min(a.mn,b.mn);
        a.mx = max(a.mx,b.mx);
        a.sum += b.sum;

        return a;
}


/// Building col
void build_y(int nx,int stx,int enx,int ny,int sty,int eny)
{
        if(sty==eny)
        {
                if(stx==enx)
                        tree[nx][ny] = node(grid[stx][sty]);
                else
                        tree[nx][ny] = merge(tree[nx*2][ny],tree[nx*2+1][ny]);
                return;
        }

        int mid = (sty+eny)/2 , lc = 2 * ny , rc = lc + 1;

        build_y(nx,stx,enx,lc,sty,mid);
        build_y(nx,stx,enx,rc,mid+1,eny);

        tree[nx][ny] = merge(tree[nx][lc],tree[nx][rc]);

}

/// Building row seg trees
void build_x(int nx,int stx,int enx)
{
        if(stx != enx)
        {
                int mid = (stx+enx)/2 , lc = 2 * nx , rc = lc + 1;
                build_x(lc,stx,mid);
                build_x(rc,mid+1,enx);

        }
        build_y(nx,stx,enx,1,1,max_y);


}

/// Updating col seg trees
void update_y(int nx,int stx,int enx,int ny,int sty,int eny,int x,int y,int val)
{
        if(sty==eny)
        {
                if(stx==enx)
                        tree[nx][ny] = node(val);
                else
                        tree[nx][ny] = merge(tree[nx*2][ny],tree[nx*2+1][ny]);

                return;
        }

        int mid = (sty+eny)/2 , lc = 2 * ny , rc = lc + 1;

        if(y<=mid)
                update_y(nx,stx,enx,lc,sty,mid,x,y,val);
        else
                update_y(nx,stx,enx,rc,mid+1,eny,x,y,val);

        tree[nx][ny] = merge(tree[nx][lc],tree[nx][rc]);
}

/// Updating row seg trees
void update_x(int nx,int stx,int enx,int x,int y,int val)
{
        if(stx!=enx)
        {
                int mid = (stx+enx)/2 , lc = 2 * nx , rc = lc + 1;
                if(x<=mid)
                        update_x(lc,stx,mid,x,y,val);
                else
                        update_x(rc,mid+1,enx,x,y,val);
        }

        update_y(nx,stx,enx,1,1,max_y,x,y,val);
}


node query_y(int nx,int ny,int sty,int eny,int ly,int ry)
{
        if(ly>ry || eny < ly || ry < sty)
                return node();
        if(ly <= sty  && eny <= ry)
                return tree[nx][ny];

        int mid = (sty+eny)/2 , lc = 2 * ny , rc = lc + 1;

        node q1 = query_y(nx,lc,sty,mid,ly,ry);
        node q2 = query_y(nx,rc,mid+1,eny,ly,ry);


        return merge(q1,q2);
}


/// Querying from [lx,ly] to [rx,ry] rectangle
node query_x(int nx,int stx,int enx,int lx,int rx,int ly,int ry)
{
        if(lx>rx || enx < lx || rx < stx)
                return node();
        if(lx <= stx  && enx <= rx)
                return query_y(nx,1,1,max_y,ly,ry);

        int mid = (stx+enx)/2 , lc = 2 * nx , rc = lc + 1;
        node q1 = query_x(lc,stx,mid,lx,rx,ly,ry);
        node q2 = query_x(rc,mid+1,enx,lx,rx,ly,ry);

        return merge(q1,q2);
}


///Helper funtions

/// Build the tree
void build()
{
        build_x(1,1,max_x);
}

/// update grid[x][y] to val
void update(int x,int y,int val)
{
        update_x(1,1,max_x,x,y,val);
}

/// Query from [lx,ly] to [rx,ry] Rectangle
node query(int lx,int rx,int ly,int ry)
{
        return query_x(1,1,max_x,lx,rx,ly,ry);
}


int main()
{
        int t,cs = 1,q,x,y,s;
        sf(t);
        while(t--)
        {
                sff(max_x,q);
                max_y = max_x;

                Fre(i,1,max_x+1)
                        Fre(j,1,max_y+1)
                        {
                                sf(grid[i][j]);
                                update(i,j,grid[i][j]);
                        }
//                build();
                CASE(cs++);
                while(q--)
                {
                        sfff(x,y,s);

                        node gg =  query(x,x+s-1,y,y+s-1);

                        pfn(gg.mx);
                }

        }
        return 0;
}


