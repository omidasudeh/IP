#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, k;
vector<int> A;
vector<int> Q;
int head, tail;

inline void new_queue() {
    Q = vector<int>(n);
    head = tail = 0;
}

inline void push_back(int x) {
    Q[tail++] = x;
}

inline int front() {
    return Q[head];
}

inline int back() {
    return Q[tail - 1];
}

inline void pop_front() {
    head++;
}

inline void pop_back() {
    tail--;
}

inline bool empty() {
    return head == tail;
}

vector<int> minimumValues() {
    new_queue();
    vector<int> answer;
    for (int i = 1; i <= n; i++) {
        if (i > k && front() == A[i - k]) pop_front();
        while (!empty() && back() > A[i]) pop_back();
        push_back(A[i]);
        if (i >= k) answer.push_back(front());
    }
    return answer;
}

vector<int> maximumValues() {
    new_queue();
    vector<int> answer;
    for (int i = 1; i <= n; i++) {
        if (i > k && front() == A[i - k]) pop_front();
        while (!empty() && back() < A[i]) pop_back();
        push_back(A[i]);
        if (i >= k) answer.push_back(front());
    }
    return answer;
}

void print(const vector<int> &numbers) {
    if (numbers.size() > 0) {
        printf("%d", numbers[0]);
        for (int i = 1; i < numbers.size(); i++)
            printf(" %d", numbers[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &k);
    A = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    print(minimumValues());
    print(maximumValues());
    return 0;
}