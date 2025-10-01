#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct of menu / columns
struct menu{
	char location[100];
    char city[100];
    int price;
    int rooms;
    int bathroom;
    int carparks;
    char type[100];
    char furnish[100];
};

menu data[10000];
int n = 0;

// to read .csv file
void readData(){
	char dataName[100];
	
	FILE *readData = fopen("file.csv", "r");
	
	fscanf(readData, "%[^\n]\n", dataName);
	
	n = 0;
	
	while(feof(readData) == false){
		fscanf(readData, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", 
		data[n].location, data[n].city, &data[n].price, 
		&data[n].rooms, &data[n].bathroom, &data[n].carparks, 
		data[n].type, data[n].furnish);
		n++;
	}
	fclose(readData);
}

//to rewrite/ rename .csv file
void writeData(char name[]){
	FILE *writeData = fopen(name, "w");
	
	fprintf(writeData, "Location ,City,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
	
	for(int i = 0; i < n; i++) {
		fprintf(writeData, "%s,%s,%d,%d,%d,%d,%s,%s\n", data[i].location, data[i].city, data[i].price, 
		data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
	}
	fclose(writeData);
}

//to search any data at .csv file
void searchData(char column[], int dataint, char datastring[]){
	bool found = false;
	
	//to search any data at each columns 
	if(strcmp(column, "Location") == 0){
		for(int i = 0; i < n; i++){
			if(strcmpi(data[i].location, datastring) == 0){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "City") == 0){
		for(int i = 0; i < n; i++){
			if(strcmpi(data[i].city, datastring) == 0){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "Price") == 0){
		for(int i = 0; i < n; i++){
			if(data[i].price == dataint){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "Rooms") == 0){
		for(int i = 0; i < n; i++){
			if(data[i].rooms == dataint){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "Bathroom") == 0 ){
		for(int i = 0; i < n; i++){
			if(data[i].bathroom == dataint){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "Carpark") == 0){
		for(int i = 0; i < n; i++){
			if(data[i].carparks == dataint){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "Type") == 0){
		for(int i = 0; i < n; i++){
			if (strcmp(data[i].type, datastring) == 0){
				found = true;
				break;
			}
		}
	}
	
	else if(strcmp(column, "Furnish") == 0){
		for(int i = 0; i < n; i++){
			if(strcmp(data[i].furnish, datastring) == 0){
				found = true;
				break;
			}
		}
	}
	
	// if any data's found inside of columns
	if(found == true){
		puts("Data found. Detail of data: ");
			
		printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
		
		if(strcmp(column, "Location") == 0){
			for(int i = 0; i < n; i++){
				if(strcmp(datastring, data[i].location) == 0){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "City") == 0){
			for(int i = 0; i < n; i++){
				if(strcmp(datastring, data[i].city) == 0){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "Price") == 0){
			for(int i = 0; i < n; i++){
				if (data[i].price == dataint){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "Rooms") == 0){
			for(int i = 0; i < n; i++ ){
				if(data[i].rooms == dataint){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "Bathroom") == 0){ 
			for(int i = 0; i < n; i++){
				if (data[i].bathroom == dataint){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "Carpark") == 0){
			for(int i = 0; i < n; i++){
				if(data[i].carparks == dataint){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "Type") == 0){
			for(int i = 0; i < n; i++){
				if(strcmp(datastring, data[i].type) == 0){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
		
		else if(strcmp(column, "Furnish") == 0){
			for(int i = 0; i < n; i++){
				if(strcmp(datastring, data[i].furnish) == 0){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
			}
		}
	}
	
	//if any data's not found inside the columns
	else{
		puts("Data not found!");
	}
	
}

//do ascending sorting
void ascSort(char column[]){
	
	if(strcmp(column, "Location") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(strcmp(data[j].location, data[j + 1].location) > 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	} 
	
	else if(strcmp(column, "City") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(strcmp(data[j].city, data[j + 1].city) > 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Price") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if (data[j].price > data[j + 1].price){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Rooms") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(data[j].rooms > data[j + 1].rooms){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Bathroom") == 0 ){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(data[j].bathroom > data[j + 1].bathroom){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Carpark") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(data[j].carparks > data[j + 1].carparks){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Type") == 0){
		for (int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(strcmp(data[j].type, data[j + 1].type) > 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Furnish") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1 - i; j++){
				if(strcmp(data[j].furnish, data[j + 1].furnish) > 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
	
	for(int i = 0; i < 5; i++){
		printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price,
		data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
	}
}

//to do descending sorting
void descSort(char column[]){
	
	if(strcmp(column, "Location") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(strcmp(data[j].location, data[j + 1].location) < 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	} 
	
	else if(strcmp(column, "City") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(strcmp(data[j].city, data[j + 1].city) < 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Price") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(data[j].price < data[j + 1].price){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Rooms") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(data[j].rooms < data[j + 1].rooms){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Bathroom") == 0 ){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(data[j].bathroom < data[j + 1].bathroom){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Carpark") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(data[j].carparks < data[j + 1].carparks){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Type") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(strcmp(data[j].type, data[j + 1].type) < 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	else if(strcmp(column, "Furnish") == 0){
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < n - 1; j++){
				if(strcmp(data[j].furnish, data[j + 1].furnish) < 0){
					menu temp;
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
	printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
	
	for(int i = 0; i < 5; i++){
		printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
		data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
	}
}

int main() {
	int input;
	
	readData(); //to read .csv file
	
	do{
		system("cls");
		
		printf("What do you want to do?\n");
		printf("1. Display data\n");
		printf("2. Search data\n");
		printf("3. Sort data\n");
		printf("4. Export data\n");
		printf("5. Exit\n");
		
		printf("Your choice: ");
		
		scanf("%d", &input); getchar(); // user's input
		
		switch(input){
			case 1:
				int rows;
				
				printf("Number of rows: ");
				scanf("%d", &rows); getchar();
				
				if(rows > n){
					rows = n;
				}
				
				printf("\nLocation                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
				
				for(int i = 0; i < rows; i++){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carparks, data[i].type, data[i].furnish);
				}
				
				printf("\n");
				getchar();
				break;
				
			case 2:
				char column[100];
				char datastring[100];
				int dataint;
				
				printf("Choose column: ");
				scanf("%s", column); getchar(); //input columns  
				printf("What data do you want to find? ");
				
				if(strcmp(column, "Price") == 0 || strcmp(column, "Rooms") == 0 || strcmp(column, "Bathroom") == 0 || strcmp(column, "Carpark") == 0){
					scanf("%d", &dataint); getchar(); //if the data's integer type
				}else{
					scanf("%s", datastring); getchar(); //if the data's string type
				}
				
				if(strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 && strcmp(column, "Price") != 0 && strcmp(column, "Rooms") != 0
				&& strcmp(column, "Bathroom") != 0 && strcmp(column, "Carpark") != 0 && strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0){
					printf("Data not found!"); //no data's found
				}else{
					searchData(column, dataint, datastring); //search detail data inside the columns
				}
				
				printf("\n");
				getchar();
				break;
				
			case 3:
				char col[100];
				char sort[100];
				
				printf("Choose colomn: ");
				scanf("%s", col); getchar(); //input columns that will be sorted
				printf("Sort ascending or descending? ");
				scanf("%s", sort); getchar(); // choose ascending sorting or descending sorting
				
				if(strcmp(sort, "ascending") == 0){
					ascSort(col); //ascending sorting
				}else if(strcmp(sort, "descending") == 0){
					descSort(col); //descending sorting
				}
				
				printf("\n");
				getchar();
				break;
				
			case 4:
				char name[100];
				
				printf("File name: ");
				scanf("%s", name); getchar(); //input new file name
				
				strcat(name, ".csv"); //adding .csv format after the renamed file
				writeData(name);
				
				printf("Data successfully written to file %s!\n", name);
				
				printf("\n");
				getchar();
				break;
				
		}
	}while(input != 5);
	
	return 0;
}
