/************************************************************************************************
 * Task		: EE5803 FPGA Lab Assignment 1
 * Author 	: Sumanth Naidu Merugula 
 * Roll number 	: EE22MTECH02004
 * Description 	: Reducing the following Boolean Expression to its simplest form using K-map 
 *		  G(U,V,W,Z)=∑(3,5,6,7,11,12,13,15) and realising the same using NAND logic in C           
 ************************************************************************************************/

/*
 * Header files 
 */ 
#include <stdio.h>
#include <stdbool.h>


/*
 * Function definition for 2 input NAND
 */
bool nand(bool a,bool b)
{
	return !(a && b);
}

/*
 * Function definition for 3 input NAND using 2 input NAND
 */
bool nand3(bool a,bool b, bool c )
{
	return nand(nand(nand(a,b),nand(a,b)),c);
}

/*
 * Function definition for 4 input NAND using 2 input NAND
 */
bool nand4(bool a,bool b,bool c,bool d)
{
	return nand(nand(nand(a,b),nand(a,b)),nand(nand(c,d),nand(c,d)));
}



/*
 * Main function definition
 */
void main()
{
	//Inputs and output variables
	bool U,V,W,Z,G;
	//Temporary variables
	int i,temp;
	//To print the truth table for the derived logic using K-map and NAND realisation
	printf("decimal\tU\tV\tW\tZ\tG\n");
	for(i=0;i<16;i++)
	{
		temp=i;
    		Z=i%2;
    		temp/=2;
    		W=temp%2;
    		temp /=2;
    		V=temp%2;
    		temp /=2;
    		U = temp%2;
    		G = nand4(nand(W,Z),nand(V,Z),nand3(U,V,nand(W,W)),nand3(nand(U,U),V,W));
    		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,U,V,W,Z,G);
	}
}

/*
 * Printed truth table 
 */
/*
decimal	U	V	W	Z	G
0	0	0	0	0	0
1	0	0	0	1	0
2	0	0	1	0	0
3	0	0	1	1	1
4	0	1	0	0	0
5	0	1	0	1	1
6	0	1	1	0	1
7	0	1	1	1	1
8	1	0	0	0	0
9	1	0	0	1	0
10	1	0	1	0	0
11	1	0	1	1	1
12	1	1	0	0	1
13	1	1	0	1	1
14	1	1	1	0	0
15	1	1	1	1	1
*/




