#ifndef PB_H_INCLUDED
#define PB_H_INCLUDED
#include<stddef.h>
#define MAX 50
typedef char EntryType[MAX];

typedef struct element
{
    EntryType Name;
    EntryType Email;
    EntryType phoneNumber;
    struct element* next;
}Element;

typedef struct Phonebook
{
    Element* Head;
    Element* rear;
    int Size;
}phoneBook;

void Create_phoneBook(phoneBook* pb);
void Add_Element(phoneBook* pb, EntryType Name, EntryType Email, EntryType PhoneNumber);
int Delete_Element(phoneBook* pb ,EntryType Name);
int Search_By_Name(phoneBook* pb ,EntryType Name, Element* Data);
int Search_By_Phone(phoneBook* pb ,EntryType PhoneNumber, Element* Data);
int Edit_Element_email(phoneBook* pb ,EntryType Name, EntryType  NewEmail);
int Edit_Element_phone(phoneBook* pb ,EntryType Name, EntryType NewPhoneNumber);
int Get_Size(phoneBook* pb);
void View_element(Element*e);
void View_all(phoneBook* pb);
int Save_On_Database(phoneBook* pb);


#endif // PB_H_INCLUDED
