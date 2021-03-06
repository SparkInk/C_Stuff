/*************************************
Name: incSort
Language: C/C++
Description: incSort sorts out numbers in the ascending order 
Inputs: arr - pointer to pass over an array of numbers;
        size - the size of an array;
Output: sorted-out array (by reference)
Author: Iakov Umrikhin
Date Created: 23.04.2021
Date Modified (last): 23.04.2021
*************************************/

void incSort(double *arr, int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++){
            if (arr[i] > arr[j]){
                double temp;
                temp = arr[i];
                arr[i]= arr[j];
                arr[j] = temp;
            }
        }
    }
}
