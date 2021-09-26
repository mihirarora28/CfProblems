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
       map<int,int>mapp; 
 ccc:     while(n--)
     {
       
     string s; 
     cin>>s; 
     stack<char>s1;
     for(auto i : s){
        //  cout<<i<<"\n";
         if(s1.empty()){
             s1.push(i); 
         }
        else if(s1.top() == '(' && i == ')'){
            // cout<<"vefd";
             s1.pop();
         }
         else{
             s1.push(i); 
         }
     }
      if(s1.size() == 0){
        //   cout<<n; 
          mapp[0]++; 
          continue; 
      }
      int ans1 =1 ;
       int c = s1.top(); 
       s1.pop(); 

       if(c == '('){
           ans1 = 1; 
           while(!s1.empty()){
               if(s1.top() == '('){
                   ans1++; 
               }
               else{
                   goto ccc;
               }
               s1.pop(); 
           }
       }

       else{
           ans1 = -1; 
            while(!s1.empty()){
               if(s1.top() == ')'){
                   ans1--; 
               }
               else{
                   goto ccc;
               }
                 s1.pop(); 
           }

       }
        // cout<<ans1<<"\n"; 
       mapp[ans1]++; 

     }
     int ans = 0 ;
     for(auto i : mapp){
         if(i.first>=0)
         {
         int c = i.first; 
         int c1 = -i.first; 
         if(i.first == 0){
            //  cout<<i.second<<"\n";
             ans+=i.second/2; 
            //  cout<<ans<<"\n"; 
             continue; 
         }
        //  cout<<mapp[c]<<" "<<mapp[c1]<<"\n"; 
          ans+= min(mapp[c],mapp[c1]); 
         }
     }
     cout<<ans; 

 }
 int main()
 {
     
     int t = 1; 
    //   scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }