#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	bool ulangi = true;
	while (ulangi) {
		srand(time(0));
		int angkaRand = rand() % 100 + 1;
		int jumlahTebak = 5;
		string nama_player;

		cout << "Siapa Nama Kamu : ";
		cin >> nama_player;
		cout << "Halo " << nama_player << " Ayo Bermain Menebak Angka dari 1 - 100 " << endl;
		cout << "Kamu Memiliki " << jumlahTebak << " Kesempatan" << endl;

		while (jumlahTebak >= 0) {
			int jawab;
			cout << "Tebak Angkanya : ";
			cin >> jawab;
			if (cin.fail()) {
				cin.clear(); // se bersih inputan user yang salah
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // abaikan karakter laeng selain angka
				cout << "Maaf, input tidak valid. Silakan masukkan angka." << endl;
				continue;
			}
				if (jawab == angkaRand) {
					cout << "Selamat " << nama_player << " Jawaban Kamu Benar" << endl;
				}
				else if (jawab >= angkaRand) {
					cout << "Jawaban Kamu Terlalu Besar" << endl;
				}
				else {
					cout << "Jawaban Kamu Terlalu Kecil" << endl;
				}
				jumlahTebak -= 1;
				if (jumlahTebak > 0) {
					cout << "Sisa Tebakan Kamu Adalah " << jumlahTebak << endl;
				}
				if (jumlahTebak == 0) {
					cout << "Maaf " << nama_player << ", Kesempatan Kamu Telah Habis, Jawabannya Adalah : " << angkaRand << endl;
					char jawaban;
					cout << "Apakah Kamu Ingin Bermain Lagi? (y/n)" << endl;
					cin >> jawaban;
					if (jawaban == 'y' || jawaban == 'Y') {
						ulangi = true;
						system("cls"); // hpus dialog yang sbeleumnya
						break;
					}
					else {
						ulangi = false;
						system("cls"); // ini juga
						cout << "\nTerimakasih Telah Bermain\n";
						break;
					}
				}
			}
		}
	return 0;
}