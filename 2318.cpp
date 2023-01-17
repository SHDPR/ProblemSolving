#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> deck;

void Input_Data(void) {
    cin >> N;
}

int Simulation(void) {
    for (int i = 1; i <= N;i++) {
        deck.push_back(i);
    }

    for (int i = 0; i < N - 1;i++) {
        int cnt = deck.back() / 2;
        for (int j = 0; j < cnt;j++) {
            deck.push_back(deck.front());
            deck.pop_front();
        }
        cout << deck.front() << ' ';
        deck.pop_front();
    }
    cout << deck.front() << ' ';
    deck.pop_front();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input_Data();

    Simulation();

    return 0;
}
