#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 ll mod = 10000000000007;
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
     int n; 
     cin>>n; 
     int arr[n]; 
     priority_queue<pair<int,int>>pq; 
     for(int i = 0 ; i < n ; i ++ ){
         cin>>arr[i]; 
         if(arr[i]>0)
         pq.push({arr[i],i});
     }
     vector<pair<int,int>>v;
     while(pq.size() > 1){
         pair<int,int>p1 = pq.top(); 
         pq.pop(); 
           pair<int,int>p2 = pq.top(); 
         pq.pop(); 
         p1.first = p1.first - 1; 
         p2.first = p2.first - 1; 
        //  cout<<p1.second<<" "<<p2.second<<"\n";
        v.push_back({p1.second+1,p2.second+1});  
         if(p1.first>0)
         pq.push(p1); 
         if(p2.first>0)
         pq.push(p2); 
     }
     cout<<v.size()<<"\n";
     for(auto i : v){
         cout<<i.first<<" "<<i.second<<"\n"; 
     } 
}
 int main()
 {
     cin.tie(NULL);
     int t = 1; 
      scanf("%d",&t); 

        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }