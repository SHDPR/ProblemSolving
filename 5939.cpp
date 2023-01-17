#include <iostream>
#include <deque>
#include <string>

using namespace std;

#define MAX_N (500000)

int N, K;
string input;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    cin >> input;

    deque<char> program;

    for(int idx = 0; idx < N; idx++){
        while(!program.empty() && K != 0 && program.back() < input[idx]){
          program.pop_back();
          K -= 1;
        }
        program.push_back(input[idx]);
    }

    for(int kdx = 0; kdx < K; kdx++)
      program.pop_back();

    for(auto el: program)
      cout << el;

    return 0;
}
