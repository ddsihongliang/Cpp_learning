class KthLargest
{
public:
    KthLargest(int kth, vector<int> &num)
    {
        if (kth != 0)
            k = kth;
        else
            k = 1;

        nums = num;
        // if (num.size()<=k)
        //     nums.push_back(-INT_MAX);
        bubble_sort(nums, nums.size());
    }

    int add(int val)
    {
        // it is neccessary to sort the array every time we
        // add a new numer. But shifting array is slow.

        // Method 1: Scan the entire array for kth rank.
        nums.push_back(val);
        int length = nums.size();
        int temp;

        for (int i = length - 1; i > 0; i--)
        {
            if (nums[i] <= nums[i - 1])
            {
                break;
            }
            else
            {
                temp = nums[i];
                nums[i] = nums[i - 1];
                nums[i - 1] = temp;
            }
        }
        // for (int i=0;i<length;i++)
        //     cout<<nums[i]<<" ";
        // cout<<endl;
        return nums[k - 1];
    }

private:
    int k;
    vector<int> nums;
    void bubble_sort(vector<int> &num, int length)
    {
        int temp;
        for (int j = 0; j < length - 1; j++)
        { // O(n^2) sorting
            for (int i = 0; i < length - 1 - j; i++)
            {
                if (num[i] < num[i + 1])
                {
                    temp = num[i + 1];
                    num[i + 1] = num[i];
                    num[i] = temp;
                }
            }
        }

        //cout<<"length: "<<length<<endl;
    }
};