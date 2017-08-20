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
    int DM[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int n;
    while(cin>>n && n){
        int D,M,Y,C,i=0,v=0;
        cin>>D>>M>>Y>>C;n--;
        while(n--){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            if(c==Y){
                if(b==M){
                    if(a==D+1){
                        i++;
                        v+=d-C;
                    }
                }else if(b==M+1){
                    if(a==1){
                        if(c%4==0 && c%100 !=0 && M==2&&D==29){
                            i++;
                            v+=d-C;
                        }else if(c%4==0 && c%100 !=0 && M==2&&D==28){
                        }else if(D==DM[M]){
                            i++;
                            v+=d-C;
                        }
                    }
                }
            }else if(c==Y+1&&M==12&&b==1&&D==DM[M]&&a==1){
                i++;
                v+=d-C;
            }
            D=a;M=b;Y=c;C=d;
        }
        cout<<i<<' '<<v<<endl;
    }
    return 0;
}
