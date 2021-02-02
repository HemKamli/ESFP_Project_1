#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
struct book
{
	char BA[30];
	int BI, BPY;
} B;

struct issue
{
	int cllgid, couid, Bid,BPY;
	int D;
	int M;
	int Y;
	char sname[25], sadd[35],BA[30];
	char date[20];
	char scont[9];
} I;

struct submit
{
	int fine;
	int cllgid, couid, Bid,BPY;
	int D;
	int M;
	int Y;
	char sname[20], sadd[35],BA[30];
	char date[20];
	char Idate[20];
	char scont[9];
	

} S;

int leapornot(int);
void f_addbook();
void f_deletebook();
void f_viewbook();
void f_issuebook();
void f_viewIbook();
void f_submitbook();
void f_Day();

FILE *fp, *fs, *fss;
int main()
{
	int choice,i;
	while (1)
	{

		system("cls");
		printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 MAIN  MENU \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n\t\t");
		for(i=1;i<=30;i++)
		{
			printf("\xc4");
		}
		printf("\n\t\t\xB2\xB2\xB1 1>Add Books");
		printf("\n\n\t\t\xB2\xB2\xB1 2>Delete Book");
		printf("\n\n\t\t\xB2\xB2\xB1 3>Issue Book");
		printf("\n\n\t\t\xB2\xB2\xB1 4>Submit Book");
		printf("\n\n\t\t\xB2\xB2\xB1 5>Book Records");
		printf("\n\n\t\t\xB2\xB2\xB1 6>Issue/Submit Records\n\t\t");

		for(i=1;i<=30;i++)
		{
			printf("\xC4");
		}
		printf("\n\n\t\tEnter Your Choice or press 0 to exit ==>> ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			system("cls");
			exit(0);

		case 1:
			system("cls");
			f_addbook();
			break;

		case 2:
			system("cls");
			f_deletebook();
			break;

		case 3:
			system("cls");
			f_issuebook();
			break;

		case 4:
			system("cls");
			f_submitbook();
			break;

		case 5:
			system("cls");
			f_viewbook();
			break;
		case 6:
			system("cls");
			f_viewIbook();
			break;

		default:
			system("cls");
			printf("Wrong Choice....!");
			break;
		}
		getch();
	}
	return 0;
}

void f_addbook()
{	
	int i;
	printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 ADD BOOK \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n\t\t");
	for(i=1;i<=30;i++)
		{
			printf("\xC4");
		}
	fp = fopen("Book.txt", "ab");
	printf("\n\t\tEnter Book Id: ");
	scanf("%d", &B.BI);
	printf("\n\t\tEnter Author Name: ");
	fflush(stdin);
	gets(B.BA);
	printf("\n\t\tEnter Book Publised Year: ");
	scanf("%d", &B.BPY);
	printf("\t\t");
	for(i=1;i<=30;i++)
		{
			printf("\xC4");
		}

	fwrite(&B, sizeof(B), 1, fp);
	printf("\n\t\tRecord saved successfully.....!");
	fclose(fp);
}

void f_deletebook()
{
	int i,id,f=0;
	printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 DELETE BOOK \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n\t\t");
	for(i=1;i<=33;i++)
		{
			printf("\xC4");
		}
	fp = fopen("Book.txt", "rb");
	printf("\n\t\tEnter Book Id: ");
	scanf("%d", &id);
	FILE *FBT;
	FBT = fopen("T.txt","ab");
	while (fread(&B, sizeof(B), 1, fp) == 1)
	{
		if(B.BI == id)
		{
			f=1;
		}
		else
		{
			fwrite(&B, sizeof(B), 1, FBT);
		}
	}
	fclose(fp);
	fclose(FBT);
	remove("Book.txt");
	rename("T.txt", "Book.txt");
	printf("\t\t");
	for(i=1;i<=33;i++)
		{
			printf("\xC4");
		}
		
	if(f==0)
	{
		printf("\n\t\tRecord not found...!");
	}
	else
	{
		printf("\n\t\tRecord Deleted Successfully...");
	}
	
	
}

