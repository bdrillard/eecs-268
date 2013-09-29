/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: radixSort.cpp
 * Created: 4/21/13
 * Modified: 4/21/13
 * Description: Radix Sort implementation.
 */
#include <queue>
#include <cmath>
using namespace std;

/*
 * Precondition: an array of longs has been generated, digits and bits have been given
 * Postcondition: the array of longs will be sorted
 */
template <typename T>
void radixSort(T a[], int size, int digits, int bits) {
    //Determine number of buckets necessary with given base and digits
    unsigned long num = pow(2, digits * bits);
    unsigned long in_bits = 0;
    do {
        num = num / bits;
        in_bits++;
    } while(num >= 1);
    
    //Initialize mah buckets
    vector< queue<int> > bucket;
    for(int i = 0; i < in_bits; i++) {
        bucket.push_back(queue<int>());
    }

    //Perform address calculation starting with least siginificant digit
    for(int i = 0; i < in_bits; i++) {
        for(int j = 0; j < size; j++) {
            //Get digit, place in bucket
            int placement = (int)(a[j] / pow(in_bits, i)) % in_bits;
            bucket[placement].push(a[j]);
        }
        
        //Empty buckets back into array
        for(int k = 0, entry = 0; k < bucket.size(); k++) {
            while(!bucket[k].empty()) {
                a[entry] = bucket[k].front();
                bucket[k].pop();
                entry++;
            }
        }
    }
    //To check order
    //for(int i = 0; i < size; i++)
    //    cout << a[i] << endl;
}

