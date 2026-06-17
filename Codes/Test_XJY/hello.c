	#include <stdio.h>

	typedef unsigned char uint_8t;
	typedef unsigned int  uint_32t;

	int main(){
		uint_8t val1 = 0xFF;
		uint_32t val2 = 0xFFFFAAAA;
		printf("val1 = 0x %08X\n",val1);
		printf("val2 = 0x %08X\n",val2);
		return 0;
	}
