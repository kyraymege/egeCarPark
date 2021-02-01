#include <iostream>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stack>

using namespace std;
struct Arac
{
    string isim;
    string plaka;
    int saat;

};
class Musteri
{
public:
    void aracEkle(Arac* arac,string isim,string plaka,int saat)
    {
        arac -> isim = isim;
        arac -> plaka = plaka;
        arac -> saat = saat;
    }

    //Her araç eklendiğinde otopark doluluğunu kontrol etmek için sayaci 1 arttırır.
    void aracSayacArttir()
    {
        ifstream dosyaOku1("C:\\otoparkDB\\aracSayaci.txt");
        string sayac = "";

        if ( dosyaOku1.is_open() )
        {

            while ( getline(dosyaOku1, sayac) )
            {

            }

            dosyaOku1.close();
        }
        int sayac1= std::stoi(sayac)+1;
        ofstream dosyaYaz2("C:\\otoparkDB\\aracSayaci.txt");
        dosyaYaz2<<sayac1;
        dosyaYaz2.close();
    }
    //Her araç eklendiğinde otopark doluluğunu kontrol etmek için sayaci 1 azaltır.
    void aracSayacAzalt()
    {
        ifstream dosyaOku1("C:\\otoparkDB\\aracSayaci.txt");
        string sayac = "";

        if ( dosyaOku1.is_open() )
        {

            while ( getline(dosyaOku1, sayac) )
            {

            }

            dosyaOku1.close();
        }
        int sayac1= std::stoi(sayac)-1;
        ofstream dosyaYaz2("C:\\otoparkDB\\aracSayaci.txt");
        dosyaYaz2<<sayac1;
        dosyaYaz2.close();
    }

