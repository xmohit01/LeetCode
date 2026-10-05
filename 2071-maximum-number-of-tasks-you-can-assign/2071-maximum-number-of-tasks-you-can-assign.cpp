class Solution {
public:
    int n, m;
    bool canComplete(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        // Consider the first k strongest workers
        multiset<int> availableWorkers(workers.begin(), workers.begin() + k);

        // Assign the hardest task first
        for(int i = k - 1; i >= 0; i--) {
            int req = tasks[i];

            // Get the strongest available worker
            int strongest = *availableWorkers.rbegin();

            if(strongest >= req) {
                // Strongest worker can complete the task without a pill
                availableWorkers.erase(prev(availableWorkers.end()));
            }
            else {
                // If the strongest worker cannot do it, a pill is required
                if(pills == 0) return false;

                // Find the weakest worker who can complete it after using a pill
                auto it = availableWorkers.lower_bound(req - strength);

                // No worker can complete the task even with a pill
                if(it == availableWorkers.end()) {
                    return false;
                }

                // Assign this worker and use one pill
                availableWorkers.erase(it);
                pills--;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n = tasks.size();
        m = workers.size();

        // Sort tasks from easiest to hardest
        sort(tasks.begin(), tasks.end());

        // Sort workers from strongest to weakest
        sort(workers.begin(), workers.end(), greater<int>());

        int l = 0;
        int r = min(n, m);
        int ans = 0;

        // Binary search for the maximum number of tasks we can complete
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(canComplete(mid, tasks, workers, pills, strength)) {
                ans = mid;
                
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};