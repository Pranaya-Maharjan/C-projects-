#include<stdio.h>
#define N 3
struct Student{
	int id;
	char name[20];
	int age;
	char major[20];
};
typedef struct Student Student;
int main(){
	int choice=0;
	printf("================Welcome to my Program=====================");
	printf("\n1.Add student record.");
	printf("\n2.View records.");
	printf("\n3.Delete record.");
	printf("\n4.Update record.");
	printf("\n5.Exit");
	printf("\nEnter your choice from 1-5:");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
		Student s1;
        FILE *fp;
        fp=fopen("student.txt","a");

              printf("\nEnter your student id:");
              scanf("%d",&s1.id);
              printf("\nEnter your name:");
              scanf("%s",s1.name);
              printf("\nEnter your age:");
              scanf("%d",&s1.age);
              printf("\nEnter the subject you're major in:");
              scanf("%s",s1.major);
              fprintf(fp,"\n%d %s %d %s",s1.id, s1.name, s1.age, s1.major);
              fclose(fp);
              break;
        }
		case 2:{
		      Student s1;
	          int i=0;
			  FILE *fp;
	          fp=fopen("student.txt","r");
			  if (fp == NULL) {
                   printf("Could not open student.txt\n");
                   break;
              }
              printf("\nID Name Age Major");
	          while(fscanf(fp,"\n%d %s %d %s",&s1.id, s1.name, &s1.age, s1.major)!=EOF){
		             printf("\n%d %s %d %s",s1.id, s1.name, s1.age, s1.major);
	          }
              fclose(fp);
              break;
        }
		case 3:{
		      Student s1;
		      int ide;
			  FILE *fp;
			  FILE *temp;
		      printf("Choose id to delete from:");
			  scanf("%d",&ide);
			  fp=fopen("student.txt","r");
			  temp=fopen("Temp.txt","w");
			  while(fscanf(fp,"\n%d %s %d %s",&s1.id, s1.name, &s1.age, s1.major)!=EOF){
				    if (ide!=s1.id){
					        fprintf(temp,"%d %s %d %s",s1.id, s1.name, s1.age, s1.major);
					}
			  }
			  fclose(fp);
			  fclose(temp);
			  remove("student.txt");
			  rename("Temp.txt", "student.txt");
			  break;
		}


	}
	return 0;

}
