#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adddishes.h"
#include "history.h"
#include "recommend.h"
#include "set.h"
#include "ui_recommend.h"
#include <fstream>
#pragma execution_character_set(“GBK”)
#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<iterator>
#include <fstream>
#include <cstring>
#include <queue>
#include <QDebug>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    adddishes *new_add;
    history *new_his;
    recommend *new_rec;
    set *new_set;

private slots:
    void on_addbutton_clicked();

    void on_historybutton_clicked();

    void on_setbutton_clicked();

    void on_intrecbutton_clicked();

    void on_ranrecbutton_clicked();

private:
    Ui::MainWindow *ui;
};

class Food{
private:
    int number; //编号
    double fixed_weight;//固定权重//可理解为评分
    double change_weight;//临时更改的权重部分
    double ultimate_weight;//最终用于随机加权的权重
    char name[30];//菜名
    char canteen[30];//食堂
    char window[30];//窗口
    char type[20];//类别 1 素菜 2 荤菜 3 荤素混合 4 套餐
    double price;//价格
    int salt;//咸度
    int sweet;//甜度
    int spicy;//辣度
    int calorie;//能量
    int grease;//油脂类
    int protein;//蛋白质
    int cellulose;//纤维素
public:
    void setnumber(int n){
        number=n;
    }
    int getnumber(){
        return number;
    }
    void settype(string n){//荤素半套
        strcpy(type,n.c_str());
    }
    string gettype(){
        return (string)type;
    }
    void setname(string n){
        strcpy(name,n.c_str());
    }
    string getname(){
        return (string)name;
    }
    void setcanteen(string n){
        strcpy(canteen, n.c_str());
    }
    string getcanteen(){
        return (string)canteen;
    }
    int canteen_int(){
         string str = canteen;
      if(str == "家园"){
       return 1;
      }
      else if(str == "燕南"){
       return 1<<1;
      }
      else if(str == "学一"){
       return 1<<2;
      }
      else if(str == "农园"){
       return 1<<3;
      }
      else if(str == "学五"){
       return 1<<4;
      }
      else{//勺园
       return 1<<5;
      }
     }
    void setprice(double n){
        price=n;
    }
    double getprice(){
        return price;
    }
    string getwindow(){
        return (string)window;
    }
    void setwindow(string n){
        strcpy(window, n.c_str());
    }
    void set_fixed_weight(double n){
        fixed_weight=(n-50)/50;
    }
    double get_fixed_weight(){
        return fixed_weight;
    }
    void set_change_weight(double n){
        change_weight=n;
    }
    double get_change_weight(){
        return change_weight;
    }
    void set_ultimate_weight(double n){
        ultimate_weight=n;
    }
    int get_ultimate_weight(){
        ultimate_weight=(fixed_weight+change_weight)/2;
        return int(1000*ultimate_weight);
    }
    void setsalt(int n){
        salt=n;
    }
    int getsalt(){
        return salt;
    }
    void setsweet(int n){
        sweet=n;
    }
    int getsweet(){
        return sweet;
    }
    void setspicy(int n){
        spicy=n;
    }
    int getspicy(){
        return spicy;
    }
    void setcalorie(int n){
        calorie=n;
    }
    int getcalorie(){
        return calorie;
    }
    void setgrease(int n){
        grease=n;
    }
    int getgrease(){
        return grease;
    }
    void setprotein(int n){
        protein=n;
    }
    int getprotein(){
        return protein;
    }
    void setcellulose(int n){
        cellulose=n;
    }
    int getcellulose(){
        return cellulose;
    }
    friend bool operator <(Food a,Food b){
        return a.getprice()<b.getprice();
    }
    Food():number(0),price(0),salt(0),sweet(0),spicy(0),
      calorie(0),grease(0),protein(0),
      cellulose(0),change_weight(0),fixed_weight(0),ultimate_weight(0){}
    Food(int num, string cname, string ccanteen, string cwindow, string ctype, double cprice,
        int csalt, int csweet, int cspicy, int ccalorie, int cgrease,
        int cprotein, int ccellulose):
        number(num),price(cprice),salt(csalt),sweet(csweet),spicy(cspicy),
        calorie(ccalorie),grease(cgrease),protein(cprotein),
        cellulose(ccellulose),change_weight(0),fixed_weight(0),ultimate_weight(0){
            strcpy(name, cname.c_str());
            strcpy(canteen, ccanteen.c_str());
            strcpy(window, cwindow.c_str());
            strcpy(type, ctype.c_str());
        }
    bool operator == (Food &cmp){
        return (string)name==cmp.getname() && (string)canteen == cmp.getcanteen();
    }
};//权重的初始值均为0

