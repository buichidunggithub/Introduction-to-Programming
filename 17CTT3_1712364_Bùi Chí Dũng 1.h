													BÀI TẬP THỰC HÀNH 01

Họ và tên: Bùi Chí Dũng
Mã số sinh viên 1712364
Lớp: 17CTT3A
Ca thực hành: Chiều Thứ 2, Ca 2, PM. 2h45
Đề:
1. Viết chương trình nhập số thực R, tính diện tích hình tròn có bán kính R, biết Pi = 3.14159.
2. Viết chương trình nhập số nguyên N, in ra cho biết góc có số đo N0
thuộc cung phần tư số
mấy của đường tròn lượng giác. Biết: góc có số đo [0..90): cung phần tư số 1, [90..180):
cung phần tư số 2, [180.. 270): cung phần tư số 3, [270..360): cung phần tư số 4.
3. Viết chương trình nhập 2 số nguyên a, b. In ra cho biết chu vi, diện tích của hình chữ nhật
có độ dài 2 cạnh là a, b.
4. Viết chương trình nhập vào 1 ký tự, in ra ký tự in hoa tương ứng.
5. Viết chương trình nhập vào 1 số nguyên, in ra ký tự tương ứng và ngược lại, nhập một ký
tự, in ra mã ASCII của ký tự đó.
6. Viết chương trình thực hiện các phép tính sau:
a. A.2n
, với A, n là các số nguyên
b. B/2m, với B, m là các số nguyên

----Bài làm

Bài 1
#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
int main()
{
	float R; double S;
	printf("nhap ban kinh R:\n");
	scanf("%f", &R);
	S = R*R*pi;
	printf("Dien tinh hinh tron la:%.4lf\n", S);
	system("pause");
	return 0;
}

Bài 2
//Xac dinh goc phan tu

#include "stdio.h"
 
int main ()
{
    int N, k;
    do
    {
        printf("\n Nhap vao so do goc (0 <= x <= 360*k) = ");
        scanf("%d", &N);
    }while(N < 0);
 
    k = N / 360;
 
    if(N >= (360*k) && N < (90 + 360*k))
        printf("\n %d o goc phan tu thu I", N);
    else if (N >= (90 + 360*k) && N < (180 + 360*k))
        printf("\n %d o goc phan tu thu 2", N);
    else if (N >= (180 + 360*k) && N < (270 + 360*k))
        printf("\n %d o goc phan tu thu 3", N);
    else if (N >= (270 + 360*k) && N <= 360*(k + 1))
        printf("\n %d o goc phan tu thu 4", N);
    else
        printf("\n %d khong hop le");
    
return 0;
}


Bài 3
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, P, S;
	printf("nhap chieu dai:\n");
	scanf("%d", &a);
	printf("nhap chieu rong: \n");
	scanf("%d", &b);
	S = a*b;
	P = 2 * (a + b);
	printf("chu vi la: %d\ndien tich la: %ld\n", P, S);
	system("pause");
	return 0;
}

Bài 4
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int kt;
	printf("nhap ki tu:\n");
	scanf("%c", &kt);
	printf("ki tu in hoa:%c\n", kt-32);
	system("pause");
	return 0;
}
Bài 5
// Bai tap ve ACII

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i; char x;
	printf("nhap ki tu: ");
	scanf("%c", &x);
	printf("ma ASCII: %d\n", x);
	printf("nhap so:  ");
	scanf("%d", &i);
	printf("ki tu ASCII: %c\n", i);
	system("pause");
	return 0;
}

Bài 6

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int A, B, m, n, z;
	printf("a) nhap so nguyen A va so mu n: \n");
	scanf("%d%ld", &A, &n);
	z = pow(2, n);
	printf("ket qua cua A.2^n la: %ld\n", A*z);
	printf("b) nhap so nguyen B va so mu m: \n");
	scanf("%d%d", &B, &m);
	printf("ket qua cua B/2^m la: %.4f\n", B / pow(2, m));
	system("pause");
	return 0;
}