    //Otoparkta araç girişi için yer olup olmadığını kontrol eder.
    bool parkYeriKontrol()
    {

        ifstream dosyaOku2("C:\\otoparkDB\\aracSayaci.txt");
        string sayac = "";

        if ( dosyaOku2.is_open() )
        {

            while ( getline(dosyaOku2, sayac) )
            {

            }

            dosyaOku2.close();
        }

        ifstream dosyaOku3("C:\\otoparkDB\\aracKapasite.txt");
        string sayac1 = "";

        if ( dosyaOku3.is_open() )
        {

            while ( getline(dosyaOku3, sayac1) )
            {

            }

            dosyaOku3.close();
        }
        if(std::stoi(sayac)==std::stoi(sayac1))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //Müşteri kısmında araç park etmek isteyenler için bu method çalışır.
    void aracParkEtme()
    {
        string a,b;
        int c;

        ifstream ayarOkuma("C:\\otoparkDB\\aracSayaci.txt");
        //Ayarların yapılıp yapılmadığı bu kısımda kontrol edilir.
        if(ayarOkuma.is_open())
        {
            //Otoparkta boş yer olup olmadığı bu kısımda kontrol edilir.
            if(parkYeriKontrol())
            {
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
                cout<<"\t\t\t\t\t****    MUSTERI PANELI   ****"<<endl;
                cout<<"\t\t\t\t\t****      PARK ETME      ****"<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tLutfen Aracinizin Plakasini Giriniz (Bitisik Olarak): ";
                cin>>a;

                cout<<"\t\t\t\t\tLutfen Isminizi Giriniz : ";
                cin>>b;
                cout<<"\t\t\t\t\tLutfen Aracinizi Kac Saat Teslim Edeceginizi Giriniz : ";
                cin>>c;
                //Struct ile arac verileri belirlenir
                Arac arac1;
                aracEkle(&arac1,b,a,c);
                //Giriş yapıldığı için sayaç arttırılır.
                aracSayacArttir();
                //Burada alınan verileri bir diziye aktarılır ve dosyaya yazılır.
                string arac[3];
                arac[0] = arac1.plaka;
                arac[1] = arac1.isim;
                arac[2] = arac1.saat;
                ofstream dosyaYaz("C:\\otoparkDB\\araclar\\"+a+".txt");
                dosyaYaz<<arac[0]<<" "<<arac[1]<<" "<<c;
                dosyaYaz.close();
                //Saatlik Ucret kısmı burada okunur.
                ifstream dosyaOku("C:\\otoparkDB\\saatlikUcret.txt");
                string satir = "";

                if ( dosyaOku.is_open() )
                {

                    while ( getline(dosyaOku, satir) )
                    {

                    }

                    dosyaOku.close();
                }

                cout<<"\t\t\t\t\tBilgileriniz alinmistir. "<<c<<" saat aracinizi teslim etmeniz durumunda;"<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tOdeyeceginiz Tutar : "<<std::stoi(satir)*c<<endl;
                cout<<"\t\t\t\t\tLutfen bir tusa basip devam ediniz...";
                //Yönetici kısmındaki hasilat hesaplama kısmı için burada bir saatleri toplayan sayaç vardır.
                ifstream hasilatOku("C:\\otoparkDB\\hasilatHesaplama.txt");
                string hasilat = "";

                if ( hasilatOku.is_open() )
                {

                    while ( getline(hasilatOku, hasilat) )
                    {

                    }

                    hasilatOku.close();
                }
                //Alınan kaç saat kalacağı bilgisi stack içine atılır.
                stack <int> s1;

                s1.push(c);
                //Stack içine atılan değer hasilat bilgisine eklenir.
                ofstream hasilatYazdir("C:\\otoparkDB\\hasilatHesaplama.txt");
                hasilatYazdir<<std::stoi(hasilat)+s1.top();
                hasilatYazdir.close();


                getch();
                system("cls");
                musteriPaneli();

            }
            else
            {
                //Eğer otoparkta yer kalmamışsa bu mesaj ile karşılaşılır.
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
                cout<<"\t\t\t\t\t****    MUSTERI PANELI   ****"<<endl;
                cout<<"\t\t\t\t\t****      PARK ETME      ****"<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tMalesef  Otoparkimizda bos yer kalmamistir..."<<endl;
                cout<<"\t\t\t\t\tLutfen bir tusa basip devam ediniz...";
                getch();
                system("cls");
                musteriPaneli();
            }

        }
        else
        {
            //Eğer yönetici ayarları yapmamışsa bu kısım ile karşılaşılır.
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\tSistemi kullanabilmek icin once yonetici ayarlamalari yapmali..."<<endl;
        }
    }

    //Aracın geri alınması için kullanılan fonksiyondur.
    void aracGeriAlma()
    {
        string plaka;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
        cout<<"\t\t\t\t\t****    MUSTERI PANELI   ****"<<endl;
        cout<<"\t\t\t\t\t****     ARAC CIKISI     ****"<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<endl;
        cout<<endl;
        //Alınması istenen aracın plakası sorulur.
        cout<<"\t\t\t\t\tLutfen aracinizin plakasini giriniz(Arada bosluk olmadan): ";
        cin>>plaka;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\tLutfen bir tusa basin..."<<endl;
        //Eğer plaka mevcutsa işlemlere devam edilir.
        ifstream plakaOkuma("C:\\otoparkDB\\araclar\\"+plaka+".txt");
        if(plakaOkuma.is_open())
        {

            string isim;
            int saat;
            while(plakaOkuma)
            {
                plakaOkuma>>plaka>>isim>>saat;
            }
            //Saatlik ücret burada okunur ve ödeyeceği tutar ve bilgiler alındıktan sonra bilgi fişi oluşturulur.
            ifstream saatlikFiyatOku("C:\\otoparkDB\\saatlikUcret.txt");
            string satir = "";

            if ( saatlikFiyatOku.is_open() )
            {

                while ( getline(saatlikFiyatOku, satir) )
                {
                    //cout << satir << endl;
                }
                getch();
                system("cls");
                //Bilgi fişi bu kısımda oluşturulur.
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
                cout<<"\t\t\t\t\t****     BILGI FISI      ****"<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<endl;
                cout<<"\t\t\t\t ----------------------------------------  ";
                cout<<endl;
                cout<<"\t\t\t\t\t   Isim : "<<isim;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t   Arac Plakasi : "<<plaka;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t   Otopark Kullanim Saati: "<<saat;
                cout<<endl;
                cout<<"\t\t\t\t ----------------------------------------  ";
                cout<<endl;
                cout<<"\t\t\t\t\t   Odenecek Tutar : "<< saat*std::stoi(satir);
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tLutfen bir tusa basin..."<<endl;


                saatlikFiyatOku.close();
            }




            plakaOkuma.close();
            getch();
            system("cls");
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t*****************************"<<endl;
            cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
            cout<<"\t\t\t\t\t****    MUSTERI PANELI   ****"<<endl;
            cout<<"\t\t\t\t\t****     ARAC CIKISI     ****"<<endl;
            cout<<"\t\t\t\t\t*****************************"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\tOdeme isleminizi tamamladiktan sonra cikis yapabilirsiniz...";

        }
        else
        {
            //Eğer girilen plaka otoparkta mevcut değilse sistem bir hata verir ve seçim ekranına yönlendirir.
            cout<<"\t\t\t\t\tMalesef otoparkimizda bu plakaya ait bir arac bulunmamaktadir.";
            getch();
            system("cls");
            musteriPaneli();
        }
        //Araç geri alındıktan sonra sistemden silinir.
        string adres = "C:\\otoparkDB\\araclar\\"+plaka+".txt";
        if(remove(adres.c_str())!=0)
        {
            cout<<"Dosya silinemedi";
        }
        //Araç sayacı 1 azaltılır ve yeni gelen araçlar için yer açılır.
        aracSayacAzalt();






        getch();
        system("cls");
        musteriPaneli();

    }
    void musteriPaneli()
    {
        //Müşteri seçim paneli bu kısımdadır.
        int j;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
        cout<<"\t\t\t\t\t****    MUSTERI PANELI   ****"<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t   1. Araci Park Etmek"<<endl<<endl;
        cout<<"\t\t\t\t\t   2. Araci Geri Almak"<<endl<<endl;
        cout<<"\t\t\t\t\t   3. Cikis"<<endl<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\n\n\t\t\t\tSeciminizi giriniz:";
        cin>>j;
        switch(j)
        {

        case 1:
            system("cls");
            aracParkEtme();
            break;
        case 2:
            system("cls");
            aracGeriAlma();
            break;
        case 3:
            system("cls");
            cikisEkrani();
            break;
        default:
            cout<<"Hatali giris yaptiniz!"<<endl;
            break;
        }
    }
    //Çıkış seçeneği buradadır.
    void cikisEkrani()
    {

        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"          \t\t\t       ************************************"<<endl;
        cout<<"          \t\t\t****************************************************"<<endl;
        cout<<"          \t\t\t********   EGE OTOPARK | TEKRAR BEKLERIZ    ********"<<endl;
        cout<<"          \t\t\t****************************************************"<<endl;
        cout<<"          \t\t\t        ************************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                           \t \t     -> Devam etmek icin lutfen bir tusa basin..."<<endl;
        getch();
        exit(0);

    }
};

class Yonetici
{

public:

