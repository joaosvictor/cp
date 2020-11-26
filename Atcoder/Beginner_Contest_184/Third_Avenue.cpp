#include "bits/stdc++.h"
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all> 
using namespace atcoder;
using ll = long long;
 
template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 
int main(){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for(int i=0; i<H; i++) cin >> a[i];
 
  using P = pair<int, int>;
  P s, g;
  // using PP = pair<P, P>;
  // vector<PP> tele(26);
  vector<vector<P>> tele(26);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(a[i][j] == 'S') s = P(i, j);
      else if(a[i][j] == 'G') g = P(i, j);
      else if(a[i][j] == '#') continue;
      else if(a[i][j] == '.') continue;
      else{ 
        int num = a[i][j] - 'a';
        tele[num].push_back(P(i, j));
      }
    }
  }
  // cout << " a: " << endl; for(string sss: a) cout << sss << endl;
  // cout << " s: (" <<s.first << ", "<<s.second << "),  g: (" << g.first << ", "<< g.second << ")" << endl;
  // cout << " tele: " << endl; for(int i=0; i<26; i++){ cout << char(i+'a') << "   "; {for(P p: tele[i]) cout << "(" << p.first << ", " << p.second << "),   ";  cout <<  endl;}}
  //BFS
  const int INF = 1e8+5;
  vector<vector<int>> dist(H, vector<int>(W, INF));
  dist[s.first][s.second] = 0;
  int dh[4] = {-1, 0, 1, 0};
  int dw[4] = {0, -1, 0, 1};
  queue<P> qu;
  qu.push(s);
  while(!qu.empty()){
    int h = qu.front().first;
    int w = qu.front().second;
    qu.pop();
    if(dist[g.first][g.second]!=INF  &&  dist[g.first][g.second] <= dist[h][w]+1) continue; 
    for(int i=0; i<4; i++){
      int nh = h + dh[i];
      int nw = w + dw[i];
      // cout <<" i: " << i << " (h, w)=(" << h << ", " << w << "),  (nh, nw)=(" <<nh << ", "<< nw << ") " << endl;
      if(nh<0 || H<=nh) continue;
      if(nw<0 || W<=nw) continue;
      if(a[nh][nw] == '#') continue;
      if(dist[nh][nw] <= dist[h][w]+1) continue;
      dist[nh][nw] = dist[h][w] + 1;
      if(a[nh][nw] == 'G') continue;
      qu.push(P(nh, nw));
    }
 
    int num = (int)a[h][w] - (int)'a';
    if(num < 0  ||  26<= num) continue;
    for(P p : tele[num]){
      int nh = p.first;
      int nw = p.second;
      // cout << a[h][w] << ": num: " << " (h, w)=(" << h << ", " << w << "),  (nh, nw)=(" <<nh << ", "<< nw << ") " << endl;
      if(dist[nh][nw] <= dist[h][w]+1) continue;
      dist[nh][nw] = dist[h][w] + 1;
      qu.push(P(nh, nw));
    }
  }
 
  if(dist[g.first][g.second] == INF) cout << -1 << endl;
  else cout << dist[g.first][g.second] << endl;
  return 0;
 
}
