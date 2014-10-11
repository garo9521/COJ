#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAXN 100005
#define pii pair <int, int>

pii num[MAXN];

map <int, int> cubeta;

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		char b;
		cin >> a >> b;
		num[i] = make_pair(a, (b == 'W' ? 1 : -1));
	}
	sort(num, num + N);
	int sum = 0;
	int ans = 0;
	for(int i = 0; i < N; i++){
		sum += num[i].second;
		if(sum > 0){
			if(sum & 1){
				if(cubeta.find(1) != cubeta.end()){
					ans = max(ans, num[i].first - cubeta[1]);
				}
				if(cubeta.find(-1) != cubeta.end()){
					ans = max(ans, num[i].first - cubeta[-1]);
				}
				
			}else{
				ans = max(ans, num[i].first - cubeta[0]);
			}
		}else{
			if(cubeta.find(sum) != cubeta.end()){
				ans = max(ans, num[i].first - cubeta[sum]);
			}
		}
		
		sum -= num[i].second;
		if(cubeta.find(sum) == cubeta.end())
			cubeta[sum] = num[i].first;
		sum += num[i].second;
	}
	cout << ans << endl;
	return 0;
}