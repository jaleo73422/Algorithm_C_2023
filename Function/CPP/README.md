## lower_bound()
找出升冪陣列中「大於或等於」val的「最小值」的最小index，
if(val < nums[0]>) -> return 0，
if(val > nums[size - 1]>) return size，
。

-----

duplicate array 不適合使用 binary search

## upper_bound()
找出升冪陣列中「大於」val的「最小值」的最小index
if(val < nums[0]>) -> return 0，
if(val >= nums[size - 1]>) return size，
。

-----

duplicate array 不適合使用 binary search