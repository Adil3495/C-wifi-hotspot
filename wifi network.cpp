#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<direct.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
string ssid,key;

int  main()
{
	time_t t;
    time(&t);
	
	
	
	int n;
	char ch='y';
	ofstream ofil,obat;

do
{
	cout<<"*******************************************************************************"<<endl;
		cout<<"\t\t\tWifi Hostspot\n1)Setup Hosted Network\n2)Start Hosted Network\n3)Stop Hosted Network\n4)Show Hosted Network\n5)Reset Password (Default \"password\")\n6)Log File\n7)License\n8)Exit\nSelect an option : ";
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"\nEnter SSID Name(Hotspot Name) : ";
			cin>>ssid;
			
			cout<<"\nEnter Password : ";
			cin>>key;
			
			mkdir("c:/Hotspot");
			system("attrib +h c:/Hotspot");
			ofil.open("c:/Hotspot/wifi.bat");
			if(ofil.fail())
			{
				cout<<"\nError: Setup file cannot create";
				break;
			}
			else
			{
			ofil<<"@echo off"<<endl<<"netsh wlan set hostednetwork ssid=\""<<ssid<<"\" key=\""<<key<<"\" mode=allow";
			ofil.close();
			cout<<"\n";
			system("c:/Hotspot/wifi.bat");
			break;
		}
		case 2:
			cout<<"\n";
			system("netsh wlan start hostednetwork");
			break;
		case 3:
			cout<<"\n";
			system("netsh wlan stop hostednetwork");
			break;
		case 4:
			system("netsh wlan show hostednetwork");
		//	system("@echo off");
		//	system("pause");
			break;
		case 5:
		//	cout<<"\nEnter new password : ";
		//	cin>>key;
			
		//	obat.open("c:/Hotspot/wifipass.bat");
			
		//	obat<<"@echo off"<<endl<<"netsh wlan set hostednetwork key=\""<<key<<"\"";
		//	obat.close();
		//	system("c:/Hosted/wifipass.bat");
			system("@echo off");
			system("netsh wlan set hostednetwork key=\"password\"");
			break;
	/*	case 5:
			cout<<"\nUnder construction ";
			break;*/
		case 6:
			ofil.open("c:/Hotspot/log.txt");
			ofil<<endl<<ctime(&t)<<endl<<"SSID = \""<<ssid<<"\"""\tPassword = \""<<key<<"\"";
			ofil.close();
			system("c:/Hotspot/log.txt");
			break;
		case 7:
			obat.open("c:/Hotspot/license.txt");
			obat<<endl<<"This Program was made my \"Mohammed Adil\" in 2nd Semester of his B Tech.\nThis is a free software.\nThis software don't have any guarantee.\n\nEnjoy...................................."<<endl;
			obat.close();
			system("c:/Hotspot/license.txt");
			break;
		case 8:
			    cout<<"\nPress any key to continue............";
				getche();
				cout<<"\n\nThis program was made my Md. Adil +919872370557";
				getch();
                exit(1); 
		default :
			cout<<"\nWrong input.........."<<endl;
	}
	cout<<"\nDo you want to continue ('Y' or 'y'): ";cin>>ch;
}while(ch=='y' || ch=='Y');
cout<<"\nPress any key to continue............";
getche();
cout<<"\n\nThis program was made my Md. Adil +919872370557";

getch();
return 0;
}

