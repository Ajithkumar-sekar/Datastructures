#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//https://www.hackerrank.com/challenges/ctci-merge-sort

void mergeHalves(vector<int>& a, vector<int>& temp, int start, int mid, int end, long long& inverions)
{
   int i, j, k;
   i = start;
   j = mid;
   k = start;
   while(i < mid && j < end + 1)
   {
       if(a[i] <= a[j])
           temp[k++] = a[i++];
       else
       {
           temp[k++] = a[j++];
           inverions += mid - i;
       }
   }

   while(i < mid)
      temp[k++] = a[i++];
   while(j <= end )
       temp[k++] = a[j++];
   for(; start <= end; start++)
       a[start] = temp[start];

}

void mergeSort(vector<int>& a, vector<int>& temp, int start, int end, long long& inversions)
{
    if(start >= end)
        return;
    int mid = (start + end)/2;
    //cout<<"Mid : "<<mid<<", Start : "<<start<<", End : "<<end<<endl;
    mergeSort(a, temp, start, mid, inversions);
    mergeSort(a, temp, mid + 1, end, inversions);
    mergeHalves(a, temp, start, mid + 1, end, inversions);
}


long long count_inversions(vector<int>& a) {
     long long c_inversions = 0;
     vector<int> temp(a.size());
     mergeSort(a, temp, 0, a.size() - 1, c_inversions);
     return c_inversions;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
