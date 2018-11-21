/*	
	The below code is redistributed under the MIT license 

*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

//booleans
#define FALSE 0
#define TRUE 1

//colors
#define DEFAULT 15
#define BLACK 0
#define GREEN 2
#define RED 4
#define LIME 10
#define AQUA 11
#define PINK 13
#define YELLOW 14


int main(void) {
	int start = TRUE;

	char gender, size, option[32];
	int top = FALSE, bot = FALSE, acc = FALSE;

	int failed_tries = 0;
	int card = FALSE, store = FALSE;
	int card_number, PIN;
	int PIN_valid = FALSE;

	char promo_code[4], verify_code[4];
	char proceed[4];
	int c = FALSE, d = FALSE;

	float cost, total;
	int i = 0;

	int exited = FALSE;

	//MAIN MENU PROGRAM START
	while (start) {
		//Some rather important initializations for the smooth execution after an "Exit"
		exited = FALSE;
		card = FALSE;
		store = FALSE;
		c = FALSE;
		d = FALSE;
		top = FALSE;
		bot = FALSE;
		acc = FALSE;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);  //elegant :O
		system("cls");
		printf("\n +-------[ DEM & OUP CLOTHING STORES LLC. ]-------+");
		printf("\n\n\n Before we start \n  Let us know of your gender (M/F)  \|");
		scanf_s(" %c", &gender);

		//CHECKING GENDER
		while (gender != 'F' && gender != 'M') {
			printf("\nType M or F to show your gender \|");
			scanf_s(" %c", &gender);
		}

		//MALE MENU 
		if (gender == 'M') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AQUA);
			while (TRUE) {
				system("cls");
				printf("+-------[ MALE MENU ]-------+\n\n"); 
				

				printf("Tops - Bottoms - Accessories\nType 'Exit' to go the previous menu");
				printf("\n\nChoose a product!  \|");
				scanf_s("%s", &option, 32);

				if (strcmp(option, "Exit") == 0) {
					exited = TRUE;
					break;
				}

				//TOPS
				if (strcmp(option, "Tops") == 0) {
					cost = 5.99;	//COST FOR TOPPER
					top = TRUE;
					system("cls");
					printf("\n\nAmazing Toppers for Men, only 5.99$!\n\n");
					printf("\nChoose your desired size  \|");
					scanf_s(" %c", &size);

					while (size != 'S' && size != 'M' && size != 'L') {
						printf("\nOops, seems like you entered something wrong..\nTry using S, M or L  \|");
						scanf_s(" %c", &size);
					}
					break;

				}
				//BOTTOMS
				if (strcmp(option, "Bottoms") == 0) {
					cost = 15.99;	//COST FOR BOTTOMS
					bot = TRUE;
					system("cls");
					printf("\n\nAmazing Bottoms for Men, only 15.99$!\n\n");
					printf("\nChoose your desired size  \|");
					scanf_s(" %c", &size);

					while (size != 'S' && size != 'M' && size != 'L') {
						printf("\nOops, seems like you entered something wrong..\nTry using S, M or L  \|");
						scanf_s(" %c", &size);
					}
					break;

				}
				//ACCESSORIES
				if (strcmp(option, "Accessories") == 0) {
					cost = 1.99;	//COST FOR ACCESSORIES
					acc = TRUE;
					system("cls");
					printf("\n\nAmazing Toppers for Men, only 1.99$!\n\n");
					printf("\nChoose your desired size  \|");
					scanf_s(" %c", &size);

					while (size != 'S' && size != 'M' && size != 'L') {
						printf("\nOops, seems like you entered something wrong..\nTry using S, M or L  \|");
						scanf_s(" %c", &size);
					}
					break;

				}
			}
		}
		//WOMEN MENU
		if (gender == 'F') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);
			while (TRUE) {
				system("cls");
				printf("+-------[ WOMEN MENU ]-------+\n\n");

				printf("Tops - Bottoms - Accessories\nType 'Exit' to go the previous menu");
				printf("\n\nChoose a product!  \|");
				scanf_s("%s", &option, 32);

				if (strcmp(option, "Exit") == 0) {
					exited = TRUE;
					break;
				}

				//TOPS
				if (strcmp(option, "Tops") == 0) {
					cost = 4.99;	//COST FOR TOPPER
					top = TRUE;
					system("cls");
					printf("\n\nAmazing Toppers for Women, only 4.99$!\n\n");
					printf("\nChoose your desired size  \|");
					scanf_s(" %c", &size);

					while (size != 'S' && size != 'M' && size != 'L') {
						printf("\nOops, seems like you entered something wrong..\nTry using S, M or L  \|");
						scanf_s(" %c", &size);
					}
					break;

				}
				//BOTTOMS
				if (strcmp(option, "Bottoms") == 0) {
					cost = 12.99;	//COST FOR BOTTOMS
					bot = TRUE;
					system("cls");
					printf("\n\nAmazing Bottoms for Women, only 12.99$!\n\n");
					printf("\nChoose your desired size  \|");
					scanf_s(" %c", &size);

					while (size != 'S' && size != 'M' && size != 'L') {
						printf("\nOops, seems like you entered something wrong..\nTry using S, M or L  \|");
						scanf_s(" %c", &size);
					}
					break;

				}
				//ACCESSORIES
				if (strcmp(option, "Accessories") == 0) {
					cost = 7.99;	//COST FOR ACCESSORIES
					acc = TRUE;
					system("cls");
					printf("\n\nAmazing Toppers for Women, only 7.99$!\n\n");
					printf("\nChoose your desired size  \|");
					scanf_s(" %c", &size);

					while (size != 'S' && size != 'M' && size != 'L') {
						printf("\nOops, seems like you entered something wrong..\nTry using S, M or L  \|");
						scanf_s(" %c", &size);
					}
					break;

				}
			}
		}

		if (exited) continue;
		//PAYMENT OPTION CHOOSER
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);
		while (TRUE) {

			if (c) break; //Breaking payment loop (menu)
			system("cls");
			printf("Available Payment Methods\n\nStore - Card\n\nType 'Exit' to head back to the main menu  \|");
			scanf_s("%s", &option, 32);

			if (strcmp(option, "Exit") == 0) {
				exited = TRUE;
				break;
			}

			while ((strcmp(option, "Card") != 0) && (strcmp(option, "Store") != 0)) {
				system("cls");
				printf("Oops, seems like you entered something wrong...\n\nTry using Store or Card  \|");
				scanf_s("%s", &option, 32);
			}

			//CARD
			while (TRUE) {

				if (strcmp(option, "Card") == 0) {
					card = TRUE;
					printf("\nInsert your card's number  \|");
					scanf_s("%d", &card_number);

					while (card_number < 9999 || card_number > 99999) {  //5 Digits Card
						printf("\nOops, seems like you entered something wrong...\n\nYour card number is only 5 digits long and can not start with 0!  \|");
						scanf_s("%d", &card_number);
					}
					printf("\nInsert your card's PIN  \|");
					scanf_s("%d", &PIN);

					while (card_number % 5 != PIN) {  //Wrong Pin
						failed_tries += 1;
						if (failed_tries == 3) {
							start = FALSE;
							break;
						}
						printf("\nOops, seems like your PIN is wrong! Try %d of 3  \|", failed_tries + 1);
						scanf_s("%d", &PIN);
					}

					
					if (failed_tries == 3) { //Terminating Program
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						printf("\nFor security reasons the program will now exit...\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
						start = FALSE;
						exited = TRUE;
					}
					PIN_valid = TRUE;
					if (PIN_valid) break;
				}
				else break;
			}if (exited) break;

			//STORE
			if (PIN_valid) break; 
			while (TRUE) {
				if (c) break; //Breaking store loop (menu)
				store = TRUE;
				d = FALSE;
				c = FALSE;
				if (strcmp(option, "Store") == 0) {
					printf("\nInsert the promo code  \|");
					scanf_s("%s", &promo_code, 4);

					//Checking promo code length

					/*	On this part I clearly have almost no idea what the heck I am doing... it does work though
					
						Basically reading the promo code and checking against the \0. if i is not 3 then user will be asked to re-enter the code

						Well, if i is 3 then the while loop will end and will enter the next one where all the confusion starts
					*/

					int i = 0; //the length
					while (!d) {
						while (promo_code[i] != '\0') i++;

						if (i > 3 || i < 3) {
							printf("\nThe code should only be 3 digits long  \|");
							scanf_s("%s", &promo_code, 4);
							d = FALSE;
						}
						if (i == 3) {
							d = TRUE;
							c = TRUE;
						}
					}


					/* On this part, I again have no idea what the heck I am doing although it works.
						It's a marvelous wizardy and hope you atleast kudo me..
						
						temp_code is initiated with 0 0 0 (learned that on theory lessons) which is then filled by the promo_code.

						The temp_code is filled from 2 to 0 and therefore the temp_code is filled with the reversed code
					*/ 

					while (c) { //While incorrect reversed

						printf("\nPlease enter the code in reverse  \|");
						scanf_s("%s", &verify_code, 4);


						//Reversing Array
						int i = 0, j = 2;
						char temp_code[4] = { '0','0','0', '\0' };
						while (i != 3 && j != -1) {

							temp_code[i] = promo_code[j];

							i++;
							j--;
						}

						//Checking reversed Array
						i = 0;
						/*	On this section, things are more clear, you get to check the code arrays element by element and accordingly modify the c boolean
							
						*/

						for (i = 0; i < 3; i++) {
							if (temp_code[i] == verify_code[i]) c = TRUE;
							else c = FALSE;

						}

						if (c) break; //Breaking incorrect promo loop (menu)

					}
				}
			}
		}


		if (exited) continue;
		//CHECKOUT MENU
		while (TRUE) {
			//CALCULATING 20% DISCOUNT
			if (store) total = ((cost * 20 / 100) - cost) * (-1);
			else total = cost;

			i = 0;

			//CONFIRMATION OF PURCHASE
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);

			if (gender == 'M')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AQUA);
			if (gender == 'F')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);

			if (top) printf("Your basket includes \n\t- x1 Topper  ");
			if (bot) printf("Your basket includes \n\t- x1 Bottom  ");
			if (acc) printf("Your basket includes \n\t- x1 Accessory  ");

			if (gender == 'M') printf("For Male gender of size %c\n", size);
			if (gender == 'F') printf("For Female gender of size %c\n", size);

			if (card) printf("Selected Payment Method\n\t -Card (%d)\n", card_number);
			if (store) printf("Selected Payment Method\n\t -Store\n\n");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			printf("Are you sure the above are correct? (Type 'yes')  \|");

			scanf_s("%s", &proceed, 4);
			if (strcmp(proceed, "yes") == 0); // if (condition) then pass
			else break; // Back to Gender Selection






			//RECEIPT - FINALIZATION
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
			system("cls");
			printf("\n +-------[ RECEIPT ]-------+ \n\n");

			if (gender == 'M')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AQUA);
			if (gender == 'F')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);

			if (top) printf(" Your order \n\t- x1 Topper ");
			if (bot) printf(" Your order \n\t- x1 Bottom ");
			if (acc) printf(" Your order \n\t- x1 Accessory ");

			if (gender == 'M') printf("for Male gender of size %c\n\n", size);
			if (gender == 'F') printf("for Female gender of size %c\n\n", size);

			if (card) printf(" Selected Payment Method\n\t -Card (%d)\n", card_number);
			if (store) printf(" Selected Payment Method\n\t -Store\n\n");


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			if (store) printf(" Paying with Cash (Store) earned you a unique one-time 20%% DISCOUNT\n");  // %% for escaping %
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIME);

			printf("\n\n Total Order Cost %.2f$", total);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
			printf("\n\n +-------[ RECEIPT ]-------+ \n\n\n\n\n\n");
			
			i++;
			if (i == 1) break;


		}
		if (i == 1) break; //exiting program

	}//Program loop
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
	system("pause");   //for echoing purposes on the executable file
	return(0);
}
