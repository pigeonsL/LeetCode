#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
/*如果左边的元素个数相加刚好等于k, 那么第k个元素就是Max(LMax1, LMax2) */
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;//c1+c2=m+n+1,即虚拟扩展之后数组长度的中点，转为下标表示c2=m+n+1-c1-1;
            //要满足LMax1 < RMin2 且 LMax2 < RMin1
			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];//数组1整体都在右边了，都比中值大
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];// 数组1整体都在左边了，都比中值小,来保证LMax2<RMin1恒成立
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];//数组2整体在右边了，都比中值大
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];//数组2整体在左边了，都比中值小

			if (LMax1 > RMin2)//数组1的左边元素太大（多），我们把C1减小，C2=k-C1也就相应的增大
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};


int main(int argc, char *argv[])
{
	vector<int> nums1 = { 2,3, 5 };
	vector<int> nums2 = { 1,4,7, 9};
	
	Solution solution;
	double ret = solution.findMedianSortedArrays(nums1, nums2);
    cout<<ret<<endl;
    system("pause");
	return 0;
}