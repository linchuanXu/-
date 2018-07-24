#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//int menu_return;
struct book *book_head = NULL;

typedef struct{//������ṹ��
	char number[100];
	char title[100];
	char author[100];
	char firm[100];
	int year;//����洢������
	int month;
	int day;
	float price;
	int amount;
	int time;//���Ĵ���
	//int star;//δʵ�ֵı���
	struct book *next;
}book;



//************��ʾ************
void print_line(book *now_book){//��ӡһ�������ϸ��Ϣ����ַ��
    printf("%s %s %s %s %d %d %d %.1f %d %d\n",now_book->number,now_book->title,now_book->author,now_book->firm,now_book->year,now_book->month,now_book->day,now_book->price,now_book->amount,now_book->time);
}
void print_list(book **books){
    int i=0;
    if(books[i]==NULL) puts("\n�޿�չʾ���");
    while(books[i])
        print_line(books[i++]);
}
book *print_8(book **books){//��ӡǰ�˸������صھŸ���ָ��ĵ�ַ**books//����Ѵ�ӡ��Ϸ���NULL
    int i;
    for(i=0;i<8;i++){
        if(*books==NULL)return NULL;
        print_line(*books);
        books++;
    }
    //printf("books:%d\n",*books);
    return books;

}
void print_book_number(){
    int i=0;
    book *temp = book_head;
    while(temp){
        i++;
        temp = temp->next;
    }
    printf("there are %d books\n\n",i);
}


//************���������ݿ������Ĳ���************
//����-����********�߼�������һ���������� ����ָ���� �� �׵�ַ//��ͬ����������ʹ�ú�����ָ����ʵ�֣�����Ϊ�˺���
//�����߼��ܽ᣺1��ʼ����̬�洢�ռ� 2���ϵĽ��д������ָ����
static book *answer[]={NULL};
void answer_init(){//answer ��ʼ��
    book **temp = answer;
    while(*temp){
        //puts("clean ");
        *temp=NULL;
        temp++;
    }
}
void I_want_know_whats_going_on(book **books){//һ����龲̬��������ĺ���-�����ڳ�����
    book **temp = books;
    printf("\t answer=%d \t",books);
    while(*temp){
        printf("& %d  ",*temp);
        temp++;
    }
}
book** search_title(book *books,char title[]){//title�Ĳ�������
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->title,title)){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//�ҵ��׷�����ʲô��answer��ָ���ָ���׵�ַ
}
book** search_two_title(book *books,char title1[],char title2[]){//title�Ĳ�������
    answer_init();
    book *temp = books;
    int count=0;
    while(temp){
        if(strstr(temp->title,title1) && strstr(temp->title,title2)){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
    }
    return answer;
}


book** search_author(book *books,char author[]){//author����
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->author,author)){
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;
}
book** search_firm(book *books,char firm[]){//firm����
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->firm,firm)){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//���ص�ַ���ϵ��׵�ַ�ĵ�ַ
}
book** search_year(book *books,int year){//year������
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->year==year){
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//���ص�ַ���ϵ��׵�ַ�ĵ�ַ
}
book** search_year_month(book *books,int year,int month){//year month ������
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->year==year && temp->month == month){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//���ص�ַ���ϵ��׵�ַ�ĵ�ַ
}
book** search_number(book *books,char number[]){//number����
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->number,number)){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//���ص�ַ���ϵ��׵�ַ�ĵ�ַ
}
book** search_year_month_day(book *books,int year,int month,int day){//year month day������
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->year==year && temp->month == month && temp->day==day){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//���ص�ַ���ϵ��׵�ַ�ĵ�ַ
}

