#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
	    void receipt();
};

void shopping::menu()
{
	int choice;
	string email;
	string password;
	
	cout << "_______________________________\n";
	cout << "                               \n";
	cout << "    Welcome to Supermarket      \n";
	cout << "_______________________________\n";
	cout << "                               \n";
	cout << "|  1) Administrator   |\n";
	cout << "|                     |\n";
	cout << "|  2) Buyer           |\n";
	cout << "|                     |\n";
	cout << "|  3) Exit            |\n";
	cout << "|                     |\n";
	cout << "                               \n";
	cout << " Please select! ";
	cin >> choice;
	
	switch (choice)
	{
		case 1:
			cout << " Please Login  \n";
			cout << " Enter Email ";
			cin >> email;
			cout << " Enter Password ";
			cin >> password;
			
			if (email == "preetykri0501@gmail.com" && password == "preety@123")
			{
				administrator();
			}
			else
			{
				cout << "Invalid email/password";
			}
			break;
		
		case 2:
			buyer();
			break;
		
		case 3:
			exit(0);
			break;
		
		default:
			cout << "Please select from the given options";
			break;
	}
};

void shopping::administrator()
{
	m:
	int choice;
	
	cout << "\n\n\n   Administrator menu";
	cout << "\n|____1) Add the Product_______|";
	cout << "\n|                             |";
	cout << "\n|____2) Modify the Product____|";
	cout << "\n|____                     ____|";
	cout << "\n|____3) Delete the Product____|";
	cout << "\n|____                     ____|";
	cout << "\n|____4) Back to main menu ____|";
	
	cout<<"\n\n Please enter your choice ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
			
			case 2:
				edit();
				break;
				
				case 3:
					rem();
					break;
					
					case 4:
						menu();
						break;
						
						default :
							cout<<"Invalid Choice!";
								
	}
	goto m;	
};

void shopping::buyer()
{
	m:
	int choice;
	cout<<"   Buyer \n";
	cout<<" _____________    \n";
	cout<<"                  \n";
	cout<<" 1) Buy Product   \n";
	cout<<"                  \n";
	cout<<" 2) Go Back       \n";
	cout<<" Enter your Choice : ";
	
	cin>>choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
			case 2:
				menu();
				
				default :
					
					cout<<"Invalid choice";
					
	}
	goto m;
	
};
void shopping::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n  Add new product";
	cout << "                     \n";
	cout<<"\n\n Product code of the product ";
	cin>>pcode;
	cout<<"\n\n Name of the product ";
	cin>>pname;
	cout<<"\n\n Price of the product ";
	cin>>price;
	cout<<"\n\n Discount on product ";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{	
		data.open("database.txt",ios::app|ios::out);
		data<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
		data.close();	
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
}
	if(token==1) 
	goto m;
	else{
		data.open("database.txt",ios::app|ios::out);
		data<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
		data.close();	
}
	
	cout<<"\n\n\t\t Record inserted !";
}
void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n Modify the record";
	cout<<"\n Product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
		else{
			data1.open("database1.txt", ios::app|ios::out);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pkey==pcode)
				{
					cout<<"\n Product new code: ";
					cin>>c;
					cout<<"\n Name of the product: ";
					cin>>n;
					cout<<"\n Price: ";
					cin>>p;
					cout<<"\n Discount: ";
					cin>>d;
					data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
					cout<<"\n\n Record edited ";
					token++;
				}
				else
				{
					data1<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
					
				}
				data>>pcode>>pname>>price>>dis;
				}
			data.close();
			data1.close();
			
			remove("database.txt");
			rename("database1.txt","database.txt");
			
			if(token==0)
			{
				cout<<"\n\n Record not found sorry!";
			}
		}
		
			
			
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\nDelete product";
    cout << "\n\nProduct code  :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\nProduct deleted successfully";
                token++;
            }
            else
            {
                data1 << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|___________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	

    data.close();
}

void shopping ::receipt()
{
	fstream data;
	
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t RECIEPT ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	
	else{
		data.close();
		
		list();
		cout<<"\n___________________________________________\n";
		cout<<"\n                                           \n";
		cout<<"\n        Please place the order             \n";
		cout<<"\n                                           \n";
		cout<<"\n___________________________________________\n";

	do
		{
			m:
			cout<<"\n\nEnter product code  :";
			cin>>arrc[c];
			cout<<"\n\nEnter the product quantity  :";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press y else n ";
			cin>>choice;
		}
	while (choice == 'y');
		
		cout << "\n\n_________________________________RECEIPT__________________________\n";
cout << "\nProduct No\t\tProduct Name\t\tProduct quantity\t\tprice\t\tAmount with discount\n";

data.open("database.txt", ios::in);
if (!data) {
    cout << "Error opening file. Exiting...";
    return;
}

for (int i = 0; i < c; i++) {
    bool found = false; // Flag to indicate if the product was found
    
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        if (pcode == arrc[i]) {
            amount = price * arrq[i];
            dis = amount - (amount * dis / 100);
            total += dis;
            cout << "\n" << pcode << "\t\t\t" << pname << "\t\t\t" << arrq[i] << "\t\t\t\t" << price << "\t\t\t\t" << dis;
            found = true;
            break; // Exit the inner loop once the product is found
        }
        data >> pcode >> pname >> price >> dis;
    }
    
    if (!found) {
        cout << "\nProduct with code " << arrc[i] << " not found.";
    }
}

data.close();

		
		cout<<"\n\n_____________________________________________";
		cout<<"\n Total Amount : "<<total;
		
	}}
int main()
{
	shopping s;
	s.menu();

	return 0;
}

