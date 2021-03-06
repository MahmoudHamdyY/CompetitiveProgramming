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

const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
            from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;
    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }
    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail) {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if(!e) {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int n,m;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

bool vaild(int i,int j)
{
    return (i>0&&i<=n&&j>0&&j<=m);
}

int main() {
    CS;
    int t;
    cin >> t;
    while (t--)
    {
        cin>>n>>m;
        ll sum=0;
        int arr[n+1][m+1];
        Dinic d(n*m*2 + 2);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
                d.AddEdge(0,(i-1)*m + j,arr[i][j]);
                d.AddEdge(((i-1)*m + j)+(n*m),n*m*2+1,arr[i][j]);
                sum+=arr[i][j];
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<4;k++)
                    if(vaild(i+dx[k],j+dy[k]))
                        d.AddEdge((i - 1) * m + j, ((i + dx[k] - 1) * m + (j + dy[k])) + (n * m),
                                  min(arr[i][j], arr[i + dx[k]][j + dy[k]]));
            }
        int mf=d.GetMaxFlow(0,n*m*2 + 1);
        cout<<sum-mf + (mf/2)<<endl;
    }
    return 0;
}
