#include <stdio.h>

#define BUF_SIZE 10

int main(){
//_IOFBF (满缓冲)：当缓冲区为空时，从流读入数据。或当缓冲区满时，向流写入数据。
//_IOLBF (行缓冲)：每次从流中读入1行数据或向流中写入1行数据。
//_IONBF (无缓冲)：直接从流中读入数据或直接向流中写入数据，而没有缓冲区。
	//setvbuf(stdout,NULL,_IONBF,0);
	//setbuf(stdout,outbuf);
	FILE *input,*output;
	char chbuf[BUF_SIZE];
	input=fopen("file.in","w+");
	output=fopen("file.out","w");
	
	if(setvbuf(input,chbuf,_IOFBF,10)!=0){
		printf("fail to set up buffer for input file\n");
	}else{
		printf("buffer set up for input file\n");
	}
	if(setvbuf(output,NULL,_IOLBF,132)!=0){
		printf("failed to set up buffer for output file\n");
	}else{
		printf("buffer set up for output file\n");
	}
	fclose(input);
	fclose(output);	
	return 0;
}