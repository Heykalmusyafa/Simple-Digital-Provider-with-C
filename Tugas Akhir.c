#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct data{
  char nama[31];//Nama User
  char nik[17];//NIK user
  char bornplc[10];//tempat lahir user
  int dd;//hari kelahiran user
  int mm;//bulan kelahiran user
  int yyyy;//tahun kelahiran user
  char no[15];//Nomor telepon user
  char username[11];//Username user
  char pass[20];//password user
  int pulsa;//informasi pulsa user
  float primequo;//kuota Utama user
  int primeexp;//masa berlaku kuota utama user
  float socmedquo;//kuota social media user
  int socmedexp;//masa berlaku kuota social media user
  float dhquo;//kuota Disney+ Hotstar user
  int dhexp;//masa berlaku kuota  Disney+ Hotstar user
  float nfquo;//kuota Netflix user
  int nfexp;//masa berlaku kuota Netflix user
}*p;

int front();//Tampilan frontpage aplikasi
int login();//function untuk login user ke aplikasi
int cekNama();//untuk mengecek agar nama user sesuai dengan ketentuan saat registrasi
int cekBornplc();//untuk mengecek agar nama tempat kelahiran user sesuai dengan ketentuan saat registrasi
int cekNo();//untuk mengecek agar user tidak memiliki nomor telepon yang sama saat registrasi
int cekNIK();//untuk mengecek agar user tidak memiliki NIK yang sama saat registrasi
int cekUname();//untuk mengecek agar user tidak memiliki username yang sama saat registrasi
int regis();//function untuk user registrasi pada aplikasi
int home();//Tampilan homepage aplikasi
int userinfo();//function untuk menampilkan data diri user
int mykuota();//function untuk menampilkan kuota yang dimiliki user
int isipulsa();//Tampilan untuk pilihan isi pulsa
int buypackage();//Tampilan untuk pilihan beli kuota/paket 
int inputbuypackage();//input untuk beli kuota/paket
int tagihan();//Tampilan untuk tagihan ketika user beli paket/kuota
int inputtagihan(int paket,int quo,int exp,int cquo,int ch);//function yang memproses tagihan kuota/paket
//paket = harga kuota, quo = jumlah kuota yang dibeli (GB), exp = masa berlaku kuota, cquo = jenis kuota yang dibeli
void SetColor(unsigned short color);//Mengubah Warna Text

 //variabel untuk pilihan
int n; //jumlah akun yang terdaftar
int m; //akun yang sedang login

//Main program
int main() {
  	p=(struct data*) malloc(100*sizeof(struct data));	
  	front();
	printf("\nTerima Kasih! Silahkan Datang kembali ke Zlife!\n\n ");
  	return 0;
}

void SetColor(unsigned short color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}//Mengubah Warna Text

int front(){
	int xf=0;
  	while(xf==0){
  		int cf;
  		printf("Selamat Datang di Aplikasi Zlife\nSIM Digital yang bisa atur seluruh kebutuhan kamu, semau kamu!\n\n1. Login\n2. Registrasi\n0. Keluar\nPilihan kamu : ");
  		scanf("%d",&cf);
 		if(cf==1){
  			system("cls");
		  	login();
  		}// Jika memilih angka 1, Maka menuju page login
  		else if(cf==2){
  			system("cls");
   		 	regist(); 
  		}// Jika memilih angka 2, maka menuju page registrasi 
  		else if(cf==0){
  			xf=1;
  			continue; 	
  		}// Jika memilih angka 0, Maka keluar aplikasi
  		else{
  			system("cls");
  			SetColor(4);
  			printf("\nMasukkan angka dengan benar, ya!\n");
			SetColor(7);
			printf("\nTekan apa saja untuk melanjutkan\n");
			while(!_kbhit()){
			}
		system("cls");
  		}	// Error Handling jika memilih angka selain yang ada di pilihan
  	}
}// frontpage

