#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::pair<int, int>> twoSum(std::vector<int>& arr, int target, int n) {
    std::unordered_map<int, int> map; // Use a map to store the indices of the elements
    std::vector<std::pair<int, int>> result;

    for (int i = 0; i < n; ++i) {
        int complement = target - arr[i];

        if (map.find(complement) != map.end()) {
            result.push_back({map[complement], i});
        }

        map[arr[i]] = i; // Store the index of the current element
    }

    if(result.empty() && map[target])
    {
	   result.push_back ({0,0 });
    }
    
    if (result.empty()) {
        return {{-1, -1}}; // Return {-1, -1} if no pairs are found
    }
     

    return result;
}

int main() {
    std::vector<int> arr = {4,9};
    int target = 9;
    int n = arr.size();

    std::vector<std::pair<int, int>> result = twoSum(arr, target, n);

    for (const auto& pair : result) {
        std::cout << "Pair: (" << pair.first << ", " << pair.second << ")\n";
    }

    return 0;
}
