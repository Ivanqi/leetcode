class Soultion:
    def maxArea(self, height):
        low = 0
        high = len(height) - 1
        maxArea = 0
        while(low < high):
            maxArea = max(maxArea, min(height[low], height[high]) * (high - low))
            if (height[low] < height[high]):
                low += 1
            else:
                high -= 1
        return maxArea


soultion = Soultion()
height = [1,8,6,2,5,4,8,3,7]
print(soultion.maxArea(height));