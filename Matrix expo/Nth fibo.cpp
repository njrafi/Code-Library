
matrix setvalue()
{
        matrix r;
        r.row = r.col = 2;
        r.mat[0][0] = r.mat[0][1] = r.mat[1][0] = 1;
        r.mat[1][1]  = 0;
        return r;
}

i64 fib(int n)
{

        if(!n)
                return 0;
        else if(n==1)
                return 1;

        matrix bm = setvalue();

        bm = power(bm,n-1,mod);


        return (bm.mat[0][0]) % mod;
}
