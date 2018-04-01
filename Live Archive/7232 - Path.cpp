#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define PI acos(-1)
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const ll inf = 1e18 + 100;
double EPS = 1e-12;

using namespace std;

double slop(double x1, double y1, double x2, double y2)
{
    return (y2-y1)/(x2-x1);
}

int dcmp(double x, double y) {
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
    CS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;
        vector< pair< pair < int , int > ,bool>>arr(n);
        int x,y;
        cin>>x>>y;
        arr[0].f.f=0;
        arr[0].f.s=0;
        arr[0].s=0;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            a-=x,b-=y;
            arr[i].f.f=a;
            arr[i].f.s=b;
            arr[i].s=0;
        }
        int m;
        cin>>m;
        vector<pair<int,int> >vec;
        for(int i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            vec.push_back({a,b});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
        {
            int ed = vec[i].f,d=vec[i].s;
            int x,y;
            if(arr[ed+i].f.f == arr[(ed+i+1)%n].f.f) {
                x = arr[ed+i].f.f;
                if(arr[ed+i].f.s>arr[(ed+i+1)%n].f.s)
                    y=arr[ed+i].f.s-d;
                else y=arr[ed+i].f.s+d;
            } else{
                y=arr[ed+i].f.s;
                if(arr[ed+i].f.f>arr[(ed+i+1)%n].f.f)
                    x=arr[ed+i].f.f-d;
                else x=arr[ed+i].f.f+d;
            }
            arr.insert(arr.begin()+ed+i+1,{{x,y},1});
        }
        stack<pair<double,int> >st;
        double dis[n+m+10];
        dis[0]=0.0;
        double ans=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(!st.size())
            {
                dis[i]=dist(0,0,arr[i].f.f,arr[i].f.s);
                if(i!=arr.size()-1)
                    st.push({slop(0,0,arr[i].f.f,arr[i].f.s),i});
                if(arr[i].s)
                    ans+=dis[i];
                continue;
            }
            bool kk=0;
            while(st.size())
            {
                if(dcmp(st.top().f,slop(0,0,arr[i].f.f,arr[i].f.s))==1)
                    st.pop();
                else{
                    kk=1;
                    dis[i]=dist(arr[i].f.f,arr[i].f.s,arr[st.top().s].f.f,arr[st.top().s].f.s)+dis[st.top().s];
                    st.push({slop(0,0,arr[i].f.f,arr[i].f.s),i});
                    break;
                }
            }
            if(!kk)
            {
                dis[i]=dist(0,0,arr[i].f.f,arr[i].f.s);
                st.push({slop(0,0,arr[i].f.f,arr[i].f.s),i});
            }
            if(arr[i].s)
                ans+=dis[i];
        }
        cout<<fixed<<setprecision(1)<<ans<<endl;
    }
    return 0;
}
