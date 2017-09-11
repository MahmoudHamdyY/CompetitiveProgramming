#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define PI acos(-1)
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    int n,m,x,y;ll k,all;
    cin>>n>>m>>k>>x>>y;
    ll arr[105][105];
    if(n<3)all=k/(m*n),k%=(n*m);
    else all=k/(2*(n-1)*m),k%=(2*(n-1)*m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            arr[i][j]=all;
            if(i&&i!=n-1)arr[i][j]+=all;
        }
    for(int i=0;i<n&&k;i++)
        for(int j=0;j<m&&k;j++)arr[i][j]++,k--;
    for(int i=n-2;i>0&&k;i--)
        for(int j=0;j<m&&k;j++)arr[i][j]++,k--;
    ll mn=1e18+5,mx=-1,ans=arr[x-1][y-1];
    for(int i=0;i<n;i++){
        sort(arr[i],arr[i]+m);
        mn=min(mn,arr[i][0]);
        mx=max(mx,arr[i][m-1]);
    }
    cout<<mx<<' '<<mn<<' '<<ans;
    return 0;
}
