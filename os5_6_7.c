/* duplicates in an array os5.c*/

#include <stdio.h>

void findDuplicates(int arr[], int size) {
    printf("Duplicate elements in the array are: ");
    int count = 0;
    for (int i = 0; i < size; i++) {
        int duplicate = 0;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("%d ", arr[i]);
            count++;
        }
    }
    printf("\nTotal number of duplicates: %d\n", count);
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 5, 6, 7, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findDuplicates(arr, size);
    
    return 0;
}

================================================
/* copy one array into another array  os6.c*/
#include <stdio.h>

int main(){
	int i,j,l,r=0;
	int arr1[5]={10,45,15,10,25},arr2[5];
	l=sizeof(arr1)/sizeof(arr1[0]);
	for(i=0;i<l;i++){
		arr2[i]=arr1[i];
	}
	printf("1st array: ");
	for(i=0;i<l;i++){
		printf("%d ",arr1[i]);
	}
	printf("\n2nd array: ");
	for(i=0;i<l;i++){
		printf("%d ",arr2[i]);
	}
	return 0;
}

================================================
/* input str -> lower to upper and vice versa  os7.c*/
#include <stdio.h>
#include <string.h>

int main(){
	char s[20];
	printf("enter string: ");
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if (s[i]>=97 && s[i]<=122){
			s[i]=s[i]-32;
			continue;
		}
		else if(s[i]>=65 && s[i]<=90){
			s[i]=s[i]+32;
			continue;
		}

	}
	printf("updated string: %s", s);

	return 0;
}
================================================
