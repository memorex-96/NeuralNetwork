#include<stdio.h> 
#include<stdlib.h> 
// C_{ij} = \sum_k A_{ik} * B_{jk}

int** multiply_matrix (int** firstArr, int** nextArr, int rows, int cols) { 
	// rows_result = first_rows, cols_result = second_cols
	int** result = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) { 
		result[i] = (int*)malloc(cols * sizeof(int)); 
		for (int j = 0; j < cols; j++) { 
		     result[i][j] = 0;   	
		     
		     for (int k = 0; k < cols; k++) {
			result[i][j] += (firstArr[i][k] * nextArr[k][j]); 	

		     } 		     
		     
		
		} 
	} 

	return result; 
		
}

int** createMatrix (int matrix[2][2], int rows, int cols) { 
	int** new_matrix = (int**)malloc(rows * sizeof(int*)); 

	for (int i = 0; i < rows; i++) { 
		new_matrix[i] = (int*)malloc(cols * sizeof(int)); 
		for (int j = 0; j < cols; j++) { 
			new_matrix[i][j] = matrix[i][j]; 
		} 
	} 
	return new_matrix; 
} 

void free_matrix (int** matrix, int rows) { 
	for (int i = 0; i < rows; i++) { 
		free(matrix[i]); 
	} 

	free(matrix); 
}

int main (int argc, char* argv[]) {

	int A[2][2] = {{1,2},{3,4}}; 
	int B[2][2] = {{5,6},{7,8}};
	
	int rows = 2; 
	int cols = 2; 

	int** firstArr = createMatrix(A, rows, cols); 
	int** nextArr = createMatrix(B, rows, cols); 
	
	int** result = multiply_matrix(firstArr, nextArr, rows, cols);

	for (int i = 0; i < rows; i++){ 
 		for (int j = 0; j < cols; j++) {
			printf("%d ", result[i][j]); 
		} 
		printf("\n");  
	} 	

	return 0; 	
} 
