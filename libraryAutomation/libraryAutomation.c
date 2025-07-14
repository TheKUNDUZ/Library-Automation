#include <stdio.h>
#include <stdlib.h>



FILE *fgercek,*fsahte;




struct ogrenci    //kayýt listeleme ve silme için int in yanýna birde durum eklemek gerekli
{
    int kimlikNumarasi[11];
    char ad[20];
    char soyad[20];
    char bolum[50];
}; 

struct ogrenci s,s1;


int main(){
	
	int silincekkisi[11];
	int silmedurum;
    printf("<----Kutuphanemize Hosgeldiniz---->\n\n");
    printf("kayit olusturmak icin 1'e basiniz\n");
    printf("Kayitli silmek icin  2'ye basiniz\n");
    printf("Kayitli kullanicilari listelemek icin 3'e basiniz\n");
    printf("Kayit guncellemek icin 4'e basiniz\n\n");
    int anaMenu;
    scanf("%d",&anaMenu);


    if(anaMenu==1){
    	
		fgercek=fopen("C:\\projects\\proje dosyalari\\kayit.txt","a");
		
    		printf("Kayit edilecek kisinin Kimlik numrasini giriniz\n");
    		scanf("%s",&s.kimlikNumarasi);
    
			printf("Kayit edilecek kisinin ismini giriniz\n");
			scanf("%s",&s.ad);

			printf("Kayit edilecek kisinin soyismini giriniz\n");
			scanf("%s",&s.soyad);
	
			printf("Kayit edilecek kisinin bolumunu giriniz\n");
			scanf("%s",&s.bolum);
		
  			printf("Kayit olusturuldu");
			
			fprintf(fgercek,"%s %s %s %s\n",s.kimlikNumarasi,s.ad,s.soyad,s.bolum);
			fclose(fgercek);
   			
			return 0;
   			 
    }


    else if(anaMenu==2){
    	
    	fgercek=fopen("C:\\projects\\proje dosyalari\\kayit.txt","r");
    	fsahte=fopen("C:\\projects\\proje dosyalari\\sahte.txt","w+");
    	
    	printf("Silmek istediginiz kisinin kimlik numarasini giriniz: \n");
    	scanf("%d",&silincekkisi);
   
		
		if(fgercek!=NULL && fsahte!=NULL)
		{
			while(fscanf(fgercek,"%s %s %s %s",s1.kimlikNumarasi,s1.ad,s1.soyad,s1.bolum)!=EOF){
			
				if(s1.kimlikNumarasi==silincekkisi){
					fprintf(fsahte, "%s %s %s %s\n",s1.kimlikNumarasi,s1.ad,s1.soyad,s1.bolum);
				}
				else{
					printf("Bu numaraya sahip birisi bulunamadi");
				}
			}
		}
    	
    
		
		fclose(fgercek);
		fclose(fsahte);
		
		remove("C:\\projects\\proje dosyalari\\kayit.txt");
		rename("C:\\projects\\proje dosyalari\\sahte.txt","C:\\projects\\proje dosyalari\\kayit.txt");
    }


	else if(anaMenu==3){
		fgercek=fopen("C:\\projects\\proje dosyalari\\kayit.txt","r");
		if(fgercek=NULL){
			printf("Kayitli kullanici bulunamadi");
		}
		else{
    	
    	fgercek=fopen("C:\\projects\\proje dosyalari\\kayit.txt","r");
    	
    	while(fscanf(fgercek,"%s %s %s %s",s.kimlikNumarasi,s.ad,s.soyad,s.bolum)!=EOF){
    		
			printf("KIMLIK NO:%s  ISIM:%s  SOYISIM:%s  BOLUM:%s\n",s.kimlikNumarasi,s.ad,s.soyad,s.bolum);
		}
	}
		fclose(fgercek);
	}

   		 else if(anaMenu==4){
   
   		int guncellemeno;
		fgercek=fopen("C:\\projects\\proje dosyalari\\kayit.txt","r");
		fsahte=fopen("C:\\projects\\proje dosyalari\\sahte.txt","w+");


    	printf("Guncellemek istediginiz kisinin kimlik numarasini giriniz:\n");
    	scanf("%d",&guncellemeno);
    	printf("Yeni adi  giriniz:\n");
    	scanf("%d",s1.ad);
    	printf("yeni soyadi giriniz:\n");
    	scanf("%d",s1.soyad);
        printf("yeni bolumu giriniz:\n");
    	scanf("%d",s1.bolum);
    	
        while(fscanf(fgercek,"%s %s %s %s",s.kimlikNumarasi,s.ad,s.soyad,s.bolum)!=EOF){  // dosya sonuna kadar okuyup kaydý buluyorum while ile

            if(s.kimlikNumarasi==guncellemeno){
                continue;                                            // kaydý bulduysa devam et
            }
  
            fprintf(fgercek,"%s %s %s %s \n",guncellemeno,s1.ad,s1.soyad,s1.bolum);
        	fprintf(fsahte,"%s %s %s %s  \n",guncellemeno,s.ad,s.soyad,s.bolum);
        }

        fclose(fgercek);
        fclose(fsahte);
        printf("\n Kayit guncellendi\n");
        remove("C:\\projects\\proje dosyalari\\kayit.txt");
        rename("C:\\projects\\proje dosyalari\\sahte.txt","C:\\projects\\proje dosyalari\\kayit.txt");
        
    }
    
    else{
        printf("Hatali tuslama yaptiniz");
        return 0;
    }



    return 0;
}

