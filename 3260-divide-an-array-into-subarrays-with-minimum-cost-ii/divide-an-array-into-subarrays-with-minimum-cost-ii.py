class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)
        # k-1 because nums[0] is always the first element of the first subarray
        k -= 1 
        
        # Initial window: elements from index 1 to dist + 1
        # We need the smallest k-1 elements from this initial window
        initial_window = nums[1 : dist + 2]
        all_elements = SortedList(initial_window)
        
        selected = SortedList(all_elements[:k])
        candidates = SortedList(all_elements[k:])
        current_sum = sum(selected)
        min_cost = current_sum
        
        # Slide the window from index dist + 2 to n - 1
        for i in range(dist + 2, n):
            # 1. Remove the element that is sliding out (at index i - dist - 1)
            out_val = nums[i - dist - 1]
            if out_val in selected:
                selected.remove(out_val)
                current_sum -= out_val
            else:
                candidates.remove(out_val)
                
            # 2. Add the new element entering the window (at index i)
            in_val = nums[i]
            # Heuristic: Add to candidates first, then balance
            candidates.add(in_val)
            
            # 3. Rebalance to ensure 'selected' has exactly k elements
            # Move smallest from candidates to selected
            while len(selected) < k:
                smallest_cand = candidates.pop(0)
                selected.add(smallest_cand)
                current_sum += smallest_cand
                
            # Move largest from selected to candidates if it's no longer optimal
            while candidates and selected[-1] > candidates[0]:
                to_cand = selected.pop(-1)
                to_sel = candidates.pop(0)
                current_sum = current_sum - to_cand + to_sel
                selected.add(to_sel)
                candidates.add(to_cand)
                
            min_cost = min(min_cost, current_sum)
            
        return nums[0] + min_cost