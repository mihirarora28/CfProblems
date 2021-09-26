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

 void solve(){
     int n;
     cin>>n; 
    string c; 
    cin>>c; 
    vector<pair<string,int>>v; 
    for(int k=1;k<=n;k++){
        string c1 = ""; 
        for(int j = k - 1; j < n ; j ++ )
        c1+=c[j]; 
        if((n-k)%2==1)
        {
            for(int j = 0; j <=k-2; j++ ){
                c1+=c[j]; 
            }
        }
        else{
               for(int j = k - 2; j >=0; j -- ){
                c1+=c[j]; 
            }
        }
        v.push_back({c1,k}); 
        // cout<<c1<<"\n"; 
    }
    sort(v.begin(),v.end()); 
    cout<<v[0].first<<"\n"; 
    cout<<v[0].second; 

}

 int main()
 {   int t = 1; 
      scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}