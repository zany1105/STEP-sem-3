#include <iostream>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
