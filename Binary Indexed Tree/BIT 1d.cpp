/// range sum

#define MAX 100005

int BIT[MAX];

// must use 1-indexed array
// arr[idx] += val 
// to set arr[idx] = x , val = x - arr[idx]
void update(int idx, int val)                                                          
{
    for( ; idx < MAX; idx += idx&(-idx))
        BIT[idx] += val;
}

// for query from x to y
// query(y) - query(x-1)
int query(int idx)                          
{
    int sum = 0;
    for( ; idx > 0; idx -= idx & (-idx))
        sum += BIT[idx];

    return sum;
}
