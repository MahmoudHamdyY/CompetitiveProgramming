#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define ss second
#define PI acos(-1)
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
vector<ll>v;
ll c;
bool ch(){
    int n=v.size();
    for(int i=0;i<n;i++){
        int k=floor(c/v[i]);k%=n;
        for(int j=i+1;j<n;j++){
            int kk=(floor(c/v[j]));
            if(k==kk%n){
                c = min((c/v[i]+1)*v[i], (c/v[j]+1)*v[j]);
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    CS;
    string s;
    while(getline(std::cin>>std::ws,s)){
        ll sum=0;
        v.clear();
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){if(sum)v.push_back(sum);sum=0;}
            else{
                sum*=32;sum+=s[i]-'a'+1;
            }
        }
        v.push_back(sum);
        c=INT_MAX;
        for(int i=0;i<v.size();i++){
            c=min(c,v[i]);
        }
        while(!ch());
        cout<<s<<'\n'<<c<<"\n\n";
    }
    return 0;
}

