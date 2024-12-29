#include<iostream> 
#include<fstream> // used for File Handling
#include<conio.h> //used for Input and Output of functions
#include<cstdlib>

using namespace std;

//Login Function
void login();
void SignIn();
void SignUp();
void Forget();
void MainPage();
//////////////////////////

void displayWardSupplies(const string& wardName, int bedsAvailable, int medications, int surgicalInstruments) 
{
    cout << "Ward: " << wardName << endl;
    cout << "Beds Available: " << bedsAvailable << endl;
    cout << "Medications Available: " << medications << endl;
    cout << "Surgical Instruments Available: " << surgicalInstruments << "\n\n";
}

// Function to display the main menu and handle user input
void displayMainMenu() 
{
	int choice;
	do
	{
	
         cout << "Hospital Wards: "<<endl;
         cout << "1. ICU "<<endl;
         cout << "2. Surgical "<<endl;
         cout << "3. Emergency "<<endl;
         cout << "4. Dental "<<endl;
         cout << "5. Exit "<<endl;
         
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) 
	       {
             case 1:
                    displayWardSupplies("ICU", 15, 30, 40);
                 break;
             case 2:
                    displayWardSupplies("Surgical", 15, 25, 55);
                  break;
             case 3:
                    displayWardSupplies("Emergency", 40, 60, 100);
                 break;
             case 4:
                    displayWardSupplies("Dental", 5, 15, 25);
                 break;
             case 5:
                    cout << "Go to Main Menu.\n";
                    MainPage();
                 break;
             default:
                    cout << "\n\nInvalid choice .\n";
                    system("pause");
                    cout<<"\n";
            }
    }
    
        while (choice != 5);
}

