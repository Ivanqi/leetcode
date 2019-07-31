public class leetcode_75_3 {
    public int[] sortColors(int[] nums) {
        int red = 0;
        int white = 0;
        int blue = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                red++;
            } else if (nums[i] == 1) {
                white++;
            } else {
                blue++;
            }
        }

        for(int i = 0; i < red; i++) {
            nums[i] = 0;
        }

        for(int i = red; i < red + white; i++) {
            nums[i] = 1;
        }

        for(int i = red + white; i < red + white + blue; i++) {
            nums[i] = 2;
        }

        return nums;
    }

    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void main (String[] args) {
        leetcode_75_3 solution = new leetcode_75_3();
        int[] checkList = {2,0,2,1,1,0};
        int[] res = solution.sortColors(checkList);
        printArray(res);
    }
};