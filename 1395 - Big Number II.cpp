#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

long double dig[MAXN];

int main(){
	for(int i = 1; i < MAXN; i++)
		dig[i] = dig[i - 1] + log(i);
	int N;
	cin >> N;
	while(N--){
		int a, b;
		cin >> a >> b;
		if(a == 1 && b == 2)
			puts("1");
		else if(a == 2 && b == 6)
			puts("1");
		else
			cout << (long long int)(dig[a + 1] / log(b)) + 1 << endl;
	}
	return 0;
}