#include<iostream.h> 
#include<conio.h>
 #include<stdio.h> 
#include<string.h> 
#include<fstream.h>
class crop 
{ 
char name [30]; 
char supplier [30]; 
char type [30]; 
char block [30]; //Refers to the block inside the godown where the crop is stored 
int code; int qty; int d, m, y; float price; 
public: void getdata() 
{ 
cout << "Enter gets(name); cout << "Enter gets(supplier); cout << "Enter gets(type); cout << "Enter cin >> qty; cout << "Enter cin >> price; cout << "Enter cin >> code; cout << "Enter gets(block); cout << "Enter cin >> d >> m >> y; 
crop name: "; supplier name: "; crop type(Fruit/Vegetable/Grains/Fodder/Other):"; quanPty(kilograms): "; price(per kilogram): "; entry code: "; the block where the crop is stored: "; date (dd/mm/yyyy): "; 
} void showdata() { 
cout << "Crop: " << name << endl; cout << "Supplier: " << supplier << endl; cout << "Type: " << type << endl; 
cout << "Qty: " << qty << endl; cout << "Code: " << code << endl; cout << "Block: " << block << endl; cout << "Date: " << d << " / " << m << " / " << y << endl; 
} 
char* ret_name() { return name; } int ret_qty() { return qty; } char* ret_supname() { return supplier; } char* ret_type() 
{ return type; } float ret_price() { return price; } 
int ret_code() { return code; } int ret_d() { return d; } int ret_m() 
{ return m; } int ret_y() { return y; } 
}; 
fstream file1, file2; crop c1, c2; void create() { 
file1.open("Entries.dat", ios::out|ios::binary); 
char a='y'; do { 
c1.getdata(); file1.write((char*)&c1, sizeof(c1)); 
cout << "Enter y or Y to enter more records."; cin >> a; 
} while(a=='y' || a=='Y'); 
file1.close(); 
file1.open("Entries.dat", ios::in|ios::binary); file2.open("Inventory.dat", ios::out|ios::binary); 
while (file1.read((char*)&c1, sizeof(c1))) { 
file2.write((char*)&c1, sizeof(c1)); } 
file1.close(); 
file2.close(); } 
void append() { 
file1.open("Entries.dat", ios::app|ios::binary); file2.open("Inventory.dat", ios::app|ios::binary); char an='y'; do 
{ c1.getdata(); 
file1.write((char*)&c1, sizeof(c1)); file2.write((char*)&c1, sizeof(c2)); cout << "Enter y or Y to enter more records."; cin >> an; 
} while(an=='y' || an=='Y'); file1.close(); file2.close(); 
} void entry_crop() { 
char sname[30]; cout << "Enter name of the crop whose entries are to be displayed: "; gets(sname); int total_qty=0; float total_price=0; 
file1.open("Entries.dat", ios::in|ios::binary); file1.seekg(0); 
while (file1.read((char*)&c1, sizeof(c1))) { 
} 
if (strcmp(c1.ret_name(), sname)==0) { 
c1.showdata(); total_qty+=c1.ret_qty(); total_price+=(c1.ret_qty() * c1.ret_price()); 
} } 
cout <<endl<<endl<< "Crop: " << sname << endl; cout << "Total quanPty: " << total_qty <<endl; cout << "Average price: " << total_price / total_qty; file1.close(); 
void entry_supplier() { 
char supplier_name[30]; 
cout << "Enter name of the supplier whose entries are to be displayed: "; 
gets(supplier_name); file1.open("Entries.dat", ios::in|ios::binary); file1.seekg(0); 
int total_sup=0; while (file1.read((char*)&c1, sizeof(c1))) { 
if (strcmp(c1.ret_supname(), supplier_name)==0) { 
c1.showdata(); total_sup+=c1.ret_qty(); 
} } 
file1.close(); } 
void entry_type() { 
char tname[30]; cout << "Enter crop type for which entries are to be displayed: "; gets(tname); 
cout << supplier_name << endl; cout << "Total quanPty supplied: " << total_sup; 
} 
int t_qty=0; float t_price=0; 
file1.open("Entries.dat", ios::in|ios::binary); file1.seekg(0); 
while (file1.read((char*)&c1, sizeof(c1))) { 
if (strcmp(c1.ret_type(), tname)==0) { 
c1.showdata(); 
t_qty+=c1.ret_qty(); t_price+=(c1.ret_qty() * c1.ret_price()); 
} } 
cout <<endl<<endl<< "Crop type: " << tname << endl; cout << "Total quanPty: " << t_qty << endl; 
cout << "Average price: " << t_price / t_qty; file1.close(); 
void entry_search() { 
int scode; cout << "Enter code to search for corresponding entry: "; cin >> scode; file1.open("Entries.dat", ios::in|ios::binary); file1.seekg(0); int flag=0; 
while (file1.read((char*)&c1, sizeof(c1))) { 
if (scode==c1.ret_code()) { 
c1.showdata(); flag=1; 
break; } 
} if (flag==0) 
cout << "Entry record not found."; file1.close(); 
} 
void entry_date() { 
int dd, mm, yyyy; cout << "Enter date (dd/mm/yyyy): "; 
cin >> dd >> mm >> yyyy; 
file1.open("Entries.dat", ios::in|ios::binary); 
file1.seekg(0); 
cout << "Entries for date: " << dd << " / " << mm << " / " << yyyy << " are: " << endl; 
int dflag=0; 
while (file1.read((char*)&c1, sizeof(c1))) { 
if (dd==c1.ret_d() && mm==c1.ret_m() && yyyy==c1.ret_y()) { c1.showdata(); dflag=1; } 
} if (dflag==0) 
cout << "No entries for date: " << dd << " / " << mm << " / " << yyyy << endl; 
file1.close(); } 
void entry_all() { 
file1.open("Entries.dat", ios::in|ios::binary); file1.seekg(0); 
while (file1.read((char*)&c1, sizeof(c1))) { 
c1.showdata(); } 
file1.close(); } 
void inventory_update() { 
int icode; char new_block [30]; int qty_sold; int f=0; cout << "Enter code to update corresponding entry: "; 
cin >> icode; file1.open("Inventory.dat", ios::in|ios::binary); file2.open("Temp.dat", ios::out|ios::binary); file1.seekg(0); while (file1.read((char*)&c1, sizeof(c1))) 
{ if (c1.ret_code()==icode) 
{ 
c2.getdata(); file2.write((char*)&c2, sizeof(c2)); f=1; cout << "The record has been updated. " << endl; 
} 
else {file2.write((char*)&c1, sizeof(c1));} 
} if (f==0) cout << "Record not found. "; file1.close(); file2.close(); remove("Inventory.dat"); 
rename("Temp.dat", "Inventory.dat"); } 
void inventory_delete() { 
int delcode; cout << "Enter code to delete corresponding entry: "; cin >> delcode; file1.open("Inventory.dat", ios::in|ios::binary); file2.open("Temp.dat", ios::out|ios::binary); file1.seekg(0); while (file1.read((char*)&c1, sizeof(c1))) 
{ if (c1.ret_code()!=delcode) 
{ file2.write((char*)&c1, sizeof(c1)); 
} 
} file1.close(); file2.close(); remove("Inventory.dat"); rename("Temp.dat", "Inventory.dat"); 
} 
void inventory_all() { 
file1.open("Inventory.dat", ios::in|ios::binary); file1.seekg(0); 
while (file1.read((char*)&c1, sizeof(c1))) { 
c1.showdata(); } 
file1.close(); } 
void main() { 
clrscr(); char ans = 'y'; int choice; do 
{ 
cout << endl << "Welcome to Cropstor. Please select one of the following opPons: " << endl; 
cout << "Enter 0 to create files for Crop Entry and Crop Inventory." << endl; 
cout << "Enter 1 to append a new crop." << endl; cout << "Enter 2 to display entries for a parPcular crop." << endl; cout << "Enter 3 to display entries by a parPcular supplier. " << endl; 
cout << "Enter 4 to display entries for a parPcular crop type. " << endl; 
cout << "Enter 5 to search for entry on the basis of entry code. " << endl; 
cout << "Enter 6 to display all entries on a parPcular date. " << endl; cout << "Enter 7 to display all entries. " << endl; 
cout<< "Enter 8 to update inventory. " << endl; cout << "Enter 9 to delete a record from inventory. " << endl; cout << "Enter 10 to display inventory. " << endl; 
cin >> choice; 
switch(choice) { 
case 0: create(); break; 
case 1: append(); break; 
case 2: entry_crop(); break; 
case 3: entry_supplier(); break; 
case 4: entry_type(); break; 
case 5: entry_search(); break; 
case 6: entry_date(); break; 
case 7: entry_all(); break; 
case 8: inventory_update(); 
break; case 9: inventory_delete(); 
break; case 10: inventory_all(); 
break; default: cout << "Wrong choice. "; 
break; 
} cout << endl << "Enter y or Y to conPnue."; cin >> ans; }while(ans=='y' || ans=='Y'); 
getch(); } 
