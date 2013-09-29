#include <cstdlib>
using namespace std;

//mergesort, breaks the original array into sub arrays and then merges adjacent elements in sorted order, evenutally merges into the final array

//sorts and merges sub arrays
template <typename T>
void merge(T a[], T temp[], int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;

  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

  while ((left <= left_end) && (mid <= right))
  {
    if (a[left] <= a[mid])
    {
      temp[tmp_pos] = a[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
      temp[tmp_pos] = a[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }

  while (left <= left_end)
  {
    temp[tmp_pos] = a[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = a[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }

  for (i=0; i < num_elements; i++)
  {
    a[right] = temp[right];
    right = right - 1;
  }
}

//break into sub arrays
template <typename T>
void m_sort(T a[], T temp[], int left, int right)
{
  int mid;
  
  if(right > left)
    {
      mid = (right + left) / 2;
      m_sort(a, temp, left, mid);
      m_sort(a, temp, mid+1, right);
      
      //merge all subarrays
      merge(a, temp, left, mid+1, right);
    }
}
//recursive merge sort
template <typename T>
void mergeSort(T a[], const int n)
{
  T *temp = new T[n];
  m_sort(a, temp, 0, n - 1);
  delete [] temp;
}

// Merge from one array into another
template <typename T>
void imerge (T c, T d, int lt, int md, int rt)
{
  //Merge c[lt:md] and c[md+1:rt] to d[lt:rt]
  int i = lt,       // cursor for first segment
    j = md+1,     // cursor for second
    k = lt;       // cursor for result
  
  //merge until one subarray is empty
  while ( (i <= md) && (j <= rt) )
    if (c[i] <= c[j])  
      d[k++] = c[i++];
    else
      d[k++] = c[j++];
  
  //copy the remaining elements
  while ( i <= md )
    d[k++] = c[i++];
  while ( j <= rt )
    d[k++] = c[j++];
}

  
//Perform one pass through the two arrays, and calls Merge() 
template <typename T>
void mergePass (T x, T y, int s, int n)
{
  int i = 0, j;
  
  while (i <= n - 2 * s)
    {
      //merge
      imerge (x, y, i, i+s-1, i+2*s-1);
      i = i + 2*s;
    }
  //if fewer than 2s elements remain
  if (i + s < n)
    imerge (x, y, i, i+s-1, n-1);
  else
    for (j = i; j <= n-1; j++)
      y[j] = x[j];   // copy last subarray to y
}
//iterative merge sort
template <typename T>
void imergeSort(T a[], int n)
{ 
  //size of subarray
  int  s = 1;     
  T *b = new T[n];
  while (s < n)
    { 
      //merge a to b
      mergePass (a, b, s, n);
      //double subarray size
      s += s;               
      //merge from b to a
      mergePass (b, a, s, n); 
      //double size of subarray
      s += s;                 
    } // end while
  delete [] b;
}
