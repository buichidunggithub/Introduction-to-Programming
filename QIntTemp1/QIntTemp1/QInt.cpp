#include "QInt.h"

QInt::QInt()				//Constructor
{
	arrayBits[0] = 0;
	arrayBits[1] = 0;
}

QInt::QInt(string str, int base) : QInt()
{
	if (base == 2)
	{
		for (int i = 0; i < str.length(); i++)
		{
			set_Bit(str.length() - i - 1, int(str[i] - '0'));
		}
	}

	else if (base == 10)
	{
		str = dec_To_Bin(str);
		for (int i = 0; i < str.length(); i++)
		{
			set_Bit(str.length() - i - 1, int(str[i] - '0'));
		}
	}

	else if (base == 16)
	{
		str = hex_To_Bin(str);
		for (int i = 0; i < str.length(); i++)
		{
			set_Bit(str.length() - i - 1, int(str[i] - '0'));
		}
	}
}

bool get_Bit(int input, int bit)
{
	if (bit >= 64 || bit < 0) return 0;
	return (input >> (bit)) & 1;
}

void set_Bit(int input, int bit, int value)
{
	if (bit >= 32 || bit < 0) return;
	if (value == 0)
		input &= ~(1 << (bit));
	else
		input |= (1 << (bit));
}

////QInt
bool QInt::get_Bit(int input) const //function for getting bit
{
	if (input < 0 || input > 127) return 0;
	int longlongIndex = 1 - (input / 64);
	int bitIndex = input % 64;
	return (arrayBits[longlongIndex]) >> (bitIndex) & 1;
}

void QInt::set_Bit(int bit, int value) //function for setting bit
{
	int bitIndex = bit % 64;
	int longlongIndex = 1 - (bit / 64);
	if (value == 0)
	{
		arrayBits[longlongIndex] &= ~(1 << bitIndex);
	}
	else if (value == 1)
	{
		arrayBits[longlongIndex] |= (1 << bitIndex);
	}
}

QInt::~QInt()
{

}

string QInt::to_String(int base)
{
	string outstr;
	for (int i = 127; i >= 0; i--)
	{
		outstr += get_Bit(i) + 48;
	}
	int j = 0;
	while (outstr[j] == '0') j++;
	outstr = outstr.substr(j);
	if (base == 10) outstr = bin_To_Dec(outstr);
	if (base == 16) outstr = bin_To_Hex(outstr);
	return outstr;
}

QInt& QInt::operator=(const QInt& bignum)
{
	QInt kq;
	for (int i = 0; i < 2; i++)
		arrayBits[i] = bignum.arrayBits[i];
	return *this;
}

string Divide_2_for_thuong(string str) //Hàm chia 2 lấy thương
{
	int len = str.length();
	int du = 0;
	string kq;
	for (int i = 0; i < len; i++)
	{
		int tmp = (str[i] - 48) + 10 * du;
		du = tmp % 2;
		kq += tmp / 2 + 48;
	}
	int j = 0;
	while ((j < kq.length() - 1) && (kq[j] == 48))
		j++;
	return kq.substr(j);
}

int Divide_2_for_du(string str) //Hàm chia 2 lấy dư
{
	int len = str.length();
	int kq = (str[len - 1] - 48) % 2;
	return kq;
}

string one_Complement(string str)
{
	string kq;
	for (int i = 0; i < str.length(); i++)
		kq += '0';
	kq = kq + str;
	for (int i = 0; i < 128; i++)
	{
		if (kq[i] == 0) kq[i] == 1;
		else
			kq[i] == 0;
	}
	return kq;
}

string oneComplement_plus_1(string str)
{
	string kq;
	int sub = 1; // sub is the value for adding to string
	for (int i = str.length() - 1; i >= 0; i--)
	{
		sub += str[i] - '0';
		kq += sub % 2 + '0';
		sub /= 2;
	}
	if (sub == '1') kq += sub;
	kq = undo_String(kq);
	return kq;

}

string two_Complement(string str)
{
	return(oneComplement_plus_1(one_Complement(str)));
}

string undo_String(string str)
{
	string kq;
	for (int i = str.length() - 1; i >= 0; i--)
		kq += str[i];
	return kq;
}

string dec_To_Bin(string str)
{
	string kq;
	string tmp;
	if (str[0] == '-') tmp = str.substr(1);
	else
		tmp = str;
	while (tmp.compare("0") != 0)
	{
		kq += Divide_2_for_du(tmp) + 48;
		tmp = Divide_2_for_thuong(tmp);
	}
	kq = undo_String(kq);
	if (str[0] == '-') return two_Complement(kq);
	return kq;
}

string hex_To_Bin_Char(const char& c)
{
	switch (c)
	{
	case '0':
		return "0000";
	case '1':
		return "0001";
	case '2':
		return "0010";
	case '3':
		return "0011";
	case '4':
		return "0100";
	case '5':
		return "0101";
	case '6':
		return "0110";
	case '7':
		return "0111";
	case '8':
		return "1000";
	case '9':
		return "1001";
	case 'A':
		return "1010";
	case 'B':
		return "1011";
	case 'C':
		return "1100";
	case 'D':
		return "1101";
	case 'E':
		return "1110";
	case 'F':
		return "1111";
	default:
		return "";
	}
}

string hex_To_Bin(const string& str)
{
	string kq;
	for (int i = 0; i < str.length(); i++)
	{
		kq += hex_To_Bin_Char(str[i]);
	}
	return kq;
}

string mul2(string str)
{
	string kq;
	int nummem = 0; //for remembering
	for (int i = str.length() - 1; i >= 0; i--)
	{
		nummem += 2 * (str[i] - 48);
		kq += nummem % 10 + 48;
		nummem /= 10;
	}
	if (nummem == 1) kq += '1';
	return undo_String(kq);
}

string plus_One_From_Dec(string str)
{
	string kq;
	int nummem = 1;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		nummem += (str[i] - 48);
		kq += nummem % 10 + 48;
		nummem /= 10;
	}
	if (nummem == 1) kq += '1';
	return undo_String(kq);
}

string bin_To_Dec(string str)
{
	string tmp;
	string kq = "0";
	if (str.length() == 128 && str[0] == '1')
	{
		int i = 0;
		tmp = two_Complement(str);
		while (tmp[i] == '0') i++;
		tmp = tmp.substr(i);
	}
	else
		tmp = str;
	for (int i = 0; i < tmp.length(); i++)
	{
		kq = (mul2(kq));
		if (tmp[i] == '1')
			kq = plus_One_From_Dec(kq);
	}
	if (tmp.compare(str) != 0)
		return '-' + kq;
	return kq;
}

char bit_To_Hex(string str)
{
	if (str == "0000") return '0';
	if (str == "0001") return '1';
	if (str == "0010") return '2';
	if (str == "0011") return '3';
	if (str == "0100") return '4';
	if (str == "0101") return '5';
	if (str == "0110") return '6';
	if (str == "0111") return '7';
	if (str == "1000") return '8';
	if (str == "1001") return '9';
	if (str == "1010") return 'A';
	if (str == "1011") return 'B';
	if (str == "1100") return 'C';
	if (str == "1101") return 'D';
	if (str == "1110") return 'E';
	return 'F';
}

string bin_To_Hex(string str)
{
	string kq;
	string tmp = str;
	while (tmp.length() % 4 != 0)
		tmp = '0' + tmp;
	for (int i = 0; i < tmp.length(); i += 4)
		kq += bit_To_Hex(tmp.substr(i, 4));
	return kq;
}

