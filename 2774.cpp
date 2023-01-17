#include <iostream>
#include <cstring>
using namespace std;

int N, Q;
int D[50001];
int prefix_sum[50001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N >> Q;
  memset(prefix_sum, 0, sizeof(prefix_sum));

  for(int ndx = 1; ndx <= N; ndx++){
    cin >> D[ndx];
    prefix_sum[ndx] = prefix_sum[ndx - 1] + D[ndx];
  }

  int start, end;
  for(int qdx = 0; qdx < Q; qdx++){
    cin >> start >> end;
    cout << prefix_sum[end] - prefix_sum[start - 1] << '\n';
  }
  return 0;
}
