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
     int n; 
     cin>>n; 
     vector<pair<int,int>>v ;
          vector<pair<int,int>>v1 ;

     for(int  i = 0 ; i  <n ; i ++ ){
         int nn; 
         cin>>nn; 
         int arr[nn]; 
         for(int  j = 0 ; j  <nn; j ++ ){
             cin>>arr[j]; 
         }
         bool ans = false; 
         for(int j = 0 ; j+1  < nn ;  j ++){
             if(arr[j] < arr[j+1]){
                 ans = true; 
             }
         }
         if(ans == true){
             continue; 
         }
         int maxed = -1; 
         int  mini = 1e9; 
         for(int  j = 0 ; j  < nn;  j ++ ){
             maxed = max(maxed,arr[j]); 
             mini = min(mini,arr[j]); 
         }
        v.push_back({mini,maxed}); 
        v1.push_back({maxed,mini}); 
     }
     sort(v.begin(),v.end()); 
     sort(v1.begin(),v1.end()); 
     int sum = 0;
     for(int i = 0 ; i  <v.size(); i++ ){
         int a = v[i].first; 
         int b = v[i].second; 
        int aa = 0 ;
        int bb =0;
        aa =   v.size() - (upper_bound(v.begin(),v.end(),make_pair(b-1,INT_MAX))-v.begin()); 
        //  bb = v1.size() - (lower_bound(v1.begin(),v1.end(),make_pair(a,-1))-v1.begin()) ; 
        //  sum =aa+bb; 
          cout<<aa<<"\n"; 
     }
     cout<<sum;
     
 }
 int main()
 {

     int t = 1; 
        // cin>>t; 
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }