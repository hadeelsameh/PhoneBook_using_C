#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include<windows.h>
#include "pb.h"

int main()
{
    phoneBook book_1;
    EntryType name;
    EntryType sname;
    EntryType dname;
    EntryType ename;
    EntryType email;
    EntryType newEmail;
    EntryType phoneNumber;
    EntryType sphone;
    EntryType newphone;
    Element data;
    Element data2;
    int expresion;
    int num;
    int flag,flag1,flag2,flag3,flag4;
    Create_phoneBook(&book_1);
    int exit=1;

    while(exit){
    printf("Choose between these options: \n");
    printf(" 1-To add new element,\n 2-To Search for an element by name,\n 3-To search for an element by phone number,\n 4-To Edit an element email,\n 5-To Edit an element phone number,\n 6-To delete an element,\n 7-To show all elements.\n->>");
    scanf("%d",&expresion);
    switch(expresion){
        case 1:
            printf("How many elements do you want to add: ");
            scanf("%d",&num);
            for (int i=0;i<num;i++){
                printf("Enter the name: ");
                scanf("%s",name);
                printf("Enter the email: ");
                scanf("%s",email);
                printf("Enter the phoneNumber: ");
                scanf("%s",phoneNumber);
                printf("\n");
                Add_Element(&book_1,name,email,phoneNumber);
            }
                printf("Element Added successfully!\n");
                printf("The number of elements after insertion is:");
                printf("%d\n",Get_Size(&book_1));
                Save_On_Database(&book_1);
                printf("\n");
            break;

        case 2:
            printf("Enter the name for search: ");
            scanf("%s",sname);
            printf("\n");
            flag = Search_By_Name(&book_1,sname,&data);
            if (flag==0){
                printf("Element Not Found!");
            }
            else if (flag==2){
                printf("PhoneBook is Empty!!");
            }
            else{
               View_element(&data);
            }
            printf("\n");
            break;

        case 3:
            printf("Enter the phoneNumber for search: ");
            scanf("%s",sphone);
            printf("\n");
            flag1=Search_By_Phone(&book_1,sphone,&data2);
            if (flag1==0){
                printf("Element Not Found!");
            }
            else if (flag1==2){
                printf("PhoneBook is Empty!!");
            }
            else{
               View_element(&data2);
            }
            printf("\n");
            break;

        case 4:
            printf("Enter the name for edit: ");
            scanf("%s",ename);
            printf("Enter new email: ");
            scanf("%s",newEmail);
            printf("\n");
            flag2= Edit_Element_email(&book_1,ename,newEmail);
            if (flag2==0){
                printf("Element Not Found!");
            }
            else if (flag2==2){
                printf("PhoneBook is Empty!!");
            }
            else{
               printf("Element edited successfully!");
               Save_On_Database(&book_1);
            }
            printf("\n");
            break;

        case 5:
            printf("Enter the name for edit: ");
            scanf("%s",ename);
            printf("Enter new phoneNumber: ");
            scanf("%s",newphone);
            printf("\n");
            flag3=Edit_Element_phone(&book_1,ename,newphone);
            if (flag3==0){
                printf("Element Not Found!");
            }
            else if (flag3==2){
                printf("PhoneBook is Empty!!");
            }
            else{
               printf("Element edited successfully!");
               Save_On_Database(&book_1);
            }
            printf("\n");
            break;

        case 6:
            printf("Enter the name for deletion: ");
            scanf("%s",dname);
            printf("\n");
            flag4=Delete_Element(&book_1,dname);
            if (flag4==0){
                printf("Element Not Found!");
            }
            else if (flag4==2){
                printf("PhoneBook is Empty!!");
            }
            else{
               printf("Element deleted successfully!\n");
               printf("The number of elements after deletion is:");
               printf("%d\n",Get_Size(&book_1));
               Save_On_Database(&book_1);
            }
            printf("\n");
            break;

        case 7:
            View_all(&book_1);
            break;

        default:
            printf("\n");
            printf("NOT Valid Option!\nRestart the program !\n");
            exit=0;
    }

    printf("\n\n\n");
    }
    return 0;
}