book** search_amount(book *books,int amount){//amount������
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->amount == amount){//����ڶ����ǵ�һ�����Ӵ�
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//���ص�ַ���ϵ��׵�ַ�ĵ�ַ
}
//1����Ϊ˼������ϸ�µ��µ����ù����������Ϊ�������ǽ��ȷ��һ�������ָ����
//1��Ȼ�ڱ�̹����ио�������һ���ϺõĴ�����󣬵��ǲ�ͳһ���ݽṹ�������ǲ����ڴ洢������ɸѡ��������ݽṹ���зֱ���͹淶˼·���ᵼ�¼���Ĵ����ظ�
//1Ϊ�˽�����ʧ�������ַ�����ȫ����д���ڲ��ҵ��ʼ�ͽ���ָ������Ż�//��������һ��ָ������������Ĵ����ʱ�临�ӶȺ;����ִ�в��軹��˼·�ʹ��������·�����������˺ܶ�·֮��ֻ�������򲹶��ֲ�������Ŀ����ͼ���������Ĵ���
//2������̬�ռ���Ϊ������� ���µڶ�������ʧ�ܣ���������֮ǰҪ���о�̬�ռ�ĳ�ʼ������,������debug�Ĺ����з��֣��������� ͬ���ľ�̬���� ���¶��� �ᵼ�¾�̬�ռ��ƫ�� ����ڸ�8-��12���ֽڵ�����������ҽ�����ȡ���� �ŵ�ȫ���������ʹ��֮ǰ����Ҫ���г�ʼ������
book* find_last(){//�ҵ����һ���ڵ�
    book *last = book_head;
    while(last->next != NULL) last = last->next;
    return last;
}
book** get_all_books(){//�����ݿ�˳��õ������鼮
    answer_init();
    book *temp = book_head;
    int i;
    for(i=0;temp;i++,temp = temp->next)
        answer[i]=temp;
    return answer;
}
int get_count(){ //�õ��鼮����
    book **temp = get_all_books();
    int i = 0;
    while(*(temp + i))
        i++;
    return i;
}
//****************���� ���ҷ���answer��
book** sort_title(){//title
    get_all_books();//�õ������鼮 ���� ����ȫ�ֱ���answer
    book *temp = NULL;
    int i,j;
    int N = get_count();
    for(i=0;i<=N-2;i++){
        for(j=0;j<=N-2-i;j++){
            if(strcmp(answer[j]->title,answer[j+1]->title)==1){
                temp = answer[j];
                answer[j] = answer[j+1];
                answer[j+1] = temp;
            }
        }
    }
    return answer;
}
book** sort_time(){//time
    get_all_books();//�õ������鼮 ���� ����ȫ�ֱ���answer
    book *temp = NULL;
    int i,j;
    int N = get_count();
    for(i=0;i<=N-2;i++){
        for(j=0;j<=N-2-i;j++){
            if(answer[j]->time < answer[j+1]->time){
                temp = answer[j];
                answer[j] = answer[j+1];
                answer[j+1] = temp;
            }
        }
    }
    return answer;
}
book** sort_year_month_day(){//����˳��year month day
    get_all_books();//�õ������鼮 ���� ����ȫ�ֱ���answer
    book *temp = NULL;
    int i,j;
    int N = get_count();
    for(i=0;i<=N-2;i++){
        for(j=0;j<=N-2-i;j++){
            if(answer[j]->year*10000+answer[j]->month*100+answer[j]->day    <   answer[j+1]->year*10000+answer[j+1]->month*100+answer[j+1]->day){
                temp = answer[j];
                answer[j] = answer[j+1];
                answer[j+1] = temp;
            }
        }
    }
    return answer;
}


//************����-���
book* creat_new_book(book *last){//��֪���ڵ㽨��
    if(last==NULL){
        book_head = (book *) malloc( sizeof(book) );
        return book_head;
    }
    last->next = (book *) malloc( sizeof(book) );
    return last->next;
}
book* creat_new_book_first(){//�Զ�Ѱ�����Ľڵ㲢�ҽ���
    book *last = find_last();
    return creat_new_book(last);

}
book* creat_head_book(){//������һ����
    return creat_new_book(book_head);
}
void add_newbook(){//�ӿ���̨�����һ������
    book *new_book = creat_new_book_first();
    scanf("%s%s%s%s%d%d%d%f%d%d",&new_book->number,&new_book->title,&new_book->author,&new_book->firm,&new_book->year,&new_book->month,&new_book->day,&new_book->price,&new_book->amount,&new_book->time);
}


