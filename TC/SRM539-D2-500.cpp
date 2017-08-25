#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define ll long long

using namespace std;

vector<int>a,b;
vector<pair<int,int> >vec;
void solve(int ind,ll s,ll e){
    if(e>9000)vec.push_back({max(s,(ll)9001),e});
    if(ind==a.size())return;
    solve(ind+1,s+a[ind],e+b[ind]);
    solve(ind+1,s,e);
}

class Over9000Rocks {
public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
        a=lowerBound;b=upperBound;vec.clear();
        solve(0,0,0);
        int ans=0,s=0,e=0;
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            if(s<=vec[i].first&&e>=vec[i].first&&e<=vec[i].second){
                ans+=vec[i].second-e;
                e=vec[i].second;
                s=vec[i].first;
            }else if(e<=vec[i].first){
                ans+=vec[i].second-vec[i].first+1;
                e=vec[i].second;
                s=vec[i].first;
            }
        }
        return ans;
	}
};
