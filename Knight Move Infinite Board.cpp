
i64 knight_move(pii p)
{
        i64 x = p.ff , y = p.ss , a,b,z,c,d;
        x = abs(x);
        y = abs(y);
        if(x<y)
                swap(x,y);

        if(x==2 && y==2)
                return 4;
        if(x==1 && y==0)
                return 3;

        if(!y || (y<<1) < x)
        {
                c = y & 1;
                a = x - ( c << 1);
                b = a & 3;
                return ( (a-b)>>1) + b + c;
        }
        else
        {
                d = x - ( (x-y) >> 1);
                z = ( ( d % 3) != 0);
                c = (x - y) & 1;
                return ( (d/3) * 2) + c + (z * 2 * (1-c));
        }
}

/// edit pii to i64 for i64 calculation
i64 get_dis(pii p1,pii p2)              
{
        if(p1.ff>p2.ff)
                swap(p1,p2);
        if(p1.ss>p2.ss)
                p2.ss = 2*p1.ss - p2.ss;

        p2.ff -= p1.ff;
        p2.ss -= p1.ss;

        return knight_move(p2);
}

int main()
{

    Fre(i,-10,11)
    {
            Fre(j,-10,11)
                    cout << get_dis(mp(0,0),mp(i,j)) << " ";

            puts("");
    }

        return 0;
}

