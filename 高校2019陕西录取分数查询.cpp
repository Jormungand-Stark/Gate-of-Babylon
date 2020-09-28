/*��ѯ����У2019�����������¼ȡ������*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud_node{
	int num;
	int fraction1;
	int fraction2;
	char school[20];
	struct stud_node*next;
};
 struct stud_node*Create_Stu_Doc ();
 struct stud_node*InsertDoc (struct stud_node*head,struct stud_node*stud);
 struct stud_node*DeleteDoc (struct stud_node*head,int num);
 void Print_Stu_Doc(struct stud_node * head);

int main(void)
{
struct stud_node*head,*p;
int choice,num,fraction1,fraction2;
char school[20];
int size=sizeof (struct stud_node);

do{
	printf("1:Create 2:Insert 3:Delete 4:Print 0:Exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			head=Create_Stu_Doc ();
			break;

		case 2:
			printf("������ ѧУ��ţ�ѧУ���ƣ��Ŀ�¼ȡ���������¼ȡ����:\n");
			scanf("%d%s%d%d",&num,school,&fraction1,&fraction2);
			p=(struct stud_node*)malloc(size);
			p->num=num;
			strcpy(p->school,school);
			p->fraction1=fraction1;
			p->fraction2=fraction2;
			head=InsertDoc (head,p);
			break;

		case 3:
			printf("Input num: \n");
			scanf("%d",&num);
			head=DeleteDoc (head,num);
			break;

		case 4:
			Print_Stu_Doc(head);
			break;

		case 0:
			break;
		}
	} while(choice!=0);

	return 0;
}
/*�½�����*/
struct stud_node*Create_Stu_Doc ()
{
	struct stud_node*head,*p,*tail;
	int num,fraction1,fraction2;
	char school[20];

	head=tail=NULL;
	printf("������ ѧУ��ţ�ѧУ���ƣ��Ŀ�¼ȡ���������¼ȡ����:\n");
	printf("(¼����Ϣ�����磺��20 �廪��ѧ 630 650�������֮��ctrl+z�˳�¼���������������)\n");
	while(scanf("%d%s%d%d",&num,school,&fraction1,&fraction2)!=EOF){
		p=(struct stud_node*)malloc(sizeof(struct stud_node));
		p->num=num;
		strcpy(p->school,school);
		p->fraction1=fraction1;
		p->fraction2=fraction2;
		p->next=NULL;

		if(head==NULL)
		head=p;//ȷ��ͷ�ڵ�
		else
		tail->next=p;//��������ṹ

		tail=p;
		//head=InsertDoc (head,p);  /*���ò��뺯��*/
	}
	return head;
}

 /*�������*/
 struct stud_node*InsertDoc (struct stud_node*head,struct stud_node*stud)
 {
 	struct stud_node*ptr,*ptr1,*ptr2;
 	ptr2=head;
 	ptr=stud;
 	if(head==NULL){
 		head=ptr;
 		head->next=NULL;
	 }
	 else{
	 	while((ptr->num>ptr2->num)&&(ptr2->next!=NULL)){
	 		ptr1=ptr2;
	 		ptr2=ptr2->next;
		 }
		 if(ptr->num<=ptr2->num){   /*��ptr1��ptr2֮������½ڵ�*/
		 if(head==ptr2)
		 head=ptr;
		 else
		 ptr1->next=ptr;

		 ptr->next=ptr2;
		 }
		 else{
		 	ptr2->next=ptr;
		 	ptr->next=NULL;
		 }
	 }
	 return head;
 }
 /*ɾ������*/
 struct stud_node*DeleteDoc (struct stud_node*head,int num)
 {
 	struct stud_node *ptr1,*ptr2;
	int flag=1;
 	for(;head!=NULL&&head->num==num;){        /*�ѽ�while����Ϊfor���*/
 		ptr2=head;
 		head=head->next;
 		free(ptr2);
	 }
	 if(head==NULL)//δ��������
	 return NULL;
	 //�����Ѵ�������Ҫɾ���Ĳ���ͷ�ڵ�
	 ptr1=head;
	 ptr2=head->next;
	 while(ptr2!=NULL){
	 	if(ptr2->num==num){
	 		ptr1->next=ptr2->next;
	 		free(ptr2);
			flag--;
			break;
		 }
		 else
		 ptr1=ptr2;
		 ptr2=ptr1->next;
	 }
	 if(flag){
		 printf("��Ҫɾ������Ϣ������");
	 }
	 return head;
 }
 /*��������*/
 void Print_Stu_Doc(struct stud_node * head)
 {
 	struct stud_node *ptr;
 	if(head==NULL){
 		printf("\nNo Records\n");
 		return;
	 }
	else
	printf("\n��У2019�����������¼ȡ�����ߣ�\n");
	printf("���\t ѧУ\t �Ŀ�¼ȡ����\t ���¼ȡ����\n");
	for(ptr=head;ptr!=NULL;ptr=ptr->next)
	printf("%d\t%s\t%d\t%d\n",ptr->num,ptr->school,ptr->fraction1,ptr->fraction2);
 }
