#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void nhapMang(int a[][100], int dong, int cot);
void inMang(int a[][100], int dong, int cot);
void timPt(int a[][100], int dong, int cot);
void tongDong(int a[][100],int dong,int cot);
int timMin(int a[][100], int dong, int cot);

int main(){ 
	int dong, cot, x;
	int a[100][100];
	printf("Nhap vao so dong: ");
	scanf("%d", &dong);
	printf("Nhap vao so cot: ");
	scanf("%d", &cot);
	nhapMang(a,dong,cot);
	inMang(a,dong,cot);
	timPt(a,dong,cot);
	tongDong(a,dong,cot);
	timMin(a,dong,cot);
	return 0;
}
void nhapMang(int a[][100], int dong, int cot){
	int i, j;
	for(i=0; i<dong; i++)
	{
		for(j=0; j<cot; j++){
		printf("a[%d][%d]=", i, j);
		scanf("%d", &a[i][j]);
		}
	}
}
void inMang(int a[][100], int dong, int cot){
	int i, j;
	for(i=0; i<dong; i++)
	{
		for(j=0; j<cot; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
void timPt(int a[][100], int dong ,int cot){
	int i, j,x;
	printf("Nhap phan tu x can tim:");
	scanf("%d", &x);
	for(i=0; i<dong; i++)
	{
		for(j=0; j<cot; j++)
		if(a[i][j]==x)
		printf("a[%d][%d]=%d\n", i, j, x );
	}
}
void tongDong(int a[][100],int dong,int cot)
{
 
 for(int i=0;i<dong;i++)   
  {
   int s=0;
     for(int j=0;j<cot;j++)
      {
      s=s+a[i][j];
      }
     printf("\n Dong thu %d co tong la: %d",i,s); 
   }
}
int timMin(int a[][100], int dong, int cot){
	int i, j;
	int min;
	min=a[0][0];
	for(i=0; i<dong; i++){
		for(j=0; j<cot; j++)
			if(a[i][j]<min)
			min=a[i][j];
		}
	printf("Gia tri nho nha cua mang la: %d ", min);
	
}