struct Dish_Package{
    Food *pSet_Meal[500]{NULL};
    int SMeal_num = 0;
    Food *pVeg_Diet[500]{NULL};
    int VegD_num = 0;
    Food *pMeat_Diet[500]{NULL};
    int MeatD_num = 0;
    Food *pVegnMeat_mix[500]{NULL};
    int VegMeat_num = 0;
};

inline void write_file(Food food,string s){//要读取或存入对应文件就直接把文件名赋值给s
    FILE* file=fopen(s.c_str(),"ab");
    if(file==NULL){
        //cout<<"file open defeat\n";
        return;
    }
    fwrite(&food,sizeof(Food),1,file);
    fclose(file);
}
inline Food read_file(int n,string s){
    FILE* file=fopen(s.c_str(),"rb");
    if(file==NULL){
        //cout<<"file open defeat\n";
        return Food();
    }
    fseek(file,sizeof(Food)*n,0);
    Food food;
    fread(&food,sizeof(Food),1,file);
    fclose(file);
    return food;
}
inline int get_food_num(string s){//获取当前读入菜品数量
    FILE* ffile=fopen(s.c_str(),"ab");
    fseek(ffile,0L,SEEK_END);
    int size=ftell(ffile);
    fclose(ffile);
    int N=size/sizeof(Food);
    return N;
}

inline int judge_repeat(Food food){
    string s = "Veg_Diet", h = "Meat_Diet", b = "VegnMeat_mix", t = "Set_Meal";
    FILE* file=fopen(s.c_str(),"rb");
       if(file==NULL){
           cout<<"file open defeat\n";
           return -1;
       }
       int tt = get_food_num(s);
       for(int i = 0; i < tt; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if(temp.getname() == food.getname() && temp.getcanteen()==food.getcanteen()) return temp.getnumber();
       }
       fclose(file);
    file=fopen(h.c_str(),"rb");
       if(file==NULL){
           cout<<"file open defeat\n";
           return -1;
       }
       tt = get_food_num(h);
       for(int i = 0; i < tt; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if(temp.getname() == food.getname() && temp.getcanteen()==food.getcanteen()) return temp.getnumber();
       }
       fclose(file);
    file=fopen(b.c_str(),"rb");
       if(file==NULL){
           cout<<"file open defeat\n";
           return -1;
       }
       tt = get_food_num(b);
       for(int i = 0; i < tt; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if(temp.getname() == food.getname() && temp.getcanteen()==food.getcanteen()) return temp.getnumber();
       }
       fclose(file);
    file=fopen(t.c_str(),"rb");
       if(file==NULL){
           cout<<"file open defeat\n";
           return -1;
       }
       tt = get_food_num(t);
       for(int i = 0; i < tt; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if(temp.getname() == food.getname() && temp.getcanteen()==food.getcanteen()) return temp.getnumber();
       }
       fclose(file);
       return -1;
   }

inline void add_reset_file(Food food){//要读取或存入对应文件就直接把文件名赋值给s//写在第n个Food的位置
    int n = judge_repeat(food);
    qDebug()<<n;
    //int n=-1;
    if(n == -1){
        food.setnumber(get_food_num(food.gettype()));
        write_file(food, food.gettype());
        return;
    }
    Food *f[1000]{NULL};
    FILE* file=fopen(food.gettype().c_str(),"rb");
    if(file==NULL){
        //cout<<"file open defeat\n";
        return;
    }
    int i=0;
    int tt = get_food_num(food.gettype());
    for(int j = 0; j < tt; ++j){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        f[i++] = new Food(temp);
    }
    fclose(file);
    food.setnumber(n);
    *f[n] = food;
    ofstream ofile(food.gettype().c_str(), ios::out | ios::binary);
    for(int j = 0; j < i; ++j){
        ofile.write((char*)(&(*f[j])), sizeof(Food));
    }
    ofile.close();
}