int login(){
  	int x=0;
  	while(x==0){
    	char uname[11], //Input Username
    	pw[20]; //Input Password
    	int i=0,hasil1,hasil2,hasil3,a=0;
   		printf("Login aplikasi Zlife sekarang!\nMasukkan 'exit' pada kolom username untuk kembali ke halaman awal\n");
  		fflush(stdin);
    	printf("Masukkan Username : ");
    	scanf("%[^\n]s",&uname);
    	hasil3 = strcmp(uname, "exit");
    	if(hasil3==0){
    		system("cls");
    		a=1;
		}
   		else{
   			fflush(stdin);
	    	printf("Masukkan password : ");
	    	scanf("%[^\n]s",&pw);
	
	    	for(i=0;i<=n;i++){
	      		if(i==n){
	        		printf("\nAkun tidak ditemukan");
	      		}
	      
	      		hasil1 = strcmp(uname, (p+i)->username);
	      		hasil2 = strcmp(pw, (p+i)->pass);
	      		if(hasil1==0&&hasil2==0){
	    	 		m=i;
			    	a=1;
			    	i=n+1;
			    	system("cls");
	        		SetColor(10);
	 		    	printf("\nLogin Berhasil!\n\n");
	        		SetColor(7);
	 		    	printf("\nTekan apa saja untuk melanjutkan\n\n");
	        		while(!_kbhit()){}
	        		system("cls");
		  	  		home();
	      		}
	    	}
		}	
    	if(a==1){
    		x=1;
		}
		else{
			system("cls");
	    	SetColor(4);
	    	printf("\nPassword dan Username yang dimasukkan tidak cocok :( Coba lagi \n\n");
	    	SetColor(7);
	 	  	printf("\nTekan 'Esc' untuk melanjutkan\n\n");
	 	  	int a=0;
	    	while(a!=27){
	    		a=getch();		
			}
	    	system("cls");	
		}
	    	
  	}
}// untuk login user

int cekNIK(){
	int x=0;
	while(x==0){
		char noNIK[17]={0};
  		int i=0,hasil,alp=0,a=0;
  		{
  		fflush(stdin);
  		printf("Masukkan 16 Digit Nomor Induk Kependudukan : ");
  		scanf("%[^\n]s",&(p+n)->nik);
  		strcpy(noNIK,(p[n]).nik);
  
  		if (noNIK[16] != '\0'){
    		SetColor(4);
  			printf("\nNIK dilarang melebihi limit!\n");
    		SetColor(7);
    		a=1;
  		}
  		if (noNIK[0] =='0'){
    		SetColor(4);
  			printf("\nNIK dilarang diawali '0'!\n");
    		SetColor(7);
    		a=1;
  		}
  		for(i=0;i<16&&noNIK[i]!='\0';i++){
  			if((noNIK[i]>=48&&noNIK[i]<=57)){
	 			alp++;
			}
			else{
    			SetColor(4);
				printf("\nNIK tidak boleh selain angka!\n");
    			SetColor(7);
    			a=1;
    			i=16;	
			}
  		}
  		if(alp<16){
    		SetColor(4);
  			printf("\nNIK harus terdiri dari 16 angka!\n");
    		SetColor(7);
    		a=1;
  		}
  		for(i=0;i<n;i++){
    		hasil=strcmp((p+n)->nik,(p+i)->nik);
    		if(hasil==0){
      			SetColor(4);
      			printf("\nNIK sudah digunakan!\n");
      			SetColor(7);
      			a=1;
				i=n;	
    		}
  		}
  		}
  		if (a!=1){
			  x=1;	
		}
  	}
}// Mengecek agar NIK tidak ada yang sama

int cekNama(){
	int x=0;
	while(x==0){
  		char name[31]={0};
  		int i,hasil,alp=0,a=0;
  		fflush(stdin);
 	 	printf("Masukkan Nama Lengkap : ");
  		scanf("%[^\n]s",&(p+n)->nama);
  		strcpy(name,(p[n]).nama);
  		{
  		if (name[30] !='\0'){
    		SetColor(4);
  			printf("\nNama dilarang melebihi limit!\n");
    		SetColor(7);
    		a=1;
  		}
  		for(i=0;i<30&&name[i]!='\0';i++){
  			if((name[i]>=65&&name[i]<=90)||(name[i]>=97&&name[i]<=122)){
			alp++;
			}
			else if(name[i]==32){
			}
			else{
    		SetColor(4);
			printf("\nNama tidak boleh selain huruf dan spasi!\n");
    		SetColor(7);
    		a=1;	
			}
  		}
  		if(alp<3){
    		SetColor(4);
  			printf("\nNama minimal terdiri dari 3 huruf!\n");
    		SetColor(7);
    		a=1;
  		}
  		}
  		if (a!=1){
  			x=1;
		}
  	}
}
// Mengecek agar Nama sesuai

int cekBornplc(){
	int x=0;
	while(x==0){
  		char name[31]={0};
 		int i,hasil,alp=0,a=0;
 	 	fflush(stdin);
  		printf("Masukkan Tempat Lahir : ");
  		scanf("%[^\n]s",&(p+n)->bornplc);
  		strcpy(name,(p[n]).bornplc);
  		{
		if (name[30] !='\0'){
    		SetColor(4);
  			printf("\nTempat lahir dilarang melebihi limit!\n");
    		SetColor(7);
    		a=1;
  		}
  		for(i=0;i<30&&name[i]!='\0';i++){
  			if((name[i]>=65&&name[i]<=90)||(name[i]>=97&&name[i]<=122)){
	  		alp++;
			}
			else if(name[i]==32){
			}
			else{
    			SetColor(4);
				printf("\nTempat lahir tidak boleh selain huruf dan spasi!\n");
    			SetColor(7);
    			i=30;
    			a=1;	
			}
  		}
	  	if(alp<3){
		    SetColor(4);
		  	printf("\nTempat lahir minimal terdiri dari 3 huruf!\n");
		    SetColor(7);
		    a=1;
  		}
  		}
  		if (a!=1){
			x=1;
		}
	}
}


int cekNo(){
	int x=0;
	while(x==0){	
	  	char nomor[15]={0},nomor2[]="+62876";
	  	int i=0,hasil,alp=0,a=0;
	  	fflush(stdin);
	 	 printf("Masukkan 8 Digit Tambahan Nomor Zlife : +62876");
	  	scanf("%[^\n]s",&nomor);
	  	strcat(nomor2,nomor);
	  	strcpy((p[n]).no,nomor2);
	  	{
	  	if (nomor[8] != '\0'){
	   		SetColor(4);
		  	printf("\nNomor dilarang melebihi limit!\n");
		    SetColor(7);
		    a=1;
	  	}
	  	for(i=0;i<8&&nomor[i]!='\0';i++){
	  		if((nomor[i]>=48&&nomor[i]<=57)){
		  	alp++;
			}
			else{
		    	SetColor(4);
				printf("\nNomor tidak boleh selain angka!\n");
			    SetColor(7);
			    i=8;
			    a=1;	
			}
	  	}
		if(alp<8){
		    SetColor(4);
		  	printf("\nNomor Tambahan harus terdiri dari 8 angka!\n");
		    SetColor(7);
		    a=1;
  		}
		for(i=0;i<n;i++){
		    hasil=strcmp((p+n)->no,(p+i)->no);
		    if(hasil==0){
			    SetColor(4);
			    printf("\nNomor sudah digunakan!\n");
			    SetColor(7);
			    a=1;
		    }
  		}
  		}
  		if (a!=1){
			  x=1;
		}
  	}
}// Mengecek agar No tidak ada yang sama

