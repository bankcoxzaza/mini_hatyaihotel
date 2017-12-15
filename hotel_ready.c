#include<stdio.h>
#include<string.h>
#include<time.h>


struct Hotel 
{
	char hotel_name[50];
	char location[100];

};

struct Hotel hotel[6]= 
{
{"PS Extra Hotel","144/22 Khongteay,Hatyai,90110"},
{"The Train Hotel Hatyai","Hatyai Railway Station,Hatyai Central,90110"},
{"TONAOI GRAND HOTEL","24 Klohongtoeipattana1,Hatyai,90110"},
{"Hatyai Signature Hotel","679 PetchakasemRoad,Hatyai,90110"},
{"S Hatyai Hotel","220 PrachathipRoad,Hatyai,90110"},
{"Buri Sriphu Hotel","310 SriphuwanartRoad,Hatyai,90110"}
};

struct Type1
{
	char t_room1[20];
	float price1;

};

struct Type1 type1[6] = {{"Double Bed",381},{"Mixed Dormitory",260},{"Corrner Deluxe",1102},{"Deluxe King Bed",1347},{"Junior Suite",1508},{"Deluxe Room",1988}};

struct Type2
{
	char t_room2[20];
	float price2;
};

struct Type2 type2[6] = {{"Twin Bed",750},{"Superior Balcony",770},{"Junior Deluxe",1453},{"Deluxe Twin Bed",1402},{"Junior Suite A",1929},{"Honeymoon Suite",3533}};

// Function //
void Showdetail1();
void Showdetail2();
void Showdetail3();
//void roomdetails();


