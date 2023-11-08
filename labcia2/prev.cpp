/*
Concepts:
1) DLL
2) CDLL
3) BST
4) BFS (graph) 
5) DFS (graph)
*/

/*
ONE
Create a circular singly linked list to store some set of numbers. Write and implement an algorithm to search a given number 's' from the list and to find the n th node data from node 's'
*/

/*
TWO
To perform the following operations on a double linked list,implement a menu driven program.
a.add an integer element to the list
b.display the list
c.get the two node positions,then swap the two node values
d.search a given number 's' from the list. start searching both from first node of the list and from the last node of the list and display to which node, the given number 's' is nearer?(from last or first
*/

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
    node()
    {
        data = 0;
        link = NULL;
    }
};
struct head
{
    int count;
    node *first;
    head()
    {
        count = 0;
        first = NULL;
    }
};

class csll
{
    head *main = new head();

public:
    void insert(int a)
    {
        node *temp = new node();
        temp->data = a;
        temp->link = NULL;
        if (main->first == NULL)
        {
            main->first = temp;
            temp->link = temp;
        }
        else
        {
            node *t = new node();
            t = main->first;
            if (main->count == 1)
            {
                main->first->link = temp;
                temp->link = main->first;
            }
            else
            {
                t = t->link;
                while (t->link != main->first)
                {
                    t = t->link;
                }
                t->link = temp;
                temp->link = main->first;
            }
        }
        main->count++;
        cout << "Data inserted successfully\n";
    }

    node *search(int s)
    {
        node *t = new node();
        t = main->first;
        if (t->data == s)
            return t;
        else
        {
            t = t->link;
            while (t != main->first && t->data != s)
                t = t->link;
            if (t != main->first)
            {
                return t;
            }
        }
    }
    void dis(node *b, int c)
    {
        node *temp1 = b->link;
        int count = 1;
        while (count - 1 != c && temp1 != b)
        {
            cout << "\n"
                 << count << " th node from " << b->data << " is " << temp1->data;
            temp1 = temp1->link;
            count++;
        }
        while (count - 1 != c)
        {
            cout << "\n"
                 << count << " th node from " << b->data << " is "
                 << "no node";
            count++;
        }
        cout << endl;
    }
    void display()
    {
        node *temp = new node();
        if (temp != NULL)
        {
            temp = main->first;
            cout << temp->data << "\n";
            temp = temp->link;
            while (temp != main->first)
            {
                cout << temp->data << "\n";
                temp = temp->link;
            }
        }
    }
};
int main()
{
    csll n;
    int num;
    int ch = 1;
    int no, s;
    node *a = new node();
    while (ch != 0)
    {
        cout << "Enter 1 for insert and 2 for display:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the number to insert:";
            cin >> num;
            n.insert(num);
            break;
        case 2:
            cout << "Enter the number to be searched and enter the number of nodes to be displayed from the search number:";
            cin >> s >> no;
            a = n.search(s);
            n.dis(a, no);
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    }
}
