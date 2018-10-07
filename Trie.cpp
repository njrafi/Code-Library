

/*
There are a couple of other of way to implement it 
But it is the most efficient because no need to memset 
If memory is a problem we can use map
*/


#define mxn 4000006


/// remember to initialize it to 1 
int nodenum;
char v[1002];


int gg[200];



struct node
{
        int nxt[64];
        int freq;
        int efreq;
        node()
        {
                mem(nxt,0);
                freq = 0;
                efreq = 0;
        }
}trie[mxn];

i64 ins()
{
        int now = 0;
        int ssz = strlen(v);
        
        For(i,ssz)
        {
                int vl = val(v[i]);
                if(!trie[now].nxt[vl])
                {
                        trie[nodenum] = node();

                        trie[now].nxt[vl] = nodenum++;

                }

                now = trie[now].nxt[vl];

                trie[now].freq++;
        }


        return ans;
}