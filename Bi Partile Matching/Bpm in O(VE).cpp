
#define mxn 2505

vector<i64> nodeR;              // original value of ith node
vpi nodeL;
map < i64 , int > id;           // mapping value of elements of R


// 0 index e kichu rakha jabe na , so node count =  size - 1
// remember to insert something in the 1st index of node vector

int matchL[mxn] , matchR[3 * mxn];
vi v[mxn];                              // L er node theke R er node e edge
bool vis[mxn];                          // L er kon kon node visited

// matchL[i] = L grp er ith node R grp er kon node er sathe matched
// matchR = same
// 0 means not matched with anyone


// u = L er ekta node
int findmatch(int u)           
{
        vis[u] = 1;

        For(i,v[u].sz)
        {
                // vv = R er ekta node
                int vv = v[u][i];               

                if(!matchR[vv])
                {
                        matchL[u] = vv;
                        matchR[vv] = u;
                        return 1;
                }

                // k = vv  jar sathe match kora
                int k = matchR[vv];
                
                // k er notun match khujtechi
                if(!vis[k] && findmatch(k))     
                {
                        matchL[u] = vv;
                        matchR[vv] = u;
                        return 1;
                }
        }

        return 0;
}

int bpm()
{
        int ans = 0;

        Fre(i,1,nodeL.sz)
        {
                mem(vis,0);

                if(!matchL[i] && findmatch(i))  // matched na hoile match khuji
                        ans++;
        }

        return ans;
}

