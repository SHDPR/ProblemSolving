#include <iostream>
#include <queue>
using namespace std;

int N, input;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  int count = 0;
  for(int ndx = 0; ndx < N; ndx++){
    int min_size = min_heap.size();
    int max_size = max_heap.size();
    cin >> input;
    count += 1;

    if(min_size < max_size)
      min_heap.push(input);
    else
      max_heap.push(input);

    while(max_size != 0 && min_heap.top() < max_heap.top()){
      int max_tmp = max_heap.top(); max_heap.pop();
      int min_tmp = min_heap.top(); min_heap.pop();
      min_heap.push(max_tmp);
      max_heap.push(min_tmp);
    }
    if(count % 2 == 1)
      cout << max_heap.top() << endl;
  }
}
