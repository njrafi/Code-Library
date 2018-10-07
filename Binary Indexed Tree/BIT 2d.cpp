

#define mxn 1111
#define max_x 1111
#define max_y 1111

i64 tree[max_x][max_y];
i64 grid[max_x][max_y];                       
// present grid after updating

/// everything should be 1 indexed


///  update point at x,y to prev + val
void update(int x, int y, i64 val)
{
        int y1;
        while (x <= max_x)
        {
                y1 = y;
                while (y1 <= max_y)
                {
                        tree[x][y1] += val;
                        y1 += (y1 & -y1);
                }
                x += (x & -x);
        }
}

///  return sum from 1,1 to x,y.
i64 read(int x,int y)                           
{
        i64 sum = 0;
        while( x)
        {
                int y1 = y;
                while(y1)
                {
                        sum += tree[x][y1];
                        y1 -= y1 & -y1;
                }
                x -= x & -x;
        }
        return sum;
}

/// returns rectangle sum of bottomLeft point (r1,c1) to topRight point(r2,c2)
i64 get_sum(int r1,int c1,int r2,int c2)
{
        return read(r2,c2) - read(r2,c1-1) - read(r1-1,c2) + read(r1-1,c1-1);
}











    return 0;
}

