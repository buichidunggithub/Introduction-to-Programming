#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhapMang(int a[], int &n);
void inMang(int a[], int &n);
void timSo(int a[], int &n);
void timPy(int a[], int &n);
int main(){
	int n,i;
	int a[100];
	nhapMang(a,n);
	inMang(a,n);
	timSo(a,n);
	timPy(a,n);
	return 0;
	system("pause");
}

void nhapMang(int a[], int &n)			// Cau a) Nhap n so nguyen vao day a
{
	int i;
	printf("Nhap n phan tu cua mang: ");
	scanf("%d", &n);
	for (i=0; i<n; i++){
	printf("a[%d]=",i);
	scanf("%d", &a[i]);
}
}

void inMang(int a[], int &n)			// Cau b) Xuat day vua nhap ra man hinh
{
	int i;
	printf("Mang a da nhap la: \n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
}
void timSo(int a[], int &n)				// Cau c) Tim so nho hon cac so lan can
{
	int i;
	for(i=0; i<n; i++)
		if(a[i]<a[i+1] && a[i]<a[i-1])
		printf("\n\nPt be nhat giua 2 pt ben canh la: a[%d]=%d ",i  , a[i]);
		if(a[0]<a[1])
		printf("Pt be hon cac phan tu ben canh(nam o bien) la: a[0]=%d \n", a[0]);
		if(a[n-1]<a[n-2])
		printf("Pt be hon cac phan tu ben canh(nam o bien) la: a[%d]=%d \n", n-1, a[n-1]);
}
void timPy(int a[], int &n)				// Cau d) Tim bo 3 so Pytago
{
	int i,j,k;
	printf("\n\nBo 3 pytago la: \n");
	for(i=1;i<=n;i++) 
	{
		for(j=1;j<=n;j++)
		{
			float k=sqrt(i*i+j*j);
			if((int) k==k)
			if( (i<j) && (j<k) && (k<=n) ) 
			printf("%d %d %f\n",i,j,k);
		}
	}
}
		
	
	

