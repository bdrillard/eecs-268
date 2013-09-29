/*
 * This file contains the standalone shellSort module
 */
#include <vector>

template <typename T>
void s_sort(T a[], int size, int steps[], int stepsSize) {
	for(int k = 0; k < stepsSize - 1; k++) {
		int i;
		int j;
		for(i = steps[k]; i < size; i++) {
			T temp = a[i];
			for(j = i; j >= steps[k] && a[j - steps[k]] > temp; j -= steps[k]) {
					a[j] = a[j - steps[k]];
			}
			a[j] = temp;
		}
	}
}

template <typename T>
void shellSort(T a[], int size) {
	//Five gaps of size dependent on data size
     
    int steps[5];
    for(int i = 0; i < 5; i++) {
        if(i == 0)
            steps[i] = 1;
        else
            steps[i] = i * (size / 5);
    }
	s_sort(a, size, steps, 5);
    
    //Twenty gaps of size dependent on data size
    /*
    int steps[25];
    for(int i = 0; i < 25; i++) {
        if(i ==0)
            steps[i] = 1;
        else
            steps[i] = i * (size / 25);
    }
    s_sort(a, size, steps, 25);
    */
    //Five gaps spaced by 3
    /*
    int steps[5] = {1, 4, 7, 10, 13};
    s_sort(a, size, steps, 5);
    */
    //Gaps generated as Fibonnaci numbers
    /* 
    vector<int> list;
    list.push_back(1);
    list.push_back(2);
    int num;
    do {
        num = list[list.size() - 1] + list[list.size() - 2];
        list.push_back(num);
    } while(num < size); 
    int stepSize = list.size();
    int* steps = new int[stepSize];
    for(int i = 0; i < stepSize; i++) {
        steps[i] = list[i];
    }
    s_sort(a, size, steps, stepSize);
    delete[] steps;
    */
    //Gaps created by alternative algorithm
    /*
    vector<int> list;
    int i = 1;
    int num;
    do {
        num = (pow(2, i) - 1);
        list.push_back(num);
        i++;
    } while(num < size);
    int stepSize = list.size();
    int* steps = new int[stepSize];
    for(int i = 0; i < stepSize; i++)
        steps[i] = list[i];
    s_sort(a, size, steps, stepSize);
    delete[] steps;
    */
}
