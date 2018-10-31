#include <iostream>
#include <vector>
#include <map>

using namespace std;

const double eps = 0.001;
class point {
public:
	double x, y;
	point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
};

class line {
public:
	double slope;
	double yintersect;
	bool vertical;
	line(double s = 0, double y = 0, bool v = false) : slope(s), yintersect(y), vertical(v) {}
};

double dabs(double a) {
	if (a > 0) return a;
	else return -a;
}

bool equals(double x, double y) {
	if (dabs(x - y) < eps) return true;
	else return false;
}

line mkline(point a, point b) {
	if (equals(b.x, a.x)) return line(a.x, 0, 1);
	double slope = (b.y - a.y) / (b.x - a.x);
	double yintersect = a.y - slope * a.x;
	return line(slope, yintersect);
}

int hash(line l, map<int, int> &m) {
	int slope = l.slope / eps;
	int yintersect = l.yintersect / eps;
	int hashcode = l.vertical ? slope | yintersect : slope ^ yintersect;
	if (m.find(hashcode) != m.end()) m[hashcode]++;
	else m[hashcode] = 1;
	return m[hashcode];
}

int main() {
	for (int n; scanf("%d", &n) != EOF && n != 0;) {
		vector<point> p(n);
		map<int, int> m;
		int linearity = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for (int i = 0; i < n; ++i) {
			m = map<int, int>();
			for (int j = i + 1; j < n; ++j) {
				linearity = max(linearity, hash(mkline(p[i], p[j]), m));
			}
		}
		printf("%d\n", linearity + 1);
	}
	return 0;
}
