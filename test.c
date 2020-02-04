c and c++ solutions. c++ is O(n) time and just 6 lines. Includes c, O(n), hashmap solution
Language	Author	Votes
c	ChrisTrompf	7
c++
C++ has all the nice tools to solve this quickly and easily.

Short and simple c++ solution. O(n) time, O(n) space
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, std::size_t> tmp;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      if (tmp.count(target - nums[i])) {
        return {tmp[target - nums[i]], i};
      }
      tmp[nums[i]] = i;
    }
    return {nums.size(), nums.size()};
  }

C does not have all the niceities of c++ and other language, so we have to do it the hard way.

Obvious brute force approach. O(n^2) time, O(1) space
int* twoSum(int* nums, int numsSize, int target) {
  int* ret = (char*)malloc(2 * sizeof(int));
  for (ret[0] = 0; ret[0] < numsSize; ++ret[0]) {
    for (ret[1] = ret[0] + 1; ret[1] < numsSize; ++ret[1]) {
      if (nums[ret[0]] + nums[ret[1]] == target) {
        return ret;
      }
    }
  }
  return ret;
}
Sorting approach. O(nlogn) time, O(n) space
The brute force is obviously expensive. If we were able to instead have the numbers in sorted order, we can find a solution in O(n) time. The reasoning behind this is as follows;

Start with the two indexes, pointing to the lowest (lo) and highest (hi) values.
If current values are less than our target, then increase lo and hence increase the sum. If the sum is greater than our target, then decrease hi and hence reduce the sum.
Continue from 2. so long as the sum doesn’t equal the target.
The problem is of course that c makes us do it the hard way. In particular we don’t want to rearrange the nums array as we need to return the indexes. We have to provide our own functions. partition_indexes that reorders an array of indexes based on the value of nums that the indexes address and sort_indexes that uses quicksort to reorder the index mappings.

Even though finding the answer if the numbers are sorted is O(n), we have to pay O(nlogn) time for the sort, so the solution is O(nlogn) time.

void swap(int * const a, int * const b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// Partition indexes that map to nums, without changing nums values or ordering
int partition_indexes(const int* const nums, int* const indexes, int lo, int hi) {
  int pivot = lo++;
  int pivot_val = nums[indexes[pivot]];
  int idx = pivot;
  int tmp;
  for (; lo < hi; ++lo) {
    if (nums[indexes[lo]] <= pivot_val) {
      swap(indexes + lo, indexes + ++idx);
    }
  }
 
  // Swapt the pivot (which is at the front) with the last value less or equal to the pivot
  swap(indexes + pivot, indexes + idx);
  
  return idx;
}

// Sort indexes that map to nums, without changing nums values or ordering
void sort_indexes(const int* const nums, int* const indexes, int lo, int hi) {
  if (lo < hi) {
    int pivot = partition_indexes(nums, indexes, lo, hi);
    sort_indexes(nums, indexes, lo, pivot);
    sort_indexes(nums, indexes, pivot + 1, hi);
  }
}

int* twoSum(int* nums, int numsSize, int target) {
  int* ret = (int*)malloc(2 * sizeof(int));
  
  // Build index mapping to nums that is sorted assendingly
  int* indexes = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    indexes[i] = i;
  }
  sort_indexes(nums, indexes, 0, numsSize);

  // Move in from either side, if the pair is below target, then left index must increase
  // to increase the sum, while right must decrease if the sum is over
  int lo = 0;
  int hi = numsSize - 1;
  while (nums[indexes[lo]] + nums[indexes[hi]] != target) {
    if (nums[indexes[lo]] + nums[indexes[hi]] < target) {
      ++lo;
    } else {
      --hi;
    }
  }
  
  ret[0] = indexes[lo];
  ret[1] = indexes[hi];
  
  free(indexes);

  return ret;
}
Hashmap. O(n) time, O(n) space
The hashmap solution for c++ is nice and simple, the c takes a bit more work and uses the external uthash (which is automatically included for c solutions).

struct number_hash {
  int value;
  int index;
  UT_hash_handle hh;
};

void destroy_table(struct number_hash** table) {
  struct number_hash* curr;
  struct number_hash* tmp;
  
  HASH_ITER(hh, *table, curr, tmp) {
    HASH_DEL(*table, curr);
    free(curr);
  }
}

int* twoSum(int* nums, int numsSize, int target) {
  struct number_hash* table = NULL;
  struct number_hash* element;
  int* ret = (int*) malloc(2 * sizeof(int));
  int remaining;
  for (int i = 0; i < numsSize; ++i) {
    remaining = target - nums[i];
   
    // Find if there has already been an element such that the sum is target
    HASH_FIND_INT(table, &remaining, element);
    if (element) {
      ret[0] = element->index;
      ret[1] = i;
      break;
    }
   
    // Add the new number to the hash table if it doesn't exist already
    HASH_FIND_INT(table, &nums[i], element);
    if (!element) {
      element = (struct number_hash *) malloc(sizeof(*element));
      element->value = nums[i];
      element->index = i;

      HASH_ADD_INT(table, value, element);
    }
  }
  
  destroy_table(&table);
 
  return ret;
}