
struct matrix
{
        i64 mat[10][10],row,col;
        matrix() {}
        matrix(int row,int col)
        {
                this->row = row;
                this->col = col;
                For(i,row)
                        For(j,col)
                                mat[i][j] = 0;
        }

};

matrix identity(matrix a)
{
        For(i,a.row)
                For(j,a.row)
                {
                        if(i==j)
                                a.mat[i][j] = 1;
                        else
                                a.mat[i][j] = 0;
                }
        return a;
}

void print(matrix a)
{
        For(i,a.row)
        {
                For(j,a.col)
                        cerr << a.mat[i][j]<< " ";
                cerr << endl;
        }
}
matrix multiply(matrix a , matrix b,i64 m = mod)
{
        matrix r;
        r.row = a.row;
        r.col = b.col;

        For(i,r.row)
                For(j,r.col)
                {
                        i64 sum = 0;
                        For(k,a.col)
                                sum = ( sum + ( a.mat[i][k] * b.mat[k][j] ) ) % m;
                        r.mat[i][j] = sum;
                }
        return r;
}


// finding a^p
matrix power(matrix a,i64 p,i64 m = mod)
{
        if(!p)
                return identity(a);
        if(p==1)
                return a;
        if(p%2==1)
                return multiply(a,power(a,p-1,m),m);
        matrix r = power(a,p/2,m);
        r = multiply(r,r,m);
        return r;
}

matrix setvalue()
{
        matrix r = matrix(2,2);
        r.mat[0][0] = r.mat[0][1] = r.mat[1][0] = 1;
        r.mat[1][1]  = 0;
        return r;
}

int main()
{

        //ios_base::sync_with_stdio(false);cin.tie(0);
        int a,b,n,m,t,c=1;
        cin >> t;
        while(t--)
        {
                cin >> a >> b >> n >> m;
                m = po(10,m);
                a %= m;
                b %= m;

                if(!n)
                {
                        b = a;
                        n++;
                }
                matrix bm = setvalue();

                bm = power(bm,n-1,m);
                CASE(c++);
                cout << (bm.mat[0][0]*b + bm.mat[0][1]*a) % m << endl;


        }

        return 0;
}

