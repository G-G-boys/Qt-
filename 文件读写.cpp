#include<iostream>
#include <time.h> 
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
string t="Set_Meal";
string s="Veg_Diet";
string h="Meat_Diet";
string b="VegnMeat_mix";
int hour,minute;
void  gettime() 
{ 
  time_t t = time(0);//返回系统的时间（从1970.1.1午夜算起），单位：秒
  char h[3],m[3]; 
  strftime(h,sizeof(h),"%H",localtime(&t));
  strftime(m,sizeof(m),"%M",localtime(&t));
  string temp;
  hour=atoi(h);
  minute=atoi(m);
}
const string snull="-1";
const int inull=-1;
const double dnull=-1;
class Food{
private:
    int number; //编号
    double fixed_weight;
    double change_weight;
    double ultimate_weight;
    string name;//菜名
    string canteen;//食堂
    string window;//窗口
    string type;//类别 1 素菜 2 荤菜 3 荤素混合 4 套餐
    double price;//价格
    int salt;//咸度
    int sweet;//甜度
    int spicy;//辣度
    int calorie;//能量
    int grease;//油脂类
    int protein;//蛋白质
    int cellulose;
public:
    void setnumber(int n){
        number=n;
    }
    int getnumber(){
        return number;
    }
    int canteen_int(){
  if(canteen == "家园"){
   return 1;
  }
  else if(canteen == "燕南"){
   return 1<<1;
  }
  else if(canteen == "学一"){
   return 1<<2; 
  }
  else if(canteen == "农园"){
   return 1<<3; 
  }  
  else if(canteen == "学五"){
   return 1<<4; 
  }
  else{//勺园
   return 1<<5;
  }
 }
    void setcellulose(int n){
        number=n;
    }
    int getcellulose(){
        return cellulose;
    }
    void settype(string n){
        type=n;
    }
    string gettype(){
        return type;
    }
    void setname(string n){
        name=n;
    }
    string getname(){
        return name;
    }
    void setcanteen(string n){
        canteen=n;
    }
    string getcanteen(){
        return canteen;
    }
    void setprice(double n){
        price=n;
    }
    string getwindow(){
        return window;
    }
    void setwindow(double n){
        window=n;
    }
    double getprice(){
        return price;
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
    double get_ultimate_weight(){
        ultimate_weight=(fixed_weight+change_weight+1)/2;
        return int(10000*ultimate_weight);
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
    friend bool operator <(Food a,Food b){
        if(a.getprice()<b.getprice())return true;
        return false;
    }
    bool operator == (Food &cmp){
		return name==cmp.getname() && canteen == cmp.getcanteen();
	}
    Food(){}
    Food(int num,
    string cname,
    string ccanteen,
    string cwindow,
    string ctype,
    double cprice,
    // string mainfoood;//搭配主食
    // int make;//烹饪方式 1 煎 2 炒 3 烹 4 炸
    int csalt,
    int csweet,
    int cspicy,
    int ccalorie,
    int cgrease,
    int cprotein,
   //int amylum;//淀粉
    int ccellulose//纤维素
    ):number(num),name(cname),canteen(ccanteen),window(cwindow),type(ctype),price(cprice),
    salt(csalt),sweet(csweet),spicy(cspicy),calorie(ccalorie),
    grease(cgrease),protein(cprotein),cellulose(ccellulose),
    change_weight(0),fixed_weight(0),ultimate_weight(0){} 
};//权重的初始值均为0
void add_to_blacklist(Food f){//加黑名单
    f.set_fixed_weight(-1);
    f.set_change_weight(-1);
    f.set_ultimate_weight(-1);
    //
}
// void changeweight(Food aim,Food* foods,int food_num){//计算临时权重
//     int a[8],b[8];
//     a[0]=aim.getsalt();a[1]=aim.getsweet();a[2]=aim.getspicy();
//     a[3]=aim.getcalorie();a[4]=aim.getgrease();a[5]=aim.getprotein();
//     a[6]=aim.getamylum();a[7]=aim.getcellulose();
//     for(int i=0;i<food_num;++i){
//     double dis=0;
//     double c_weight=0;
//     b[0]=foods[i].getsalt();b[1]=foods[i].getsweet();b[2]=foods[i].getspicy();
//     b[3]=foods[i].getcalorie();b[4]=foods[i].getgrease();b[5]=foods[i].getprotein();
//     b[6]=foods[i].getamylum();b[7]=foods[i].getcellulose();
//     for(int j=0;j<8;++j){
//         if(b[j]<=0)continue;
//         else{
//             dis+=(a[j]-b[j])*(a[j]-b[j]);
//         }
//     }
//     c_weight=1/(dis+1);
//     foods[i].set_change_weight(c_weight);
//     }
// }
struct Dish_Package{
public:
	Food *pSet_Meal[500];
	int SMeal_num = 0;
	Food *pVeg_Diet[500];
	int VegD_num = 0;
	Food *pMeat_Diet[500];
	int MeatD_num = 0;
	Food *pVegnMeat_mix[500];
	int VegMeat_num = 0;
};
void changeweight(Food & aim,Food & foods){//计算临时权重
    int a[7],b[7];
    a[0]=aim.getsalt();a[1]=aim.getsweet();a[2]=aim.getspicy();
    a[3]=aim.getcalorie();a[4]=aim.getgrease();a[5]=aim.getprotein();
    a[6]=aim.getcellulose();
    double dis=0;
    int tn=0;
    double c_weight=0;
    b[0]=foods.getsalt();b[1]=foods.getsweet();b[2]=foods.getspicy();
    b[3]=foods.getcalorie();b[4]=foods.getgrease();b[5]=foods.getprotein();
    b[6]=aim.getcellulose();
    for(int j=0;j<3;++j){
        if(b[j]<=0||a[j]<=0)continue;
        else{
            tn+=a[j];
            dis+=abs((a[j]-b[j])*1.5);
        }
    }
    for(int j=3;j<7;++j){
        if(b[j]<=0||a[j]<=0)continue;
        else{
            dis+=abs(a[j]-b[j]);
        }
    }
    c_weight=1/(dis+tn/15);
    foods.set_change_weight(c_weight);
}
void write_file(Food food,string s){//要读取或存入对应文件就直接把文件名赋值给s
    FILE* file=fopen(s.c_str(),"ab");
    if(file==NULL){
        cout<<"file open defeat\n";
        return;
    }
    fwrite(&food,sizeof(Food),1,file);
    fclose(file);
}
void write_file(Food food,string s,int n){//要读取或存入对应文件就直接把文件名赋值给s
    FILE* file=fopen(s.c_str(),"ab");
    if(file==NULL){
        cout<<"file open defeat\n";
        return;
    }
    fseek(file,sizeof(Food)*n,0);
    fwrite(&food,sizeof(Food),1,file);
    fclose(file);
}
Food read_file(int n,string s){
    FILE* file=fopen(s.c_str(),"rb");
    if(file==NULL){
        cout<<"fille open defeat\n";
        return Food();
    }
    fseek(file,sizeof(Food)*n,0);
    Food food;
    fread(&food,sizeof(Food),1,file);
    fclose(file); 
    return food;   
}
int get_food_num(string s){//获取当前读入菜品数量
    FILE* ffile=fopen(s.c_str(),"ab"); 
    fseek(ffile,0L,SEEK_END);
    int size=ftell(ffile);
    fclose(ffile);  
    int N=size/sizeof(Food);
    return N;
}
void Calrandom_weight_forPack(Dish_Package &pack){
	for(int i = 0; i < pack.SMeal_num; ++i){
		pack.pSet_Meal[i]->set_change_weight(0.9);
	}
	for(int i = 0; i < pack.VegD_num; ++i){
		pack.pVeg_Diet[i]->set_change_weight(0.9);
	}
	for(int i = 0; i < pack.MeatD_num; ++i){
		pack.pMeat_Diet[i]->set_change_weight(0.9);
	}
	for(int i = 0; i < pack.VegMeat_num; ++i){
		pack.pVegnMeat_mix[i]->set_change_weight(0.9);
	}	
}
Dish_Package Weighted_random(const Dish_Package &dish_selected){
	int *pSM_weight[500], *pVD_weight[500], *pMD_weight[500], *pVMm_weight[500];
	bool picked[500];
	int SM_picknum = 3, VD_picknum = 3, MD_picknum = 3, VMm_picknum = 3;
	int SM_wSum = 0, VD_wSum = 0, MD_wSum = 0, VMm_wSum = 0;
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
		int weight_preSum = 0;
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
		int weight_preSum = 0;
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
		int weight_preSum = 0;
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
		int weight_preSum = 0;
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


// void read_all_file(Food * & f,string s){
//     FILE* file=fopen(s.c_str(),"rb");
//     if(file==NULL){
//         cout<<"fille open defeat\n";
//         return;
//     }
//     int i=0;
//     while(feof(file)==0){
//     fread(&f[i],sizeof(Food),1,file);
//     i++;
//     } 
//     fclose(file); 
// }

void read_all_file(Dish_Package &pack, int canteen){//��ȡ����ѡ��ʳ�õĲ˽���pack
	if(canteen == 0) canteen = 63;
	string s = "Meat_Diet";
    FILE* file=fopen(s.c_str(),"rb");
    if(file==NULL){
        cout<<"fille open defeat\n";
        return;
    }
    int t = get_food_num(s);
    for(int i = 0; i < t; ++i){
    	Food temp;
    	fread(&temp,sizeof(Food),1,file);
    	if((canteen&temp.canteen_int()) != 0) pack.pMeat_Diet[pack.MeatD_num++] = new Food(temp);
    } 
    fclose(file);
    
	s = "Veg_Diet";
    file=fopen(s.c_str(),"rb");
    if(file==NULL){
        cout<<"fille open defeat\n";
        return;
    }
    t = get_food_num(s);
    for(int i = 0; i < t; ++i){
    	Food temp;
    	fread(&temp,sizeof(Food),1,file);
    	if((canteen&temp.canteen_int()) != 0) pack.pVeg_Diet[pack.VegD_num++] = new Food(temp);
    } 
    fclose(file);
    
	s = "Set_Meal";
    file=fopen(s.c_str(),"rb");
    if(file==NULL){
        cout<<"fille open defeat\n";
        return;
    }
    t = get_food_num(s);
    for(int i = 0; i < t; ++i){
    	Food temp;
    	fread(&temp,sizeof(Food),1,file);
    	if((canteen&temp.canteen_int()) != 0) pack.pSet_Meal[pack.SMeal_num++] = new Food(temp);
    } 
    fclose(file);
    
	s = "VegnMeat_mix";
    file=fopen(s.c_str(),"rb");
    if(file==NULL){
        cout<<"fille open defeat\n";
        return;
    }
    t = get_food_num(s);
    for(int i = 0; i < t; ++i){
    	Food temp;
    	fread(&temp,sizeof(Food),1,file);
    	if((canteen&temp.canteen_int()) != 0) pack.pVegnMeat_mix[pack.VegMeat_num++] = new Food(temp);
    } 
    fclose(file); 
}
int judge_repeat(Food food){
	string a_s[4] ={"Meat_Diet","Veg_Diet","Set_Meal","VegnMeat_mix"};
	for(int ij=0;ij<4;++ij){
		FILE* ff=fopen(a_s[ij].c_str(),"rb");
		if(ff==NULL){
			return 0;
		}
		int ts = get_food_num(a_s[ij]);
		while(ts>0){
			Food ft;
            fread(&ft,sizeof(Food),1,ff);
			if(food.getname()==ft.getname()&&food.getcanteen()==ft.getcanteen()){
				return ft.getnumber();
			}
            ts--;
		}	
		fclose(ff);	
	}
	return -1;
}
void add_reset_file(Food &food){
	int n = judge_repeat(food);
	if(n == -1){
		food.setnumber(get_food_num(food.gettype()));
		write_file(food, food.gettype());
		return;
	}
	// Food *f[1000]={NULL};
	// FILE* file=fopen(food.gettype().c_str(),"rb");
    // if(file==NULL){
    //     cout<<"file open defeat\n";
    //     return;
    // }
    // int i=0;
    // int tt = get_food_num(food.gettype());
    // for(int j = 0; j < tt; ++j){
    // 	Food temp;
	//     fread(&temp,sizeof(Food),1,file);
	// 	f[i++] = new Food(temp);
    // } 
    // fclose(file);
    // food.setnumber(n);
    // *f[n] = food;
	// ofstream ofile(food.gettype().c_str(), ios::out | ios::binary);
	// for(int j = 0; j < i; ++j){
	// 	ofile.write((char*)(&(*f[j])), sizeof(Food));
	// }
	// ofile.close();
}
int main(){
string t="Set_Meal";
string s="Veg_Diet";
string h="Meat_Diet";
string b="VegnMeat_mix";
FILE* ft=fopen(t.c_str(),"w");fclose(ft);
FILE* fs=fopen(s.c_str(),"w");fclose(fs);
FILE* fh=fopen(h.c_str(),"w");fclose(fh);
FILE* fb=fopen(b.c_str(),"w");fclose(fb);
Food * jian[12];
    Food f(0,"干煸仔鸡饭","家园","中式简餐",t,12,3,1,4,3,2,3,1);
    write_file(f,f.gettype());
    Food f3(get_food_num(t),"烧鹅饭","家园","广东风味",t,16,2,1,1,2,2,2,2);
    write_file(f3,f3.gettype());
    Food f2(get_food_num(t),"干煸炒面","家园","新疆档口",t,13,4,1,4,2,2,1,2);
    write_file(f2,f2.gettype());
Food f158(get_food_num(h),"厦门姜焖鸡","燕南","鲁菜浙菜",h,10,1,1,3,2,1,3,1);
write_file(f158,f158.gettype());
Food f195(get_food_num(h),"生蒸五花肉","勺园","湖南风味",h,8,1,2,3,3,3,2,1);
write_file(f195,f195.gettype());
Food f196(get_food_num(h),"糖醋鸡球","勺园","浙江风味",h,8,1,3,1,3,2,2,1);
write_file(f196,f196.gettype());
    Food f68(get_food_num(h),"山城辣子鸡","学一","米饭炒菜",h,12,3,1,4,3,2,3,1);
    write_file(f68,f68.gettype());   
    Food f49(get_food_num(t),"叉烧煲仔饭","家园","煲仔饭",t,18,3,3,1,3,2,2,2);
    write_file(f49,f49.gettype());
    Food f50(get_food_num(t),"盐焗鸡仔饭","家园","煲仔饭",t,14,5,2,1,3,2,3,2);
    write_file(f50,f50.gettype());
    Food f51(get_food_num(t),"热干面","学一","面食窗口",t,7.5,4,1,2,2,2,1,1);
    write_file(f51,f51.gettype());
Food f157(get_food_num(h),"京烧鸡肉","燕南","粤菜闽菜",h,12,2,1,1,3,1,3,1);
write_file(f157,f157.gettype());
    Food f6(get_food_num(t),"芝士焗番茄拌饭","燕南","日韩料理",t,13,2,1,2,2,2,2,2);
    write_file(f6,f6.gettype());
    Food f10(get_food_num(t),"羊肉泡馍","燕南","陕西档口",t,13,4,1,1,2,2,2,1);
    write_file(f10,f10.gettype());
    Food f11(get_food_num(t),"木桶烟笋腊肉饭","农园","潇湘风味",t,18,4,1,4,2,2,2,3);
    write_file(f11,f11.gettype());
    Food f12(get_food_num(t),"黄焖鸡米饭","燕南","日韩料理",t,16,4,1,2,2,2,2,2);
    write_file(f12,f12.gettype());
    Food f26(get_food_num(b),"丝瓜肉丸","家园","南区热菜",b,6,3,1,1,2,2,1,3);
    write_file(f26,f26.gettype());
    Food f28(get_food_num(b),"肉片炒菜花","家园","南区热菜",b,5,3,1,1,2,3,2,3);
    write_file(f28,f28.gettype());  
    Food f13(get_food_num(t),"冷面","学一","冷面",t,12,2,2,1,2,1,2,1);
    write_file(f13,f13.gettype());
    Food f7(get_food_num(t),"芝士泡菜拉面锅","燕南","日韩料理",t,12,4,1,3,2,3,2,1);
    write_file(f7,f7.gettype());
    Food f9(get_food_num(t),"鸡肉米线","家园","夏季推荐凉拌",t,13,4,1,1,3,2,3,1);
    write_file(f9,f9.gettype());
    Food f14(get_food_num(t),"脆皮烧鸭饭","家园","广东风味",t,13,3,2,2,3,2,2,2);
    Food f27(get_food_num(s),"酿苦瓜","家园","南区热菜",s,4.5,2,1,1,1,1,1,3);
    write_file(f27,f27.gettype());
    Food f23(get_food_num(s),"蚝油生菜","家园","南区热菜",s,3,1,1,1,1,1,1,3);
    write_file(f23,f23.gettype());
    Food f15(get_food_num(t),"鸡肉砂锅饭","家园","煲仔饭",t,18,3,2,2,2,2,3,2);
    write_file(f15,f15.gettype());
    Food f16(get_food_num(t),"爆汁鸡排饭","家园","中式简餐",t,12,3,2,1,3,3,2,1);
    write_file(f16,f16.gettype());
    Food f24(get_food_num(s),"油淋芦笋","家园","南区热菜",s,5.5,1,1,1,1,1,1,3);
    write_file(f24,f24.gettype());
    Food f25(get_food_num(s),"五香毛豆","家园","南区热菜",s,4,3,1,1,2,1,2,1);
    write_file(f25,f25.gettype());
    Food f35(get_food_num(s),"雪菜毛豆粒","家园","家园素食",s,8,2,1,2,1,2,1,2);
    write_file(f35,f35.gettype());
    Food f36(get_food_num(s),"西芹炒香干","家园","家园素食",s,8,3,2,1,2,1,2,3);
    write_file(f36,f36.gettype());
    Food f37(get_food_num(s),"咸蛋黄玉米粒","家园","家园素食",s,7,3,2,1,2,1,2,1);
    write_file(f37,f37.gettype());
    Food f40(get_food_num(s),"木耳小白菜","家园","家园素食",s,6,2,1,1,1,1,1,2);
    write_file(f40,f40.gettype());   
    Food f18(get_food_num(b),"青萝卜鱼丸汤","家园","南区热菜",b,3.5,3,1,1,1,1,2,1);
    write_file(f18,f18.gettype());
    Food f20(get_food_num(b),"话梅烧翅根","家园","南区热菜",b,7,3,1,1,3,2,2,1);
    write_file(f20,f20.gettype());
    Food f29(get_food_num(b),"香芹炒肉丝","家园","南区热菜",b,4,3,1,1,2,2,2,3);
    write_file(f29,f29.gettype());
    Food f56(get_food_num(t),"麻辣小龙虾套餐","学一","米饭炒菜",t,18,4,1,4,3,2,2,1);
    write_file(f56,f56.gettype());
    Food f57(get_food_num(t),"糖醋丸子套餐","学一","米饭炒菜",t,9,3,2,1,2,2,1,1);
    write_file(f57,f57.gettype());
    Food f58(get_food_num(t),"风味鸡排套餐","学一","米饭炒菜",t,12,3,1,1,3,2,3,1);
    write_file(f58,f58.gettype());    
    Food f30(get_food_num(b),"鹌鹑蛋红烧肉","家园","南区热菜",b,6,3,1,1,3,3,3,1);
    write_file(f30,f30.gettype());   
    Food f41(get_food_num(b),"青椒鱼片","家园","南区热菜",b,15,3,1,4,2,2,3,2);
    write_file(f41,f41.gettype());
    Food f42(get_food_num(b),"菠萝咕咾肉","家园","江南风味",b,13,2,2,1,3,2,2,1);
    write_file(f42,f42.gettype());
    Food f4(get_food_num(t),"金牌口水鸡饭","学五","校园快餐",t,13,4,1,1,3,2,3,2);
    write_file(f4,f4.gettype());
    Food f8(get_food_num(t),"鲶鱼豆腐锅","燕南","日韩料理",t,12,4,1,2,2,2,3,1);
    write_file(f8,f8.gettype());
    Food f1(get_food_num(t),"杭帮五花肉饭","家园","江南风味",t,17,3,1,1,3,3,2,1);
    write_file(f1,f1.gettype());
Food f192(get_food_num(h),"自制酱牛肉","勺园","酱制熟食",h,6,2,1,1,3,2,3,1);
write_file(f192,f192.gettype());
Food f193(get_food_num(h),"湘味回锅肉","勺园","湖南风味",h,8,1,1,4,3,3,2,1);
write_file(f193,f193.gettype());  
    Food f52(get_food_num(t),"炸酱面","学一","面食窗口",t,4,4,2,1,2,2,2,1);
    write_file(f52,f52.gettype());
    Food f53(get_food_num(t),"襄阳牛肉面","学一","面食窗口",t,12,3,1,1,2,1,3,1);
    write_file(f53,f53.gettype());
    Food f38(get_food_num(s),"鸡蛋西葫芦","家园","家园素食",s,8,3,2,1,2,1,2,1);
    write_file(f38,f38.gettype());
    Food f39(get_food_num(s),"番茄日本豆腐","家园","家园素食",s,12,2,1,1,2,1,3,1);
    write_file(f39,f39.gettype());
    Food f54(get_food_num(t),"酱腔骨套餐","学一","米饭炒菜",t,15,4,1,1,3,2,3,1);
    write_file(f54,f54.gettype());
    Food f60(get_food_num(h),"京酱肉丝","学一","米饭炒菜",h,8,3,2,1,2,2,2,2);
    write_file(f60,f60.gettype());  
    Food f61(get_food_num(h),"椒麻小酥肉","学一","米饭炒菜",h,5,3,1,4,3,3,2,1);
    write_file(f61,f61.gettype());   
    Food f62(get_food_num(h),"藤椒鱼片","学一","米饭炒菜",h,10,3,1,3,2,1,3,1);
    write_file(f62,f62.gettype());
    Food f19(get_food_num(h),"酥炸小河虾","家园","南区热菜",h,4.5,4,1,1,3,3,2,1);
    write_file(f19,f19.gettype());
    Food f21(get_food_num(h),"孜然鸡块","家园","南区热菜",h,6,4,1,2,3,3,2,1);
    write_file(f21,f21.gettype());   
    Food f69(get_food_num(h),"黄焖鸡块","学一","米饭炒菜",h,10,3,1,1,3,2,3,1);
    write_file(f69,f69.gettype());   
    Food f31(get_food_num(h),"小炒鸡块","家园","南区热菜",h,6,3,1,2,3,3,3,1);
    write_file(f31,f31.gettype());  
    Food f32(get_food_num(h),"豆豉排骨","家园","南区热菜",h,8,4,1,2,3,2,3,1);
    write_file(f32,f32.gettype());
    Food f81(get_food_num(s),"干锅千页豆腐","学一","米饭炒菜",s,8,2,1,2,1,1,3,1);
    write_file(f81,f81.gettype());  
    Food f82(get_food_num(s),"炒烤吐司","学一","主食",s,3,2,2,1,2,1,1,1);
    write_file(f82,f82.gettype()); 
Food f215(get_food_num(s),"清炒快菜","勺园","湖南风味",s,4,2,1,1,1,1,1,3);
write_file(f215,f215.gettype());
Food f216(get_food_num(s),"荷塘月色","勺园","浙江风味",s,7,2,1,1,1,1,2,3);
write_file(f216,f216.gettype());
Food f217(get_food_num(t),"木桶红烧肉饭","农园","潇湘风味",t,16,2,1,3,3,3,2,2);
write_file(f217,f217.gettype());   
    Food f67(get_food_num(h),"炸牙签肉","学一","米饭炒菜",h,24,2,1,2,3,3,3,1);
    write_file(f67,f67.gettype());   
    Food f70(get_food_num(b),"火腿炒双花","学一","米饭炒菜",b,6,3,1,1,2,2,2,1);
    write_file(f70,f70.gettype()); 
    Food f85(get_food_num(s),"炒三鲜","学一","米饭炒菜",s,8,3,2,1,2,1,3,2);
    write_file(f85,f85.gettype());  
    Food f86(get_food_num(s),"三色彩苔","学一","米饭炒菜",s,5,1,1,1,1,1,1,2);
    write_file(f86,f86.gettype());  
    Food f87(get_food_num(s),"粉条炒鸡蛋","学一","米饭炒菜",s,7,3,1,1,1,1,3,1);
    write_file(f87,f87.gettype());  
    Food f88(get_food_num(s),"水果捞","学一","米饭炒菜",s,8,1,3,1,1,1,1,3);
    write_file(f88,f88.gettype());  
    Food f89(get_food_num(s),"椒丝腐乳空心菜","学一","米饭炒菜",s,6,3,1,3,1,1,2,3);
    write_file(f89,f89.gettype());
Food f96(get_food_num(t),"担担面","农园","轻食热菜",t,10,4,1,4,3,1,3,1);
write_file(f96,f96.gettype()); 
Food f125(get_food_num(s),"鸡蛋西红柿","农园","4元菜品自选区",s,4,2,2,1,1,1,3,1);
write_file(f125,f125.gettype());  
Food f127(get_food_num(s),"尖椒豆皮","农园","4元菜品自选区",s,4,1,1,3,1,1,3,3);
write_file(f127,f127.gettype()); 
    Food f83(get_food_num(s),"豆沙黄米糕","学一","主食",s,4,1,3,1,2,1,2,1);
    write_file(f83,f83.gettype());  
    Food f84(get_food_num(s),"尖椒炒豆皮","学一","米饭炒菜",s,7,2,1,4,1,1,3,2);
    write_file(f84,f84.gettype());
Food f212(get_food_num(s),"烧茄子","勺园","时蔬素菜",s,6,2,1,1,1,1,1,3);
write_file(f212,f212.gettype());
Food f213(get_food_num(s),"西红柿炒鸡蛋","勺园","时蔬素菜",s,6,2,2,1,1,1,3,2);
write_file(f213,f213.gettype());
Food f214(get_food_num(s),"老干妈煎黄瓜","勺园","湖南风味",s,7,2,1,4,1,2,1,2);
write_file(f214,f214.gettype()); 
Food f128(get_food_num(s),"葱油娃娃菜","农园","4元菜品自选区",s,4,1,1,1,1,1,1,3);
write_file(f128,f128.gettype());    
    Food f64(get_food_num(h),"乳香肉条","学一","米饭炒菜",h,6,2,2,1,2,2,2,1);
    write_file(f64,f64.gettype()); 
Food f172(get_food_num(s),"川渝长豆角","燕南","鲁菜浙菜",s,9,2,1,1,1,1,2,3);
write_file(f172,f172.gettype()); 
Food f104(get_food_num(t),"猪蹄凤爪饭","学五","校园快餐",t,18,2,1,1,3,3,3,1);
write_file(f104,f104.gettype());    
Food f138(get_food_num(b),"鸡片炒青椒","农园","5元菜品自选区",b,5,2,1,4,2,1,3,3);
write_file(f138,f138.gettype());  
    Food f65(get_food_num(h),"酱猪蹄","学一","米饭炒菜",h,30,2,1,1,3,3,3,1);
    write_file(f65,f65.gettype());   
    Food f66(get_food_num(h),"麻辣鸡爪","学一","米饭炒菜",h,25,2,1,4,3,3,3,1);
    write_file(f66,f66.gettype());
Food f116(get_food_num(h),"炸鸡腿","学五","合利屋",h,8,2,1,1,3,3,3,1);
write_file(f116,f116.gettype());  
Food f162(get_food_num(b),"鸡丝炒豇豆","燕南","川菜湘菜",b,8,2,1,1,2,1,3,2);
write_file(f162,f162.gettype());
Food f163(get_food_num(b),"毛豆仁炒腊肠","燕南","川菜徽菜",b,13,2,1,3,2,2,3,2);
write_file(f163,f163.gettype());  
    Food f71(get_food_num(b),"芹菜炒培根","学一","米饭炒菜",b,7,3,1,1,2,1,2,2);
    write_file(f71,f71.gettype());
    Food f72(get_food_num(b),"火腿娃娃菜","学一","米饭炒菜",b,6,3,1,1,2,2,2,2);
    write_file(f72,f72.gettype());
    Food f73(get_food_num(b),"翡翠肉燕","学一","米饭炒菜",b,8,2,1,1,2,1,2,1);
    write_file(f73,f73.gettype());
    Food f34(get_food_num(h),"韩式炸鸡","家园","日韩料理",h,3.5,3,2,2,3,3,3,1);
    write_file(f34,f34.gettype());
    Food f45(get_food_num(h),"小炒牛肉","家园","蜀湘风味",h,18,3,1,5,3,2,3,1);
    write_file(f45,f45.gettype());
    Food f46(get_food_num(h),"台式三杯鸡","家园","闽南风味",h,13,3,2,1,3,2,3,1);
    write_file(f46,f46.gettype());
    Food f76(get_food_num(b),"冬瓜炖排骨","学一","特供菜",b,8,2,2,1,2,1,3,2);
    write_file(f76,f76.gettype());
    Food f77(get_food_num(b),"西红柿玉米鸡丁","学一","米饭炒菜",b,8,2,2,1,2,1,2,1);
    write_file(f77,f77.gettype());
    Food f78(get_food_num(b),"荠菜溜鱼丸","学一","特供菜",b,10,3,1,1,2,2,2,2);
    write_file(f78,f78.gettype());
    Food f79(get_food_num(b),"金针云耳蒸滑鸡","学一","米饭炒菜",b,9,2,2,1,2,1,2,2);
    write_file(f79,f79.gettype());
    Food f80(get_food_num(s),"蛋包豆腐","学一","米饭炒菜",s,5,2,1,1,1,1,3,1);
    write_file(f80,f80.gettype());   
Food f129(get_food_num(s),"鸡蛋香芹叶","农园","轻食热菜",s,4,1,1,1,1,1,3,3);
write_file(f129,f129.gettype());  
Food f97(get_food_num(t),"朝鲜冷面","农园","轻食热菜",t,12,3,1,2,2,1,3,1);
write_file(f97,f97.gettype());  
Food f130(get_food_num(b),"肉沫豆腐白菜汤","农园","4元菜品自选区",b,4,3,1,1,1,2,3,2);
write_file(f130,f130.gettype());
    Food f55(get_food_num(t),"猪排饭套餐","学一","米饭炒菜",t,14,3,1,1,3,3,2,1);
    write_file(f55,f55.gettype());
Food f137(get_food_num(b),"玉米虾仁","农园","8元菜品自选区",b,4,1,3,1,2,1,3,1);
write_file(f137,f137.gettype());
Food f171(get_food_num(s),"燕麦焗南瓜","燕南","川菜湘菜",s,10,1,3,1,3,1,2,3);
write_file(f171,f171.gettype());
Food f139(get_food_num(b),"鸡丝炒苦瓜","农园","5元菜品自选区",b,5,2,1,1,2,1,3,2);
write_file(f139,f139.gettype());
Food f136(get_food_num(h),"蒜香排骨","农园","12元菜品区",h,12,3,1,2,2,1,3,1);
write_file(f136,f136.gettype());    
Food f98(get_food_num(h),"酱牛肉","农园","轻食热菜",h,12,4,1,1,3,1,3,1);
write_file(f98,f98.gettype()); 
Food f91(get_food_num(h),"酱肘子","农园","轻食热菜",h,12,3,1,1,3,3,3,1);
write_file(f91,f91.gettype());   
Food f140(get_food_num(h),"红烧丸子","农园","主食",h,3,3,1,1,2,2,1,1);
write_file(f140,f140.gettype()); 
Food f145(get_food_num(h),"麻辣兔头","农园","5元菜品自选区",h,13,2,1,5,2,2,3,1);
write_file(f145,f145.gettype()); 
Food f101(get_food_num(t),"香辣鸡腿肉拌饭","学五","校园快餐",t,13,3,2,3,3,2,3,2);
write_file(f101,f101.gettype());
Food f167(get_food_num(b),"橄榄肉沫油麦菜","燕南","粤菜闽菜",b,10,1,2,1,1,2,1,3);
write_file(f167,f167.gettype());
Food f168(get_food_num(b),"芥兰熘鸡片","燕南","粤菜闽菜",b,10,2,2,1,2,1,3,3);
write_file(f168,f168.gettype()); 
Food f131(get_food_num(b),"香菇肉片","农园","8元菜品自选区",b,6,3,1,1,2,1,2,3);
write_file(f131,f131.gettype());  
Food f115(get_food_num(t),"辛拉面","学五","合利屋",t,15,2,1,3,2,1,2,1);
write_file(f115,f115.gettype());   
Food f194(get_food_num(h),"啤酒鸭","勺园","湖南风味",h,10,2,2,5,3,2,3,1);
write_file(f194,f194.gettype());  
Food f132(get_food_num(b),"胡萝卜烧肉","农园","8元菜品自选区",b,8,2,1,1,2,2,1,2);
write_file(f132,f132.gettype());  
Food f133(get_food_num(b),"鸡丝黑豆苗","农园","8元菜品自选区",b,4,2,1,1,2,1,3,2);
write_file(f133,f133.gettype());
Food f126(get_food_num(s),"干锅菜花","农园","5元菜品自选区",s,5,3,1,3,2,2,1,3);
write_file(f126,f126.gettype()); 
    Food f48(get_food_num(h),"柳木羊肉串","家园","新疆风味",h,12,3,1,4,3,2,3,1);
    write_file(f48,f48.gettype());
    Food f63(get_food_num(h),"豉汁排骨","学一","米饭炒菜",h,10,3,2,1,3,2,3,1);
    write_file(f63,f63.gettype());   
Food f134(get_food_num(b),"山芋粉蒸肉","农园","12元菜品区",b,12,2,1,1,3,2,2,3);
write_file(f134,f134.gettype());  
Food f169(get_food_num(s),"虾皮粉丝娃娃菜","燕南","粤菜闽菜",s,8,2,2,1,1,1,2,3);
write_file(f169,f169.gettype());
    Food f59(get_food_num(t),"香煎五福卷饼","学一","主食",t,8,4,2,1,2,2,2,2);
    write_file(f59,f59.gettype());
Food f135(get_food_num(b),"白萝卜炖排骨","农园","12元菜品区",b,10,3,1,1,2,1,3,2);
write_file(f135,f135.gettype());  
Food f170(get_food_num(s),"鱼香白玉豆腐","燕南","川菜湘菜",s,12,1,3,1,1,1,3,1);
write_file(f170,f170.gettype());  
Food f102(get_food_num(t),"特色五花肉拌饭","学五","校园快餐",t,16,3,2,3,3,3,1,2);
write_file(f102,f102.gettype());  
Food f103(get_food_num(t),"香汁肥牛拌饭","学五","校园快餐",t,18,3,3,3,3,3,2,2);
write_file(f103,f103.gettype()); 
Food f204(get_food_num(b),"肉片白菜炖宽粉","勺园","风味炒菜",b,8,2,1,1,2,2,1,3);
write_file(f204,f204.gettype());
Food f205(get_food_num(b),"干锅五花土豆片","勺园","风味炒菜",b,10,2,1,3,3,2,1,1);
write_file(f205,f205.gettype());
Food f166(get_food_num(b),"圆白菜炒培根","燕南","粤菜闽菜",b,8,2,1,1,2,2,2,3);
write_file(f166,f166.gettype());
Food f105(get_food_num(t),"小炒肥肠鸡","学五","校园快餐",t,13,2,1,3,3,3,2,1);
write_file(f105,f105.gettype());  
Food f106(get_food_num(t),"锅包肉套餐","学五","校园快餐",t,13,1,3,1,3,3,2,1);
write_file(f106,f106.gettype());  
Food f107(get_food_num(t),"金牌口水鸡","学五","校园快餐",t,13,2,2,2,2,2,3,1);
write_file(f107,f107.gettype());  
Food f108(get_food_num(t),"牛排意大利面","学五","合利屋",t,30,3,2,1,3,1,3,1);
write_file(f108,f108.gettype());
Food f109(get_food_num(t),"鸡柳饭","学五","合利屋",t,16,2,1,1,3,3,2,1);
write_file(f109,f109.gettype());  
Food f110(get_food_num(t),"鱿鱼蛋包饭","学五","合利屋",t,25,3,1,2,2,2,3,1);
write_file(f110,f110.gettype()); 
    Food f44(get_food_num(b),"宫保鸡丁","家园","蜀湘风味",b,14,2,2,4,3,2,2,2);
    write_file(f44,f44.gettype());
Food f173(get_food_num(s),"鸡菇小白菜","燕南","川菜徽菜",s,8,2,1,1,1,1,1,3);
write_file(f173,f173.gettype());
Food f180(get_food_num(t),"厦门沙茶面","勺园","面食稀食",t,12,2,1,3,1,1,1,1);
write_file(f180,f180.gettype()); 
Food f111(get_food_num(t),"铁板牛肉西兰花","学五","合利屋",t,28,3,1,2,2,2,3,3);
write_file(f111,f111.gettype());  
Food f112(get_food_num(t),"五花肉石锅拌饭","学五","合利屋",t,25,2,1,1,3,3,2,2);
write_file(f112,f112.gettype()); 
    Food f75(get_food_num(b),"春笋烧肉","学一","米饭炒菜",b,10,2,1,1,2,1,2,2);
    write_file(f75,f75.gettype());
Food f142(get_food_num(h),"小炒肉","农园","8元菜品自选区",h,8,3,1,2,2,3,1,1);
write_file(f142,f142.gettype()); 
Food f143(get_food_num(h),"白灼虾","农园","10元菜品区",h,10,4,1,1,2,1,3,1);
write_file(f143,f143.gettype()); 
Food f117(get_food_num(h),"玉米片凤尾虾","学五","合利屋",h,12,3,2,1,3,2,3,1);
write_file(f117,f117.gettype());;
Food f92(get_food_num(s),"煮玉米","农园","轻食粗粮",s,1.5,1,3,1,2,2,1,2);
write_file(f92,f92.gettype());  
Food f93(get_food_num(t),"宜宾燃面","农园","轻食热菜",t,10,4,1,5,2,1,1,1);
write_file(f93,f93.gettype());
Food f120(get_food_num(b),"安井蛋饺","学五","湖南米粉",b,2,2,1,1,2,1,2,1);
write_file(f120,f120.gettype());  
Food f148(get_food_num(b),"番茄肥牛粉","学五","湖南米粉",b,16,3,2,1,3,3,2,1);
write_file(f148,f148.gettype());  
Food f122(get_food_num(b),"麻辣牛肉粉","学五","湖南米粉",b,15,3,2,4,2,2,3,1);
write_file(f122,f122.gettype());  
Food f123(get_food_num(b),"牛杂粉","学五","湖南米粉",b,15,3,2,3,3,2,2,1);
write_file(f123,f123.gettype());  
Food f124(get_food_num(t),"老坛酸菜牛肉面","学五","面食快餐",t,10,3,1,3,2,2,3,2);
write_file(f124,f124.gettype());
Food f150(get_food_num(t),"川味小面","燕南","正宗陕西风味",t,11,2,1,5,2,1,1,1);
write_file(f150,f150.gettype());
Food f151(get_food_num(t),"油泼刀削面","燕南","正宗陕西风味",t,7,2,1,4,2,1,1,1);
write_file(f151,f151.gettype());
Food f152(get_food_num(t),"风味茄子饭","农园","拼味套餐",t,7,1,2,4,2,1,1,3);
write_file(f152,f152.gettype());
Food f153(get_food_num(t),"西红柿鸡蛋面","燕南","正宗陕西风味",t,6,2,2,1,2,1,1,2);
write_file(f153,f153.gettype());
Food f154(get_food_num(h),"京烧鸡肉","燕南","粤菜闽菜",h,12,2,1,1,3,1,3,1);
write_file(f154,f154.gettype());
Food f141(get_food_num(h),"水煮鱼","农园","12元菜品区",h,10,2,1,2,2,1,3,1);
write_file(f141,f141.gettype()); 
    Food f47(get_food_num(h),"铁板鱿鱼","家园","新疆风味",h,10,3,1,2,3,2,3,1);
    write_file(f47,f47.gettype());  
    Food f74(get_food_num(b),"咖喱鸡块","学一","米饭炒菜",b,7,3,2,1,2,1,2,1);
    write_file(f74,f74.gettype());
Food f155(get_food_num(h),"四川椒麻鸡","燕南","川菜湘菜",h,13,1,1,4,3,2,3,1);
write_file(f155,f155.gettype());
Food f197(get_food_num(h),"杭州小炒肉","勺园","浙江风味",h,10,2,2,1,3,2,2,1);
write_file(f197,f197.gettype());
Food f160(get_food_num(h),"尖椒鸭片","燕南","川菜湘菜",h,12,1,1,4,2,1,3,1);
write_file(f160,f160.gettype());
Food f161(get_food_num(b),"豆干回锅肉","燕南","川菜湘菜",b,10,2,1,3,2,2,3,1);
write_file(f161,f161.gettype());
Food f144(get_food_num(h),"黑椒鸡块","农园","5元菜品自选区",h,3.5,3,1,3,3,3,2,1);
write_file(f144,f144.gettype());  
Food f113(get_food_num(t),"虾仁炒饭","学五","合利屋",t,16,1,2,1,2,1,3,1);
write_file(f113,f113.gettype());  
Food f164(get_food_num(b),"四川酸菜籴肉片","燕南","川菜徽菜",b,10,2,1,4,2,2,2,1);
write_file(f164,f164.gettype());
Food f165(get_food_num(b),"豆豉蒜蓉烤鲶鱼","燕南","川菜徽菜",b,14,2,1,1,2,2,3,1);
write_file(f165,f165.gettype());
Food f201(get_food_num(b),"梅菜扣肉","勺园","湖南风味",b,8,4,1,2,3,3,2,2);
write_file(f201,f201.gettype());
Food f202(get_food_num(b),"湘味炒三丁","勺园","湖南风味",b,9,2,1,3,2,1,2,2);
write_file(f202,f202.gettype());
Food f203(get_food_num(b),"宫保鸡丁","勺园","风味炒菜",b,8,2,2,3,2,1,2,3);
write_file(f203,f203.gettype());
    Food f43(get_food_num(b),"麻辣一锅鲜","家园","蜀湘风味",b,14,3,1,5,3,3,2,2);
    write_file(f43,f43.gettype());
Food f174(get_food_num(s),"咸蛋黄焗玉米粒","燕南","川菜徽菜",s,8,3,2,1,2,1,3,2);
write_file(f174,f174.gettype());
Food f175(get_food_num(s),"滑炒双丝","燕南","鲁菜浙菜",s,12,1,2,1,2,1,1,3);
write_file(f175,f175.gettype());
Food f176(get_food_num(s),"鸡蛋炒饼","燕南","正宗陕西风味",s,8,2,2,1,2,1,2,1);
write_file(f176,f176.gettype());
Food f177(get_food_num(s),"广味有机菜花","燕南","有机菜系列",s,6,2,1,1,1,1,1,3);
write_file(f177,f177.gettype());
Food f178(get_food_num(t),"卤汁牛肉粉","勺园","面食稀食",t,12,2,1,2,2,1,3,1);
write_file(f178,f178.gettype());
Food f179(get_food_num(t),"沙茶牛肉粉","勺园","面食稀食",t,12,2,1,4,2,1,3,1);
write_file(f179,f179.gettype());
Food f181(get_food_num(t),"打卤面","勺园","面食稀食",t,5,3,1,1,1,1,2,2);
write_file(f181,f181.gettype());
Food f182(get_food_num(t),"鸡丝凉面","勺园","定食套餐",t,8,1,1,3,1,1,2,1);
write_file(f182,f182.gettype());
Food f183(get_food_num(t),"锡纸肥牛粉","勺园","湖南风味",t,16,2,1,3,3,2,2,1);
write_file(f183,f183.gettype());
Food f185(get_food_num(t),"锡纸鱼豆腐粉","勺园","湖南风味",t,16,2,1,3,2,1,3,2);
write_file(f185,f185.gettype());
Food f186(get_food_num(t),"大盘鸡","勺园","西北面食",t,8,2,1,4,2,1,3,1);
write_file(f186,f186.gettype());
Food f187(get_food_num(t),"黄焖豆腐米饭","勺园","湖南风味",t,8,1,2,1,2,1,3,1);
write_file(f187,f187.gettype());
Food f188(get_food_num(t),"黄焖鸡米饭","勺园","湖南风味",t,8,1,2,1,2,2,2,1);
write_file(f188,f188.gettype());
Food f189(get_food_num(h),"椒盐虾","勺园","风味炒菜",h,2,4,1,1,3,1,3,1);
write_file(f189,f189.gettype());
Food f190(get_food_num(h),"豆泡红烧肉","勺园","风味炒菜",h,10,1,1,1,3,3,2,1);
write_file(f190,f190.gettype());
Food f191(get_food_num(h),"农家烧炒鸡","勺园","风味炒菜",h,12,2,1,3,3,2,3,1);
write_file(f191,f191.gettype());
    Food f22(get_food_num(h),"孜然炒烤肉","家园","南区热菜",h,6,4,1,2,3,3,2,1);
    write_file(f22,f22.gettype()); 
Food f156(get_food_num(h),"韭香鸭血","燕南","川菜湘菜",h,9,1,1,1,2,1,2,1);
write_file(f156,f156.gettype());
Food f94(get_food_num(s),"冰糖银耳汤","农园","轻食粗粮",s,1.5,1,3,1,2,1,1,2);
write_file(f94,f94.gettype());  
Food f95(get_food_num(s),"芝士焗红薯","农园","轻食粗粮",s,5,3,3,1,3,3,2,3);
write_file(f95,f95.gettype());    
Food f147(get_food_num(h),"炸鸡排","学五","合利屋",h,10,2,1,1,3,3,3,1);
write_file(f147,f147.gettype());
Food f206(get_food_num(b),"尖椒肉丝","勺园","风味炒菜",b,10,2,1,4,2,1,2,3);
write_file(f206,f206.gettype());
Food f207(get_food_num(s),"菠菜炒鸡蛋","勺园","风味炒菜",s,6,2,1,1,1,1,1,3);
write_file(f207,f207.gettype());
Food f208(get_food_num(s),"三鲜豆腐汤","勺园","风味炒菜",s,5,3,1,1,1,1,3,2);
write_file(f208,f208.gettype());
Food f146(get_food_num(h),"盐水鸡肝","农园","5元菜品自选区",h,4,5,1,1,2,1,3,1);
write_file(f146,f146.gettype()); 
Food f90(get_food_num(t),"香辣鱿鱼拌饭","学五","校园快餐",t,18,3,2,3,2,1,3,2);
write_file(f90,f90.gettype()); 
Food f5(get_food_num(t),"特色烤肉拌饭","学五","校园快餐",t,16,4,2,1,3,2,2,2);
write_file(f5,f5.gettype()); 
Food f159(get_food_num(h),"水煮肉片","燕南","鲁菜浙菜",h,10,1,1,1,3,2,2,1);
write_file(f159,f159.gettype());
Food f184(get_food_num(t),"锡纸麻辣粉","勺园","湖南风味",t,16,2,1,4,2,1,2,2);
write_file(f184,f184.gettype());     
Food f100(get_food_num(t),"孜然肥牛拌饭","学五","校园快餐",t,18,4,2,2,3,2,3,2);
write_file(f100,f100.gettype());  
Food f209(get_food_num(s),"香菇烧豆腐","勺园","时蔬素菜",s,5,2,2,1,1,1,3,3);
write_file(f209,f209.gettype());
Food f210(get_food_num(s),"鸡蛋西葫芦","勺园","时蔬素菜",s,6,1,2,1,1,1,3,2);
write_file(f210,f210.gettype());
Food f211(get_food_num(s),"手撕包菜","勺园","时蔬素菜",s,3,1,1,1,1,1,1,3);
write_file(f211,f211.gettype());
Food f218(get_food_num(t),"木桶鸡肉饭","农园","潇湘风味",t,12,2,1,3,2,2,3,2);
write_file(f218,f218.gettype()); 
Food f219(get_food_num(t),"烩面","农园","面条汤粉",t,10,3,2,1,2,1,2,1);
write_file(f219,f219.gettype()); 
Food f220(get_food_num(t),"砂锅小酥肉","农园","砂锅铁板",t,9,2,2,1,2,2,3,2);
write_file(f220,f220.gettype()); 
Food f221(get_food_num(t),"铁板鱿鱼饭","农园","砂锅铁板",t,14,3,1,3,2,2,3,1);
write_file(f221,f221.gettype()); 
Food f222(get_food_num(t),"羊肉冒菜","农园","四川冒菜",t,7,2,2,4,2,1,3,2);
write_file(f222,f222.gettype()); 
Food f223(get_food_num(t),"牛肉米粉","农园","特色米粉",t,12,2,1,4,2,1,2,2);
write_file(f223,f223.gettype()); 
Food f224(get_food_num(t),"家常豆腐饭","农园","拼味套餐",t,7,2,2,3,2,1,3,1);
write_file(f224,f224.gettype());  
Food f118(get_food_num(s),"蓑衣干子","学五","湖南米粉",s,2,2,2,1,1,1,2,2);
write_file(f118,f118.gettype());  
Food f119(get_food_num(s),"卤蛋","学五","湖南米粉",s,2,4,1,1,2,1,3,1);
write_file(f119,f119.gettype());  
Food f121(get_food_num(s),"老长沙卤味拌粉","学五","湖南米粉",s,9,3,1,1,2,2,2,2);
write_file(f121,f121.gettype()); 
Food f114(get_food_num(b),"海鲜乌冬面","学五","合利屋",b,25,1,1,1,2,1,3,1);
write_file(f114,f114.gettype());
Food f198(get_food_num(h),"西湖仔鸡","勺园","浙江风味",h,13,1,1,3,3,2,2,1);
write_file(f198,f198.gettype());
Food f199(get_food_num(b),"五彩肉沫蒸粉丝","勺园","浙江风味",b,8,2,2,3,3,2,2,1);
write_file(f199,f199.gettype());
Food f200(get_food_num(b),"肉沫鸡蛋羹","勺园","湖南风味",b,3,1,2,1,2,2,3,1);
write_file(f200,f200.gettype());
Food f225(get_food_num(s),"风味小土豆","农园","江南风味",s,6,3,1,2,2,1,1,1);
write_file(f225,f225.gettype()); 

//    Food f316(get_food_num(s),"荷色","勺园","浙江风味",s,7,2,1,1,1,1,2,3);
    cout<<"-------------------------------------------\n";
//    cout<<judge_repeat(f316)<<endl;	
//    add_reset_file(f316);
    // int nnum=0;
    // int tt=get_food_num(h);
    // cout<<h<<endl;
    // for(int i = 0; i < tt; ++i){
    // 	Food temp;
    //     temp=read_file(i,h);
    //     cout<<temp.getname()<<"   "<<temp.getnumber()<<"    "<<temp.getcanteen()<<endl;
        
    // } 

    // cout<<get_food_num(s)<<endl;
    // cout<<get_food_num(h)<<endl;
    // cout<<get_food_num(b)<<endl;
    // cout<<get_food_num(t)<<endl;
    // int tt=get_food_num(s);
    // cout<<s<<endl;
    // for(int i = 0; i < tt; ++i){
    // 	Food temp;
    // 	temp=read_file(i,s);
    //     if(temp.getcanteen()=="农园"){
    //     cout<<temp.getname()<<"   "<<temp.getnumber()<<endl;
    //     //nnum++;
    //     }
    // }
    // } 
    // tt=get_food_num(b);
    // cout<<b<<endl;
    // for(int i = 0; i < tt; ++i){
    // 	Food temp;
    // 	temp=read_file(i,b);
    //     if(temp.getcanteen()=="农园"){
    //     cout<<temp.getname()<<"   "<<temp.getnumber()<<endl;
    //     nnum++;
    //     }
    // } 
    // tt=get_food_num(t);
    // cout<<t<<endl;
    // for(int i = 0; i < tt; ++i){
    // 	Food temp;
    // 	temp=read_file(i,t);
    //     if(temp.getcanteen()=="农园"){
    //     cout<<temp.getname()<<"   "<<temp.getnumber()<<endl;
    //     nnum++;
    //     }
    // } 
    // cout<<nnum<<endl;
    // return 0;
    // Dish_Package P,sl;
    // read_all_file(P,0);
    // Calrandom_weight_forPack(P);
    // sl=Weighted_random(P);

}