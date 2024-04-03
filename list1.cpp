#include <iostream>
#include <list>
using namespace std;
list<int> list1;
class lists
{
private:
    int element;
    int position;

public:
    void push()
    {
        cout << "Please enter the element you want to push" << endl;
        cin >> element;
        list1.push_back(element);
    }
    void pop()
    {
        cout << "Popping the last inserted element in the list " << endl;
        list1.pop_back();
        cout << "Last element succesfully popped" << endl;
    }
    void push_specific()
    {
        cout << "Please enter the position where you want to add the element" << endl;
        cin >> position;
        cout << "Please enter the element you want to push" << endl;
        cin >> element;
        list<int>::iterator iter = list1.begin();
        for (int i = 0; i < position - 1; i++)
        {
            iter++;
        }
        list1.insert(iter,element);
        cout<<"Succesfully inserted"<<endl;
    }
    void pop_specific()
    {
        cout << "Please enter the postion you wan to remove from the list" << endl;
        cin >> position;
        list<int>::iterator it = list1.begin();
        for (int i = 0; i < position - 1; i++)
        {
            it++;
        }
        list1.erase(it);
        cout << "Element succesfully removed" << endl;
    }
    void display()
    {
        list<int>::iterator it;
        for (it = list1.begin(); it != list1.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;
    }
};
int main()
{
    lists mylist;
    int i, n, elem, choice = 0;
    cout << "Please enter the number of elements you want in your list" << endl;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Please enter the element you want to push in the list " << endl;
        cin >> elem;
        list1.push_back(elem);
    }
    while (choice != 6)
    {
        cout << "---------------------------------------MENU---------------------------------------" << endl;
        cout << "1.Insert element\n2.Remove element\n3.Insert at specific postion\n4.Delete from specific postion\n5.Display list\n6.exit" << endl;
        cout << "Please select your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            mylist.push();
            break;
        case 2:
            mylist.pop();
            break;
        case 3:
            mylist.push_specific();
            break;
        case 4:
            mylist.pop_specific();
            break;
        case 5:
            mylist.display();
            break;
        default:
            cout << "Invalid input please try again" << endl;
            break;
        }
    }
}
