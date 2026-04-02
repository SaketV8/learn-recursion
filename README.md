<h1 align="center">Learn Recursion</h1>

learning recursion to increase my chances of solving any DSA question encountered in interviews (-_-)

### [🌸 Everything All At Once (～￣▽￣)～](./EVERYTHING_ALL_AT_ONCE.md)

## Day 1
> 19 Dec, 2025

- [x] print increasing
- [x] print decreasing
- [x] print increasing-decreasing
- [x] factorial
- [x] linear-power-x-n
- [x] logarithmic-power-x-n

## Day 2
> 20 Dec, 2025

- [x] print zig-zag (pre-in-post)
- [x] tower-of-hanoi
- [x] print array element
- [x] print array element in reverse
- [x] max array element
- [x] first index of occurance in array
- [x] last index of occurance in array

## Day 3
> 21 Dec, 2025

- [x] all indices in array
- [x] get subsequence
- [x] get keypad combination
- [x] get stair path
- [x] stair path base helper (for explaining `base` case of `get-stair-path`)

## Day 4
> 22 Dec, 2025

- [x] get maze path
- [x] get maze path with jump
- [x] print subsequence
- [x] print keypad combination
- [x] print stair path
- [x] print maze path

## Day 5
> 23 Dec, 2025 || solved first 3 on 25 Dec, 2025

> [!NOTE]  
> I’ll solve the remaining problems after my university exam (-_-)

- [x] print maze path with jump
- [x] print permutation
- [x] print encoding
- [ ] ~~flood fill~~
- [ ] ~~target sum subsets~~
- [ ] ~~n queens~~
- [ ] ~~knight tour~~

## Day 6
> 31 March, 2025

- [x] flood fill
- [x] target sum subsets
- [x] n queens
- [x] knight tour


## Visualization Diagram

<details>
<summary> Permutation & Combination </summary>
<h3 align="center"> ⚡ Permutation & Combination </h3>

```mermaid
flowchart LR

%% ========== COMBINATIONS ==========
subgraph Comb["Combinations (n=4, k=2)"]

c0((start))

c0 --> c1[1]
c0 --> c2[2]
c0 --> c3[3]
c0 --> c4[4]

c1 --> c12[1,2]
c1 --> c13[1,3]
c1 --> c14[1,4]

c2 --> c23[2,3]
c2 --> c24[2,4]

c3 --> c34[3,4]

end

%% ========== PERMUTATIONS ==========
subgraph Perm["Permutations [1,2,3]"]

p0((start))

p0 --> p1[1]
p0 --> p2[2]
p0 --> p3[3]

p1 --> p12[1,2]
p1 --> p13[1,3]

p2 --> p21[2,1]
p2 --> p23[2,3]

p3 --> p31[3,1]
p3 --> p32[3,2]

p12 --> p123[1,2,3]
p13 --> p132[1,3,2]

p21 --> p213[2,1,3]
p23 --> p231[2,3,1]

p31 --> p312[3,1,2]
p32 --> p321[3,2,1]


end

```

### if used[i] not used

```mermaid
flowchart TB

start((start))

%% level 1
start --> n1[1]
start --> n2[2]
start --> n3[3]

%% level 2
n1 --> n11[1,1]
n1 --> n12[1,2]
n1 --> n13[1,3]

n2 --> n21[2,1]
n2 --> n22[2,2]
n2 --> n23[2,3]

n3 --> n31[3,1]
n3 --> n32[3,2]
n3 --> n33[3,3]

%% level 3
n11 --> n111[1,1,1]
n11 --> n112[1,1,2]
n11 --> n113[1,1,3]

n12 --> n121[1,2,1]
n12 --> n122[1,2,2]
n12 --> n123[1,2,3]

n13 --> n131[1,3,1]
n13 --> n132[1,3,2]
n13 --> n133[1,3,3]

n21 --> n211[2,1,1]
n21 --> n212[2,1,2]
n21 --> n213[2,1,3]

n22 --> n221[2,2,1]
n22 --> n222[2,2,2]
n22 --> n223[2,2,3]

n23 --> n231[2,3,1]
n23 --> n232[2,3,2]
n23 --> n233[2,3,3]

n31 --> n311[3,1,1]
n31 --> n312[3,1,2]
n31 --> n313[3,1,3]

n32 --> n321[3,2,1]
n32 --> n322[3,2,2]
n32 --> n323[3,2,3]

n33 --> n331[3,3,1]
n33 --> n332[3,3,2]
n33 --> n333[3,3,3]
```

### CPP code 

```cpp
// COMBINATION
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, int n, int k, vector<int>& path) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);               // choose

            backtrack(i + 1, n, k, path);   // move forward

            path.pop_back();                // un-choose
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backtrack(1, n, k, path);
        return result;
    }
};


// PERMUTATION
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;              // choose
            path.push_back(nums[i]);

            backtrack(nums, path, used);

            path.pop_back();             // un-choose
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, path, used);
        return result;
    }
};

```

</details>