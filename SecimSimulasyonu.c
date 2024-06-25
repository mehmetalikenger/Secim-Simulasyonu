#include <stdio.h>

//FONKSÝYON PROTOTÝPLERÝ
int oyGir(int dizi[4][6], int ilKod);
int milletvekiliAta(int dizi[4][6], int ilKod);
int listele(int dizi[4][6], int ilKod, int toplamOy, int kontenjan);
void genelListele(int dizi1[4][6],int dizi2[4][6],int dizi3[4][6],int dizi4[4][6],int dizi5[4][6], int il1_birinciParti, int il2_birinciParti, int il3_birinciParti, int il4_birinciParti, int il5_birinciParti);

int main() {
	
	int toplamOy = 0;	
	
	int il_1[4][6];
	int il1_kod = 1;
	int il1_toplamOy = oyGir(il_1, il1_kod);
	int il1_kontenjan = milletvekiliAta(il_1, il1_kod);
	
	int il_2[4][6];
	int il2_kod = 2;
	int il2_toplamOy = oyGir(il_2, il2_kod);
	int il2_kontenjan = milletvekiliAta(il_2, il2_kod);
	
	int il_3[4][6];
	int il3_kod = 3;
	int il3_toplamOy = oyGir(il_3, il3_kod);
	int il3_kontenjan = milletvekiliAta(il_3, il3_kod);
	
	int il_4[4][6];
	int il4_kod = 4;
	int il4_toplamOy = oyGir(il_4, il4_kod);
	int il4_kontenjan = milletvekiliAta(il_4, il4_kod);
	
	int il_5[4][6];
	int il5_kod = 5;
	int il5_toplamOy = oyGir(il_5, il5_kod);
	int il5_kontenjan = milletvekiliAta(il_5, il5_kod);
	
	int il1_birinciParti = listele(il_1, il1_kod, il1_toplamOy, il1_kontenjan);
	int il2_birinciParti = listele(il_2, il2_kod, il2_toplamOy, il2_kontenjan);
	int il3_birinciParti = listele(il_3, il3_kod, il3_toplamOy, il3_kontenjan);
	int il4_birinciParti = listele(il_4, il4_kod, il4_toplamOy, il4_kontenjan);
	int il5_birinciParti = listele(il_5, il5_kod, il5_toplamOy, il5_kontenjan);
	genelListele(il_1, il_2, il_3, il_4, il_5, il1_birinciParti, il2_birinciParti, il3_birinciParti, il4_birinciParti, il5_birinciParti);
	
	return 0;
}

//FONKSIYONLAR
//OY GÝRME FONKSÝYONU
int oyGir(int dizi[4][6], int ilKod){
		
	int i, partiAd = 65, toplamOy = 0;                          // Diziler integer deðer tuttuklarý için parti adlarý olan harfleri, dizide integer olarak tutuyoruz.
	
	for(i = 0; i <= 5; i++) {
		
		printf("%c partisinin %d kodlu il icin gecerli oy sayisini giriniz: ", partiAd, ilKod);
		scanf("%d", &dizi[1][i]);
		dizi[3][i] = dizi[1][i];                          // Milletvekili atama algoritmasýnda oy sayýlarý bölünerek deðiþtiði için yandaki kodda oy sayýlarý farklý bir satýra kopyalanýyor.
		dizi[0][i] = partiAd;
		
		toplamOy += dizi[1][i];
		partiAd++;	
	}	
	
	printf("\n");
	return toplamOy;
}

