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
     int arr[n]; 
     for(int i = 0 ; i < n ; i++){
         cin>>arr[i]; 
     }
     

     int currentindex = 0 ; 
       vector<int>visited; 
      vector<int>s; 

int t =4;
      while(s.size()!=n)
       {
     
     int mini = 1e9; 
     int index = -1; 
    //  vector<int>vv; 
   sort(visited.begin(),visited.end()); 
     for(int i = currentindex ; i < n ; i ++){
       auto it = binary_search(visited.begin(), visited.end() ,arr[i]); 
       if(it == true){
           continue; 
       }
         mini = min(mini, arr[i]); 
     }
     
     s.push_back(mini); 
     bool c = false;
     for(int i = currentindex ; i < n ; i ++){
        //  sort(visited.begin(),visited.end()); 
       auto it = binary_search(visited.begin(), visited.end() ,arr[i]); 
        if(it == true){
           continue; 
       }
        //  if(i+1<n && arr[i + 1] == mini ){
        //      continue ; 
        //  }
           
         if(arr[i] == mini)
         {
         index = mini;
         break; 
         }
        c = true; 


         visited.push_back(arr[i]); 
          s.push_back(arr[i]); 
     }
     visited.push_back(mini);
         if(c == true)
         {  
            int c = s.back(); 
            auto it = find(s.begin(),s.end(),c); 
            s.erase(it); 
            auto it1 = find(visited.begin(),visited.end(),c); 
            visited.erase(it1); 
         }

      }

   
     for(auto i : s){
      cout<<i<<" "; 
     }
    //  for(auto i : )
    //  s.clear(); 
     
    //  for(auto i : )


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