//#include <iostream>
//#include <vector>
//using namespace std;
//
////int main() {
////	int n;
////	while (cin >> n) {
////		int count = 0;
////		while (n) {
////			n &= (n - 1);
////			count++;
////		}
////		cout << count << endl;
////	}
////	return 0;
////}
////#include <iostream>
////using namespace std;
////
////int main() {
////	int n;
////	while (cin >> n) {
////		int count = 0;
////		while (n) {
////			if (n & 1 == 1)
////				count++;
////			n >>= 1;
////		}
////		cout << count << endl;
////	}
////	return 0;
////}
//
//
//void swap(int* arr, int left, int right) {
//	int temp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = temp;
//}
//
//void selectSort(int* arr, int n) {
//	for (int i = 0; i < n-1; i++) {
//		int min = i;
//		for (int j = i + 1; j < n; j++) {
//			if (arr[j] < arr[min])
//				min = j;
//		}
//		swap(arr, min, i);
//	}
//}
//
//
//class Solution {
//public:
//	int balancedStringSplit(string s) {
//		int cnt = 0;
//		int balance = 0;
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] == 'R') {
//				balance++;
//			}
//			else {
//				balance--;
//			}
//			if (balance == 0)
//				cnt++;
//		}
//		return cnt;
//	}
//};
//
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int price = 0;
//		for (int i = 1; i < prices.size(); i++) {
//			if (prices[i] > prices[i - 1]) {
//				price += prices[i] - prices[i - 1];
//			}
//		}
//		return price;
//	}
//};
//
//class Solution {
//public:
//	bool canJump(vector<int>& nums) {
//		int rightMost = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			if (i <= rightMost) {
//				rightMost = max(rightMost, i + nums[i]);
//			}
//			if (rightMost >= nums.size() - 1)
//				return true;
//		}
//		return false;
//	}
//};
//
//int main() {
//	int arr[] = { 7,6,9,4,2,5,3,1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	selectSort(arr, size);
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int money, vector<pair<int, int> >& moneyCount) {
	int num = 0;
	for (int i = moneyCount.size() - 1; i >= 0; i--) {
		int c = min(money / moneyCount[i].first, moneyCount[i].second);
		money -= c * moneyCount[i].first;
		num += c;
	}
	if (money > 0) {
		num = -1;
	}
	return num;
}

int main() {
	vector<pair<int, int> > moneyCount = { {1,2},{2,3},{5,3},{10,3},{20,4},{50,1} };
	int money;
	cin >> money;

	int ret = solve(money, moneyCount);
	if (ret != -1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}