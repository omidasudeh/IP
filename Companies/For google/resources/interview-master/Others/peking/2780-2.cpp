#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    int x1, y1, x2, y2;
    bool vertical;
    double slope, intercept;
    
    void initialize(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        
        if (x1 == x2) {
            vertical = true;
        }
        else {
            vertical = false;
            slope = 1.0 * (y1 - y2) / (x1 - x2);
            intercept = 1.0 * y1 - slope * x1;
        }
    }
};

const double eps = 1e-4;

bool compare(Line* const &a, Line* const &b) {
    if (a->vertical && b->vertical) return a->x1 < b->x1;
    if (a->vertical) return false;
    if (b->vertical) return true;
    if (abs(a->slope - b->slope) < eps)
        return a->intercept < b->intercept;
    return a->slope < b->slope;
}

bool equals(Line* const &a, Line* const &b) {
    if (a->vertical && b->vertical) return a->x1 == b->x1;
    if (a->vertical || b->vertical) return false;
    if (abs(a->slope - b->slope) < eps)
        return abs(a->intercept - b->intercept) < eps;
    return false;
}

const int MAXN = 1000;
int X[MAXN], Y[MAXN];

Line lines[MAXN];
int p = 0;

Line* newLine(int x1, int y1, int x2, int y2) {
    lines[p].initialize(x1, y1, x2, y2);
    return &lines[p++];
}

void freeLines() {
    p = 0;
}

int main() {
    for (int N; scanf("%d", &N) != EOF; ) {
        for (int i = 0; i < N; i++)
            scanf("%d%d", &X[i], &Y[i]);
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            vector<Line*> lines;
            for (int j = 0; j < N; j++) {
                if (j == i) continue;
                lines.push_back(newLine(X[i], Y[i], X[j], Y[j]));
            }
            sort(lines.begin(), lines.end(), compare);
            
            int j = 0;
            while (j < lines.size()) {
                int k = j + 1;
                while (k < lines.size() && equals(lines[j], lines[k]))
                    k++;
                answer = max(answer, k - j + 1);
                j = k;
            }
            
            freeLines();
        }
        printf("%d\n", answer);
    }
    return 0;
}
