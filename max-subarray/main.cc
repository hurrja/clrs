#include <cstdlib>
#include <tuple>
#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
tuple <int, int, int> maxSubarray (const int A [], const T size)
{
    // playing with type traits here
    static_assert (is_integral <T>::value, "requires integral size type");

    int sum, from, to; // max sum subarray found so far
    int sumToI, fromToI;  // max sum subarray ending at index i
    
    for (T i = 0; i < size; i++)
    {
        auto elem = A [i];
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

int main ()
{
    const int A [] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    const auto N = extent <decltype (A)>::value; // size of array declared above

    int sum, from, to;
    tie (sum, from, to) = maxSubarray (A, N);
    cout << "sum [ " << sum << " ] in [ " << from << ", "
         << to << " ]" << endl;
    exit (0);
}
