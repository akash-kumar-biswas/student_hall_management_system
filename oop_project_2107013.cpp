//Coded by Akash Biswas 
//Roll: 2107013
//Session: 2021-2022 
#include<bits/stdc++.h>
using namespace std;

class student{
    private:

    string name;
    int id;
    int roll;
    int room_number;
    string dept;
    double halldue=0.0;
    bool HalldueStatus=false;  

    public:

    student(){

    } 

    student(string name,int id,int roll,int room_number,string dept){
        this->name=name;
        this->id=id;
        this->roll=roll;
        this->room_number=room_number;
        this->dept=dept;
    }

    void set_halldue(double halldue){
        HalldueStatus=true;
        this->halldue=this->halldue+halldue;
    }

    void pay_off_halldue(double money){
       if(money<this->halldue) this->halldue=this->halldue-money;

       else {
        this->halldue=0.0;
        HalldueStatus=false;
       }  
    }

    bool get_SetHallDueStatus(){
        return HalldueStatus;
    }
   
    double get_halldue(){
        return halldue;
    }

    void display_student(){
        cout<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Roll: "<<roll<<endl<<"Room Number: "<<room_number<<endl<<"Dept: "<<dept<<endl;
    }

    int get_id(){
        return id;
    }

    int get_room_number(){
        return room_number;
    }

    string get_name(){
        return name;
    }

    string get_dept(){
        return dept;
    }

    int get_roll(){
        return roll;
    }

    void remove_student(){
        name=" ";
        id=0;
        roll=0;
        dept=" ";
    }
};

class staff{
    private:

    string name;
    int id;
    string position;
    
    public:

    staff(){

    }

    staff(string name,int id,string position){
        this->name=name;
        this->id=id;
        this->position=position;
    }

    void display_staff(){
        cout<<"name: "<<name<<endl<<"id: "<<id<<endl<<"position: "<<position<<endl;
    }
};

class meal{
    private:

    string name;
    int id;
    string date1;
    string date2;
    bool MealOnStatus;  

    public:

    void meal_off(string name,int id,string date1,string date2){
        if(MealOnStatus==true){
        this->name=name;
        this->id=id;
        this->date1=date1;
        this->date2=date2;
        MealOnStatus=false;
        cout<<"\nMeal off successfully."<<endl;
        }
        else cout<<"\nMeal is already off."<<endl;
    }

     void meal_on(string name,int id,string date1,string date2){
        if(MealOnStatus==false){
        this->date1=date1;
        this->date2=date2;
        MealOnStatus=true;
        cout<<"\nMeal on successfully."<<endl;
        }
        else cout<<"\nMeal is already on."<<endl;
    }

    void display_meal(){
        if(MealOnStatus){
            cout<<"\nYour meal is on from "<<date1<<" to "<<date2<<"."<<endl;
        }
        else cout<<"\nYour meal is off from "<<date1<<" to "<<date2<<"."<<endl;
    } 

};

class hall_manager{
   private:

   student arr1[500];
   staff arr2[50];
   meal arr3[500]; 
   int total1;
   int total2;
   
   public:
   hall_manager(){
    total1=0;
    total2=0;
   }

   void Add_New_Student(string name,int id,int roll,int room_number,string dept){
       if(total1>500){
        cout<<"Hall is full.Cann't added more student.<<endl";
        return;
       }
       for(int i=0;i<500;i++){
          if(arr1[i].get_id()==0 && arr1[i].get_name()==" " && arr1[i].get_roll()==0 && arr1[i].get_dept()==" "){
            arr1[i]=student(name,id,roll,arr1[i].get_room_number(),dept);
            cout<<"\nThe student with id "<<id<<" added successfully and allocated room no. is: "<<arr1[i].get_room_number()<<endl;
            total1++;
            return;
          }
       }
       arr1[total1]=student(name,id,roll,room_number,dept);
       cout<<"\nThe student with id "<<id<<" added successfully and allocated room no. is: "<<room_number<<endl;
       total1++;
   }

   void Remove_Student(string name,int id){
    cout<<"\nRemove the student with id: "<<id<<endl;
     for(int i=0;i<500;i++){
        if(arr1[i].get_id()==id && arr1[i].get_name()==name){
             arr1[i].remove_student();
             cout<<"The Student with id "<<id<<" removed successfully."<<endl;
             total1--;
             return;
        }
     }
     cout<<"Can't found the student with id "<<id<<"\n"<<endl;
   }

    void Display_All_Student(){
    cout<<"\nDisplay all current student in this hall:"<<endl;
    int count=1;
    for(int i=0;i<500;i++){
        if(arr1[i].get_dept()=="CSE"||arr1[i].get_dept()=="EEE"||arr1[i].get_dept()=="ME"||arr1[i].get_dept()=="CE"
        ||arr1[i].get_dept()=="URP"||arr1[i].get_dept()=="ARCH") {
        cout<<"("<<count<<"):"<<endl;
        arr1[i].display_student();
        count++;
        cout<<endl;
        }
    }
   }

    void Set_Halldue(string name,int id,double halldue){
        cout<<"\nSet hall due of the student with id: "<<id<<endl;
        for(int i=0;i<500;i++){
            if(arr1[i].get_id()==id && arr1[i].get_name()==name){
                arr1[i].set_halldue(halldue);
                cout<<"Hall due set successfully of the student with id: "<<id<<"\n"<<endl;
                return;
            }
        }
        cout<<"Cann't found the student with id: "<<id<<"\n"<<endl;
    }

    void Display_Halldue(string name,int id){
        cout<<"\nView halldue of the student with id: "<<id<<endl;
        for(int i=0;i<500;i++){
            if(arr1[i].get_id()==id && arr1[i].get_name()==name){
                cout<<"Hall due of the student with id "<<id<<" is: "<<arr1[i].get_halldue()<<" Taka.\n"<<endl;
                return;
            }
        }
     cout<<"Cann't found the student with id: "<<id<<"."<<"\n"<<endl;
    }

