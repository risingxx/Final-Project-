#include <iostream> //menggunakan header iostream
#include <string> //menggunakan header string
using namespace std; //menggunakan library namespace standard

class Vig { //pembuatan kelas Vig untuk kunci vingenere
   public:
      string kunci;
   Vig(string kunci) { //proses generating kunci untuk selanjutnya hasilnya akan di masukkan ke dalam proses enkripsi atau dekripsi
      for (int i = 0; i < kunci.size(); ++i) {
         if (kunci[i] >= 'A' && kunci[i] <= 'Z')
            this->kunci += kunci[i];
         else if (kunci[i] >= 'a' && kunci[i] <= 'z')
            this->kunci += kunci[i] + 'A' - 'a';
      }
   }
   string enkripsi(string t) { //proses enkripsi dari plain text ke cipher text dengan vingenere
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + kunci[j] - 2 * 'A') % 26 + 'A'; //menamabah 'A' sehingga masuk dalam alfabet ASCII yaitu dari 65-99 untuk huruf kapital
         j = (j + 1) % kunci.length();
      }
      return output;
   }
   string dekripsi(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - kunci[j] + 26) % 26 + 'A';//menamabah 'A' sehingga masuk dalam alfabet ASCII yaitu dari 65-99 untuk huruf kapital
         j = (j + 1) % kunci.length();
      }
      return output;
   }
};
int main() {
	int pw, pilih, stop;
	string key;
	string teksori, tekscipher;
	cout<< "================================================================================================================="<<endl;
	cout<<endl;
	cout<< "TUGAS FINAL PROJECT ENKRIPSI DAN DEKRIPSI PESAN DENGAN KRIPTOGRAFI SEDERHANA VINGENERE CIPHER DUA ALI PROSES ENKRIPSI"<<endl;
	cout<<endl;
	cout<< "Masukkan Password :"; cin>>pw;
	if(pw!= 12345)
    {
        cout << "Sandi salah, coba masukkan ulang sandi yang benar\n" << endl;
        return main();
    }
    cout<< "Untuk enkripsi (1) untuk dekripsi (2)"<<endl;
	cout<< "Pilih enkripsi atau dekripsi : " ; cin>>pilih;
	if (pilih==1){
	cout << "Masukkan pesan yang akan dienkripsi (berbentuk teks tanpa spasi) / plain text: "; cin >> teksori;
   cout<<endl;
   cout << "Masukkan kunci dalam karakter : "; cin>>key;
   Vig v(key);
   string hasilenkripsi= v.enkripsi(teksori); //enkripsi tahap 1
   string hasilenkripsi2= v.enkripsi(hasilenkripsi); //enkripsi tahap 2
   cout << "Hasil pesan enkripsi atau ciphertext: " << hasilenkripsi2 << endl;
	}
   else if (pilih==2){
   	cout << "Masukkan pesan yang akan didekripsi (berbentuk teks tanpa spasi): "; cin >> tekscipher;
   cout<<endl;
   cout << "Masukkan kunci dalam karakter teks : "; cin>>key;
   Vig v(key);
   string hasildekripsi = v.dekripsi(tekscipher); //dekripsi tahap 1
   string hasildekripsi2 = v.dekripsi(hasildekripsi); //dekripsi tahap 2
   cout << "Hasil dekripsi pesan :" << hasildekripsi2 << endl;
	}
   cout<<"Tekan 1 untuk hentikan program dan 2 untuk mengulang program :"; cin>>stop;
   if(stop==1){
   	return 0;
   }
   else if(stop==2)
   { 
   return main();
   }
}
