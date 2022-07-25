#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	if(argc != 3)
	{
		printf("syntax : %s <file1> <file2>\n", argv[0]);
	}

	FILE *file1, *file2;
	uint32_t bin1, bin2, res;

	file1 = fopen(argv[1], "rb");
	file2 = fopen(argv[2], "rb");

	if(file1 == NULL)
	{
		printf("Can't open \"%s\"\n", argv[1]);
		exit(-1);
	}

	if(file2 == NULL)
	{
		printf("Can't open \"%s\"\n", argv[2]);
		exit(-1);
	}

	fread(&bin1, 4, 1, file1);
	fread(&bin2, 4, 1, file2);

	fclose(file2);
	fclose(file1);

	bin1 = ntohl(bin1);
	bin2 = ntohl(bin2);

	cal = bin1+bin2;
    printf("%d(%#x) + %d(%#x) = %d(%#x)\n",bin1, bin1, bin2, bin2, cal, cal);


	return 0;
}