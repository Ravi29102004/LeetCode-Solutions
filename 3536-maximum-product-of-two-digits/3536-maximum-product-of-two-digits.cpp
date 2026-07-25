class Solution {
public:
    int maxProduct(int n) {
        int max1=0;
        int max2=0;

        while(n>0)
        {
            int current_digit=n%10;
            if(current_digit>max1)
            {
                max2=max1;
                max1=current_digit;
            }else if(current_digit>max2)
            {
                max2=current_digit;
            }
            n/=10;
        }

        return max1*max2;
    }
};