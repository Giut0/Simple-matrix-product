/*
 ============================================================================
 Name        : prod_matrix.c
 Author      : Vito Proscia
 Version     : 2.0
 Description : Product between two matrices
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 100
#define MAX_COLUMN 100

short int isOperationValid(unsigned short int rowFirst, unsigned short int columnSecond);
void loadMatrix(int firstMatrix[MAX_ROW][MAX_COLUMN], int secondMatrix[MAX_ROW][MAX_COLUMN], unsigned short int rowFirst, unsigned short int columnFirst, unsigned short int rowSecond, unsigned short int columnSecond);
void printMatrix(int firstMatrix[MAX_ROW][MAX_COLUMN], int secondMatrix[MAX_ROW][MAX_COLUMN], unsigned short int rowFirst, unsigned short int columnFirst, unsigned short int rowSecond, unsigned short int columnSecond);
void multiplicationMatrices(int firstMatrix[MAX_ROW][MAX_COLUMN], int secondMatrix[MAX_ROW][MAX_COLUMN], int result[MAX_ROW][MAX_COLUMN], unsigned short int columnFirst, unsigned short int rowSecond);

int main(void) {
	
	unsigned short int rowFirstMatrix, columnFirstMatrix, rowSecondMatrix, columnSecondMatrix;
	int firstMatrix[MAX_ROW][MAX_COLUMN];
	int secondMatrix[MAX_ROW][MAX_COLUMN];
	int result[MAX_ROW][MAX_COLUMN];


    do{
        //input number of rows and columns of the first matrix
        printf("\n************************ First matrix ************************ \n \n");
        printf("Enter the number of rows of the first matrix: ");
        scanf("%hu", &rowFirstMatrix);
        printf("Enter the number of columns of the first matrix: ");
        scanf("%hu", &columnFirstMatrix);

        //input number of rows and columns of the second matrix
        printf("\n************************Second matrix************************ \n \n");
        printf("Enter the number of rows of the second matrix: ");
        scanf("%hu", &rowSecondMatrix);
        printf("Enter the number of columns of the second matrix: ");
        scanf("%hu", &columnSecondMatrix);

    }while (isOperationValid(rowFirstMatrix, columnSecondMatrix) == 0);   //operation validity check
    
    loadMatrix(firstMatrix, secondMatrix, rowFirstMatrix, columnFirstMatrix, rowSecondMatrix, columnSecondMatrix);
    printMatrix(firstMatrix, secondMatrix, rowFirstMatrix, columnFirstMatrix, rowSecondMatrix, columnSecondMatrix);
    multiplicationMatrices(firstMatrix, secondMatrix, result, columnFirstMatrix, rowSecondMatrix);

	return 0;
}

short int isOperationValid(unsigned short int rowFirst, unsigned short int columnSecond){

    unsigned short int flagValidation = 0;

    if(rowFirst == columnSecond){

        flagValidation = 1; 

    }

    return flagValidation;
}

void loadMatrix(int firstMatrix[MAX_ROW][MAX_COLUMN], int secondMatrix[MAX_ROW][MAX_COLUMN], unsigned short int rowFirst, unsigned short int columnFirst, unsigned short int rowSecond, unsigned short int columnSecond){
    
    unsigned short int i, j;

		//input first matrix
		printf("\n************************ First matrix ************************ \n \n");
		for(i = 0; i < rowFirst; i++){

			for(j = 0; j < columnFirst; j++){

				printf("Enter a value in the %da row and %da column of the first matrix: ", (i + 1), (j + 1));
				scanf("%d", &firstMatrix[i][j]);

			}
		}

        //input second matrix
		printf("\n************************ Second matrix ************************ \n \n");
		for(i = 0; i < rowSecond; i++){

			for(j = 0; j < columnSecond; j++){

				printf("Enter a value in the %da row and %da column of the second matrix: ", (i + 1), (j + 1));
				scanf("%d", &secondMatrix[i][j]);

			}
		}

}

void printMatrix(int firstMatrix[MAX_ROW][MAX_COLUMN], int secondMatrix[MAX_ROW][MAX_COLUMN], unsigned short int rowFirst, unsigned short int columnFirst, unsigned short int rowSecond, unsigned short int columnSecond){
  
   unsigned short int i, j;

		//output first matrix
		printf("\n----- 1a Matrix ----- \n \n");
		for(i = 0; i < rowFirst; i++){

			for(j = 0; j < columnFirst; j++){

				printf(" %d \t", firstMatrix[i][j]);

			}
			printf("\n \n");
		}

		//output second matrix
		printf("\n----- 2a Matrix ----- \n \n");
		for(i = 0; i < rowSecond; i++){

			for(j = 0; j < columnSecond; j++){

				printf(" %d \t", secondMatrix[i][j]);

			}
			printf("\n \n");
		}

}

void multiplicationMatrices(int firstMatrix[MAX_ROW][MAX_COLUMN], int secondMatrix[MAX_ROW][MAX_COLUMN], int result[MAX_ROW][MAX_COLUMN], unsigned short int columnFirst, unsigned short int rowSecond){
   
   unsigned short int i, j, k;

		// multiplication
        printf("\n************************ Result of multiplication ************************ \n \n");
		for(i = 0; i < columnFirst; i++){

			for(j = 0; j < rowSecond; j++){
				
				result[i][j] = 0;

				for(k = 0; k < columnFirst; k++){
					
					result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];

				}

				printf(" %d \t", result[i][j]);

			}
            printf("\n \n");
		}

}
