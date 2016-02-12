#include<iostream>
#include<stdio.h>
using namespace std;

int abs(int n){
	if(n<0) return n*-1;
	else return n;
}

int mod(int a, int b){
	return ((a%b)+b)%b;
}


int main (int argc, char *argv[]) {
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int amin, amax, bmin, bmax, mmax, mmin, c=0;
		cin>>amin>>amax>>bmin>>bmax>>mmin>>mmax;
		int a=amin;
		for(int b=bmin;b<=bmax;b++){
			for(int m=mmin;m<=mmax;m++){
				if(mod((mod(a, m)+mod(b, m)), m) == mod((mod(a, m)-mod(b, m)), m)){
					c++;
				}
				
			}
		}
		printf("Case %i: %i\n", i+1, c*(amax-amin+1));
	}
	return 0;
}
