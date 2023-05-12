#include<iostream>
#include<map>
#include<vector>

#define int long long int

using namespace std;

int dp(int n, map<int,int> &m){
    if(n==1 || n==0) return n;
    if(m[n]) return m[n]; 
    m[n] = dp(n-1,m)+dp(n-2,m);
    return m[n];
}

int32_t main(){
    int t;  cin>>t;
    map<int,int>m; 
    dp(81,m);
    while (t--)
    {
        int n,sum=0;  cin>>n;
        for(auto [key,value]:m){
            if(value>n) break;
            if(value%2)  continue;
            sum+=value;
        }
        cout<< sum << endl; 
    }
}