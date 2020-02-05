#include <stdio.h>





unsigned long interleave (unsigned int i1, unsigned int i2){
	unsigned long result = 0;
	unsigned long temp = 0;
	unsigned long temp2 = 0;
	i1 <<32; 
	temp |= i1 & 0xff00ff00;
	i1 <<8; 
	temp |= i1 & 0x00ff00ff;
	temp2 |= i2 & 0xff00ff00;
	i2 <<24; 
	temp2 |= i2 & 0x00ff00ff;
	result |= temp | temp2;
	
	return result;
	

}

void print_raw_bytes(char *start, unsigned intlen){
	

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
	//print_raw_bytes(&i2, sizeof(i1));
	printf("%d\n", count_ones(5));
	printf("%d\n", count_ones(i1));
	return 0;
}	
