int main()
{

        int t,cs = 1;
       // WRITE;
        sf(t);

        while(t--)
        {
                scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
                double lo = 0 , hi = 1 , A , B ,da ,db;
                while(abs(hi-lo)>eps)
                {
                        // 2 point A and B between lo and hi
                        A = (2*lo+hi)/3;                
                        B = (lo+2*hi)/3;
                        da = f(A);
                        db = f(B);

                        // if desired value is in point A next search will be in [lo,B]
                        //  if desired value is in point B next search will be in [B,hi]
                        if(abs(da-db)<eps)
                                break;
                        else if(da<db)                  
                                hi = B;
                        else
                                lo = A;                 
                }

                CASE(cs++);
                printf("%.8f\n" , min(da,db));
        }

        return 0;
}

