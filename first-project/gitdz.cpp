#include<iostream>

using namespace std;

int fib(int n){ 
if (n==0){
return 0;
}
if ( n==1){
return 1;
}
return fib(n-1)+fib(n-2);
} 

int main(){
int n=10;
for (int i=0;i<n;i++)
cout<<fib(i)<<endl; 
cout<<"Hello world!"<<endl; 
return 0;
}
