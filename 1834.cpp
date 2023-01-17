#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;
int candy[5000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  for(int ndx = 0; ndx < N; ndx++){
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }
  int cost = 0;
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    pq.push(a + b);
    cost += (a + b);
  }
  cout << cost;
}
