#include <stdio.h>

unsigned long interleave(unsigned int i1, unsigned int i2)
{
	unsigned long res = 0;
	char *pi1, *pi2, *pi3;
	pi1 = (char *) &i1;
	pi2 = (char *) &i2;
	pi3 = (char *) &res;
	int i;
	for(i = 0; i < 4; i++) {
		pi3[2*i] = pi2[i];
		pi3[2*i+1] = pi1[i];
	}
	return res;
}
unsigned long interleave1(unsigned int i1, unsigned int i2)
{
	unsigned long ret = 0;
	/* We are going to use unsigned long temp variables so we don't shift out of bounds */
	unsigned long t1 = i1;
	unsigned long t2 = i2;

	ret |= (t1 & 0xff000000) << 32;
	ret |= (t2 & 0xff000000) << 24;
	ret |= (t1 & 0xff0000) << 24;
	ret |= (t2 & 0xff0000) << 16;
	ret |= (t1 & 0xff00) << 16;
	ret |= (t2 & 0xff00) << 8;
	ret |= (t1 & 0xff) << 8;
	ret |= t2 & 0xff;

	return ret;
}

void print_raw_bytes(char *start, unsigned int len)
{
	unsigned char *s = (unsigned char *) start;
	unsigned int i = 0;
	for(i = 0; i < len; i++) {
		printf("%p: %x\n", &start[i], start[i]);
	}
	return;
}

#define BITS_PER_BYTE 8
unsigned int count_ones(unsigned int n)
{
	int i;
	unsigned int count = 0;
	for(i = 0; i < sizeof(n) * BITS_PER_BYTE; i++) {
		if( (n >> i) & 1 )
			count ++;
	}
	return count;
}

int main()
{
	unsigned int i1 = 0x12345678;
	unsigned int i2 = 0xdeadbeef;
	printf("0x%x, 0x%x -> 0x%lx\n", i1,i2, interleave(i1,i2));
	print_raw_bytes((char *)&i1, sizeof(i1));
	printf("%x -> %u 1's\n", i2, count_ones(i2));
	printf("%d\n", count_ones(5));
	printf("%d\n", count_ones(i1));
	return 0;
}
