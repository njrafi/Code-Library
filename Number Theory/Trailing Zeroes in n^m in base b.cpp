#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF ((ll)1e18)

ll n,m,b,ans=INF;

int main()
{
    cin>>n>>m>>b;
    for(ll i=2;i<=b;i++)
        if(b%i==0)
        {
            ll num1=0,num2=0;
            while(b%i==0)num1++,b/=i;
            while(n%i==0)num2++,n/=i;
            ans=min(ans,num2*m/num1);
        }
    cout<<ans;
    return 0;
}