    void Pay_Off_Halldue(string name,int id,double money){
            cout<<"\nPay off hallldue of the student with id: "<<id<<endl;
            for(int i=0;i<500;i++){
            if(arr1[i].get_id()==id && arr1[i].get_name()==name){
                if(arr1[i].get_SetHallDueStatus()){
                 arr1[i].pay_off_halldue(money);
                 cout<<"Paid off halldue successfully."<<endl;
                 return;
                }
                else{
                    cout<<"Paid off halldue is not successful."<<endl;
                    return;
                }
            }
        }
    }

     void Add_New_Staf(string name,int id,string position){
        cout<<"\nAdd new staf with id: "<<id<<endl;
          if(total2>50){
            cout<<"\nCann't added more staff"<<endl;
            return;
          }
         arr2[total2]=staff(name,id,position);
         total2++;
         cout<<"The staf with id "<<id<<" added successfully."<<endl;
         return;
    }

   void Display_All_Staff(){
    cout<<"\nDisplay all current staff in this hall:"<<endl;
    int count=1;
    for(int i=0;i<total2;i++){
        cout<<"("<<count<<"):"<<endl;
        arr2[i].display_staff();
        count++;
        cout<<endl;
    } 
   }

   void Meal_off(string name,int id,string date1,string date2){
        for(int i=0;i<500;i++){
          if(arr1[i].get_id()==id && arr1[i].get_name()==name){
            arr3[i].meal_off(name,id,date1,date2);
          }
       }
   } 

    void Meal_On(string name,int id,string date1,string date2){
        for(int i=0;i<500;i++){
          if(arr1[i].get_id()==id && arr1[i].get_name()==name){
            arr3[i].meal_on(name,id,date1,date2);
          }
       }
   }

   void Display_Meal(string name,int id){
       for(int i=0;i<500;i++){
          if(arr1[i].get_id()==id && arr1[i].get_name()==name){
            arr3[i].display_meal();
            return;
          }
       }
   }

   friend void SearchStudent(string,int,hall_manager);

};

void SearchStudent(string name,int id,hall_manager obj){
    cout<<"\n";
    for(int i=0;i<500;i++){
        if(obj.arr1[i].get_name()==name && obj.arr1[i].get_id()==id){
            obj.arr1[i].display_student();
            return;
        }
    }
    cout<<"\nThe student with id "<<id<<" does not exist."<<endl;
}

int main(){

    hall_manager HallManager;
    string name,date1,date2,dept,position;
    int id,roll,RoomNumber;
    double HallDue,Money;
    char cha;
   
    do{  
         system("cls");   

         cout<<"\nPress 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 and 12 to do the following operation: "<<endl;
         cout<<"1.Add new student."<<endl;
         cout<<"2.Remove student."<<endl;
         cout<<"3.Display all student."<<endl;
         cout<<"4.Set halldue."<<endl;
         cout<<"5.Display halldue."<<endl;
         cout<<"6.Pay off halldue."<<endl;
         cout<<"7.Get on meal."<<endl;
         cout<<"8.Get off meal."<<endl;
         cout<<"9.Display meal."<<endl;
         cout<<"10.Add new staff."<<endl;
         cout<<"11.Display all staff."<<endl;
         cout<<"12.Search a student.\n"<<endl;
          
         int n;
         cin>>n;

        switch(n){

           case 1:
           cout<<"\nEnter name, id, roll, room number and department: "<<endl;
           cin>>name>>id>>roll>>RoomNumber>>dept;
           HallManager.Add_New_Student(name,id,roll,RoomNumber,dept);
           break;

           case 2:
           cout<<"\nEnter name and id: "<<endl;
           cin>>name>>id;
           HallManager.Remove_Student(name,id);
           break;

           case 3:
           HallManager.Display_All_Student();
           break;

           case 4:
           cout<<"\nEnter name, id and halldue: "<<endl;
           cin>>name>>id>>HallDue;
           HallManager.Set_Halldue(name,id,HallDue);
           break;

           case 5:
           cout<<"\nEnter name and id: "<<endl;
           cin>>name>>id;
           HallManager.Display_Halldue(name,id);
           break;

           case 6:
           cout<<"\nEnter name, id and money: "<<endl;
           cin>>name>>id>>Money;
           HallManager.Pay_Off_Halldue(name,id,Money);
           break;

           case 7:
           cout<<"\nEnter name, id, date1 and date2: "<<endl;
           cin>>name>>id>>date1>>date2;
           HallManager.Meal_On(name,id,date1,date2);
           break;
           
           case 8:
           cout<<"\nEnter name, id, date1 and date2: "<<endl;
           cin>>name>>id>>date1>>date2;
           HallManager.Meal_off(name,id,date1,date2);
           break;
            
           case 9:
           cout<<"\nEnter name and id: "<<endl;
           cin>>name>>id;
           HallManager.Display_Meal(name,id);
           break;

           case 10:
           cout<<"\nEnter name, id and position: "<<endl;
           cin>>name>>id>>position;
           HallManager.Add_New_Staf(name,id,position);
           break;
           
           case 11:
           HallManager.Display_All_Staff();
           break;
           
           case 12:
           cout<<"\nEnter name and id: "<<endl;
           cin>>name>>id;
           SearchStudent(name,id,HallManager);
           break;

           default:
           cout<<"\nTry again.Can't match."<<endl;
    }

    cout<<"\nPress (Y/y) to return the previous stage."<<endl;
    
    cin>>cha;

}while(cha=='Y' || cha=='y');

return 0;
}