int cekUname(){
	int x;
	while(x==0){
	  	char uname[11]={0};
	  	int i,hasil, hasil2,alp=0,a=0;
	  	fflush(stdin);
	  	printf("Masukkan Username : ");
	  	scanf("%[^\n]s",&(p+n)->username);
	  	hasil2=strcmp((p+n)->username,"exit");
	  	{
		if (hasil2==0){
	    	SetColor(4);
		 	printf("\nUsername dilarang!\n");
	    	SetColor(7);
	    	a=1;	
	  	}
	  	strcpy(uname,(p[n]).username);
	  	if (uname[10] !='\0'){
	    	SetColor(4);
	  		printf("\nUsername dilarang melebihi limit!\n");
	    	SetColor(7);
	    	a=1;
	  	}
	  	for(i=0;i<10&&uname[i]!='\0';i++){
	  		if((uname[i]>=65&&uname[i]<=90)||(uname[i]>=97&&uname[i]<=122)){
			alp++;
	    	}
	    	else if((uname[i]>=48&&uname[i]<=57)||uname[i]==32){	
	    	}
	    	else{
	      	SetColor(4);
	      	printf("\nUsername tidak boleh selain huruf dan angka!\n");
	      	SetColor(7);
	      	i=10;
	      	a=1;
	    	}
	  	}	
	  	if(alp<5){
	  		printf("\nUsername minimal terdiri dari 5 huruf/angka!\n");
	    	a=1;
	  	}
	  	for(i=0;i<n;i++){
	    	hasil=strcmp((p+n)->username,(p+i)->username);
	    	if(hasil==0){
	      		SetColor(4);
	      		printf("\nUsername sudah digunakan!\n\n");
	      		SetColor(7);
	      		a=1;
	    	}
	  	}
	  	}
	  	if (a!=1){
			  x=1;
		}
	}
}// Mengecek agar Username tidak ada yang sama dan bukan 'exit'

int regist(){
  	int no;
  	int x=0;
  
  	printf("\nRegistrasi dulu yuk!\n");
  	cekNama();
  	cekNIK();
 	cekBornplc();
  
	while(x==0){
	    printf("Masukkan Tanggal Lahir (dd) : ");
	    scanf("%d",&(p+n)->dd);
	    printf("Masukkan Bulan Lahir (mm) : ");
	    scanf("%d",&(p+n)->mm);
	    printf("Masukkan Tahun Lahir (yyyy) : ");
	    scanf("%d",&(p+n)->yyyy);
	    if ( (p[n]).yyyy <= 0||(p[n]).dd <= 0 ||(p[n]).mm <= 0 ||(p[n]).mm > 12 || (p[n]).yyyy > 2021
	    || ( (p[n]).dd > 29 && (p[n]).mm == 2 )
	    || ( (p[n]).dd > 31 && ( (p[n]).mm == 1 || (p[n]).mm == 3 || (p[n]).mm == 5 || (p[n]).mm == 7 || (p[n]).mm == 8 || (p[n]).mm == 10 || (p[n]).mm == 12 ) )
	    || ( (p[n]).dd > 30 && ( (p[n]).mm == 4 || (p[n]).mm == 6 || (p[n]).mm == 9 || (p[n]).mm == 11 ) ) 
	    || (((p[n]).dd == 29) &&((p[n]).mm == 2) &&((p[n]).yyyy % 4 > 0)) ){
	     	SetColor(4);
	      	printf("\nMasukkan data dengan benar, ya!\n");
	      	SetColor(7);
	    } //mencegah input tanggal lahir salah
	    else{
	      x=1;
	    }
	}
  	cekNo();
  	fflush(stdin);
  	cekUname();

  	fflush(stdin);
  	printf("Masukkan Password : ");
  	scanf("%[^\n]s",&(p+n)->pass);
  	(p+n)->pulsa=0;    
  	(p+n)->primequo=0;
  	(p+n)->socmedquo=0;
  	(p+n)->dhquo=0;
  	(p+n)->nfquo=0;
  	(p+n)->primeexp=0;
  	(p+n)->socmedexp=0;
  	(p+n)->dhexp=0;
  	(p+n)->nfexp=0;
  	n++;// jumlah user yang terdaftar bertambah
  	system("cls");
  	SetColor(10);
  	printf("Registrasi Berhasil!\n\n");
  	SetColor(7);
  	printf("Tekan apa saja untuk melanjutkan\n\n");
  	while(!_kbhit()){}
  	system("cls");
}// Registrasi user

