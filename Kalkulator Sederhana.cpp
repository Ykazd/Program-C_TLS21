#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int jenis;  //Deklarasi variabel
    float a, b, hasil;
    
    cout<<"====================\n";
    cout<<"Kalkulator Sederhana\n";
    cout<<"====================\n\n";
    cout<<"1. Aritmatika\n2. Trigonometri\n3. Turunan dan Integral (Tak Tentu)\nPilih jenis operasi(angka): ";
    cin>>jenis;

    if (jenis == 1){    //Aritmatika
        char operasi;

        cout<<"Masukkan angka pertama:";    //Input bilangan pertama
        cin>>a;
        cout<<"Pilih operator (+, -, /, *, ^, v):"; //Input operasi
        cin>>operasi;
        cout<<"Masukkan angka kedua:";  //Input bilangan kedua
        cin>>b;
        switch (operasi){
            case '+':   //Penjumlahan
                hasil = a + b;
                break;
            case '-':   //Pengurangan
                hasil = a - b;
                break;
            case '/':   //Pembagian
                hasil = a / b;
                break;
            case '*':   //Perkalian
                hasil = a * b;
                break;
            case '^':   //Perpangkatan
                hasil = pow(a, b);
                break;
            case 'v':   //Perakaran
                hasil = pow(b,1/a);
                break;
            default:
                cout<<"Input salah\n";
        }
        cout<<a<<" "<<operasi<<" "<<b<<" = "<<hasil;    //Output hasil aritmatika
    }

    else if (jenis == 2){   //Trigonometri
        cout<<"\n1. Sin\n2. Cos\n3. Tan\n4. Csc\n5. Sec\n6. Cot\n\nPilih (angka): ";    //Input jenis trigonometri
        cin>>jenis;
        cout<<"Masukkan derajat: "; //Input angka
        cin>>a;

        a *= M_PI / 180;    //Konversi radian ke derajat

        switch (jenis){
            case 1: //Sin
                hasil = sin(a);
                break;
            case 2: //Cos
                hasil = cos(a);
                break;
            case 3: //Tan
                hasil = tan(a);
                break;
            case 4: //Csc
                hasil = 1/sin(a);
                break;
            case 5: //Sec
                hasil = 1/cos(a);
                break;
            case 6: //Cot
                hasil = 1/tan(a);
                break;
            default:
                cout<<"Input salah\n";
        }
        cout<<"Hasil: "<<hasil; //Output hasil trigonometri

    }

    else if (jenis == 3){ //Turunan dan Integral
        int jumlah;

        cout<<"\n1. Turunan\n2. Integral\n\nPilih (angka): ";   //Input jenis
        cin>>jenis;
        cout<<"Masukkan banyak X: ";    //Input berapa banyak variabel X
        cin>>jumlah;
        
        cout<<"\nf(x) = ";              //Output rumus awal
        for (int i = 0; i < jumlah; i++){
            cout<<"nX^p";
            if(jumlah - i != 1){
                cout<<" + ";
            }
        }

        float n[jumlah];    //Deklarasi dan input koefisien dan pangkat
        int p[jumlah];     
        for (int i = 0; i < jumlah; i++){
            cout<<"\nMasukkan nilai n ke-"<<i+1<<": ";
            cin>>n[i];
            cout<<"Masukkan nilai p ke-"<<i+1<<": ";
            cin>>p[i];
        }

        cout<<"\nf(x) = ";              //Output rumus akhir
        for (int i = 0; i < jumlah; i++){
            cout<<n[i]<<"X^"<<p[i];
            if(jumlah - i != 1){
                cout<<" + ";
            }
        }

        switch(jenis){
            case 1:         //Turunan
                cout<<"\nf'(x) = ";         //Output turunan
                for (int i = 0; i < jumlah; i++){
                    cout<<n[i] * p[i]<<"X^"<<p[i]-1;
                    if(jumlah - i != 1){
                        cout<<" + ";
                    }
                }
                break;

            case 2:         //Integral
                cout<<"\nF(x) = ";
                for (int i = 0; i < jumlah; i++){       //Output rumus awal integral
                    if(p[i] != -1){                 //Pangkat selain -1
                        cout<<n[i]<<"/"<<p[i] + 1<<"X^"<<p[i]+1;
                    }
                    else{                           //Pangkat -1
                        cout<<n[i]<<"ln|X|";
                    }
                    if(jumlah - i != 1){
                        cout<<" + ";
                    }
                    else
                        cout<<" + C";
                }
                cout<<"\nF(x) = ";                      //Output rumus akhir integral
                for (int i = 0; i < jumlah; i++){
                    if(p[i] != -1){                 //Pangkat selain -1
                        cout<<n[i] / (p[i] + 1)<<"X^"<<p[i]+1;
                    }
                    else{                           //Pangkat -1
                        cout<<n[i]<<"ln|X|";
                    }
                    if(jumlah - i != 1){
                        cout<<" + ";
                    }
                    else
                        cout<<" + C";
                }
                break;
            default:
                cout<<"Input salah";
        }
    }
    return 0;
}
