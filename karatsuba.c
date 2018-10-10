
#include<stdio.h> 
#include<iostream> 
using namespace std;

int FazerTamanhoIgual(string &str1, string &str2)
{
	int tamanho1 = str1.size();
	int tamanho2 = str2.size();
	if (tamanho1 < tamanho2){
		for (int i = 0; i < tamanho2 - tamanho1; i++)
			str1 = '0' + str1;
		return tamanho2;
	}
	else if (tamanho1 > tamanho2)
	{
		for (int i = 0; i < tamanho1 - tamanho2; i++)
			str2 = '0' + str2;
	}
	return tamanho1; 
}

string bits(string first, string second)
{
	string result;   

	int length = FazerTamanhoIgual(first, second);
	int carry = 0;  

	for (int i = length - 1; i >= 0; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';

		int sum = (firstBit ^ secondBit ^ carry) + '0';

		result = (char)sum + result;

		carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
	}

	if (carry)  result = '1' + result;

	return result;
}

int multiplicacaoBitABit(string a, string b)
{
	return (a[0] - '0')*(b[0] - '0');
}

long int karatsuba(string X, string Y)
{
	int n = FazerTamanhoIgual(X, Y);

	if (n == 0) return 0;
	if (n == 1) return multiplicacaoBitABit(X, Y);

	int fh = n / 2;    
	int sh = (n - fh);  

	string Xl = X.substr(0, fh);
	string Xr = X.substr(fh, sh);

	string Yl = Y.substr(0, fh);
	string Yr = Y.substr(fh, sh);

	long int P1 = karatsuba(Xl, Yl);
	long int P2 = karatsuba(Xr, Yr);
	long int P3 = karatsuba(bits(Xl, Xr), bits(Yl, Yr));

	return P1 * (1 << (2 * sh)) + (P3 - P1 - P2)*(1 << sh) + P2;
}


int main()
{
	printf("RESULTADO:        %ld\n", karatsuba("110", "1010"));
	printf("RESULTADO:        %ld\n", karatsuba("1", "1010"));
	printf("RESULTADO:        %ld\n", karatsuba("0", "1010"));
}