int home(){
  	float kuota;
  	int c, x=0;
	  	
	while(x==0){
		kuota = (p+m)->primequo + (p+m)->socmedquo + (p+m)->dhquo + (p+m)->nfquo;
		printf("Selamat datang di Zlife %s\n\nJumlah Pulsa Anda : Rp. %d\nTotal Kuota Intenet : %.2f GB\n\nMenu\n1. Info Pengguna\n2. Rincian Kuota\n3. Isi Pulsa\n4. Beli Paket\n0. Logout\nPilihan Kamu : ",(p+m)->nama,(p+m)->pulsa,kuota);
		scanf("%d",&c);
	  	if(c==1){
	 		system("cls");
	    	userinfo();
	  	}
	  	else if(c==2){
	  		system("cls");
	  		mykuota();
	 	}
	 	else if(c==3){
	  		system("cls");
	 		isipulsa();
		}
		else if(c==4){
	  		system("cls");
	 		buypackage();
		}
	 	else if(c==0){
	 		x=1;
	  		system("cls");
	      	SetColor(10);
	   		printf("\nLogout Berhasil!\n");
	      	SetColor(7);
	      	printf("Tekan apa saja untuk melanjutkan\n\n");
	      	while(!_kbhit()){}
	      	system("cls");
	 	}
	  	else{
	      	system("cls");
	      	SetColor(4);
	   		printf("\nMasukkan angka dengan benar, ya!\n");
	      	SetColor(7);
	     	 printf("Tekan apa saja untuk melanjutkan\n\n");
	      	while(!_kbhit()){}
	      	system("cls");
	  	}
	}
}// Homepage

int userinfo(){
	int x=0;
	printf("Informasi Pengguna\n\n");
	printf("Nama Pengguna			: %s\n",(p+m)->nama);
	printf("NIK				: %s\n",(p+m)->nik);
	printf("Tempat/Tanggal Lahir		: %s/",(p+m)->bornplc);
	printf("%d ",(p+m)->dd);
	if((p[m]).mm==1){
	  	printf("Januari");
	}
  	else if((p[m]).mm==2){
  		printf("Februari");
  	}
  	else if((p[m]).mm==3){
  		printf("Maret");	
  	}
  	else if((p[m]).mm==4){
  		printf("April");
  	}
  	else if((p[m]).mm==5){
  		printf("Mei");
  	}
  	else if((p[m]).mm==6){
  		printf("Juni");
  	}
  	else if((p[m]).mm==7){
  		printf("Juli");
  	}
  	else if((p[m]).mm==8){
  		printf("Agustus");
  	}
  	else if((p[m]).mm==9){
  		printf("September");
  	}
  	else if((p[m]).mm==10){
  		printf("Oktober");
  	}
  	else if((p[m]).mm==11){
  		printf("November");
  	}
  	else if((p[m]).mm==12){
  		printf("Desember");
  	}//Menampilkan bulan dalam bentuk abjad
	printf(" %d\n",(p+m)->yyyy);
	printf("Nomor Zlife			: %s\n",(p+m)->no);
	printf("Username			: %s\n",(p+m)->username);
	printf("Password			: %s\n\nTekan apa saja untuk kebali....",(p+m)->pass);
	while(!_kbhit()){	
	}//jika keyboard ditekan
	system("cls");
}// Menampilkan data diri user

