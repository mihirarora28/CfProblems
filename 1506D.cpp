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
     int arr[n]; 
     map<int,int>mapp; 
     priority_queue<int>pq; 
     for(int i = 0; i < n; i ++ )
     {
     cin>>arr[i]; 
     mapp[arr[i]]++; 
     }
     for(auto i : mapp){
         pq.push(i.second); 
     }
     while(pq.size()>=2){
      
         int c = pq.top(); 
         pq.pop(); 
         int c1 = pq.top() ; 
         pq.pop(); 
            // cout<<c<<" "<<c1<<"\n"; 
         c -- ;
         c1--; 
         if(c!=0){
             pq.push(c); 
         }
         if(c1!=0){
             pq.push(c1); 
         }
     }
     if(pq.size() == 0)
     cout<<0; 
     else
     cout<<pq.top(); 
     
}

 int main()
 {   int t = 1; 
      scanf("%d",&t);    
    while(t--){
solve(); 
cout<<"\n"; 
 }
}