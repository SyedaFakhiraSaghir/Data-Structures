#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#define size 5

using namespace std;

class task{
     //------------------attributes-----------------------------
    private:
        string name; //task's name
        string deadline; //last day of the task
        string status; //1.partially done //2.done //3.not done
        string category; //list name //work //academic //event //personal //wishlist //archive
        string details;
        int key;
        int timet; //currect time
        bool missedtask; //done = 1 //not done=0
    public:
        task *next;
        task *prev;
        //------------------default constructor-----------------------------
        task()
        {
   
        }
         //------------------parameterized constructor-----------------------------
        task(string n,string d, string s, string c, int k, int t, bool m,string details)
        {
            name=n;
            deadline=d;
            status=s;
            category=c;
            key=k;
            timet=t;
            missedtask=m;
            next=NULL;
            prev=NULL;
            this->details = details;
        }
        //------------------copy constructor-----------------------------
        task(const task *& t)
        {
            name=t->name;
            deadline=t->deadline;;
            status=t->status;
            category=t->category;
            key=t->key;
            timet=t->timet;
            details = t->details;
            missedtask=t->missedtask;
            next=t->next;
            prev=t->prev;
        }
        //------------------setters-----------------------------
        void setname(string name)
        {
            this->name=name;
        }
        void setdeadline(string deadline)
        {
            this->deadline=deadline;
        }
        void setstatus(string status)
        {
            this->status=status;
        }
        void setcategory(string category)
        {
            this->category=category;
        }
        void setkey(int key)
        {
            this->key=key;
        }
        void settimet(int timet)
        {
            this->timet=timet;
        }
        void setmissedtask(bool missedtask)
        {
            this->missedtask=missedtask;
        }
        void setdetails(string details)
		{
			this->details = details;
		}
        //------------------getters-----------------------------
        string getname()
        {
            return name;
        }
        string getdeadline()
        {
            return deadline;
        }
        string getstatus()
        {
            return status;
        }
        string getcategory()
        {
            return category;
        }
        string getdetails()
        {
            return details;
        }
        int getkey()
        {
            return key;
        }
        int gettimet()
        {
            return timet;
        }
        bool getmissedtask()
        {
            return missedtask;
        }
};

