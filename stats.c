/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <FULLY functional>
 *
 * <Add Extended Description Here>
 *
 * @author <Lam Tran>
 * @date <August 24th 2022 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
/* Add other Implementation File Code Here */
int find_max(unsigned char a[], int n){
	int max = a[0];
	for (int i = 0; i < n; i++){
		if (a[i] >= max){
			max = a[i];
		}
	}
	printf("Max = %d", max);
	return max;
}
int find_min(unsigned char a[], int n){
	int min = a[0];
	for (int i =0;i<n;i++){
		if(a[i]<=min){
			min = a[i];
		}
	}
	printf("\nMin = %d", min);
	return min;
}
int find_mean(unsigned char a[], int n){
	int sum = 0;
	float mean;
	for (int i =0;i<n;i++){
		sum = sum + a[i];
	    }
	mean = sum / (float)SIZE;
	printf("\nMean= %.4f", mean);
	return mean;
}
int swap(int p,int q) {
   int t;
   
   t=p; 
   p=q; 
   q=t;
}
int sort(unsigned char a[],int n) { 
   int i,j,temp;
   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(a[j] < a[j+1])
            swap(a[j],a[j+1]);
      }
   }
   printf("\nAfter sorting, the array goes by: \n");
   for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
}
int find_median(unsigned char a[], int n){
    sort(a,n);
    int median;
    n = (n+1) / 2 - 1;      
    printf("\nMedian = %d ", a[n]);
    median = a[n];
    return median;
}
int print_statistics(unsigned char a[], int n, int x, int b, int c, float d){
    printf("\nThis is the statistics of the array: ");
    printf("\nMaximum: %d", x);
    printf("\nMinimum: %d", b);
    printf("\nMean: %d", c);
    printf("\nMedian: %f", d);
}
int print_array(unsigned char a[], int n){
    printf("\nThe array goes by: \n");
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int max = find_max(test, SIZE);
  int min = find_min(test, SIZE);
  int mean = find_mean(test, SIZE);
  int median = find_median(test, SIZE);
  /* Statistics and Printing Functions Go Here */
  print_array(test,SIZE);
  sort(test,SIZE);
  print_statistics(test, SIZE, max, min, mean, median);
  }
/* Add other Implementation File Code Here */
