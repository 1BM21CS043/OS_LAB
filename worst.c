#include <stdio.h>
 #include <conio.h>
 #define max 25
 void main()
 {
 int frag[max], b[max], f[max], i, j, nb, nf, temp;
 int bf[max], ff[max];
 printf("\n\tMemory Management Scheme- First Fit");
 printf("\nEnter the number of blocks:");
 scanf("%d", &nb);
 printf("Enter the number of files:");
 scanf("%d", &nf);
 printf("\nEnter the size of the blocks:\n");
 for (i = 1; i <= nb; i++)
 {
 printf("Block %d:", i);
 scanf("%d", &b[i]);
 }
 printf("Enter the size of the files:\n");
 for (i = 1; i <= nf; i++)
 {
 printf("File %d:", i);
 scanf("%d", &f[i]);
 }
 for (i = 1; i <= nf; i++)
 {
 temp =-1; // Reset temp to-1 for each new file
 for (j = 1; j <= nb; j++)
{
 if (bf[j] != 1)
 {
 if (b[j] >= f[i])
 {
 ff[i] = j;
 temp = b[j]- f[i];
 break;
 }
 }
 }
 frag[i] = temp;
 if (temp !=-1)
 {
 bf[ff[i]] = 1;
 }
 }
 printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
 for (i = 1; i <= nf; i++)
 {
 }
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
 getch();
 }
