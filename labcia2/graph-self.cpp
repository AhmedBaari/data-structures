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

    gvertex *pop() // * for pop
    {
        node *victim = top;
        gvertex *poppedData = victim->vertex;
        top = top->below;
        delete victim;
        count--;
        return poppedData;
    }

    node *topstack()
    {
        return top;
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
        garc *greenie2 = new garc();

        greenie2->content = male;
        greenie2->nextArc = NULL;

        // Inserting FEMALE arc in FEMALE Relationships
        if (female->firstArc == NULL)
        {
            female->firstArc = greenie2;
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
            runner->nextArc = greenie2;
        }
    }

    void depthFirstTraversal () {
        // We need stack for DFT
        Stack DFTstack;

        // We will keep count of visited vertexes, to compare with the vertexcount
        int visitedVertices = 0;

        // The Vertex Runner for DFT
        gvertex *runner = firstVertex;

        // Push the first vertex to begin
        DFTstack.push(runner);
        runner->processed = true;
        runner->inStack = true;
        visitedVertices++;
        cout << runner->data << "\t"; //print data

        // Now perform the traversal as long as all vertexes are visited
        while (count != visitedVertices) {
            // Get the stack top 
            /*
            Vertex & next arc
            */
            node *stackTop = DFTstack.topstack();

            // Start a runner at the vertex's relationships list
            garc *ARCrunner = stackTop->vertex->firstArc;

            // forward to the relationship which is NOT PROCESSED
            while (ARCrunner != NULL && ARCrunner->content->processed == true) {
                ARCrunner = ARCrunner->nextArc;
            }
            /* If we have reached an unprocessed arc, do the rituals */
            if (ARCrunner != NULL) {
                gvertex *targetVertex = ARCrunner->content;
                DFTstack.push(targetVertex); // push the content to stack
                targetVertex->processed = true;
                targetVertex->inStack = true;
                visitedVertices++;
                cout << targetVertex->data << "\t";
            }

            else {
                // BACKTRACK
                /* This is done when the vertex at top of stack doesn't have any adjascent unprocessed vertexes */
                gvertex *poppingVertex = DFTstack.pop();
                poppingVertex->inStack = false;

                /* If the stack is empty, then that network is over. We'll try again with the next UNPROCESSED vertex */
                if (DFTstack.topstack() == NULL) {
                    runner = firstVertex->nextVertex; // Just making it more efficient by starting in 2nd instead of 1st vertex

                    while(runner != NULL && runner->processed == true) {
                        runner = runner->nextVertex;
                    }

                    /* If we find an unprocessed vertex */
                    if (runner !=NULL) {
                        DFTstack.push(runner);
                        runner->processed = true;
                        runner->inStack = true;
                        visitedVertices++;
                        cout << runner->data << "\t";
                    }
                }
            }
        }
        cout << "\n";

        // Traverse to next unprocessed arc
        
    }

};

int main()
{
    graph myGraph;
    int choice;
    char vertexData, startVertexData, endVertexData;

    do
    {
        cout << "\n=============================\n";
        cout << "           MENU\n";
        cout << "=============================\n";
        cout << "1. Insert Vertex\n";
        cout << "2. Insert Edge\n";
        cout << "3. Depth First Search\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter character to insert: ";
                cin >> vertexData;
                myGraph.insertVertex(vertexData);
                break;

            case 2:
                cout << "Enter characters to add edge: ";
                cin >> startVertexData >> endVertexData;
                if (myGraph.insertArc(startVertexData, endVertexData))
                    cout << "Edge inserted between " << startVertexData << " and " << endVertexData << "." << endl;
                else
                    cout << "Either one or both vertices not present in graph.\n";
                break;

            case 3:
                myGraph.depthFirstTraversal();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}