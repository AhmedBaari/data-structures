/* Today, we are going to implement a graph*/

// First, let's import the necessary libraries
#include <iostream>
using namespace std;

/* We will have 3 structures: Head, Vertex, Arc */
struct head;
struct gvertex;
struct garc;

/* The head will be used to control all vertexes
It has count and first vertex */
struct head
{
    int count;
    gvertex *firstVertex; // * is for pointer
};

/* The Vertex has the following parts
Next Vertex: What is the vertex after this?
Data: Either character or integer. I'll use character
Processed: Did the BFT/DFT go through this already?
In Stack: Is this element present in BFT/DFT stack right now?
First arc: The first element in it's own linked list of relationships
*/
struct gvertex
{
    gvertex *nextVertex;
    char data;
    bool processed;
    bool inStack;
    garc *firstArc;
};

/* The ARC will have:
Content: the other vertex this is having a relationship with
next garc: next arc in this linked list
*/
struct garc
{
    gvertex *content;
    garc *nextArc;
};

/* Also, we will have a node for the stack */
struct node
{
    gvertex *vertex;
    node *below;
};

/* Now, we will create a stack application to handle the DFT/BFT stack*/
class Stack
{
public:
    int count;
    node *top;
    Stack() : count(0) {}

    /* To push a node into the stack */
    bool push(gvertex *v)
    {
        node *greenie = new node();
        greenie->vertex = v;
        greenie->below = NULL;

        if (count == 0)
        {
            top = greenie;
        }
        else
        {
            // node *temp = top;
            // while(top && top->below) {
            //     top = top->below;
            // }
            // top->below = greenie;
            greenie->below = top;
            top = greenie;
        }
        count++;

        return true;
    }

    gvertex *pop()
    {
        node *victim = top;
        gvertex *poppedData = victim->vertex;
        top = top->below;
        delete victim;
        count--;
        return poppedData;
    }
};

/* Now, the graph class */
class graph
{
public:
    gvertex *firstVertex;
    int count;

    graph()
    {
        count = 0;
        firstVertex = NULL;
    }

    void insertVertex(char data)
    {
        // Declare new vertex
        gvertex *greenie = new gvertex();

        // Fill it's stuff
        greenie->nextVertex = NULL;
        greenie->data = data; // Data is inserted here
        greenie->processed = greenie->inStack = false;
        greenie->firstArc = NULL;

        // Insert it in the right place
        if (count == 0)
        {
            firstVertex = greenie;
        }
        else
        {
            // Traverse to last vertex
            gvertex *runner = firstVertex; // Don't forget the "*"
            while (runner->nextVertex != NULL)
            {
                runner = runner->nextVertex;
            }
            // Link greenie to the last vertex
            runner->nextVertex = greenie;
        }
        count++;
        cout << "Vertex Successfully Inserted!";
    }

    /* Now, we will insert ARC */
    bool insertArc(char male_data, char female_data)
    {
        // First, we will find the vertexes which hold the data of male and female
        if (!firstVertex)
        {
            cout << "No vertexes available" << endl;
            return false;
        }
        gvertex *male = firstVertex;
        gvertex *female = firstVertex;

        while (male && male->data != male_data) // ⭕ DANGER
        {
            male = male->nextVertex;
        }
        if (male->data != male_data)
            return false;

        while (female && female->data != female_data) // ⭕ DANGER
        {
            female = female->nextVertex;
        }
        if (female->data != female_data)
            return false;

        /* Inserting ARC in MALE to target FEMALE */
        garc *greenie = new garc();
        
        greenie->content = female;
        greenie->nextArc = NULL;
        
        // Inserting MALE arc in MALE Relationships
        if (male->firstArc == NULL) {
            male->firstArc = greenie;
        } else {
            // Traverse to last element
            garc *runner = new garc(); // is () required?

            runner = male->firstArc;
            while (runner->nextArc !=NULL)
            {
                runner = runner->nextArc;
            }
            runner->nextArc = greenie;
        }


        /* Inserting ARC in FEMALE to target MALE */
        garc *greenie = new garc();

        greenie->content = male;
        greenie->nextArc = NULL;

        // Inserting MALE arc in MALE Relationships
        if (female->firstArc == NULL)
        {
            female->firstArc = greenie;
        }
        else
        {
            // Traverse to last element
            garc *runner = new garc(); // is () required?

            runner = female->firstArc;
            while (runner->nextArc != NULL)
            {
                runner = runner->nextArc;
            }
            runner->nextArc = greenie;
        }
    }

    void depthFirstTraversal () {
        // We need stack for DFT
        Stack DFTstack;

        // We will keep count of visited vertexes, to compare with the vertexcount
        int visitedVertexes = 0;

        // Create the runner
        gvertex *runner = firstVertex;

        // Push the first vertex to begin
        DFTstack.push(runner);
        runner->processed = true;
        runner->inStack = true;
        visitedVertexes++;
        cout << runner->data << "\t"; //print data

        // Get Stack Top

        // Traverse to next unprocessed arc
        
    }

};

int main()
{
    cout << "Hello World" << endl;
}