#include <bits/stdc++.h>
using namespace std;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

#define rrep(i,a,b) for (ll i = (a); i >= ll(b); i--)
#define cauto const auto&
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vld = vector<long double>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template <class T, class U>
bool chmin(T& a, const U& b) {return (b < a) ? (a = b, true) : false;}
template <class T, class U>
bool chmax(T& a, const U& b) {return (b > a) ? (a = b, true) : false;}
void in() {}
void printMatrix(const auto &vec){for(const auto &v : vec){ for(const auto &e : v){cerr << e << " ";}cerr << endl;}}
template<class T> void printTable(const vector<vector<T>> &tb){ for(const auto &i : tb){ for(const auto &j : i){cerr << j << " ";}cerr << endl;}}
template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
    cin >> head;
    in(std::forward<Tail>(tail)...);
}
const ll INF = 1LL << 60;
const ll mod = 998244353;

// 時間管理
class TimeKeeperDouble {
private:
	std::chrono::high_resolution_clock::time_point start_time_;
	double time_threshold_;
	double now_time_ = 0;
public:
	TimeKeeperDouble(const double time_threshold)
		: start_time_(std::chrono::high_resolution_clock::now()),
		time_threshold_(time_threshold) {}
	void setNowTime() {
		auto diff = std::chrono::high_resolution_clock::now() - this->start_time_;
		this->now_time_ = std::chrono::duration_cast<std::chrono::microseconds>(diff).count() * 1e-3;
	}
	double getNowTime() const { return this->now_time_; }
	bool isTimeOver() const { return now_time_ >= time_threshold_; }
};
class Random {
public:
	std::mt19937 mt_;
	// [0,1.0)
	std::uniform_real_distribution<double> dd_{ 0.0, 1.0 };

	// seedを指定して初期化
	Random(const int seed = 0) : mt_(std::mt19937(seed)) {}

