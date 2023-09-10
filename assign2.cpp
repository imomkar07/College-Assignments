 #include<iostream>
using namespace std;

class Node
{
    public :
    int Data;
    Node *next;
    Node()
    {
        Data=0;
    }
};

class linkedlist
{
    public :
    Node *head = NULL;

    public : 
    void InsertAtHead(int val);
    void InsertAtTail(int val);
    void InsertAfter(int val, int pval);
    void InsertAtAnywhere(int val , int pos);
    void Display();
    int size();
    void Delete_at(int idx);
    void DeleteElement(int val);
    void ReverseList();
};

void linkedlist :: InsertAtHead(int val)
{
    Node *NewNode = new Node();
    NewNode -> Data = val;
    NewNode -> next = NULL;
    if(head == NULL)
    {
      head = NewNode;
    }
    else
    {
        NewNode -> next = head;
        head = NewNode;
    }
  
}

void linkedlist :: InsertAtTail(int val)
{
    Node *NewNode = new Node();
    NewNode -> Data = val;
    NewNode -> next = NULL;

    if(head == NULL)
    {
         head = NewNode;
    }
    else
    {
    Node *Temp = head;
    while(Temp -> next != NULL)
    {
        Temp = Temp -> next;
    }
    Temp -> next = NewNode;
    }
}

void linkedlist :: InsertAfter(int val, int pval)
{
    Node *NewNode = new Node();
    NewNode -> Data = val;
    NewNode -> next = NULL;
    Node *Temp = head;
    while(Temp -> next != NULL)
    {
        if(Temp -> Data == pval)
        {
            break;
        }
        Temp = Temp -> next;
    }
    if(Temp -> next == NULL)
    {
        cout<<"PREVIOUS VALUE NOT FOUND";
    }
    else
    {
        NewNode -> next = Temp -> next;
        Temp -> next = NewNode;
    }
}

void linkedlist :: InsertAtAnywhere(int val , int pos)
{
    Node *NewNode = new Node();
    NewNode -> Data = val;
    NewNode -> next = NULL;
    Node *Temp = head;
    if(pos==0)
    {
        InsertAtHead(val);
    }
    else if(pos==size())
    {
        InsertAtTail(val);
    }
    else if(pos<0 || pos > size())
    {
        cout<<"INVALID POSITION";
    }
    else 
    {
        for (int i = 1; i <= pos - 1; i++)
        {
            Temp = Temp->next;
        }
        NewNode->next = Temp->next;
        Temp->next = NewNode;
    }
}

int linkedlist :: size()
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void linkedlist :: Display()
{
    Node *Temp = head;
    while (Temp != NULL) 
    {
        cout << Temp->Data << " ";
        Temp = Temp->next;
    }
    cout << endl;
}

void linkedlist :: Delete_at(int idx) 
{
    if (idx == 0) 
    {
        head = head->next;
    } 
    else 
    {
        Node *Temp = head;
        Node *n = NULL;
        for (int i = 0; i < idx - 1; i++)
        {
            Temp = Temp->next;
        }
        n = Temp->next;
        Temp->next = Temp->next->next;
        delete n;
    }
}

void linkedlist :: DeleteElement(int val)
{
    Node *Temp = head;
    Node *p = NULL;
    while(Temp != NULL)
    {
        if(Temp -> Data == val)
        {
           break;
        }
        p = Temp;
        Temp = Temp -> next;
    }

    if(Temp == NULL)
    {
        cout<<"NUMBER NOT FOUND";
    }
    else if(Temp != head)
    {
        p -> next = Temp -> next;
    }
    else
    {
        head = head -> next;

    }
}

void linkedlist :: ReverseList()
{
    Node *prev=NULL;
    Node *current=head;
    Node *next=NULL;
    while(current != NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head = prev;
}

int main()
{
    linkedlist l1;
    l1.InsertAtHead(32);
    l1.InsertAtAnywhere(43,1);
    l1.InsertAtAnywhere(9,2);
    l1.InsertAtTail(54);
    l1.Display();
    l1.InsertAtHead(45);
    l1.InsertAfter(64,9);
    l1.Delete_at(2);
    l1.DeleteElement(45);
    l1.Display();
    l1.ReverseList();
    l1.Display();
}