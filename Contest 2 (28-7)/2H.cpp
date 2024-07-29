/*
 * Cho dãy số A[] với N số nguyên phân biệt. 
 * Hãy tìm tất cả các số nguyên X sao cho tồn tại 2 tập con không giao nhau trong dãy A[] mà tổng 
 * các phần tử trong mỗi tập đó bằng X. 
 * Một tập con của một dãy số được tạo ra bằng các loại bỏ một số phần từ (không loại bỏ tất cả) 
 * trong dãy số ban đầu.
 * Dãy số ban đầu cũng được coi là tập con của chính nó (tức là không loại bỏ phần tử nào). . 
 *
 *Input:
 * Dòng đầu ghi số N là số phần tử của dãy số A[]. (1 ≤ N ≤ 18).
 * Dòng số 2 ghi N số nguyên phân biệt  A1; A2; …; AN (1 ≤ Ai ≤ 30).
 * 
 * Output:
 * Dòng đầu tiên ghi số m là số lượng giá trị X tìm được.
 * Dòng thứ 2 lần lượt ghi các giá trị X theo thứ tự từ nhỏ đến lớn.
 */

#include <bits/stdc++.h>

bool check(int set1, int set2) { return (set1 & set2) == 0; }

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::unordered_map<int, std::vector<int>> sum_to_sets;

    int total_sets = 1 << n;  

    for (int mask = 1; mask < total_sets; ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }
        sum_to_sets[sum].push_back(mask);
    }

    std::vector<int> result;
    for (const auto& pair : sum_to_sets) {
        const std::vector<int>& sets = pair.second;
        bool found = false;
        for (size_t i = 0; i < sets.size() && !found; ++i) {
            for (size_t j = i + 1; j < sets.size(); ++j) {
                if (check(sets[i], sets[j])) {
                    result.push_back(pair.first);
                    found = true;
                    break;
                }
            }
        }
    }

    std::sort(result.begin(), result.end());

    std::cout << result.size() << std::endl;
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}