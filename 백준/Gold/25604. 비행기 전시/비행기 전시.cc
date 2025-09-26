#include <bits/stdc++.h>
using namespace std;
int n, m, t, now, here, weight, done[2][1004], flag[2], last[2];
struct Boo {
    int d, m, r, i;
};
vector<Boo> v[2];
vector<pair<int, int>> ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        int d, mm, r;
        cin >> d >> mm >> r;
        v[d].push_back({d, mm, r, i});
    }
    ret.assign(n, {0, 0});

    // 각 측면에서 다음에 처리할 인덱스 (입력은 전체 r 비내림, 한쪽도 순서 유지됨)
    int idx[2] = {0, 0};
    now = 0; here = 0; weight = 0;
    int finished = 0;

    auto remainCnt = [&](int side){ return (int)v[side].size() - idx[side]; };

    while(finished < n) {
        // 현재 위치에서, 준비된 부품을 번호순으로 최대한 적재(필요 시 분할)
        while(idx[here] < (int)v[here].size() && v[here][idx[here]].r <= now && weight < m) {
            Boo &p = v[here][idx[here]];
            if(ret[p.i].first == 0) ret[p.i].first = now;

            int take = min(m - weight, p.m);
            weight += take;
            p.m -= take;
            if(p.m == 0) {
                // 이번 이동으로 완전히 운송됨 => 도착 시간은 now + t
                ret[p.i].second = now + t;
                idx[here]++;
                finished++;
            } else {
                // 트럭 가득 참 -> 즉시 출발
                break;
            }
        }

        // 출발 조건: (1) 트럭이 가득 찼거나 (2) 적재량이 있고 더 실을 게 없으면 출발
        bool canLoadHereNow = (idx[here] < (int)v[here].size() && v[here][idx[here]].r <= now);
        if(weight == m || (weight > 0 && !canLoadHereNow)) {
            now += t;
            here ^= 1;
            weight = 0;
            continue;
        }

        if(weight == 0) {
            // 아무것도 실리지 않은 상태 -> 대기/이동 규칙
            int other = here ^ 1;
            int nextHere = (idx[here] < (int)v[here].size() ? v[here][idx[here]].r : INT_MAX);
            int nextThere = (idx[other] < (int)v[other].size() ? v[other][idx[other]].r : INT_MAX);

            if(nextHere == INT_MAX && nextThere == INT_MAX) break; // 종료

            if(remainCnt(here) == 0 && remainCnt(other) > 0) {
                // 현재 측면 끝 -> 바로 반대로 이동해서 거기서 대기
                now += t;
                here = other;
                continue;
            }

            if(nextHere <= nextThere) {
                // 현재 위치 먼저(동일 시 현재 우선)
                if(nextHere > now) now = nextHere;
                continue;
            } else {
                // 반대편이 더 먼저 준비됨: 그 시각까지 기다렸다가 이동 시작
                if(nextThere > now) now = nextThere;
                now += t;
                here = other;
                continue;
            }
        }
        // 그 외의 경우는 루프 상단에서 다시 적재 시도
    }

    for(auto ans : ret) cout << ans.first << " " << ans.second << "\n";

    return 0;
}