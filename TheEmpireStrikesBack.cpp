#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

  static const int MOD = 1000000007;

struct TheEmpireStrikesBack {
  int AX;
  int BX;
  int CX;
  int AY;
  int BY;
  int CY;
  int N;
  int M;
  vector<pair<LL, LL> > P;
  stack<pair<LL, LL> > stk;
  bool valid(int T) {
    int used = 0;
    for (int i = 0; i < P.size(); ) {
      int start = i;
      int nxt = start + 1;
      while(nxt < P.size()) {
        if (P[nxt].second < P[start].second - T) {
          break;
        }
        nxt++;
      }

      int center = nxt - 1;
      while(nxt < P.size()) {
        if (P[nxt].first > P[center].first + T) {
          break;
        }
        nxt++;
      }

      i = nxt;
      used++;
    }
    return used <= M;
  }
  int find(int _AX, int _BX, int _CX, int _AY, int _BY, int _CY, int _N, int _M) {
    AX = _AX, BX = _BX, CX = _CX, AY = _AY, BY = _BY, CY = _CY, N = _N, M = _M;
    P.push_back(make_pair(AX, AY));
    for (int i = 1; i < N; i++) {
      LL x = ((P[i-1].first * BX) + CX) % MOD;
      LL y = ((P[i-1].second * BY) + CY) % MOD;
      P.push_back(make_pair(x, y));
    }

    sort(P.begin(), P.end());
    for (int i = 0; i < N; i++) {
      int y = P[i].second;
      while(!stk.empty() && y >= stk.top().second) {
        stk.pop();
      }
      stk.push(P[i]);
    }

    P.clear();
    while(!stk.empty()) {
      P.push_back(stk.top());
      stk.pop();
    }

    reverse(P.begin(), P.end());

    int left = 0, right = MOD;
    while(left <= right) {
      int mid = left + (right -left) / 2;
      if (!valid(mid)) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }

    return left;
  }
};

// CUT begin
ifstream data("TheEmpireStrikesBack.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int AX, int BX, int CX, int AY, int BY, int CY, int N, int M, int __expected) {
    time_t startClock = clock();
    TheEmpireStrikesBack *instance = new TheEmpireStrikesBack();
    int __result = instance->find(AX, BX, CX, AY, BY, CY, N, M);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int AX;
        from_stream(AX);
        int BX;
        from_stream(BX);
        int CX;
        from_stream(CX);
        int AY;
        from_stream(AY);
        int BY;
        from_stream(BY);
        int CY;
        from_stream(CY);
        int N;
        from_stream(N);
        int M;
        from_stream(M);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(AX, BX, CX, AY, BY, CY, N, M, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1452690926;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TheEmpireStrikesBack (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
