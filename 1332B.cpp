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
int dp[100][100];
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
     for(int i = 0 ; i < n ; i ++ )
     cin>>arr[i]; 
     vector<int>v; 
     map<int,int>mapp; 
     v.push_back(2); 
       v.push_back(3); 
         v.push_back(5); 
           v.push_back(7); 
             v.push_back(11); 
               v.push_back(13); 
                 v.push_back(17); 
                   v.push_back(19); 
                     v.push_back(23); 
                      v.push_back(29);
                        v.push_back(31); 
        vector<int>answers; 
    for(int i = 0 ;i  < n; i ++ ){
        for(int j = 0 ; j < 11; j ++ ){
            if(arr[i]%v[j] == 0){
                //  cout<<arr[i]<<" "<<v[j]<<"\n"; 
                answers.push_back(v[j]); 
                 break; 
            }
        }
    }
    map<int,int>pairyt; 
    // int color = 1; 
    set<int>s; 
    for(auto i : answers)
    s.insert(i); 
    cout<<s.size()<<"\n"; 
    //  cout<<answers.size()<<"\n"; 
    int color = 1; 
    int len = answers.size(); 
    for(int i = 0 ; i < len; i ++ ){
       if(answers[i] == 2) {
           if(mapp[2] ==0 )
           {
           cout<<color<<" "; 
               mapp[2] = color; 
           color++; 
       
           }
           else{
               cout<<mapp[2]<<" "; 
           }
       }
       //
        if(answers[i] == 3) {
           if(mapp[3] ==0 )
           {
           cout<<color<<" "; 
              mapp[3] = color; 
           color++; 
        
           }
           else{
               cout<<mapp[3]<<" "; 
           }
       }
        if(answers[i] == 5) {
           if(mapp[5] ==0 )
           {
           cout<<color<<" "; 
                 mapp[5] = color; 
           color++; 
     
           }
           else{
               cout<<mapp[5]<<" "; 
           }
       }
        if(answers[i] == 7) {
           if(mapp[7] ==0 )
           {
           cout<<color<<" "; 
               mapp[7] = color; 
           color++; 
       
           }
           else{
               cout<<mapp[7]<<" "; 
           }
       }
        if(answers[i] == 11) {
           if(mapp[11] ==0 )
           {
           cout<<color<<" "; 
            mapp[11] = color; 
           color++; 
          
           }
           else{
               cout<<mapp[11]<<" "; 
           }
       }
        if(answers[i] == 13) {
           if(mapp[13] ==0 )
           {

           cout<<color<<" "; 
            mapp[13] = color; 
           color++; 
          
           }
           else{
               cout<<mapp[13]<<" "; 
           }
       }
        if(answers[i] == 17) {
           if(mapp[17] ==0 )
           {
           cout<<color<<" "; 
               mapp[17] = color; 
           color++; 

       
           }
           else{
               cout<<mapp[17]<<" "; 
           }
       }
        if(answers[i] == 19) {
           if(mapp[19] ==0 )
           {
           cout<<color<<" "; 
               mapp[19] = color; 
           color++; 
       
           }
           else{
               cout<<mapp[19]<<" "; 
           }
       }
        if(answers[i] == 23) {
           if(mapp[23] ==0 )
           {
           cout<<color<<" "; 
            mapp[23] = color; 
           color++; 
          
           }
           else{
               cout<<mapp[23]<<" "; 
           }
       }
        if(answers[i] == 29) {
           if(mapp[29] == 0 )
           {
           cout<<color<<" "; 
               mapp[29] = color; 
           color++; 
       
           }
           else{
               cout<<mapp[29]<<" "; 
           }
       }
        if(answers[i] == 31) {
           if(mapp[31] ==0 )
           {
           cout<<color<<" "; 
                mapp[31] = color; 
           color++; 
      
           }
           else{
               cout<<mapp[31]<<" "; 
           }
       }
       
      
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