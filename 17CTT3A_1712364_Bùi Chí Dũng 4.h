BÀI TẬP THỰC HÀNH TUẦN 02														BÀI TẬP THỰC HÀNH TUẦN 02, Sep18
Họ và tên: Bùi Chí Dũng
MSSV: 1712364
Lớp: 17CTT3A
Ca thực hành: Chiều thứ 2, 14g45 PMT_NDT 4.1

Đề: Sử dụng cấu trúc điều khiển, rẽ nhánh, lặp
Bài 1. Viết chương trình nhập vào 2 số a, b. Giải và biện luận phương trình bậc nhất ax + b = 0
Bài 2. Viết chương trình nhập vào 3 số a, b, c. Giải và biện luận phương trình trùng phương ax4
+ bx2 + c = 0
Bài 3. Viết chương trình xếp loại cho Học sinh, biết:
- Điểm ‘A’: xếp loại giỏi,
- Điểm ‘B’, ‘C’: xếp loại khá,
- Điểm ‘D’: xếp loại trung bình,
- Điểm ‘F’: Đăng ký học lại.
Bài 4. Viết chương trình nhập vào 3 số a, b, c. Xác định xem a, b, c có phải là độ dài 3 cạnh một
tam giác hay không. Nếu phải thì đó là tam giác gì trong các loại: tam giác vuông, tam giác
tù, tam giác nhọn.
Bài 5. Viết chương trình nhập số nguyên không âm N (N < 1000). In ra cách đọc N bằng tiếng Việt
không dấu.
Bài 8. Viết chương trình nhập số nguyên không âm N. Hãy tính và in ra giá trị của các các biểu
thức sau:
a)
1 + 1/2 + 1/3 + ... +1/N 


Bài làm: 
Bài 1
//Giai phuong trinh bac nhat ax+b=0
#include <stdio.h>
#include <math.h>
int main()
{
	float a, b;
	 printf("Nhap he so a: ");
	 scanf("%f", &a);
	 printf("Nhap he so b: ");
	 scanf("%f",&b);
	 
	if (a==0 && b==0)
	printf(" Phuong trinh vo so nghiem");
	else if (a ==0 && b!=0) 
	printf("Phuong trinh vo nghiem");
	else 
	printf("Nghiem x = %f", -b/a );
	
	return 0;
	
	}
Bài 2
//Bien luan nghiem cua phuong trinh trung phuong
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float a, b, c, delta, t1, t2, x1, x2, x3, x4;
	printf("Nhap he so pt co dang a*(x*x*x*x) + b*(x*x) + c:\n ");
	printf("Nhap a: ");
	scanf("%f", &a );
	printf("Nhap b: ");
	scanf("%f", &b );
	printf("Nhap c: ");
	scanf("%f", &c );
	delta = b*b - 4*a*c;
		if (delta<0)
	{
	printf("Phuong trinh vo nghiem: ");
	}
		else
		{
		if ( delta==0)
			{
			t1 = -b/(2*a);
				t2 = t1;
			if(t1<0 && t2 <0)
			{
			printf("Phuong trinh vo nghiem ");
			}
			else
							{
				if(t1>=0)
			       {
			x1 = sqrt (t1);
			x2 = -x1;
			printf(" x1 = %4.3f\n ", x1);
			printf(" x2 = %4.3f\n ", x2);
			}
				if(t2>=0)
			 	    {
			x3 = sqrt(t2);
			x4 = -x3;
			printf(" x3 = %4.3f\n ", x3);
			printf(" x4 = %4.3f\n ", x4);
				    }
			       			}
			}
		if (delta>0)
			{
			t1 = (-b + sqrt (delta))/(2*a);
			t1 = (-b - sqrt (delta))/(2*a);
				if(t1<0)
				{
				printf("Phuong trinh vo nghiem ");
				}
				else
					{
				if(t1>=0)
							{
				x1 = sqrt (t1);
				x2 = -x1;
				printf(" x1 = %4.3f\n ", x1);
				printf(" x2 = %4.3f\n ", x2);
							}
				if(t2>=0)
						{
				x3 = sqrt(t2);
				x4 = -x3;
				printf(" x3 = %4.3f\n ", x3);
				printf(" x4 = %4.3f\n ", x4);
						}
					}
			}
			}
	getch();
	return 0;
	
}
	
	
Bài 3
//Xep loai hoc sinh
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	  char xeploai;
	printf("Nhap diem xep loai : ");
	  xeploai = getchar();
		if (xeploai == 'A') printf("xep loai gioi ");
		else if (xeploai == 'B') printf("xep loai kha ");
		else if (xeploai == 'C') printf("xep loai kha ");
		else if (xeploai == 'D') printf("xep loai trung binh ");
		else if (xeploai == 'F') printf("hoc lai ");
	return 0;
}

Bài 4
//Bienl luan tam giac
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double a, b, c; 
	double x, y, z;
	printf(" Nhap 3 canh cua tam giac\n");
	scanf("%lf %lf %lf", &a, &b, &c);
		if (a + b <= c || a + c <= b || b + c <= a)
	printf("Khong la tam giac ");
		else if (a + b > c || a + c > b || b + c > a)
		{
		  x= (a*a + b*b - c*c) / (2*a*b);
		  y= (a*a + c*c - b*b) / (2*a*c);
		  z= (b*b + c*c - a*a) / (2*b*c);
		if (z == 0 || y == 0 || x == 0)
	printf("La tam giac vuong ");
else if (z>0 & y>0 & x>0)
	printf("La tam giac nhon ");		
else if (z<0 || y<0 || x<0)
	printf("La tam giac tu ");
		
		}
		return 0;
}

Bài 5
//Input a number and output a word describe this number by vietnamese
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int number, n;
	printf("Input a number:\n");
	scanf("%d", &number);
	if (number == 0) printf("khong ");
	for (int z=100 ; z >=1; z = z/10)
	{
		if (number > 99) z = 100;
		if (number > 9 & number<100) z = 10;
		if (number > 0 & number<10 ) z = 1;
		n = number / z;
			switch (n) 
			{
			case 1:
				if (number >= 10 & number < 20)
					printf("");
				else printf("mot ");
				break;
			case 2:
				printf("hai ");
				break;
			case 3:
				printf("ba ");
				break;
			case 4:
				printf("bon ");
				break;
			case 5:
				printf("nam ");
				break;
			case 6:
				printf("sau ");
				break;
			case 7:
				printf("bay ");
				break;
			case 8:
				 printf("tam ");
				break;
			case 9:
				printf("chin ");
				break;
			}
			if (number > 99) printf("tram ");
			if (100 > number & number >= 10) printf("muoi ");
			if (number>90 &number%100==0 & number%10==0) printf("");
			else if (number > 99 & number % 100 < 10) printf("linh ");
			number = number%z;
	}
	system("pause");
	return 0;
}
Bài 8
a)
//Tinh tong gia tri bieu thuc
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	int main()
	{
		int N; 
		double s=0;
		printf("nhap n: \n");
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			s = s+1.0/i;
		printf("tong la: %0.5lf\n", s);
		system("pause");
	}





