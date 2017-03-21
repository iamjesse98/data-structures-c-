#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Default Size of the data set */
#define N_DEFAULT 100

/* data type: POINT (in two-dimension) */
typedef struct {
   double x;        /* x-coordinate */
   double y;        /* y-coordinate */
} POINT;

/* Generate a list of n random POINTs */
POINT *genInput ( int n ) {
   POINT *P = NULL;
   int i;

   /* seed the random number generator by current time */
   srand((unsigned int)time(NULL));

   P = (POINT *)malloc(n * sizeof(POINT));
   for (i=0; i<n; ++i) {
      P[i].x = (double)rand() / 2147483648.;
      P[i].y = (double)rand() / 2147483648.;
   }
   return P;
}

/* merge-sort a list of POINTs in increasing order of x-coordinate */
void sortInput ( POINT *P, int n ) {
   int i, j, k, n1, n2;
   POINT *Q;

   if (n == 1) return; // base case
   n1 = n/2; n2 = n-n1; // first half, second half

   sortInput(P, n1); // first half
   sortInput(&P[n1], n2); // second half

   Q = (POINT *) malloc ( n * sizeof(POINT) );
   i = 0; j = n1;

   for (k = 0; k < n; ++k) {
      if (i >= n1) Q[k] = P[j++];
      else if (j >= n) Q[k] = P[i++];
      else if (P[i].x < P[j].x) Q[k] = P[i++];
      else Q[k] = P[j++];
   }

   for (k = 0; k < n; ++k) P[k] = Q[k]; // update P

   free(Q);
}

/* print the input POINTs to the data file "CH1.dat" */
void printInput ( POINT *P, int n ) {
   int i;
   for (i = 0; i < n; ++i) {
      printf("%12.10lf %12.10lf\n", P[i].x, P[i].y);
   }
}

/* Main Program Execution Starts Here  */
int main ( int argc, const char *argv[] ) {
	int n;
	POINT *P;

	/* argv[1] - can be overridden */
	n = (argc > 1) ? atoi(argv[1]) : N_DEFAULT;

	/* Generate the input POINT set */
	P = genInput(n);      

	/* Sort the POINT set by x-coordinate */
	sortInput(P,n); // array, # of elems

	/* Print the point in the POINT set */
	printInput(P,n);

	/* Release the memory */
	free(P);
}
