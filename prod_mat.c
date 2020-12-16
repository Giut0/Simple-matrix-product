/*
 ============================================================================
 Name        : prod_mat.c
 Author      : Vito Proscia
 Version     : 1.0
 Description : Product between two matrices
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int row1, column1, row2, column2;

	//input number of rows and columns of the first matrix
	puts("************************First matrix************************");
	puts("Enter the number of rows of the first matrix: ");
	scanf("%d", &row1);
	puts("Enter the number of columns of the first matrix: ");
	scanf("%d", &column1);

	//input number of rows and columns of the second matrix
	puts("************************Second matrix************************");
	puts("Enter the number of rows of the second matrix: ");
	scanf("%d", &row2);
	puts("Enter the number of columns of the second matrix: ");
	scanf("%d", &column2);

	int a[row1][column1];
	int b[row2][column2];
	int ris[row1][column2];
	int i, j, k;

        //operation validity check
	if(row1 == column2){
		//input first matrix
		puts("************************First matrix************************");
		for(i = 0; i < row1; i++){
			for(j = 0; j < column1; j++){
				printf("Enter a value in the %d row and %d column of the first matrix: \n", (i + 1), (j + 1));
				scanf("%d", &a[i][j]);
			}
		}
        //input second matrix
		puts("************************Second matrix************************");
		for(i = 0; i < row2; i++){
			for(j = 0; j < column2; j++){

				printf("Enter a value in the %d row and %d column of the second matrix: \n", (i + 1), (j + 1));
				scanf("%d", &b[i][j]);
			}
		}
		//output first matrix
		puts("---1a Matrix---");
		for(i = 0; i < row1; i++){
			for(j = 0; j < column1; j++){

				printf("%d \t", a[i][j]);
			}
			printf("\n");
		}
		//output second matrix
		puts("---2a Matrix---");
		for(i = 0; i < row2; i++){
			for(j = 0; j < column2; j++){

				printf("%d \t", b[i][j]);
			}
			printf("\n");
		}

		// multiplication
		for(i = 0; i < column1; i++){
			for(j = 0; j < row2; j++){
				
				ris[i][j] = 0;
				for(k = 0; k < column1; k++){
					
					ris[i][j] += a[i][k] * b[k][j];
				}

			}
		}

		//output multiplication
		puts("************************Result of multiplication************************");
		for(i = 0; i < column1; i++){
			for(j = 0; j < row2; j++){

				printf("%d \t", ris[i][j]);
			}
			printf("\n");
		}

	}else{

		puts("Invalid operation :( ");
	}

	system("pause");
	return 0;
}
