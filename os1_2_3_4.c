/* fibonacci series os1.c */
#include <stdio.h>

int main()
{
	int n,n1=0,n2=1,n3;
	printf("enter no of elements: ");
	scanf("%d",&n);

	printf("fibo series: %d,%d",n1,n2);
	for(int i=2;i<n;i++){
		n3=n1+n2;
		n1=n2;
		n2=n3;
		printf(",%d",n3);

	}
	return 0;
}

====================================
/* student record os2.c */
#include <stdio.h>

struct stu
{
	char name[20], dob[10],branch[20];
	int marks[3], regno;

};
int main(){
	struct stu s;
	int i,total=0, avg=0;

	printf("enter regno: ");
	scanf("%d",&s.regno);
	printf("enter name: ");
	scanf("%s",s.name);
	printf("enter dob: ");
	scanf("%s",s.dob);
	printf("enter branch: ");
	scanf("%s",s.branch);
	printf("enter 3 sub marks: ");

	for (i=0;i<3;i++){
		scanf("%d",&s.marks[i]);
		total=total+s.marks[i];
	}
	avg=total/3;
	printf("name: %s\n",s.name);
	printf("regno: %d\n",s.regno);
	printf("dob: %s\n",s.dob);
	printf("branch: %s\n",s.branch);
	printf("marks:-");
	for (i=0;i<3;i++){
		printf("%d\n",s.marks[i]);
	}
	printf("total: %d\n",total);
	printf("avg: %d\n",avg);

	return 0;
}

====================================
/* bubble sort os3.c */
#include <stdio.h>

int main(){
	int i,j,n,temp,arr[100];
	printf("enter no of elem: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;

}
====================================

/* linear search  os4.c*/
#include <stdio.h>

int main(){
	int i,n,l,r=0;
	int arr[5]={10,45,15,25};
	printf("enter number to search: ");
	scanf("%d",&n);
	l=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<l;i++){
		if(arr[i]==n){
			r++;
			printf("element is found at %d",i+1);
			break;
		}
	}
	if(r==0){
		printf("elmt not found");
	}

	return 0;
}
