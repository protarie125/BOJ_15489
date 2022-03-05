#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

vvl tri;

ll choose(int r, int c) {
	if (1 == c) {
		return 1;
	}

	if (2 == c) {
		return r - 1;
	}

	auto ans = ll{ 1 };
	auto p = r - 1;
	auto q = c - 1;
	if (p / 2 < q) {
		q = p - q;
	}
	auto q2 = q;
	for (int i = 0; i < q; ++i) {
		ans *= p;
		p -= 1;
	}

	for (int i = 0; i < q; ++i) {
		ans /= q2;
		q2 -= 1;
	}

	return ans;
}

ll solve(int r, int c, int w) {
	if (1 == w) {
		if (tri[r][c] < 0) {
			tri[r][c] = choose(r, c);
		}

		return tri[r][c];
	}

	auto ans = ll{ 0 };
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j <= i; ++j) {
			ans += solve(r + i, c + j, 1);
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int r, c, w;
	cin >> r >> c >> w;

	tri = vvl(r + w + 1, vl(r + w + 1, -1));
	cout << solve(r, c, w);

	return 0;
}