void f_viewbook()
{
	int i;
	printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 BOOK RECORD \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n");
	for(i=1;i<=70;i++)
		{
			printf("\xC4");
		}
	printf("\n%-20s\xB3 %-30s\xB3 %s\n", "Book_Id", "Author", "Publish_Year");
	for(i=1;i<=70;i++)
		{
			printf("\xC4");
		}
	fp = fopen("Book.txt", "rb");
	while (fread(&B, sizeof(B), 1, fp) == 1)
	{
		printf("\n%-20d\xB3 %-30s\xB3 %d", B.BI, B.BA, B.BPY);
	}
	fclose(fp);
	printf("\n");
	for(i=1;i<=70;i++)
		{
			printf("\xC4");
		}
	printf("\nPress Any Key to countinue....");
}

void f_issuebook()
{
	int id, f = 0;
	int i;
	printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 ISSUE BOOK \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n\t\t");
	for(i=1;i<=32;i++)
		{
			printf("\xC4");
		}
	SYSTEMTIME date;
	GetSystemTime(&date);
	sprintf(I.date, "%d / %d / %d", date.wDay, date.wMonth, date.wYear);
	I.D = date.wDay;
	I.M = date.wMonth;
	I.Y = date.wYear;
	fs = fopen("Issue.txt", "ab");
	printf("\n\t\tEnter Student Name: ");
	fflush(stdin);
	gets(I.sname);
	printf("\n\t\tEnter Student address: ");
	fflush(stdin);
	gets(I.sadd);
	printf("\n\t\tEnter Course ID: ");
	scanf("%d", &I.couid);
	printf("\n\t\tEnter College ID: ");
	scanf("%d", &I.cllgid);
	printf("\n\t\tEnter Student Contact NO:");
	fflush(stdin);
	gets(I.scont);
	printf("\n\t\tEnter Book ID: ");
	scanf("%d", &id);
	printf("\n\t\t");
	for(i=1;i<=32;i++)
		{
			printf("\xC4");
		}

	fp = fopen("Book.txt", "rb");
	while (fread(&B, sizeof(B), 1, fp) == 1)
	{
		if (id == B.BI)
		{
			f = 1;
			I.Bid = B.BI;
			strcpy(I.BA,B.BA);
			I.BPY = B.BPY;
			fwrite(&I, sizeof(I), 1, fs);
		}
	}
	fclose(fp);
	fclose(fs);
	if (f == 0)
	{
		printf("\n\t\tPlease Enter Correct Book ID....!");
	}
	else
	{
		printf("\n\t\tRecord saved successfully...");
	}
}

void f_viewIbook()
{
int i;
	printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 ISSUE/SUBMIT \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n\n");
	for(i=1;i<=168;i++)
		{
			printf("\xC4");
		}
	printf("%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%-15s\xB3%s\n", "Student_Name", "College_ID", "Course_ID", "Student_Contact", "Student_Address", "Book_ID","Author","Publish_Year","Issue_Date", "Submit_Date", "Fine");
	for(i=1;i<=168;i++)
		{
			printf("\xC4");
		}
	fss = fopen("Submit.txt", "rb");
	while (fread(&S, sizeof(S), 1, fss) == 1)
	{
		printf("%-15s\xB3%-15d\xB3%-15d\xB3%-15s\xB3%-15s\xB3%-15d\xB3%-15s\xB3%-15d\xB3%-15s\xB3%-15s\xB3%d\n", S.sname, S.cllgid, S.couid, S.scont, S.sadd, S.Bid, S.BA, S.BPY, S.Idate, S.date, S.fine);
	}
	fclose(fss);
	fs = fopen("Issue.txt", "rb");
	while (fread(&I, sizeof(I), 1, fs) == 1)
	{
		printf("%-15s\xB3%-15d\xB3%-15d\xB3%-15s\xB3%-15s\xB3%-15d\xB3%-15s\xB3%-15d\xB3%s\n", I.sname, I.cllgid, I.couid, I.scont, I.sadd, I.Bid, I.BA, I.BPY, I.date);
	}
	fclose(fs);
	for(i=1;i<=168;i++)
		{
			printf("\xC4");
		}

	printf("\n\nPress Any Key to countinue....");
}

