/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int i = 0, j = 0, k, a_diff1, a_diff2, g_diff;
	if (arr == NULL){
		return NULL;
	}
	else{
		if (len <= 0){
			return NULL;
		}
		else{
			int *res = (int*)malloc(6 * sizeof(int));
			a_diff1 = arr[i + 1] - arr[i];
			while (a_diff1 == arr[i + 1] - arr[i]){
				i++;
			}
			if (i == 1){
				g_diff = arr[i + 1] / arr[i];
				res[4] = 0;
				while (g_diff == arr[i + 1] / arr[i]){
					i++;
				}
				res[5] = i;
				i++;
				res[0] = i;
				a_diff1 = arr[i + 1] - arr[i];
				while (a_diff1 == arr[i + 1] - arr[i]){
					i++;
				}
				res[1] = i;
				i++;
				res[2] = i;
				a_diff2 = arr[i + 1] - arr[i];
				while (a_diff2 == arr[i + 1] - arr[i]){
					i++;
				}
				res[3] = i;
			}
			else{
				res[0] = 0;
				res[1] = i;
				i++;
				j = i;
				a_diff2 = arr[j + 1] - arr[j];
				while (a_diff2 == arr[j + 1] - arr[j]){
					j++;
				}
				if (j - i == 1){
					g_diff = arr[i + 1] / arr[i];
					res[4] = i;
					while (g_diff == arr[i + 1] / arr[i]){
						i++;
					}
					res[5] = i;
					i++;
					j = i;
					res[2] = i;
					a_diff2 = arr[j + 1] - arr[j];
					while (a_diff2 == arr[j + 1] - arr[j]){
						j++;
					}
					res[3] = j;
				}
				else{
					res[2] = i;
					res[3] = j;
					g_diff = arr[j + 1] / arr[j];
					res[4] = j;
					while (g_diff == arr[j + 1] / arr[j]){
						j++;
					}
					res[5] = j;

				}
			}
			return res;
		}
	}
}