#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MATRIX_SIZE 0xA00

typedef enum { false, true } bool;

void swaprows(unsigned int size, float *matrix, unsigned int row1, unsigned int row2)
{
  float buffer;
  int i;
  for(i=0;i<size;i++)
  {
    buffer = matrix[row1*size + i];
    matrix[row1*size + i] = matrix[row2*size+i];
    matrix[row2*size + i] = buffer;
  }
}

void rowechelon( unsigned int size, float *matrix )
{
  // for each column
  unsigned int col,i,j,row=size;
  bool fixed[size];
  unsigned int highest_row_not_fixed;
  for(i=0;i<size;i++) fixed[i] = false;
  for(col=0;col<size;col++)
  {
    highest_row_not_fixed = size;
    for(i=0;i<size;i++)
    {
      if(!fixed[i])
      {
        if(highest_row_not_fixed > i) highest_row_not_fixed = i;
        if(matrix[i*size + col])
        {
          row = i;
          break;
        }
      }
    }
    if(!matrix[row*size + col]) continue;
    // make the leading value in row equal 1
    float reciprocal = 1 / matrix[row*size + col];
    for(i=0;i<size;i++) matrix[row*size + i] *= reciprocal;
    unsigned int r = highest_row_not_fixed;
    swaprows(size,matrix,row,r);
    fixed[r] = true;
    // zero this column in all following rows
    for(i=r+1;i<size;i++)
    {
      float c = matrix[i*size+col];
      for(j=0;j<size;j++) matrix[i*size + j] -= c * matrix[r*size + j];
    }
  }
}

int main()
{
  // create a matrix
  unsigned int size = MATRIX_SIZE;
  float *matrix = (float *)malloc(sizeof(float)*size*size);
  int i,j;
  srand(size);
  for( i=0; i<size; i++)
  {
    for( j=0; j<size; j++)
    {
      matrix[i*size +j] = (float)(rand() % 9);
    }
  }
  rowechelon( size, matrix);
  free(matrix);
}
