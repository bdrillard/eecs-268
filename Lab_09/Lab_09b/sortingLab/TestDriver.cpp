//Selection and Bubble are working

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include "Sorts.h"
using namespace std;

typedef void (*SortFunction)(double a[], int n);

int main(int argc, char *argv[])
{
  if(argc < 4) {
    cerr << "Usage: " << argv[0]
         << " <algorithm> <n> <sequence [seed]>" << endl
         << "algorithm\t<B|S|I|Q|3|M|i|R>\n"
         << "\t\t(B)ubble\n"
         << "\t\t(S)election\n"
         << "\t\t(I)nsertion\n"
         << "\t\t(Q)uick (first element pivot)\n"
         << "\t\t(3)Quick (median of 3)\n"
         << "\t\t(M)erge\n"
         << "\t\t(i)terative merge\n"
	 << "\t\tS(H)ell\n"
         << "n\t\tsize\n"
         << "sequence\t<R|A|D>\n"
         << "\t\t(R)andom\n\t\t(A)scending\n\t\t(D)escending\n"
         << "seed\t\toptional parameter for R sequence"
         << " time(NULL) if not specified\n";
    return -1;
  }

  int n = atoi(argv[2]);
  long seed = time(NULL);
  double *orig = new double[n];
  double *correct = new double[n];
  char sequence = argv[3][0];

  switch(sequence)
  {
    case 'R':
      if(argc == 5)
        seed = atoi(argv[4]);
      srand48(seed);
      for(int i = 0; i < n; i++)
        correct[i] = orig[i] = drand48();
      break;
    case 'A':
      for(int i = 0; i < n; i++)
        correct[i] = orig[i] = i;
      break;
    case 'D':
      for(int i = 0; i < n; i++)
        correct[i] = orig[i] = n-i;
      break;
  }//end switch

  //when you correctly write a more efficient sorting routine
  //you should use that instead of selectionSort!
  bubbleSort<double>(correct,n);

  int m = 0; //number of algorithms
  while(argv[1][m] != '\0')
  {
    char algorithm = argv[1][m];
    string algstr;
    SortFunction f;
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
      default : cerr << "Invalid algorithm choice - '"
                     << algorithm << "'\n";
                exit(-1);
    }

    cout << algstr << "...\n";

    double *a = new double[n];
    for(int i = 0; i < n; i++)
      a[i] = orig[i];

    (f)(a,n);

    //check to see if data is sorted  
    for(int i = 1; i < n; i++)
      assert(a[i] >= a[i-1]);

    //check to see if data was corrupted
    for(int i = 0; i < n; i++)
      assert(a[i] == correct[i]);

    cout << "okay\n";

    delete [] a;
    m++;
  }//end while

  return 0;
}
