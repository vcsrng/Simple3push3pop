#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Mahasiswa{
	int age;
	char name[50];
	Mahasiswa *prev, *next;
}*head=NULL,*tail=NULL;

Mahasiswa* createNode(int age,char name[]){
	Mahasiswa* newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
	newNode -> age = age;
	strcpy(newNode->name, name);
	newNode -> prev = NULL;
	newNode -> next = NULL;
	
	return newNode;
}

void pushHead(int age,char name[]){
	Mahasiswa* node = createNode(age,name);
	if(!head){
		head = tail = node;
	}else{
		head->prev=node;
		node->next=head;
		head = node;
	}
}

void pushTail(int age,char name[]){
	Mahasiswa* node = createNode(age,name);
	if(!head){
		head = tail = node;
	}else{
		tail->next=node;
		node->prev=tail;
		tail = node;
	}
}

void pushMid(int age,char name[]){
	Mahasiswa* node = createNode(age,name);
	if(!head){
		head = tail = node;
	}else{
		if(age < head->age){
			pushHead(age,name);
		}else if(age > tail->age){
			pushTail(age,name);
		}else{
			Mahasiswa* curr = head;
			while(curr->next != NULL && curr->next->age <= age){
				curr = curr->next;
			}
			curr->next->prev = node;
			node->prev = curr;
			node->next = curr->next;
			curr->next = node;
		} 
	}
}

void popHead(){
	if(!head){
		return;
	}else{
		if(head==tail){
			Mahasiswa* temp = head;
			free(temp);
			head=tail=NULL;
		}else{
			Mahasiswa* temp = head;
			head = head->next;
			free(temp);
			head->prev = NULL;
		}
	}
}

void popTail(){
	if(!head){
		return;
	}else{
		if(head==tail){
			Mahasiswa* temp = head;
			free(temp);
			head=tail=NULL;
		}else{
			Mahasiswa* temp = tail;
			tail=tail->prev;
			free(temp);
			tail->next = NULL;
		}	
	}
}

void popMid(int age){
	if(!head){
		return;
	}else{
		if(head==tail && head->age == age){
			Mahasiswa* temp = head;
			free(temp);
			head=tail=NULL;
		}else if(head->age==age){
			popHead();
		}else if(tail->age==age){
			popTail();
		}else{
			Mahasiswa* temp = head;
			while(temp != NULL && temp->age!=age){
				temp= temp->next;
			}
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			free(temp);
		}	
	}
}

void printAll(){
	Mahasiswa* curr = head;
	while(curr){
		printf("%d %s\n", curr->age,curr->name);
		curr = curr->next;
	}
}

void search(int age){
	Mahasiswa* curr = head;
	while(curr != NULL && curr->age!=age){
		curr = curr->next;
	}
	if(curr != NULL){
		printf("Data Found : %d %s\n", curr->age, curr->name);
	}else{
		printf("Data Not Found!\n");
	}
}

int main(){
	int check=0;
	int inputan;
	int inputan2;
	int input2;
	int input3;
	int umurinput;
	int umurinput2;
	char namainput[50];
	printf("How much data you want to input!\n");
	printf(">> ");
	scanf("%d", &inputan); getchar();
	printf("Input data\n");
	int i=0;
	while(i<inputan){
		if(i!=0){
			system("cls");
			printf("Input data\n");
		}
		if(check=1){
			system("cls");
			printf("Input data\n");
			check=check-1;
		}
		printf("Data#%d:\n", i+1);
		printf("1. PushHead\n");
		printf("2. PushMid\n");
		printf("3. PushTail\n");
		printf("4. PopHead\n");
		printf("5. PopMid\n");
		printf("6. PopTail\n");
		printf(">> ");
		scanf("%d", &input2); getchar();
		switch(input2){
			case 1:
				printf("PushHead-Name : ");
				scanf("%s", namainput); getchar();
				printf("PushHead-Age : ");
				scanf("%d", &umurinput); getchar();
				pushHead(umurinput, namainput);
				i=i+1;
				break;
			case 2:
				printf("PushMid-Name : ");
				scanf("%s", namainput); getchar();
				printf("PushMid-Age : ");
				scanf("%d", &umurinput); getchar();
				pushMid(umurinput, namainput);
				i=i+1;
				break;
			case 3:
				printf("PushTail-Name : ");
				scanf("%s", namainput); getchar();
				printf("PushTail-Age : ");
				scanf("%d", &umurinput); getchar();
				pushTail(umurinput, namainput);
				i=i+1;
				break;
			case 4:
				popHead();
				i=i+1;
				break;
			case 5:
				printf("PopMid : ");
				scanf("%d", &input3); getchar();
				popMid(input3);
				i=i+1;
				break;
			case 6:
				popTail();
				i=i+1;
				break;
			default:
				printf("No options hey . . . \n");
				check=1;
				getch();
		}
	}
	system("cls");
	printf("Data Mahasiswa :\n");
	printAll();
	printf("How much data you want to search!\n");
	printf(">> ");
	scanf("%d", &inputan2); getchar();
	for(int j=0;j<inputan2;j++){
		printf("Search by Age#%d : ", j+1);
		scanf("%d", &umurinput2); getchar();
		search(umurinput2);
	}
		
	return 0;
}
