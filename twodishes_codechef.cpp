#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	  int n,a,b,c;
	  cin>>n>>a>>b>>c;
	  if(b>=n){
	      if(a+c>=n){
	          cout<<"YES"<<endl;
	      }
	      else{
	          cout<<"NO"<<endl;
	      }
	  }
	  else{
	      cout<<"NO"<<endl;
	  }
	}
	return 0;
}
