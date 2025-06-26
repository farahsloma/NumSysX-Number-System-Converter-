#include <iostream>
using namespace std;
char* DecimalToHexa(int D_number) {
	char* result = new char[15];
	char temp[15];
	int index = 0;
	while (D_number) {
		int mod = D_number % 16;
		D_number /= 16;
		if (mod < 10) {
			temp[index] = mod +'0';
		}
		else {
			mod -= 10;
			mod += 'A';
			temp[index] = mod;
		}
		index++;
	}
	temp[index] = 0;
	for (int i = strlen(temp) - 1, j = 0; i >= 0; j++, i--) {
		result[j] = temp[i];
	}
	result[index] = 0;
	return result;
}
int HexaToDecimal(char* number) {
	char* result = new char[15];
	int res = 0;
	for (int i = strlen(number) - 1, j = 0; i >= 0; i--, j++) {
		result[j] = number[i];
	}
	int index = 0;
	while (index < strlen(number)) {
		int num = 0;
		if (result[index] <= '9' && result[index] >= '0') {
			num =result[index] - '0';
			int pro = num * pow(16, index);
			res += pro;
		}
		else {
			num = result[index] - 'A';
			num += 10;
			int pro = num * pow(16, index);
			res +=pro;
		}
		index++;
	}
	return res;

}
char* DecimalToOcta(int D_number) {
	char* result = new char[15];
	char temp[15];
	int index = 0;
	while (D_number) {
		int mod = D_number % 8;
		D_number /= 8;
		temp[index] = mod + '0';
		index++;
	}
	temp[index] = 0;
	for (int i = strlen(temp) - 1, j = 0; i >= 0; i--, j++) {
		result[j] = temp[i];
	}
	result[index] = 0;
	return result;

}

int OctaToDecimal(char* number) {
	int index = strlen(number) - 1;
	int result = 0;
	for (int i = 0; i < strlen(number); i++) {
		int num = number[index] - '0';
		int power = num * pow(8, i);
		result += power;
		index--;
	}
	return result;
}
char* DecimalToBinary(int number) {
	int index = 0;
	char* result = new char[15];
	char temp[15];
	while (number) {

		temp[index] = (number % 2) +'0';
		number /= 2;
		index++;
	}
	temp[index] = 0;
	for (int i = strlen(temp) - 1, j = 0; i >= 0; i--, j++) {
		result[j] = temp[i];
	}
	result[index] = 0;
	return result;
}
int BinaryToDecimal(char* number) {
	int result = 0;
	char temp[15];
	for (int i = strlen(number) - 1, j = 0; i >= 0; i--, j++) {
		temp[j] = number[i];
	}
	for (int i = 0; i < strlen(number); i++) {
		int num = temp[i] - '0';
		int pro = num * pow(2, i);
		result += pro;
	}
	return result;
}

int choose_one() {
	cout << "choose what do you want to convert : " << endl;
	cout << "1 - Binary To Decimal." << endl;
	cout << "2 - Binary To Octa." << endl;
	cout << "3 - Binary To Hexa." << endl;
	cout << "4 - Octa To Decimal." << endl;
	cout << "5 - Octa To Binary." << endl;
	cout << "6 - Octa To Hexa." << endl;
	cout << "7 - Hexa To Decimal." << endl;
	cout << "8 - Hexa To Octa." << endl;
	cout << "9 - Hexa To Binary." << endl;
	cout << "10 - Decimal To Binary." << endl;
	cout << "11 - Decimal To Hexa." << endl;
	cout << "12 - Decimal To Octa." << endl;
	cout << "What do you want to convert : ";
	int num;
	cin >> num;
	return num;

}

void main() {
	int num = choose_one();
	int D;
	char* B = new char[15];
	char* O = new char[15];
	char* H = new char[15];
	switch (num){
	case 1: cout << "please enter binary number : ";
		
		cin >> B;
		cout << "Decimal number is " << BinaryToDecimal(B) << endl;
		break;
	case 2: cout << "please enter binary number : ";
		
		cin >> B;
		D = BinaryToDecimal(B);
		O = DecimalToOcta(D);
		cout << "Octa number is " << O << endl;
		break;
	case 3: cout << "please enter binary number : ";
		
		cin >> B;
		 D = BinaryToDecimal(B);
		 H = DecimalToHexa(D);
		cout << "Hexa number is " << H << endl;
		break;
	case 4: cout << "please enter Octa number : ";
		
		cin >> O;
		cout << "Decimal number is " << OctaToDecimal(O) << endl;
		break;
	case 5: cout << "please enter Octa number : ";
		cin >> O;
		 D = OctaToDecimal(O);
		 B = DecimalToBinary(D);
		cout << "Binary number is " << B << endl;
		break;
	case 6: cout << "please enter Octa number : ";
		cin >> O;
		 D = OctaToDecimal(O);
		H = DecimalToHexa(D);
		cout << "Hexa number is " << H << endl;
		break;
	case 7: cout << "please enter Hexa number : ";
		cin >> H;
		cout << "Decimal number is " << HexaToDecimal(H) << endl;
		break;
	case 8: cout << "please enter Hexa number : ";
		cin >> H;
		 D = HexaToDecimal(H);
		 O = DecimalToOcta(D);
		cout << "Octa number is " << O << endl;
		break;
	case 9: cout << "please enter Hexa number : ";
		cin >> H;
		 D = HexaToDecimal(H);
		 B = DecimalToBinary(D);
		cout << "Binary number is " << B << endl;
		break;
	case 10: cout << "please enter Decimal number : ";
		cin >> D;
		cout << "Binary number is " << DecimalToBinary(D) << endl;
		break;
	case 11: cout << "please enter Decimal number : ";
		
		cin >> D;
		cout << "Hexa number is " << DecimalToHexa(D) << endl;
		break;
	case 12: cout << "please enter Decimal number : ";
		cin >> D;
		cout << "Octa number is " << DecimalToOcta(D) << endl;
		break;
	default:
		cout << "Invalid number." << endl;
		break;

	}

}