int mykuota(){
	int c, x=0;
	while(x==0){
	  	printf("Berikut Rincian Pulsa Kamu\n\nKuota Internet		: %.2f GB",(p+m)->primequo);
	  	printf("\n\n===Topping Kuota===\n");
	  	if ((p[m]).socmedquo>0){
		 	printf("Kuota Social Media		: %.2f GB	(Masa Berlaku %d Hari)\n",(p+m)->socmedquo,(p+m)->socmedexp);
		}	
		if ((p[m]).nfquo>0){
			printf("Kuota Netflix		: %.2f GB	(Masa Berlaku %d Hari)\n",(p+m)->nfquo,(p+m)->nfexp);
		}
		if ((p[m]).dhquo>0){
			printf("Kuota Disney+ Hotstar		: %.2f GB	(Masa Berlaku %d Hari)\n",(p+m)->dhquo,(p+m)->dhexp);
		}
	  	if((p[m]).socmedquo==0 && (p[m]).nfquo==0 && (p[m]).dhquo==0){
	    	printf("Kamu tidak memiliki jenis kuota lain :(\n");
	  	}
	
	  	printf("\nMasukkan angka '1' untuk membeli kuota internet atau angka '0' untuk kembali ke home: ");
	
	    scanf("%d", &c);
	    if(c==1){
	      system("cls");
	      buypackage();
	      x++;
	    }
	    else if(c==0){
	    	system("cls");
	      	x++;
	    }
	    else{
	      SetColor(4);
	      printf("\nMasukkan angka dengan benar, ya!\n");
	      SetColor(7);
	      printf("Tekan apa saja untuk melanjutkan\n\n");
	      while(!_kbhit()){}
	      system("cls");
	    }
  	}
}// Menampilkan rincian kuota user

int isipulsa(){
	int c,xi=0;
	while(xi==0){
		int tambahpulsa,x=0;
		printf("Ayo, Isi Pulsa Kamu Sekarang Juga! \n\nMasukkan Nominal Pulsa yang Mau Kamu Isi : Rp. ");
	  	while(x==0){
		    scanf ("%d",&tambahpulsa);
		    if(tambahpulsa<=0){
		      SetColor(4);
		      printf("Masa isi pulsa negatif :(, masukkan angka yang benar!\n\nMasukkan Nominal Pulsa yang Mau Kamu Isi : Rp. ");
		      SetColor(7);
		    }
		    else{
		      x=1;
		    }
		}
	  	x=0;
		printf("\nPilih Opsi Pembayaran\n1. ZWallet\n2. MitraZ\n3. Indomaret\n4. Alfamart/Alfamidi\nPilihan Kamu : ");
		while (x==0){
			scanf("%d", &c);
			if (c>=1&&c<=4){
				x=1;
			}
			else {
	      		SetColor(4);
				printf("Masukkan angka dengan benar, ya!");
	      		SetColor(7);
	      		printf("\nPilihan Kamu : ");
			}
		}
		x=0;
		printf("\nBerikut Rincian Tagihan Kamu : \n\n");
		printf("Nama Pengguna					: %s\n",(p+m)->nama);
		printf("Nomor Pengguna					: %s\n",(p+m)->no);
		printf("Jumlah yang harus dibayarkan			: Rp. %d\n",tambahpulsa);
		printf("Dibayar Melalui					: ");
		if(c==1){
			printf("ZWallet\n");
		}
		else if(c==2){
			printf("MitraZ\n");
		}
		else if(c==3){
			printf("indomaret\n");
		}
		else if(c==4){
			printf("Alfamart/Alfamidi\n");
		}
		printf("\nMasukkan angka '1' untuk menkonfirmasi pembayaran atau '0' untuk membatalkan : ");
		while(x==0){
	    	scanf("%d",&c);
	    	if(c==1){
	      		x=1;
	    	}
	    	else if(c==0){
		      	system("cls");
		      	SetColor(4);
		      	printf("\n==Pembayaran kamu dibatalkan==\n\n");
		      	SetColor(7);
		      	printf("\nTekan apa saja untuk melanjutkan\n\n");
		      	while(!_kbhit()){}
		      	system("cls");
		      	x=1;
            xi=1;
	    	}
	    	else {
		      	SetColor(4);
		      	printf("\nMasukkan angka yang benar, ya!\n");
		      	SetColor(7);
		      	printf("\nPilihan Kamu : ");
	    	}
	  	}
	  	if(c!=0){
	  		x=0;
			(p+m)->pulsa+=tambahpulsa;
		  	SetColor(10);
		  	printf("\nPembayaran Terkonfirmasi!\n\n");
		  	SetColor(7);
			printf("Pulsa anda sekarang Rp. %d\n\n1. Isi Pulsa Lagi\n0. Kembali ke Home\nPilihan Kamu : ",(p+m)->pulsa);
			while(x==0){
				scanf("%d", &c);
				if (c==0){
					system("cls");
					xi=1;
					x=1;
				}
				else if(c==1){
					system("cls");
					x=1;
				}
				else {
			    	SetColor(4);
					printf("\nMasukkan angka dengan benar, ya!\n");
			    	SetColor(7);
				}
			
		  	}
		}
	}
}// Tampilan isi pulsa