//MÝLLETVEKÝLÝ ATAMA FONKSÝYONU
int milletvekiliAta(int dizi[4][6], int ilKod){
	
	int kontenjan,i, enBuyuk;
	printf("Lutfen %d kodlu il icin milletvekili kontenjanini giriniz: ", ilKod);
	scanf("%d", &kontenjan);
	int kopyaKontenjan = kontenjan;                             // Kontenjan deðeri döngü içinde sýfýrlandýðý için bu deðeri kopyalýyoruz.
	
	for(i = 0; i < 6; i++){                                       /* Milletvekili sayýlarýný tutacak olan indexler þu an hiçbir deðer tutmuyorlar. Milletvekili atarken bu indexlere direk +1 eklediðimiz için 
                                        							ve çýktý alýrken sorun yaþamamak için bu indexlere baþlangýç olarak 0 deðerini atýyoruz. */		
		dizi[2][i] = 0;
}
	while(kontenjan > 0){
		enBuyuk = 0;
		
		for(i = 0; i < 6; i++){                                   // Bu döngüde dizideki en büyük oy sayýsýnýn tutan sütün bulunuyor ve enBuyuk deðiþkenine atanýyor. Döngüler kontenjan bitene kadar devam ediyor.
			if(dizi[1][i] >= dizi[1][enBuyuk]){
				enBuyuk = i;
			}
	}
		dizi[2][enBuyuk] += 1;                      // enBuyuk deðiþkeninin tuttuðu sütun index deðeri kullanýlarak, o sütunda bulunan partiye +1 milletvekili atanýyor.
		dizi[1][enBuyuk] /= 2;                      // Milletvekili atanan partinin oyu yarýya düþürülüyor.
		kontenjan -= 1;
	}
	
	printf("\n");
	return kopyaKontenjan;
}

//LÝSTELEME FONKSÝYONU
int listele(int dizi[4][6], int ilKod, int toplamOy, int kontenjan){
	
	int i, j, temp1 = 0, temp2 = 0, temp3 = 0, diziKopya[4][6], birinciParti;

	for(i = 0; i < 4; i++){                                      /* Türkiye geneli sonuçlarýný hatasýz yazdýrabilmemiz için il dizilerinin bubble sort ile deðiþtirilmemiþ halleri gerekiyor.
		                                       	   					Bu nedenle il dizilerini baþka bir diziye kopyalayýp, bubble sort algoritmasý içinde bu kopya diziyi kullanýyoruz. */	
		for(j = 0; j < 6; j++){
			
			diziKopya[i][j] = dizi[i][j];			
		}		
	}	
	
	for (i = 0; i < 5; i++) {                                             // Bubble Sort
    
		for (j = 0; j < 6 - i - 1; j++) {
      
	  		if (diziKopya[3][j] > diziKopya[3][j+1]){
        		temp1 = diziKopya[3][j];
        		diziKopya[3][j] = diziKopya[3][j+1];
        		diziKopya[3][j+1] = temp1;
        		
        		temp2 = diziKopya[2][j];
        		diziKopya[2][j] = diziKopya[2][j+1];
        		diziKopya[2][j+1] = temp2;
        		
        		temp3 = diziKopya[0][j];
        		diziKopya[0][j] = diziKopya[0][j+1];
        		diziKopya[0][j+1] = temp3;    		
      		}
    	}
  }
	
	birinciParti = diziKopya[0][5];

	printf("Il Plaka Kodu: %d\n", ilKod);
	printf("Milletvekili Kontenjani: %d\n", kontenjan);
	printf("Gecerli Oy Sayisi: %d\n", toplamOy);
	printf("\t\tOy Sayisi      Oy Yuzdesi     MV Sayisi\n");
	printf("\t\t---------      ----------     ---------\n");
		
	for(i = 5; i >= 0; i--){
			
		printf("%c Partisi\t", diziKopya[0][i]);
		printf("%6d\t\t", diziKopya[3][i]);
		printf("%6.2f\t\t", (float)(diziKopya[3][i]*100)/toplamOy);
		printf("%3d\n", diziKopya[2][i]);
	}
		printf("\nDevam etmek icin bir tusa basiniz...\n");
		getch();
		
		printf("\n");
		return birinciParti;                                                       // birinciParti = O ilde en çok oyu alan parti
}

