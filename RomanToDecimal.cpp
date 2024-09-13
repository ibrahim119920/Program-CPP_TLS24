#include <iostream>  
#include <cstring>    

using namespace std;

class romanType 
{
    char romanInput[8]; // Array karakter untuk menyimpan simbol angka Romawi
    int resDecimal;     // Variabel untuk menyimpan hasil konversi ke desimal

public: 
    // Konstruktor
    romanType();        // Deklarasi konstruktor default
    // Fungsi anggota
    void romanToDecimal(); // Fungsi untuk mengkonversi angka Romawi ke desimal
    int get_decimal();     // Fungsi untuk mendapatkan nilai desimal dari konversi
};

int main()
{
    romanType ob;          // Membuat objek dari kelas romanType
    ob.romanToDecimal();   // Memanggil fungsi untuk mengkonversi angka Romawi ke desimal

    // Jika hasil desimal lebih dari 0, cetak hasilnya
    if (ob.get_decimal() > 0) 
        cout << "Decimal : " << ob.get_decimal() << endl << endl;
    // Jika hasilnya tidak valid, cetak pesan kesalahan
    else 
        cout << "Invalid format\n";

    main(); // Memanggil fungsi main() lagi untuk memulai kembali program (loop rekursif)
}

romanType::romanType() 
{
    // Inisialisasi simbol angka Romawi di array
    romanInput[0] = 'M'; 
    romanInput[1] = 'D';
    romanInput[2] = 'C'; 
    romanInput[3] = 'L'; 
    romanInput[4] = 'X'; 
    romanInput[5] = 'V'; 
    romanInput[6] = 'I'; 
    resDecimal = 0;      
}

void romanType::romanToDecimal()
{
    char a[100];         // Array untuk menyimpan input angka Romawi dari pengguna
    cout << "Enter a number in roman format : "; // Meminta input pengguna
    cin >> a;            // Membaca input pengguna

    int dec, n = 1;      // Variabel dec untuk nilai desimal sementara, n untuk memeriksa nilai sebelumnya
    int l = strlen(a);   // Mendapatkan panjang string input

    // Loop melalui string input dari belakang
    for (int i = l - 1; i >= 0; i--)
    {
        a[i] = toupper(a[i]); // Mengubah huruf kecil menjadi huruf besar untuk konsistensi

        // Pengecekan dan konversi simbol Romawi ke nilai desimal
        if (a[i] == romanInput[0]) 
            dec = 1000;
        else if (a[i] == romanInput[1]) 
            dec = 500;
        else if (a[i] == romanInput[2]) 
            dec = 100;
        else if (a[i] == romanInput[3]) 
            dec = 50;
        else if (a[i] == romanInput[4]) 
            dec = 10;
        else if (a[i] == romanInput[5]) 
            dec = 5;
        else if (a[i] == romanInput[6]) 
            dec = 1;
        else // Jika simbol tidak valid, set hasil desimal ke -1 dan keluar dari loop
        {
            resDecimal = -1;
            break;     
        }

        // Jika angka sebelumnya lebih besar dari angka saat ini, maka kurangi (aturan Romawi)
        if (n > dec)
            resDecimal = (resDecimal - dec);
        // Jika tidak, tambahkan angka desimal saat ini
        else
            resDecimal = resDecimal + dec;

        // Set n ke nilai desimal saat ini untuk pengecekan pada iterasi berikutnya
        n = dec;
    }
}

int romanType::get_decimal()
{
    // Mengembalikan nilai hasil desimal
    return resDecimal;
}