inline void read_all_file(Dish_Package &pack, int canteen){//读取所有选中食堂的菜进入pack
    if(canteen == 0) canteen = 63;
    string news = "Meat_Diet";
    FILE* file=fopen(news.c_str(),"rb");
    if(file==NULL){
        //cout<<"fille open defeat\n";
        return;
    }
    int t = get_food_num(news);
    for(int i = 0; i < t; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if((canteen&temp.canteen_int()) != 0) pack.pMeat_Diet[pack.MeatD_num++] = new Food(temp);
    }
    fclose(file);

    news = "Veg_Diet";
    file=fopen(news.c_str(),"rb");
    if(file==NULL){
        //cout<<"fille open defeat\n";
        return;
    }
    t = get_food_num(news);
    for(int i = 0; i < t; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if((canteen&temp.canteen_int()) != 0) pack.pVeg_Diet[pack.VegD_num++] = new Food(temp);
    }
    fclose(file);

    news = "Set_Meal";
    file=fopen(news.c_str(),"rb");
    if(file==NULL){
        //cout<<"fille open defeat\n";
        return;
    }
    t = get_food_num(news);
    for(int i = 0; i < t; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if((canteen&temp.canteen_int()) != 0) pack.pSet_Meal[pack.SMeal_num++] = new Food(temp);
    }
    fclose(file);

    news = "VegnMeat_mix";
    file=fopen(news.c_str(),"rb");
    if(file==NULL){
        //cout<<"fille open defeat\n";
        return;
    }
    t = get_food_num(news);
    for(int i = 0; i < t; ++i){
        Food temp;
        fread(&temp,sizeof(Food),1,file);
        if((canteen&temp.canteen_int()) != 0) pack.pVegnMeat_mix[pack.VegMeat_num++] = new Food(temp);
    }
    fclose(file);
}

inline Dish_Package Weighted_random(const Dish_Package &dish_selected){
    int *pSM_weight[500]{NULL}, *pVD_weight[500]{NULL}, *pMD_weight[500]{NULL}, *pVMm_weight[500]{NULL};
    bool picked[500];
    int SM_picknum = 3, VD_picknum = 3, MD_picknum = 3, VMm_picknum = 3;
    long long SM_wSum = 0, VD_wSum = 0, MD_wSum = 0, VMm_wSum = 0;
    Dish_Package answer;

    //SM--setMeal
    if(SM_picknum > dish_selected.SMeal_num) SM_picknum = dish_selected.SMeal_num; //renew picknum

    for(int i = 0; i < dish_selected.SMeal_num; ++i){
        pSM_weight[i] = new int(dish_selected.pSet_Meal[i]->get_ultimate_weight());
        SM_wSum += *pSM_weight[i];
    }
    memset(picked,false,sizeof(picked));
    srand((unsigned)time(NULL));
    for(int num = 0; num < SM_picknum; ++num){
        int b = rand();b = rand();
        int a = b % SM_wSum + 1;
        long long weight_preSum = 0;
        for(int i = 0; i < dish_selected.SMeal_num; ++i){
            weight_preSum += dish_selected.pSet_Meal[i]->get_ultimate_weight();
            if(weight_preSum >= a){
                if(!picked[i]){
                    picked[i] = true;
                    answer.pSet_Meal[answer.SMeal_num++] = dish_selected.pSet_Meal[i];
                }
                else ++SM_picknum;
                break;
            }
        }
    }

    //VD
    if(VD_picknum > dish_selected.VegD_num) VD_picknum = dish_selected.VegD_num; //renew picknum

    for(int i = 0; i < dish_selected.VegD_num; ++i){
        pVD_weight[i] = new int(dish_selected.pVeg_Diet[i]->get_ultimate_weight());
        VD_wSum += *pVD_weight[i];
    }
    memset(picked,false,sizeof(picked));
    srand((unsigned)time(NULL));
    for(int num = 0; num < VD_picknum; ++num){
        int b = rand();b = rand();
        int a = b % VD_wSum + 1;
        long long weight_preSum = 0;
        for(int i = 0; i < dish_selected.VegD_num; ++i){
            weight_preSum += dish_selected.pVeg_Diet[i]->get_ultimate_weight();
            if(weight_preSum >= a){
                if(!picked[i]){
                    picked[i] = true;
                    answer.pVeg_Diet[answer.VegD_num++] = dish_selected.pVeg_Diet[i];
                }
                else ++VD_picknum;
                break;
            }
        }
    }

    //MD
    if(MD_picknum > dish_selected.MeatD_num) MD_picknum = dish_selected.MeatD_num; //renew picknum

    for(int i = 0; i < dish_selected.MeatD_num; ++i){
        pMD_weight[i] = new int(dish_selected.pMeat_Diet[i]->get_ultimate_weight());
        MD_wSum += *pMD_weight[i];
    }
    memset(picked,false,sizeof(picked));
    srand((unsigned)time(NULL));
    for(int num = 0; num < MD_picknum; ++num){
        int b = rand();b = rand();
        int a = b % MD_wSum + 1;
        long long weight_preSum = 0;
        for(int i = 0; i < dish_selected.MeatD_num; ++i){
            weight_preSum += dish_selected.pMeat_Diet[i]->get_ultimate_weight();
            if(weight_preSum >= a){
                if(!picked[i]){
                    picked[i] = true;
                    answer.pMeat_Diet[answer.MeatD_num++] = dish_selected.pMeat_Diet[i];
                }
                else ++MD_picknum;
                break;
            }
        }
    }

    //VnMmix
    if(VMm_picknum > dish_selected.VegMeat_num) VMm_picknum = dish_selected.VegMeat_num; //renew picknum

    for(int i = 0; i < dish_selected.VegMeat_num; ++i){
        pVMm_weight[i] = new int(dish_selected.pVegnMeat_mix[i]->get_ultimate_weight());
        VMm_wSum += *pVMm_weight[i];
    }
    memset(picked,false,sizeof(picked));
    srand((unsigned)time(NULL));
    for(int num = 0; num < VMm_picknum; ++num){
        int b = rand();b = rand();
        int a = b % VMm_wSum + 1;
        long long weight_preSum = 0;
        for(int i = 0; i < dish_selected.VegMeat_num; ++i){
            weight_preSum += dish_selected.pVegnMeat_mix[i]->get_ultimate_weight();
            if(weight_preSum >= a){
                if(!picked[i]){
                    picked[i] = true;
                    answer.pVegnMeat_mix[answer.VegMeat_num++] = dish_selected.pVegnMeat_mix[i];
                }
                else ++VMm_picknum;
                break;
            }
        }
    }
    //
    return answer;
}

