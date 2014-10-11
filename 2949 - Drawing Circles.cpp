#include <bits/stdc++.h>

using namespace std;

#define MAXN 202
#define MARGEN 100

int puntos[MAXN][MAXN];
vector< pair <int, int > >  points[11];
bool muerto[11][MAXN * MAXN];



int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a += MARGEN;
		b += MARGEN;
		puntos[a][b] = max(puntos[a][b], c);
	}
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			if(puntos[i][j]){
				points[puntos[i][j]].push_back(make_pair(i, j));
			}
		}
	}
	int ans = 0;
	for(int i = 10; i > 0; i--){
		for(int k = 0; k < points[i].size(); k++){
			if(muerto[i][k])
				continue;
			for(int j = i - 1; j > 0; j--){
				for(int p = 0; p < points[j].size(); p++){
					if((points[i][k].first - points[j][p].first) * (points[i][k].first - points[j][p].first) + (points[i][k].second - points[j][p].second) * (points[i][k].second - points[j][p].second) <= (i - j) * (i - j)){
						muerto[j][p] = true;
					}
				}
			}
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}