	// [0,m)の整数の範囲の乱数
	int nextInt(const int m) {
		return rand() % m;
	}
	// [n,m)の整数の範囲の乱数
	inline int nextInt(const int n, const int m) {
		return nextInt(m - n) + n;
	}
	// [0,1.0)
	double nextDouble() { return dd_(mt_); }
	// [0,1.0)
	double nextLog() { return log(dd_(mt_)); }
};
namespace constant {
	constexpr bool LOCAL_INOUT = false;
	constexpr bool LOCAL_DEBUG = false;
	constexpr int TIME_LIMIT = 1950; //制限時間が2sec
	constexpr int N = 1000; //注文の総数
	constexpr int M = 50;   //1000件から選ぶ部分集合の要素数
	constexpr int CENTER = 400; //headquarters
	constexpr int INF = 1e9;
}
struct Position {
	int x, y;
	Position() {};
	Position(int x, int y) :x(x), y(y) {}
	constexpr int dist(const Position & other) {
		return abs(x - other.x) + abs(y - other.y);
	}
	void output() {
		std::cout << x << " " << y;
	}
};
struct Input {
	std::vector<Position> data;
	Input() {}
	void readData() {
		data.resize(constant::N * 2 + 1);
		for (int i = 0; i < constant::N; ++i) {
			int rx, ry, dx, dy;
			std::cin >> rx >> ry >> dx >> dy;
			data[i] = Position(rx, ry);
			data[i + constant::N] = Position(dx, dy);
		}
		data[constant::N * 2] = Position(constant::CENTER, constant::CENTER);
	}
};
struct Insert {
	Insert() : cost(constant::INF) {}
	int cost;
	int l, r, index;
};
struct State {
	std::vector<bool>used;
	std::vector<int>answer;
	int cost;
	State() {
		used.resize(constant::N);
	}
	void insert(Insert &insert) {
		answer.insert(answer.begin() + insert.r, insert.index + constant::N);
		answer.insert(answer.begin() + insert.l, insert.index);
		used[insert.index] = true;
	}
};
class Solver {
public:
	Solver(Input input) :input(input) {}
	void run(const double start_temp = 100, const double end_temp = 0) {
		greedy();
		// int counter = 0;
		// auto nowState = bestState;
		// while (true) {
		// 	time_keeper.setNowTime();
		// 	if (time_keeper.isTimeOver())break;
		// 	auto tmpState = nowState;

		// 	if (0 != counter % 10) {
		// 		replace(tmpState);
		// 	}
		// 	else {
		// 		two_opt(tmpState);
		// 	}
		// 	int diff = tmpState.cost - nowState.cost;
		// 	double temp = start_temp + (end_temp - start_temp) * (time_keeper.getNowTime() / constant::TIME_LIMIT);
		// 	double diff_threshold = temp * rnd.nextLog();
		// 	if (-diff > diff_threshold) {
		// 		nowState = tmpState;
		// 		if (diff < 0) {
		// 			bestState = tmpState;
		// 		}
		// 	}
		// 	counter++;
		// }
		// if (constant::LOCAL_DEBUG) {
		// 	std::cout << "result:" << bestState.cost << std::endl;
		// 	std::cout << "counter:" << counter << std::endl;
		// }
	}
	void output() {
		std::vector<int> v;
		for (auto e : bestState.answer) {
			if (e < constant::N)v.push_back(e);
		}
		std::cout << v.size() << " ";
		for (auto e : v) std::cout << e + 1 << " ";
		std::cout << std::endl;

		std::cout << bestState.answer.size() << " ";
		for (auto e : bestState.answer) {
			input.data[e].output();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
private:
	Input input;
	State bestState;
	TimeKeeperDouble time_keeper = TimeKeeperDouble(constant::TIME_LIMIT);
	Random rnd;
	void greedy() {
		std::set<int>st;
		for (int i = 0; i < constant::N; ++i) {
			st.insert(i);
		}
		State state;
		state.answer.push_back(constant::N * 2);
		state.answer.push_back(constant::N * 2);
		for (int i = 0; i < constant::M; ++i) {
			Insert bestInsert;
			for (int j = 0; j < constant::N; ++j) {
				if (state.used[j])continue;
				auto ins = insert(state.answer, j);
				if (ins.cost < bestInsert.cost) {
					bestInsert = ins;
				}
			}
			int index = bestInsert.index;
			state.insert(bestInsert);
		}
		bestState = state;
		bestState.cost = calcCost(state.answer);
		if (constant::LOCAL_DEBUG) {
			std::cout << "Greedy:" << bestState.cost << std::endl;
		}
	}
	Insert insert(std::vector<int>&vec, int target) {
		std::vector<int> l(vec.size()), l_idx(vec.size());
		l[0] = constant::INF;
		std::vector<int>lr_index(vec.size());
		for (int i = 1; i < vec.size(); ++i) {
			int dist = getDist(vec[i - 1], target);
			dist += getDist(target, vec[i]);
			dist -= getDist(vec[i - 1], vec[i]);
			if (dist < l[i - 1]) {
				l[i] = dist;
				l_idx[i] = i;
			}
			else {
				l[i] = l[i - 1];
				l_idx[i] = l_idx[i - 1];
			}
		}
		std::vector<int> r(vec.size()), r_idx(vec.size());
		r.back() = constant::INF;
		for (int i = vec.size() - 1; i > 0; --i) {
			int dist = getDist(vec[i - 1], target + constant::N);
			dist += getDist(target + constant::N, vec[i]);
			dist -= getDist(vec[i - 1], vec[i]);
			if (dist < r[i]) {
				r[i - 1] = dist;
				r_idx[i - 1] = i;
			}
			else {
				r[i - 1] = r[i];
				r_idx[i - 1] = r_idx[i];
			}
		}
		Insert ret;
		for (int i = 1; i < vec.size() - 1; ++i) {
			if (l[i] + r[i] < ret.cost) {
				ret.cost = l[i] + r[i];
				ret.l = l_idx[i];
				ret.r = r_idx[i];
				ret.index = target;
			}
		}
		for (int i = 1; i < vec.size(); ++i) {
			int dist = getDist(vec[i - 1], target);
			dist += getDist(target, target + constant::N);
			dist += getDist(target + constant::N, vec[i]);
			dist -= getDist(vec[i - 1], vec[i]);
			if (dist < ret.cost) {
				ret.cost = dist;
				ret.l = i;
				ret.r = i;
				ret.index = target;
			}
		}
		return ret;
	}

	int getDist(int i, int j) {
		return input.data[i].dist(input.data[j]);
	}
	int calcCost(const std::vector<int> &route) {
		int cost = 0;
		for (int i = 0; i < route.size() - 1; ++i) {
			cost += input.data[route[i]].dist(input.data[route[i + 1]]);
		}
		return cost;
	}
	void two_opt(State &state) {
		auto[l, r] = randSelect();

		int delta = getDist(state.answer[l - 1], state.answer[r]) + getDist(state.answer[l], state.answer[r + 1]);
		delta -= getDist(state.answer[l - 1], state.answer[l]) + getDist(state.answer[r], state.answer[r + 1]);

		int start_temp = 10;
		int end_temp = 0;
		double temp = start_temp + (end_temp - start_temp) * (time_keeper.getNowTime() / constant::TIME_LIMIT);
		double diff_threshold = temp * rnd.nextLog();
		if (delta >= diff_threshold) return;
		std::set<int> seen;
		for (int i = l; i <= r; i++) {
			if (state.answer[i] < constant::N) seen.insert(state.answer[i]);
			else if (seen.count(state.answer[i] - constant::N)) return;
		}

		std::reverse(state.answer.begin() + l, state.answer.begin() + r + 1);
		state.cost += delta;
	}
	void replace(State &state) {
		int remove = state.answer[rnd.nextInt(1, constant::M * 2 + 1)] % constant::N;
		state.answer.erase(state.answer.begin() + get_index(state.answer, remove));
		state.answer.erase(state.answer.begin() + get_index(state.answer, remove + constant::N));

		std::vector<int> candidates;
		while (candidates.size() < 5) {
			int i = rnd.nextInt(constant::N);
			if (!state.used[i] && !exist(candidates, i)) {
				candidates.push_back(i);
			}
		}

		Insert bestIns = Insert();
		for (auto candidate : candidates) {
			auto ret = insert(state.answer, candidate);
			if (ret.cost < bestIns.cost) {
				std::swap(bestIns, ret);
			}
		}
		int val = bestIns.index;
		state.answer.insert(state.answer.begin() + bestIns.r, val + constant::N);
		state.answer.insert(state.answer.begin() + bestIns.l, val);
		int newCost = calcCost(state.answer);
		int delta = newCost - state.cost;

		state.used[remove] = false;
		state.used[bestIns.index] = true;
		state.cost = newCost;
	}
	template <class T>
	int exist(std::vector<T>& data, T element) {
		return !(get_index(data, element) == data.size());
	}
	template <class T>
	int get_index(std::vector<T>& data, T element) {
		return distance(data.begin(), find(data.begin(), data.end(), element));
	}
	std::pair<int, int>randSelect() {
		while (true) {
			int l = rnd.nextInt(1, constant::M * 2 + 1);
			int r = rnd.nextInt(1, constant::M * 2 + 1);
			if (l == r)continue;
			if (l > r)std::swap(l, r);
			return { l,r };
		}
	}
};
// https://atcoder.jp/contests/ahc006/submissions/29167700
void local() {
#pragma warning(disable : 4996)
	FILE *in = freopen("../../../../017_ahc/001_010/006/in.txt", "r", stdin);
	//FILE *out = freopen("../../../../017_ahc/001_010/001out.txt", "w", stdout);
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	if (constant::LOCAL_INOUT)local();
	Input input;
	input.readData();
	Solver solver(input);
	solver.run();
	solver.output();
	return 0;
}
