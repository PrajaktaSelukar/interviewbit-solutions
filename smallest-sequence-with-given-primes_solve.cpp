// Time - O(N LogN), Space - O(N)
// where N is the number of integers to generate.
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> primes{A, B, C};
    int nums_count = D;
    unordered_set<int> found_nums(primes.begin(), primes.end());
    priority_queue<int, vector<int>, greater<int>> next_num(found_nums.begin(),
                                                            found_nums.end());
    vector<int> result;
    while (result.size() != nums_count) {
        int cur_num = next_num.top();
        next_num.pop();
        for (auto &p : primes) {
            if (found_nums.count(cur_num * p) == 0) {
                next_num.push(cur_num * p);
                found_nums.insert(cur_num * p);
            }
        }
        result.push_back(cur_num);
    }

    return result;
}


// Time - O(N * P), Space - O(N + P)
// where N is the number of integers to generate and P is the number of primes
// given.
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> primes{A, B, C};
    int nums_count = D;
    vector<int> candidate_terms = primes;
    vector<int> term_indices(primes.size(), 0);
    vector<int> result;
    for (int count = 0; count < nums_count; count++) {
        int next_term =
            *min_element(candidate_terms.begin(), candidate_terms.end());
        result.push_back(next_term);

        for (int t = 0; t < candidate_terms.size(); t++) {
            if (candidate_terms[t] == next_term) {
                candidate_terms[t] = primes[t] * result[term_indices[t]];
                term_indices[t]++;
            }
        }
    }

    return result;
}
