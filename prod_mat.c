/*
 ============================================================================
 Name        : prod_mat.c
 Author      : Vito Proscia
 Version     :
 Copyright   : Your copyright notice
 Description : Product between two matrices
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int row1, column1, row2, column2;

	//inserimento numero di righe e colonne della prima matrice
	puts("************************Prima matrice************************");
	puts("Inserire il numero di righe della prima matrice: ");
	scanf("%d", &row1);
	puts("Inserire il numero di colonne della prima matrice: ");
	scanf("%d", &column1);

	//inserimento numero di righe e colonne della seconda matrice
	puts("************************Seconda matrice************************");
	puts("Inserire il numero di righe della seconda matrice: ");
	scanf("%d", &row2);
	puts("Inserire il numero di colonne della seconda matrice: ");
	scanf("%d", &column2);

	int a[row1][column1];
	int b[row2][column2];
	int ris[row1][column2];
	int i, j, k;

    // controllo validità operazione
	if(row1 == column2){
		//inserimento della prima matrice
		puts("************************Prima matrice************************");
		for(i = 0; i < row1; i++){
			for(j = 0; j < column1; j++){
				printf("Inserire un valore nella %da riga e %da colonna della prima matrice: \n", (i + 1), (j + 1));
				scanf("%d", &a[i][j]);
			}
		}
        //inserimento seconda matrice
		puts("************************Seconda matrice************************");
		for(i = 0; i < row2; i++){
			for(j = 0; j < column2; j++){

				printf("Inserire un valore nella %da riga e %da colonna della seconda matrice: \n", (i), (j + 1));
				scanf("%d", &b[i][j]);
			}
		}
		//output prima matrice
		puts("---1a Matrice---");
		for(i = 0; i < row1; i++){
			for(j = 0; j < column1; j++){

				printf("%d \t", a[i][j]);
			}
			printf("\n");
		}
		//output seconda matrice
		puts("---2a Matrice---");
		for(i = 0; i < row2; i++){
			for(j = 0; j < column2; j++){

				printf("%d \t", b[i][j]);
			}
			printf("\n");
		}

		// calcolo prodotto tra le due matrici
		for(i = 0; i < column1; i++){

			for(j = 0; j < row2; j++){

				ris[i][j] = 0;
				for(k = 0; k < column1; k++){

					ris[i][j] += a[i][k] * b[k][j];
				}

			}
		}

		//output dela matrice del prodotto
		puts("************************Risultato prodotto************************");
		for(i = 0; i < column1; i++){

			for(j = 0; j < row2; j++){

				printf("%d \t", ris[i][j]);
			}
			printf("\n");
		}

	}else{

		puts("Operazione non valida :(");
	}

	system("pause");
	return 0;
}
