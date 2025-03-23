#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int n, i;
	printf("Kac elemanlik bir array oluþturacaksýnýz: ");
	scanf("%d", &n);
	
	int* arr = (int*)malloc(n*sizeof(n));
	if(arr==NULL){
		printf("Bellek ayrimi basarisiz!!!\n");
		return 1;
	}
	
	for (i=0; i<n; i++){
		printf("arr[%d]= ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("Girilen array elemanlari: ");
	for(i=0; i<n; i++){
		printf("%d", arr[i]);
	}
	
	printf("\n");
	free(arr);
	return 0;
}
