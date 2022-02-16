#/*# Start of file changecase.a */
#
#/*# MIPSMARK 1.0 1/5/98 Copyright 1998 J. Waldron. */
#
/* Question:
   write a c function sentenceCase, which takes one argument,
   of type char* (pointer to a string) and changes the case
   of all letters in the string, so that the first character
   is capitalized (UPPERCASE) and all the remaining letters
   are lower case.
   Do not refer to the variable "teststr"
*/
#/*# Output format must be:		*/
#/*# "After 1999 came 2000 \[square brackets\]"		*/
#include <stdio.h>       /* for printf in C programs */
#include <stdlib.h>	 /* for exit() in C programs */


#/*##############################################
#					 	#
#		text segment			#
#						#
#################################################

	.text		
       	.globl __start 
__start:		# execution starts here  */

char anotherteststr[] = "aFtEr 1999 cAmE 2000 [Square Brackets]\n";
//char anotherteststr[] = " zebrA stRIPes @ ZEbra\n";

#/* Any changes above this line will be discarded by
# mipsmark. Put your answer between dashed lines. */
#/*-------------- start cut ----------------------- */

#/*  Student's Name:		Account:		*/


/*  Student's Name:	Jerry Lau	Account: jlau	*/

void sentenceCase(char* s)
{
	/* YOUR CODE GOES HERE */
	
	/*
	if(s[0] == ' '){
        int index = 0;
        for(int i=1;s[i] !='\n'; i++){
            s[i-1] = s[i];
            
            index = i;
        }
	        
        //s[index] = '\n';
	//s[index] = 127;
	s[index] = 8;
    }
	*/

#include <stdbool.h>
	
	bool first = true;
	

    for(int i=0; s[i] !='\n'; i++){
        
        
		if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] < 122)){
		    
		    if(first == true){
		        
		        if(s[0] == ' '){
		            s[i-1] = s[i-1] & ~32;
		        }
		        else{
		            s[i] = s[i] & ~32;
		        }
		        first = false;
		    
		    }
		    else{
		        s[i] = s[i] | 32;
		    }
		}
    }
	
}

#/*
	j __start	#nasty loop if mips program not exited */
#/*--------------  end cut  -----------------------
# Any changes below this line will be discarded by
# mipsmark. Put your answer between dashed lines.

#################################################
#                                               #
#               data segment                    #
#                                               #
#################################################

        .data			#*/
int main()
{  sentenceCase(anotherteststr);
   puts(anotherteststr);
   return 0;
}
#
#/*# End of file changecase.a		*/
