#include <iostream>
#include <queue>
#define MAX_Q 100000
using namespace std;
typedef pair<int, int> interval;

struct compare{
  bool operator()(interval a, interval b){
    if(a.first- a.second != b.first - b.second)
      return (a.first - a.second) > (b.first - b.second);
    else
      return a.first > b.first;
  }
};

priority_queue<interval, vector<interval>, compare> seat;
int M, N, Q;
int input;
int pos[MAX_Q + 1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> M >> N >> Q;
  int start = 1, end = M, count = 0;
  for(int ndx = 0; ndx < N; ndx++){
    cin >> input;
    pos[++count] = input;
    if(start <= input - 1)
      seat.push({start, input -1});
    start = input + 1;
  }
  if(start <= end)
    seat.push({start, end});

  for(int qdx = 0; qdx < Q; qdx++){
    cin >> input;
    if(count >= input){
      cout << pos[input] << " ";
      continue;
    }

    int mid;
    while(count != input){
        interval curr = seat.top(); seat.pop();
        mid = (curr.first + curr.second) / 2;
        if(curr.first <= mid - 1)
          seat.push({curr.first, mid - 1});
        if(mid + 1 <= curr.second)
          seat.push({mid + 1, curr.second});
        count++;
    }
    cout << mid << " ";
  }
}
