#include <iostream>
#include <vector>
#include "util.h"

// Helper method for mergeSortRecur().
// Merge two sorted vectors by recursion.
std::vector<int> mergeSortedVectorsRecur(
    std::vector<int>& sorted1, 
    std::vector<int>& sorted2) {
  // Base case.
  if (sorted1.size() != 0 && sorted2.size() == 0) {
    return sorted1;
  } else if (sorted1.size() == 0 && sorted2.size() != 0) {
    return sorted2;
  } else if (sorted1.size() == 0 && sorted2.size() == 0) {
    return std::vector<int>();
  }

  // Merge two sorted numbers one by one element.
  // If nums1[0] <= nums2[0]: return nums1[0] + merge(nums1[1:], nums2), 
  // and vice versa.
  std::vector<int> result, result2;
  if (sorted1[0] <= sorted2[0]) {
    result = std::vector<int>(sorted1.begin(), sorted1.begin() + 1);
    std::vector<int> sorted1_right(sorted1.begin() + 1, sorted1.end());
    result2 = mergeSortedVectorsRecur(sorted1_right, sorted2);
  } else {
    result = std::vector<int>(sorted2.begin(), sorted2.begin() + 1);
    std::vector<int> sorted2_right(sorted2.begin() + 1, sorted2.end());
    result2 = mergeSortedVectorsRecur(sorted1, sorted2_right);
  }
  result.insert(result.end(), result2.begin(), result2.end());
  return result;
}

// Merge sort algorithm by recursively merging two sorted numbers.
// Time complexity: O(n*logn).
// Space complexity: O(n).
std::vector<int> mergeSortRecur(std::vector<int>& nums) {
  // Base case.
  if (nums.size() <= 1) return nums;

  // Sort the 1st & 2nd halves respectively and merge them.
  auto mid = nums.size() / 2;
  std::vector<int> left(nums.begin(), nums.begin() + mid);
  std::vector<int> right(nums.begin() + mid, nums.end());
  auto sorted1 = mergeSortRecur(left);
  auto sorted2 = mergeSortRecur(right);
  return mergeSortedVectorsRecur(sorted1, sorted2);
}

// Helper method for mergeSortIter().
// Merge two sorted vectors by iteration.
std::vector<int> mergeSortedVectorsIter(
    std::vector<int>& sorted1, 
    std::vector<int>& sorted2) {
  // Apply two pointer method.
  int i = 0, j = 0;
  std::vector<int> result;

  // Iteratively select small number to put into result.
  int n1 = sorted1.size();
  int n2 = sorted2.size();
  int n = n1 + n2;

  for (int k = 0; k < n; k++) {
    if (i < n1 && j < n2) {
      if (sorted1[i] <= sorted2[j]) {
        result.push_back(sorted1[i]);
        i++;
      } else {
        result.push_back(sorted2[j]);
        j++;
      }
    } else if (i < n1 && j >= n2) {
      result.push_back(sorted1[i]);
      i++;
    } else if (i >= n1 && j < n2) {
      result.push_back(sorted2[j]);
      j++;
    }
  }

  return result;
}

// Merge sort algorithm by iteratively merging two sorted numbers.
// Time complexity: O(n*logn).
// Space complexity: O(n).
std::vector<int> mergeSortIter(std::vector<int>& nums) {
  // Base case.
  if (nums.size() <= 1) return nums;

  // Sort the 1st & 2nd halves respectively and merge them.
  auto mid = nums.size() / 2;
  std::vector<int> left(nums.begin(), nums.begin() + mid);
  std::vector<int> right(nums.begin() + mid, nums.end());
  auto sorted1 = mergeSortIter(left);
  auto sorted2 = mergeSortIter(right);
  return mergeSortedVectorsIter(sorted1, sorted2);
}

int main() {
  std::vector<int> nums = {5, 2, 3, 1, 4};

  std::vector<int> result1 = mergeSortRecur(nums);
  std::cout << "Recur:" << std::endl;
  printVector(result1);

  std::vector<int> result2 = mergeSortIter(nums);
  std::cout << "Iter:" << std::endl;
  printVector(result2);

  return 0;
}
