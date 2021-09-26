#include<iostream>
using namespace std; 
int main(){
    cout<<"Enter the value of first number\n";
    int a; 
    cin>>a; 
    cout<<"Enter the value of second number\n";
    int b; 
    cin>>b; 
    cout<<"1.Addition Operation\n 2. Subtraction\n 3. Multiplication\n 4. Division \n 5. Modulo Operation"; 
    int choice; 
    cin>>choice; 
    switch(choice){
        case 1:
          cout<<"Addition of the 2 numbers is\n";
          cout<<a+b; 
          break; 
        case 2:
          cout<<"Subtraction of the 2 numbers is\n";
          cout<<a-b; 
          break; 
        case 3:
          cout<<"Multiplication of the 2 numbers is\n";
          cout<<a*b; 
          break; 
        case 4:
          cout<<"Division of the 2 numbers is\n";
          cout<<(double)a/b; 
          break; 
        case 5: 
        cout<<"Enter value of Quotient\n"; 
         int c; 
         cin>>c; 
         cout<<a%c; 
         break; 
         default:
         cout<<"Wrong choice\n";
    }
}