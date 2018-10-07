
struct matrix
{
        i64 mat[3][3],row,col;
        matrix()
        {
                For(i,3)
                        For(j,3)
                                mat[i][j] = 1;
        }
};



matrix setvalue()
{
        matrix r = matrix();
        r.row = r.col = 3;
        r.mat[1][0] = r.mat[2][0] = r.mat[2][2] = 0;
        return r;
}



i64 fibSum(int n)
{

        if(n<1)
                return 0;
        else if(n==1)
                return 1;

        matrix bm = setvalue();

        bm = power(bm,n-1,mod);


        return (bm.mat[0][0] + bm.mat[0][1]) % mod;
}

