public class leetcode_11_3 {
    /**
     * 在这种情况下，我们将简单地考虑每对可能出现的线段组合并找出这些 情况之下的最大面积
     * 复杂度分析
     * 时间复杂度：O(n^{2})，计算所有 \frac{n(n-1)}{2} 种高度组合的面积
     * 空间复杂度: O(1) ，使用恒定的额外空间 
     * @param height
     * @return
     */
    public int maxArea(int[] height) {
        int maxArea = 0;
        for(int i = 0; i < height.length - 1; i++) {
            for(int j = i + 1; j < height.length; j++) {
                maxArea = Math.max(maxArea, Math.min(height[i], height[j]) * (j - i));
            }
        }
        return maxArea;
    }

    public static void main (String[] args) {
        leetcode_11_3 solution = new leetcode_11_3();
        int[] checkList = {1,8,6,2,5,4,8,3,7};
        int res = solution.maxArea(checkList);
        System.out.println("输出结果为:" + res);
    }
}