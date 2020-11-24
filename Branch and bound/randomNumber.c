#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  srand((int)time(0));
  FILE *fptr;
  fptr = fopen("input.txt", "w");

  if (fptr == NULL)
  {
    printf("Errol");
    exit(0);
  }
  int x[100][100];
  int n = 2;
  fprintf(fptr,"%d\n",n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        x[i][j] = 0;
      else
      {
        int c = rand() % 100;
        x[i][j]=c;
         
       
      }
       fprintf(fptr,"%d ", x[i][j]);
    }
     fprintf(fptr,"\n");
  }
 
  fclose(fptr);
  return 0;
}