void MainPage()
{
	char fname[20];
 	int i;

//Select user for their choice
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";	
         cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
         cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
         cout<<"\t\t\t\t\t\t|                                           	                  |\n";
         cout<<"\t\t\t\t\t\t|             1.  -> Enter New Patient Record                     |\n";
         cout<<"\t\t\t\t\t\t|             2.  -> Add Diagnosis Information                    |\n";
         cout<<"\t\t\t\t\t\t|             3.  -> Delete Doctor Information        	          |\n";
         cout<<"\t\t\t\t\t\t|             4.  -> Full History of the Patient                  |\n";
         cout<<"\t\t\t\t\t\t|             5.  -> Discharge Patient                            |\n";
         cout<<"\t\t\t\t\t\t|             6.  -> Information About the Hospital               |\n";
         cout<<"\t\t\t\t\t\t|             7.  -> Logout                                       |\n";
         cout<<"\t\t\t\t\t\t|             8.  -> Exit the Program                             |\n";
         cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	
a:
	{
		cout<<"\t\t\t\t\t\tEnter your choice: ";
		cin>>i;
	}
//if inputed choice is other than given choice

	if(i > 8 || i < 1)	
		{
			cout<<"\t\t\t\t\t\tInvalid Choice"<<endl;
			cout<<"\t\t\t\t\t\tTry again..........."<<endl;
			goto a;
		}

//Clears the previous output on the screen
system("cls");

    if(i==1)
		{
 		 	cout<<endl;
  			
			  ofstream pat_file;
  			char fname[20];
  			
  			  cout<<"\n\n\t\t\t...........Adding a Patient...........";
			  cout<<"\n\nEnter the patient's file name : ";
  		cin.ignore();
  			gets(fname);
  			pat_file.open(fname);
  	
  		if(!fname)
		  {	
			cout<<"\nError while opening the file\n";MainPage();
		  }
		else
			{
			//Using structure for patient information along with arrays//
                        struct patient_info
                        {
                            char name[20];
                            char address[100];
                            char contact[10];
                            char age[5];
                            char blood_gp[5];
                            char disease_past[50];
                            char id[15];
                        };

            patient_info b;
            cout<<"\n\n********************************************************************\n"<<endl;
			pat_file<<"********************************************************************"<<endl;
        
		//For name    
			cout<<"Name : ";
			pat_file<<"Name : ";
			gets(b.name);
			pat_file<<b.name<<endl;
        
		//For address    
			cout<<"Address : ";
			pat_file<<"Address : ";
			gets(b.address);
			pat_file<<b.address<<endl;
		
		//for Contact info	
            cout<<"Contact Number : ";
			pat_file<<"Contact Number : ";
			gets(b.contact);
			pat_file<<b.contact<<endl;
		
		//for Age
            cout<<"Age : ";
			pat_file<<"Age : ";
			gets(b.age);
			pat_file<<b.age<<endl;
		
		//for blood group
            cout<<"Blood Group : ";
			pat_file<<"Blood Group : ";
			gets(b.blood_gp);
			pat_file<<b.blood_gp<<endl;
		
		//for previous medical history
            cout<<"Any Major disease suffered earlier : ";
			pat_file<<"Any Major disease suffered earlier : ";
			gets(b.disease_past);
			pat_file<<b.disease_past<<endl;
		
		//for patient id
            cout<<"Patient ID : ";
			pat_file<<"Patient ID : ";
			gets(b.id);
			pat_file<<b.id<<endl;
            cout<<"\n\n********************************************************************\n"<<endl;
			pat_file<<"********************************************************************"<<endl;
            cout<<"Information Saved Successfully"<<endl;
        	}	
        
//both functions included from header file "conio.h"//       
	system("pause");
	system("cls");
	
//redirects the user to path b://
  MainPage();

}
	
// option 2 opening and editing the record of the patient

	if(i==2)
    	{
    		fstream pat_file;
    		cout<<"Enter the patient's file name to be opened : ";
    	cin.ignore();
    		gets(fname);
    		system("cls");
			pat_file.open(fname, ios::in);
			
		if(!pat_file)
			{
				cout<<"Error while opening the file!"<<endl;
				MainPage();
			}
		else	
			{
		    	cout<<"\t\t\t\t........................................ Information about "<<fname<<" ........................................"<<endl;
		    	string info;
			
				while(pat_file.good())
				{
				
				getline(pat_file,info);
				cout<<info<<endl;
			
				}
			
			cout<<endl;
			pat_file.close();
			/*			
			ios::out | ios::app:
								ios output and ios append. ios output is used when the file is opened for output (to write)
								and ios append allows the written data to be stored at the end of the file instead of
								actually overwriting or rewriting the already existing data! They are basically flag used with file 
								stream
			*/
						
			//adding the additional information at the end of file instead of overwriting or manipulating existing data in file//
			pat_file.open(fname, ios::out | ios::app);
            cout<<endl;
            
			cout<<"Adding more information in that patient's "<<fname<< " file... : \n";pat_file<<"\nDescription of "<<endl;
                            struct app
                            {
                                char symptom[500];
                                char diagnosis[500];
                                char medicine[500];
                                char addmission[30];
                                char ward[15];
                            };
            //appends the added info at the end of file
            app add;
            
            //for symptoms
            cout<<"Symptoms : ";
			pat_file<<"Symptoms : ";
			gets(add.symptom); 
			pat_file<<add.symptom<<endl;
		    
			//for diagnosis
            cout<<"Diagnosis : "; 
			pat_file<<"Diagnosis : ";
			gets(add.diagnosis); 
			pat_file<<add.diagnosis<<endl;
		    
			//for Medicines
            cout<<"Medicines : "; 
			pat_file<<"Medicines : ";
			gets(add.medicine); 
			pat_file<<add.medicine<<endl;
	    	
			//for admission
            cout<<"Addmission Required? : "; 
			pat_file<<"Addmission Required? : ";
			gets(add.addmission); 
			pat_file<<add.addmission<<endl;
			
			//for ward
            cout<<"Type of ward : "; 
			pat_file<<"Type of ward : ";
			gets(add.ward); 
			pat_file<<add.ward<<endl;
			pat_file<<"\n*************************************************************************";
            cout<<endl<<add.ward<<" ward is alloted Successfully"<<endl;
       		cout<<"Information added sucessfully!"<<endl;
        		
			pat_file.close();
			cout<<endl;
			
			system("pause");
            system("cls");
			MainPage();
			
			}
}

// option 3
if(i==3)
{
    fstream pat_file;
    cout<<"Enter the Doctor file name to Delete : ";
    cin.ignore();
    gets(fname);
    system("cls");
		if(remove(fname)!=0)	
		{
			cout<<"That File Of Doctor Does not Exist ."<<endl;
			MainPage();
		}
		else
		{
		    cout<<"\n\n\n\t\t\t Doctor "<<fname<<" Data Deleted SuccessFully. \n\n\n"<<endl;
        }
        system("pause");
        system("cls");
        MainPage();
}


if(i==4)
{
    fstream pat_file;
    cout<<"Enter the patient's file name to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)	
		{
			cout<<"Error while opening the file"<<endl;
			MainPage();
		}
		else
		{
		    cout<<"\t\t\t\t........................................ Full Medical History of "<<fname<<" ........................................"<<endl;
		    string info;
		    
			while(pat_file.good())
				{
				
				getline(pat_file,info);
				cout<<info<<endl;
			
				}
			cout<<endl;
        }
        system("pause");
        system("cls");
        MainPage();
}

	if(i==5)
{
    fstream pat_file;
    cout<<"Enter the patient's file name to Delete : ";
    cin.ignore();
    gets(fname);
    system("cls");
		if(remove(fname)!=0)	
		{
			cout<<"That File Of Patient Does not Exist ."<<endl;
			system("pause");
			MainPage();
		}
		else
		{
		    cout<<"\n\n\n\t\t\t Patient "<<fname<<" Data Deleted SuccessFully. "<<endl;
        }
        system("pause");
        system("cls");
        MainPage();
}

// option 6 About Hospital
if(i==6)
		{	
			ifstream file;
			file.open("Info.txt");
	
			if(!file)	
				{	
					cout<<"\a\nError while opening the file\n";
					MainPage();
				}
			else
				{
		    		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t...........................Information about the Hospital.............................\n\n";
		    		string line;
			
						while(file.good())
							{
								getline(file,line);
								cout<<line<<endl;
							}	
			cout<<endl;
			system("pause");
            system("cls");
			MainPage();
				}	
		}

// option 07
         if(i==7)

           { 
	          login();	
            }
// option 08

if(i==8)
	{
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
          cout<<"\t\t _______________________________________________________________________________________\n";
          cout<<"\t\t|                                           		                                |\n";
          cout<<"\t\t|                                           		                                |\n";
          cout<<"\t\t|                                           		                                |\n";
          cout<<"\t\t|                                           		                                |\n";
          cout<<"\t\t|                    ---------------------------------------------                      |\n";
          cout<<"\t\t|                    *********************************************                      |\n";
          cout<<"\t\t|                                                                                       |\n";
          cout<<"\t\t|                                   Thank You For Using                                 |\n";
          cout<<"\t\t|                                                                                       |\n";
          cout<<"\t\t|                               HOSPITAL MANAGEMENT SYSTEM                              |\n";
          cout<<"\t\t|                                                                                       |\n";
          cout<<"\t\t|                    *********************************************                      |\n";
          cout<<"\t\t|                    ---------------------------------------------                      |\n";
          cout<<"\t\t|                                      Made By                                          |\n";
          cout<<"\t\t|                                                                                       |\n";
          cout<<"\t\t|                              Muhammad Abdullah Naeem                                  |\n";
          cout<<"\t\t|                                                                                       |\n";
	   	  cout<<"\t\t|                                Abdullah Bin Salman                                    |\n";
          cout<<"\t\t|                                                                                       |\n";
          cout<<"\t\t|_______________________________________________________________________________________|\n";

	}
}

