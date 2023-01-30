#include <iostream>
#include <vector>

using namespace std;

void coutArr(vector<string> arr) {
	for (int i = 0; i < (int)arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void sortArr(vector<string>& arr, vector<string> alphabet) { // "Їжаченко", "Атанасів", "Іларій", "Єремій", "Ґудзь", "Янгель", "Андрійчук"
	vector<int> ArrIndex;
	for (int i = 0; i < (int)arr.size(); i++) { // "Їжаченко"
		for (int alphIndex = 0; alphIndex < (int)alphabet.size(); alphIndex++) { // "Ї"
			if (arr[i][0] == alphabet[alphIndex][0]) { // "Ї" == "Ї"
				ArrIndex.push_back(alphIndex);
			}
		}
	}

	for (int i = 0; i < (int)ArrIndex.size() - 1; i++) {
		for (int j = i + 1; j < (int)ArrIndex.size(); j++) {
			if (ArrIndex[i] >= ArrIndex[j]) {
				swap(ArrIndex[i], ArrIndex[j]);
				swap(arr[i], arr[j]);
			}
		}
	}
}

int main() {
	system("chcp 1251>nul");
	vector<string> alphabet = {
		"А", "а", "Б", "б", "В", "в", "Г", "г", "Ґ", "ґ", "Д", "д", "Е", "е", "Є", "є", "Ж", "ж", "З", "з",
		"И", "и", "І", "і", "Ї", "ї", "Й", "й", "К", "к", "Л", "л", "М", "м", "Н", "н", "О", "о", "П", "п",
		"Р", "р", "С", "с", "Т", "т", "У", "у", "Ф", "ф", "Х", "х", "Ц", "ц", "Ч", "ч", "Ш", "ш", "Щ", "щ",
		"ь", "Ю", "ю", "Я", "я" };

	vector<string> arr = { "Їжаченко", "Атанасів", "Іларій", "Єремій", "Ґудзь", "Янгель", "Андрійчук" };
	cout << "Масив до сортування: "; coutArr(arr);
	cout << "Масив пiсля сортування: "; sortArr(arr, alphabet); coutArr(arr);

	return 0;
}

/*
Написати програму, яка впорядковує українські прізвища за українською абеткою.
Приклад вектора прізвищ для тестування:

невпорядкований
{Їжаченко, Атанасів, Іларій, Єремій, Ґудзь, Янгель, Андрійчук}
впорядкований
{Андрійчук, Атанасів, Ґудзь, Єремій, Іларій, Їжаченко, Янгель}
*/
