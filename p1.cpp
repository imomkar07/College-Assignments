#include<iostream>
#include<cstring>
using namespace std;

/*DATA TYPES AND VARIABLES ARE DECLARED*/
class Employee{
    public:
     int iEmpId;
     string sName,sCity;
};

class HashTable
{
    private:
    Employee Data[10];
    public:
    HashTable()
    {
        for(int i=0;i<10;i++)
        {
          Data[i].sName="";
          Data[i].iEmpId=-1;
          Data[i].sCity="";
        }
    }

    int HashValue(int num)
    {
        int iHash_Value;
        iHash_Value = num%10;
        return iHash_Value;
    }


    void insertRecord_linear(string name, int id, string city)
    {
        int index = HashValue(id);
        if(Data[index].iEmpId==-1)
        {
            Data[index].iEmpId = id;
            Data[index].sName = name;
            Data[index].sCity=city;
        }
        else
        {
            int Newindex;
          Newindex = index+1;
          while(Newindex!=index)
          {
            if(Data[Newindex].iEmpId==-1)
            {
               Data[Newindex].iEmpId = id;
               Data[Newindex].sName = name;
               Data[Newindex].sCity=city;
               break;
            }
            Newindex=(Newindex+1)%10;
          }
        }        
    }

    void search_linear()
    {
        int num;
        cout<<"Employee id to be searched = ";
        cin>>num;
        int Hvalue;
        Hvalue=HashValue(num);
        if(Data[Hvalue].iEmpId==num)
        {
            cout<<"Details of employee id "<<num<<" is :"<<endl;
            cout<<"Name : "<< Data[Hvalue].sName<<endl;
            cout<<"Id : "<< Data[Hvalue].iEmpId<<endl;
            cout<<"City : "<< Data[Hvalue].sCity<<endl;
        }
        else
        {
          int Newindex;
          Newindex = Hvalue+1;
          while(Newindex!=Hvalue)
          {
            if(Data[Newindex].iEmpId==num)
            {
                cout<<"Details of employee id "<<num<<" is:"<<endl;
                cout<<"Name : "<< Data[Newindex].sName<<endl;
                cout<<"Id : "<< Data[Newindex].iEmpId<<endl;
                cout<<"City : "<< Data[Newindex].sCity<<endl;    
               break;
            }
            Newindex=(Newindex+1)%10;
          }
          if(Data[Newindex].iEmpId!=num){
          cout<<"ENTER VALID EMPLOYEE ID";
          }
        }
    }
    
     void insertRecord_quadratic(string name, int id, string city)
    {
        int index = HashValue(id);
        if(Data[index].iEmpId==-1)
        {
            Data[index].iEmpId = id;
            Data[index].sName = name;
            Data[index].sCity=city;
        }
        else
        {
        for(int i=1; i<100; i++)
         {   
          int Newindex;
          Newindex = (index+(i*i))%10;
          if(Newindex!=index)
          {
            if(Data[Newindex].iEmpId==-1)
            {
               Data[Newindex].iEmpId = id;
               Data[Newindex].sName = name;
               Data[Newindex].sCity=city;
               break;
            }
          }
         }
        }
    }

    void search_quadratic()
    {
        int num;
        cout<<"Employee id to be searched = ";
        cin>>num;
        int Hvalue;
        Hvalue=HashValue(num);
        if(Data[Hvalue].iEmpId==num)
        {
            cout<<"Details of employee id "<<num<<" is :"<<endl;
            cout<<"Name : "<< Data[Hvalue].sName<<endl;
            cout<<"Id : "<< Data[Hvalue].iEmpId<<endl;
            cout<<"City : "<< Data[Hvalue].sCity<<endl;
        }
        else
        {
        for(int i=1; i<100; i++)
        {
          int Newindex;
          Newindex = (Hvalue+(i*i))%10;
          if(Newindex!=Hvalue)
          {
            if(Data[Newindex].iEmpId==num)
            {
                cout<<"Details of employee id "<<num<<" is:"<<endl;
                cout<<"Name : "<< Data[Newindex].sName<<endl;
                cout<<"Id : "<< Data[Newindex].iEmpId<<endl;
                cout<<"City : "<< Data[Newindex].sCity<<endl;    
               break;
            }
          }
          if(Data[Newindex].iEmpId!=num)
          {
          cout<<"ENTER VALID EMPLOYEE ID";
          }
        }
        }
    }
};

int main()
{
    HashTable ht;
    cout<<"Enter probing method"<<endl<<"1.linear"<<endl<<"2.Quadratic"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1 :
             cout<<"linear probing is executed"<<endl;
             for (int i = 0; i < 4; i++) 
             {
                string name, city;
                int id;
        
                cout << "Enter details for employee " << i + 1 << ":" << endl;
                cout << "Name: ";
                cin >> name;
                cout << "ID: ";
                cin >> id;
                cout << "City: ";
                cin >> city;
                ht.insertRecord_linear(name, id, city);
            }
            break;
        case 2 :
             cout<<"Quadratic probing is executed"<<endl;
             for (int i = 0; i < 3; i++) 
             {
                string name, city;
                int id;
        
                cout << "Enter details for employee " << i + 1 << ":" << endl;
                cout << "Name: ";
                cin >> name;
                cout << "ID: ";
                cin >> id;
                cout << "City: ";
                cin >> city;
                ht.insertRecord_quadratic(name, id, city);
            }
            break;
    }
   if(choice==1)
   {
      ht.search_linear(); 
   }
   else if(choice==2)
   {
       ht.search_quadratic();
   }
}
