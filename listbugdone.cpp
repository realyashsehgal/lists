#include <iostream>
#include <list>
using namespace std;

// Declare a global list named list1 to store integers
list<int> list1;

// Define a class named lists to perform operations on the list
class lists
{
public:
    int element;    // Store the element value
    int position;   // Store the position value

public:
    // Function to push an element to the end of the list
    int push(int n)
    {
        cout << "Please enter the element you want to push" << endl;
        cin >> element;
        list1.push_back(element);   // Add element to the end of the list
        n++;
        return n;
    }

    // Function to pop the last element from the list
    int pop(int n)
    {
        if (n != 0)
        {
            cout << "Popping the last inserted element in the list " << endl;
            list1.pop_back();   // Remove the last element from the list
            cout << "Last element succesfully popped" << endl;
            n--;
            return n;
        }
        else
        {
            cout << "There is no element in the list " << endl;
            return n;
        }
    }

    // Function to insert an element at a specific position in the list
    int push_specific(int n)
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
        list1.insert(iter, element);    // Insert element at the specified position
        cout << "Succesfully inserted" << endl;
        n++;
        return n;
    }

    // Function to remove an element from a specific position in the list
    int pop_specific(int n)
    {
        cout << "Please enter the postion you want to remove from the list" << endl;
        cin >> position;
        if (position <= n)
        {
            list<int>::iterator it = list1.begin();
            for (int i = 0; i < position - 1; i++)
            {
                it++;
            }
            list1.erase(it);    // Erase element at the specified position
            cout << "Element succesfully removed" << endl;
            n--;
            return n;
        }
        else
        {
            cout << "There is no element at the given position " << position << endl;
            return n;
        }
    }

    // Function to display the elements of the list
    void display(int n)
    {
        if (n != 0)
        {
            list<int>::iterator it;
            for (it = list1.begin(); it != list1.end(); it++)
            {
                cout << (*it) << " ";
            }
            cout << endl;
        }
        else
        {
            cout<<"The list is empty"<<endl;
        }
    }
};

// Main function to drive the program
int main()
{
    lists mylist;   // Create an object of class lists
    int i, n, elem, choice = 0;
    cout << "Please enter the number of elements you want in your list" << endl;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Please enter the element you want to push in the list " << endl;
        cin >> elem;
        list1.push_back(elem);   // Add elements to the global list
    }
    // Display menu and perform operations based on user choice
    while (choice != 6)
    {
        cout << "---------------------------------------MENU---------------------------------------" << endl;
        cout << "1.Insert element\n2.Remove element\n3.Insert at specific postion\n4.Delete from specific postion\n5.Display list\n6.exit" << endl;
        cout << "Please select your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            n = mylist.push(n); // Call push function
            break;
        case 2:
            n = mylist.pop(n);  // Call pop function
            break;
        case 3:
            n = mylist.push_specific(n);    // Call push_specific function
            break;
        case 4:
            n = mylist.pop_specific(n); // Call pop_specific function
            break;
        case 5:
            mylist.display(n);  // Call display function
            break;
        default:
            cout << "Invalid input please try again" << endl;
            break;
        }
    }
}

