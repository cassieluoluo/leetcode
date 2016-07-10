public class TwoSum{
    public int[] twoSum(int[] nums, int target){
        int rtn[] = new int[2];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++){
            if (map.get(target - nums[i]) != null){
                rtn[0] = map.get(target-nums[i]);
                rtn[1] = i;
                return rtn;
            }
            map.put(nums[i], i);
        }
        return rtn;
    }

    /* If all the numbers are non-negative, we can use array. */

    /*
    public int[] twoSum(int[] nums, int target){
        int have[] = new int[target];
        int rtn[] = new int[2];
        Arrays.fill(have, -1);
        for(int i=0; i<target; i++){
            if(have[target-nums[i]] != -1){
                rtn[0] = have[target-nums[i]];
                rtn[1] = i;
                return rtn;
            }
            have[nums[i]] = i;
        }
        return rtn;
    }*/
} // Author: Bonnie
