#include <stdlib.h>
#include <stdio.h>
int main()
{

int m[11][11] = {0};
int i=0, j, k, l, n, min, r[11] = {10, 20, 50, 1, 100};
int result=9999;
//system("color 1f");
//printf("Enter number of matrices, n: ");
//scanf("%d", &n);

printf("Enter overlapping dimensions for the matrices\n");
printf("(NB: 11 dimensions maximum, [Ctrl] + Z to end input\n");
printf("    if no dimensions entered, defaults = {10, 20, 50, 1, 100}\n");

result = scanf("%d",&n);
while (result!= EOF)
{
  r[i++]=n;
  //scanf("%d",&r[i]);

   result = scanf("%d",&n);
}

if (i==0)
  n = 4;
 else n = i-1;

for (l=1; l< n; l++)
{
 for (i = 1; i<= n-l; i++)
 {
   j = i+l;
   
   
   //m[i][j] = MAXINT;
   printf("For m_%d,%d: \n", i, j);
   printf("\t k = %d\n", i);
    m[i][j] = m[i][i] + m[i+1][j] + r[i-1]*r[i]*r[j];
   printf("\t cost = %d + %d + ( %d x %d x %d )\n\t      = %d\n",m[i][i] ,m[i+1][j] , r[i-1],r[i],r[j], m[i][j]);


    for(k = i+1; k < j; k++)
     {
      int v = m[i][k] + m[k+1][j] + r[i-1]*r[k]*r[j];

       printf("\t k = %d\n", k);
 printf("\t cost = %d + %d + ( %d x %d x %d )\n\t      = %d\n\n",m[i][k] ,m[k+1][j] , r[i-1],r[k],r[j], v);
        if (  v < m[i][j])
           m[i][j] = v;
     }
 }
}



printf("\n\nTable is:\n");
for (l=1; l<= n; l++)
     {
        for (i = 1; i<= n-l; i++)
         printf("%d\t",m[i][i+l]);
     printf("\n");
    }

//    system("PAUSE");
      return 0;
}
