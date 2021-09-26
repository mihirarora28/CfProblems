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
int factorial( int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res = ((res)%mod * (i)%mod)%mod;
    return res%mod;
}
bool sortbysec(const pair<ll,vector<ll>> &a,
              const pair<ll,vector<ll>> &b)
{
    return (a.first < b.first);
}
 void solve(){
     int n; 
     cin>>n; 
     int k; 
     cin>>k; 
     int arr[n]; 
     map<int,int>mapp; 
     for(int  i = 0; i < n; i ++ )
 {
     cin>>arr[i];
     mapp[arr[i]]++; 

 }
 int maxed = -1; 
 for(auto i : mapp){
     maxed = max(maxed,i.second); 
    
 }
 if(k<maxed){
     cout<<"NO\n"; 
     return; 
 }
 cout<<"YES\n"; 
    int colors[5001];
    for(int i = 0 ; i < 5001; i ++ )
    colors[i] = 1; 
    vector<int>v; 
    for(int i = 0 ; i < n; i ++ ){
        v.push_back(colors[arr[i]]);  
        colors[arr[i]]++; 
    }
    int c = maxed; 
    k = k - maxed; 
    map<int,bool>mapps; 
    int cccc = maxed  + 1; 
    for(int i  = 0; i  < v.size(); i ++ ){
        if(mapps[v[i]] == true){
            v[i] = cccc; 
            cccc++; 
            k--; 
        }
        else{
            mapps[v[i]]=true; 
        }
        if(k == 0){
            break; 
        }
    }
    for(auto i : v){
        cout<<i<<" "; 
    }
}

 int main()
 {   int t = 1; 
    //   scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}