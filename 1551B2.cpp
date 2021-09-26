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
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
 
 void solve(){
     int n,k; 
     cin>>n>>k; 
     int arr[n]; 
     for(int  i = 0 ; i  <n ; i ++ )
     cin>>arr[i]; 
     map<int,int>mapp; 
     vector<pair<int,pair<int,int>>>v;
     for(int  i = 0 ; i < n ; i ++ )
     {
         mapp[arr[i]]++; 
         v.push_back({i,{arr[i],0}}); 
     } 
     int uncolored = 0; 
     int tobecolored = 0 ; 
     for(auto i : mapp){
        //  if(i.second < k ){
        //      uncolored = (uncolored + i.second)%k; 
        //  }
         if(i.second>=k){
             tobecolored = tobecolored + k; 
         }
         if(i.second<k){
             tobecolored = tobecolored + i.second; 
         }

     }

      sort(v.begin(), v.end(), sortbysecdesc);
      int factor = tobecolored/k; 
      int factorss = 0 ; 
     int color = 1 ; 
     int colors = 0 ;
     bool ans = true; 
     map<int,int>coloured; 
     for(int i = 0 ; i < n; i ++ ){
         int c = v[i].second.first; 
         if(coloured[c] == k || ans == false)
         {
             v[i].second.second = 0; 
         }
         else{
            //  if(colors == )
            //  colors++; 
            if(factor == factorss){
               ans = false; 
               v[i].second.second = 0 ; 
               continue; 
            }
               tobecolored--; 
            ////
             coloured[c]++; 
             v[i].second.second = color; 
             color = (color + 1)%(k+1); 
             if(color == 0)
             {
             color= 1; 
             factorss++; 
             }

         }
     }
     sort(v.begin(),v.end()); 
     for(int  i = 0 ; i < n ; i ++ )
     {
         cout<<v[i].second.second<<" "; 
     }

}
 int main()
 {

     int t = 1; 
      scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }