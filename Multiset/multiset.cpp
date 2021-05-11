#include <iostream>  
#include <set>  
#include <string>  
#include <cstdlib>  
  
using namespace std;  
  
int main()  
{  
    multiset<int> ms;  
    multiset<int>::iterator it, it1, msIt;  
    int choice, item;     
      
    while (1)  
    {  
        cout<<"\n---------------------"<<endl;  
        cout<<"Multiset Example"<<endl;  
        cout<<"\n---------------------"<<endl;  
        cout<<"1.Insert Number into the Multiset"<<endl;  
        cout<<"2.Delete Element from the Multiset"<<endl;  
        cout<<"3.Find Element in a Multiset"<<endl;  
        cout<<"4.Count Elements with a specific key"<<endl;  
        cout<<"5.Size of the Multiset"<<endl;  
        cout<<"6.Display Multiset"<<endl;  
        cout<<"7.First Element of the Multiset"<<endl;  
        cout<<"8.Exit"<<endl;  
        cout<<"Enter your Choice: ";  
        cin>>choice;  
          
        switch(choice)  
        {  
        case 1:  
            cout<<"Enter value to be inserted: ";  
            cin>>item;  
            if (ms.empty())  
                it1 = ms.insert(item);  
            else  
                it1 = ms.insert(it1, item);  
            break;  
        case 2:  
            cout<<"Enter value to be deleted: ";  
            cin>>item;  
            ms.erase(item);  
            break;  
        case 3:  
            cout<<"Enter element to find ";  
            cin>>item;  
            it = ms.find(item);  
            if (it != ms.end())  
                cout<<"Element found"<<endl;  
            else  
                cout<<"Element not found"<<endl;  
            break;  
        case 4:  
            cout<<"Enter element to be counted: ";  
            cin>>item;  
            cout<<item<<" appears "<<ms.count(item)<<" times."<<endl;  
            break;  
        case 5:  
            cout<<"Size of the Multiset: "<<ms.size()<<endl;  
            break;  
        case 6:  
            cout<<"Elements of the Multiset:  ";  
            for (it = ms.begin(); it != ms.end(); it++)  
                cout<<*it<<"  ";  
            cout<<endl;  
            break;  
        case 7:  
        if(ms.empty())  
        {  
            cout<<"Multiset is empty";  
        }  
        else  
        {  
            msIt =  ms.begin();  
                cout << "The First Element of the Multiset is " << *msIt << endl;   
        }  
             break;  
        case 8:  
            exit(1);  
            break;  
        default:  
            cout<<"Wrong Choice"<<endl;  
        }  
    }  
    return 0;  
}  