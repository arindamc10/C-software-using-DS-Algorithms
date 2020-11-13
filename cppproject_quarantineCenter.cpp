#include <iostream>
#include <string>
using namespace std;
int c = 0;
struct quarantine
{
    string name;
    string address;
    int age;
    string arrival_date;
    string coming_from;
    string going_to;
    int allotted_room;
    string discharge_date;
}record[500];

void data_entry()
{
    cout << "Enter information: " <<endl;
        cout << "Enter name: ";
        cin >> record[c].name;

        cout << "Enter address: ";
        cin >> record[c].address;
        
        cout << "Enter age: ";
        cin >> record[c].age;
	

        cout << "Enter arrival date in dd/mm/yy: ";
        cin >> record[c].arrival_date;


        cout << "Enter coming from: ";
        cin >> record[c].coming_from;


        cout << "Enter going to: ";
        cin >> record[c].going_to;


        cout << "Enter allotted room: ";
        cin >> record[c].allotted_room;


        cout << "Enter discharge date in dd/mm/yy: ";
        cin >> record[c].discharge_date;
        cout << endl;
	c++;
}
void period()
{
	for(int i=0;i<c;i++)
	{
		string a = record[i].arrival_date;
		string b = record[i].discharge_date;
		int dd1 = stoi(a.substr(0,1));
		int mm1 = stoi(a.substr(3,4));
		int yy1 = stoi(a.substr(6,7));
		int dd2 = stoi(b.substr(0,1));
		int mm2 = stoi(b.substr(3,4));
		int yy2 = stoi(b.substr(6,7));
		if(mm1 == mm2)
		{
			if((dd2 - dd1) > 14)
			{
				record[i].name = "";
    			record[i].address = "";
    			record[i].age = 0;
    			record[i].arrival_date = " ";
    			record[i].coming_from = "";
    			record[i].going_to = "";
    			record[i].allotted_room = 0;
    			record[i].discharge_date = "00/00/00";
			}
		}
		else
		{
			int x = 0;
			if(mm1 == 1||mm1 == 3||mm1 == 5||mm1 == 7||mm1 == 8||mm1 == 10||mm1 == 12)
				x = 31+dd2-dd1;
			else if(mm1 == 2)
				x = 28+dd2-dd1;
			else
				x = 30+dd2-dd1;
			
			if(x>14)
			{
				record[i].name = "";
    			record[i].address = "";
    			record[i].age = 0;
    			record[i].arrival_date = "";
    			record[i].coming_from = "";
    			record[i].going_to = "";
    			record[i].allotted_room = 0;
    			record[i].discharge_date = "";
			}
		}
	}
}
int search(quarantine arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid].allotted_room == x) 
            return mid; 
        if (arr[mid].allotted_room > x) 
            return search(arr, l, mid - 1, x); 
        return search(arr, mid + 1, r, x); 
    } 
    return -1; 
}
void merge_sort(quarantine *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   quarantine larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i].allotted_room <= rarr[j].allotted_room) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}
void final_sort(quarantine *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      final_sort(array, l, m);
      final_sort(array, m+1, r);
      merge_sort(array, l, m, r);
   }
}


void full_list()
{
	final_sort(record,0,c-1);
	period();
	int k=0;
	for(int i=0;i<500;i++)
	{
		if(record[k].allotted_room == (81+i))
		{
			cout<<" "<<i+81<<"Occupied"<<endl;
			k++;			
		}
		else
		{
			cout<<" "<<81+i<<"Vacant"<<endl;
		}
	}
}
int main()
{
	char ch = ' ';
	for(int u=1;u<=500;u++)
	{
	cout<<"type 'i' to give information"<<endl;
	cout<<"type 's' to sort the rooms"<<endl;
	cout<<"type 'p' to search for a quarantined person"<<endl;
	cout<<"type 'l' for showing the list of rooms"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 'i': data_entry();
			break;
		case 's':{
		        final_sort(record,0,c-1);
				for(int i=0;i<c;i++)
				{
					cout<<"Name: "<<record[i].name<<endl;
				    cout<<"Address: "<<record[i].address<<endl;
				    cout<<"Age: "<<record[i].age<<endl;
				    cout<<"Arrival date: "<<record[i].arrival_date<<endl;
				    cout<<"Coming from: "<<record[i].coming_from<<endl;
				    cout<<"Going to: "<<record[i].going_to<<endl;
				    cout<<"Alloted room: "<<record[i].allotted_room<<endl;
				    cout<<"Discharge date: "<<record[i].discharge_date<<endl;
				    cout<<""<<endl;
				}  
		       } 
		     break;
		case 'p': 
		    {
		    cout<<"Enter a room number";
			int p = 0; 
			cin>>p;
			final_sort(record,0,c-1);
			int x = search(record,0,c-1,p);
			if(x == -1)
				cout<<"Sorry, the room is vacant "<<endl;
			else
			{
				cout<<"Name: "<<record[x].name<<endl;
				cout<<"Address: "<<record[x].address<<endl;
				cout<<"Age: "<<record[x].age<<endl;
				cout<<"Arrival date: "<<record[x].arrival_date<<endl;
				cout<<"Coming from: "<<record[x].coming_from<<endl;
				cout<<"Going to: "<<record[x].going_to<<endl;
				cout<<"Alloted room: "<<record[x].allotted_room<<endl;
				cout<<"Discharge date: "<<record[x].discharge_date<<endl;
				cout<<""<<endl;
			}
		    }
			break;
		case 'l': full_list();
			break;
	    }
    }
    
    return 0;
}
