#include<stdio.h>
#include<stdlib.h>
#include"pb.h"

void Create_phoneBook(phoneBook* pb){
    pb->Head=NULL;
    pb->rear=NULL;
    pb->Size=0;
}

void Add_Element(phoneBook* pb,EntryType name, EntryType email, EntryType PhoneNumber){
    Element* p=(Element *)malloc(sizeof(Element));
    strcpy(p->Email,email);
    strcpy(p->Name,name);
    strcpy(p->phoneNumber,PhoneNumber);
    p->next = NULL;

    if (pb->rear==NULL){
        pb->Head=p;
    }
    else{
        pb->rear->next=p;
    }
    pb->rear=p;
    pb->Size++;
}

int Delete_Element(phoneBook* pb ,EntryType Name){
    int flag=0;
    Element* temp;
    Element* temp2;
    temp=pb->Head;
    temp2=NULL;
    if (pb->rear!=NULL){
        for(int i=1;i<=pb->Size;i++){
            if ( !(strcmp(temp->Name,Name)) ){
                flag=1;

                    if(temp==pb->Head){
                        pb->Head=temp->next;
                        free(temp);
                        pb->Size--;
                    }
                    else {
                        temp2->next=temp->next;
                        free(temp);
                        pb->Size--;
                    }
                    if(pb->Size ==0){
                        pb->rear=NULL;
                    }
                return flag;
            }
            else{
                temp2=temp;
                temp=temp->next;
            }
        }
    }
    else{
        flag=2;
    }
    return flag;
}

int Search_By_Name(phoneBook* pb ,EntryType Name, Element* Data){
    int flag=0;
    Element* temp;
    temp=pb->Head;
    if (pb->Size!=0){
        for(int i=1;i<=pb->Size;i++){
            if ( !(strcmp(temp->Name,Name)) ){
                Data=temp;
                flag=1;
                return flag;
            }
            else{
                temp=temp->next;
            }
        }
    }
    else{
        flag=2;
    }
    return flag;
}

int Search_By_Phone(phoneBook* pb ,EntryType PhoneNumber, Element* Data){
    int flag=0;
    Element* temp;
    temp=pb->Head;
    if (pb->Size!=0){
        for(int i=1;i<=pb->Size;i++){
            if ( !(strcmp(temp->phoneNumber,PhoneNumber)) ){
                Data=temp;
                flag=1;
                return flag;
            }
            else{
                temp=temp->next;
            }
        }
    }
    else{
        flag=2;
    }
    return flag;
}

int Edit_Element_email(phoneBook* pb ,EntryType Name, EntryType  NewEmail){
    int flag=0;
    Element* temp;
    temp=pb->Head;
    if (pb->Size!=0){
        for(int i=1;i<=pb->Size;i++){
            if ( !(strcmp(temp->Name,Name)) ){
                strcpy(temp->Email,NewEmail);
                flag=1;
                return flag;
            }
            else{
                temp=temp->next;
            }
        }
    }
    else{
        flag=2;
    }
    return flag;
}

int Edit_Element_phone(phoneBook* pb ,EntryType Name, EntryType  NewPhoneNumber){
    int flag=0;
    Element* temp;
    temp=pb->Head;
    if (pb->Size!=0){
        for(int i=1;i<=pb->Size;i++){
            if ( !(strcmp(temp->Name,Name)) ){
                strcpy(temp->phoneNumber,NewPhoneNumber);
                flag=1;
                return flag;
            }
            else{
                temp=temp->next;
            }
        }
    }
    else{
        flag=2;
    }
    return flag;
}

int Get_Size(phoneBook* pb){
    return pb->Size;
}

void View_element(Element*e){
    printf("Name:%s \nEmail address:%s \nPhone Number:%s\n",e->Name,e->Email,e->phoneNumber);
            printf("--------------------------------------------\n");
}

void View_all(phoneBook* pb){
    Element* temp;
    temp=pb->Head;
    if (pb->rear!=NULL){
        for(int i=1;i<=pb->Size;i++){
            printf("\n");
            printf("Name:%s \nEmail address:%s \nPhone Number:%s\n",temp->Name,temp->Email,temp->phoneNumber);
            printf("--------------------------------------------\n");
            temp=temp->next;
        }
    }
    else{
        printf("\n");
        printf("The PhoneBook is Empty!\n");
    }
}

int Save_On_Database(phoneBook* pb){
    int flag=0;
    FILE* p2f;
    p2f = fopen("Database.txt", "w");

     if(p2f==NULL){
        printf("Error\n");
    }
    else{
        Element* temp;
        temp=pb->Head;
        if (pb->rear!=NULL){
        for(int i=1;i<=pb->Size;i++){
            fprintf(p2f,"Name:%s \nEmail address:%s \nPhone Number:%s\n -----------------------------------\n",temp->Name,temp->Email,temp->phoneNumber);
            temp=temp->next;
            }
            printf("Data in the 'Database.txt' has updated successfully!");
        }
        else{
            printf("The PhoneBook is Empty!\n");
        }
            flag=1;
    }
    fclose(p2f);
    return flag;
}




