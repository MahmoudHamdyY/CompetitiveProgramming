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

using namespace std;

long long f(long long a){
	if(a==1)return 1;
	return a*f(a-1);
}
class LittleElephantAndPermutationDiv2 {
public:
	long long getNumber(int N, int K) {
        vector<int>vec(N);ll ans=0;
        for(int i=0;i<N;i++)vec[i]=i+1;
        do(
            int k=0;
            for(int i=0;i<N;i++)k+=max(i+1,vec[i]);
            if(k>=K)ans++;
        )while(next_permutation(vec.begin(),vec.end()));
        return ans*f(N);
	}
};