int delete_book(book* temp){//ƾ��ṹ��ָ�� ɾ��һ����
    if(book_head == temp){//��һ������������
        book_head = temp->next;
        printf("delete book : %s\n",temp->title);
        free(temp);
        return 1;
    }

    book *before = book_head;
    while( before->next != temp && before != NULL)
        before = before->next;
    if(before->next != temp){
        puts("no answer");
        return 0;
    }
    before->next = temp->next;
    printf("delete book : %s\n",temp->title);
    free(temp);
    return 1;
}
void delete_books(book **books){//ƾ��ṹ��ָ�뼯���׸�ָ��ĵ�ַ ɾ���౾��
    if(!*books) puts("ɾ��ʧ�� û�д���");
    while(*books){
        delete_book(*books);
        books++;
    }
}
void delete_lost_books(){//ɾ����ʧ�鼮
    //ɾ���鼮������amountΪ0����
    delete_books(search_amount(book_head,0));
}
//************���ݿ����************
//��ȡ���ݴ��ļ�
void data_read(char path[]){//����һ��ͨ�õĴ��ļ��������ݺ����������ڵ�һ�� �� �Ժ�Ķ�� ���ļ���������ݿ�
    //��ȡ�ļ�
    FILE *data;
    data = fopen(path,"r");
    if(data==NULL) printf("data==NULL");
    //����or�������
    book *new_book,*last_book;
    if(book_head==NULL) new_book = creat_head_book();//������ݿ�Ϊ��
    else new_book = creat_new_book_first();//�Զ�Ѱ�����Ľڵ㲢�ҽ���
    while(1){//�ж��Ƿ��ȡ�����һ�е�ͬʱ �����ݶ����
    if(fscanf(data,"%s%s%s%s%d%d%d%f%d%d\n",&new_book->number,&new_book->title,&new_book->author,&new_book->firm,&new_book->year,&new_book->month,&new_book->day,&new_book->price,&new_book->amount,&new_book->time) == EOF) break;
        //printf("new_book: %s : %d \n",new_book->title,new_book);
    last_book = new_book;//��¼���Ľڵ�//���ڽ���
    new_book = creat_new_book(new_book);
    }
    last_book->next = NULL;//���һ���ڵ�Ľ���
    free(new_book);//�ͷŶ���ڵ�
    fclose(data);//�ر��ļ�
}
void data_write(char path[]){//���ݿ⵼��
    int i=1;
    FILE *data;
    data = fopen(path,"w+");
    //printf("%s:%d\n",path,data);
    book *temp = book_head;
    while(temp){
        i = fprintf(data,"%s %s %s %s %d %d %d %.1f %d %d\n",temp->number,temp->title,temp->author,temp->firm,temp->year,temp->month,temp->day,temp->price,temp->amount,temp->time);
        printf("write book:%s\n",temp->title);
        temp = temp->next;
    }
    fclose(data);
}
//��һ�γ�ʼ����ȡ���ݿ�
void data_read_first(){
    data_read("bookdata.txt");
    printf("*********************// ���������ݿ� //***********************\n");
}

//��ʼ��//�����ļ� ��ʼ�����ݿ�
void init(){
    data_read_first();

}

//************�˵�******************************************
//���صĻ��������򣨱��˵�����Ȼһֱִ����ȥ
//�˵����߼�˼���˺ܾã���ִ����һ�����������ǽ������˵�������һ���˵��أ���ѡ����һ���˵�
//ͬʱΪ������ ��Ӧ��+�˵� �Ľṹ
//?????????���γ���whileѭ������Ӧ�����˵��������������Ͻṹ?????????????
//ֵ��һ����������Ӧ����bool���͵� ������c�������ǲ�֧�ֵģ������Զ���һ����������bool��������int���
int get_return_int(int min,int max){//�����������ޣ��Ӽ�������õ�һ�����ʵ�int���
    char return_c;
    int n ;
    while(1){
        return_c = getche();
        n = return_c - '0';
        if(n<=max && n>=min) return n;
        else puts("\tplease try again.");
    }
}

