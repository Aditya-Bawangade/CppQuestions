#include <iostream>
#include <algorithm>
#include <vector>

void permutations(std::vector<int> &v, int i, int n) {
    if (i == n) {
        for (int j = 0; j < 5; j++) {
            std::cout << v[j] << " ";
        }
        std::cout << std::endl;
    } else {
        for (int j = i; j < n; j++) {
            std::swap(v[i], v[j]);
            permutations(v, i + 1, n);
            std::swap(v[i], v[j]);
        }
    }
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    permutations(v, 0, 5);
    return 0;
}
