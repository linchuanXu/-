#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//int menu_return;
struct book *book_head = NULL;

typedef struct{//单本书结构体
	char number[100];
	char title[100];
	char author[100];
	char firm[100];
	int year;//分离存储年月日
	int month;
	int day;
	float price;
	int amount;
	int time;//借阅次数
	//int star;//未实现的标星
	struct book *next;
}book;



//************显示************
void print_line(book *now_book){//打印一本书的详细信息（地址）
    printf("%s %s %s %s %d %d %d %.1f %d %d\n",now_book->number,now_book->title,now_book->author,now_book->firm,now_book->year,now_book->month,now_book->day,now_book->price,now_book->amount,now_book->time);
}
void print_list(book **books){
    int i=0;
    if(books[i]==NULL) puts("\n无可展示结果");
    while(books[i])
        print_line(books[i++]);
}
book *print_8(book **books){//打印前八个，返回第九个的指针的地址**books//如果已打印完毕返回NULL
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


//************以下是数据库的链表的操作************
//搜索-遍历********逻辑：返回一个满足结果的 链表指针组 的 首地址//不同的搜索可以使用函数的指针来实现，但是为了合作
//做完逻辑总结：1初始化静态存储空间 2符合的结果写入链表指针组
static book *answer[]={NULL};
void answer_init(){//answer 初始化
    book **temp = answer;
    while(*temp){
        //puts("clean ");
        *temp=NULL;
        temp++;
    }
}
void I_want_know_whats_going_on(book **books){//一个检查静态变量情况的函数-无用于程序本身
    book **temp = books;
    printf("\t answer=%d \t",books);
    while(*temp){
        printf("& %d  ",*temp);
        temp++;
    }
}
book** search_title(book *books,char title[]){//title的部分搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->title,title)){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//我到底返回了什么：answer是指针的指针首地址
}
book** search_two_title(book *books,char title1[],char title2[]){//title的部分搜索
    answer_init();
    book *temp = books;
    int count=0;
    while(temp){
        if(strstr(temp->title,title1) && strstr(temp->title,title2)){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
    }
    return answer;
}


book** search_author(book *books,char author[]){//author搜索
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
book** search_firm(book *books,char firm[]){//firm搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->firm,firm)){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//返回地址集合的首地址的地址
}
book** search_year(book *books,int year){//year的搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->year==year){
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//返回地址集合的首地址的地址
}
book** search_year_month(book *books,int year,int month){//year month 的搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->year==year && temp->month == month){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//返回地址集合的首地址的地址
}
book** search_number(book *books,char number[]){//number搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(strstr(temp->number,number)){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//返回地址集合的首地址的地址
}
book** search_year_month_day(book *books,int year,int month,int day){//year month day的搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->year==year && temp->month == month && temp->day==day){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//返回地址集合的首地址的地址
}

book** search_amount(book *books,int amount){//amount的搜索
    answer_init();
    book *temp = books;
    int count=0;
	while(temp){
        if(temp->amount == amount){//如果第二个是第一个的子串
            answer[count++] = temp;
        }
        temp = temp->next;
	}
	return answer;//返回地址集合的首地址的地址
}
//1以上为思考不够细致导致的无用功：输入参数为链表，但是结果确是一个链表的指针组
//1虽然在编程过程中感觉链表不是一个较好的处理对象，但是不统一数据结构：具体是不对于存储和排序筛选处理的数据结构进行分别处理和规范思路，会导致极大的代码重复
//1为了解决这个失误：有两种方法：全部重写：在查找的最开始就进行指针组的优化//或者增加一个指针组变成新链表的代码的时间复杂度和具体的执行步骤还有思路就大大饶了弯路，但是在走了很多路之后，只能这样打补丁弥补大型项目的蓝图不够清晰的错误
//2命名静态空间作为搜索结果 导致第二次搜索失败，所以搜索之前要进行静态空间的初始化操作,但是在debug的过程中发现：两个函数 同样的静态变量 重新定义 会导致静态空间的偏移 大概在负8-正12个字节的情况，所以我将其提取出来 放到全局里，但是在使用之前还是要进行初始化操作
book* find_last(){//找到最后一个节点
    book *last = book_head;
    while(last->next != NULL) last = last->next;
    return last;
}
book** get_all_books(){//按数据库顺序得到所有书籍
    answer_init();
    book *temp = book_head;
    int i;
    for(i=0;temp;i++,temp = temp->next)
        answer[i]=temp;
    return answer;
}
int get_count(){ //得到书籍数量
    book **temp = get_all_books();
    int i = 0;
    while(*(temp + i))
        i++;
    return i;
}
//****************排序 并且放入answer中
book** sort_title(){//title
    get_all_books();//得到所有书籍 并且 存入全局变量answer
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
    get_all_books();//得到所有书籍 并且 存入全局变量answer
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
book** sort_year_month_day(){//排序顺序year month day
    get_all_books();//得到所有书籍 并且 存入全局变量answer
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


//************建立-添加
book* creat_new_book(book *last){//已知最后节点建立
    if(last==NULL){
        book_head = (book *) malloc( sizeof(book) );
        return book_head;
    }
    last->next = (book *) malloc( sizeof(book) );
    return last->next;
}
book* creat_new_book_first(){//自动寻找最后的节点并且建立
    book *last = find_last();
    return creat_new_book(last);

}
book* creat_head_book(){//建立第一本书
    return creat_new_book(book_head);
}
void add_newbook(){//从控制台中添加一本新书
    book *new_book = creat_new_book_first();
    scanf("%s%s%s%s%d%d%d%f%d%d",&new_book->number,&new_book->title,&new_book->author,&new_book->firm,&new_book->year,&new_book->month,&new_book->day,&new_book->price,&new_book->amount,&new_book->time);
}


int delete_book(book* temp){//凭借结构体指针 删除一本书
    if(book_head == temp){//第一个查找是特例
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
void delete_books(book **books){//凭借结构体指针集的首个指针的地址 删除多本书
    if(!*books) puts("删除失败 没有此书");
    while(*books){
        delete_book(*books);
        books++;
    }
}
void delete_lost_books(){//删除遗失书籍
    //删除书籍：所有amount为0的书
    delete_books(search_amount(book_head,0));
}
//************数据库操作************
//读取数据从文件
void data_read(char path[]){//这是一个通用的从文件读入数据函数，适用于第一次 和 以后的多次 从文件添加入数据库
    //读取文件
    FILE *data;
    data = fopen(path,"r");
    if(data==NULL) printf("data==NULL");
    //建立or添加链表
    book *new_book,*last_book;
    if(book_head==NULL) new_book = creat_head_book();//如果数据库为空
    else new_book = creat_new_book_first();//自动寻找最后的节点并且建立
    while(1){//判断是否读取到最后一行的同时 将数据读入↓
    if(fscanf(data,"%s%s%s%s%d%d%d%f%d%d\n",&new_book->number,&new_book->title,&new_book->author,&new_book->firm,&new_book->year,&new_book->month,&new_book->day,&new_book->price,&new_book->amount,&new_book->time) == EOF) break;
        //printf("new_book: %s : %d \n",new_book->title,new_book);
    last_book = new_book;//记录最后的节点//用于结束
    new_book = creat_new_book(new_book);
    }
    last_book->next = NULL;//最后一个节点的结束
    free(new_book);//释放多余节点
    fclose(data);//关闭文件
}
void data_write(char path[]){//数据库导出
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
//第一次初始化读取数据库
void data_read_first(){
    data_read("bookdata.txt");
    printf("*********************// 已载入数据库 //***********************\n");
}

//初始化//读入文件 初始化数据库
void init(){
    data_read_first();

}

//************菜单******************************************
//返回的话跳出程序（本菜单，不然一直执行下去
//菜单的逻辑思考了很久，当执行完一个操作到底是进入主菜单还是上一个菜单呢，我选择上一个菜单
//同时为了契合 反应器+菜单 的结构
//?????????就形成了while循环（反应器（菜单））的三种契合结构?????????????
//值得一提的是这个反应器是bool类型的 但是在c语言中是不支持的，可以自定义一个类型类似bool，本程序int解决
int get_return_int(int min,int max){//输入上限下限，从键盘流里得到一个合适的int结果
    char return_c;
    int n ;
    while(1){
        return_c = getche();
        n = return_c - '0';
        if(n<=max && n>=min) return n;
        else puts("\tplease try again.");
    }
}

//********************二级页面change
void menu_change_delete_lost(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("****************删除书籍 已遗失*********************");
    delete_books(search_amount(book_head,0));
    puts("****************删除完成****************************");
    puts("请按任意键返回上一级菜单");
    getche();
}
void menu_change_record_lost_number(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("****************登记丢失书籍 从书号*****************");
    printf("请输入丢失的书籍的书号：");
    char number[100];
    scanf("%s",number);
    book** losts = search_number(book_head,number);
    while(*losts){
        (*losts)->amount--;
        printf("《%s》当前数量：%d - 1 = %d\n",(*losts)->title,(*losts)->amount+1,(*losts)->amount);
        losts++;
    }
    puts("****************登记结束****************************");
    puts("请按任意键返回上一级菜单");
    getche();
}
void menu_change_output_file(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("****************输出书籍 到文件*********************");
    puts("\n图书数据将保存至程序根目录下output.txt\n按任意键开始输出数据");
    getche();
    data_write("output.txt");
    puts("****************输出完毕****************************");
    puts("请按任意键返回上一级菜单");
    getche();
}
void menu_change_delete_number(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("****************删除书籍 从书号*********************");
    printf("请输入想要删除的书籍的书号：");
    char number[100];
    scanf("%s",number);
    //printf("%d",*(search_number(book_head,number)));
    delete_books(search_number(book_head,number));
    puts("请按任意键返回上一级菜单");
    getche();
}
void menu_change_add_keyboard(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("****************添加书籍 从键盘*********************");
    puts("请依次输入：书号、书名、作者、出版社、出版年、月、日、单价、数量、借阅次数");
    add_newbook();
    printf("add new book :%s",find_last()->title);
    puts("请按任意键返回上一级菜单");
    getche();
}
void menu_change_add_books_file(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("****************添加书籍 从文件*********************");
    puts("\n请将图书数据保存至程序根目录下new_books.txt\n按任意键开始加载数据");
    getche();
    book *last = find_last();
    data_read("new_books.txt");
    last = last->next;
    while(last){
        printf("add new book:%s\n",last->title);
        last = last->next;
    }
    puts("****************读取完毕****************************");
    puts("请按任意键返回上一级菜单");
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
    puts("************小型图书管理系统************************");
    puts("****************更改书库****************************");
    puts("**************1 添加书籍（从文件）******************");
    puts("**************2 添加书籍（从键盘）******************");
    puts("**************3 删除书籍（书号）********************");
    puts("**************4 输出书籍（到文件）******************");
    puts("**************5 书籍遗失登记************************");
    puts("**************6 自动删除遗失书籍********************");
    puts("**************0 返回上一级菜单**********************");
    return get_return_int(0,6);
}
//********************二级页面browse
void menu_browse_time(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************书籍浏览***************************");
    book** list = print_8(sort_time());
    while(list){
        puts("\n按任意键进入下一页");
        getche();
        system("cls");
        puts("************小型图书管理系统************************");
        puts("****************书籍浏览***************************");
        list = print_8(list);
    }
    puts("\n********浏览完毕********\n********按任意键返回上一菜单********");
    getche();
}
void menu_browse_year_month_day(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************书籍浏览***************************");
    book** list = print_8(sort_year_month_day());
    while(list){
        puts("\n按任意键进入下一页");
        getche();
        system("cls");
        puts("************小型图书管理系统************************");
        puts("****************书籍浏览***************************");
        list = print_8(list);
    }
    puts("\n********浏览完毕********\n********按任意键返回上一菜单********");
    getche();
}
void menu_browse_title(){
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************书籍浏览***************************");
    book** list = print_8(sort_title());
    while(list){
        puts("\n按任意键进入下一页");
        getche();
        system("cls");
        puts("************小型图书管理系统************************");
        puts("****************书籍浏览***************************");
        list = print_8(list);
    }
    puts("\n********浏览完毕********\n********按任意键返回上一菜单********");
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
    puts("************小型图书管理系统************************");
    puts("****************书籍浏览****************************");
    puts("**************1 书名顺序****************************");
    puts("**************2 出版时间顺序************************");
    puts("**************3 借阅次数排序************************");
    puts("**************0 返回上一级菜单**********************");
    return get_return_int(0,3);
}
//********************二级页面search
void menu_search_number(){//这是一个超过二级的子页面，不设置反应器，void单步操作
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍书号：");
    char number[999];
    scanf("%s",number);
    print_list(search_number(book_head,number));
    puts("\n按任意键返回上一菜单");
    getche();
}
void menu_search_title1(){
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍名称：");
    char title[999];
    scanf("%s",title);
    print_list(search_title(book_head,title));
    puts("\n按任意键返回上一菜单");
    getche();
}
void menu_search_title2(){
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍名称的两个关键词：");
    char title1[999],title2[999];
    scanf("%s%s",title1,title2);
    print_list(search_two_title(book_head,title1,title2));
    puts("\n按任意键返回上一菜单");
    getche();
}
void menu_search_author(){
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍作者：");
    char author[999];
    scanf("%s",author);
    print_list(search_author(book_head,author));
    puts("\n按任意键返回上一菜单");
    getche();
}
void menu_search_year(){
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍的年份：");
    int year;
    scanf("%d",&year);
    print_list(search_year(book_head,year));
    puts("\n按任意键返回上一菜单");
    getche();
}
void menu_search_year_month(){
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍的年份 月份：");
    int year,month;
    scanf("%d%d",&year,&month);
    print_list(search_year_month(book_head,year,month));
    puts("\n按任意键返回上一菜单");
    getche();
}
void menu_search_year_month_day(){
    system("cls");
    puts("************小型图书管理系统************************\n");
    puts("****************书籍查询****************************");
    printf("请输入查询的书籍的年份 月份 日期：");
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    print_list(search_year_month_day(book_head,year,month,day));
    puts("\n按任意键返回上一菜单");
    getche();
}
int menu_react_search(int r){//search反应器
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
int menu_search(){//search页面
    system("cls");
    puts("************小型图书管理系统************************");
    puts("****************书籍查询****************************");
    puts("**************1 书号查询****************************");
    puts("**************2 书名查询（单关键词）****************");
    puts("**************3 书名查询（双关键词）****************");
    puts("**************4 作者查询****************************");
    puts("**************5 出版年查询**************************");
    puts("**************6 出版年月查询************************");
    puts("**************7 出版年月日查询**********************");
    puts("**************0 返回上一级菜单**********************");

    return get_return_int(0,7);
}

//********************一级页面index
int menu_react_index(int r){
    //索引的反应器为了正常对于index的循环 需要返回正常1 or 退出0
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
    puts("************小型图书管理系统************");
    puts("**************1 书籍查询****************");//多种关键词搜索
    puts("**************2 书籍浏览****************");//多种顺序-8
    puts("**************3 更改书库****************");//添加删除修改
    puts("**************0 退出程序****************");//

    return get_return_int(0,3);
}

int main() {

	init();
    while( menu_react_index( menu_index() ) );
    puts("\t程序已退出");

    //思考了很久，最后对于一个菜单的逻辑是：一个菜单 = 一个打印函数+一个处理器函数
    //我也不是非常清楚这样做的理由
    //仅仅找到了一个网上不太类似的菜单源码
    //虽然完全可以整合到一起去，制作一个漫长的菜单流程，但是我还是分开细节做了 菜单函数 和 返回值处理函数
    //这个结构大概在扩充延展的时候会比较好，也更加容易理解，结构清晰
	return 0;
}

