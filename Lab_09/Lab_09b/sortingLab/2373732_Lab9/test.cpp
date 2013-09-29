#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <bitset>
using namespace std;


int main(){
        int D = 4, B = 3, N = 10, d = 0;
        srand (time(NULL));
        long array[N];
        for(int i = 0; i < N; i++){
                array[i] = 0;
                for(int k = D - 1; k >= 0; k--){
                        d = rand() % (int)(pow(2, B) );
                        array[i] = (array[i] << B)|d;
                        std::bitset<8> x(d);
                        std::bitset<8> y(array[i]);
                        cout << "Digit: "<< D-k << " Bits: " << B <<" Value: " << d <<" Binary: "<< x <<" Number: "<<array[i] << " Binary: " << y <<endl;

                }
        }
        return 0;
}
