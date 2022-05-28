#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int rno;
    char name[20];
    char srn[20];
    char branch[20];
    int sem; 
    float sgpa;
    struct subject
    {
        int scode;
        char sname[20];
        int mark;
    }sub[15];
    int total1;
    int total2;
    int total3;
    float per;
    char grade;
}student;

void write_student()
{
    student *s;
    FILE *fp;
    int n, i , j;
    printf("Enter how many students you want : ");
    scanf("%d",&n);
    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt", "w");
    for (i=0;i<n;i++)
    {   
        s[i].total1 = 0;
        s[i].total2 = 0;
        s[i].total3 = 0;
        s[i].per = 0;
        printf("\nEnter Roll Number : ");
        scanf("%d",&s[i].rno);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s",s[i].name);
        fflush(stdin);
        printf("Enter SRN : ");
        scanf("%[^\n]s",s[i].srn);
        fflush(stdin);
        printf("Enter Branch : ");
        scanf("%[^\n]s",s[i].branch);
        fflush(stdin); 
        printf("Enter Semester : ");
        scanf("%d",&s[i].sem);
        fflush(stdin);
        char arr[][20] = {"Civil","Chemistry","Maths","Computers","Electronics"};
        printf("\n");
        for (j=0;j<5;j++)
        {
            printf("Enter marks of %s in ISA1 out of 60: ", arr[j]);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total1 += s[i].sub[j].mark;
        }
        printf("\n");
        for (j=0;j<5;j++)
        {
            printf("Enter marks of %s in ISA2 out of 40 : ", arr[j]);
            scanf("%d",&s[i].sub[j+5].mark);
            s[i].total2 += s[i].sub[j+5].mark;
        }
        printf("\n");
        for (j=0;j<5;j++)
        {
            printf("Enter marks of %s in ESA out of 100: ", arr[j]);
            scanf("%d",&s[i].sub[j+10].mark);
            s[i].total3 += s[i].sub[j+10].mark;
        }
        s[i].per = (((s[i].total1+s[i].total2)/2)+(s[i].total3/2))/5;
        s[i].sgpa = s[i].per/10;
        if(s[i].per>=90)
            s[i].grade='S';
        
        else if(s[i].per>=80 &&s[i].per<90)
            s[i].grade='A';
            
        else if(s[i].per>=70 &&s[i].per<80)
            s[i].grade='B';
        
        else if(s[i].per>=60 &&s[i].per<70)
            s[i].grade='C';
               
        else if(s[i].per>=50 &&s[i].per<60)
            s[i].grade='D';
        
        else if(s[i].per>=40 &&s[i].per<50)
            s[i].grade='E';
            
        else
            s[i].grade='F';
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    free(s);
}
void display_all()
{
    student s1; 
    FILE *fp;
    int j;
    fp = fopen("mystudents.txt","r");
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf("\nSRN : %s",s1.srn);
        printf("\nName : %s",s1.name);
        printf("\nRoll No. : %d",s1.rno);
        printf("\nBranch : %s",s1.branch);
        printf("\nSemester : %d",s1.sem);
        printf("\n\n                         ISA1");
        printf("\n\nUE20CV101\tUE20CY101\tUE20MA151\tUE20CS151\tUE20EC101\n");
        for(j=0;j<5;j++)
        {
            printf("    %d\t\t",s1.sub[j].mark);
        }
        printf("\n===========================================================================");
        printf("\n\n                         ISA2");
        printf("\n\nUE20CV101\tUE20CY101\tUE20MA151\tUE20CS151\tUE20EC101\n");
        for(j=5;j<10;j++)
        {
            printf("    %d\t\t",s1.sub[j].mark);
        }
        printf("\n===========================================================================");
        printf("\n\n                         ESA");
        printf("\n\nUE20CV101\tUE20CY101\tUE20MA151\tUE20CS151\tUE20EC101\n");
        for(j=10;j<15;j++)
        {
            printf("  %d\t\t",s1.sub[j].mark);
        }
        printf("\n===========================================================================");
        printf("\nGrade : %c", s1.grade);
        printf("\nSGPA : %.2f",s1.sgpa);
        printf("\n");
        printf("\n");
        printf("\n");
    }
    fclose(fp);
}
void append()
{
    student *s;
    FILE *fp;
    int n, i , j;
    printf("Enter how many students you want to append: ");
    scanf("%d",&n);
    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt", "a+");
    for (i=0;i<n;i++)
    {   
        s[i].total1 = 0;
        s[i].total2 = 0;
        s[i].total3 = 0;
        s[i].per = 0;
        printf("\nEnter Roll Number : ");
        scanf("%d",&s[i].rno);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s",s[i].name);
        fflush(stdin);
        printf("Enter SRN : ");
        scanf("%[^\n]s",s[i].srn);
        fflush(stdin);
        printf("Enter Branch : ");
        scanf("%[^\n]s",s[i].branch);
        fflush(stdin); 
        printf("Enter Semester : ");
        scanf("%d",&s[i].sem);
        fflush(stdin);
        char arr[][20] = {"Civil","Chemistry","Maths","Computers","Electronics"};
        printf("\n");
        for (j=0;j<5;j++)
        {
            printf("Enter marks of %s in ISA1 out of 60: ", arr[j]);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total1 += s[i].sub[j].mark;
        }
        printf("\n");
        for (j=0;j<5;j++)
        {
            printf("Enter marks of %s in ISA2 out of 40 : ", arr[j]);
            scanf("%d",&s[i].sub[j+5].mark);
            s[i].total2 += s[i].sub[j+5].mark;
        }
        printf("\n");
        for (j=0;j<5;j++)
        {
            printf("Enter marks of %s in ESA out of 100: ", arr[j]);
            scanf("%d",&s[i].sub[j+10].mark);
            s[i].total3 += s[i].sub[j+10].mark;
        }
        s[i].per = (((s[i].total1+s[i].total2)/2)+(s[i].total3/2))/5;
        s[i].sgpa = s[i].per/10;
        if(s[i].per>=90)
            s[i].grade='S';
        
        else if(s[i].per>=80 &&s[i].per<90)
            s[i].grade='A';
            
        else if(s[i].per>=70 &&s[i].per<80)
            s[i].grade='B';
        
        else if(s[i].per>=60 &&s[i].per<70)
            s[i].grade='C';
               
        else if(s[i].per>=50 &&s[i].per<60)
            s[i].grade='D';
        
        else if(s[i].per>=40 &&s[i].per<50)
            s[i].grade='E';
            
        else
            s[i].grade='F';
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}

void no_of_rec()
{   
    student s1; 
    FILE *fp;
    fp = fopen("mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    printf("\n\nNO OF RECORDS = %d\n\n", n);
    fclose(fp);  
}
void display_sp()
{  
    student s1; 
    FILE *fp;
    int j, rno, found=0;
    fp = fopen("mystudents.txt","r");
    printf("Enter roll number to search: ");
    scanf("%d",&rno);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno == rno)
        {
            found = 1;
            printf("\nSRN : %s",s1.srn);
            printf("\nName : %s",s1.name);
            printf("\nRoll No. : %d",s1.rno);
            printf("\nBranch : %s",s1.branch);
            printf("\nSemester : %d",s1.sem);
            printf("\n\n                         ISA1");
            printf("\n\nUE20CV101\tUE20CY101\tUE20MA151\tUE20CS151\tUE20EC101\n");
            for(j=0;j<5;j++)
            {
                printf("    %d\t\t",s1.sub[j].mark);
            }
            printf("\n===========================================================================");
            printf("\n\n                         ISA2");
            printf("\n\nUE20CV101\tUE20CY101\tUE20MA151\tUE20CS151\tUE20EC101\n");
            for(j=5;j<10;j++)
            {
                printf("    %d\t\t",s1.sub[j].mark);
            }
            printf("\n===========================================================================");
            printf("\n\n                         ESA");
            printf("\n\nUE20CV101\tUE20CY101\tUE20MA151\tUE20CS151\tUE20EC101\n");
            for(j=10;j<15;j++)
            {
                printf("  %d\t\t",s1.sub[j].mark);
            }
            printf("\n===========================================================================");
            printf("\nGrade : %c", s1.grade);
            printf("\nSGPA : %.2lf",s1.sgpa);
            printf("\n");
            printf("\n");
            printf("\n");
        }
    }
    if(!found)
    {
        printf("\nRecord Not Found\n");
    }
    fclose(fp);
}
void modify_student()
{
    student s; 
    FILE *fp, *fp1;
    int  j, rno, found=0;
    fp = fopen("mystudents.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("Enter roll number to update: ");
    scanf("%d",&rno);
    while(fread(&s,sizeof(student),1,fp))
    {
        if(s.rno == rno)
        {
            found = 1;            
            s.total1 = 0;
            s.total2 = 0;
            s.total3 = 0;
            s.per = 0;
            fflush(stdin);
            printf("Enter new details of the student\n");
            fflush(stdin);
            printf("\nEnter Roll Number : ");
            scanf("%d",&s.rno);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%[^\n]s",s.name);
            fflush(stdin);
            printf("Enter SRN : ");
            scanf("%[^\n]s",s.srn);
            fflush(stdin);
            printf("Enter Branch : ");
            scanf("%[^\n]s",s.branch);
            fflush(stdin); 
            printf("Enter Semester : ");
            scanf("%d",&s.sem);
            fflush(stdin);
            char arr[][20] = {"Civil","Chemistry","Maths","Computers","Electronics"};
            printf("\n");
            for (j=0;j<5;j++)
            {
                printf("Enter marks of %s in ISA1 out of 60: ", arr[j]);
                scanf("%d",&s.sub[j].mark);
                s.total1 += s.sub[j].mark;
            }
            printf("\n");
            for (j=0;j<5;j++)
            {
                printf("Enter marks of %s in ISA2 out of 40 : ", arr[j]);
                scanf("%d",&s.sub[j+5].mark);
                s.total2 += s.sub[j+5].mark;
            }
            printf("\n");
            for (j=0;j<5;j++)
            {
                printf("Enter marks of %s in ESA out of 100: ", arr[j]);
                scanf("%d",&s.sub[j+10].mark);
                s.total3 += s.sub[j+10].mark;
            }
            s.per = (((s.total1+s.total2)/2)+(s.total3/2))/5;
            s.sgpa = s.per/10;
            if(s.per>=90)
                s.grade='S';
        
            else if(s.per>=80 &&s.per<90)
                s.grade='A';
            
            else if(s.per>=70 &&s.per<80)
                s.grade='B';
        
            else if(s.per>=60 &&s.per<70)
                s.grade='C';
               
            else if(s.per>=50 &&s.per<60)
                s.grade='D';
        
            else if(s.per>=40 &&s.per<50)
                s.grade='E';
            
            else
                s.grade='F';
        }
        fwrite(&s,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        fp1 = fopen("temp.txt","r");
        fp = fopen("mystudents.txt","w");
        while(fread(&s,sizeof(student),1,fp1))
        {
            fwrite(&s,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("\nRecord Not Found\n");
    }
}

void delete_student()
{
    student s1; 
    FILE *fp, *fp1;
    int  j, rno, found=0;
    fp = fopen("mystudents.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("Enter roll number to delete: ");
    scanf("%d",&rno);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno == rno)
        {   
            found = 1; 
        }
        else
        {
            fwrite(&s1,sizeof(student),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        printf("\n\nRecord deleted\n\n");
        fp1 = fopen("temp.txt","r");
        fp = fopen("mystudents.txt","w");
        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("\nRecord Not Found\n");
    }
    
    fclose(fp);
    
}
void result_menu()
{
    int ch;
    do
    {
        printf("\n1. Display all the records ");
        printf("\n2. Search for a specific record");
        printf("\n3. Back to main menu");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {   
        case 1: 
            display_all();
            break;
        case 2:
            display_sp();
            break;
        }
    }while(ch != 3);
}
void entry_menu()
{
    int ch; 
    do
    {
        printf("\n1. Create a record "); 
        printf("\n2. Add a new record");
        printf("\n3. Display total number of records");
        printf("\n4. Modify a record");
        printf("\n5. Delete a record");
        printf("\n6. Back to main menu");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: 
            write_student();
            break;        
        case 2:
            append();
            break;
        case 3:
            no_of_rec();
            break;
        case 4:
            modify_student();
            break;
        case 5:
            delete_student();
            break;
        }
    }while(ch!=6);
}
int main()
{
    int ch;
    do
    {
        printf("\n1. Entry/ Edit Menu");
        printf("\n2. Class result");
        printf("\n3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: 
                entry_menu();
                break;
            case 2: 
                result_menu();
                break;
        }
    }while(ch != 3);
    return 0;

}
