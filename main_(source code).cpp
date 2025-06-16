#include<iostream>
#include<string>
#include <sstream>
#include <bits/stdc++.h>
#include<windows.h>
#include"queue.h"
#include"animation.h"
#include"stack.h"

using namespace std;

int search(int);

int display();
string check(int);       //   for checking quantity

////////////////////////////////////////////////////////////////////
struct node
 {
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct    node* next;
};
struct customer
{

 int ID;
 string name;

};

struct node *head=NULL;

////////////////////////////////////////////////////////////////////
 void beg()
{
	system("cls"); //clear the screen

	int id,quant;           //  quant  for quantity
	string name;
	double pre;            //  pre for price
	struct node *t=new node;
	struct node *p=head;
     int n;

	cout<<"\t\t enter product ID:-"<<endl;

	bool states=false;
	do { cin>>id;

	if(search(id)!=0)
    {
        t->ID=id;
    states=true;

    }else
    {
        cout<<"id is already exist please try another one"<<endl;

    }} while(states==false);

	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->prePrice=pre;

	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
	if(head==NULL)
	{
	t->next=head;
	head=t;
	}
	system("cls");
    cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";

	}

///////////////////////////////////////////////////////////////////////////////////////////


	int search(int id)                     //    for search item in list
 {


 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)

 			return 0;
 		else{
 			count++;
 			p=p->next;
 		}
	}
 	return count;
 }
 
////////////////////////////////////////////////////////////////////////
void delPro() {
 	system("cls");
 	display(); // Display the current list

 	int id;
 	cout << "\n\nEnter ID to delete that product:\n\n";
 	cin >> id;

 	if (head == nullptr) {
 		system("cls");
 		cout << "List is empty" << endl;
 		return;
 	}

 	node *cur = head;

 	node *pre = nullptr;

 	int pos = search(id);
 	if (pos == -1) {
 		cout << "\n<<<Not found>>\n\n";
 		return;
 	}

 	if (cur->ID == id) {
 		head = cur->next;
 		delete cur;
 		system("cls");
 		cout << "\n<<Item is deleted>>\n";
 		return;
 	}

 	while (cur != nullptr && cur->ID != id) {
 		pre = cur;
 		cur = cur->next;
 	}

 	if (cur == nullptr) {
 		cout << "\n<<<Not found>>\n\n";
 		return;
 	}

 	pre->next = cur->next;
 	delete cur;

 	system("cls");
 	cout << "\n<<Item is deleted>>\n";
 }


//////////////////////////////////////////////////////////////////////////////////
	void modify()
	{
		int id;
		double pre;        //    pre for price
		string pName;
		int nid; int nq;     //   pName for new name
		if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
    }
         else
	{
	    display();
		cout<<"\n\nEnter ID to modify product Name and its price:\n";
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=display();               //   for load number of nodes
	    pos=search(id);
	                            //   for check weather desire node is exist or not
	    if(pos<=count)
    {
		while(cur->ID!=id)
        {
			cur=cur->next;
		}
		cout<<"\nOld ID : "<<cur->ID<<endl;
		cout<<"\nOld Name : "<<cur->proName<<endl;
		cout<<"\nOld Price : "<<cur->prePrice<<endl;
		cout<<"\nOld Quantity : "<<cur->quantity<<endl;

		cout<<endl<<endl;
		cout<<"Enter new ID:";
		bool states=false;
	  do { cin>>nid;
       if (nid==cur->ID)
        {
            cur->ID=nid;
            states=true;
       }
	   else if(search(nid)!=0)
       {
       cur->ID=nid;
       states=true;
        }
    else
        {cout<<"id is already exist please try another one"<<endl;
        }} while(states==false);

		cout<<"Enter new Name:";
		cin>>pName;
		cur->proName=pName;
		cout<<"Enter new Price:";
		cin>>pre;
		cur->prePrice=pre;
		cout<<"Enter new Quantity:";
		cin>>nq;
		cur->quantity=nq;
		cout<<"\n-------Product Modified-------\n";
	}

	    else
    {
		cout<<id<<" is <<<Not found>>\n\n";
	}
	}
}

//////////////////////////////////////////////////////////////////////////////////////
int display()
{
		system("cls");
		int c=0;             //   c for counter products
		struct node *p=head;
		cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
		cout<<"=================================================================|\n";
		while(p!=NULL)
		{
			cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->prePrice<<"\t\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
			p=p->next;
			c=c+1; // encrements the counter c + 1 for each product displayed
		}
		cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
		return c;
	    }
////////////////////////////////////////////////////////////////////////////////////////
	    string check(int quant)

	{              //        check function
	    int a = quant;
       stringstream ss;
       ss << a;
      string quantity = ss.str();

	    	if(quant<=0)
	    	return "out of stock!";
	    	else
	    	return quantity;
		}