// Main Function()

int main()

{
//Interface Display of Code (UI)//

         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
         cout<<"\t\t _______________________________________________________________________________________\n";
         cout<<"\t\t|                                           		                                    |\n";
         cout<<"\t\t|                                           		                                    |\n";
         cout<<"\t\t|                                           		                                    |\n";
         cout<<"\t\t|                                           		                                    |\n";
         cout<<"\t\t|                    ---------------------------------------------                      |\n";
         cout<<"\t\t|                    *********************************************                      |\n";
         cout<<"\t\t|                                                                                       |\n";
         cout<<"\t\t|                                       WELCOME TO                                      |\n";
         cout<<"\t\t|                                                                                       |\n";
         cout<<"\t\t|                               HOSPITAL MANAGEMENT SYSTEM                              |\n";
         cout<<"\t\t|                                                                                       |\n";
         cout<<"\t\t|                     ********************************************                      |\n";
         cout<<"\t\t|                    ---------------------------------------------                      |\n";
         cout<<"\t\t|                                                                                       |\n";
         cout<<"\t\t|                                                                                       |\n";
         cout<<"\t\t|                                                                                       |\n";
         cout<<"\t\t|_______________________________________________________________________________________|\n";
         cout<<"\n\n\n\nLoading Please Wait....";

system("cls");

//Login Function is used here

login();
// Main Menu Function
MainPage();
}