int buypackage(){
	int c, c1, x=0;
  while(x==0){
    printf("Pilih paket yang kamu mau!");
    printf("\n1. Paket utama\n2. Paket social media\n3. Paket hiburan\n Ketik '0' untuk kembali ke home\n");
    int y=0, ch, quo, paket, exp, cquo;//penentu jenis paket yang dipilih
    printf("pilih paket (0/1/2/3): ");
    scanf("%d", &c);
    if(c==1){
      system("cls");
      printf("Paket promo khusus buat kamu!\n\n1. 5 GB/bulan Rp. 15000\n2. 25 GB/bulan Rp. 45000\n3. 60 GB/bulan Rp. 75000\nUntuk kembali ke menu sebelumya masukkan '0'\n\n");  
      
      while(y==0){
        printf("Pilih paket: ");
        scanf("%d",&ch);
        if(ch==1){
          paket = 15000;
          quo = 5;
          exp = 30;
          y=1;
        }
        else if(ch==2){
          paket = 45000;
          quo = 25;
          exp = 30;
          y=1;
        }
        else if(ch==3){
          paket = 75000;
          quo = 60;
          exp = 30;
          y=1;
        }
        else if(ch==0){
          paket=0;
          quo=0;
          exp=0;
          y=1;
        }
        else{
          SetColor(4);
          printf("\nMasukkan angka dengan benar, ya!\n");
          SetColor(7);
        }
      }
      cquo=1;
      if (ch!=0){
        if((p+m)->pulsa>=paket){
          tagihan(paket,quo,exp,cquo,c1);
          if(c1==0){
            x=1;
          }
        }
        else{
          system("cls");
          SetColor(4);
          printf("\n======Pulsa kamu tidak cukup. Isi pulsa kamu dulu, ya!======\n");
          SetColor(7);
          printf("\nTekan apa saja untuk melanjutkan\n");
          while(!_kbhit()){}
          system("cls");
          x=1;
        }
      }
      else{
        system("cls");
      }
    }
    else if(c==2){
      system("cls");
      printf("Main socmed sepuasnya sampe jadi artis!\n\n1. 1 GB/7 Hari Rp. 3000\n2. 5 GB/7 Hari Rp. 10000\n3. 15 GB/7 Hari Rp. 25000\nUntuk kembali ke menu sebelumya masukkan '0'\n\n");
      
      while(y==0){
        printf("Pilih paket: ");
        scanf("%d",&ch);
        if(ch==1){
          paket = 3000;
          quo = 1;
          exp = 7;
          y=1;
        }
        else if(ch==2){
          paket = 10000;
          quo = 5;
          exp = 7;
          y=1;
        }
        else if(ch==3){
          paket = 25000;
          quo = 15;
          exp = 7;
          y=1;
        }
        else if(ch==0){
          paket=0;
          quo=0;
          exp=0;
          y=1;
        }
        else{
          SetColor(4);
          printf("\nMasukkan angka dengan benar, ya!\n");
          SetColor(7);
        }
      }
      cquo=2;
      if (ch!=0){
        if((p+m)->pulsa>=paket){
          tagihan(paket,quo,exp,cquo,c1);
          if(c1==0){
            x=1;
          }
        }
        else{
          system("cls");
          printf("\n===Pulsa kamu tidak cukup. Isi pulsa kamu dulu, ya!===\n\n");
          x=1;
        }
      }
      else{
        system("cls");
      }
    }
    else if(c==3){
      system("cls");
      printf("Nonton Drama dan Film yang lagi HYPE! Biar hari-hari kamu ga ngebosenin!\n\n1. Netflix 5 GB/Bulan Rp. 15.000\n2. Netflix 15 GB/Bulan Rp. 30000\n3. Disney+ Hotstar 5 GB/Bulan Rp. 15000\n4. Disney+ Hotstar 5 GB/Bulan Rp. 30000\nUntuk kembali ke menu sebelumya masukkan '0'\n\n");
      
      while(y==0){
        printf("Pilih paket: ");
        scanf("%d",&ch);
        if(ch==1){
          paket = 15000;
          quo = 5;
          exp = 30;
          cquo=3;
          y=1;
        }
        else if(ch==2){
          paket = 30000;
          quo = 15;
          exp = 30;
          cquo=3;
          y=1;
        }
        else if(ch==3){
          paket = 15000;
          quo = 5;
          exp = 30;
          cquo=4;
          y=1;
        }
        else if(ch==4){
          paket = 30000;
          quo = 15;
          exp = 30;
          cquo=4;
          y=1;
        }
        else if(ch==0){
          paket=0;
          quo=0;
          exp=0;
          y=1;
        }
        else{
          printf("\nMasukkan angka dengan benar, ya!\n");
        }
      }
      if (ch!=0){
        if((p+m)->pulsa>=paket){
          tagihan(paket,quo,exp,cquo,c1);
          if(c1==0){
            x=1;
          }
        }
        else{
          system("cls");
          printf("\n===Pulsa kamu tidak cukup. Isi pulsa kamu dulu, ya!===\n\n");
          x=1;
        }
      }
      else{
        system("cls");
      }
    }
    else if(c==0){
      system("cls");
      x=1;
    }
    else{
      system("cls");
      printf("\nMasukkan angka dengan benar, ya!\n");
    }
  } 
}// Tampilan beli kuota/paket

