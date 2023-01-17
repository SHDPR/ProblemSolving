#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string input_str;
  int N;

  cin >> input_str >> N;
  list<char> editor = list<char>(input_str.begin(), input_str.end());
  auto cursor = editor.end();

  for(int ndx = 0; ndx < N; ndx++){
    char cmd, ch;
    cin >> cmd;
    switch(cmd){
      case 'L':
        if(cursor != editor.begin())
          cursor = prev(cursor);
        break;
      case 'D':
        if(cursor != editor.end())
          cursor = next(cursor);
        break;
      case 'B':
        if(cursor != editor.begin())
          cursor = editor.erase(prev(cursor));
        break;
      case 'P':
        cin >> ch;
        cursor = next(editor.insert(cursor, ch));
        break;
    }
  }

  for(char ch : editor)
    cout << ch;
}
