/* duplicates in an array os5.c*/
#include <stdio.h>

int main(){
	int i,j,l,r=0;
	int arr[5]={10,45,15,10,25};
	l=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<l;i++){
		for(j=i+1;j<l;j++){
			if(arr[i]==arr[j]){
				printf("duplicate found at %d\n",j+1);
				r++;
			}
		}
	}
	printf("no of duplicates: %d\n",r);
	if(r==0){
		printf("dupli not found!");
	}
	

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
