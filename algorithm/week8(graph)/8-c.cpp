// *
// 문제
// 욱제는 세계적인 인기를 자랑하는 월클(World Class) 스타이다! 영선이는 욱제TV 구독자 5조5억명 달성 기념 파티를 준비하고 있다. 
// 영선이는 욱제를 아는 수많은 사람들에게 초대장을 돌렸는데, 초대장을 받은 모든 사람들이 자신이 언제 와서 언제 떠날 것인지 답변을 줬다.
// 욱제는 월클병에 걸려서 기대에 미치지 않는 인원과 파티를 즐기는 것을 용납하지 않는다. 그래서 욱제는 자신을 제외한 파티 인원이 T명 미만이 되는 순간 파티장에서 나가고, 
// 파티 인원이 T명 이상이 되는 순간 다시 돌아온다. 답변을 정리하던 영선이는 충격적인 사실을 깨달았는데, 파티가 진행되는 동안 T명 이상의 인원이 계속 유지되지 못 한다는 것이다. 
// 그래서 영선이는 급히 자신의 친구들 K명을 부르려고 한다.

// 영선이의 친구들은 부끄럼이 많아서 욱제 및 영선이의 친구들을 제외한 파티 인원이 T명 이상이 되는 순간 다 같이 파티장에서 나가 버리고 돌아오지 않는다. 
// 또한 파티 인원이 T명 이상이면 영선이의 친구들은 파티장에 들어가지 않는다. 
// 단, 아직 들어오지 않은 영선이의 친구들은 이후 파티 인원이 T명 미만이 되면 파티장으로 들어 갈 수 있다. 
// 영선이는 친구들 각각을 적절한 시각에 투입시켜 최대한 오랫동안 욱제가 파티에 머물도록 하고 싶다. 꼭 K명을 모두 투입시킬 필요는 없다. 
// 영선이는 욱제를 얼마나 오래 파티에 머물게 할 수 있을까?

// 입력
// 첫째 줄에 파티가 진행되는 시간 N (1 ≤ N ≤ 300), 파티에 초대한 사람 수 M (1 ≤ M ≤ 300), 영선이의 친구 수 K (1 ≤ K ≤ 300), 욱제가 기대하는 최소의 파티 인원 T (1 ≤ T ≤ M)가 주어진다.
// 둘째 줄부터 M개의 줄에 걸쳐 각 줄마다 ai, bi가 주어진다. i번째 사람은 시각 ai에 파티에 참여하고, 시각 bi에 파티를 떠난다. (1 ≤ ai ≤ N, ai < bi ≤ N + 1)
// 파티가 시작되는 시각은 1을 기준으로 한다.

// 출력
// 영선이의 친구들을 파티에 투입시켰을 때 욱제가 파티에 머무를 수 있는 최대 시간을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, dp[304][304], a, b, cnt[304];
vector<pair<int, int>> v;

int go(int idx, int friends, int prev) {        // prev 는 이전 차수에 필요했던 영선이 친구 수, friends 는 현재 가용한 친구 수
    if (idx == v.size()) return 0;              // 이 go 함수는 v 벡터 사이즈만큼만 반복, idx는 결국 v벡터의 idx
    if (dp[idx][friends]) return dp[idx][friends];
    
    int cost = max(0, t-v[idx].second);     // 최소인원보다 현재 인원이 적으면 그 수가 이번 차수에 필요한 친구 수
    int realCost = prev >= cost ? 0 : cost;     // 이번 차수에 필요한 친구수가 저번 차수의 영선이 친구로 충당 가능하면 이번차수에 진짜 필요한 realCost는 0 아니면 cost
    int &ret = dp[idx][friends];
    if (friends >= realCost) {      // 이번 차수에 영선이 친구를 투입하는 경우와 투입하지 않는 경우, 두가지가 있음
        return ret = max(go(idx+1, friends-realCost, cost)+v[idx].first, go(idx+1, friends, 0));
    }else return ret = go(idx+1, friends, 0);   // 이 경우는 영선이 친구수가 부족해서 투입 못함
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> t;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        for (int j=a; j<b; j++) {
            cnt[j] = min(t, ++cnt[j]);  //  cnt[j] j시에 있는 사람수, min(t, )을 걸면 파티장에 있어야하는 최소한의 인원수 t를 초과할 수 없음, 밑에서 체크를 위해 필요 
        }
    }

    int temp = cnt[1];                      // 파티가 시작됐다. 즉 인원수가 t라는 뜻
    int interval = 1;
    for (int i=2; i<=n; i++) {              // dp를 위해서 벡터 v를 미리 만들어둠
        if (temp != cnt[i]) {               // 위에서 cnt[j] = min(t, ++cnt[j]) 한것은 여기를 위함, 즉 최소인원이 안된다는 뜻
            v.push_back({interval, temp});  // 현재까지의 시간 interval을 저장해주고, 현재 인원수를 같이 저장, 이 인원수를 채우면 욱제가 머무는 시간인 interval이 늘어나는것
            interval = 0;
            temp = cnt[i];
        }
        interval++;
    }

    cout << go(0, k, 0) << "\n";
    return 0;
}

// 핵심은 v벡터를 만드는것
// v벡터 요소 {interval, temp} 의 의미는 t-temp 명을 투입하면 interval 시간을 욱제가 머무른다는 뜻
// 현재까지의 시간 interval과 최소인원이 안되는 현재 인원수를 같이 저장
// 이러한 pair가 저장되있기 때문에 얘들을 순회하면서 현재인원을 최소 인원만큼 투입시키면서 
// 최대가 되는 interval을 찾는것

// dp[idx][friends], 현재 인덱스idx에 가용한 친구수friends에 해당하는 파티 시간
// 이 디피를 걸기 위해서 v벡터를 미리 세팅해야함
// 벡터 v는 interval 동안 파티에 머무는 사람의 수를 pair 로 저장함

// 이제 그 벡터를 순회하면서 해당 차수(idx)에 필요한 영선이 친구수를 투입하거나 하지 않으면서
// 영선이 친구를 투입하면 해당 차수의 시간을 더하면서 재귀적으로 go를 호출하고
// 투입 안하면 그냥 다음 차수를 재귀적으로 호출하면서
// 욱제가 최대한 머무는 시간을 구해줌