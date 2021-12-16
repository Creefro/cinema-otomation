#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void filmler();
void klt(int g,char hhhh[],int boyut);
typedef struct {
    char red[5][50];
    char green[5][50];
    char blue[5][50];

}kol;
struct  {
    int matine;
    char film[20];
    char salon[10];
}rez;

int main(){
    char secim;
    system("cls");
    printf("Kayit icin '1'\nGiris yapmak icin '2' tuslayin. ");
    secim= getchar();
    switch (secim){
    case '1':
        kayit();
        break;
    case '2':
        giris();
        break;
    default:
        printf("Hatali secim. Lutfen tekrar deneyin\n");
        getch();
        main();
        system("cls");
        break;
    }

    return 0;
}
void kayit(){
    system("cls");
    filmler();
    char sifre[10];
    FILE *ptr;
    ptr = fopen ("sifre.txt","w");
    printf("Lutfen sifrenizi belirleyin:");
    scanf("%s",&sifre);
    fprintf(ptr,"%s",sifre);
    fclose(ptr);
    printf("\nKayit basariyla tamamlanmistir. Devam etmek icin bir tusa basin.\a");
    getch();
    main();
}
void giris(){
    system("cls");
    char sifre[10];
    char sifreKontrol[10];
    int kontrol;
    FILE *ptr;
    ptr = fopen ("sifre.txt","r");
    printf("Lutfen sifrenizi girin: ");
    scanf("%s", &sifre);
    if(ptr == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}
    while(fscanf(ptr," %s",&sifreKontrol)!=EOF){
        if (strcmp(sifre,sifreKontrol)==0){
            printf("\nGiris basarili. Ana Menuye gitmek icin bir tusa basin.\a");
            getch();
            menu();
        }
        else{
                hata:
            printf("\nHatali giris! Tekrar denemek icin 1, cikis yapmak icin 0 tuslayin.\a");
            scanf("%d",&kontrol);
            if (kontrol==1){
                giris();
            }
            else if (kontrol==0){
                cikis();
            }
            else{
                goto hata;
            }
        }

    }
}
void cikis(){
    system("cls");
    printf("Guney Kaya 202802042 Yazilim Muhendisligi");
}
void menu(){
    system("cls");
    char a;

    printf("\t\t\tHOSGELDINIZ!\n");
    printf("\t\t\t1.Vizyondaki Filmler\n");
    printf("\t\t\t2.Bilet Al\n");
    printf("\t\t\t3.Hasilat Bilgisi\n");
    printf("\t\t\t4.Cikis\n");
    kontrol1:
    scanf(" %c",&a);

    switch (a){
    case '1':
        vizyon();
        break;
    case '2':
        bilet();
        break;
    case '3':
        hasilat();
        break;
    case '4':
        cikis();
        break;
    default:
        printf("\n\t\t\tHatali giris yaptiniz. Lutfen tekrar deneyin.\a");
        getch();
        goto kontrol1;
        break;
    }
}
void filmler() {
    FILE *p,*red,*green,*blue;
    int i,j;
    p= fopen("film.txt","w");
    red=fopen("red.txt","w+");
    green=fopen("green.txt","w+");
    blue=fopen("blue.txt","w+");
    if(red == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}
	if(green == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}
	if(blue == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}
    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            fputc('0',red);
        }

    }
    fclose(red);
    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            fputc('0',green);
        }

    }
    fclose(green);
    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            fputc('0',blue);
        }

    }
    fclose(blue);
    if(p == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}

    fprintf(p,"%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s\n%s %d %s"
            ,"film1",1,"red"
            ,"film2",1,"green"
            ,"film3",1,"blue"
            ,"film4",2,"red"
            ,"film5",2,"green"
            ,"film6",2,"blue"
            ,"film7",3,"red"
            ,"film1",3,"green"
            ,"film2",3,"blue"
            ,"film3",4,"red"
            ,"film4",4,"green"
            ,"film5",4,"blue"
            ,"film6",5,"red"
            ,"film7",5,"green"
            ,"film1",5,"blue"
            );
    fclose(p);
}
void vizyon() {
    system("cls");
    char ch;
    FILE *ptr;
    ptr = fopen("film.txt","r");

if(ptr == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}
	printf("Film  M Salon\n\n");
    while( ( ch = fgetc(ptr) ) != EOF ){
      		printf("%c",ch);}
    fclose(ptr);
    printf("\nGeri donmek icin bir tusa basin. \a");
    getch();
    menu();
}
void bilet (){
    FILE *p,*pp;
    p = fopen("film.txt","r");
    pp = fopen ("log.txt","a");
    char filmsec[20];
    int seans,koltuk;
    int n,asd;
    int hasilat;
    char salon[10];
    system("cls");
    don:
    printf("\nBilet almak istediginiz filmi secin: ");
    scanf("%s",&filmsec);
    printf("\nKac numarali seans: ");
    scanf("%d",&seans);
    while (fscanf(p,"%s %d %s\n",&rez.film,&rez.matine,&rez.salon)!= EOF){
        if ((strcmp(rez.film,filmsec)==0)&&(seans == rez.matine)){
                printf("\n%d. matinede \n%s salonunda \n%s filmi\a",rez.matine,rez.salon,rez.film);
                strcpy(salon,rez.salon);
        }
        /*else{
            printf("Film ve seans bilgileri yanlistir. Lutfen tekrar deneyin. ");
            getch();
            goto don;
        }*/
    }

    printf("\nTam mi ogrenci mi?: 1/2\n");
    scanf("%d",&asd);
    if (asd==1){
        hasilat=30;
    }
    else {
        hasilat=20;
    }
    fprintf(pp,"%s %d %s %d %d\n",filmsec,seans,salon,hasilat,1);
    klt(seans,salon,10);
    fclose(p);
    fclose(pp);
    printf("\nMenuye donmek icin bir tusa basin.");
    getch();
    menu();
}
void klt(int g,char hhhh[],int boyut){
    kol Koltuk;
    kol *pk;
    pk=&Koltuk;
    int i,j,k,kltk;
    FILE *red,*green,*blue;
    if (strcmp(hhhh,"red")==0){
    red=fopen("red.txt","r");
    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            (*pk).red[i][j] = getc(red) ;
        }

    }
    for(j=0;j<50;j++)
    {
        if((*pk).red[g-1][j] == '0')
        {
            (*pk).red[g-1][j] = 1;
            kltk=j+1;
            break;
        }
        else
            continue;

    }
    red=fopen("red.txt","w+");
    for(i=0;i<5;i++)
    {
        for(k=0;k<50;k++)
        {
            if((*pk).red[i][k] == '0')
            fputc('0',red);
        else
            fputc('1',red);
        }

    }
    fclose(red);
    fclose(red);
    }
    if (strcmp(hhhh,"green")==0){
    green=fopen("green.txt","r");
    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            (*pk).green[i][j] = getc(green) ;
        }

    }
    for(j=0;j<50;j++)
    {
        if((*pk).green[g-1][j] == '0')
        {
            (*pk).green[g-1][j] = 1;
            kltk=j+1;
            break;
        }
        else
            continue;

    }
    green=fopen("green.txt","w+");
    for(i=0;i<5;i++)
    {
        for(k=0;k<50;k++)
        {
            if((*pk).green[i][k] == '0')
            fputc('0',green);
        else
            fputc('1',green);
        }

    }
    fclose(green);
    fclose(green);
    }
    if (strcmp(hhhh,"blue")==0){
    blue=fopen("blue.txt","r");
    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            (*pk).blue[i][j] = getc(blue) ;
        }

    }
    for(j=0;j<50;j++)
    {
        if((*pk).blue[g-1][j] == '0')
        {
            (*pk).blue[g-1][j] = 1;
            kltk=j+1;
            break;
        }
        else
            continue;

    }
    blue=fopen("blue.txt","w+");
    for(i=0;i<5;i++)
    {
        for(k=0;k<50;k++)
        {
            if((*pk).blue[i][k] == '0')
            fputc('0',blue);
        else
            fputc('1',blue);
        }

    }
    fclose(blue);
    fclose(blue);
    }
    printf("\n%d numarali koltuk",kltk);
    return kltk;
}
void hasilat (){
    system("cls");
    FILE *qq;
    qq=fopen("log.txt","r");
    int hasilat,t;
    char ch;
    int k=0,l=0;
    if(qq == NULL)
	{
		printf("Dosya acilamadi!\a");
		exit(1);

	}
	printf("Film  M Salon\n");

    while (fscanf(qq,"%s %d %s %d %d\n",&rez.film,&rez.matine,&rez.salon,&hasilat,&t)!=EOF){
            k += hasilat;
            l += t;

            printf("%s %d %s %d\n",rez.film,rez.matine,rez.salon,hasilat);
    }
    printf("\nToplam Hasilat: %d TL", k);
    printf("\nToplam Koltuk: %d",l);
    getch();
    menu();
    fclose(qq);
}
