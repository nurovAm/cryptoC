void getCofactor(int n, int mat[][n], int temp[][n], 
                 int p, int q)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++) 
        {
            // Copying into temporary matrix 
            // only those element which are 
            // not in given row and column
            if (row != p && col != q) 
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row 
                // index and reset col index
                if (j == n - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding the 
   determinant of matrix. n is current 
   dimension of mat[][]. */
int determinantOfMatrix( int n, int mat[][n])
{
    // Initialize result
    int D = 0; 
 
    //  Base case : if matrix contains 
    // single element
    if (n == 1)
        return mat[0][0];
 
    // To store cofactors
    int temp[n][n]; 
 
    // To store sign multiplier
    int sign = 1; 
 
    // Iterate for each element of 
    // first row
    for (int f = 0; f < n; f++) 
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(n, mat, temp, 0, f);
        D += sign * mat[0][f]
             * determinantOfMatrix(n - 1, temp);
 
        // Terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}



int print_matrix(int i, int matrix[][i] ){
    
     for(int k = 0; k < i; k++){
        for(int l = 0; l < i; l++){
            printf("%d ", matrix[k][l]);   
        }
        printf("\n");
    }
}

char * matrix_encrypt(char * text){
    int i;
    printf("Enter the size of matrix key\n");
    scanf("%d", &i);
    
    if(i > 10){
        printf("Matrix size is too large\n");
        return("Error");
    }
    int matrix[i][i];
    for(int k = 0; k < i; k++){
        for(int l = 0; l < i; l++){
            printf("Element %d, %d ", (k), (l));
            scanf("%d", &matrix[k][l]);   
        }
    }
    printf("Your matrix\n");
    print_matrix(i, matrix);
    int det = determinantOfMatrix(i, matrix);
    printf("Determinate %d", det);
}




