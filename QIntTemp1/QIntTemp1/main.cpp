#include<iostream>
#include<stdio.h>
#include<conio.h>
#include"QInt.h"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

ifstream input;
ofstream output;


int main()
{
	QInt temp("1011", 2);
	cout << temp.to_String(16);

	_getch();
}

//Xét các trường hợp trên dòng lệnh 
/*
Ta có các quy ước như sau:
-VD1
Input: 10 2 1515216511 => Tức là chuyển số sau cùng từ hệ 10 sang hệ. 2
-VD2
Input: 10 1515516 + 215465 => Tức là thực hiện phép tính trên hệ 10.

Nhận xét: cắt chuỗi lệnh đưa vào mảng 4 phần tử. Xét các trường hợp  như trong hàm Parse bên dưới để xử lý lệnh.
*/

