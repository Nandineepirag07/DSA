// find No of Prime No in given Range 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v(n+1,1);
   
    //mark all even no as not prime 
    for(int i=0;i<=n;i+=2){
        v[i]=0;
    }
    v[2]=1;  //mark 2 as prime 
    v[1]=0;
    for(int i=3;i<=n;i+=2){
      // if this odd no is prime then mark all its multiple as not prime 
      
      if(v[i]==1)    
       {
 
        for(int j=i*i;j<=n;j=j+i)
          v[j]=0;
       }      
    }
    
    for(int i=0;i<n;i++){
        if(v[i]==1)
         cout<<i<<" ";
    }
    
	return 0;
}