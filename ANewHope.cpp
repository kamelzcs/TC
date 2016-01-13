#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

struct ANewHope {
  vector<int> firstWeek;
  vector<int> lastWeek;
  map<int, int> dict;
  int D;
  int func(int start, int target, int N, int D) {
    if (N - 1 - start + target + 1 >= D) {
      return 1;
    }
    return 1 + func((start + D) % N, target, N, D);
  }
  int count(vector<int> _firstWeek, vector<int> _lastWeek, int _D) {
    firstWeek = _firstWeek, lastWeek = _lastWeek, D = _D;
    if (firstWeek == lastWeek) {
      return 1;
    }
    int ans = -1;

    for (int i = 0; i < lastWeek.size(); i++) {
      dict[lastWeek[i]] = i;
    }

    for (int i = 0; i < firstWeek.size(); i++) {
      ans = max(ans, func(i, dict[firstWeek[i]], firstWeek.size(), D));
    }
    return ans + 1;
  }
};

// CUT begin
ifstream data("ANewHope.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(vector<int> firstWeek, vector<int> lastWeek, int D, int __expected) {
    time_t startClock = clock();
    ANewHope *instance = new ANewHope();
    int __result = instance->count(firstWeek, lastWeek, D);
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
        vector<int> firstWeek;
        from_stream(firstWeek);
        vector<int> lastWeek;
        from_stream(lastWeek);
        int D;
        from_stream(D);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(firstWeek, lastWeek, D, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1452688450;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ANewHope (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
