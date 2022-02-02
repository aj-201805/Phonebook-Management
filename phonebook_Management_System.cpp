#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

string name[50], phoneNo[50], mobileNo[50], faxNo[50], email[50], address[50];

int counter = -1;

int validate_contact(string tmpName){
	 for(int i = 0; i <= counter; i++){
	 	if(name[i] == tmpName){
	 		return 0;
	 	}
	 }
 	 return 1;
}

void add_contact(){
     string tmpName = "";
	 cout << "Enter Name: ";
	 cin >> tmpName;

	 if(validate_contact(tmpName) == 1){
	     counter++;
	 	 name[counter] = tmpName;
	 }else{
	 	cout << endl << "Contact Already Exist with this Name" << endl;
	 	return;
	 }

     cout << "Enter Phone No: ";
     cin >> phoneNo[counter];
     cout << "Enter Mobile No: ";
     cin >> mobileNo[counter];
     cout << "Enter Fax No: ";
     cin >> faxNo[counter];
     cout << "Enter Email No: ";
     cin >> email[counter];
     cout << "Enter Address: ";
     cin >> address[counter];

}

void print_contact(int tmpCounter){
	if(name[tmpCounter] == "")
		return;
	if(counter > -1){
		cout << "Name: "<<name[tmpCounter] << endl;
		cout << "Phone No: "<<phoneNo[tmpCounter] << endl;
		cout << "Mobile No: "<<mobileNo[tmpCounter] << endl;
		cout << "Fax No: "<<faxNo[tmpCounter] << endl;
		cout << "Email: "<<email[tmpCounter] << endl;
		cout << "Address: "<<address[tmpCounter] << endl << endl;
		cout << "Press any key to continue..." << endl << endl;
		getch();
	}
}

void print_all_contact(){
	if(counter > -1){
		for(int i=0; i<=counter; i++){
		    print_contact(i);
		}
	}
}

void update_contact(int tmpCounter){
     string tmpName = "";

	 cout << "Enter Name: ";
	 cin >> tmpName;

	 if(validate_contact(tmpName)){
	 	 name[tmpCounter] = tmpName;
	 }else{
	 	cout << endl << "Contact Already Exist with this Name" << endl;
	 	return;
	 }

     cout << "Enter Phone No: ";
     cin >> phoneNo[tmpCounter];
     cout << "Enter Mobile No: ";
     cin >> mobileNo[tmpCounter];
     cout << "Enter Fax: ";
     cin >> faxNo[tmpCounter];
     cout << "Enter Email: ";
     cin >> email[tmpCounter];
     cout << "Enter Address: ";
     cin >> address[tmpCounter];
}

void delete_contact(int tmpCounter){
	 name[tmpCounter] = "";
     phoneNo[tmpCounter] = "";
     mobileNo[tmpCounter] = "";
     faxNo[tmpCounter] = "";
     email[tmpCounter] = "";
     address[tmpCounter] = "";
}

int search_counter(){
	 if(counter < 0)
	 	 return -1;

	 string tmpName;

	 cout << "Enter Name: ";
	 cin >> tmpName;

	 for(int i = 0; i <= counter; i++){
	 	if(name[i] == tmpName){
	 		return i;
	 	}
	 }

 	 return 1;
}

int main(){

	char op;
	do{
		system("cls");
		cout << "1. Add Contact" << endl;
		cout << "2. View contact list" << endl;
		cout << "3. Search Contact" << endl;
		cout << "4. Update Contact" << endl;
		cout << "5. Delete Contact" << endl;
		cout << "6. Exit" << endl << endl;
		cout << "Enter Option from 1 to 6 : ";
		cin >> op;

		switch(op){
			case '1':
			{
				 add_contact();
				 cout << endl << "Contact added successful..." << endl;
				 cout << "Press any key to continue";
				 getch();
		 		 break;
			}

			case '2':
			{
				 print_all_contact();
		 		 break;
			}

			case '3':
			{
				 int tmpCounter = search_counter();
				 if(tmpCounter > -1){
				      print_contact(tmpCounter);
				 }
		 		 break;
			}

			case '4':
			{
				 int tmpCounter = search_counter();
				 if(tmpCounter > -1){
				      update_contact(tmpCounter);
				 }
		 		 break;
			}

			case '5':
			{
				 int tmpCounter = search_counter();
				 if(tmpCounter > -1){
				      delete_contact(tmpCounter);
				 }
		 		 break;
			}

			case '6':
			{
				 continue;
		 		 break;
			}
		}

	}while(op != '6');

	return 0;

}
