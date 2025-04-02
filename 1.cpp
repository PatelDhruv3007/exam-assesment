#include<iostream>
#include<fstream>
using namespace std ;

class student 
{
    public:
    int id ;
    string name;
    float percentage;
    char grade;

    void sdata()
    {
        cout<<"Enter student ID = ";
        cin>>id;
        cout<<"Enter student name = ";
        cin>>name;
        cout<<"Enter student percentage = ";
        cin>>percentage;
        calgrade();
    }
    void calgrade() {

        if (percentage > 80) 
        {
            cout<< "grade = 'A'";
        }
        else if (percentage > 60) 
        {
            cout<< "grade = 'B'";
        
        } 
        else if (percentage > 40) 
        {
            cout<< "grade = 'C'";
        }
        else 
        {
            cout<< "grade = 'F'";
        }
    }

    void displaystudent()
    {
        cout<<"\nstudent id = "<<id;
        cout<<"\nstudent name = "<<name;
        cout<<"\nstudent percentage  = "<<percentage;
        cout<<"\nstudent  grade = "<<grade;
    }

    void filesave()
    {
        ofstream Myfile("Student.txt");
        Myfile<<id<< " " <<name<< " " <<percentage<< " " <<grade<<endl;
        Myfile.close();
        cout<<"\nstudent data saved";
    }

    void studentview()
    {
        ifstream Myfile("student.txt");
        if(!Myfile)
        {
            cout<<"\nno student data found";
        }
        
        student s;
        while (Myfile>>s.id>>s.name>>s.percentage>>s.grade)
        {
            s.displaystudent();
        }  
        Myfile.close();  
    }   
    void searchsbyid(int sid)
    {
        ifstream Myfile("student.txt");
        if(!Myfile)
        {
            cout<<"\nno student data found";
        }
        
        student s;
        while (Myfile>>s.id>>s.name>>s.percentage>>s.grade)
        {
            if (s.id == sid)
            {
                s.displaystudent();
            }
            
            
        } 
    }
};

class teacher 
{
    public:
    int id;
    string name;
    string subject;
    double salary ;

    void tdata()
    {
        cout<<"Enter teacher ID = ";
        cin>>id;
        cout<<"Enter teacher name = ";
        cin>>name;
        cout<<"Enter teacher sublect = ";
        cin>>subject;
        cout<<"Enter teacher salary = ";
        cin>>salary;
    }

    void displayteacher()
    {
        cout<<"\nteacher id = "<<id;
        cout<<"\nteacher name = "<<name;
        cout<<"\nteacher subject  = "<<subject;
        cout<<"\nteacher  salary = "<<salary;
    }
    void filesave()
    {
        ofstream Myfile("teacher.txt");
        Myfile<<id<< " " <<name<< " " <<subject<< " " <<salary<<endl;
        Myfile.close();
        cout<<"\nteacher data saved";
    }

    void teacherview()
    {
        ifstream Myfile("teacher.txt");
        if(Myfile)
        {
            cout<<"\nno teacher data found";
        }
        teacher t;
        while (Myfile>>t.id>>t.name>>t.subject>>t.salary)
        {
            t.displayteacher();
        }
        Myfile.close();
    }

    void searchtbyid(int tid)
    {
        ifstream Myfile("teacher.txt");
        if(!Myfile)
        {
            cout<<"\nno teacher data found";
        }
        
        teacher t;
        while (Myfile>>t.id>>t.name>>t.subject>>t.salary)
        {
            if (t.id == tid)
            {
                t.displayteacher();
            }
            
            
        } 
    }
    
};
int main()
{
    int choice;
    cout<<"\npress 1 for add student";
    cout<<"\npress 2 for add teacher";
    cout<<"\npress 3 for view student";
    cout<<"\npress 4 for view teacher";
    cout<<"\npress 5 for seach bu student id";
    cout<<"\npress 6 for seach by teacher id";
    cout<<"\npress 7 for exit";
    cout<<"\nEnter your choice = ";
    cin>>choice;

    switch (choice)
    {
    case 1 :
        {
            student s;
            s.sdata();
            s.filesave();
        }
        break;
    case 2 :
        {
            teacher t;
            t.tdata();
            t.filesave();

        }
    break;
    case 3 :
        {
            student s;
            s.studentview();
        }
    break;
    case 4 :
        {
            teacher t;
            t.teacherview();
        }
    break;
    case 5 :
        {
            int id;
            cout<<"enter the id = ";
            cin>>id;
            student s;
            s.searchsbyid(id);
        }
    break;
    case 6 :
        {
            int id;
            cout<<"enter the id = ";
            cin>>id;
            teacher t;
            t.searchtbyid(id);
        }
    break;
    case 7 :
    {
        break;
    }    
    return 0 ;
}