///////////////////////////////////////////////////////////////////////
	void buy() {
    system("cls");              // Clear the screen
    display();                 // Display the current list of products
    string products[20];       // Array to store names of purchased products
    int pay = 0, no, c = 0, price, id, i = 1;

    if (head == NULL) {        // Check if the product list is empty
        cout << "\n<<<<There is no items to buy>>>>\n\n";
    } else {
        cout << "How many items do you want to buy?\n";
        cin >> no;            // Get the number of items the user wants to buy
        int count = display();  // Store the number of nodes in 'count'

        while (i <= no) {     // Loop until the number of items to buy is reached
            struct node *cur = head; // Start from the head of the list
            int quant; // Quantity to purchase
            cout << "Enter ID of the item that you want to buy: ";
            cin >> id; // Get the ID of the item

            if (id == -1) { // If user inputs -1, clear the screen and return to the main menu
                system("cls");
                return;
            }

            int pos = search(id); // Search for the item by ID
            if (pos <= count) {  // If the item is found in the list
                while (cur->ID != id) { // Find the node with the matching ID
                    cur = cur->next;
                }

                cout << "How many quantities do you want: ";
                cin >> quant; // Get the quantity to purchase

                if (cur->quantity < quant) { // Check if sufficient quantity is available
                    cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
                    cout << "\n\t\t\t-----(Press -1 to Back to Main Menu)------" << endl;
                    continue; // Continue to the next iteration to let the user enter valid data
                }

                products[c] = cur->proName; // Store the product name in the array
                c++; // Increment the count of purchased products
                pay += (cur->prePrice * quant); // Calculate the total bill
                cur->quantity -= quant; // Update the quantity in the list
                i++; // Increment the count of processed items
            } else {
                cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }
        }

        string customer;
        cout << "\n\t\tEnter Your Name: ";
        cin >> customer; // Get the name of the customer
        enqueue(customer); // Enqueue the customer's name

        system("cls"); // Clear the screen

        cout << "\n\n\n\n\t\t\tYou have bought: ";
        for (int i = 0; i < no; i++) { // Display the purchased items
            cout << products[i] << " ";
        }

        if (pay >= 3000) { // Apply a discount if the total bill is greater than or equal to 3000
            price = pay * 0.90; // Calculate the price with a 10% discount
            cout << "\n\nOriginal price: " << pay;
            cout << "\nWith 10% discount: " << price << "\nThank you for shopping!\n\n";
        } else {
            price = pay; // No discount applied
            cout << "\nBill Amount: " << price << "\nThank you for shopping!\n\n";
        }
    }
}



 /////////////////////////////////////////////////////////////////////////////////////////
 int membership()
 {
 		string customer;
        cout<<"\n\t\t Enter Your User Name :";
        cin.ignore(); //
		getline(cin,customer);

        enqueue(customer);
        system("cls");
        display();
		string products[20];
		   //   for display sold items
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL)
        {
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else
        {
		cout<<"How many items you want to buy!\n";
		cin>>no;
        int count=display();           //   for store no of nodes  in c
		while (i<=no)    // cheack if the counter i <= number of products
        {
			struct node *cur=head;
            int quant,cho;   a:           //   quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1)
			{
			system("cls");
			}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"How many quantities you want:";
	       cin>>quant;
	       if(cur->quantity<quant)
           {
               cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
               goto a;

           }
           products[c]=cur->proName;   // this will conatin the items buy names in array;
		   c++;

	       pay=pay+(cur->prePrice*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {

		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";

}
}

	    system("cls");
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show the item you have bought
        cout<<products[i]<<" ";
       }
 	    price=pay*(0.80);           //    with 20% discount as member
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 20% discount: "<<price;
    }

        if(pay>=3000){
        							          //    coupon
        cout<<"\n You have won coupon worth 500 EGP"<< "\nThank you for shopping !\n\n";
		}
         else{
         cout<<"\n shop more to win gift coupons"<< "\nThank you for shopping !\n\n";
		}

}

 /////////////////////////////////////////////////////////////////////////////////////////
  int newmembership()
 {
     struct customer *cus = new customer;
 		int cou = 1;
        cout<<"\n\t\t Enter Your Name :";
		getline (cin,cus->name);
        cus->ID=cou;
        cou++;
        enqueue(cus->name);

        display();
		string products[20];
		   //   for display sold items
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL) // if the array list is empty
        {
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else
        {
		cout<<"How many items you want to buy!\n";
		cin>>no;
        int count=display();           //   for store number of items in c
		while (i<=no)
        {
			struct node *cur=head;
            int quant,cho;   a:           //   quant   for quantity  , cho for choice a is a label for goto statement
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1)
			{
			system("cls");
			}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"How many quantities you want:";
	       cin>>quant;
	       if(cur->quantity<quant)
           {
               cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
               goto a;

           }
           products[c]=cur->proName;   // this will conatin the items buy names in array;
		   c++;

	       pay=pay+(cur->prePrice*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {

		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";

}
}

	    system("cls");
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show that item you have bought
        cout<<products[i]<<" ";
       }
 	    price=(pay+1000);           //    amount  + membership (will get discount from next time)
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with purchase of membership card: "<<price; //adding price of membership card
}
        cout<<"\n You will get membership discount from next time "<< "\nThank you for shopping !\n\n";


}

 ////////////////////////////////////////////////////////////////////////////////////////
   int stock()
	{
		system("cls");
			int ch;


	do {

                 //            choice for below message



	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|                Stock                     |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 for ADD a new product    "<<endl;
	cout<<"\t\t     Enter 2 to display all products   "<<endl;
	cout<<"\t\t     Enter 3 for MODIFY Existing product"<<endl;
	cout<<"\t\t     Enter 4 for Delete a particular product item"<<endl;
	cout<<"\t\t     Enter 0 for Main Menu"<<endl;


	cout<<"\nEnter Your choice >>>";   cin>>ch;
	switch(ch){
	case 1:
	beg();
	break;
case 2:
	system("cls");
    display();
    break;
case 3:
	modify();
	system("cls");

	break;
case 4:
	delPro();
//cout<<"\n-------Product is Deleted-------\n";
	break;

default: system("cls");
	}
}
while(ch!=0)	;
}