void f_submitbook()
{
	int f = 0;
	int i;
	printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3 ISSUE BOOK \xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t\n\t\t");
	for(i=1;i<=33;i++)
		{
			printf("\xC4");
		}
	SYSTEMTIME date;
	GetSystemTime(&date);
	sprintf(S.date, "%d / %d / %d", date.wDay, date.wMonth, date.wYear);
	S.D = date.wDay;
	S.M = date.wMonth;
	S.Y = date.wYear;

	printf("\nEnter College ID: ");
	scanf("%d", &S.cllgid);
	FILE *ft;
	ft = fopen("temp.txt", "ab");
	fs = fopen("Issue.txt", "rb");
	while (fread(&I, sizeof(I), 1, fs) == 1)
	{
		if (I.cllgid == S.cllgid)
		{
			f = 1;
			S.Bid = I.Bid;
			S.couid = I.couid;
			S.BPY = I.BPY;
			strcpy(S.sadd, I.sadd);
			strcpy(S.scont, I.scont);
			strcpy(S.sname, I.sname);
			strcpy(S.Idate, I.date);
			strcpy(S.BA,I.BA);
			f_Day();
		}
		else
		{
			fwrite(&I, sizeof(I), 1, ft);
		}
	}
	fclose(fs);
	fclose(ft);
	remove("Issue.txt");
	rename("temp.txt", "Issue.txt");
	printf("\n\t\t");
	for(i=1;i<=33;i++)
		{
			printf("\xC4");
		}
	if (f == 0)
	{
		printf("\n\t\tSorry,Issue Record Not Found....!");
	}
	else
	{
		printf("\n\t\tRecord Saved Succesfully.....!");
	}
}

void f_Day()
{
	int day_diff = 0;
	int Extra_day = 0;
	int D,M,Y;

	int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;

	if (S.Y > I.Y)
	{
		if (I.M == 2)
		{
			if (leapornot(I.Y) == 1)
			{
				day_diff += 29 - I.D;
			}
			else
			{
				day_diff += 28 - I.D;
			}
		}
		else
		{
			day_diff = day[I.M - 1] - I.D;
		}
		I.M++;

		for (i = I.M; i <= 12; i++)
		{
			if (i == 2)
			{
				if (leapornot(I.Y) == 1)
				{
					day_diff += 29;
				}
				else
				{
					day_diff += 28;
				}
			}
			else
			{
				day_diff += day[i - 1];
			}
		}
		I.Y++;

		for (i = I.Y; i < S.Y; i++)
		{
			if (leapornot(i) == 1)
			{
				day_diff += 366;
			}
			else
			{
				day_diff += 365;
			}
		}

		for (i = 1; i < S.M; i++)
		{
			if (i == 2)
			{
				if (leapornot(S.Y) == 1)
				{
					day_diff += 29;
				}
				else
				{
					day_diff += 28;
				}
			}
			else
			{
				day_diff += day[i - 1];
			}
		}

		day_diff += S.D;
	}
	else if (I.Y == S.Y)
	{
		if (S.M > I.M)
		{
			if (I.M == 2)
			{
				if (leapornot(I.Y) == 1)
				{
					day_diff += 29 - I.D;
				}
				else
				{
					day_diff += 28 - I.D;
				}
			}
			else
			{
				day_diff = day[I.M - 1] - I.D;
			}
			I.M++;
			for (i = I.M; i < S.M; i++)
			{
				if (i == 2)
				{
					if (leapornot(I.Y) == 1)
					{
						day_diff += 29;
					}
					else
					{
						day_diff += 28;
					}
				}
				else
				{
					day_diff += day[i - 1];
				}
			}

			day_diff += S.D;
		}
		else if (I.M == S.M)
		{
			if (S.D > I.D)
			{
				day_diff = S.D - I.D;
			}
			else if (I.D == S.D)
			{
				day_diff = 0;
			}
		}
	}
	if(day_diff <= 30)
	{
		S.fine = 0;
	}
	else
	{
		Extra_day = day_diff - 30;
		S.fine = Extra_day *5;
	}
	fss = fopen("submit.txt", "ab");
	fwrite(&S, sizeof(S), 1, fss);
	fclose(fss);
}

int leapornot(int y)
{
	if (y % 400 == 0)
	{
		return 1;
	}
	else
	{
		if (y % 100 == 0)
		{
			return 0;
		}
		else if (y % 4 == 0)
		{
			return 1;
		}
		else
			return 0;
	}
}
