#include <iostream>
//Muhammad Hasnat Rahim 47474
//Sarmad Hassan 45724
using namespace std;

class NodeSy
{
	public:
    	int data;
    	NodeSy* next;

    	NodeSy(int value) : data(value), next(NULL) {}
};

class NodeDy
{
	public:
    	int data;
    	NodeDy* next;
	    NodeDy* prev;

    	NodeDy(int value) : data(value), next(NULL), prev(NULL) {}
};
class SinglyLinkedList
{
	public:
    	NodeSy* head;
    	SinglyLinkedList() : head(NULL) {}

    void addFirst(int value)             // Time Complexity : O(1)      
	{
        NodeSy* new_node = new NodeSy(value);
        new_node->next = head;
        head = new_node;
    }

    void addLast(int value)                 // Time Complexity : O(n) 
	{
        NodeSy* new_node = new NodeSy(value);
        if (!head)
		{
            head = new_node;
            return;
        }
        NodeSy* last_node = head;
        while (last_node->next)
		{
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    int deleteFirst()           // Time Complexity : O(1) 
	{
        if (!head)
		{
            return -1;
        }
        int deleted_value = head->data;
        NodeSy* temp = head;
        head = head->next;
        delete temp;
        return deleted_value;
    }

    int deleteLast()                    // Time Complexity : O(1) 
	{
        if (!head)
		{
            return -1;
        }
        if (!head->next)
		{
            int deleted_value = head->data;
            delete head;
            head = NULL;
            return deleted_value;
        }
        NodeSy* second_last = head;
        
        while (second_last->next->next)
		{
            second_last = second_last->next;
        }
        
        int deleted_value = second_last->next->data;
        delete second_last->next;
        second_last->next = NULL;
        return deleted_value;
    }

    void insertAt(int value, int index)                       // Time Complexity : O(n) 
	{
        if (index == 0)
		{
            addFirst(value);
        }
		else
		{
            NodeSy* new_node = new NodeSy(value);
            NodeSy* current = head;
            for (int i = 0; i < index - 1; ++i)
			{
            	if (!current)
				{
                    cerr << "Index out of range" << endl;
                    return;
                }
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    bool search(int value)                          // Time Complexity : O(n) 
	{
        NodeSy* current = head;
        while (current)
		{
            if (current->data == value)
			{
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isPalindrome()                               // Time Complexity : O(n) 
	 {
         if (!head) 
		{
            return false; // Empty list exception
        }
		
        NodeSy* slow = head;
        NodeSy* fast = head;
        NodeSy* prev = NULL;

        // Half ko reverse
        while (fast != NULL && fast->next != NULL) 
		{
            fast = fast->next->next;

            NodeSy* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // If the linked list has an odd number of elements, skip the middle element
        if (fast != NULL) 
		{
            slow = slow->next;
        }

        // Compare the reversed first half with the second half
        while (slow != NULL) 
		{
            if (slow->data != prev->data) 
			{
            	cout<<"Is not a palindrome"<<endl;
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        
    cout<<"Is a palindrome"<<endl;
        return true;
    }

    int countNodes()                    // Time Complexity : O(n) 
	{
        int count = 0;
        NodeSy* current = head;
        while (current)
		{
            ++count;
            current = current->next;
        }
        return count;
    }

    int max()                               // Time Complexity : O(n) 
	{
        if (!head)
		{
            return -1;
        }
        int max_value = head->data;
        NodeSy* current = head->next;
        
        while (current)
		{
            if (current->data > max_value)
			{
                max_value = current->data;
            }
            current = current->next;
        }
        return max_value;
    }

    double average()                  // Time Complexity : O(n) 
	{
        if (!head)
		{
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        NodeSy* current = head;
        while (current)
		{
            total += current->data;
            ++count;
            current = current->next;
        }
        return total / count;
    }

    void reverse()                          // Time Complexity : O(n) 
	{
        NodeSy* prev = NULL;
        NodeSy* current = head;
        while (current)
		{
            NodeSy* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }
    void Display()                      // Time Complexity : O(n) 
    {
    	NodeSy* current = head;
        while (current)
		{
        	cout << current->data << " ";
        	current = current->next;
    	}
	}



   
};


class DoublyLinkedList
{
	private:
    	NodeDy* head;
    	NodeDy* tail;

	public:
    	DoublyLinkedList() : head(NULL), tail(NULL) {}

    	void addFirst(int value)                 // Time Complexity: O(1)
		{
        	NodeDy* new_node = new NodeDy(value);
        	if (!head)
			{
            	head = tail = new_node;
        	}
			else
			{
            	new_node->next = head;
            	head->prev = new_node;
            	head = new_node;
        	}
    }

    void addLast(int value)                           // Time Complexity: O(1)
	{
        NodeDy* new_node = new NodeDy(value);
        if (!tail)
		{
            head = tail = new_node;
        }
		else
		{
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    int deleteFirst()                 // Time Complexity: O(1)
	{
        if (!head)
		{
            return -1;
        }
        int deleted_value = head->data;
        NodeDy* temp = head;
        head = head->next;
        if (head)
		{
            head->prev = NULL;
        }
		else
		{
            tail = NULL;
        }
        delete temp;
        return deleted_value;
    }

    int deleteLast()                          // Time Complexity: O(1)
	{
        if (!tail)
		{
            return -1;
        }
        int deleted_value = tail->data;
        NodeDy* temp = tail;
        tail = tail->prev;
        if (tail)
		{
            tail->next = NULL;
        }
		else
		{
            head = NULL;
        }
        delete temp;
        return deleted_value;
    }

    void insertAt(int value, int index)                  // Time Complexity: O(n)
	{
        if (index == 0)
		{
            addFirst(value);
        }
		else
		{
            NodeDy* new_node = new NodeDy(value);
            NodeDy* current = head;
            for (int i = 0; i < index - 1; ++i)
			{
                if (!current)
				{
                    cerr << "Index out of range" << endl;
                    return;
                }
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next)
			{
                current->next->prev = new_node;
            }
            current->next = new_node;
            if (!new_node->next)
			{
                tail = new_node;
            }
        }
    }

    bool search(int value)                        // Time Complexity: O(n)
	{
        NodeDy* current = head;
        while (current)
		{
            if (current->data == value)
			{
                return true;
            }
            current = current->next;
        }
        return false;
    }

     bool isPalindrome()                                   // Time Complexity: O(n)
	 {
         if (!head) {
            return false; // Empty list exception :)
        }

        NodeDy* slow = head;
        NodeDy* fast = head;
        NodeDy* prev = NULL;

        // Reverse the first half of the list
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;

            NodeDy* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // If the linked list has an odd number of elements, skip the middle element
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare the reversed first half with the second half
        while (slow != NULL) {
            if (slow->data != prev->data) {
            	cout<<"Is not a palindrome"<<endl;
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
    cout<<"Is a palindrome"<<endl;
        return true;
    }

    int countNodes()                         // Time Complexity: O(n)
	{
        int count = 0;
        NodeDy* current = head;
        while (current)
		{
            ++count;
            current = current->next;
        }
        return count;
    }

    int max()                               // Time Complexity: O(n)
	{
        if (!head)
		{
            return -1;
        }
        int max_value = head->data;
        NodeDy* current = head->next;
        while (current)
		{
            if (current->data > max_value)
			{
                max_value = current->data;
            }
            current = current->next;
        }
        return max_value;
    }

    double average()                   // Time Complexity: O(n)
	{
        if (!head)
		{
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        NodeDy* current = head;
        while (current)
		{
            total += current->data;
            ++count;
            current = current->next;
        }
        return total / count;
    }

    void reverse()
	{                                   // Time Complexity: O(n)
        NodeDy* temp = NULL;
        NodeDy* current = head;

        while (current != NULL)
		{
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL)
		{
            head = temp->prev;
        }
    }

    void Display()                              // Time Complexity: O(n)
	{
        NodeDy* current = head;
        while (current)
		{
            cout << current->data << " ";
            current = current->next;
        }
    }

    bool detectLoop()                        // Time Complexity: O(n)
	{
		NodeDy* slow = head;
        NodeDy* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
            	cout<<"Loop Detected :) ";
                return true; 
            }
        }
          cout<<"No loop Detected :(";
        return false; 
    }

   
};
class CircularSinglyLinkedList
{
	private:
	    NodeSy* head;

	public:
    	CircularSinglyLinkedList() : head(NULL) {}

    	void addFirst(int value)                          // Time Complexity: O(1)
		{
        	NodeSy* new_node = new NodeSy(value);
        	if (!head)
			{
            	head = new_node;
            	head->next = head;  // Circular reference
        	}
			else
			{
            	NodeSy* last_node = head;
            	while (last_node->next != head)
				{
                	last_node = last_node->next;
            	}
            	new_node->next = head;
            	head = new_node;
            	last_node->next = head;  
        	}
    	}

    void addLast(int value)                          // Time Complexity: O(n)
	{
        NodeSy* new_node = new NodeSy(value);
        if (!head)
		{
            head = new_node;
            head->next = head;  // Circular reference
        }
		else
		{
            NodeSy* last_node = head;
            while (last_node->next != head)
			{
                last_node = last_node->next;
            }
            last_node->next = new_node;
            new_node->next = head;  // Circular reference
        }
    }

    int deleteFirst()                    // Time Complexity: O(1)
	{
        if (!head)
		{
            return -1;
        }
        int deleted_value = head->data;
        if (head->next == head)
		{
            delete head;
            head = NULL;
        }
		else
		{
            NodeSy* temp = head;
            NodeSy* last_node = head;
            while (last_node->next != head)
			{
                last_node = last_node->next;
            }
            head = head->next;
            delete temp;
            last_node->next = head;  
        }
        return deleted_value;
    }

    int deleteLast()
	{
        if (!head)
		{
            return -1;
        }
        int deleted_value;
        if (head->next == head)
		{
            deleted_value = head->data;
            delete head;
            head = NULL;
        }
		else
		{
            NodeSy* last_node = head;
            while (last_node->next->next != head)
			{
                last_node = last_node->next;
            }
            deleted_value = last_node->next->data;
            NodeSy* temp = last_node->next;
            last_node->next = head;  
            delete temp;
        }
        return deleted_value;
    }

    void insertAt(int value, int index)                 // Time Complexity: O(n)
	{
        if (index == 0)
		{
            addFirst(value);
        }
		else
		{
            NodeSy* new_node = new NodeSy(value);
            NodeSy* current = head;
            for (int i = 0; i < index - 1; ++i)
			{
                if (!current)
				{
                    cerr << "Index out of range" << endl;
                    return;
                }
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    bool search(int value)                              // Time Complexity: O(n)
	{
        if (!head)
		{
            return false;
        }
        NodeSy* current = head;
        do
		{
            if (current->data == value)
			{
                return true;
            }
            current = current->next;
        }
		while (current != head);
        return false;
    }

    bool isPalindrome()
	{
		cout<<"Impossible / Not Possible"<<endl;
        return false;
    }

    int countNodes()                // Time Complexity: O(n)
	{
        if(!head)
		{
            return 0;
        }
        int count = 0;
        NodeSy* current = head;
        do
		{
            ++count;
            current = current->next;
        }
		while (current != head);
        return count;
    }

    int max()                                 // Time Complexity: O(n)
	{
        if (!head)
		{
            return -1;
        }
        int max_value = head->data;
        NodeSy* current = head->next;
        do
		{
            if (current->data > max_value)
			{
                max_value = current->data;
            }
            current = current->next;
        }
		while (current != head);
        return max_value;
    }

    double average()                 // Time Complexity: O(n)
	{
        if (!head)
		{
            return 0.0;
        }
        double total = 0.0;
        int count = 0;
        NodeSy* current = head;
        do
		{
            total += current->data;
            ++count;
            current = current->next;
        }
		while (current != head);
        return total / count;
    }

    void reverse()                              // Time Complexity: O(n)
	{
        if (!head || head->next == head)
		{
            return;
        }
        NodeSy* prev = NULL;
        NodeSy* current = head;
        NodeSy* next_node = NULL;

        do
		{
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
		while (current != head);

        head->next = prev;
        head = prev;
    }

    void Display()                        // Time Complexity: O(n)
	{
        if (!head)
		{
            return;
        }
        NodeSy* current = head;
        do
		{
            cout << current->data << " ";
            current = current->next;
        }
		while (current != head);
    }

   bool detectLoop()                       // Time Complexity: O(1)
		{
			if(head!=NULL && head->next!=NULL){
				cout<<"Circular Linklist is containing a loop"<<endl;
				return true;
			}
			else
	        cout<<"No loop found for now "<<endl;
	        return false;
    	}

   
};
class CircularDoublyLinkedList
{
	private:
    	NodeDy* head;

	public:
	    CircularDoublyLinkedList() : head(NULL) {}

	    void addFirst(int value)                        //Time Complexity: O(1)
		{
        	NodeDy* new_NodeDy = new NodeDy(value);
        	if (!head)
			{
            	head = new_NodeDy;
            	head->next = head;  
            	head->prev = head;  
        	}
			else
			{
	            NodeDy* last_NodeDy = head->prev;
    	        new_NodeDy->next = head;
        	    head->prev = new_NodeDy;
            	new_NodeDy->prev = last_NodeDy;
            	last_NodeDy->next = new_NodeDy;
            	head = new_NodeDy;
        	}
    	}

    	void addLast(int value)                              //Time Complexity: O(1)
		{
	        NodeDy* new_NodeDy = new NodeDy(value);
        	if (!head)
			{
            	head = new_NodeDy;
            	head->next = head;  
            	head->prev = head;  
        	}
			else
			{
	            NodeDy* last_NodeDy = head->prev;
    	        new_NodeDy->prev = last_NodeDy;
        	    last_NodeDy->next = new_NodeDy;
            	new_NodeDy->next = head;
            	head->prev = new_NodeDy;
        	}
	    }

    	int deleteFirst()                 //Time Complexity: O(1)
		{
	        if (!head)
			{
    	        return -1;
        	}
        	int deleted_value = head->data;
        	if (head->next == head)
			{
	            delete head;
    	        head = NULL;
        	}
			else
			{
	            NodeDy* temp = head;
    	        NodeDy* last_NodeDy = head->prev;
        	    head = head->next;
            	head->prev = last_NodeDy;
            	last_NodeDy->next = head;
            	delete temp;
        	}
        	return deleted_value;
    	}

    	int deleteLast()                    //Time Complexity: O(1)
		{
        	if (!head)
			{
            	return -1;
        	}
        	int deleted_value;
        	if (head->next == head)
			{
	            deleted_value = head->data;
    	        delete head;
        	    head = NULL;
        	}
			else
			{
            	NodeDy* last_NodeDy = head->prev;
            	deleted_value = last_NodeDy->data;
            	NodeDy* temp = last_NodeDy;
            	head->prev = last_NodeDy->prev;
            	last_NodeDy->prev->next = head;
            	delete temp;
        	}
        	cout<<"Operation Performed....Press Any Key "<<endl;
        	system("pause");
        	return deleted_value;
    	}

	    void insertAt(int value, int index)                            //Time Complexity: O(n)
		{
        	if (index == 0)
			{
            	addFirst(value);
        	}
			else
			{
            	NodeDy* new_NodeDy = new NodeDy(value);
            	NodeDy* current = head;
            	for (int i = 0; i < index - 1; ++i)
				{
	                if (!current)
					{
	                    cerr << "Index out of range" << endl;
    	                return;
        	        }
            	    current = current->next;
            	}
            	new_NodeDy->next = current->next;
            	new_NodeDy->prev = current;
            	current->next->prev = new_NodeDy;
            	current->next = new_NodeDy;
        	}
    	}

	    bool search(int value)                        //Time Complexity: O(n)
		{
        	if (!head)
			{
	            return false;
	        }
    	    NodeDy* current = head;
        	do
			{
            	if(current->data == value)
				{
                	return true;
            	}
            	current = current->next;
        	}
			while (current != head);
        	return false;
    	}

    	bool isPalindrome()                      //Time Complexity: no 
		{
			cout<<"Impossible";
        	return false;
    	}

    	int countNodeDys()                         //Time Complexity: O(n)
		{
        	if (!head)
			{
            	return 0;
        	}
        	int count = 0;
        	NodeDy* current = head;
        	do
			{
            	++count;
            	current = current->next;
        	}
			while(current != head);
        	return count;
    	}

	    int max()                          //Time Complexity: O(n)
		{
        	if (!head)
			{
            	return -1;
        	}
        	int max_value = head->data;
        	NodeDy* current = head->next;
        	do
			{
            	if (current->data > max_value)
				{
                	max_value = current->data;
            	}
            	current = current->next;
        	}
			while(current != head);
        	return max_value;
    	}

    	double average()                        //Time Complexity: O(n)
		{
        	if(!head)
			{
	            return 0.0;
    	    }
        	double total = 0.0;
        	int count = 0;
        	NodeDy* current = head;
        	do
			{
	            total += current->data;
    	        ++count;
        	    current = current->next;
        	}
			while(current != head);
        	return total / count;
    	}

    	void reverse()                              //Time Complexity: O(n)
		{
        	if (!head || head->next == head)
			{
	            return;
    	    }
        	NodeDy* temp = NULL;
        	NodeDy* current = head;

        	do
			{
            	temp = current->prev;
            	current->prev = current->next;
            	current->next = temp;
            	current = current->prev;
        	}
			while(current != head);

        	head->next = temp;
        	head = temp->prev;
    	}

    	void Display()                       //Time Complexity: O(n)
		{
        	if (!head)
			{
            	return;
        	}
        	NodeDy* current = head;
        	do
			{
	            cout << current->data << " ";
	            current = current->next;
    	    }
			while(current != head);
    	}

    	bool detectLoop()                   //Time Complexity: O(1)
		{
			if(head!=NULL && head->next!=NULL){
				cout<<"Circular Linklist is containing a loop"<<endl;
				return true;
			}
			else
	        cout<<"No loop found for now "<<endl;
	        return false;
    	}

    
};
int main()
{
    string choice;
    
    s:  
        cout<<"                                       _________________________________              "<<endl;   
    	cout<<"                                      |                                 |              "<<endl;
    	cout<<"                                      |    Initiating The LinkedList    |              "<<endl;
    	cout<<"                                      |_________________________________|              "<<endl<<endl<<endl;
    	
    	cout << "                                       Choose the type of linked list:" << endl<<endl<<endl;
    	cout << "                       1. Singly Linked List                         " ;
    	cout << "2. Doubly Linked List" << endl<<endl<<endl;
    	cin >> choice;

    	if (choice != "1" && choice != "2")
		{
        	cout << "Invalid choice. Try Again. \a" << endl;
        	system("pause");
        	system("cls");
        	goto s;
    	}

    	string circularChoice;
    	r:
    		cout << "                                   Please Choose The Type Of Linked List:" << endl<<endl;
    		cout << "                    1. Simple Linked List                           " ;
    		cout << "2. Circular Linked List" << endl<<endl;
    		cin >> circularChoice;

    		if (circularChoice != "1" && circularChoice != "2")
			{
        		cout << "Invalid choice. Try Again.\a" << endl;
        		system("pause");
        		system("cls");
        		goto r;
    		}

		    if (choice == "1")
			{
        		if (circularChoice == "1")
				{
        			system("cls");
            		// Simple Singly Linked List
            		SinglyLinkedList sll;
            		int value;
					string operation;

		            do
					{
            			l:
            				cout<<"                                       Simple Singly Linked List     "<<endl<<endl;
                			cout << "		                          Choose an operation:" << endl<<endl;
                			cout << "\t\t\t\t\t1. Add First value to the list" << endl;
                			cout << "\t\t\t\t\t2. Add Last value to the list" << endl;
                			cout << "\t\t\t\t\t3. Delete first value" << endl;
                			cout << "\t\t\t\t\t4. Delete last value" << endl;
                			cout << "\t\t\t\t\t5. Insert value at an index" << endl;
                			cout << "\t\t\t\t\t6. Search for a value" << endl;
                			cout << "\t\t\t\t\t7. Count Nodes" << endl;
                			cout << "\t\t\t\t\t8. Find maximum value" << endl;
                			cout << "\t\t\t\t\t9. Calculate average" << endl;
                			cout << "\t\t\t\t\t10. Reverse the list" << endl;
                			cout << "\t\t\t\t\t11. Display the list" << endl;
                			
                			cout << "\t\t\t\t\t12. Find Palindrome"<<endl<<endl;
                			cout << "\t\t\t\t\t    0. Exit" << endl;
                			cin >> operation;

                			if (operation == "1")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			sll.addFirst(value);
                    			system("cls");
                    			goto l;
                			}
                			if (operation == "2")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			sll.addLast(value);
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "3")
							{
                    			sll.deleteFirst();
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "4")
							{
                    			sll.deleteLast();
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "5")
							{
                    			int index;
                    			cout << "Enter index: ";
                    			cin >> index;
                    			cout << "Enter value to insert: ";
                    			cin >> value;
                    			sll.insertAt(value, index);
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "6")
							{
                    			cout << "Enter value to search: ";
                    			cin >> value;
                    			if (sll.search(value))
								{
                        			cout << "Value found in the list." << endl;
                    			}
								else
								{
                        			cout << "Value not found in the list." << endl;
                    			}
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "7")
							{
                    			cout << "Number of Nodes: " << sll.countNodes() << endl;
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "8")
							{
                    			cout << "Maximum value: " << sll.max() << endl;
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "9")
							{
                    			cout << "Average: " << sll.average() << endl;
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "10")
							{
                    			sll.reverse();
                    			cout << "List reversed." << endl;
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
							else if (operation == "11")
							{
                    			cout << "List: ";
                    			sll.Display();
                    			cout << endl;
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
                		
                				else if (operation == "12")
							{
                    			sll.isPalindrome();
                    			cout << endl;
                    			system("pause");
                    			system("cls");
                    			goto s;                    
                			}
                			
							else if (operation == "0")
							{
                    			// will exit the loop
                			}
							else
							{
                    			cout << "Invalid choice.\a" << endl;
                    			system("pause");
                    			system("cls");
                    			goto l;
                			}
                			
                			
            		}
					while (operation != "0");
        		}
				else
				{
        			system("cls");
            		// Circular Singly Linked List
            		CircularSinglyLinkedList csll;
            		int value;
					string operation;

		            do
					{
						L:
							cout<<"                                     Circular Singly Linked List        "<<endl<<endl;
                			cout << "		                         Choose an operation:" << endl<<endl;
                			cout << "\t\t\t\t\t1. Add First value to the list" << endl;
                			cout << "\t\t\t\t\t2. Add Last value to the list" << endl;
                			cout << "\t\t\t\t\t3. Delete first value" << endl;
                			cout << "\t\t\t\t\t4. Delete last value" << endl;
                			cout << "\t\t\t\t\t5. Insert value at an index" << endl;
                			cout << "\t\t\t\t\t6. Search for a value" << endl;
                			cout << "\t\t\t\t\t7. Count Nodes" << endl;
                			cout << "\t\t\t\t\t8. Find maximum value" << endl;
                			cout << "\t\t\t\t\t9. Calculate average" << endl;
                			cout << "\t\t\t\t\t10. Reverse the list" << endl;
                			cout << "\t\t\t\t\t11. Display the list" << endl;
                			cout << "\t\t\t\t\t12. Detect Loop" << endl<<endl;
                			cout << "\t\t\t\t\t    0. Exit" << endl;
                			cin >> operation;

                			if (operation == "1")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			csll.addFirst(value);
                    			system("cls");
                    			goto L;
                			}
                			if (operation == "2")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			csll.addLast(value);
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "3")
							{
                    			csll.deleteFirst();
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "4")
							{
                    			csll.deleteLast();
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "5")
							{
                    			int index;
                    			cout << "Enter index: ";
                    			cin >> index;
                    			cout << "Enter value to insert: ";
                    			cin >> value;
                    			csll.insertAt(value, index);
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "6")
							{
                    			cout << "Enter value to search: ";
                    			cin >> value;
                    			if (csll.search(value))
								{
                        			cout << "Value found in the list." << endl;
                    			}
								else
								{
                        			cout << "Value not found in the list." << endl;
                    			}
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "7")
							{
                    			cout << "Number of Nodes: " << csll.countNodes() << endl;
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "8")
							{
                    			cout << "Maximum value: " << csll.max() << endl;
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "9")
							{
                    			cout << "Average: " << csll.average() << endl;
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "10")
							{
                    			csll.reverse();
                    			cout << "List reversed." << endl;
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
							else if (operation == "11")
							{
                    			cout << "List: ";
                    			csll.Display();
                    			cout<<endl;
                    			system("pause");
                    			system("cls");
                    			goto L;
                    			cout << endl;
                			}
							else if (operation == "12")
							{
                    			cout << "List: ";
                    			csll.detectLoop();
                    			cout<<endl;
                    			system("pause");
                    			system("cls");
                    			goto L; 
                			}
							else if (operation == "0")
							{
                    			//  exit the loop
                			}
							else
							{
                    			cout << "Invalid choice.\a" << endl;
                    			system("pause");
                    			system("cls");
                    			goto L;
                			}
            		}
					while (operation != "0");
        		}
    		}
			else
			{
        		if (circularChoice == "1")
				{
	        		system("cls");
		            // Simple Doubly Linked List
        		    DoublyLinkedList dll;
            		sd:
            			int value;
						string operation;

            			do
						{
                                        system("cls");							
            				cout<<"                                          Simple Doubly Linked List"<<endl<<endl;
                			cout << "		                           Choose an operation:" << endl<<endl;
                			cout << "\t\t\t\t\t1. Add First value to the list" << endl;
                			cout << "\t\t\t\t\t2. Add Last value to the list" << endl;
                			cout << "\t\t\t\t\t3. Delete first value" << endl;
                			cout << "\t\t\t\t\t4. Delete last value" << endl;
                			cout << "\t\t\t\t\t5. Insert value at an index" << endl;
                			cout << "\t\t\t\t\t6. Search for a value" << endl;
                			cout << "\t\t\t\t\t7. Count Nodes" << endl;
                			cout << "\t\t\t\t\t8. Find maximum value" << endl;
                			cout << "\t\t\t\t\t9. Calculate average" << endl;
                			cout << "\t\t\t\t\t10. Reverse the list" << endl;
                			cout << "\t\t\t\t\t11. Display the list" << endl;
                			cout << "\t\t\t\t\t12. Detect Loop" << endl;
                			cout << "\t\t\t\t\t13. Check Palindrome" << endl <<endl;
                			cout << "\t\t\t\t\t   0. Exit" << endl;
                			cin >> operation;

                			if (operation == "1")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			dll.addFirst(value);
                    			system("cls");
                    			goto sd;
                			}
                			if (operation == "2")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			dll.addLast(value);
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "3")
							{
                    			dll.deleteFirst();
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "4")
							{
                    			dll.deleteLast();
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "5")
							{
                    			int index;
                    			cout << "Enter index: ";
                    			cin >> index;
                    			cout << "Enter value to insert: ";
                    			cin >> value;
                    			dll.insertAt(value, index);
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "6")
							{
                    			cout << "Enter value to search: ";
                    			cin >> value;
                    			if (dll.search(value))
								{
                        			cout << "Value found in the list." << endl;
                    			}
								else
								{
                        			cout << "Value not found in the list." << endl;
                    			}
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "7")
							{
                    			cout << "Number of Nodes: " << dll.countNodes() << endl;
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "8")
							{
                    			cout << "Maximum value: " << dll.max() << endl;
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "9")
							{
                    			cout << "Average: " << dll.average() << endl;
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "10")
							{
                    			dll.reverse();
                    			cout << "List reversed." << endl;
                    			system("pause");
                    			system("cls");
                    			goto sd;	
                			}
							else if (operation == "11")
							{
                    			cout << "List: ";
                    			dll.Display();
                    			cout << endl;
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
							else if (operation == "12")
							{
                    			cout << "List: ";
                    			dll.detectLoop();
                    			cout<<endl;
                    			system("pause");
                    			system("cls");
                    			goto sd; 
                			}
                			else if (operation == "13")
							{
//                    			cout << "List: ";
                    			dll.isPalindrome();
                    			cout<<endl;
                    			system("pause");
                    			system("cls");
                    			goto s; 
                			}
							else if (operation == "0")
							{
                    			 //exit 
                			}
							else
							{
                    			cout << "Invalid choice.\a" << endl;
                    			system("pause");
                    			system("cls");
                    			goto sd;
                			}
            		}
					while (operation != "0");
					
        		}
				else
				{
            		// Circular Doubly Linked List
		            CircularDoublyLinkedList cdll;
		            cd:
			            int value;
						string operation;
            			do
						{                          system("cls");
            				cout<<"                               \t\tCircular Doubly Linked List"<<endl<<endl;
			                cout << "                            \t\t  Choose an operation:" << endl<<endl;
			                cout << "\t\t\t\t\t1. Add First value to the list" << endl;
			                cout << "\t\t\t\t\t2. Add Last value to the list" << endl;
			                cout << "\t\t\t\t\t3. Delete first value" << endl;
			                cout << "\t\t\t\t\t4. Delete last value" << endl;
			                cout << "\t\t\t\t\t5. Insert value at an index" << endl;
			                cout << "\t\t\t\t\t6. Search for a value" << endl;
			                cout << "\t\t\t\t\t7. Count NodeDys" << endl;
			                cout << "\t\t\t\t\t8. Find maximum value" << endl;
			                cout << "\t\t\t\t\t9. Calculate average" << endl;
			                cout << "\t\t\t\t\t10. Reverse the list" << endl;
			                cout << "\t\t\t\t\t11. Display the list" << endl;
			                cout << "\t\t\t\t\t12. Detect Loop" << endl;
			                cout << "\t\t\t\t\t   0. Exit" << endl;
			                cin >> operation;
                			if (operation == "1")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			cdll.addFirst(value);
                    			system("cls");
                    			goto cd; 
                			}
                			if (operation == "2")
							{
                    			cout << "Enter value to add: ";
                    			cin >> value;
                    			cdll.addLast(value);
                    			system("cls");
                    			goto cd; 
                			}
							else if (operation == "3")
							{
                    			cdll.deleteFirst();
                    			system("cls");
                    			goto cd; 
                			}
							else if (operation == "4")
							{
                    			cdll.deleteLast();
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "5")
							{
                    			int index;
                    			cout << "Enter index: ";
                    			cin >> index;
                    			cout << "Enter value to insert: ";
                    			cin >> value;
                    			cdll.insertAt(value, index);
                    			system("pause");
                    			system("cls");
                    			goto cd; 
                			}
							else if (operation == "6")
							{
                    			cout << "Enter value to search: ";
                    			cin >> value;
                    			if (cdll.search(value))
								{
	                        		cout << "Value found in the list." << endl;
			                    }
								else
								{
                        			cout << "Value not found in the list." << endl;
                    			}
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "7")
							{
                    			cout << "Number of NodeDys: " << cdll.countNodeDys() << endl;
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "8")
							{
	                    		cout << "Maximum value: " << cdll.max() << endl;
		                    	system("pause");
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "9")
							{
                    			cout << "Average: " << cdll.average() << endl;
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "10")
							{
                    			cdll.reverse();
                    			cout << "List reversed." << endl;
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "11")
							{
                    			cout << "List: ";
                    			cdll.Display();
                    			cout << endl;
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
							else if (operation == "12")
							{
                    			cout << "List: ";
                    			cdll.detectLoop();
                    			cout<<endl;
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
//                			else if (operation == "13")
//							{
//                    			cout << "List: ";
//                    			cdll.isPalindrome();
//                    			cout<<endl;
//                    			system("pause");
//                    			system("cls");
//                    			goto cd;
//                			}
							else if (operation == "0")
							{
                    			// exitinng
                			}
							else
							{
                    			cout << "Invalid choice. \a" << endl;
                    			system("pause");
                    			system("cls");
                    			goto cd;
                			}
            		} while (operation != "0");
        		}
    }

    return 0;
}
