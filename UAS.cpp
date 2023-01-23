#include <stdio.h>   
#include <conio.h>
#include <stdlib.h>
struct Opsi
{
	int Pilihan,ambil,kembali;
	char Sopir,TM;
}Pil;
struct itungan{
	int Bsewa,Bsopir,makan,waktu,overtime,Tsewa,Tjasa,total;
}rms;
char Minibus;
void Intro(void);void OpsiMobil(void);  
void jasa(void);void WAK();void rumus();
main()
{
  Intro();
  OpsiMobil();
  jasa();
  WAK();
  rumus();
  getch();
}

/*definisi fungsi*/
void Intro(void)
{ 
	puts("Rental Mobil \"SISFO\""); 
	puts("====================");
	puts("Tipe Mobil Yang Tersedia");
	puts("1. Minibus	Rp 350000");
	puts("2. Sedan	Rp 400000");
	puts("3. MPV		Rp 450000");
	puts("4. SUV		Rp 550000");
	puts("*harga per 12 jam");
}
void OpsiMobil()
{do{
	printf("Tipe Mobil Yang Dipilih = ");scanf("%d",&Pil.Pilihan);
	if(Pil.Pilihan==1){
		rms.Bsewa=350000;
	}
	else if(Pil.Pilihan==2){
		rms.Bsewa=400000;
	}
	else if(Pil.Pilihan==3){
		rms.Bsewa=450000;
	}
	else if(Pil.Pilihan==4){
		rms.Bsewa=550000;
	}
	else{printf("Input salah\n");
	}
}while(Pil.Pilihan>=5);
}
void jasa()
{
	printf("Menggunakan jasa sopir [Y/N] = ");scanf("%s",&Pil.Sopir);
	if(Pil.Sopir=='y'||Pil.Sopir=='Y'){
		rms.Bsopir=150000;
		rms.makan=50000;
	}
	else if(Pil.Sopir=='n'||Pil.Sopir=='N'){
		rms.Bsopir=0;
		rms.makan=0;
	}
}
void WAK()
{do{
	printf("Waktu pengambilan  = ");scanf("%d",&Pil.ambil);
	printf("Waktu pengembalian = ");scanf("%d",&Pil.kembali);
	if(Pil.ambil>=25||Pil.kembali>=25){
		printf("input salah\n");
	}
}while(Pil.ambil>=25||Pil.kembali>=25);
}
void rumus()
{if(Pil.kembali>>Pil.ambil){
	rms.waktu=Pil.kembali-Pil.ambil;
	if(rms.waktu%12==0){
		rms.Tsewa=rms.waktu/12*rms.Bsewa;
		rms.Tjasa=rms.Bsopir+rms.makan;
		rms.total=rms.Tjasa+rms.Tsewa;
		}
	if(rms.waktu%12!=0){
                rms.makan=70000;
		rms.overtime=rms.waktu%12;
		rms.Tsewa=rms.overtime*(rms.Bsewa*0.1)+(rms.waktu-rms.overtime)/12*rms.Bsewa;
		rms.Tjasa=rms.Bsopir+rms.makan;
		rms.total=rms.Tjasa+rms.Tsewa;
		}
	}
if(Pil.ambil>=Pil.kembali){
	rms.waktu=(24-Pil.ambil)+Pil.kembali;
	if(rms.waktu%12==0){
		rms.Tsewa=rms.waktu/12*rms.Bsewa;
		rms.Tjasa=rms.Bsopir+rms.makan;
		rms.total=rms.Tjasa+rms.Tsewa;
		}
	if(rms.waktu%12!=0){
		rms.makan=70000;
		rms.overtime=rms.waktu%12;
		rms.Tsewa=rms.overtime*(rms.Bsewa*0.1)+(rms.waktu-rms.overtime)/12*rms.Bsewa;
		rms.Tjasa=rms.Bsopir+rms.makan;
		rms.total=rms.Tjasa+rms.Tsewa;
		}
	}
printf("Total Biaya Sewa 				= %d\n",rms.Tsewa);
printf("Total Biaya Jasa				= %d\n",rms.Tjasa);
printf("Total Yang Harus Dibayar			= %d",rms.total);
}

