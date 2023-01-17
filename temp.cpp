#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_M ((int)1e5)
#define MAX_N ((int)1e5)

int M, N, L;//사대수, 동물수, 사거리
int shoot[MAX_M];
struct POS {
    int x;
    int y;
};
POS animal[MAX_N];

void InputData() {
    cin >> M >> N >> L;
    for (int i = 0; i < M; i++) {
        cin >> shoot[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> animal[i].x >> animal[i].y;
    }
}

int BS_Lower(int s, int e, int d) {//d보다 크거나 같은 값중에 제일 작은 인덱스
    int sol = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (shoot[m] >= d) {
            sol = m; e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return sol;
}

int Solve() {
    int cnt = 0;

    //1.사대 오름차순 정렬
    sort(shoot, shoot + M);

    //2.동물 기준으로 탐색
    for (int i = 0; i < N; i++) {
        if (animal[i].y > L) continue; //무조건 못잡음
        int rs = animal[i].x - (L - animal[i].y);
        int re = animal[i].x + (L - animal[i].y);
        int idx = BS_Lower(0, M - 1, rs);
        if ((idx < 0) || (shoot[idx] > re)) continue; //못잡음
        cnt++;
        cout << i << " possible\n";
    }

    return cnt;
}

int main() {
    InputData();
    int ans = Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}
