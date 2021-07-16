/*
Task : lab maamagement system
Author : M Usama
Date : 10-15-2020
*/

#include <iostream>
#include <iomanip>
using namespace std;

//declaring global variables
int user, id_no, lab_no, pc_no;

//functions prototypes
void print_s(int** array2);
void print(int** array, int loop, int s);
void init(int** array3, int lop, int e);
void show_menu();
void login(int** array,int id , int lab , int pc);
void logout(int** array, int lab_no, int pc_no);
void search(int** array, int id);
void in_cases(int** array, int lab,int id_no, int pc_no , int pc);
void out_cases(int** array, int lab_no,int pc_no, int pc);

int main(){
	// assigning dynaimc memory to arrays 
	int** p_array;
	p_array = new int* [4];

	p_array[0] = new int[5];
	p_array[1] = new int[6];
	p_array[2] = new int[4];
	p_array[3] = new int[3];

	// Assigning 0 to arrays
	init(p_array, 5, 0);
	init(p_array, 6, 1);
	init(p_array, 4, 2);
	init(p_array, 3, 3);
int choice,user;
	// FOR MENU
	while (true)
	{
		show_menu();
		cout << " Your choice : ";
		cin >> choice;
	switch (choice)
			{
	case 1:
	{
		cout << "\n\n 1 LOGIN \n 2 LOGOUT  \n 3 SEARCH  \n 4 Show DATABASE  \n 5 QUIT  " << endl;
		cout<<"\n  Your choice :";
		cin >> user;
			if (user == 1)
		{
			int id, lab, pc;
			cout << "Enter the ID no , lab(1-4) no and PC no. eg (12345 2 2) : ";
			cin >> id >> lab >> pc;
			login(p_array,id,lab,pc);
			system("pause");
			system("CLS");
			show_menu();
			
		}
		else if (user == 2)
		{
			int  lab, pc;
			cout << "Enter  lab(1-4) no and PC no. eg (2 2) : ";
			cin >>  lab >> pc;
			logout(p_array,lab,pc);
			system("pause");
			system("CLS");
			show_menu();
		
		}
		else if (user == 3)
		{
			int id;
			cout << "Enter the id number : ";
			cin >> id;
			search(p_array, id);
			system("pause");
			system("CLS");
			show_menu();
		
		}
		else if (user == 4)
		{
			cout << endl;
			cout << setw(40) << "Computer stations\n" << endl;

			print_s(p_array);
			system("pause");
			system("CLS");
			show_menu();
		
		}
		else if (choice == 5)
			return 0;
		break;
	}
	case 2:{

	{
		cout << "\n 1 LOGIN \n 2 LOGOUT \n 5 QUIT" << endl;
		cout<<"\n  You choice :";
		cin >> user;
			if (user == 1)
		{
			int id, lab, pc;
			cout << "Enter the ID no , lab(1-4) no and PC no. eg (12345 2 2) : ";
			cin >> id >> lab >> pc;
			login(p_array,id,lab,pc);
			system("pause");
			system("CLS");
			show_menu();
			
		}
		else if (user == 2)
		{
			int  lab, pc;
			cout << "Enter  lab(1-4) no and PC no. eg (2 2) : ";
			cin >>  lab >> pc;
			logout(p_array,lab,pc);
			system("pause");
			system("CLS");
			show_menu();
		
		}
		else if (choice == 3)
		return 0;
	}
	default:
		cout << "Invalid input !";
	}
}
}
	//Deleting the dynamic memory
	for(int i = 0; i <4 ; i++)
	{
		delete [] p_array[i];
	}
	delete[]p_array;
	}
