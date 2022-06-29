#include <cstdlib>
#include <tuple>
#include <iostream>
#include <type_traits>

using namespace std;

tuple<int, int, int> maxSubarray (const int A [], size_t size)
{
    int sum, from, to; // max sum subarray found so far
    int sumToI, fromToI;  // max sum subarray ending at index i
    
    for (size_t i = 0; i < size; i++)
    {
        int elem = A [i];
        if (i == 0) // first element, initialize values
        {
            sum = elem;
            from = i;
            to = from;
            sumToI = sum;
            fromToI = from;
        }
        else
        {
            // determine a max sum subarray ending at i
            if (sumToI <= 0)
            {
                sumToI = elem;
                fromToI = i;
            }
            else
                sumToI += elem;

            // determine whether max is prev max or max ending at i
            if (sumToI > sum)
            {
                sum = sumToI;
                from = fromToI;
                to = i;
            }
        }
    }

    return make_tuple (sum, from, to);
}

int main (int, char**)
{
    const int A [] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    const size_t N = extent<decltype(A)>::value;

    int sum, from, to;
    tie (sum, from, to) = maxSubarray (A, N);
    cout << "sum [ " << sum << " ] in [ " << from << ", "
         << to << " ]" << endl;
    exit (0);
}



//////////////////////////////////////////////////
// Local Variables:				//
// mode: c++					//
// make-backup-files: t				//
// End:						//
//////////////////////////////////////////////////
