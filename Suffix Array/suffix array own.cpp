
namespace suff
{

        /// Read detains in evernote
        /// A better algo for array construction is skew/dc3 (available in Zahin vai notebook)



        ///remember to change mxn
        const int mxn = 400004;

        struct info
        {
                int prvR,newR,idx;      // prev rank,new rank,and index
                info()
                {
                        prvR = newR = idx = 0;
                }
        };

        bool cmp(info a,info b)         // sorting according to rank
        {
                if(a.prvR==b.prvR)
                        return a.newR<b.newR;
                return a.prvR<b.prvR;
        }


        info arr[mxn];                  // information array
        /// after building arr[i].idx is the i'th value of suffix array

        int Rank[18][mxn];              // will contain the rank
        int n;                          // text size
        string text;                    // The Text

        int lcp[mxn];                   // lcp array


        /// Suffix Array is an array which will contains the index of suffix of a string if the suffixes were lexicographical sorted
        /// complexity (n * log(n) ^ 2)

        void build_suffix_array(string s)
        {
                text = s;
                text += '$';
                n = text.sz;
                mem(Rank,0);

                For(i,n)
                {
                        arr[i] = info();
                        Rank[0][i] = text[i];     // rank suffix according to first char
                }

                for(int step = 1 , jump = 1 ; jump < n ; step++ , jump *= 2)
                {
                        For(i,n)
                        {
                                arr[i].idx = i;
                                arr[i].prvR = Rank[step-1][i];
                                arr[i].newR = -1;

                                if(i+jump<n)
                                        arr[i].newR = Rank[step-1][i+jump];

                        }

                        sort(arr,arr+n,cmp);

                        Rank[step][arr[0].idx] = 0;

                        Fre(i,1,n)
                                if(arr[i].prvR == arr[i-1].prvR && arr[i].newR==arr[i-1].newR )
                                        Rank[step][arr[i].idx] = Rank[step][arr[i-1].idx];
                                else
                                        Rank[step][arr[i].idx] = i;


                }
        }


        ///The LCP Array is the array of Longest Common Prefixes between the ith suffix and the (i-1)th suffix in the Suffix Array
        ///complexity (n * log(n))

        void build_LCP_array()
        {
                lcp[0] = 0;

                Fre(i,1,n)
                {
                        int id1 = arr[i - 1].idx;
                        int id2 = arr[i].idx;
                        lcp[i] = 0;
                        for(int j = ceil(log2(n)) ; j >= 0; j--)
                                if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
                                {
                                        lcp[i] += (1 << j);
                                        id1 += (1 << j);
                                        id2 += (1 << j);
                                }
                }

        }


        void print_array()
        {
                cout << "\n\nSuffix Array : \n\n";
                For(i,n)
                        cout<< i << " " << arr[i].idx << " " <<text.substr(arr[i].idx)<<endl;

                cout << "\n\nLCP Array: \n\n";
                Fre(i,1,n)
                        cout << i << ' ' << lcp[i] << endl;
        }


        /// returns count of distinct substring(tested in spoj)
        int countDistinctSubstring()
        {
                int ans = 0;

                Fre(i,1,n)
                        ans += (n - arr[i].idx - 1 ) - lcp[i];

                return ans;
        }

        /// returns count of distinct substring of length [l,r]
        int countDistinctSubstringRange(int l,int r)
        {
                int ans = 0;
                Fre(i,1,n)
                {
                        int rr = (n - arr[i].idx - 1 );
                        int ll = lcp[i] + 1;

                        ans += max(0,min(r,rr) - max(l,ll) + 1);
                }

                return ans;
        }
}



int main()
{


        suff::build_suffix_array("abcdef");
        suff::build_LCP_array();
        suff::print_array();
        cout << suff::countDistinctSubstring() << endl;
        cout << suff::countDistinctSubstringRange(2,5) << endl;







        return 0;
}