class linkedlist{
    public:
    task *head;
    linkedlist()
    {
        head=NULL;
    }
    void inserttask(task *t)
    {
    	task *newnode= new task(*t);
    	if (head == NULL) {
            head = newnode;
        }
        else {
            task* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
	}
    void insert(int choiceoflist) 
	{
    	system("Color 07"); 
    	string n;
		string d;
		string s;
		int k;
		int t;
		int m;
		string details;
		string c;
		int inp;
		//n:\n1.Academic tasks\n2.Shopping taks\n3.Personal tasks\n4.Events\n5.Wish list\n6.Archived Tasks";
    	if(choiceoflist==0)
    	{
    		c="Academic tasks";
		}
		else if(choiceoflist==1)
    	{
    		c="Shopping tasks";
		}
		else if(choiceoflist==2)
    	{
    		c="Personal tasks";
		}
		else if(choiceoflist==3)
    	{
    		c="Events";
		}
		else if(choiceoflist==4)
    	{
    		c="Wish list";
		}
		else if(choiceoflist==5)
    	{
    		c="Archived Tasks";
		}
    	cout << "Enter Task Name: ";
		fflush(stdin);
		getline(cin,n);
    	cout << "Enter Task Deadline (dd/mm/yy) : ";
		fflush(stdin);
		getline(cin,d);
    	cout << "Enter Task Status\n1. Done\n2. Not done\n3.partially done\n ";
		fflush(stdin); 
		cin>>inp;
		if(inp==1)
		{
			s="done";
		}
		else if(inp==2)
		{
			s="not done";
		}
		else if(inp==3)
		{
			s="partially done";
		}
    	cout << "Enter Key: "; 
		cin >> k;
    	cout << "Enter Time: "; 
		cin >> t;
		labelagain:
    	cout << "Enter 1 if you missed the task, and 0 if you didn't: ";
		cin >> m;
		if(m==0 || m==1)
		{
			goto cont;
		}
		else
		{
			goto labelagain;
		}
		cont:
    	cout << "Enter Details Of Task: ";
		fflush(stdin);
		getline(cin, details);
        task* newnode = new task(n, d, s, c, k, t, m, details);
        if (head == NULL) {
            head = newnode;
        }
        else {
            task* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

   	void search()
	{
		int number;
		tryagain:
    	system("Color 01"); 
		string tname;
		cout << "Enter Task Name You Want To Search: ";
		fflush(stdin);
		getline(cin,tname);
	    task* t = head;
		while(t != NULL){
			if(t->getname() == tname){
				cout << endl << "Task found" << endl;
				displaytask(t);
				return;
			}
			t=t->next;
		}
		gain:
		cout<<"The task name entered does'nt exist\nEnter 1 to try again\n2 to go back to main\n";
		cin>>number;
		if(number==1)
		{
			goto tryagain;
		}
		else if(number==2)
		{
			return;
		}
		else
		{
			cout<<"Error wrong choice!!\n";
			goto gain;
		}
    }

   void display()
    {
    	system("Color 09"); 
        task* t=head;
        cout<<"************TASK DETAILS************";
        while(t!=NULL){
           cout<<"\nTask name: "<<t->getname();
           cout<<"\tDeadline: "<<t->getdeadline();
           cout<<"\nCategory: "<<t->getcategory();
           cout<<"\tStatus: "<<t->getstatus();
           cout << "\nDetails: " << t->getdetails();
           cout<<"\nMissed tasks: "<<t->getmissedtask();
           cout<<"\tTime: "<<t->gettimet();
           t=t->next;
		}
    }
   void displaytask(task *t)
    {
    	if(t!=NULL){
    	system("Color 01");
        cout<<"************TASK DETAILS************";
       cout<<"\nTask name: "<<t->getname();
       cout<<"\tDeadline: "<<t->getdeadline();
       cout<<"\nCategory: "<<t->getcategory();
       cout<<"\tStatus: "<<t->getstatus();
       cout << "\nDetails: " << t->getdetails();
       cout<<"\nMissed tasks: "<<t->getmissedtask();
       cout<<"\tTime: "<<t->gettimet();
   		}
   		else{
   			cout<<"Task doesn't exist";
		   }
    }
    
void sortdeadline() {
	system("Color 01");
    if (head == NULL || head->next == NULL) {
        return; // Return if the list is empty or has only one element
    }

    task* current;
    task* nextNode;
    task* temp = new task(); 
    bool swapped;

    do {
        swapped = false;
        current = head;

        while (current->next != NULL) {
            nextNode = current->next;
            int num1 = atoi(current->getdeadline().c_str());
            int num2 = atoi(nextNode->getdeadline().c_str());

            if (num1 > num2) {
                // Swap values
                temp->setname(current->getname());
                temp->setdeadline(current->getdeadline());
                temp->setstatus(current->getstatus());
                temp->setcategory(current->getcategory());
                temp->setkey(current->getkey());
                temp->settimet(current->gettimet());
                temp->setdetails(current->getdetails());
						

                current->setname(nextNode->getname());
                current->setdeadline(nextNode->getdeadline());
                current->setstatus(nextNode->getstatus());
                current->setcategory(nextNode->getcategory());
                current->setkey(nextNode->getkey());
                current->settimet(nextNode->gettimet());
				current->setdetails(nextNode->getdetails());
				
                nextNode->setname(temp->getname());
                nextNode->setdeadline(temp->getdeadline());
                nextNode->setstatus(temp->getstatus());
                nextNode->setcategory(temp->getcategory());
                nextNode->setkey(temp->getkey());
                nextNode->settimet(temp->gettimet());
				nextNode->setdetails(temp->getdetails());
				
                swapped = true;
            }

            current = current->next;
        }

    } while (swapped);

    delete temp; 
}
    void sortstatus()
    {
    	int num;
        cout<<"Press:\n";
		cout<<"1 if you want to sort acoording to sequence (not done, partially done, done)\n";
		cout<<"2 if you want to sort acoording to sequence (partially done, not done, done)\n";
		cout<<"3 if you want to sort acoording to sequence (done, partially done, not done)\n";
		cout<<"4 if you want to go back\n";
		cin >> num;
		if(num == 4 || head == NULL)
		{
			return;
		}
		bool swapped;
		task *curr = head;
		while(curr->next != NULL)
		{
			swapped = false;
			task *temp = curr->next;		
			while(temp != NULL)
			{
				string de = temp->getdetails();
				string n = temp->getname();
				string d = temp->getdeadline();
				string s = temp->getstatus();
				string c = temp->getcategory();
				int k = temp->getkey();
				int t = temp->gettimet();
				
				if(num == 1)
				{
					if(temp->getstatus() == "not done" && curr->getstatus() != "not done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					else if(temp->getstatus() == "partially done" && curr->getstatus() != "not done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
				}
				else if(num==2)
				{
					if(temp->getstatus() == "partially done" && curr->getstatus() != "partially done")
					{	
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					else if(temp->getstatus() == "not done" && curr->getstatus() != "patially done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					
				}
				else if(num == 3)
				{
					if(temp->getstatus() == "done" && curr->getstatus() != "done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
					else if(temp->getstatus() == "partially done" && curr->getstatus() != "done")
					{
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						swapped = true;
					}
				}
				temp = temp->next;
			}
			if(swapped == false)
			{
				break;
			}
			curr = curr->next;
		}
    }
    void sortdetail() //sorting according to the length of details
    {
    	
    	int num;
    	cout<<"Press:\n";
		cout<<"1 if you want tasks with more details on the top\n";
		cout<<"2 if you want tasks with less details on the top\n";
		cout<<"3 if you want to go back\n";
		cin >> num;
		if(num == 3 || head == NULL)
		{
			return;
		}
		
		int count = 0;
		int count2 = 0;
		bool swapped;
		task *curr = head;
		while(curr->next != NULL)
		{
			swapped = false;
			count = 0;
			string str = curr->getdetails();
			for(int i = 0; i < str.length();i++)
			{
				if(str[i] == ' ' || str[i] == str.length()-1)
				{
					count++;
				}
			}
			task *temp = curr->next;		
			while(temp != NULL)
			{
				string de = temp->getdetails();
				string n = temp->getname();
				string d = temp->getdeadline();
				string s = temp->getstatus();
				string c = temp->getcategory();
				int k = temp->getkey();
				int t = temp->gettimet();
				count2 = 0;
				str = temp->getdetails();
				for(int i = 0; i < str.length();i++)
				{
					if(str[i] == ' ' || str[i] == str.length()-1)
					{
						count2++;
					}
				}
			
				//if num==2 put the tasks with less details at top else if num==1 put the tasks with more deatils on top
        		//ascending
       	 		//descending
				if(num==1)
				{
					if(count < count2)
					{
						temp->setdetails(curr->getdetails());
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						count = count2;
						swapped = true;
					}
				}
				else if(num==2)
				{
					if(count > count2)
					{	
						task *swap = temp;
						 	
						temp->setdetails(curr->getdetails());
						temp->setname(curr->getname());
                		temp->setdeadline(curr->getdeadline());
                		temp->setstatus(curr->getstatus());
               		 	temp->setcategory(curr->getcategory());
                		temp->setkey(curr->getkey());
                		temp->settimet(curr->gettimet());
                		temp->setdetails(curr->getdetails());
						
						
						curr->setname(n);
                		curr->setdeadline(d);
                		curr->setstatus(s);
                		curr->setcategory(c);
                		curr->setkey(k);
                		curr->settimet(t);
						curr->setdetails(de);
						
						count = count2;
						swapped = true;
					}
				}
				temp = temp->next;
			}
			if(swapped == false)
			{
				break;
			}
			curr = curr->next;
		}
    }
    void update()
    {
    	continue2:
    	int number;
    	string n;
    	cout<< endl <<"Enter Task Name which you want to Update: ";
		fflush(stdin);
    	getline(cin,n);
        task *t = head;
        while(t->getname() != n)
        {
        	t = t->next;
		}
		continue1:
    	int choice;
        cout<<"\nWhat do you want to update:\n1. Task Name\n2.Task deadline\n3.Task Status\n4.Task time"<<endl;
        cin>>choice;
        switch(choice)
        {
        	case 1:
			{
				string name;
				cout<< "Enter Name : ";
				fflush(stdin);
				getline(cin,name);
        		t->setname(name);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 2:
			{
				string deadline;
				cout<<"Enter Deadline: ";
				fflush(stdin);
				getline(cin,deadline);
				t->setdeadline(deadline);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 3:
			{
				string status;
				cout<<"Enter Status : ";
				fflush(stdin);
				getline(cin,status);
				t->setstatus(status);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			case 4:
			{
				int timet;
				cout<<"Enter Time : ";
				cin >> timet;
				t->settimet(timet);
        		cout<<"\nUpdated";
        		return;
				break;
			}
			default:
				{
					int val;
					cout<<"\nEnter a valid choice :\n0 to continue updation in this task\n1 to update a new task\n2 to go back to main page\n";
					if(val==1)
					{
						goto continue2;
					}
					else if(val==0)
					{
						goto continue1;
					}
					else
					{
						return;
					}
				}
		}
    }
    void deletet()
    {
    	tryagain:
    		int number,flag=0;
    	string n;
    	cout<<"\nEnter Task Name to be Deleted : ";
		fflush(stdin);
    	getline(cin,n);
        task *t=head;
        if(head != NULL && head->getname() == n)
		{
			head = head->next;
		}
		else 
		{
			task *t = head;
        	while(t->next != NULL)
        	{
        		if(t->next->getname() == n)
				{
					flag=1;
					break;
				}
        		t = t->next;
			}
			if(flag==1)
			{
				t->next = t->next->next;
			}
			if(flag==1)
			{
				cout<<"\nTask not found\n";
				return;
			}
		}
		gain:
		cout<<"\nEnter 1 to keep deleting tasks\n2 to go back to main\n";
		cin>>number;
		if(number==1)
		{
			goto tryagain;
		}
		else if(number==2)
		{
			return;
		}
		else
		{
			cout<<"Error wrong choice!!\n";
			goto gain;
		}
    }
    task* archive()
    {
        string n;
    	cout<<"\nEnter Task Name to be Archived : ";fflush(stdin);
    	getline(cin,n);
        
        if(head != NULL && head->getname() == n)
		{
			task *temp = head;
			head = head->next;
			return temp;
		}
		task *t = head;
        while(t->next != NULL)
        {
        	if(t->next->getname() == n)
			{
				break;
			}
        	t = t->next;
		}
		task *temp = t->next;
		t->next = t->next->next;
		return temp; 
	}
};

class User{
		public:
		string name;
		string dateOfBirth;
		string email;
		string password;
		int code;
	

		linkedlist *l;
		
		User()
		{
			//1. Academic tasks\n2. Shopping taks\n3. Personal tasks\n4. Events\n5. Wish list\n6. Archived Tasks
			l=new linkedlist[6]; 
			name="-----";
			dateOfBirth="00";
			email="GDFGETHGDFC";
			password="DHGFHSDGJDGHD";
			code=0;
		}
		User(string n,string d,string e,string p)
		{
			//1. Academic tasks\n2. Shopping taks\n3. Personal tasks\n4. Events\n5. Wish list\n6. Archived Tasks
			l=new linkedlist[6];
			name=n;
			dateOfBirth=d;
			email=e;
			password=p;
			code=0;
		}
		void setName(string n){
			name=n;
		}
		string getName(){
			return name;
		}
		void setDate(string d){
			dateOfBirth=d;
		}
		string getDate(){
			return dateOfBirth;
		}
		void setEmail(string e){
			email=e;
		}
		string getEmail(){
			return email;
		}
		void setPassword(string p){
			password=p;
		}
		string getPassword(){
			return password;
		}
		void setCode(int c){
			code=c;
		}
		int getCode(){
			return code;
		}
		void displayarchive()
		{
			task *t= l[5].head;
			system("Color 09");
	        cout<<"************TASK DETAILS************";
	        while(t!=NULL){
	           cout<<"\nTask name: "<<t->getname();
	           cout<<"\tDeadline: "<<t->getdeadline();
	           cout<<"\nCategory: "<<t->getcategory();
	           cout<<"\tStatus: "<<t->getstatus();
	           cout << "\nDetails: " << t->getdetails();
	           cout<<"\nMissed tasks: "<<t->getmissedtask();
	           cout<<"\tTime: "<<t->gettimet();
	           t=t->next;
			}
		}
		void archivetasks(int use)
		{
		    string n;
		    task* tt = l[use].archive(); 
		    if(tt!=NULL)
		    {
				l[5].inserttask(tt);
			    displayarchive();
			    cout << "\nTASK ARCHIVED\n";
			    return;
			}
			cout << "\nTASK NOT FOUND\n";
			return;
		}

		void Input(){
			int digit=0,specialCharacter=0,character=0,Code;
		  	cout<<"Enter name:";
			fflush(stdin);
		  	getline(cin,name);
		  	cout<<"\nEnter date of birth:";
			fflush(stdin);
		  	getline(cin,dateOfBirth);
		  	scan:
		  	cout<<"Enter email:";
			fflush(stdin);
		  	getline(cin,email);
		  	if(!CheckObject("users.txt",email))
			{
			 	goto scan; 	
			}
		  	label:
		 	cout<<"Enter password:";fflush(stdin);
		 	getline(cin,password);
		  	for(int i=0;i<password.length();i++){
		  		if(password[i]>=48 && password[i]<=57){
		  			digit++;
		  			//cout<<"Digit:"<<digit<<endl;
				}	
				else if((password[i]>= 65 && password[i]<=90) ||  (password[i]>=97 &&password[i]<=122)){
			  		character++;
			  		//	cout<<"charac:"<<character<<endl;
	     		}
		    	else if((password[i]>=33 && password[i]<=42) || password[i]==64){
		  			specialCharacter++;
		  			//cout<<"Special: "<<specialCharacter;
		  		}
			}
			if(specialCharacter>0 && character>0 && digit>0){
				cout<<"\nStrong password.";
			}
			else{
				cout<<"\nEnter character, digits, and special character as the password is not strong enough.\n";
				goto label;
			}
			srand(time(0));
			code=1000+rand()%8999;
			cout<<"\nYour code is: "<<code<<endl;
			label2:
			cout<<"\nEnter code: ";
			cin>>Code;
			if(code==Code)
			{
				cout<<"\n**********Successfully registered!**********\n";
				fstream file ("users.txt", ios :: app);
				file << this->name << endl;
				file << this->dateOfBirth << endl;
				file << this->email << endl;
				file << this->password << endl;
				file << this->code << endl;
				file.close();
			}
			else{
				cout<<"\nError.Enter the code again:";
				goto label2;
			}
		}
		//-------------------------------------------------------------USER CLASS OVERLOADING-------------------------------------------------------------
		User& operator=(const User& us) {
        for (int i = 0; i < 7; ++i) {
            // Assuming you have a copy constructor for List
            l[i].head = us.l[i].head;
        }
        return *this;
    }
		bool CheckObject(string fname,string e)
		{
			bool save = true;
			fstream file;
			file.open(fname, ios::in);
			if(file.is_open())
			{
				string str;
				int i = 1;
				while(getline(file,str))
				{	
					
					if(i == 6)
					{
						i = 1;
					}
					if (i == 3 && str == e)
					{	
						save = false;
						cout << endl << endl << "Email Already Exists "  << endl;
						file.close();
						return false;
					}
					i++;
				}
			}
			return true;
		}
		bool LoadObject(string fname,User *user)
		{
			fstream file (fname,ios :: in);
			if(file.is_open())
			{
				string str;
				int i = 1;
				while(getline(file,str))
				{	
					if(i == 6)
					{
						i = 1;
					}
					if (i == 3 && str == user->getEmail())
					{	
						this->name = user->getName();
						this->dateOfBirth = user->getDate();
						this->email = str;
						this->password = user->getPassword();
						this->code = user->getCode();
						file.close();
						return true;
					}
					i++;
				}
				file.close();
			}
			cout << endl  << endl << "Object Does Not Exists" << endl;
			return false;
		}
		
	//Displaying users account
	void userDisplay(){
		cout<<"\n\n**********Displaying user's details**********";
		cout<<"\nName: "<<name;
		cout<<"\nDate of birth: "<<dateOfBirth;
		cout<<"\nEmail: "<<email;
		cout<<"\nPassword: "<<password;
	}
	
//	void filing()
//	{
//		fstream FileName;                       
//	    FileName.open("FileName.txt", ios::app);                
//	    if (!FileName) 
//		{                            
//	        cout<<" Error while creating the file ";          
//	    }
//	    else {
//	    	for(int i=0;i<6;i++)
//	    	{ 
//	    		task *t=l[i].head;
//	    		while(l[i].head->next!=NULL)
//	        	{
//	        		FileName<< getDate();
//	        		FileName<< getName();
//	        		FileName<< getEmail();
//	        		FileName<< getPassword();
//	        		FileName<< l[i].head->getname();
//	        		FileName<< l[i].head->getname();
//	        		FileName<< l[i].head->getcategory();
//	        		FileName<< l[i].head->getdeadline();
//	        		FileName<< l[i].head->getdetails();
//	        		FileName<< l[i].head->getmissedtask();
//	        		FileName<< l[i].head->getstatus();
//	        		FileName<< l[i].head->gettimet();
//	        		FileName<< l[i].head->getkey();
//	        		l[i].head=l[i].head->next;
//	        	}
//	        	l[i].head=t;
//			}
//	        cout<<"File created and data got written to file";    
//	        FileName.close();                   
//	    }
//	}

void displayffff(User& user)
{
	for (int i = 0; i < 6; i++)
        {
            task *t = user.l[i].head;
            while (user.l[i].head != NULL)
            {
                cout << user.l[i].head->getname() << " ";
                cout << user.l[i].head->getcategory() << " ";
                cout << user.l[i].head->getdeadline() << " ";
                cout << user.l[i].head->getdetails() << " ";
                cout<< user.l[i].head->getmissedtask() << " ";
                cout<< user.l[i].head->getstatus() << " ";
                cout << user.l[i].head->gettimet() << " ";
                cout << user.l[i].head->getkey() << " ";

                user.l[i].head = user.l[i].head->next;
            }
            user.l[i].head = t; // Reset the head to its original position
        }
}


	void filing(User& user)
	{
	    fstream FileName;
	    FileName.open("FileName.txt", ios::out); // Change ios::app to ios::out
	    if (!FileName)
	    {
	        cout << "Error while creating the file";
	    }
	    else
	    {
	        // Write user details
	        FileName << user.getDate() << " " << user.getName() << " " << user.getEmail() << " "
	                 << user.getPassword() << " " << user.getCode() << endl;
	
	        // Iterate through each list and write task details
	        for (int i = 0; i < 6; i++)
	        {
	            task *t = user.l[i].head;
	            while (user.l[i].head != NULL)
	            {
	                FileName << user.l[i].head->getname() << " ";
	                FileName << user.l[i].head->getcategory() << " ";
	                FileName << user.l[i].head->getdeadline() << " ";
	                FileName << user.l[i].head->getdetails() << " ";
	                FileName << user.l[i].head->getmissedtask() << " ";
	                FileName << user.l[i].head->getstatus() << " ";
	                FileName << user.l[i].head->gettimet() << " ";
	                FileName << user.l[i].head->getkey() << " ";
	
	                user.l[i].head = user.l[i].head->next;
	            }
	            user.l[i].head = t; // Reset the head to its original position
	        }

	        cout << "File created and data got written to file";
	        FileName.close();
	    }
	}
	void readFromFile(User& user)
	{
		string name; //task's name
	    string deadline; //last day of the task
	    string status; //1.partially done //2.done //3.not done
	    string category; //list name //work //academic //event //personal //wishlist //archive
	    string details;
	    int key;
	    int timet; //currect time
	    bool missedtask; //done = 1 //not done=0
	    task *next;
	    
	    ifstream FileName("FileName.txt");
	    if (!FileName)
	    {
	        cout << "Error opening the file for reading";
	        return;
	    }
	
	    // Read user details
	    FileName >> user.dateOfBirth >> user.name >> user.email >> user.password >> user.code;
	
	    // Read task details for each list
	    for (int i = 0; i < 6; i++)
	    {
	        while (FileName >> name >> category>> deadline >> details>> missedtask >> status>> timet >> key)
	        {
			    user.l[i].head->setname(name) ;
				user.l[i].head->setcategory(category);
			    user.l[i].head->setdeadline(deadline);
				user.l[i].head->setdetails(details);
			    user.l[i].head->setmissedtask(missedtask);
				user.l[i].head->setstatus(status);
			    user.l[i].head->settimet(timet);
				user.l[i].head->setkey(key);				
				cout << user.l[i].head->getname() << " ";
                cout << user.l[i].head->getcategory() << " ";
                cout << user.l[i].head->getdeadline() << " ";
                cout << user.l[i].head->getdetails() << " ";
                cout<< user.l[i].head->getmissedtask() << " ";
                cout<< user.l[i].head->getstatus() << " ";
                cout << user.l[i].head->gettimet() << " ";
                cout << user.l[i].head->getkey() << " ";																				
	            // Create a new node for the next task
	            user.l[i].head->next;
	
	            // Move to the newly created node
	            user.l[i].head = user.l[i].head->next;
	        }
	    }
	
	    FileName.close();
	}

	
};

class Feedback {
public:
    string gArray[size] = {
        "Thank you for your positive feedback!",
        "Thank you for your kind words! We're delighted to hear that you had a great experience with our software application.",
        "Your positive feedback made our day! We're here to provide the best service possible, and it's great to know we're on the right track.",
        "Your positive feedback inspires us to continue delivering excellence. We're committed to maintaining the high standards you've come to expect.",
        "Customer satisfaction is our primary goal, and your positive feedback is a testament to our efforts. Thank you for your trust."
    };

    string bArray[size] = {
        "Thank you for sharing your feedback. We're truly sorry to hear about the issues you encountered while using our software.",
        "We apologize for the inconvenience you experienced with our software. Your feedback is valuable to us.",
        "I'm sorry to hear that you had a negative experience with our software. We take your concerns seriously. We are committed to delivering a better experience, and your feedback helps us identify areas for improvement.",
        "It's disappointing to learn that our software did not meet your expectations. We're committed to resolving these issues promptly.",
        "We understand the frustration you've experienced, and we are determined to make your next interaction with our software a better one."
    };

    string mArray[size] = {
        "Your comments provide valuable insights for us to work on enhancing your future experiences with our software.",
        "We're committed to continuous improvement, and your feedback serves as a stepping stone toward achieving that goal. Thank you for sharing your thoughts.",
        "Thank you for taking the time to share your thoughts. We are actively working on implementing changes based on your feedback to improve your experience.",
        "Your feedback is an essential part of our ongoing efforts to improve. We'll use your insights to refine and enhance our service.",
        "Your medium-level feedback is helping us identify areas for refinement, and we're dedicated to taking the necessary steps to make things right."
    };

    Feedback() {
    }

    int getRandomNumber() {
        srand(time(0));
        int randomNumber = 0 + rand() % 5;
        return randomNumber;
    }

    void FeedbackInput() {
    	system("Color 0D"); 
        string word;
        cout << "\nEnter feedback: ";
        cin >> word;
        for (int i ; i<word.length() ;i++) 
	{
		word[i] = tolower(word[i]);
	}
        if (word == "outstanding" || word == "impressive" || word == "exceptional" || word == "excellent" || word == "superb" || word == "user-friendly" || word == "marvellous" || word == "innovative" || word == "easy-to-use" || word == "very well-designed") {
            int c = getRandomNumber();
            cout << gArray[c];
        }
        else if (word == "streamlined" || word == "efficient" || word == "responsive" || word == "fast" || word == "reliable" || word == "secure" || word == "user-centric" || word == "mobile-friendly" || word == "well-designed") {
            int c = getRandomNumber();
            cout << mArray[c];
        }
        else if (word == "glitchy" || word == "buggy" || word == "unreliable" || word == "slow" || word == "inefficient" || word == "incompatible" || word == "confusing" || word == "frustrating" || word == "non-responsive" || word == "poorly designed") {
            int c = getRandomNumber();
            cout << bArray[c];
        }
        else {
            cout << "\nThank you for your feedback.";
        }
    }
};


int inputfunction()
{
    int type;
    again:
    	system("Color 07"); 
	cout<<"\nDo you want to:\n1.Insert a task\n2.Update a task\n3.Delete a task\n4.Archive a task\n5.Search for a task\n6.Display tasks\n7.Sort a task\n8.exit\n";
	cin>>type;
	switch(type)
	{
	    case 1:
	    {
	        return 1;
	        break;
	    }
	    case 2:
	    {
	        return 2;
	        break;
	    }
	    case 3:
	    {
	        return 3;
	        break;
	    }
	    case 4:
	    {
	        return 4;
	        break;
	    }
	    case 5:
	    {
	        return 5;
	        break;
	    }
	    case 6:
	    {
	        return 6;
	        break;
	    }
	    case 7:
	    {
	        return 7;
	        break;
	    }
	    case 8:
	    {
	        return 8;
	        break;
	    }
	    default:
	    {
	        goto again;
	    }
	}
}

int chooselist()
{
	int it;
    label:
    system("Color 08"); 
    cout<<"\nWhich list do you want to open:\n1. Academic tasks\n2. Shopping taks\n3. Personal tasks\n4. Events\n5. Wish list\n6. Archived Tasks\n7. Exit\n";
    cin>>it;
    
    if(it==1)
    {
        return 0;
    }
    else if(it==2)
    {
        return 1;
    }
    else if(it==3)
    {
        return 2;
    }
    else if(it==4)
    {
        return 3;
    }
    else if(it==5)
    {
        return 4;
    }
    else if(it==6)
    {
        return 5;
    }
    else if(it==7)
    {
        return 6;
    }
    else
    {
        cout<<"Enter a valid choice";
        goto label;
    }
}

void WriteUserToFile(const User& u) 
{
    ofstream file1;
    file1.open("user_data.txt", ios::app);
    
    if (file1.is_open()) 
    {
        file1.write(reinterpret_cast<const char*>(&u), sizeof(u));
        file1.close();
        cout<<"written successful";
    } 
    else 
    {
        cout << "Error opening file for writing.\n";
    }
}

User ReadUserFromFile() 
{
    User u1;
    User uss;
    ifstream file2;
    file2.open("user_data.txt", ios::in);
    if (file2.is_open()) 
    {
        file2.read(reinterpret_cast<char*>(&u1), sizeof(u1));
        file2.close();
    } 
    else 
    {
        cout << "Error opening file for reading.\n";
    }
    return u1;
}

int main() 
{
    system("Color 0A"); 
    
	    User u;
	cout<<"\n\n---------------------------------------------------------------------------------------"<<endl;
	cout<<"=--------------------------------- T A S K     P R O ---------------------------------="<<endl;
	cout<<"---------------------------------------------------------------------------------------\n\n"<<endl;
    int choice;
    system("Color 0B"); 
    option: //label if option other than 1, 2, 3 choosen
    cout<<"Choose an option:\n1. Are you Already registered?\n2.Do you want to register?\n3.exit\n";
    cin>>choice;
    if(choice==1)
    {
 		u.readFromFile(u);
	}
	else if(choice==2)
	{
		system("Color 0C"); 
	   	u.Input();
	}
	else if(choice==3)
	{
		exit(1);
	}
	else
	{
		goto option;
	}
	int repeats;
	//program keeps running until user chooses to exit
	while(1)
	{
		mainn:
		system("cls"); 	
    	system("Color 0D"); 
    	cout<<"\n\n---------------------------------------------------------------------------------------"<<endl;
	    cout<<"=--------------------------------- T A S K     P R O ---------------------------------="<<endl;
	    cout<<"---------------------------------------------------------------------------------------\n\n"<<endl;
	    int userchoice=chooselist();
	    if(userchoice==6)
	    {
	    	goto exittt;
		}
	    chooseotherfunctionalites:
		int us=inputfunction();
	    if(us== 1)//insert
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** I N S E R T I N G   A   T A S K *****************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].insert(userchoice);
		}
		else if(us==2)//update
	    {
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"***************** U P D A T I N G   A   T A S K ******************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].update();
		}
		else if(us==3)//delete
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"************** D E L E T I N G   A   T A S K *********************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].deletet();	
		}
		else if(us==4)//archive
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** A R C H I V I N G   A   T A S K *****************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.archivetasks(userchoice);
		}
		else if(us==5)//search
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	        cout<<"**************** S E A R C H I N G   A   T A S K *****************"<<endl;    	
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].search();
		}
		else if(us==6)//display
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** D I S P L A Y I N G   A   T A S K ***************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	u.l[userchoice].display();
		}
		else if(us==7)//sort
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	    cout<<"************* S O R T I N G   T A S K S **************************"<<endl;
	    	    cout<<"******************************************************************\n\n"<<endl;
	    	co1:
	       	int num;
	        cout<<"\nYou have the option to sort with respect to:\n1.Details\n2.Deadline\n3.Status\n";
	        	cin>>num;
	        	switch(num){
	        		case 1:
					{
						u.l[userchoice].sortdetail();
						break;
					}
					case 2:
					{
						u.l[userchoice].sortdeadline();
						break;
					}
					case 3:
					{
						u.l[userchoice].sortstatus();
						break;
					}
					default:
					{
						int val;
						cout<<"\nEnter :\n0 to continue sorting this list\n1 to go back to main page\n";
						if(val==1)
						{
							goto co1;
						}
						else
						{
							goto mainn;
						}
						break;
					}
			}
		}
		else if(us==8)//store and exit
	    {
	    	
	    	cout<<"\n\n******************************************************************"<<endl;
	    	cout<<"**************** E X I T I I N G   T A S K    P R O **************"<<endl;
	    	cout<<"******************************************************************\n\n"<<endl;
	    	goto exittt;
		}
		
    	system("Color 07"); 
		cout<<"\n\nTo go back the main page Press 1\nTo see more options to explore this list press 2\n\n";
		cin>>repeats;
		if(repeats==1)
		{
			goto mainn;
		}
		else if(repeats==2)
		{
			goto chooseotherfunctionalites;
		}
	    Feedback f;
	    f.FeedbackInput();
	}
	exittt:
		u.displayffff(u);
		u.filing(u);
	return 0;
}
