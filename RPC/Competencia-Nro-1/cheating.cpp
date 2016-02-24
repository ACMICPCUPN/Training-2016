#include<iostream>
#include<cmath>
using namespace std;

double dist(int X, int Y){
	return X*X+Y*Y;
}

int main (int argc, char *argv[]) {
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int D, X, Y;
		cin>>D>>X>>Y;
		if(dist(X, Y)==0) cout<<0<<endl;
		else if(dist(X, Y)<D) cout<<2<<endl;
		else cout<<ceil(sqrt(dist(X, Y)/D))<<endl;
	}
	return 0;
}

