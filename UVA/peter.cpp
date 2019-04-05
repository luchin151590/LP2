#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> findExactSum(vector<int> & , int);

int main()
{
    int numBook, totalMoney;
    while(cin >> numBook)
    {
        vector<int> bookPrice(numBook);

        for(int index = 0; index < numBook; index++)
            cin >> bookPrice[index];

        cin >> totalMoney;

        pair<int, int> optimalPair = findExactSum(bookPrice, totalMoney);

        cout << "Peter should buy books whose prices are " << optimalPair.first << " and "
                << optimalPair.second << "." << endl << endl;
    }

    return 0;
}


pair<int, int> findExactSum(vector<int> & arr, int sum)
{

    sort(arr.begin(), arr.end());

    pair<int, int> optimalPair;
    bool notInitialize = true;

    int left = 0;
    int right = arr.size() - 1;
    while(left < right)
    {
        if(arr[left] + arr[right] > sum)
            
            right--;
        else
            if(arr[left] + arr[right] < sum)
                left++;
            else
            {
                
                if(notInitialize)
                {
                    notInitialize = false;
                    optimalPair = make_pair(arr[left], arr[right]);
                }
                else
                {
                    if(optimalPair.second - optimalPair.first > arr[right] - arr[left])
                        optimalPair = make_pair(arr[left], arr[right]);
                }
                left++;
                right--;
            }
    }

    return optimalPair;
}
