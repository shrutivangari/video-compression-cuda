#include <stdio.h>

int main(void)
{
   static const char filename1[] = "a.txt";
   static const char filename2[] = "b.txt";
   FILE *file1 = fopen(filename1, "r");
   FILE *file2 = fopen(filename2, "r");
  size_t i,j,m,n,p,q;
   int array1[3][3];
  int array2[3][3];
  int array3[3][3];
  int sum=0;
   
   if (file1 == NULL || file2 == NULL)
   {
       perror(filename1);
       perror(filename2);
   }
   
   if(file1 || file2)
   {     
      for (i = 0; i < sizeof array1 / sizeof *array1; ++i )
      {
         for (j = 0; j < sizeof array1 / sizeof *array1; ++j )
         {
            if ( fscanf(file1, "%d", &array1[i][j]) != 1 )
            {
               puts("error in file");
               return 0;
            }
         }
      }
      
      
   for (m = 0; m < sizeof array2 / sizeof *array2; ++m )
      {
         for (n = 0; n < sizeof array2 / sizeof *array2; ++n )
         {
            if ( fscanf(file2, "%d", &array2[m][n]) != 1 )
            {
               puts("error in file");
               return 0;
            }
         }
      }
      
   

   for (p = 0; p < sizeof array3 / sizeof *array3; ++p )
      {
         for (q = 0; q < sizeof array3 / sizeof *array3; ++q )
         {
            array3[p][q] = array2[p][q] - array1[p][q];
            printf("%4d", array3[p][q]);
            sum += array3[p][q];
                         
         }
         putchar('\n');
      }
      printf("Sum is %d", sum);
      fclose(file1);
      fclose(file2);
   return 0;
}
}
