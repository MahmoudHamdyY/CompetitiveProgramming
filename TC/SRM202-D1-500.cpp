#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Histogram {
public:
	vector <string> draw(vector <string> title, vector <int> val) {
        vector<string>ans;
        int space=0;
        for(int i=0;i<title.size()-1;i++){
            int a=int(title[i].size())/2,b=int(title[i+1].size())/2;
            if(int(title[i+1].size())%2)a++;
            space=max(space,a+b);
        }
        while(1){
            int ind=0,mx=-1;
            for(int i=0;i<val.size();i++)if(val[i]>=mx)ind=i,mx=val[i];
            if(mx==0)break;
            string k="";
            for(int i=0;i<=ind;i++){
                if(!i){
                    string s=title[i],S="";
                    for(int j=0;;j++){
                        S+=' ';
                        if(int(s.size())%2){if(j==int(s.size())/2&&val[i]==mx){S[j]='X';break;}else if(j==int(s.size())/2){S[j]=' ';break;}}
                        else if(j+1==int(s.size())/2){
                            if(val[i]==mx)S[j]='X';
                            else S[j]=' ';
                            break;
                        }
                    }
                    k+=S;
                }else{
                    string s="";
                    for(int j=0;j<space;j++)s+=' ';
                    if(val[i]!=mx)s+=' ';
                    else s+='X';
                    k+=s;
                }
                if(val[i]==mx)val[i]--;
            }
            ans.push_back(k);
        }
        string s="";s+=title[0];
        for(int i=1;i<title.size();i++){
            int a=int(title[i-1].size())/2,b=int(title[i].size())/2;
            if(int(title[i].size())%2)a++;
            for(int j=a+b;j<=space;j++)s+=' ';
            s+=title[i];
        }
        ans.push_back(s);
        return ans;
	}
};

