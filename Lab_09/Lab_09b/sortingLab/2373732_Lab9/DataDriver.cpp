/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: DataDriver.cpp
 * Created: ???
 * Modified: 4/21/13
 * Description: Added implementation for ShellSort and RadixSort
 */
#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>
#include "Sorts.h"
#include <bitset>
using namespace std;

unsigned long getTime() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000ul + tv.tv_usec;
}

typedef void (*SortFunction)(double a[], int n);
//Typedef for radixSort's additional parameters
typedef void (*SortRadix)(long a[], int size, int digits, int bits); 

int main(int argc, char *argv[]) {
  if(argc < 6) {
    cerr << "Usage: " << argv[0]
         << " <algorithm> <mink> <maxk> <iterations> <sequence [seed]>" << endl
	     << " <R> <mink> <maxk> <iterations> <digits> <bits> <[seed]>" << endl
         << "algorithm\t<B|S|I|Q|3|M|i|H|R>\n"
         << "\t\t(B)ubble\n"
         << "\t\t(S)election\n"
         << "\t\t(I)nsertion\n"
         << "\t\t(Q)uick (first element pivot)\n"
         << "\t\t(3)Quick (median of 3)\n"
         << "\t\t(M)erge\n"
         << "\t\t(i)terative merge\n"
	     << "\t\tS(H)ell\n"
	     << "\t\t(R)adix\n"
         << "mink\t\tminimum exponent for size, 2^(2*i)\n"
         << "maxk\t\tmaximum exponent for size, 2^(2*i)\n"
         << "iterations\tnatural number for iterations\n"
         << "sequence\t<R|A|D>\n"
         << "\t\t(R)andom\n\t\t(A)scending\n\t\t(D)escending\n"
         << "seed\t\toptional parameter for R sequence"
         << " time(NULL) if not specified\n";
    return -1;
  }

  long seed = time(NULL);

  int m = 0; //number of algorithms
  while(argv[1][m] != '\0')
  {
    char algorithm = argv[1][m];
    string algstr;
    SortFunction f;
    SortRadix r;
    bool radix = false;
    switch(algorithm)
    {
      case 'B': f = &bubbleSort; algstr = "BubbleSort"; break;
      case 'S': f = &selectionSort; algstr = "SelectionSort"; break;
      case 'I': f = &insertionSort; algstr = "InsertionSort"; break;
      case 'M': f = &mergeSort; algstr = "MergeSort"; break;
      case 'i': f = &imergeSort; algstr = "iMergeSort"; break;
      case 'Q': f = &quickSort; algstr = "QuickSort"; break;
      case '3': f = &quickSort3; algstr = "QuickSort3"; break;
      case 'H': f = &shellSort; algstr = "ShellSort"; break;
      case 'R': r = &radixSort; algstr = "RadixSort"; radix = true; break;
      default : cerr << "Invalid algorithm choice - '"
                     << algorithm << "'\n";
                exit(-1);
    }
    
    //Execute Radix
    if(radix) {
        //Gather different arguments
        const int mink = atoi(argv[2]);
        const int maxk = atoi(argv[3]);
        const int iterations = atoi(argv[4]);
        const int digits = atoi(argv[5]);
        const int bits = atoi(argv[6]);
        if(argc == 8)
            seed = atoi(argv[7]);
        srand48(seed);
        cout << algstr << endl;
        //Generate data, test
        for(int i = mink; i <= maxk; i++) {
            unsigned long totaltime = 0;
            int n = (int)pow((double)2,(2*(double)i));
            long *a = new long[n];
            if(a == NULL) {
                cerr << "Can't allocate an array of size " << n << endl;
                exit(-1);
            }
            
            //Generate radix test data through bitshifting
            int d = 0;
            for(int j = 0; j < iterations; j++) {
                for(int k = 0; k < n; k++) {
                    a[k] = 0;
                    for(int m = digits - 1; m >= 0; m--) {
                        d = rand() % (int)(pow(2, bits));
                        a[k] = (a[k] << bits)|d;
                        std::bitset<8> x(d);
                        std::bitset<8> y(a[k]);
                    }
                }
                unsigned long start = getTime();
                (r)(a, n, digits, bits);
                totaltime += getTime() - start;              
            }
            //Delete test array
            delete[] a;

            double avgtime = totaltime/(double)iterations;
            
            //Show time stats
            cout << "t_" << left << setw(11) << n
                 << " = " << right << setw(15)
                 << avgtime << " microseconds"
                 << right << setw(15) 
                 << (avgtime/1000000.0) << " seconds\n"
                 << left;

        }
        //Don't try to execute any more algorithms
        break;
    }

    const int mink = atoi(argv[2]);
    const int maxk = atoi(argv[3]);
    const int iterations = atoi(argv[4]);
    const char sequence = argv[5][0];
    if(argc == 7)
      seed = atoi(argv[6]);
    srand48(seed);
    cout << algstr << endl;
    for(int i = mink; i <= maxk; i++)
    {
      unsigned long totaltime = 0;
      //modified for report
      int n = (int)pow((double)2,(2*(double)i));
      double *a = new double[n];
      if(a == NULL)
      {
        cerr << "Can't allocate an array of size " << n << endl;
        exit(-1);
      }
      for(int j = 0; j < iterations; j++)
      {
        switch(sequence)
        {
          case 'R':
            for(int x = 0; x < n; x++)
              a[x] = drand48();
            break;
          case 'A':
            for(int x = 0; x < n; x++)
              a[x] = x;
            break;
          case 'D':
            for(int x = 0; x < n; x++)
              a[x] = n-x;
            break;
        }//end switch

        unsigned long start = getTime();
        (f)(a,n);
        totaltime += getTime() - start;
      }//end j for loop

      delete [] a;

      double avgtime = totaltime/(double)iterations;

      cout << "t_" << left << setw(11) << n
           << " = " << right << setw(15)
           << avgtime << " microseconds"
           << right << setw(15) 
           << (avgtime/1000000.0) << " seconds\n"
           << left;
    }//end i for loop

    m++;
  }//end while

  return 0;
}//end main

