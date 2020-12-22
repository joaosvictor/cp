#include<iostream>
 using namespace std;
 int main(){
    long long n;
    cin>>n;
    cout<<((n%2)?2:1) * (n/2 + 1) *(n - n/2 + 1);
}