    char pass[20],pass2[20];

    Yonetici()
    {


    }
    //Yonetici cikis ekrani bu kısımdadır.
    void yoneticiCikisEkrani()
    {

        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"          \t\t\t       ************************************"<<endl;
        cout<<"          \t\t\t****************************************************"<<endl;
        cout<<"          \t\t\t********   EGE OTOPARK | TEKRAR BEKLERIZ    ********"<<endl;
        cout<<"          \t\t\t****************************************************"<<endl;
        cout<<"          \t\t\t        ************************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                           \t \t     -> Devam etmek icin lutfen bir tusa basin..."<<endl;
        getch();
        exit(0);

    }
    //Yonetici girisi için belirlenen şifre bu kısımda belirlenir.
    //6 haneli bu şifre sayesinde panele giriş yapılabilir.
    void yoneticiSifre()
    {
sifreTekrar:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\tLutfen Sifreyi Giriniz: ";
        //Bu kısımda 6 haneli bir giriş yapılacağını ve giriş yaparken şifrenin görünmemesi için her klavyeden giriş yapıldığında yerine bir yıldız konması gerektiği şeklinde çalışır.
        for(int z=0; z<6; z++)
        {
            pass[z]=getch();
            system("cls");
            cout<<"\n\n\n\n\n\n\n\t\t\t\t\tLutfen Sifreyi Giriniz: ";
            for(int i=1; i<=(z+1); i++)
            {
                cout<<"*";
            }
        }
        //Eğer şifre bu değere eşitse yönetici paneline aktarılır.
        if(strcmp(pass,"190309")==0)
        {
            system("cls");
            yoneticiPaneli();
        }
        else
        {
            //Eğer eşit değilse hata verir ve tekrar girmesini ister.
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl<<"\t\t\t\tHatali Giris Yaptiniz! Lutfen Tekrar Deneyiniz!"<<endl;
            getch();
            goto sifreTekrar;
            exit(0);
        }
    }
    //Yönetici paneli girişi bu kısımdadır.
    void yoneticiPaneli()
    {
        int j;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
        cout<<"\t\t\t\t\t****    YONETICI PANELI  ****"<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t   1. Ayarlar"<<endl<<endl;
        cout<<"\t\t\t\t\t   2. Hasilat Hesaplama"<<endl<<endl;
        cout<<"\t\t\t\t\t   3. Rezerve"<<endl<<endl;
        cout<<"\t\t\t\t\t   4. Secim Paneline Geri Don"<<endl<<endl;
        cout<<"\t\t\t\t\t   5. Cikis Yap"<<endl<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\n\n\t\t\t\tSeciminizi giriniz:";
        cin>>j;
        switch(j)
        {

        case 1:
            system("cls");
            yoneticiAyarlar();
            break;
        case 2:
            system("cls");
            yoneticiHasilatHesaplama();
            break;
        case 3:
            system("cls");
            yoneticiRezerve();
            break;
        case 4:
            system("cls");
            profilSecimEkrani();
            break;
        case 5:
            system("cls");
            yoneticiCikisEkrani();
            break;
        default:
            cout<<"Hatali giris yaptiniz!"<<endl;
            break;
        }
    }
    //Sistemin çalışması için gerekli dosyaların kurulumu ve seçeneklerin belirlenmesi bu kısımda oluşturulur.
    void yoneticiAyarlar()
    {
        int ucret,kapasite;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<"\t\t\t\t\t****      EGE OTOPARK    ****"<<endl;
        cout<<"\t\t\t\t\t****    YONETICI PANELI  ****"<<endl;
        cout<<"\t\t\t\t\t****        AYARLAR      ****"<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\tOtopark Kapasitesini giriniz:";
        cin>>kapasite;
        cout<<endl;
        cout<<"\t\t\t\t\tOtoparkin saatlik ucretini giriniz(TL Cinsinden):";
        cin>>ucret;
        cout<<endl;
        cout<<"\t\t\t\t\tBilgileriniz Kaydedilmistir. Kurulumlar tamamlanmistir."<<endl<<"\t\t\t\tLutfen bir tusa basin..."<<endl;
        system("mkdir c:\\otoparkDB");
        system("mkdir c:\\otoparkDB\\araclar");
        ofstream dosyaYaz("C:\\otoparkDB\\aracSayaci.txt");
        dosyaYaz<<"0";
        dosyaYaz.close();
        ofstream dosyaYaz2("C:\\otoparkDB\\saatlikUcret.txt");
        dosyaYaz2<<ucret;
        dosyaYaz2.close();
        ofstream dosyaYaz3("C:\\otoparkDB\\aracKapasite.txt");
        dosyaYaz3<<kapasite;
        dosyaYaz3.close();
        ofstream dosyaYaz4("C:\\otoparkDB\\hasilatHesaplama.txt");
        dosyaYaz4<<"0";
        dosyaYaz4.close();

        getch();
        system("cls");
        yoneticiPaneli();

    }

