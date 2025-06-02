#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	cin >> S;
	for (int i = 0; i <alphabet.length(); i++) {
		cout << (int)S.find(alphabet[i]) << " ";
	}
	return 0;
}