void login()
{
   
	int choice;
	
	cout<<"\t\t\t______________________________________________________________________\n\n\n";
	cout<<"\t\t\t                          Welcome To Login Page                        \n\n\n";
	cout<<"\t\t\t _____________________________    MENU    ____________________________  \n\n";
	cout<<"\t\t\t                                                                         \n\n";
	cout<<"\t\t\t\t\t _____________________________________\n";
	cout<<"\t\t\t\t\t|                                     |\n";
	cout<<"\t\t\t\t\t|        Press 1 For Sign In          |\n ";
	cout<<"\t\t\t\t\t|        Press 2 For Sign Up          |\n";
	cout<<"\t\t\t\t\t|        Press 3 For Frogot ID        |\n";
	cout<<"\t\t\t\t\t|        Press 4 For Exit             |\n";
	cout<<"\t\t\t\t\t|_____________________________________|\n\n\n";
	cout<<"\t\t\t\t\t Enter Your Choice :  ";
	cin>>choice;
	
	switch(choice)
		{
			case 1:
				{
					system("cls");
					SignIn();
					break;   
				}
			case 2:
				{
					system("cls");
					SignUp();
					break;
				}
			case 3:
				{
					system("cls");
					Forget();         
					break;
				}
			case 4:
				{
				 system("cls");
					  cout<<"\n\n\t\t Thank You !!";                                    
					break;
				}
			default:
				system("cls");
				cout<<"\n\n\t \a Please Make Sure Your Choice Is "<<choice<<" Valid !!\n\n";
				main();	
		}
}

void SignUp()
{
								
	string ruserID, rpassword, rId, rpass;
	
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\t\t\t\t\t\t\t   *  Enter Your Username And Password   *\n";
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\t  Hospital Managment System \n\n";
    	cout<<"\t\t\t\t\t\t\t\t------------------------------";
    	cout<<"\n\t\t\t\t\t\t\t\t\t    SignUp \n";	
    	cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";	
    	cout << "\t\t\t\t\t\t\t\tEnter Username: ";
 cin>>ruserID;
    	cout<<"\n\t\t\t\t\t\t\t\tEnter Password: ";
	cin>>rpassword;
	
		ofstream ToSignUp("SignIn Info.txt", ios::app);
			
			ToSignUp<<ruserID<<' '<<rpassword<<endl;
			
		cout<<"\n Your SuccessFully SignedUp And SignIn And Enjoy!!"<<endl<<endl;
		system("pause");
		system("cls");
		main();
}

