#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX_N (300000)

int N, K;
queue<int> rank_strlen[21];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long sol = 0;

	cin >> N >> K;
  string input;
  for(int ndx = 0; ndx < N; ndx++){
    cin >> input;
    int input_len = input.length();

    while(!rank_strlen[input_len].empty() && (ndx - rank_strlen[input_len].front()) > K)
      rank_strlen[input_len].pop();

    sol += rank_strlen[input_len].size();
    rank_strlen[input_len].push(ndx);
  }

	// 출력하는 부분
	cout << sol << '\n';

	return 0;
}
