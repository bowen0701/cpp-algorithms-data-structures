#include <iostream>
#include <vector>
#include <random>

// Bubble sort algorithm.
// Procedure:
// - Start from i=n-1,...,1, 
// - Swap (nums[j], nums[j+1]) if not sorted, for j=0,...,i-1.
// Time complexity: O(n^2).
// Space complexity: O(1).
void bubbleSort(std::vector<int>& nums) {
  int n = nums.size();

  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}

int main() {
  // Generate vector nums=0,...,9.
  int n = 10;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    nums[i] = i;
  }
  
  // Shuffle nums.
  unsigned seed = 71; 
  std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed)); 
  std::cout << "nums: " << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  // Apply bubble sort. 
  std::cout << "Bubble sort:" << std::endl;
  bubbleSort(nums);
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