inline void changeweight(Food & aim,Food & foods){//智能推荐计算权重
    int a[7],b[7];
    a[0]=aim.getsalt();a[1]=aim.getsweet();a[2]=aim.getspicy();
    a[3]=aim.getcalorie();a[4]=aim.getgrease();a[5]=aim.getprotein();
    a[6]=aim.getcellulose();
    double dis=0;
    double c_weight=0;
    b[0]=foods.getsalt();b[1]=foods.getsweet();b[2]=foods.getspicy();
    b[3]=foods.getcalorie();b[4]=foods.getgrease();b[5]=foods.getprotein();
    b[6]=foods.getcellulose();
    for(int j=0;j<3;++j){
        if(b[j]<=0||a[j]<=0)continue;
        else{
            dis+=abs((a[j]-b[j])*1.5);
        }
    }
    for(int j=3;j<7;++j){
        if(b[j]<=0||a[j]<=0)continue;
        else{
            dis+=abs(a[j]-b[j]);
        }
    }
    c_weight=1/(dis+1);
    foods.set_change_weight(c_weight);
}

inline void CalculateWeight_forPack(Dish_Package &pack, Food aim){
    for(int i = 0; i < pack.SMeal_num; ++i){
        changeweight(aim,*pack.pSet_Meal[i]);
    }
    for(int i = 0; i < pack.VegD_num; ++i){
        changeweight(aim,*pack.pVeg_Diet[i]);
    }
    for(int i = 0; i < pack.MeatD_num; ++i){
        changeweight(aim,*pack.pMeat_Diet[i]);
    }
    for(int i = 0; i < pack.VegMeat_num; ++i){
        changeweight(aim,*pack.pVegnMeat_mix[i]);
    }
}

inline void Calrandom_weight_forPack(Dish_Package &pack){
    for(int i = 0; i < pack.SMeal_num; ++i){
        pack.pSet_Meal[i]->set_change_weight(0.09);
    }
    for(int i = 0; i < pack.VegD_num; ++i){
        pack.pVeg_Diet[i]->set_change_weight(0.09);
    }
    for(int i = 0; i < pack.MeatD_num; ++i){
        pack.pMeat_Diet[i]->set_change_weight(0.09);
    }
    for(int i = 0; i < pack.VegMeat_num; ++i){
        pack.pVegnMeat_mix[i]->set_change_weight(0.09);
    }
}

inline void save_preference(Food aim){
    ofstream ofile("preference", ios::out |ios::binary);
    if(!ofile){
        //cout << "can not open file preference" << endl;
        return;
    }
    ofile.write((char*)&aim, sizeof(Food));
    ofile.close();
}

inline Food read_preference(){ return read_file(0,"preference");}

#endif // MAINWINDOW_H