void SignIn()
{ 
	int count;
	string userID, password, Id, pass;
	char  ch;
	system("cls");
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   *  Enter Your Username And Password   *\n";
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\t  Hospital Managment System \n\n";
    	cout<<"\t\t\t\t\t\t\t\t------------------------------";
    	cout<<"\n\t\t\t\t\t\t\t\t\t    SignIn \n";	
    	cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";	
    	cout << "\t\t\t\t\t\t\t\tEnter Username: ";
    cin>>userID;
   		cout<<"\n\t\t\t\t\t\t\t\tEnter Password: ";
    
     ch = _getch();
    	while(ch != 13)//character 13 is enter
   	    {
	 		password.push_back(ch);
      		cout << '*';
      		ch = _getch();
    	}
    ifstream ToRead("SignIn Info.txt");
    	if(!ToRead)
    		{
			cout<<"\n\n\a !! File Not Found ";
			
			}
			
		while(ToRead>>Id>>pass)
		{
			if(Id==userID && password==pass)
				{
					count=1;
					
				}
		}
		ToRead.close(); //File closed
			
			{
			if(count==1)
				{
				  cout<<"\n You SignedIn SuccessFully !!"<<endl<<endl;
				  system("pause");
				  system("cls");		  
				  	MainPage();
				}
			else
				{
					cout<<"\n\n\a Your Username And Password Is Incorrect !!!"<<endl<<endl;
					system("pause");
					system("cls");
					login();
				}
			}
}
                                               
void Forget()

{
	int option;
	int count=0;
	
	string fpass,fuserID,fid;
	
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   *     Forgot Password Not Worry!      *\n";
		cout<<"\t\t\t\t\t\t\t   *            We will Fix              *\n";
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\n\n\n\t\t\t\t\t\t\t\t------------------------------";
		cout<<"\n\t\t\t\t\t\t\t\t  Hospital Managment System \n";
    	cout<<"\t\t\t\t\t\t\t\t------------------------------\n";

    cout<<"\n\t\t\t\t\t\t\t _________________________________________________\n";
      	cout<<"\t\t\t\t\t\t\t|                                                 |\n";
    	cout<<"\t\t\t\t\t\t\t|        .Press 1 To Search Id By Username.       |\n";
    	cout<<"\t\t\t\t\t\t\t|                                                 |\n";
    	cout<<"\t\t\t\t\t\t\t|        .Press 2 To Return Login Page.           |\n";
        cout<<"\t\t\t\t\t\t\t|_________________________________________________|\n";
		cout<<"\n\n\t\t\t\t\t\tPlease Enter Your Choice: ";                
		cin>>option;
		                                                               
		switch(option)
			{
				case 1:   
					{
						
							system("cls");
						int count=0;
		  
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   *            We will Fix Here         *\n";
		cout<<"\t\t\t\t\t\t\t   *                                     *\n";
		cout<<"\t\t\t\t\t\t\t   ***************************************\n"; 
		cout<<"\n\n\n\t\t\t\t\t\t\t\t------------------------------";
		cout<<"\n\t\t\t\t\t\t\t\t  Hospital Managment System \n";
    	cout<<"\t\t\t\t\t\t\t\t------------------------------\n";
    	cout<<"\n\t\t\t\t\t\t\tPlease Enter Your Username: ";
    	cin>>fuserID;
    	
    			ifstream ToForget("SignIn Info.txt");
    				while(ToForget>>fid>>fpass)
    					{                
    						if(fid==fuserID)
    							{
    								count=1;
								}
						}
				ToForget.close();
				
					if(count==1)
						{
							cout<<"\n\n Your Account Is SuccessFully Found ! ";
							cout<<"\n-------------------------------------------";
							cout<<"\n\n Your Password Is: "<<fpass<<endl;
							cout<<"\n-------------------------------------------"<<endl;
							system("pause");
							system("cls");
							main(); 					         
						}
					else
						{																										  		                                                                                                  
							cout<<"\n\n\a Your Username Does not Exist !! \n \n\n You Want To SignUp . "<<endl;
							system("pause");
							system("cls");
							main();
						}
						break;		
				 	}	
				case 2:
					   {
						system("cls");
						main();	
						break;
					   }  	
				default:
						cout<<"\n\n\a Please Make Sure Your Choice Is Valid !!\n\n";
						system("pause");
						system("cls");
						Forget();
			}
}
