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
 * @file <stats.h >
 * @brief <Function without code // Outine >
 *
 * <Add Extended Description Here>
 *
 * @author <Lam Tran>
 * @date <August 24th 2022 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Find the maximum value
 *
 * Given the array and the size, start the loop in the array
 * to find out the max vaue
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @return <Max value>
 */
 int find_max(unsigned char a[], int n);
 
 /**
 * @brief <Find the minimum value>
 *
 * Given the array and the size, start the loop in the array
 * to find out the min vaue
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @return <Min value>
 */
 int find_min(unsigned char a[], int n);
 
 /**
 * @brief <Find the mean value>
 *
 * Given the array and the size, calculating the sum 
 * then divide it into the size
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @return <Mean value>
 */
 int find_mean(unsigned char a[], int n);
 
/**
 * @brief <Find the median value>
 *
 * Given the array and the size, calculating the number
 * in the middle of the size, then store that component's
 * value to the mean varieble.
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @return <Median value>
 */
 int find_median(unsigned char a[], int n);
 
 /**
 * @brief <Sort the array by largest to smallest>
 *
 * Given the array and the size, calculating the number
 * in the middle of the size, then store that component's
 * value to the mean varieble.
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @return <sorted array>
 */
 int sort(unsigned char a[], int n);
 
 /**
 * @brief <swap the position of 2 component>
 *
 * Given the array and the size, start 2 loops and sorting 
 * the largest to the smallest in the current queue by the loops
 * @param <int p> <variable of the compoment>
 * @param <int n> <variable of the compoment>
 * @return <swap the position>
 */
 int swap(int p, int q);
 
 /**
 * @brief <Print out the array>
 *
 * Given the array and the size, initialize a loop from 0 to SIZE
 * and print out the ith component
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @return <all the value in array>
 */
 int print_array(unsigned char a[], int n);
 
 /**
 * @brief <Print out the calculated statistics>
 *
 * Simply print all the calculated values
 *
 * @param <unsigned char a[]> <variable of the array>
 * @param <int n> <the size>
 * @param <int x> <Max>
 * @param <int b> <Min>
 * @param <int c> <Mean>
 * @param <float d> <Median>
 * @return <All the statistics>
 */
 int print_statistics(unsigned char a[], int n, int x, int b, int c, float d);

#endif /* __STATS_H__ */
