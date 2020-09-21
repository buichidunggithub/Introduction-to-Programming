#pragma once
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

//|				arrayBits[0]				|				arrayBit[1]					|
//| 0010110010110...............001010001011 1001010101011..................101101010111
//| ^									   ^ ^										   ^		
//|127....................................64 63........................................0


class QInt
{
public:
	long long arrayBits[2];
public:
	bool get_Bit(int i)const;
	void set_Bit(int value, int bit);

	QInt();
	QInt(string str, int base);
	//QInt(const QInt &A);
	~QInt();
	string to_String(int base);
	QInt& operator=(const QInt& bignum);


};
bool get_Bit(int input, int bit);
void set_Bit(int input, int bit, int value);
string bin_To_Dec(string str);
string bin_To_Hex(string str);
string dec_To_Bin(string str);
string hex_To_Bin(const string& str);
string undo_String(string str);
