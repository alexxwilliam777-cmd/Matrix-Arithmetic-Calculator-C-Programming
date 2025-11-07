#include<stdio.h>
#include<stdlib.h>

int glo_adjoint[3][3];

//This function performs the addition of matrix A and B and hence displays the result
void sum_function(int A[][3], int B[][3]){
    for(int i = 0; i < 3; i++){
        printf("|");
        for(int j = 0; j < 3; j++){
            printf("%4d ",A[i][j]+B[i][j]);
        }printf(" |\n");
    }
}

//This function performs the subtraction of matrix A and B and hence displays the result
void diff_function(int A[][3], int B[][3]){
    for(int i = 0; i < 3; i++){
        printf("|");
        for(int j = 0; j < 3; j++){
            printf("%4d ",A[i][j]-B[i][j]);
        }printf(" |\n");
    }
    
}

//This function performs the multiplication of matrix A and B and hence displays the result
void product_function(int A[][3], int B[][3]) {
    int C[3][3] = {0};
    
    for (int i = 0; i < 3; i++) {         
        for (int j = 0; j < 3; j++) {      
            for (int k = 0; k < 3; k++) {   
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf("%4d ", C[i][j]);
        }
        printf(" |\n");
    }
}

//This function can calculate minors and cofactors for a given matrix
void minors_cofactors(int A[][3], int mode){
    int *a = malloc(sizeof(int) * 9);
    int *b = malloc(sizeof(int) * 9);
    int temp = 0;
    a[0] = ((A[1][1]*A[2][2]) - (A[1][2]*A[2][1]));
    a[1] = ((A[1][0]*A[2][2]) - (A[1][2]*A[2][0]));
    a[2] = ((A[1][0]*A[2][1]) - (A[1][1]*A[2][0]));
    a[3] = ((A[0][1]*A[2][2]) - (A[2][1]*A[0][2]));
    a[4] = ((A[0][0]*A[2][2]) - (A[2][0]*A[0][2]));
    a[5] = ((A[0][0]*A[2][1]) - (A[2][0]*A[0][1]));
    a[6] = ((A[0][1]*A[1][2]) - (A[1][1]*A[0][2]));
    a[7] = ((A[0][0]*A[1][2]) - (A[1][0]*A[0][2]));
    a[8] = ((A[0][0]*A[1][1]) - (A[1][0]*A[0][1]));
    
    //This block of code executes when only minors are to be displayed
    if (mode==5){
        printf("|");
        for(int i = 0; i < 3; i++){
            printf("%4d ",a[i]);
        }printf(" |\n");
        printf("|");
        for(int i = 3; i < 6; i++){
            printf("%4d ",a[i]);
        }printf(" |\n");
        printf("|");
        for(int i = 6; i < 9; i++){
            printf("%4d ",a[i]);
        }printf(" |\n");
    }
    
    //This block of code executes when only cofactors are to be displayed
    if (mode==6){
        a[1] = -a[1];
        a[3] = -a[3];
        a[5] = -a[5];
        a[7] = -a[7];
        
        printf("|");
        for(int i = 0; i < 3; i++){
            printf("%4d ",a[i]);
        }printf(" |\n");
        printf("|");
        for(int i = 3; i < 6; i++){
            printf("%4d ",a[i]);
        }printf(" |\n");
        printf("|");
        for(int i = 6; i < 9; i++){
            printf("%4d ",a[i]);
        }printf(" |\n");
    }
    
    /*This block of code executes only when there's a need of adjoint
    for calulating the inverse of a given matrix. 
    It calculates the adjoint and stores it in the gloabal variable as an array*/
    if (mode==7){
        a[1] = -a[1];
        a[3] = -a[3];
        a[5] = -a[5];
        a[7] = -a[7];
        
        for(int i = 0; i < 9; i++){
            b[i] = a[i];
        }
        
        temp = b[1];
        b[1] = b[3];
        b[3] = temp;
        
        temp = 0;
        
        temp = b[2];
        b[2] = b[6];
        b[6] = temp;
        
        temp = 0;
        
        temp = b[5];
        b[5] = b[7];
        b[7] = temp;
    
        for(int i = 0, j = 0; i < 3, j < 3; i++, j++){
            glo_adjoint[0][i] = b[j];
        }
        for(int i = 0, j = 3; i < 3, j < 6; i++, j++){
            glo_adjoint[1][i] = b[j];
        }
        for(int i = 0, j = 6; i < 3, j < 9; i++, j++){
            glo_adjoint[2][i] = b[j];
        }

    }
    
    free(a);
    free(b);
}

//This function calculates the determinant for a given matrix.
void determinant(int A[][3],int mode){
    int *a = malloc(sizeof(int) * 3);
    
    a[0] = A[0][0]*((A[1][1]*A[2][2]) - (A[1][2]*A[2][1]));
    a[1] = A[0][1]*((A[1][0]*A[2][2]) - (A[1][2]*A[2][0]));
    a[2] = A[0][2]*((A[1][0]*A[2][1]) - (A[1][1]*A[2][0]));
    
    int det = (a[0]-a[1])+a[2];

    printf("Determinant is %d\n",det);

    //This block of code executes only when there's a need of inverse of a matrix.
    if(mode==7){
        if(det==0){
            printf("Since the determinant of the matrix is zero, inverse does not exists.");
        }
        else{
            printf("Since the determinant of matrix is %d, which is not equals to zero, inverse exists.\n",det);
            minors_cofactors(A,mode);

            for(int i = 0; i < 3; i++){
            printf("|");
            for(int j = 0; j < 3; j++){
                printf("%4d/%d", glo_adjoint[i][j], det);
            }printf(" |\n");
        }

        }
        
    }

    free(a);
}

int main(){

    int A[3][3];
    int B[3][3];
    int mode;

    // Asking the mode of arithmetic operation
    printf("Enter 1 for addition\nEnter 2 for difference\nEnter 3 for product\nEnter 4 for determinant\nEnter 5 for minors\nEnter 6 for co-factors\nEnter 7 for inverse\n");
    printf("Select mode of operation: ");
    scanf("%d", &mode);
    
    //Taking elements of matrices as an input
    if (mode == 1 || mode == 2 || mode == 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("Enter the elements (row-wise) for the matrix A:\n");
                scanf("%d",&A[i][j]);
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("Enter the elements (row-wise) for the matrix B:\n");
                scanf("%d",&B[i][j]);
            }
        }
    }

    if (mode == 4 || mode == 5 || mode == 6 || mode == 7){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("Enter the elemets (row_wise) for the matrix:\n");
                scanf("%d",&A[i][j]);
            }
        }
    }

    //Calls functions for performing required operation
    if (mode==1){
        sum_function(A,B);
    }
    if (mode==2){
        diff_function(A,B);
    }
    if (mode==3){
        product_function(A,B);
    }
    if (mode == 4){
        determinant(A,mode);
    }
    if (mode==5 || mode==6){
        minors_cofactors(A,mode);
    }
    if (mode==7){
        determinant(A,mode);
    }
    return 0;
}