    //Bu kısımda otopark işleminden toplamda kazanılan para miktarı hesaplanır ve ekrana yazdırılır.
    void yoneticiHasilatHesaplama(){

        ifstream hasilatOku("C:\\otoparkDB\\hasilatHesaplama.txt");
                string hasilat = "";

                if ( hasilatOku.is_open() )
                {

                    while ( getline(hasilatOku, hasilat) )
                    {

                    }

                    hasilatOku.close();
                }
        ifstream saatlikUcretOku("C:\\otoparkDB\\saatlikUcret.txt");
                string saatlikUcret = "";

                if ( saatlikUcretOku.is_open() )
                {

                    while ( getline(saatlikUcretOku, saatlikUcret) )
                    {

                    }

                    hasilatOku.close();
                }

        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t******************************"<<endl;
        cout<<"\t\t\t\t\t****      EGE OTOPARK     ****"<<endl;
        cout<<"\t\t\t\t\t****    YONETICI PANELI   ****"<<endl;
        cout<<"\t\t\t\t\t****   HASILAT HESAPLAMA  ****"<<endl;
        cout<<"\t\t\t\t\t******************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t ----------------------------------------  ";
                cout<<endl;
                cout<<"\t\t\t\t\t  Simdiye kadar kazanilan toplam para;";
                cout<<endl;
                cout<<"\t\t\t\t\t  "<<std::stoi(hasilat)*std::stoi(saatlikUcret)<<endl;
                cout<<"\t\t\t\t ----------------------------------------  ";
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tLutfen bir tusa basin..."<<endl;
                getch();
                system("cls");
                yoneticiPaneli();




    }
    //Burada yönetici istediği şekilde bilgileri girerek kendi araç girişi yapabilir.
    void yoneticiRezerve()
    {
        Musteri musteri;
        string a,b;
        int c;

        ifstream ayarOkuma("C:\\otoparkDB\\aracSayaci.txt");
        //Ayarların yapılıp yapılmadığı bu kısımda kontrol edilir.
        if(ayarOkuma.is_open())
        {
            //Otoparkta boş yer olup olmadığı bu kısımda kontrol edilir.
            if(musteri.parkYeriKontrol())
            {
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
                cout<<"\t\t\t\t\t****   YONETICI PANELI   ****"<<endl;
                cout<<"\t\t\t\t\t****    REZERVE ETME     ****"<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tLutfen Aracin Plakasini Giriniz (Bitisik Olarak): ";
                cin>>a;

                cout<<"\t\t\t\t\tLutfen Kisinin Ismini Giriniz : ";
                cin>>b;
                cout<<"\t\t\t\t\tLutfen Aracin Kac Saat Kalacagini Giriniz : ";
                cin>>c;
                //Struct ile arac verileri belirlenir

                ofstream dosyaYaz("C:\\otoparkDB\\araclar\\"+a+".txt");
                dosyaYaz<<a<<" "<<b<<" "<<c;
                dosyaYaz.close();
                musteri.aracSayacArttir();
                //Saatlik Ucret kısmı burada okunur.
                ifstream dosyaOku("C:\\otoparkDB\\saatlikUcret.txt");
                string satir = "";

                if ( dosyaOku.is_open() )
                {

                    while ( getline(dosyaOku, satir) )
                    {

                    }

                    dosyaOku.close();
                }

                cout<<"\t\t\t\t\tBilgileriniz alinmistir ve kaydedilmistir."<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tArac girisi sorunsuz bir sekilde yapilmistir."<<endl;
                cout<<"\t\t\t\t\tLutfen bir tusa basip devam ediniz...";
                //Yönetici kısmındaki hasilat hesaplama kısmı için burada bir saatleri toplayan sayaç vardır.
                ifstream hasilatOku("C:\\otoparkDB\\hasilatHesaplama.txt");
                string hasilat = "";

                if ( hasilatOku.is_open() )
                {

                    while ( getline(hasilatOku, hasilat) )
                    {

                    }

                    hasilatOku.close();
                }
                //Alınan kaç saat kalacağı bilgisi stack içine atılır.

                //Stack içine atılan değer hasilat bilgisine eklenir.
                ofstream hasilatYazdir("C:\\otoparkDB\\hasilatHesaplama.txt");
                hasilatYazdir<<std::stoi(hasilat)+c;
                hasilatYazdir.close();


                getch();
                system("cls");
                yoneticiPaneli();

            }
            else
            {
                //Eğer otoparkta yer kalmamışsa bu mesaj ile karşılaşılır.
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
                cout<<"\t\t\t\t\t****   YONETICI PANELI   ****"<<endl;
                cout<<"\t\t\t\t\t****    REZERVE ETME     ****"<<endl;
                cout<<"\t\t\t\t\t*****************************"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\t\t\tMalesef  Otoparkimizda bos yer kalmamistir..."<<endl;
                cout<<"\t\t\t\t\tLutfen bir tusa basip devam ediniz...";
                getch();
                system("cls");
                yoneticiPaneli();
            }

        }
        else
        {
            //Eğer yönetici ayarları yapmamışsa bu kısım ile karşılaşılır.
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\tSistemi kullanabilmek icin once yonetici ayarlamalari yapmali..."<<endl;
        }
    }
    //Temel profil seçim ekranı buradadır. Bu kısımda kullanıcı tipini seçer ve işlemlere başlar.
    void profilSecimEkrani()
    {
        int j;
        Yonetici yonetici;
        Musteri musteri;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<"\t\t\t\t\t****     EGE OTOPARK     ****"<<endl;
        cout<<"\t\t\t\t\t*****************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t   1. Yonetici Girisi"<<endl<<endl;
        cout<<"\t\t\t\t\t   2. Musteri Girisi"<<endl<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\n\n\t\t\t\tSeciminizi giriniz:";
        cin>>j;

        switch(j)
        {

        case 1:
            system("cls");
            yonetici.yoneticiSifre();
            break;
        case 2:
            system("cls");
            musteri.musteriPaneli();
            break;
        default:
            cout<<"Hatali giris yaptiniz!"<<endl;
            break;
        }

    }
};

//Sistem ilk çalıştığında ekrana gelen hoşgeldiniz yazısı bu kısımda belirlenir.
void girisEkrani()
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"          \t\t\t       ************************************"<<endl;
    cout<<"          \t\t\t****************************************************"<<endl;
    cout<<"          \t\t\t********      EGE OTOPARK | HOSGELDINIZ     ********"<<endl;
    cout<<"          \t\t\t****************************************************"<<endl;
    cout<<"          \t\t\t        ************************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                           \t \t     -> Devam etmek icin lutfen bir tusa basin..."<<endl;
    getch();
    system("cls");
}










//Bu kısımda Giriş için gerekli fonksiyonlar çalıştırılır ve sistem işlemeye başlar.
int main()
{
    Yonetici yonetici;

    girisEkrani();

    yonetici.profilSecimEkrani();



    return 0;
}
