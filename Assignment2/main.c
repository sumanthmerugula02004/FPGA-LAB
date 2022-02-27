/************************************************************************************************
 * Task		      : EE5803 FPGA Lab Assignment 2
 * Author 	    : Sumanth Naidu Merugula 
 * Roll number 	: EE22MTECH02004
 * Description 	: Reducing the following Boolean Expression to its simplest form using K-map 
 *		            G(U,V,W,Z)=∑(3,5,6,7,11,12,13,15) and realising the same using NAND logic 
 *                in C and testing it using an Arduino UNO        
 ************************************************************************************************/
/*
 * Header files 
 */ 
#include <avr/io.h>
#include <util/delay.h>
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
int main()
{
	
	/*
	* Setup
	*/
	DDRB = DDRB | 0b00000001;	// B0 as OUTPUT
	DDRD = DDRD & 0b11100001;	// D1, D2, D3, D4 as INPUTS
	/*
	* Loop
	*/
	while(1)
	{
		bool U = PIND & 0b00000010;
		bool V = PIND & 0b00000100;
		bool W = PIND & 0b00001000;
		bool Z = PIND & 0b00010000;
		bool G = nand4(nand(W,Z),nand(V,Z),nand3(U,V,nand(W,W)),nand3(nand(U,U),V,W));	
		_delay_ms(1000);
		if(G)
			PORTB = PORTB | 0b00000001;    // Set B0 as HIGH
		else
			PORTB = PORTB & !(0b00000001); // Set B0 as LOW	
	}// End of while 1
}// End of main
	