////////////////////////////////////////////////
void administator()
	{
		int ch;
		system("cls");



	do {

                 //            choice for below message



	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|          Administator Portal              |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 to display all products   "<<endl;
	cout<<"\t\t     Enter 2 for Customers List "<<endl;
	cout<<"\t\t     Enter 3 for Dequeue customer"<<endl;
	cout<<"\t\t     Enter 0 for Main Menu"<<endl;


	cout<<"\nEnter Your choice >>>";   cin>>ch;
	switch(ch){
case 1:
	system("cls");
    display();
    break;
case 2:
	  system("cls");
      cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  displayQueue();
	   break;
case 3:
	   system("cls");
	  cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  dequeue();
      displayQueue();
	break;

default: system("cls");

	}
}
while(ch!=0)	;
}

///////////////////////////////////////////////////////////////////////////

int main()
{
     for(int i=0;i<=51;i++)
     {
     	push(i);
	 }

		system("color 0C");     //  for console color 0>background black , c>font light red
	gotoxy(17,5);
	cout<<"--------------------------------------------------"<<endl;
	gotoxy(17,7);
	cout<<"||            Super Market Project             ||"<<endl;
	gotoxy(17,9);
	cout<<"--------------------------------------------------"<<endl;
   	gotoxy(17,11);
   	cout<<"|Supervisor -->>  prof. Mohamed Abdelaziz    <<-- |\n"<<endl;
   	gotoxy(17,13);
 	cout<<"|Special thanks to -->>  Dr. Radwa Taher    <<-- |\n"<<endl;
 	gotoxy(17,15);
   	cout<<"     >>>-----Project Implemented By-----<<<"<<endl;
    gotoxy(22,17);
   	cout<<"Aser Mohamed Ali Mahmoud   (222102487)"<<endl;
   	gotoxy(22,18);
   	cout<<"Mahmoud Emad Mohamed       (223104648)"<<endl;
   	gotoxy(22,19);
   	cout<<"Hossam Ayman Elders        (222200017)"<<endl;
   	gotoxy(22,20);
   	cout<<"Abdallah Mostafa Mohamed   (223104683)"<<endl;
   	gotoxy(22,21);
   	cout<<"Ahmed Saeed Ahmed          (223102981)"<<endl;
   	gotoxy(22,22);
   	cout<<"Mohamed hesham Abdelhalim  (A20001133)"<<endl;
   	gotoxy(22,23);
   	cout<<""<<endl<<endl;
	system("pause"); // pause the exection and waits for user to press any key
	system("cls"); // clear the screen
	system("color Fc");  //  for console color 0>background off-white , c>font light red
	///////////////////////////
	int ps;
	cout<<"\n\t\t|	Super Market Login	|\n";
	cout<<"\n\t\tEnter Password: ";
	cin>>ps;
	if(ps==1161)
	{
		cout<<"\t\tWelcome \n\n";

	///////////////////////////
    int ch;

	while(ch!=5){

	                     //            choice for below message

    cout<<"\n\t\t|--------<Main Menu>-----------|";
    cout<<"\n\n";
	cout<<"\t\t 1)Stock                  \n";
	cout<<"\t\t 2)Customer               \n";
	cout<<"\t\t 3)Membership Customer    \n";
	cout<<"\t\t 4)Admin                  \n";
	cout<<"\t\t 5)Exit                   \n";

	cout<<"\nEnter Your choice >>>";cin>>ch;

		switch(ch){

	case 1:

		stock();

		break;

	case 2:
		cout<<endl<<endl;
		bpop();
		system("pause");
	    buy();
	    break;


	case 3:

		int choice;
		while(choice!=2){
			cout<<"\t\t 1)Existing Member                  \n";
			cout<<"\t\t 2)New Member Register              \n";

				cout<<"\nEnter Your choice >>>";cin>>choice;
		switch(choice){
		case 1:
			membership();
			break;
		case 2:
			newmembership();
			break;
		}
		break;
	}
	break;


	case 4:
    	administator();
    	break;


    case 5:
    	cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
    	break;

	}

}
return 0;


}
	else{
	cout<<"\t\tWrong password \n\n";
	}
}

