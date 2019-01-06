


/// very little chance of clash
/// if clash do double hash

#define ui64 unsigned long long

namespace hashString
{

        /// prime
        const int p1 = 163;
        /// total string
        const int totst = 100005;
        /// Max String Length
        const int mxns = 10004;

        ui64 pr1[mxns] ;
        vector<ui64> h1[totst] ;


        /// Remember to call in first
        void gen_prime()
        {
                pr1[0] = 1;
                Fre(i,1,mxns)
                        pr1[i] = pr1[i-1] * p1 ;
        }


        /// generating hash
        void gen(string sss,int idx = 0)
        {

                h1[idx].clr;
                h1[idx].pb(0);

                For(i,sss.sz)
                        h1[idx].pb( ( h1[idx][i] * p1) + sss[i] ) ;

        }


        /// 0 based indexing
        /// gives hash of a range
        ui64 hashOfRange(int l,int r,int idx = 0)
        {

                int len = r - l + 1;

                ui64 hash1 =  h1[idx][r+1] -  (h1[idx][l] * pr1[len]) ;


                return hash1;

        }
}


int main()
{
        hashString::gen_prime();
        hashString::gen("gglala");
        cout << hashString::hashOfRange(0,5) << endl;
        return 0;
}


