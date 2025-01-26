/*Q4: You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.
Area=min(height[i],height[j])×(j−i)
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertical lines: ";
    cin >> n;

    int heights[n];
    cout << "Enter the heights of vertical lines: " << endl;
    for (int i=0; i<n; i++)
        {cin >> heights[i];}
    
    int maxArea=0;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int minHeight;
            if (heights[i] < heights[j])
                {minHeight = heights[i];}
            else
                {minHeight = heights[j];}
            
            int area = minHeight * (j-i);
            if (area > maxArea)
                {maxArea = area;}
        }
    }
    cout << "The maximum area of water the container can store is: " << maxArea << endl;
}