//ÜLKE GENELÝ ÝÇÝN LÝSTELEME FONKSÝYONU
void genelListele(int dizi1[4][6], int dizi2[4][6], int dizi3[4][6], int dizi4[4][6], int dizi5[4][6], int il1_birinciParti, int il2_birinciParti, int il3_birinciParti, int il4_birinciParti, int il5_birinciParti){
	
	int i, j, genel[4][6], partiAd = 65, toplamOy = 0, mvToplami = 0, temp1, temp2, temp3, enBuyuk = 0, sayac;
	
	for(i = 0; i < 6; i++){
		genel[0][i] = partiAd;
		partiAd++;
		genel[1][i] = dizi1[3][i] + dizi2[3][i] + dizi3[3][i] + dizi4[3][i] + dizi5[3][i];             // Tüm partilerin tüm illerdeki oy sayýlarýný toplayarak genelDiziye atýyoruz.
		genel[2][i] = dizi1[2][i] + dizi2[2][i] + dizi3[2][i] + dizi4[2][i] + dizi5[2][i];			   // Tüm partilerin tüm illerdeki milletvekili sayýlarýný toplayarak genelDiziye atýyoruz.
	}
	
	for(i = 0; i < 6; i++){
			toplamOy += genel[1][i];
			mvToplami += genel[2][i];
		}
		
	for (i = 0; i < 5; i++) {                              // Bubble Sort
    
		for (j = 0; j < 6 - i - 1; j++) {
      
	  		if (genel[1][j] > genel[1][j+1]){
        		temp1 = genel[1][j];
        		genel[1][j] = genel[1][j+1];
        		genel[1][j+1] = temp1;
        		
        		temp2 = genel[2][j];
        		genel[2][j] = genel[2][j+1];
        		genel[2][j+1] = temp2;
        		
        		temp3 = genel[0][j];
        		genel[0][j] = genel[0][j+1];
        		genel[0][j+1] = temp3;	
      		}
    	}
  }
  
  	printf("Turkiye Geneli\n");
	printf("Milletvekili Kontenjani: %d\n", mvToplami);
	printf("Gecerli Oy Sayisi: %d\n", toplamOy);
	printf("\t\tOy Sayisi      Oy Yuzdesi     MV Sayisi      MV Yuzdesi\n");
	printf("\t\t---------      ----------     ---------      ----------\n");
		
	for(i = 5; i >= 0; i--){
			
		printf("%c Partisi\t", genel[0][i]);
		printf("%6d\t\t", genel[1][i]);
		printf("%6.2f\t\t", (float)(genel[1][i]*100)/toplamOy);
		printf("%3d\t\t", genel[2][i]);
		printf("%5.2f\n", (float)(genel[2][i]*100)/mvToplami);				
	}
	
	for(i = 0; i < 6; i++){                                                  
		if(genel[2][i] >= genel[2][enBuyuk]){                                     // En yüksek milletvekili sayýsýna sahip partinin sütun indeksi bulunuyor.
		enBuyuk = i;
		}
	}
	
	printf("\nIktidar partisi: %c", genel[0][enBuyuk]);
	genel[2][enBuyuk] = 0;                                                			
		
	for(i = 0; i < 6; i++){
		if(genel[2][i] >= genel[2][enBuyuk]){
		enBuyuk = i;
		}
	}
		
	printf("\nAna Muhalefet Partisi: %c\n\n", genel[0][enBuyuk]);
				
	int ilBirincileri[6] = {il1_birinciParti, il2_birinciParti, il3_birinciParti, il4_birinciParti, il5_birinciParti, 0};           // Her ilde en çok oyu alan parti diziye atanýyor.
	
	printf("Partilerin oy sayilarina gore il birincilikleri:");		
	for(i = 0; i < 5; i++){                                                            // Bu algoritma, dizi içinde tekrar eden deðerlerin tekrar sayýsýný buluyor. Tekrar etmeyen deðerler için 1 sonucunu yazýyor.
			
		sayac = 1;
	
		for(j = i+1; j < 6; j++){
			
			if(ilBirincileri[i] == ilBirincileri[j]) {	
				sayac++;
				ilBirincileri[j] = 0;							//Eðer tekrar varsa; sayac arttýrýldýktan sonra tekrar olan indekslere sýfýr deðeri atanýyor. Böylece partiler sonuc ekranýnda birden fazla kez yazdýrýlmýyor.
				
			} else if (ilBirincileri[i] == 0) {
					
					break;
			  }
		}
		
		if(ilBirincileri[i] != 0) {
			printf("\n%c Partisi %d ilde birinci.", ilBirincileri[i], sayac);
		}
		
		if(sayac == 5){
			break;
		}
	}
		getch();
}
