#include <stdio.h>
#define N 4

typedef long array_t[N][N];

void transpose(array_t a)
{
	 for (long i = 0; i < N; ++i)
	 {
		 for (long j = 0; j < i; ++j)
		 {
			 long t1 = a[i][j];
			 long t2 = a[j][i];
			 a[i][j] = t2;
			 a[j][i] = t1;
		 }
	}
}

void transposeOpt(array_t a)
{
	for (long i = 0; i < N; ++i)
	{
		long *rp = &a[i][0]; //pointer to row
		long *cp = &a[0][i]; //pointer to column
		for (long j = 0; j < i; ++j)
		{
			long t1 = *rp;
			long t2 = *cp;
			*rp = t2;
			*cp = t1;
			rp ++;
			cp += 4;
		}
	}
}

/*
.L3:
	movq (%rax), %rcx //takes the value of a[i][j] and stores it in t1
	movq (%rdx), %rsi //takes the value of a[j][i] and stores it in t2
	movq %rsi, (%rax) //assigns a[i][j] with value at a[j][i]
	movq %rcx, (%rdx) //assigns a[j][i] with value at a[i][j]
	addq $8, %rax //shifts the pointer to a[i] over to a[i+1]
	addq $32, %rdx //shifts the pointer to a[][j] to a[j+4]
	cmpq %r9, %rax //ending condition of for loop j < i
	jne .L3 //jump back to start of for loop based on flag evaulation
 */
void print_a(array_t a)
{
	for (int i = 0; i < N; ++i)
	{
		if (i == 0)
		{
			printf("{{");
		}else
		{
			printf("{");
		}
		for (int j = 0; j < N; ++j)
		{
			if (j == N -1 & i == N-1)
			{
				printf("%ld}", a[i][j]);
			}else if (j == N-1)
			{
				printf("%ld}, ", a[i][j]);
			}else
			{
				printf("%ld, ", a[i][j]);
			}
		}
	}printf("}\n");
}

int main ()
{
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,16}};
	array_t b = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,16}};

	printf("Transpose output:\n");
	transpose(a);
	print_a(a);

	printf("TransposeOpt output:\n");
	transposeOpt(b);
	print_a(b);

	return 0;

}
