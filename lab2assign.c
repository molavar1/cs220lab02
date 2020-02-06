#include <stdio.h>





//unsigned long interleave (unsigned int i1, unsigned int i2){
//	unsigned long result = 0;
//  unsigned long temp = 0;
//  unsigned long temp2 = 0;
//	i1 <<32;
//	temp |= i1 & 0xff00ff00;
//	i1 <<8;
//	temp |= i1 & 0x00ff00ff;
//	temp2 |= i2 & 0xff00ff00;
//	i2 <<24;
//	temp2 |= i2 & 0x00ff00ff;
//	result |= temp | temp2;
//
//	return result;
//}
unsigned long interleave (unsigned int i1, unsigned int i2){
	unsigned long result = 0;
	unsigned char *p1 = (unsigned char *) &i1;
	unsigned char *p2 = (unsigned char *) &i2;
	unsigned char *presult = (unsigned char *) &result;
	for(int i = 0; i < sizeof(i1); i++){
		presult[2*i] = p1[i];
		presult[2*i+1] = p2[i];
	}
	return result;

}

void print_raw_bytes(char *start, unsigned intlen){
	unsigned char *s = (unsigned char *) start;
	unsigned int i = 0;
	for(i = 0; i < intlen; i++) {
		printf("%p: %x\n", &start[i], start[i]);
	}
	return;

}

unsigned int count_ones(unsigned int n){
	unsigned int count = 0;
	while(n){
	count += n & 1;
	n >>= 1;
	}
	return count;

}

int main(){
	unsigned int i1 = 0x12345678;
	unsigned int i2 = 0xdeadbeef;
	printf("Ox%x, 0x%x -> 0x%lx\n", i1,i2, interleave(i1,i2));
	print_raw_bytes((char*)&i2, sizeof(i1));
	printf("%d\n", count_ones(5));
	printf("%d\n", count_ones(i1));
	return 0;
}
