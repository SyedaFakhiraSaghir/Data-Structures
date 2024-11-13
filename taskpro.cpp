#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#define size 5

using namespace std;
class User{
	private:
		string name;
		string dateOfBirth;
		string email;
		string password;
		int code;
	public:
		User(){
			name="\0";
			dateOfBirth="\0";
			email="\0";
			password="\0";
			code=0;
		}
		User(string n,string d,string e,string p){
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
		
		void Input(){
			int digit=0,specialCharacter=0,character=0,Code;
		  	cout<<"Enter name:";
		  	cin>>name;	
		  	cout<<"\nEnter date of birth:";
		  	cin>>dateOfBirth;
		  	cout<<"Enter email:";
		  	cin>>email;
		  	label:
		 	cout<<"Enter password:";
		 	cin>>password;
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
			if(code==Code){
				cout<<"\n*****************************Successfully registered!*****************************\n";
			}
			else{
				cout<<"\nError.Enter the code again:";
				goto label2;
			}
		}
		
		bool SaveObject(string fname)
		{
			bool save = true;
			ifstream file (fname, ios :: in);
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
					if (i == 3 && str == this->email)
					{	
						save = false;
						cout << endl << endl << "Object Already Exists "  << endl;
						file.close();
						return false;
					}
					i++;
				}
			}
			if(save == true)
			{
				fstream file (fname, ios :: app);
				if(file.is_open())
				{
					file << name << endl;
					file << this->dateOfBirth << endl;
					file << this->email << endl;
					file << this->password << endl;
					file << this->code << endl;
				}
				file.close();
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
		cout<<"\n\n*****************************Displaying user's details*****************************";
		cout<<"\nName: "<<name;
		cout<<"\nDate of birth: "<<dateOfBirth;
		cout<<"\nEmail: "<<email;
		cout<<"\nPassword: "<<password;
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
        task(const task & t)
        {
            name=t.name;
            deadline=t.deadline;;
            status=t.status;
            category=t.category;
            key=t.key;
            timet=t.timet;
            details = t.details;
            missedtask=t.missedtask;
            next=t.next;
            prev=t.prev;
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
    task *tail;
    linkedlist()
    {
        head=NULL;
        tail=NULL;
    }
    ////////////   aafreen's functions   //////////////
    void insert(string n, string d, string s, string c, int k, int t,bool m,string details) {
        task* newnode = new task(n, d, s, c, k, t, m, details);
        if (head == NULL && tail == NULL) {
            head = newnode;
            tail = newnode;
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

   task* search(string tname)
	{
	    task* t=head;
		while(t!=NULL){
			if(t->getname()==tname){
				return t;
			}
			t=t->next;
		}
    }

   void display()
    {
        task* t=head;
        cout<<"*********************************TASK DETAILS*********************************";
        while(t!=NULL){
           cout<<"\nTask name: "<<t->getname();
           cout<<"\nDeadline: "<<t->getdeadline();
           cout<<"\nCategory: "<<t->getcategory();
           cout<<"\nStatus: "<<t->getstatus();
           cout << "\nDetails: " << t->getdetails();
           cout<<"\nMissed tasks: "<<t->getmissedtask();
           cout<<"\nTime: "<<t->gettimet();
           t=t->next;
		}
    }

   
void sortdeadline() {
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
            int num1 = std::atoi(current->getdeadline().c_str());
            int num2 = std::atoi(nextNode->getdeadline().c_str());

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
    ////////////   fakhira's functions   //////////////
    void sortcategory() //sorting according to category
    {
    	string cat;
    	cout<<"Press:\n";
		cout<<"1 if you want tasks with more details on the top\n";
		cout<<"2 if you want tasks with less details on the top\n";
		cout<<"3 if you want to go back\n";
    	//if num==2 put the tasks with less details at top else if num==1 put the tasks with more deatils on top
        //ascending
        //descending
		if(cat=="1")
		{
			//more details
		}
		else if(cat=="2")
		{
			//less details
		}
		else 
		{
			return;
		}
        //category passed as parameter on top
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
    	string n;
    	cout<<"\Enter Task Name which you want to Update: ";
    	cin>>n;
        task *t=head;
        while(t->next->getname()!=n)
        {
        	t=t->next;
		}
		continue1:
    	int choice;
        cout<<"\nWhat do you want to update:\n1. Task Name\n2.Task deadline\n3.Task Status\n4.Task Category\n5.Task time"<<endl;
        cin>>choice;
        switch(choice)
        {
        	case 1:
			{
				string name;
				cout<< "Enter Name : ";
				cin>>name;
        		t->next->setname(name);
				break;
			}
			case 2:
			{
				string deadline;
				cout<<"Enter Deadline : ";
				cin>>deadline;
				t->next->setdeadline(deadline);
				break;
			}
			case 3:
			{
				string status;
				cout<<"Enter Status : ";
				cin>>status;
				t->next->setstatus(status);
				break;
			}
			case 4:
			{
				string category;
				cout<<"Enter Category : ";
				cin>>category;
				t->next->setcategory(category);
				break;
			}
			case 5:
			{
				int timet;
				cout<<"Enter Time : ";
				cin>>timet;
				t->next->settimet(timet);
				break;
			}
			default:
				{
					int val;
					cout<<"\nEnter :\n0 to continue updation in this task\n1 to update a new task\n2 to go back to main page\n";
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
						break;
					}
				}
		}
    }
    void deletet()
    {
    	string n;
    	cout<<"\Enter Task Name to be Deleted : ";
    	cin>>n;
        task *t=head;
        while(t->next->getname()!=n)
        {
        	t=t->next;
		}
	task *temp=t->next;
		t->next=t->next->next;
		delete temp;
    }
    task* archive()
    {
        string n;
    	cout<<"\Enter Task Name to be Archived : ";
    	cin>>n;
        task *t=head;
        while(t->next->getname()!=n)
        {
        	t=t->next;
		}
		task *temp=t->next;
		t->next=t->next->next;
		return temp;
    }
};


int inputfunction()
{
    int type;
    again:
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
    cout<<"\\nWhich list do you want to insert a task in:\n1.Academic tasks\n2.Shopping taks\n3.Personal tasks\n4.Events\n5.Wish list\n";
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
    else
    {
        cout<<"Enter a valid choice";
        goto label;
    }
}

int main() {
    
//    User user1("Taha", "xyz", "taha@gmailcom", "123456789");
//    User user2("Taha", "xyz", "taha@gmailcom", "123456789");
//    user1.SaveObject("users.txt");
//    user1.userDisplay();
//    
//	user2.SaveObject("users.txt");
//	user2.LoadObject("users.txt",&user2);

	User u;
    cout<<"=----------------- W E L C O M E     T O     T A S K     P R O -----------------="<<endl;
    int choice;
    
    option: //label if option other than 1, 2, 3 choosen
    cout<<"Choose an option:\n1. Are you Already registered?\n2.Do you want to register?\n3.exit\n";
    cin>>choice;
    if(choice==1)
    {
    		//----------------make a function in user class to take user input and password check if correct
		//check username with password
		//if correct info entered use read object from file and perform functions on it
	}
	else if(choice==2)
	{
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
	
	//program keeps running until user chooses to exit
	while(1)
	{
		mainn:
	    int userchoice=chooselist();
		int us=inputfunction();
	    if(us== 0)//insert
	    {
	    	u.l[userchoice]->insert();
		}
		else if(us==1)//update
	    {
	    	u.l[userchoice]->update();
		}
		else if(us==2)//delete
	    {
	    	u.l[userchoice]->deletet();
		}
		else if(us==3)//archive
	    {
	    	u.l[userchoice]->archive();
		}
		else if(us==4)//search
	    {
	    	u.l[userchoice]->search();
		}
		else if(us==5)//display
	    {
	    	u.l[userchoice]->display();
		}
		else if(us==6)//sort
	    {
	    	co1:
	       int num;
	        	cout<<"\nYou have the option to sort with respect to:\n1.Details\n2.Category\n3.Deadline\n4.Status\n";
	        	cin>>num;
	        	switch(num){
	        		case 1:
					{
						u.l[userchoice]->sortdetail();
						break;
					}
					case 2:
					{
						u.l[userchoice]->sortcategory();
						break;
					}
					case 3:
					{
						u.l[userchoice]->sortdeadline();
						break;
					}
					case 4:
					{
						u.l[userchoice]->sortstatus();
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
		else if(us==7)//store and exit
	    {
	    	exit(1);
		}
	    /*Feedback f;
	    f.FeedbackInput();
	    return 0;*/
	    return 0;
/*search function
String name;
task* t=l.search(name);
cout<<t.getname();.......other attributes
*/
	}
}