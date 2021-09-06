/*
 This is a student record management system project, which enables you to create,
read, modify, and delete student Records and make a valid student report card. It utilizes
file handling and shows the class and object of the programming language. It is a very
effective and simple understanding of beginners. This is a simple project in C++, built as a
console application.
 The Student Record Management project is designed in ‘C++’ language. This system is
based on a concept to store and generate all the records of the students. Also, this
program has a simple database of students for a school where the user can add student
details safely and it’s not time-consuming. This System makes it easy to store records of
each. Moreover, the user can view all the records, modify and remove the details. Also,
this project is easy to operate and understand by the users.this program has the following applications.

o Recording student & course info
o Course registration
o Checking course pre-request
o Find semester load
o Compute cumulative grade
o Generate student rank based on CGP
o Determine Student status (pass/warning/dismissal)
o Produce various statistical report (such as No. of
passed, warned

*/

///////////////////////include libraries//////////////////////////////////////////////////////////////////////////////////////////
 #include <iostream>
 #include <fstream>
 #include <cstring>
 #include <stdlib.h>
 #include <iomanip>
 #include <string>

 using namespace std;
 /////////////////////////////declaring global user name , PIN and other variables/////////////////////////////////////////////////////////
string Admin_Name;
int pin_num = 1234;
int New_pin = 1234;
int choice = 0;
int Size = 0;
int size2 = 0;
int size3 = 0;
bool program_running = true;
bool program_running2 = true;
bool program_running3 = true;
int c = 0;
int c2 = 0;
int c3 = 0;
int n;
int* ptr = &choice;
int* ptr2 = &n;
//////////////////////////////declaring a global structures named PORTAL,course and full ////////////////////////////////////////////////////////////

 struct full
 {
   char f_name[10];
   char m_name[10];
   char l_name[10];
 };

 struct course {

	char course_name[20];
	int credit_hour;
	char course_pre_requsit[40];
	char course_type[20];
	double score;
	double number_grade;
	char letter_grade;

 };

 struct PORTAL {

    full name;
    int id_number;
    long int phone_number;
    char nationality[20];
	char email[30];
    char department[30];
    char major[30];
    char type[30];
	char sex;
	int year_of_learning;
	int academic_year;
    double cumulative_grade;
	char semister_load[25];
    char student_status[20];
	char section;
	course list[0];//////////////////////////////////////////////
	course list2[0];/////////////////////////////////////////////nested structure
 } ;
////////////////////////////////////defining  structure variables///////////////////////////////////////////////////////////////////
PORTAL Student;
PORTAL* student = new PORTAL[Size] ;
course* list=new course[size2];
course* list2=new course[size3];
/////////////////////////////////////Prototyping of functions//////////////////////////////////////////////////////////////////////

 void WELLCOME();
 void THANK_U();
 void MAIN_MENU();
 void ADMIN();
 void OPTION ();
 void EXIT ();
 void HELP ();
 void student_menu ();
 void registrar () ;
 void student_log_in () ;
 void Change_PIN();
 int pin_checker (int &pin_num,int &New_pin);
 void Generate ();
 void register_stu();
 void edit_record ();
 void delete_record ();
 void view_all ();
 //void view_single ();
 void register_course ();
 void delete_record ();
 void digital_id ();
 void slip ();
 void report ();
 void resize_student();
// void delete_menu ();
 void resize_course ();
 void new_course ();
 void register_stu2 ();
 void delete_all_record ();
 void delete_course();
// double calc_CGPA (course list[]},int size2);
 void calc_grade (course list[],int size2);
///////////////////////////////////MAIN FUNCTION////////////////////////////////////////////////////////////////////////////////////
 int main( )
 {


system("color a1");
pin_checker ( pin_num, New_pin);
WELLCOME();


MAIN_MENU ();



 return 0;
 }
