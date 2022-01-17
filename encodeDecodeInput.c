#include<stdio.h>
#include<string.h>

/* **********************************************************
*
* FileName: encodeDecodeHomeAssign.c
*
* Description : This program is intended to demonstrate encryption and decryption of strings
*				depending on the users input. A user is first asked to select to either encrypt
*			or decrypt a string (which the user inputs). The user can then enter in 
*				as many alphabetical characters/strings (upper & lowercase, with spaces) as they would  
*				like, which will then be either encrypted or decyrpted, depending on the users choice.
*				However, there is a char encoding limit of 200, so if the user exceeds this
*				limit, the program will prompt an error and then ask the user to start the 	
*				process over again. For correct encryption and decyption tables, please refer
*				to the project guidelines, which specifics, for example: DE - A B C D E ...
*				which, in EN, is: EN - Z Y X W V. Therefore if a user chooses to encyrpt a string,
*				the encoding goes from DE -> EN and the result is the following: A -> Z,
*				B-> Y, C -> X, D -> W ... And so forth. It is the same for lowercase letters.
*				Also, the logic is inverted if the user chooses to decode a string.
*				 
*
*
* Programmer : Neil Smyth
*
* Date : 01/01/2022
*
* Version : 1.8
*
********************************************************** */

/* main function below contains all the program logic*/
int main (void) {

	int i;  /* init 'i' variable for the loop counter */
	
	char str[256];  /* var 'str' takes user input to be manipulated. Using [256] to prevent 'buffer overflow' according to: 
					 * https://stackoverflow.com/questions/26330229/strlen-doesnt-work-even-with-include-string-h-in-c */
	
	char choice; /* single char to determine user choice - encode, decode or quit*/
	
	char encryptChar; /* single char for assigning new char - either encoded or decoded char */
	
	int maxStrlen = 200; /* max encoding length set at 200 - be aware strlen func needs to - 1 */
	
	/* main program loop - if broken, program will be ended */
	while (1) {
		
		/* prompts user to choose from options */
		printf("Please select to either Encyrpt or Decyrpt a string. Use 'e' or 'd' to choose .. or 'q' to quit!\n");
		scanf("%s", &choice); 
		
		/* if the user selects 'e' to encrypt a string */	
		if (choice == 'e') {
			
			printf("Enter a string to encode \n");
			fgetc(stdin);  /* used before so '\n' isn't assigned as stdin in fgets (from scanf) */
			fgets(str, sizeof(str), stdin);
			
			i=0; /* loop counter initalised at 0 */
			printf("This is the string to be encoded : %s", str);
			
			/* NB - strlen func adds 1 so we minus 1 for correct result*/
			printf("This is the string len: %d \n", (strlen(str) - 1)); 
			
			/* this section checks users input string length (if it's greater than 200)
			* NB - had to -1 as the strlen func adds 1 - therefore minus 1 = a strlen of 201 is too long
			* but string len <=200 is fine. Also a blank space ' ' counts as char */
			if (strlen(str) - 1 > maxStrlen) {
				
				printf("This is the string len: %d - this is too long. Try again \n", (strlen(str) -1) );
				/* break;  but no longer want to break while loop */
			}
			
			else {
						
				printf("Here is encoded string(s) below:\n");
				
				/* while loop - while string is not NULL terminating char. It loops/increments till it finds a '\0' 
	     		 * this is useful as we can not anticipate how long each user input string will be */
				while (str[i] != '\0') {
				  	
				  	/* this section below checks 'if string index not' in this asscii number range i.e. != 0-65 or 90-97 ... 
					 * this logic essentially checks if each char is is in alphabet (either 'A-Z' or 'a-z') or not.
					 * for reference A=65, Z=90, a=97 and z=122 (asscii table) */
					if (!((str[i] >= 0 && str[i] <65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127))) {
						
						/* if string char (index) is an uppercase char in alphabet - between A&Z*/
						if (str[i] >= 'A' && str[i] <= 'Z') {
							
							/* uppercase formula manipulation: Z + A (90+65) - string char  
			  			     * value e.g 'H' = 72 aka 90 + 65 - 72 = 83 .. ='S'  */
							encryptChar = 'Z' + 'A' - str[i]; 
							 
							/* prints out encrypted char - uppercase*/							  
							printf("%c", encryptChar);
						}
	
						/* if string char (index) is an lowercase char in alphabet range - - between a&z*/
					   	if (str[i] >= 'a' && str[i] <= 'z') {
					   		
					   		/* lowercase formula manipulation: z + a (122+97) - string char 
			  				 * value e.g 'a' = 97 aka..  122 + 97 - 97 = 122 .. ='z'  */
					   		encryptChar = 'z' + 'a' - str[i]; 
							
							/* prints out encrypted char - lowercase*/			  
							printf("%c", encryptChar);
					   		
						}
					   	
					   		
					} 
					
					/* here we check if string index is in range outside asscii alphabet, if so we simply reprint 
					 * which is therefore the same char (i.e. no encoding/decoding) */  
					if (((str[i] >= 0 && str[i] < 65) || (str[i] >90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127))) {
					    	
					    /* if string index char is not an alphabetical char - 
					     * we don't encode or decode - simply reprint it out
					     * i.e. if user inputs '!' then a '!' is returned */ 
					      printf("%c", str[i]);   
					}
					    
					i++; /* while loop increment (+1) index till string is complete */
						
				}
				
				printf("\n"); /* print empty line to give space to view encoded string */
				
			} /* else clause closing brackets */
				
		}
			
			
		/* if the user selects 'd' to decrypt a string */	
		else if (choice == 'd') {
			
			printf("Enter a string to decode \n");
			fgetc(stdin);   /* used before so '\n' isn't assigned as stdin in fgets (from scanf) */
			fgets(str, sizeof(str), stdin);
			
			i=0; /* loop counter initalised at 0 */
			printf("This is the string that will be decoded: %s \n", str);
			
			/* strlen func adds 1 so we minus 1 for correct result*/
			printf("This is the string len: %d \n", (strlen(str) - 1));
			
			/* this section checks users input string length (if it's greater than 200)
			* NB - had to -1 as the strlen func adds 1 - therefore minus 1 = a strlen of 201 is too long
			* but string len <=200 is fine. Also a blank space ' ' counts as char */
			if (strlen(str) - 1 > maxStrlen) {
				
				printf("This is the string len: %d - this is too long (>200 in len). Try again \n", (strlen(str) - 1));
				
			}
			
			else {
			
				/* while loop - while string is not NULL terminating char. It loops till it finds a '\0' 
				*  this is useful as we can not anticipate how long each user input string will be */
				while (str[i] != '\0') {
				  	
					  /* this section  below checks 'if string index not' in this asscii number range i.e. != 0-65 or 90-97 etc. 
					 * this logic essentially checks if each char is is in alphabet (either 'A-Z' or 'a-z')  
					 * for reference A=65, Z=90, a=97 and z=122 (see asscii table) */
					if (!((str[i] >= 0 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127))) {
					 	
						 /* if string char is an uppercase letter in alphabet*/
						if (str[i] >= 'A' && str[i] <= 'Z')  {
							
							/* uppercase formula manipulation Z + A (90+65) - string char  
				  			 * value e.g 'H' = 72 aka 90 + 65 - 72 = 83 .. ='S'  */
							encryptChar = 'Z' + 'A' - str[i];  
							
							/* below prints out decrypted char - uppercase*/					  
							printf("%c", encryptChar);
						}
							
						/* if string char is a lowercase letter in alphabet*/
					   	if (str[i] >= 'a' && str[i] <= 'z') {
					   			
					   		/* lowercase formula manipulation: z + a (122+97) - string char 
				  			 * value e.g 'a' = 97 aka..  122 + 97 - 97 = 122 .. ='z'  */
							encryptChar = 'z' + 'a' - str[i];  
							
							/* below prints out decrypted char - lowercase*/								  
							printf("%c", encryptChar);
						}
					   	  		
					} 
					  
					/* here we check if string index is in range outside asscii alphabet, if so we simply reprint 
					 * which is therefore the same char (i.e. no encoding/decoding) */    
					if (((str[i] >= 0 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] <= 127))) {
					      
					      /* if string index char is not an alphabetical char - 
						   * we don't encode or decode - simply reprint it out
						   * i.e. if user inputs '!' then a '!' is returned */ 
						  printf("%c", str[i]);   
					}
					    
					i++; /* increment loop index till string(s) is complete */
				}
				
				printf("\n"); /* print empty line to give space to view encoded string */
				
			}
		}
			
		/* user selects to 'quit' the encode/decode section. While loop is broken and program ends */
		else if (choice == 'q') {
				
				printf("You have chosen to quit \n");
				break; 
		}
		
		else {
			/* prompts user to enter correct choice - continues via loop*/
			printf("Please enter the correct value - 'e' to encyrpt, 'd' to decrypt or 'q' to quit! \n");
		}
			
	}
	
	printf("Program ended - Goodbye \n");
	
	system("pause");
	return 0;
}