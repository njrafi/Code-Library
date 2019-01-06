#include <bits/stdc++.h>




#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree< pair < long long int , long long int> ,null_type,less< pair < long long int , long long int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{


        int t,cs = 1;
        sf(t);
        while(t--)
        {


                ordered_set points,seg;
                i64 n,q , inp;
                sff(n,q);
                char op[3];

                points.insert(mp(0,0));
                points.insert(mp(n,0));

                seg.insert(mp(n,lala++));


                printf("Case %d:\n",cs++);
                while(q--)
                {
                        scanf("%s",op);
                        sf(inp);
                        if(op[0]=='F')
                        {

                                pair<i64,i64> ret = *seg.find_by_order(inp-1);
                                pfn(ret.ff);
                        }
                        else
                        {

                                points.insert(mp(inp,0));
                                i64 pos = points.order_of_key(mp(inp,0));
                                pair<i64,i64> prev = *points.find_by_order(pos-1);
                                pair<i64,i64> next = *points.find_by_order(pos+1);
                                seg.erase(seg.lower_bound(mp(next.ff-prev.ff,0)));
                                seg.insert(mp(inp-prev.ff,lala++));
                                seg.insert(mp(next.ff-inp,lala++));

                        }
                }

        }
        return 0;
}
