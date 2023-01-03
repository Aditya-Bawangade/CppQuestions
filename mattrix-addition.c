#include<stdio.h>
int main(){
    int rows,cols;
    scanf("%d",&rows);
    scanf("%d",&cols);
    int mat1[rows][cols];
    int mat2[rows][cols];
    int ans[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",(*(mat1+i)+j));
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",(*(mat2+i)+j));
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            *(*(ans+i)+j) = *(*(mat1+i)+j) + *(*(mat2+i)+j);
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d",*(*(ans+i)+j));
            printf(" ");
        }
        printf("\n");
    }
    
    return 0;


}