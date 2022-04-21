#include<iostream>
using namespace std;
bool valid(string& s) {
	int length = s.length();
	if ( length >=10 && length <=16 )
		return true;
	else
		return false;

}
int twodigit(int a) {
	int temp = 0;
	if (a > 9) {
		temp += a / 10;
		temp += a % 10;
		return temp;
	}
	else return a;
}

int sum2(string& s) {
	int size = s.length(), i; int total_one = 0; bool flag = true;
	for (i = size - 1; i >= 0; i--) {
		int x = s[i] - '0';
		if (flag == true) {
			total_one += x;
		}
		flag = !flag;

	}
	return total_one;

}



int sum1(string& s) {
	int size = s.length(), i; int total_sec = 0; bool flag = false; int sum = 0;
	for (i = size - 1; i >= 0; i--) {
		int x = s[i] - '0';
		if (flag == true) {
			x = 2 * x;
			total_sec += twodigit(x);
		}
		flag = !flag;

	}

	sum = sum + sum2(s) + total_sec;
	return sum;
}


int main() {
	string cardnum;
	cout << "Enter the credit card number : \n";
	cin >> cardnum;
	if (valid(cardnum)) {
		if (sum1(cardnum) % 10 == 0) {
			cout << "valid card \n";
			return 0;
		}


		else {
			cout << "not valid";
			return 0;
		}



	}
}