///////////////////////////This function reads Thank You text form Thank u.txt and display it/////////////////////////////////////////
 void THANK_U(){

	ifstream ifs ("Thank u.txt");
	string Lines = " ";

    if (ifs)
    {
		while (ifs.good ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";

	    	Lines += TempLine;
		}

	cout << Lines;

	}
    cout<<"\n\t  |\t\t\t\t\t\t\t";
    ifs.close ();

}

 ////////////////////////////this function reads 3D Welcome text form welcome.txt and dispaly it////////////////////////////////////////

 void WELLCOME()
{
system("color 09");

	ifstream ifs ("welcome.txt");
	string Lines = "";

    if (ifs)
    {
		while (ifs.good ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";

	    	Lines += TempLine;
		}

	cout << Lines;


	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    void MAIN_MENU ()
	{
		
		 for (int i=0;i<4;i++)
   
    {

    cout <<"\n****************************************************************************************************************\n";
    cout <<endl;
    cout <<"\tADDIS ABABA SCIENCE AND TECHNOLOGY UNIVERSITY \n";
    cout <<"\tFUNDAMENTALS OF PROGRAMMING 2  \n";
    cout <<"\tGROUP PROJECT  \n";
    cout <<"\tSTUDENT RECORD MANAGEMENT SYSTEM \n";
    cout <<endl;
    cout <<"******************************************************************************************************************\n";
    cout <<"1: REGISTRAR\n";
    cout <<"2: STUDENT\n";
    cin>>*ptr;

   	    if(*ptr==1)
		   {
             ADMIN();
             break;
	       }
        else if(*ptr==2)
           {
             student_log_in ();
             break;
           }
        else
		{
			cout<<"Wrong input. You have "<<3-i<<" chances. Please choose from 1 and 2."<<endl;
		}
   }
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OPTION ()
{
	cout<<"#########################################################################"<<endl;
	cout<<"##\t\t1. MAIN MENU                                            ##"<<endl;
	cout<<"##\t\t2. HELP                                                 ##"<<endl;
	cout<<"##\t\t3. REGISTRAR                                            ##"<<endl;
	cout<<"##\t\t4. STUDENT                                              ##"<<endl;
    cout<<"##\t\t5. CHANGE USER_NAME & PASSWORD                          ##"<<endl;
    cout<<"##\t\t6. EXIT THE PROGRAM                                     ##"<<endl;
    cout<<"#########################################################################"<<endl;

    cin>>*ptr;

	switch(*ptr)
	{
	case 1:
		MAIN_MENU ();
		break;
    case 2:
		HELP ();
		break;
    case 3:
     	registrar ();
		break;
    case 4:
        student_log_in ();
		break;
	    case 5:
		Change_PIN ();
		break;
    case 6:
		EXIT ();
		break;


	default:
		cout <<"******************************************************************************************************************\n";
		cout<<"Invalid entry. This program will terminate."<<endl;
		cout <<"******************************************************************************************************************\n";
		EXIT ();
		break;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void EXIT ()
 {
 	cout <<"\n****************************************************************************************************************\n";
     	THANK_U();
 	    cout<<"\nVersion: 1.0.0"<<endl;
        cout<<"Build date: SEPTEMPER 2 2021"<<endl;
        cout<<"Build number: 0718.22/12"<<endl;
        cout<<"Built by GROUP 3 plc"<<endl;
        cout<<"Copyright\n All rights reserved."<<endl;
        cout <<"\n****************************************************************************************************************\n";
		cout<<"Credits"<<endl;
        cout <<"\n****************************************************************************************************************\n";
        cout<<"YOSEF LAKEW           ETS 0722/12"<<endl;
        cout<<"DIRSHAYE YISHAK       ETS 0980/12"<<endl;
        cout<<"ABEBE BIRU            ETS 0751/12"<<endl;
        cout<<"VANILLA GETACHEW      ETS 0652/12"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;

 		cout <<"\n****************************************************************************************************************\n";
 }

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void ADMIN(){

    int pin;
cout <<"\n****************************************************************************************************************\n" ;
    for(int i=4; i>0; i--){

    cout<<"Enter the Admin name: ";
    cin>>Admin_Name;
    if(Admin_Name=="AASTU" || Admin_Name=="aastu"  ){
        cout<<"Enter the PIN: ";
        cin>>pin;

        if(pin==pin_num){
            registrar ();
          break;
        }

        else
        {
            if(i==1){
                cout<<"You Lost Your Chances!!"<<endl;
                OPTION ();

            }
            else
            {
            cout<<Admin_Name<<" You Entered Wrong PIN!\n \tTry again you have "<<i-1<<" chance\n\t";

            }

        }


    }
    else{
            if(i==1){
                cout<<"You Lost Your Chances!!"<<endl;
                OPTION ();
            }
            else
            {
                cout<<"Wrong User name\n\t Try again you have "<<i-1<<" chance\n\t";
            }
    }

    }
    cout <<"\n****************************************************************************************************************\n";
}

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void HELP ()
 {
      cout << "Sorry. We cannot help right now. Please try later.\n";
	  cout << "Or enter this website: https://www.group3documentationc++.com\n";  
     cout<<"Build date: SEPTEMPER, 2, 2021 GC"<<endl;
        cout<<"Build number: 0718.22/12"<<endl;
        cout<<"Built by GROUP 3 plc"<<endl;
 	





 }

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void student_menu()
 {
cout <<"\n****************************************************************************************************************\n";
 	    cout<<"\t\t1. VIEW YOUR RECORD"<<endl;
        cout<<"\t\t2. GENERATE YOUR GRADE REPORT"<<endl;
        cout<<"\t\t3. GENERATE YOUR DIGITAL ID"<<endl;
        cout<<"\t\t4. GENERATE YOUR SLIP"<<endl;
        cout<<"\t\t5. YOUR RANK"<<endl;
        cout<<"\t\t6. MORE OPTIONS"<<endl;
cout <<"\n****************************************************************************************************************\n" ;
		cin>>*ptr;
cout <<"\n****************************************************************************************************************\n" ;
        switch(*ptr)
		{
     case 1:
		break;
     case 2:
		break;
     case 3:
		break;
     case 4:
	    break;	
     case 5:
		break;	
     case 6:
     	OPTION ();
			break;

     default:
     	cout<<"Invalid input."<<endl;
     	OPTION ();
			break;
		}

 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void registrar ()
 {
 	cout <<"\n****************************************************************************************************************\n";
        cout<<"\t\t1.  REGISTER A NEW STUDENT"<<endl;
        cout<<"\t\t2.  DELETE A STUDENT RECORD"<<endl;
        cout<<"\t\t3.  GENERATE STUDENTS RECORD"<<endl;
        cout<<"\t\t4.  ERASE AN EXISTING COURSE"<<endl;
        cout<<"\t\t5.  GENERATE STUDENTS DIGITAL ID"<<endl;
        cout<<"\t\t6.  GENERATE STUDENTS SLIP"<<endl;
        cout<<"\t\t7.  GENERATE STUDENTS CGPA"<<endl;
        cout<<"\t\t8.  GENERATE STATISTICAL REPORT OF STUDENTS"<<endl;
        cout<<"\t\t9.  MORE OPTIONS"<<endl;
 	cout <<"\n****************************************************************************************************************\n";

 	cin>>*ptr;
 	cout <<"\n****************************************************************************************************************\n";

 	switch(*ptr)
	 {
         case 1:
         register_stu ();
		 break;
         case 2:
       // delete_menu ();
		 break;
         case 3:
   	     Generate ();
		 break;
         case 4:
         delete_course();
		 break;
         case 5:
		 break;
	 	 case 6:
		 break;
	 	 case 7:
		 break;
	 	 	 case 8:
		 break;
	 	 case 9:
	 	 	OPTION ();
		 break;
	    default:
	 	    OPTION ();
		 break;
	 }
 	cout <<"\n****************************************************************************************************************\n";


 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void student_log_in ()
   {
   	cout <<"\n****************************************************************************************************************\n";
   	cout<<"Enter your ID number: "<<endl;
   	cin>>Student.id_number;
   	/// ()

       student_menu();


   	cout <<"\n****************************************************************************************************************\n";
   }

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Change_PIN ( ){



    int current_pin;
    cout<<"Enter the admin Name: ";
    cin>>Admin_Name;
    cout<<"Enter the current PIN: ";
    cin>>current_pin;



    if(current_pin==pin_num && Admin_Name == "AASTU")
	{

        cout<<"Enter the new PIN: ";
        cin>>New_pin;

         pin_checker (pin_num,New_pin);

cout <<"\n****************************************************************************************************************\n";
cout<<"You have changed your password successfully."<<endl;
cout <<"\n****************************************************************************************************************\n";
OPTION ();


}
    else{
        cout<<"Sorry you entered wrong value!"<<endl;
        OPTION ();

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pin_checker (int &pin_num,int &New_pin)
{

	pin_num=New_pin;
	return pin_num;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void register_stu ()
{
	student[0].id_number=1000;

	cout <<"Registor a new student"<<endl;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Please answer all of the questions below. "<<endl;
    cout <<"\n----------------------------------------------------------------------------------------------------------------\n";

	while (program_running)
	{

    cout <<"\n****************************************************************************************************************\n";
	cout <<"Student "<<c+1<<endl;
    cout <<"\n****************************************************************************************************************\n";
	cout <<"Full name"<<endl;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Student's name : "<<endl;
	cin  >>student[c].name.f_name;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"His/her father's name : "<<endl;
    cin  >>student[c].name.m_name;
    cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"His/her grandfather's name : "<<endl;
    cin  >>student[c].name.l_name;
	cout <<"\n------------------------------------------course* list=new course[size2];----------------------------------------------------------------------\n";
	student[c].id_number++;
    cout <<"ID-Number : "<<student[c].id_number<<endl;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Nationality"<<endl;
    cout <<"1: ETHIOPIAN\n";
    cout <<"2: OTHER\n";
    cout <<"Your response : ";
    cin>>*ptr;
    cout <<"Student's Phone-number"<<endl;
    cout <<"Your response :+251";
    cin  >>student[c].phone_number;

    switch(*ptr)
	{
	case 1:
        strncpy(student [c].nationality, "Ethiopian", 14);
        break;

    case 2:

    	cin>>student[c].nationality;
		break;

	default:
		cout<<"Invalid input"<<endl;
		OPTION();
		break;
	}

	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"E-mail"<<endl;
    cout <<"Your response : ";
    cin  >>student[c].email;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Sex"<<endl;
    cout <<"1: MALE\n";
    cout <<"2: FEMALE\n";
    cout <<"Your response : ";
    cin  >>*ptr;
    switch(*ptr)
	{
	case 1:
		student[c].sex='M';
		break;
	case 2:
		student[c].sex='F';
		break;
	default:
		cout<<"Invalid input"<<endl;
		OPTION();
	}
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Department"<<endl;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"1: ARCHITECTURE\n";
    cout <<"2: SOFTWARE ENGINEERING\n";
    cout <<"3: MECHANICAL ENGINEERING\n";
    cout <<"4: ELECTRICAL ENGINEERING\n";
    cout <<"5: ELECTRO MECHANICAL ENGINEERING\n";
    cout <<"6: ENVIRONMENTAL ENGINEERING\n";
	cout <<"7: CIVIl ENGINEERING\n";
	cout <<"your response : ";
	cin  >>*ptr;
	switch(*ptr)
	{
	    case 1:
	    	strncpy(student [c].department, "ARCHITECTURE",30);
		break;
		case 2:
			strncpy(student [c].department, "SOFTWARE ENGINEERING",30);
		break;
		case 3:
			strncpy(student [c].department, "MECHANICAL ENGINEERING",30);
		break;
		case 4:
			strncpy(student [c].department, "ELECTRICAL ENGINEERING",30);
		break;
		case 5:
			strncpy(student [c].department, "ELECTRO MECHANICAL ENGINEERING",30);
		break;
		case 6:
			strncpy(student [c].department, "ENVIRONMENTAL ENGINEERING",30);
		break;
		case 7:
			strncpy(student [c].department, "CIVIl ENGINEERING",30);
		break;
	default:
		OPTION();
		break;
	}



    cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	/*cout <<"program major (i.e Bsc,masters)"<<endl;
    cout <<"1: BACHELOR\n";
    cout <<"2: MASTER\n";
    cout <<"3: OTHERS\n";
    cout <<"your response : ";
    cin  >>*ptr;
    switch(*ptr)
	{
	case 1:
		strncpy(student [c].major, "Bachelor",10);
	    break;
    case 2:

    	strncpy(student [c].major, "MASTER",10);
		break;
	case 3:
		cin>> student[c].major;
		break;
	default:
		cout<<"invalid input"<<endl;
		OPTION();
		break;
	}
*/
  	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Program type (i.e Regular or Extention)"<<endl;
    cout <<"1: REGULAR\n";
    cout <<"2: EXTENSION (Night)\n";
    cout <<"3: EXTENSION (Distance)\n";
    cout <<"4: EXTENSION (Weekend)\n";
    cout <<"5: EXTENSION (Summer)\n";
    cout <<"Your response : ";
    cin  >>*ptr;
    switch(*ptr)
	{
	case 1:

		strncpy(student [c].type, "REGULAR",30);
		break;
	case 2:
		strncpy(student [c].type, "EXTENSION (Night)",30);
		break;
	case 3:
		strncpy(student [c].type, "EXTENSION (Distance)",30);
		break;
	case 4:
		strncpy(student [c].type, "EXTENSION (Weekend)",30);
		break;
	case 5:
		strncpy(student [c].type, "EXTENSION (Summer)",30);
		break;
	default:
        cout<<"Invalid input"<<endl;
		OPTION();
		break;
	}

	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Year of learning (choose)"<<endl;
    cout <<"1: FIRST\n";
    cout <<"2: SECOND\n";
    cout <<"3: THIRD\n";
    cout <<"4: FOURTH\n";
    cout <<"5: FIVTH\n";
    cout <<"6: OTHERS\n";
    cout <<"Your response : ";
    cin  >>*ptr;
    switch(*ptr)
	{
	case 1:
		student[c].year_of_learning=1;
		break;
	case 2:
		student[c].year_of_learning=2;
		break;
	case 3:
		student[c].year_of_learning=3;
		break;
	case 4:
		student[c].year_of_learning=4;
		break;
	case 5:
		student[c].year_of_learning=5;
		break;
	case 6:
		cin>>student[c].year_of_learning;
		break;
	default:
        cout<<"Invalid input"<<endl;
		OPTION();
		break;
	}
   	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Academic year"<<endl;
	cout <<"Your response : ";
	cin>>student[c].academic_year;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Section"<<endl;
    cout <<"your response : ";
    cin  >>student[c].section;

	 cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
 	cout <<"Did the student take any course?"<<endl;
    cout <<"1: YES\n";
    cout <<"2: NO\n";
    cout <<"Your response : "<<endl;
    cin>>*ptr;
      switch(*ptr)
	{
	case 1:

	cout <<"\n****************************************************************************************************************\n";
	cout <<"Please fill on the following details about the course he took."<<endl;
    cout <<"\n----------------------------------------------------------------------------------------------------------------\n";

    while (program_running2)
	{
	resize_course ();
    cout <<"Course name"<<endl;
    cin  >>student[c].list[c2].course_name;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Credit hours"<<endl;
    cin  >>student[c].list[c2].credit_hour;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Pre request"<<endl;
    cin  >>student[c].list[c2].course_pre_requsit;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Course type"<<endl;
    cin  >>student[c].list[c2].course_type;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
	cout <<"Score"<<endl;
	cin  >>student[c].list[c2].score;
    calc_grade (list,c2  );
	cout <<"\n****************************************************************************************************************\n";
    cout <<"You want to  add another course? "<<endl;
	cout <<"\n****************************************************************************************************************\n";
    cout <<"1: YES\n";
    cout <<"2: NO\n";
    cout <<"Your response : ";
    cin>>*ptr;
	switch(*ptr)
	{
	case 1:
		program_running2=true;
		c2++;
		break;
	case 2:
		program_running2=false;
		OPTION();
		break;
	default:
		OPTION();
		break;
	}

	}
		break;



    case 2:
    new_course ();
    cout <<"\n****************************************************************************************************************\n";
	cout <<"Please fill on the following details about the new course"<<endl;
    cout <<"\n----------------------------------------------------------------------------------------------------------------\n";

    while (program_running3)
	{
    cout <<"Course name"<<endl;
    cin  >>student[c].list2[c3].course_name;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Credit hours"<<endl;
    cin  >>student[c].list2[c3].credit_hour;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Pre request"<<endl;
    cin  >>student[c].list2[c3].course_pre_requsit;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";
    cout <<"Course type"<<endl;
    cin  >>student[c].list2[c3].course_type;
	cout <<"\n----------------------------------------------------------------------------------------------------------------\n";

    cout <<"\n****************************************************************************************************************\n";
	cout <<"You want to registor another new course "<<endl;
	cout <<"\n****************************************************************************************************************\n";
    cout <<"1: YES\n";
    cout <<"2: NO\n";
    cout <<"Your response : ";
    cin>>*ptr;
	switch(*ptr)
	{
	case 1:
		program_running3=true;
		c3++;
		break;
	case 2:
		program_running3=false;
		OPTION();
		break;
	default:
		OPTION();
		break;
	}

	cin.ignore();
	}

		break;
	default:
        cout<<"Invalid input"<<endl;
		OPTION();
		break;
	}



	    cout <<"\n****************************************************************************************************************\n";
	cout <<"You want to registor another student?"<<endl;
	cout <<"\n****************************************************************************************************************\n";
    cout <<"1: YES\n";
    cout <<"2: NO\n";
    cout <<"Your response : ";
    cin>>*ptr;
	switch(*ptr)
	{
	case 1:
		resize_student ();
		c++;
		break;
	case 2:
		program_running=false;
		OPTION();
		break;
	default:
		OPTION();
		break;
	}
	c++;
	}
	}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void Generate ()
 {
 	cout <<"\n****************************************************************************************************************\n";
    cout<<"\t\t1. Select a student"<<endl;
 	cout<<"\t\t2. View all students record"<<endl;
 	cout<<"\t\t3. Other options"<<endl;
 	cout <<"\n****************************************************************************************************************\n";
 	cin>>*ptr;
 	cout <<"\n****************************************************************************************************************\n";
 	switch(*ptr)
	 {
	 case 1:
	 //	view_single ();
		 break;
     case 2:
     	view_all ();
		 break;
     case 3:
     	OPTION();
		 break;
	 default:
	 	OPTION();
		 break;
	 }

 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void delete_record ()
 {

 	cout<<"\n****************************************************************************************************************\n";
 	cout<<"Enter the student's ID: "<<endl;
    cin>>*ptr2;
 	cout<<"\n****************************************************************************************************************\n";
 		for (int i=0;i<Size;i++)
	 {
	 	if(*ptr2==student[c].id_number);





	 }




 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void delete_all_record ()
 {

 	cout<<"\n****************************************************************************************************************\n";
 	cout<<"Enter the student's ID: "<<endl;
    cin>>*ptr2;
 	cout<<"\n****************************************************************************************************************\n";
 		for (int i=0;i<Size;i++)
	 {
	 	if(*ptr2==student[c].id_number);


	 }




 }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void view_all ()
 {
 	cout <<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    cout <<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";


 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void view_single ()
{
    cout<<"\n****************************************************************************************************************\n";
 	cout<<"enter the students id"<<endl;
    cin>>*ptr2;
 	cout<<"\n****************************************************************************************************************\n";

	 		for (int i=0;i<size;i++)
	 {
	 	if(*ptr2==student[c].id_number)
		 {

		 	cout





		 }


	 }


}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 void delete_menu ()
{
    cout <<"\n****************************************************************************************************************\n";
    cout<<"\t\t1, select a student"<<endl;
 	cout<<"\t\t2, view all students record"<<endl;
 	cout<<"\t\t3, other options"<<endl;
 	cout <<"\n****************************************************************************************************************\n";
	cin>>*ptr;
	cout <<"\n****************************************************************************************************************\n";
	switch(*ptr)
	{
	    case 1:
	    delete_record ();
		break;
		case 2:
		delete_all_record ();
		break;
		case 3:
        OPTION();
		break;
	default:
		OPTION();
		break;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void digital_id ()
{




}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void slip ()
{




}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void report ()
{





}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double calc_CGPA (course list[],int size2)
{
	double a;
	double b;
	int sum=0;
	int sum2=0;
	for (int i=0;i<size2;i++)
	{
		a=(list[i].number_grade)*(list[i].credit_hour);
		sum+=a;
	}
		for (int i=0;i<size2;i++)
	{
		b=list[i].credit_hour;
		sum2+=b;
	}

	return (sum/sum2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void resize_student()
{
	PORTAL* temp=new PORTAL[Size+1];

	for (int i=0;i<Size;i++)

		temp[i]=student[i];

	Size++;

	student=temp;
	delete [] temp;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void resize_course ()
{
	course* temp2=new course[size2+1];

	for (int i=0;i<size2;i++)

		temp2[i]=list[i];

	Size++;

	list=temp2;
	delete [] temp2;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void new_course ()
{
	course* temp3=new course[size3+1];

	for (int i=0;i<size3;i++)

		temp3[i]=list2[i];

	Size++;

	list2=temp3;
	delete [] temp3;



}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void delete_course()
{






}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void view_status ()
{







}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void calc_grade (course list[],int size2  )
{

	for (int i=0;i<size2;i++)
	{

		if ( list[i].score>=100)
        {
					cout<<"Invalid input"<<endl;
		        OPTION();

		}
		        else if ( list[i].score>85)
        {

			list[i].number_grade=4;
            list[i].letter_grade='A';
            cout<<"Student's number grade = "<<list[i].number_grade<<endl;
            cout<<"His/her letter grade = "<<list[i].letter_grade<<endl;

		}

				else if ( list[i].score>=70)
        {

			list[i].number_grade=3;
            list[i].letter_grade='B';
                        cout<<"Student's number grade = "<<list[i].number_grade<<endl;
            cout<<"His/her letter grade = "<<list[i].letter_grade<<endl;
		}

				else if ( list[i].score>=60)
        {

			list[i].number_grade=2.5;
            list[i].letter_grade='C';
                        cout<<"Student's number grade = "<<list[i].number_grade<<endl;
            cout<<"His/her letter grade = "<<list[i].letter_grade<<endl;
		}
				else if ( list[i].score>=50)
        {

			list[i].number_grade=2;
            list[i].letter_grade='D';
                        cout<<"Student's number grade = "<<list[i].number_grade<<endl;
            cout<<"His/her letter grade = "<<list[i].letter_grade<<endl;
		}

               else if ( list[i].score<50)
        {

			list[i].number_grade=1.5;
            list[i].letter_grade='F';
                        cout<<"Student' number grade = "<<list[i].number_grade<<endl;
            cout<<"His/her letter grade = "<<list[i].letter_grade<<endl;
		}
		     else
			 {
				 	cout<<"Invalid input"<<endl;
	            	OPTION();
			 }

	}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
