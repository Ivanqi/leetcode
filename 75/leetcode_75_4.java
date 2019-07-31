public class leetcode_75_4 {
    public int[] sortColors(int[] nums) {
        int head = 0;
        int cursor = 0;
        int tail = nums.length - 1;
        while(cursor <= tail) {
            if (nums[cursor] == 0) {
                int temp = nums[head];
                nums[head] = nums[cursor];
                nums[cursor] = temp;
                head++;
                cursor++;
            } else if (nums[cursor] == 2) {
                int temp = nums[tail];
                nums[tail] = nums[cursor];
                nums[cursor] = temp;
                tail--;
            } else {
                cursor++;
            }
        }
        return nums;
    }

    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void main (String[] args) {
        leetcode_75_4 solution = new leetcode_75_4();
        int[] checkList = {2,0,1};
        int[] res = solution.sortColors(checkList);
        printArray(res);
    }
};