void print_s(int** array)
{
	print(array, 5, 0);
	print(array, 6, 1);
	print(array, 4, 2);
	print(array, 3, 3);
}
void print(int** array, int loop, int s)
{
	cout << "LAB " << s + 1 << "    ";

	for (int i = 0; i < loop; i++)
	{
		if (array[s][i] == 0)
		{
			cout << i + 1 << ": empty  ";
		}
		else
		{
			cout << i + 1 << ":  " << array[s][i] << "   ";
		}
	}
	cout << endl;
}
void init(int** array3, int lop, int e)
{
	for (int i = 0; i < lop; i++)
	{
		array3[e][i] = 0;
	}
}
void show_menu()
{
	// creating menu for user
	system("cls");
	cout << setw(47) << "  HOME PAGE \n";
	cout << setw(50) << "===================" << endl;
	cout << setw(52) << "Lab Management System\n";
	cout << setw(15) << " SELECT USER\n\n";
	cout << " 1 Admin  \n 2 User\n\n ";
}
void login(int** array,int id_no, int lab_no, int pc_no)
{
	while(id_no <10000 || id_no >99999)
	{
	cout << "Invalid ID entered! Enter 5 digit ID no : ";
	cin >> id_no;
	}
	while (lab_no < 1 || lab_no > 4)
	{
		cout << "Error ! Lab dosen`t exist\nEnter the lab number(1-4) :";
		cin >> lab_no;
	}
	switch (lab_no)
	{

	case 1:
	{
		in_cases(array, lab_no, id_no, pc_no ,5);
		break;
	}
	case 2:
	{
		in_cases(array, lab_no, id_no, pc_no , 6);
		break;
	}
	case 3:
	{
		in_cases(array, lab_no, id_no, pc_no , 4);
		break;
	}
	case 4:
	{
		in_cases(array, lab_no, id_no, pc_no , 3);
		break;
	}
	}
}
void logout(int** array,int lab_no , int pc_no)
{

	while (lab_no < 1 || lab_no > 4)
	{
		cout << "Error ! Lab dosen`t exist\nEnter the lab number(1-4) :";
		cin >> lab_no;
	}
	switch (lab_no)
	{

	case 1:
	{
		out_cases(array, lab_no, pc_no,5);
		break;
	}
	case 2:
	{
		out_cases(array, lab_no, pc_no,6);
		break;
	}
	case 3:
	{
		out_cases(array, lab_no, pc_no,4);
		break;
	}
	case 4:
	{
		out_cases(array, lab_no, pc_no,3);
		break;
	}
	}

}
void search(int** array, int id)
{
	while(id_no <10000 || id_no >99999)
	{
	cout << "Invalid ID entered! Enter 5 digit ID no : ";
	cin >> id_no;
	}
	// for lab 1
	for (int i = 0; i < 5; i++)
	{
		if (array[0][i] == id)
		{
			cout << "\nUser " << id << " is in lab " << 1 << " at computer " << i + 1 << endl;
			return;
		}

	}
	//For lab 2
	for (int i = 0; i < 6; i++)
	{
		if (array[1][i] == id)
		{
			cout << "\nUser " << id << " is in lab " << 2 << " at computer " << i + 1 << endl;
			return;
		}

	}

	// For lab 3
	for (int i = 0; i < 4; i++)
	{
		if (array[2][i] == id)
		{
			cout << "\nUser " << id << " is in lab " << 3 << " at computer " << i + 1 << endl;
			return;
		}

	}

	//For lab 3
	for (int i = 0; i < 3; i++)
	{
		if (array[3][i] == id)
		{
			cout << "\nUser " << id << " is in lab " << 4 << " at computer " << i + 1 << endl;
			return;
		}

	}
	cout << "\nThe user " << id << " is not present in the Lab " << endl;
}
void in_cases(int** array, int lab_no,int id_no, int pc_no, int pc)
{

	while (pc_no < 1 || pc_no >pc)
	{
		cout << "Error ! Computer station dosen`t exist \nEnter the computer station number(1-"<<pc <<") :  ";
		cin >> pc_no;
	}
	

	if (array[lab_no-1 ][pc_no - 1] != 0)
	{

		cout << "\nError ! system already in use Try another one.\n";
		
	}
	else if (array[lab_no-1 ][pc_no - 1] == 0)
	{
		cout << endl;
		cout << "You have been successfully login to LAB " << lab_no << " computer " << pc_no << endl;
		cout << endl;
		array[lab_no-1][pc_no - 1] = id_no;
	/*	cout << setw(40) << "Computer stations\n" << endl;
		print_s(array);*/
	}
}
void out_cases(int** array, int lab_no, int pc_no,int pc)
{



	while (pc_no < 1 || pc_no >pc)
	{
		cout << "Error ! Computer station dosen`t exist \nEnter the computer station number(1-5) :  ";
		cin >> pc_no;
	}


	if (array[lab_no - 1][pc_no - 1] != 0)
	{
		cout << endl;
		cout << "You have been successfully logout from LAB " << lab_no << " computer " << pc_no << endl;
		cout << endl;
		array[lab_no-1][pc_no - 1] = 0;
	/*	cout << setw(40) << "Computer stations\n" << endl;
		print_s(array);*/

	}
	else if (array[lab_no - 1][pc_no - 1] == 0)
	{
		cout << "\nError ! No one is login here Try another one. \n";
		

	}
	}
	