int tagihan(int paket,int quo,int exp,int cquo,int ch){
  int xt=0;
  while(xt==0){
    int x=0,c;
    printf("\nBerikut Rincian Tagihan Kamu : \n\n");
    printf("Nama Pengguna					: %s\n",(p+m)->nama);
    printf("Nomor Pengguna					: %s\n",(p+m)->no);
    printf("Jumlah yang harus dibayarkan			: Rp. %d\n",paket);
    printf("Jumlah kuota					: %d GB\n",quo);
    printf("Masa berlaku kuota				: %d hari\n", exp);
  
    printf("Jenis kuota                   			: ");
    if(cquo==1){
      printf("Paket Utama\n");
    }
    else if(cquo==2){
      printf("Paket Social Media\n");
    }
    else if(cquo==3){
      printf("Paket Netflix\n");
    }
    else if(cquo==4){
      printf("Paket Disney+ Hotstar\n");
    }
    printf("\nMasukkan angka '1' untuk menkonfirmasi pembayaran dan '0' untuk membatalkan : ");
    scanf("%d",&c);
    if(c==1){
      (p+m)->pulsa = (p+m)->pulsa-paket;
      if(cquo==1){
        (p+m)->primequo+=quo;
        (p+m)->primeexp+=exp;
      }
      else if(cquo==2){
        (p+m)->socmedquo+=quo;
        (p+m)->socmedexp+=exp;
      }
      else if(cquo==3){
        (p+m)->nfquo+=quo;
        (p+m)->nfexp+=exp;
      }
      else if(cquo==4){
        (p+m)->dhquo+=quo;
        (p+m)->dhexp+=exp;
      }
      int x=0;
      printf("\nPembayaran Terkonfirmasi!\n\n1. Beli Paket Lagi\n0. Kembali ke Menu Sebelumnya\nPilihan Kamu : ");
      while(x==0){
        scanf("%d",&ch);
        if(ch==1){
          x=1;
          xt=1;
          system("cls");
        }
        else if(ch==0){
          x=1;
          xt=1;
          system("cls");
        }
        else{
          printf("\n Masukkan angka dengan benar, ya!: ");
        }
      }
    }
    else if(c==0){
      ch=0;
      system("cls");
      printf("\n==Pembayaran kamu dibatalkan==\n\n");
      xt=1;
    }
    else{
      printf("\n Masukkan angka dengan benar, ya!");
    }
  }
}// Display tagihan beli kuota/paket
