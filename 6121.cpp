#include <iostream>
#define N_MAX 100000
using namespace std;

int N, M;
int cost[N_MAX];

bool is_possible(int mid){
  int remain = mid;
  int count = 1;
  for(int ndx = 0; ndx < N-1; ndx++){
      remain -= cost[ndx];
      if(remain < cost[ndx + 1]){
        remain = mid;
        count += 1;
      }
  }
  return (count <= M);
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  int start = 0;
  int end = 0;
  for(int ndx = 0; ndx < N; ndx++){
    cin >> cost[ndx];
    end += cost[ndx];
    start = (start > cost[ndx])? start : cost[ndx];
  }
  int ans = 0;

  while(start <= end){
    int mid = (start + end) / 2;

    if(is_possible(mid)){
      ans = mid;
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  cout << ans << endl;

}