//********************����ҳ��change
void menu_change_delete_lost(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("****************ɾ���鼮 ����ʧ*********************");
    delete_books(search_amount(book_head,0));
    puts("****************ɾ�����****************************");
    puts("�밴�����������һ���˵�");
    getche();
}
void menu_change_record_lost_number(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("****************�ǼǶ�ʧ�鼮 �����*****************");
    printf("�����붪ʧ���鼮����ţ�");
    char number[100];
    scanf("%s",number);
    book** losts = search_number(book_head,number);
    while(*losts){
        (*losts)->amount--;
        printf("��%s����ǰ������%d - 1 = %d\n",(*losts)->title,(*losts)->amount+1,(*losts)->amount);
        losts++;
    }
    puts("****************�Ǽǽ���****************************");
    puts("�밴�����������һ���˵�");
    getche();
}
void menu_change_output_file(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("****************����鼮 ���ļ�*********************");
    puts("\nͼ�����ݽ������������Ŀ¼��output.txt\n���������ʼ�������");
    getche();
    data_write("output.txt");
    puts("****************������****************************");
    puts("�밴�����������һ���˵�");
    getche();
}
void menu_change_delete_number(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("****************ɾ���鼮 �����*********************");
    printf("��������Ҫɾ�����鼮����ţ�");
    char number[100];
    scanf("%s",number);
    //printf("%d",*(search_number(book_head,number)));
    delete_books(search_number(book_head,number));
    puts("�밴�����������һ���˵�");
    getche();
}
void menu_change_add_keyboard(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("****************����鼮 �Ӽ���*********************");
    puts("���������룺��š����������ߡ������硢�����ꡢ�¡��ա����ۡ����������Ĵ���");
    add_newbook();
    printf("add new book :%s",find_last()->title);
    puts("�밴�����������һ���˵�");
    getche();
}
void menu_change_add_books_file(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("****************����鼮 ���ļ�*********************");
    puts("\n�뽫ͼ�����ݱ����������Ŀ¼��new_books.txt\n���������ʼ��������");
    getche();
    book *last = find_last();
    data_read("new_books.txt");
    last = last->next;
    while(last){
        printf("add new book:%s\n",last->title);
        last = last->next;
    }
    puts("****************��ȡ���****************************");
    puts("�밴�����������һ���˵�");
    getche();
}
int menu_react_change(int r){
    switch(r){
        case 0:return 0;break;
        case 1:menu_change_add_books_file();break;
        case 2:menu_change_add_keyboard();break;
        case 3:menu_change_delete_number();break;
        case 4:menu_change_output_file();break;
        case 5:menu_change_record_lost_number();break;
        case 6:menu_change_delete_lost();break;
    }
    return 1;
}
int menu_change(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�������****************************");
    puts("**************1 ����鼮�����ļ���******************");
    puts("**************2 ����鼮���Ӽ��̣�******************");
    puts("**************3 ɾ���鼮����ţ�********************");
    puts("**************4 ����鼮�����ļ���******************");
    puts("**************5 �鼮��ʧ�Ǽ�************************");
    puts("**************6 �Զ�ɾ����ʧ�鼮********************");
    puts("**************0 ������һ���˵�**********************");
    return get_return_int(0,6);
}
//********************����ҳ��browse
void menu_browse_time(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�鼮���***************************");
    book** list = print_8(sort_time());
    while(list){
        puts("\n�������������һҳ");
        getche();
        system("cls");
        puts("************С��ͼ�����ϵͳ************************");
        puts("****************�鼮���***************************");
        list = print_8(list);
    }
    puts("\n********������********\n********�������������һ�˵�********");
    getche();
}
void menu_browse_year_month_day(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�鼮���***************************");
    book** list = print_8(sort_year_month_day());
    while(list){
        puts("\n�������������һҳ");
        getche();
        system("cls");
        puts("************С��ͼ�����ϵͳ************************");
        puts("****************�鼮���***************************");
        list = print_8(list);
    }
    puts("\n********������********\n********�������������һ�˵�********");
    getche();
}
void menu_browse_title(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�鼮���***************************");
    book** list = print_8(sort_title());
    while(list){
        puts("\n�������������һҳ");
        getche();
        system("cls");
        puts("************С��ͼ�����ϵͳ************************");
        puts("****************�鼮���***************************");
        list = print_8(list);
    }
    puts("\n********������********\n********�������������һ�˵�********");
    getche();
}
int menu_react_browse(int r){
    switch(r){
        case 0:return 0;break;
        case 1:menu_browse_title();break;
        case 2:menu_browse_year_month_day();break;
        case 3:menu_browse_time();break;
    }
    return 1;
}
int menu_browse(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�鼮���****************************");
    puts("**************1 ����˳��****************************");
    puts("**************2 ����ʱ��˳��************************");
    puts("**************3 ���Ĵ�������************************");
    puts("**************0 ������һ���˵�**********************");
    return get_return_int(0,3);
}
//********************����ҳ��search
void menu_search_number(){//����һ��������������ҳ�棬�����÷�Ӧ����void��������
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮��ţ�");
    char number[999];
    scanf("%s",number);
    print_list(search_number(book_head,number));
    puts("\n�������������һ�˵�");
    getche();
}
void menu_search_title1(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮���ƣ�");
    char title[999];
    scanf("%s",title);
    print_list(search_title(book_head,title));
    puts("\n�������������һ�˵�");
    getche();
}
void menu_search_title2(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮���Ƶ������ؼ��ʣ�");
    char title1[999],title2[999];
    scanf("%s%s",title1,title2);
    print_list(search_two_title(book_head,title1,title2));
    puts("\n�������������һ�˵�");
    getche();
}
void menu_search_author(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮���ߣ�");
    char author[999];
    scanf("%s",author);
    print_list(search_author(book_head,author));
    puts("\n�������������һ�˵�");
    getche();
}
void menu_search_year(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮����ݣ�");
    int year;
    scanf("%d",&year);
    print_list(search_year(book_head,year));
    puts("\n�������������һ�˵�");
    getche();
}
void menu_search_year_month(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮����� �·ݣ�");
    int year,month;
    scanf("%d%d",&year,&month);
    print_list(search_year_month(book_head,year,month));
    puts("\n�������������һ�˵�");
    getche();
}
void menu_search_year_month_day(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************************\n");
    puts("****************�鼮��ѯ****************************");
    printf("�������ѯ���鼮����� �·� ���ڣ�");
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    print_list(search_year_month_day(book_head,year,month,day));
    puts("\n�������������һ�˵�");
    getche();
}
int menu_react_search(int r){//search��Ӧ��
    switch(r){
    case 0:return 0;break;
    case 1:menu_search_number();break;
    case 2:menu_search_title1();break;
    case 3:menu_search_title2();break;
    case 4:menu_search_author();break;
    case 5:menu_search_year();break;
    case 6:menu_search_year_month();break;
    case 7:menu_search_year_month_day();break;
    }
    return 1;
}
int menu_search(){//searchҳ��
    system("cls");
    puts("************С��ͼ�����ϵͳ************************");
    puts("****************�鼮��ѯ****************************");
    puts("**************1 ��Ų�ѯ****************************");
    puts("**************2 ������ѯ�����ؼ��ʣ�****************");
    puts("**************3 ������ѯ��˫�ؼ��ʣ�****************");
    puts("**************4 ���߲�ѯ****************************");
    puts("**************5 �������ѯ**************************");
    puts("**************6 �������²�ѯ************************");
    puts("**************7 ���������ղ�ѯ**********************");
    puts("**************0 ������һ���˵�**********************");

    return get_return_int(0,7);
}

