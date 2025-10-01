#include <stdio.h>
#include <string.h>

void reverseAndInverseCapitalize(char string[]){
	
	int length = strlen(string);
	
	for(int i = 0; i < length; i++){
		if(string[i] >= 65 && string[i] <= 90){
			string[i] += 32;
		}else if (string[i] >= 97 && string[i] <= 122){
			string[i] -= 32;
		}
	}
	
	for(int i = length - 1; i >= 0; i--){
		printf("%c", string[i]);	
	}
	
}

int main(){
	char string[101];
	scanf("%[^\n]", string); getchar();
	
	reverseAndInverseCapitalize(string);
	  
	return 0;
}