#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//allocating the array on the heap and passing back the pointer
//so the main function can access the string. 
char* getLetters(int lengthOfString) {
    char* stringP = malloc(sizeof(char) * (lengthOfString+1));
    char startingChar = 'A';

    for(int i = 0; i < lengthOfString; i++){
        *(stringP+i) = startingChar+i;
    }
    *(stringP+lengthOfString) = '\0';

	return stringP;
}

//this takes a 2 character string and turns it into a 2 digit number.
int toInt(char* string){
    int firstRow = *string - 48;
    int secondRow = *(string+1) - 48;

    if (secondRow > -1){
        firstRow = firstRow * 10;
    } else {
        secondRow = 0;
    }

    int num = firstRow + secondRow;

    if (num > 26){
        num = 26;
    }
    else if (num < 0){
        num = 0;
    }

    return num;
}


int main() {
	char gotLetter[4];

    printf("how many characters would you like to print? (max of 26): "); 
    fgets(gotLetter, 4, stdin);

    gotLetter[strcspn(gotLetter, "\n")] = 0;
    int num = toInt(gotLetter);

    char* stringP = getLetters(num);

    printf("[ %s ]", stringP);

    free(stringP);

    printf("\n\npress ENTER to close");

    getchar();
	return 1;
}