//********************һ��ҳ��index
int menu_react_index(int r){
    //�����ķ�Ӧ��Ϊ����������index��ѭ�� ��Ҫ��������1 or �˳�0
    switch (r){
    case 0:return 0;break;
    case 1:while(menu_react_search(menu_search()));break;
    case 2:while(menu_react_browse(menu_browse()));break;
    case 3:while(menu_react_change(menu_change()));break;
    }
    return 1;
}
int menu_index(){
    system("cls");
    puts("************С��ͼ�����ϵͳ************");
    puts("**************1 �鼮��ѯ****************");//���ֹؼ�������
    puts("**************2 �鼮���****************");//����˳��-8
    puts("**************3 �������****************");//���ɾ���޸�
    puts("**************0 �˳�����****************");//

    return get_return_int(0,3);
}

int main() {

	init();
    while( menu_react_index( menu_index() ) );
    puts("\t�������˳�");

    //˼���˺ܾã�������һ���˵����߼��ǣ�һ���˵� = һ����ӡ����+һ������������
    //��Ҳ���Ƿǳ����������������
    //�����ҵ���һ�����ϲ�̫���ƵĲ˵�Դ��
    //��Ȼ��ȫ�������ϵ�һ��ȥ������һ�������Ĳ˵����̣������һ��Ƿֿ�ϸ������ �˵����� �� ����ֵ������
    //����ṹ�����������չ��ʱ���ȽϺã�Ҳ����������⣬�ṹ����
	return 0;
}

