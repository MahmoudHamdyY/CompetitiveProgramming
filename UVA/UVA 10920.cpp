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

int chx[]={0,-1,0,1},chy[]={1,0,-1,0};
int main(){
    //CS;
    ll n,x,c,co,r,k,i,f;bool ff;
    while(scanf("%lld%lld",&n,&x)&&n&&x){
        c=(n+1)/2,r=(n+1)/2,k=1,i=0,f=0;
        ff=0;
        int l=0;bool hh=0;
        while(k+(l*4)+1<=x){
            k+=(l*4)+1;
            l+=2;
            r++;
            i=1;
            f+=2;
            hh=1;
        }
        if(!f)f=1;
        else f--;
        while(k<x){
            co=0;
            if(hh){co+=l/2 -1;hh=0;}
            while(co<f){
                c+=chx[i];r+=chy[i];
                co++;k++;
                if(k>=x){ff=1;break;}
            }
            if(ff)break;
            i++;
            i%=4;
            if(i==0||i==2)f++;
        }
        printf("Line = %lld, column = %lld.\n",r,c);
    }
    return 0;
}

