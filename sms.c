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
        Student s1[N];
        int i=0;
	FILE *fp;
	fp=fopen("student.txt","a");
	do{
		printf("\nEnter your student id:");
		scanf("%d",&s1[i].id);
		printf("\nEnter your name:");
		scanf("%s",s1[i].name);
		printf("\nEnter your age:");
		scanf("%d",&s1[i].age);
		printf("\nEnter the subject you're major in:");
		scanf("%s",s1[i].major);
		fprintf(fp,"\n%d %s %d %s",s1[i].id, s1[i].name, s1[i].age, s1[i].major);
		i++;
	}while(i<N);
	fclose(fp);
	printf("\nfor displaying:");
	i=0;
	fp=fopen("student.txt","r");
        printf("\nID Name Age Major");   			 	
	while(fscanf(fp,"\n%d %s %d %s",&s1[i].id, s1[i].name, &s1[i].age, s1[i].major)!=EOF){
		printf("\n%d %s %d %s",s1[i].id, s1[i].name, s1[i].age, s1[i].major);
	}
        fclose(fp);
	return 0;
}



		
