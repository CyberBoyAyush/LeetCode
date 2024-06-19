### If this helps plz upvote my solution!!!!
## Problem Explanation:

You are given an array `bloomDay` where `bloomDay[i]` indicates the number of days it takes for the `i-th` flower to bloom. You want to make `m` bouquets, each consisting of `k` consecutive flowers from the garden.

To minimize the waiting time for the bouquets, you need to determine the minimum number of days required such that you can make at least `m` bouquets.

## Solution Approach:

1. **Binary Search:** We can use binary search to efficiently determine the minimum number of days needed. The search range will be between the minimum (`low`) and maximum (`high`) bloom days in the `bloomDay` array.
  
2. **Checking Feasibility:** For a given number of days (`mid`), we will check if it's possible to make at least `m` bouquets using the function `possible(bloomDay, mid, m, k)`. This function will simulate the bouquet-making process and return `true` if it's feasible to make `m` bouquets within `mid` days.

3. **Adjusting Search Range:** Depending on the feasibility check:
   - If making `m` bouquets is possible within `mid` days, we update our answer (`ans`) to `mid` and move our `high` pointer to search for a potentially smaller `mid`.
   - If making `m` bouquets is not possible within `mid` days, we adjust our `low` pointer to search for larger `mid` values.

## Code Implementation:

```cpp
class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0, noOfBouquets = 0;
        
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfBouquets += cnt / k;
                cnt = 0;
            }
        }
        noOfBouquets += cnt / k;
        
        return noOfBouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) {
            return -1; // Not enough flowers to make required bouquets
        }
        
        int low = INT_MAX, high = INT_MIN, ans = 0;
        
        // Determine the range of days (low to high) based on bloomDay array
        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1; // We need minimum, so move to the left part of the array
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
```

## Time Complexity:

The time complexity of this solution is \( O(n \log(\text{maxDays} - \text{minDays})) \), where:
- \( n \) is the size of the `bloomDay` array.
- `maxDays` and `minDays` are the maximum and minimum bloom days in the `bloomDay` array, respectively.

The primary contributor to the time complexity is the binary search algorithm, which iterates until convergence within the range of bloom days, combined with the linear `possible` function evaluation.

## Space Complexity:

The space complexity of this solution is \( O(1) \) because it uses only a constant amount of additional space, regardless of the input size (`bloomDay` array). The space complexity remains constant as the algorithm operates primarily in-place without requiring significant auxiliary data structures.


