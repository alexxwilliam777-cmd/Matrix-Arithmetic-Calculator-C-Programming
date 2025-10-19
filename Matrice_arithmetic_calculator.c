#include<stdio.h>
#include<stdlib.h>

//This function sums the two matrices and prints the result
void sum_function(int A[][3], int B[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%4d ",A[i][j]+B[i][j]);
        }printf("\n");
    }
}

//This function substract the two matrices and prints the result
void diff_function(int A[][3], int B[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%4d ",A[i][j]-B[i][j]);
        }printf("\n");
    }

}

//This function multiplies the two matrices and prints the result
void product_function(int A[][3],int B[][3]){
    int i = 0;
    int j = 0;
    int *a = malloc(sizeof(int) * 9);
    int *b = malloc(sizeof(int) * 9);
    int *c = malloc(sizeof(int) * 9);
    int t = 0;

    for(int n = 0, i = 0, j = 0; n < 3, j<3; n++, j++){
        a[n] = A[i][j];
        for(int n = 3, i = 1, j = 0; n < 6, j<3; n++, j++){
            a[n] = A[i][j];
            for(int n = 6, i = 2, j = 0; n < 9, j<3; n++, j++){
                a[n] = A[i][j];
            }
        }
    }
    for(int n = 0, j = 0, i = 0; n < 3, i < 3; n++, i++){
        b[n] = B[i][j];
        for(int n = 3, j = 1, i = 0; n < 6, i < 3; n++, i++){
            b[n] = B[i][j];
            for(int n = 6, j = 2, i = 0; n < 9, i < 3; n++, i++){
                b[n] = B[i][j];
            }
        }
    }
    for(i = 0, j = 0; i < 3, j < 3; i++, j++){
        t += a[i]*b[j];
        c[0] = t;
    }
    t = 0;
    for(i = 0, j = 3; i < 3, j < 6; i++, j++){
        t += a[i]*b[j];
        c[1] = t;
    }
    t = 0;
    for(i = 0, j = 6; i < 3, j < 9; i++, j++){
        t += a[i]*b[j];
        c[2] = t;
    }
    t = 0;
    for(i = 3, j = 0; i < 6, j < 3; i++, j++){
        t += a[i]*b[j];
        c[3] = t;
    }
    t = 0;
    for(i = 3, j = 3; i < 6, j < 6; i++, j++){
        t += a[i]*b[j];
        c[4] = t;
    }
    t = 0;
    for(i = 3, j = 6; i < 6, j < 9; i++, j++){
        t += a[i]*b[j];
        c[5] = t;
    }
    t = 0;
    for(i = 6, j = 0; i < 9, j < 3; i++, j++){
        t += a[i]*b[j];
        c[6] = t;
    }
    t = 0;
    for(i = 6, j = 3; i < 9, j < 6; i++, j++){
        t += a[i]*b[j];
        c[7] = t;
    }
    t = 0;
    for(i = 6, j = 6; i < 9, j < 9; i++, j++){
        t += a[i]*b[j];
        c[8] = t;
    }
    free(a);
    free(b);

    for(i = 0; i < 3; i++){
        printf("%4d ",c[i]);
    }printf("\n");
    for(i = 3; i < 6; i++){
        printf("%4d ",c[i]);
    }printf("\n");
    for(i = 6; i < 9; i++){
        printf("%4d ",c[i]);
    }printf("\n");
    free(c);
    
}

int main(){
    int A[3][3];
    int B[3][3];
    int mode;

//Asking the mode of arithmetic operation
    printf("Enter 1 for addition\nEnter 2 for difference\nEnter 3 for product\n");
    printf("Select mode of operation: ");
    scanf("%d",&mode);

//Storing elements of matrice A
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter elements (row-wise) for matrix A:\n");
            scanf("%d",&A[i][j]);
        }
    }

//Storing elements of matrice B
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter elements (row-wise) for matrix B:\n");
            scanf("%d",&B[i][j]);
        }
    }

//Calls sum function at line 4
    if(mode==1){
        sum_function(A,B);
    }

//Calls difference function at line 13
    if(mode==2){
        diff_function(A,B);
    }
//Calls product function at line 23
    if(mode==3){
        product_function(A,B);
    }
    return 0;

}