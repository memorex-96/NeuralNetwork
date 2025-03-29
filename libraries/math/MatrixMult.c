#include<stdio.h> 
#include<stdlib.h> 
// C_{ij} = \sum_k A_{ik} * B_{jk}


void testing_shared () { 
	printf("Message from MatrixMult.c\n"); 
} 	

int** multiply_matrix (int** firstArr, int** nextArr, int rows, int cols) { 
	// rows_result = first_rows, cols_result = second_cols
	int** result = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; ++i) { 
		result[i] = (int*)malloc(cols * sizeof(int)); 
		for (int j = 0; j < cols; ++j) { 
		     result[i][j] = 0;   	
		     
		     for (int k = 0; k < cols; ++k) {
			result[i][j] += (firstArr[i][k] * nextArr[k][j]); 	

		     } 		     
		     
		
		} 
	} 

	return result; 
		
}

void free_matrix (int** matrix, int rows) { 
	for (int i = 0; i < rows; i++) { 
		free(matrix[i]); 
	} 

	free(matrix); 
}
 
