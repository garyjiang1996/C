#include <stdio.h>
int main(){
//1085: A+B for Input-Output Practice (I)
// Your task is to Calculate a + b. Too easy?! Of course! I specially designed the problem for acm beginners. 
//You must have found that some problems have the same titles with this one, yes, all these problems were designed for the same aim
// The input will consist of a series of pairs of integers a and b, separated by a space, one pair of integers per line.
// For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input.
//input:a,b;output:a+b
	// int a,b;
	// while(~scanf("%d%d",&a,&b))
		// printf("%d\n",a+b);
//1086: A+B for Input-Output Practice (II)
// The first line integer means the number of input integer a and b. Your task is to Calculate a + b.
// Your task is to Calculate a + b. The first line integer means the numbers of pairs of input integers.
// For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input.
//input:n,a,b;output:n group of a+b	
	// int n,a,b;
	// scanf("%d",&n);
	// while(n--){
		// scanf("%d%d",&a,&b);
		// printf("%d\n",a+b);
	// }
//1087: A+B for Input-Output Practice (III)
//Input contains multiple test cases. 
//Each test case contains a pair of integers a and b, one pair of integers per line.
//A test case containing 0 0 terminates the input and this test case is not to be processed.
//For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input.
//input:a,b;output: a+b (end with a=b=0)
	// (1)
	// int a,b;
	// while(~scanf("%d%d",&a,&b),a+b)
		// printf("%d\n",a+b);
	// (2)
	// int a,b;
	// while(~scanf("%d%d",&a,&b)&&(a==b==0))
		// printf("%d\n",a+b);
//1088: A+B for Input-Output Practice (IV)
// Your task is to Calculate the sum of some integers.
// Input contains multiple test cases. Each test case contains a integer N, and then N integers follow in the same line. 
// A test case starting with 0 terminates the input and this test case is not to be processed.
// For each group of input integers you should output their sum in one line, and with one line of output for each line in input.
//input:n,t,s;output:n numbers of t add up (end with n=0)
	// int n,t,s=0;
	// while(~scanf("%d",&n)&&n){
		// while(n--){
			// scanf("%d",&t);
			// s+=t;
		// }
		// printf("%d\n",s);
		// s=0;
	// }
//1089: A+B for Input-Output Practice (V)
// Your task is to calculate the sum of some integers.
// Input contains an integer N in the first line, and then N lines follow. Each line starts with a integer M, and then M integers follow in the same line.
// For each group of input integers you should output their sum in one line, and with one line of output for each line in input.
//input:n row m nums;output:each row's sum
	// int n,m,t,s=0;
	// scanf("%d",&n);
	// while(n--){
		// scanf("%d",&m);
		// while(m--){
			// scanf("%d",&t);
			// s+=t;
		// }
		// printf("%d\n",s);
		// s=0;
	// }
//1090: A+B for Input-Output Practice (VI)
// Your task is to calculate the sum of some integers.
// Input contains multiple test cases, and one case one line. Each case starts with an integer N, and then N integers follow in the same line.
// For each test case you should output the sum of N integers in one line, and with one line of output for each line in input.
//input:each row n nums;output:each row's sum
	// int n,t,s=0;
	// while(~scanf("%d",&n)){
		// while(n--){
			// scanf("%d",&t);
			// s+=t;
		// }
		// printf("%d\n",s);
		// s=0;
	// }
//1091: A+B for Input-Output Practice (VII)
// Your task is to Calculate a + b.
// The input will consist of a series of pairs of integers a and b, separated by a space, one pair of integers per line.
// For each pair of input integers a and b you should output the sum of a and b, and followed by a blank line.
//similar with 1085 just add a \n
	// int a,b;
	// while(~scanf("%d%d",&a,&b))
		// printf("%d\n\n",a+b);
	
//1092: A+B for Input-Output Practice
// Your task is to calculate the sum of some integers
// Input contains an integer N in the first line, and then N lines follow. Each line starts with a integer M, and then M integers follow in the same line
// For each group of input integers you should output their sum in one line, and you must note that there is a blank line between outputs.
//similar with 1089 just add a \n
	// int n,m,t,s=0;
	// scanf("%d",&n);
	// while(n--){
		// scanf("%d",&m);
		// while(m--){
			// scanf("%d",&t);
			// s+=t;
		// }
		// printf("%d\n\n",s);
		// s=0;
	// }
	return 0;
}