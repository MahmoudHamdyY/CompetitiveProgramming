#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define PI acos(-1)
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    CS;
    int n,m,mx=1e9 + 5;cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        mx=min(mx,b-a);
    }
    mx++;
    cout<<mx<<endl;
    for(int i=0;i<n;i++)cout<<i%mx<<' ';
    return 0;
}
