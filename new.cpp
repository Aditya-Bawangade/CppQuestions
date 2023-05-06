#include<bits/stdc++.h>
using namespace std;
bool isValid(std::vector<int>& vec, int key) {
    int num = vec.size();
    int truth = num - key;
    int liar = key;
    for (int i = 0; i < num; i++) {
        if (vec[i] >= key) {
            liar++;
        }
        if (vec[i] > key) {
            truth--;
        }
    }
    return truth >= liar;
}

int ans(std::vector<int>& vec) {
    int num = vec.size();
    int min_liars = num + 1;
    for (int key = 0; key <= num; key++) {
        if (isValid(vec, key)) {
            min_liars = min(min_liars, key);
        }
    }
    return min_liars;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<int> vec(n);
        for (int j = 0; j < n; j++) {
            std::cin >> vec[j];
        }
        int finans = ans(vec);
        if (isValid(vec, finans)) {
            cout<< finans <<endl;
        } else {
            cout << -1 ;
        }
    }
    return 0;
}
