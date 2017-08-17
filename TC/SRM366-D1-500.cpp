#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define PI acos(-1)
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
vector<vector<string> >vec;
vector<string>G,S;
vector<vector<int> > vv;
ll n;
void solve(int ind,vector<string> v,ll msk){
    if(msk==n){vec.push_back(v);return;}
    if(ind==G.size())return;
    solve(ind+1,v,msk);
    ll nmsk=msk;
    for(int i=0;i<vv[ind].size();i++)nmsk |= ((ll)1 << vv[ind][i]);
    v.push_back(G[ind]);
    solve(ind+1,v,nmsk);
    v.pop_back();
}

class GuitarConcert {
public:
	vector <string> buyGuitars(vector <string> guitarNames, vector <string> guitarSongs) {
        G.clear();vec.clear();S.clear();vv.clear();n=0;
        G=guitarNames;S=guitarSongs;
        vv.resize(15);
        bool vis[50]={0};
        for(int i=0;i<S.size();i++){
            for(int j=0;j<S[i].size();j++)if(S[i][j]=='Y')vv[i].push_back(j),vis[j]=1;;
        }
        for(int i=0;i<S[0].size();i++)if(vis[i])n|=((ll)1 << i);
        vector<string>v;
        solve(0,v,0);
        if(vec.size())v=vec[0];
        for(int i=0;i<vec.size();i++){
            sort(vec[i].begin(),vec[i].end());
            if(v.size()>vec[i].size()){
                v=vec[i];
            }
            else if(v.size()==vec[i].size()){
                v=min(v,vec[i]);
            }
        }
        return v;
	}
};
