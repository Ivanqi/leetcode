public class leetcode_11_4 {
    /***
     * 
     * @param height
     * @return
     */
    public int maxArea(int[] height) {
        int maxAreas = 0;
        int low = 0;
        int high = height.length - 1;
        while(low < high) {
            maxAreas = Math.max(maxAreas, Math.min(height[low], height[high]) * (high - low));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return maxAreas;
    }

    public static void main (String[] args) {
        leetcode_11_3 solution = new leetcode_11_3();
        int[] checkList = {1,8,6,2,5,4,8,3,7};
        int res = solution.maxArea(checkList);
        System.out.println("输出结果为:" + res);
    }
}