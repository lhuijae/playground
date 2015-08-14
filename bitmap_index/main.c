#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BITPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N (24*32*12*50)

int
get(unsigned long *bitmap, int i)
{
	return (bitmap[i >> SHIFT] & (1 << (i & MASK))) ? 1 : 0;
}

void
set(unsigned long *bitmap, int i)
{
	bitmap[i >> SHIFT] |= (1 << (i & MASK));
}

void
clr(unsigned long *bitmap, int i)
{
	bitmap[i >> SHIFT] &= ~(1 << (i & MASK));
}
#if 0
int
main(int argc, char *argv[])
{
	unsigned long  size = 1 + N / BITPERWORD;
	unsigned long *bitmap = (unsigned long *) malloc(size);
	if (bitmap)
	{
		memset(bitmap, 0, size);
		set(bitmap, 100);
		fprintf(stderr, "%d\n", get(bitmap, 100));
		fprintf(stderr, "%d\n", get(bitmap, 101));
		free(bitmap);
	}

	return 0;
}
#endif