int main()
{
		
	int i;
	
	int per_nigh,in_d,in_m,out_d,out_m;;
	
	int check;
	
	int ch_type,ch_hotel;

	int c_room,c_adult,c_child,guest;
	char type_room[30],hotel1[10],location1[50];
	float price,sum,total,total1,money;

	char show_Dt;
	char name[50],last[50],email[50],tel[20];
	char id[50];
	
	int choice;
	
//randomecode
	srand(time(NULL));
	int randomNumber = rand()%100000;
	int randomPin = rand()%10000;

//file open
	

	FILE *fptrp;
	
	loop3:

	fptrp = fopen("hatyaihotel.csv","a+");
	if(fptrp == NULL)
	{
		printf("Can not open hatyaiotel.csv");
	}
	else
	{
		
	printf("\n 		      FIND HOTELS IN HADYAI 2018 \n\n");
	
	printf(" 			  PRICE PER NIGH ? \n\n");
	
	printf(" || [1.] THB 300-900 || [2.] THB 900-1500 || [3.] THB 1500-5000 || \n\n");

	
	do
	{
		printf("  ANS : ");
		scanf("%d",&per_nigh);
		
	}while(per_nigh < 1 || per_nigh > 3);
	
	printf("\n  CHECK THE DAY IN 2018 \n\n");
	
///Check In
		printf("  CHECK IN\n");
		
		loop1:
			
		printf("  Month : ");
		scanf("%d",&in_m);
		
			//month 31 day
			if(in_m==1 || in_m==3 || in_m==5 || in_m==7 || in_m==8 || in_m==10 || in_m==12 )
			{
				do
				{
					printf("  Date  : ");
					scanf("%d",&in_d);	
				}while(in_d < 1 || in_d > 31);
			}
			//month 30 day
			else if(in_m==4 || in_m==6 || in_m==9 || in_m==11 )
			{
				do
				{
					printf("  Date  : ");
					scanf("%d",&in_d);
				}while(in_d < 1 || in_d > 30);
			}
			//month 28 day
			else if(in_m==2)
			{
				do
				{
					printf("  Date  : ");
					scanf("%d",&in_d);
				}while(in_d < 1 || in_d > 28);
			}
			else
			{
				goto loop1;
			}
//Check Out
		printf("\n  CHECK OUT\n");
		loop2:
			do
			{
				printf("  Month : ");
				scanf("%d",&out_m);
			}while(out_m!=in_m);
			
			do
			{
			
				if(out_m==1 || out_m==3 || out_m==5 || out_m==7 || out_m==8 || out_m==10 || out_m==12 )
				{
				
					do
					{
						printf("  Date  : ");
						scanf("%d",&out_d);	
					}while(out_d < 1 || out_d > 31);			
				}
				else if(out_m==4 || out_m==6 || out_m==9 || out_m==11 )
				{
					do
					{
						printf("  Date  : ");
						scanf("%d",&out_d);			
					}while(out_d < 1 || out_d > 30);
				}
				else if(out_m==2)
				{
					do
					{
						printf("  Date  : ");
						scanf("%d",&out_d);
					}while(out_d < 1 || out_d > 28);
				}
				else
				{
					goto loop2;
				}
			
			}while(out_d<=in_d);
			
	check=out_d-in_d;
	
	printf("\n  Room Details\n");
	do
	{
		printf("  Rooms    : ");
		scanf("%d",&c_room);
	}while(c_room < 1 || c_room > 9);

	do
	{
		printf("  Adults   : ");
		scanf("%d",&c_adult);
		printf("  Children : ");
		scanf("%d",&c_child);
	}while(c_adult < c_room);
		
	printf("\n       ------------\n");
	printf("      |   SEARCH   |\n");
	printf("       ------------\n");
	getch();
	system("cls");
	
	
	if(per_nigh == 1)
	{		
		for(i=0;i<2;i++)
		{
			printf("\n  [%d] %s \n",i+1,hotel[i].hotel_name);
			printf("  == Room  > [1] %s THB %.2f \n",type1[i].t_room1,type1[i].price1); 
			printf(" 	   > [2] %s THB %.2f \n",type2[i].t_room2,type2[i].price2);
			printf("  Location : %s \n\n",hotel[i].location);
	
// Ask show detail
			do
			{
				printf("  Show Details ? (Y/N) : ");
				scanf("%c",&show_Dt);
				scanf("%c",&show_Dt);
			}while(show_Dt != 'Y' && show_Dt != 'y' && show_Dt != 'N' && show_Dt != 'n');
				
			if(show_Dt == 'Y' || show_Dt == 'y')
			{
				Showdetail1();		
			}
			printf("----------------------------------------------\n");
		}
			do
			{	
				printf("\n  Please Select A Hotel   : ");
				scanf("%d",&ch_hotel);
			}while(ch_hotel < 1 || ch_hotel > 2);
			
			do
			{
				printf("  Please Select Type Room : ");
				scanf("%d",&ch_type);
			}while(ch_type < 1 || ch_type > 2);
			
	}else if(per_nigh == 2)
	{
		for(i=2;i<4;i++)	
		{	
			printf("\n  [%d] %s \n",i+1,hotel[i].hotel_name);
			printf("  == Room  > [1] %s THB %.2f \n",type1[i].t_room1,type1[i].price1); 
			printf(" 	   > [2] %s THB %.2f \n",type2[i].t_room2,type2[i].price2);
			printf("  Location : %s \n\n",hotel[i].location);
// Ask show detail	
			do
			{
				printf("  Show Details ? (Y/N) : ");
				scanf("%c",&show_Dt);
				scanf("%c",&show_Dt);
			}while(show_Dt != 'Y' && show_Dt != 'y' && show_Dt != 'N' && show_Dt != 'n');
				
			if(show_Dt == 'Y' || show_Dt == 'y')
			{
				Showdetail2();										
			}
		}
			
			do
			{	
				printf("\n  Please Select A Hotel   : ");
				scanf("%d",&ch_hotel);
			}while(ch_hotel < 3 || ch_hotel > 4);
			
			do
			{
				printf("  Please Select Type Room : ");
				scanf("%d",&ch_type);
			}while(ch_type < 1 || ch_type > 2);
			
	}else if(per_nigh == 3)
	{

		for(i=4;i<6;i++)
		{			
			printf("\n  [%d] %s \n",i+1,hotel[i].hotel_name);
			printf("  == Room  > [1] %s THB %.2f \n",type1[i].t_room1,type1[i].price1); 
			printf(" 	   > [2] %s THB %.2f \n",type2[i].t_room2,type2[i].price2);
			printf("  Location : %s \n\n",hotel[i].location);
// Ask show detail 
			do
			{
				printf("  Show Details ? (Y/N) : ");
				scanf("%c",&show_Dt);
				scanf("%c",&show_Dt);
			}while(show_Dt != 'Y' && show_Dt != 'y' && show_Dt != 'N' && show_Dt != 'n');
							
			if(show_Dt == 'Y' || show_Dt == 'y')
			{
				Showdetail3();	
			}
		}
			do
			{	
				printf("\n  Please Select A Hotel   : ");
				scanf("%d",&ch_hotel);
			}while(ch_hotel < 5 || ch_hotel > 6);
			
			do
			{
				printf("  Please Select Type Room : ");
				scanf("%d",&ch_type);
			}while(ch_type < 1 || ch_type > 2);
	}


	printf("\n       ------------\n");
	printf("      |   CONNECT   |\n");
	printf("       ------------\n");
	getch();
	system("cls");

	printf("\n		   BOOK NOW \n");
	printf(" 		BOOKING DETAILS\n\n");
	strcpy(hotel1,hotel[ch_hotel-1].hotel_name);
	printf("  HOTEL     : %s \n",hotel1);	
	
	if(ch_type == 1)
	{
		printf("  TYPE ROOM : %s",type1[ch_hotel-1].t_room1);
		strcpy(type_room,type1[ch_hotel-1].t_room1);
		price = type1[ch_hotel-1].price1;
		printf("\n  PRICE     : THB %.2f",price );
	}else
	{
		printf("  TYPE ROOM : %s",type2[ch_hotel-1].t_room2);
		strcpy(type_room,type2[ch_hotel-1].t_room2);
		price = type2[ch_hotel-1].price2;
		printf("\n  PRICE     : THB %.2f",price );
	}
	strcpy(location1,hotel[ch_hotel-1].location);
	printf("\n  LOCATION  : %s\n",location1);
	printf("  CHECK IN  : %d / %d / 2018 \n",in_d,in_m);
	printf("  CHECK OUT : %d / %d / 2018 \n",out_d,out_m);
	printf("\n          STAY\n");
	printf("  NIGHT     : %d\n",check);
	printf("  ROOM      : %d\n",c_room);
	printf("  ADULTS    : %d\n",c_adult);
	printf("  CHILDREN  : %d\n",c_child);
	printf("\n----------------------------------------------\n");	

	printf("\n 		YOUR INFORMATION\n\n");
	printf("  NAME        : ");
	scanf("%s",&name);
	printf("  LAST        : ");
	scanf("%s",&last);
	printf("  ID Passport : ");
	scanf("%s",&id);
	printf("  E-MAIL      : ");
	scanf("%s",&email);
	printf("  TEL.        : ");
	scanf("%s",&tel);
	printf("\n----------------------------------------------\n");
	
	///////////////////////////////////////////////////////////////////////////////
	printf("\n           YOUR ROOM DETAILS \n\n");
	printf("    ROOM : %d x %s \n",check,type_room);
	printf("    INFORMATION CUSTUMER : %d Adults\n			   %d Children\n",c_adult,c_child);
	
	sum=(price*(c_room*check));
	
	printf("    PRICE PER ROOM       : THB %.2f\n",price);
	printf("    TOTAL                : THB %.2f\n",sum);
	
	printf("\n           INCLUDED IN PRICE \n");
	
	total1=((sum*0.07)+sum);
	total=((total1*0.10)+total1);
	
	printf("    + VAT 7%%             : %.2f THB\n",sum*0.07);
	printf("    + SERVICE CHARGE 10%% : %.2f THB\n",total1*0.10);
	printf("    TOTAL PAYABLE        : %.2f THB\n",total);
	
//	printf("Smart choicel you saved %.2f THB \n\n");
    printf("\n----------------------------------------------\n");

	printf("\n 	BOOK NOW & PAY NOW !! \n\n");
	
//	printf(" 	   PLEASE PAY NOW !!!  \n\n");
	printf("    TOTAL : THB %.2f \n\n\n",total);
	
	
	printf("       YOU CAN PAY MENT BY \n\n");
	printf("    - Credit Card \n");
	printf("    - Internet Banking \n");
	printf("    - Lnstallment \n");
	printf("    - Counter Service And Other \n");

	printf("\n    ! ! !   T H A N K   Y O U   ! ! ! \n");
	
	printf("\n       ------------\n");
	printf("      |   CONFIAM  |\n");
	printf("       ------------\n");
	getch();
	system("cls");
	
	loop4:
	printf("\n		BOOKING CONFIRMATION\n\n");
	printf("    HOTEL           : %s\n",hotel1);
	printf("    CHECK IN        : %d/%d/2018\n",in_d,in_m);
	printf("    CHECK OUT       : %d/%d/2018\n",out_d,out_m);
	
	printf("\n    Deal\n");
	printf("    Type Room       : %s \n",type_room);
	printf("    Room details    : %d Rooms\n",c_room);
	printf("                      %d Adults\n",c_adult);
	printf("                      %d Children\n",c_child);	
	printf("    Price           : %.2f \n\n",sum);
	
	printf("    Custumer information\n");
	printf("    NAME            : %s  %s\n",name,last);
	printf("    ID Passport     : %s\n",id);
	printf("    E-MAIL          : %s\n",email);
	printf("    Mobile          : %s\n",tel);
		
	printf("\n    Rate details \n");
	printf("    Total PAYABLE   : %.2f  THB \n",total);
		
	printf("\n    Payment information \n");
	printf("    Bill No.        : 2018%d\n",randomNumber);
	printf("    PIN Code        : %d\n",randomPin);
	printf("    Date       ");
	

	
	//file white
	fprintf(fptrp,"%s %s,%s,%s,Room x %d,Adults x %d,Children x %d,%s,%s,0%s,%d/%d/2018,%d/%d/2018,2018%d,%d,%.2f\n"
	,name,last,hotel1,type_room,c_room,c_adult,c_child,id,email,tel,in_d,in_m,out_d,out_m,randomNumber,randomPin,total);
	fclose(fptrp);
		
	printf("\nAppend complete !!!");
	
	printf("\n           Booking Choice\n");
	printf("     [1.] Booking details  [2.] Back to main [Other.] Exit\n");
	printf("Choice : ");
	scanf("%d",&choice);
//	system("cls");
	
	switch(choice)
	{
		case 1:
			goto loop4;
			break;
		case 2:
			goto loop3;
			break;
		default:
			break;
	}
	
			
				
	return 0;
	}
}

