

int ida_d, solved , n;
vi v;


bool ida()
{
        if(v.sz>ida_d)
                return 0;
        if(v.back()==n)
                return 1;
        if (  po(2,ida_d - v.sz) * v.back() < n)
                return 0;


        For(i,v.sz)
        {
                v.pb(v.back()+v[i]);

                if(v.back()<=10000 && ida())
                        return 1;

                v.pop_back();

                v.pb(v.back() - v[i]);

                if(v.back()>0 && ida())
                        return 1;

                v.pop_back();
        }

        return 0;
}

int main()
{


        while(1)
        {
                sf(n);
                if(!n)
                        break;
                solved = 0;
                ida_d = 0;
                v.clr;
                v.pb(1);

                while(!ida())
                {
                        ida_d++;
                        v.clr;
                        v.pb(1);
                }
                cout << ida_d - 1<< endl;

        }
        return 0;
}

