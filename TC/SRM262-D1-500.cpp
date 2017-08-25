#include <bits/stdc++.h>
#define ll long long
using namespace std;

int score(string k){
    int ret=0;
    sort(k.begin(),k.end());
    if(k[0]==k[4])ret= 50;
    int t=0;
    int msk=0;
    for(int i=0;i<5;i++)t+=k[i]-'0',msk|=(1 << (k[i]-'1'));
    if((msk&31)==31||(msk&62)==62)ret=max(ret,40);
    if((msk&15)==15||(msk&30)==30||(msk&60)==60)ret=max(ret,30);
    if(k[0]==k[1]&&k[2]==k[4])ret=max(ret,25);
    if(k[0]==k[2]&&k[3]==k[4])ret=max(ret,25);
    if(k[0]==k[3]||k[1]==k[4])ret=max(ret,t);
    return ret;
}

class BestYahtzeeScore {
public:
	int bestScore(string rolls) {
        int ans=0;
        for(int i=0;i<(1 << 5);i++){
            for(int j=0;j<(1<<5);j++){
                string k="";int ii=0;
                for(int z=0;z<5;z++){
                    k+=rolls[ii];ii++;
                }
                for(int z=0;z<5;z++)if(i&(1 <<z))k[z]=rolls[ii],ii++;
                for(int z=0;z<5;z++)if(j&(1 <<z))k[z]=rolls[ii],ii++;
                ans=max(ans,score(k));
            }
        }
        return ans;
	}
};