void Showdetail1(){
		printf(" \n 	 - DETAILS -\n");
		printf("  - Features you'll love \n");
		printf("   > Free Wi-fi in all Rooms. \n");
		printf("   > Blackout curtains. \n");
		printf("   > Car park.\n");
		printf("   > Fan.\n");
				
		printf("  - Some helpful facts \n");
		printf("   Check in\n");
		printf("   > Check in from  : 11.00 A.M.\n");
		printf("   > Check in until : 12.00 P.M.\n");
		printf("   Check out\n");
		printf("   > Check out from  : 10.00 A.M.\n");
		printf("   > Check out until : 12.00 A.M.\n\n");
}

void Showdetail2(){
		printf(" \n 	 - DETAILS -\n");
		printf("  - Features you'll love \n");
		printf("   > Free Wi-fi in all Rooms. \n");
		printf("   > Blackout curtains. \n");
		printf("   > Car park.\n");
		printf("   > Air conditioner.\n");
		printf("   > Breakfast.\n");
		printf("   > Meeting and Banquet Facilities.\n");
				
		printf("  - Some helpful facts \n");
		printf("   Check in\n");
		printf("   > Check in from  : 10.00 A.M.\n");
		printf("   > Check in until : 12.00 P.M.\n");
		printf("   Check out\n");
		printf("   > Check out from  : 09.00 A.M.\n");
		printf("   > Check out until : 12.00 A.M.\n\n");
}

void Showdetail3(){
		printf(" \n 	 - DETAILS -\n");
		printf("  - Features you'll love\n");
		printf("   > Free Wi-fi in all Rooms.\n");
		printf("   > Blackout curtains.\n");
		printf("   > Car park.\n");
		printf("   > Fitness.\n");
		printf("   > Air conditioner.\n");
		printf("   > Breakfast.\n");
		printf("   > Swimming Pool.\n");
		printf("   > Bar.\n");
		printf("   > Meeting and Banquet Facilities.\n");
				
		printf("  - Some helpful facts \n");
		printf("   Check in\n");
		printf("   > Check in from  : 10.00 A.M.\n");
		printf("   > Check in until : 12.00 P.M.\n");
		printf("   Check out\n");
		printf("   > Check out from  : 09.00 A.M.\n");
		printf("   > Check out until : 12.00 A.M.\n\n");
}





