#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1000000007;
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (prime[p])
        primes.push_back(p); 
}
ll power(ll x,  ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2)%mod) * (power(x, y / 2)%mod))%mod;
    else
        return ((((x  %mod) * ((power(x, y / 2)%mod)))%mod * (power(x, y / 2)%mod))%mod)%mod;
}
 void solve(){
    ll n; 
    cin>>n; 
    vector<pair<ll,ll>>v; 
    // set<pair<int,int>>s; 
    map<pair<int,int>,bool>mapp; 

     v.push_back({0,0}); 
    for(int i = 0 ; i < n  ; i ++ ){
        ll a,b; 
        cin>>a>>b; 
        if(a==0 && b == 0){
            continue; 
        }
       if(mapp[{a,b}] == true){
           continue; 
       }
       mapp[{a,b}] = true; 
       v.push_back({a,b}); 
        // s.insert({a,b}); 
    }
    // for(auto i : s){
    //     v.push_back(i); 
    // }
    int ans = 0 ;
    if(v.size() == 1){
        cout<<1; 
        return; 
    }
    map<int,int>mapp2; 
    // cout<<v.size()<<"\n"; 
    for(int i = 0 ; i + 1 < v.size() ; i ++ ){
        pair<int,int>pp = v[i+1];
        pair<int,int>pp2 = v[i];  
        int c = max(pp2.first,pp2.second); 
        //  cout<<c<<" "<<pp.first<<" "<<pp.second<<" "<<ans<<"\n"; 
        if(pp.first>=c && pp.second >=c){
            int c1 = min(pp.first,pp.second); 
            if(mapp2[c] == true && mapp2[c1] == true && c1!=c){
                ans+=(c1-c)-1; 
            }
            if(mapp2[c] == true||mapp2[c1] == true){
                   ans+=(c1-c) ;
                   continue;  
            }
                 mapp2[c] = true; 
                 mapp2[c1] = true; 
            // cout<<c<<" "<<c1<<"\n"; 
            ans+=(c1-c) + 1; 
        //  cout<<i<<" "<<ans<<"\n"; 
        }
        else{
            continue; 
        }
    }
    cout<<ans; 
    
 }
 int main()
 {
     int t = 1; 
    //  scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }