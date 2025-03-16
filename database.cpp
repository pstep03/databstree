#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "states.h"

struct Person{
    std::string name;
    std::string age;
    std::string state;
};

struct Node{
    Person person;
    Node *left;
    Node *right;
};

class BSTree{
    private:
    Node *root;
    void insert_h(Person, Node *);
    void findName_h(Node *, std::string, bool& exist);
    void findAge_h(Node *, std::string, bool& exist); //Booleans used to check if given name, age, and state exist within the database
    void findState_h(Node *, std::string, bool& exist);
    void inorder_h(Node*);
    
    public:
    void insert(Person);
    void generateBST(std::vector<Person>);
    void findName(std::string);
    void findAge(std::string);
    void findState(std::string);
    void inorderTraverse();
    bool isEmpty(); //Boolean to check if tree is empty when displaying database

    BSTree(){
            root = NULL;
        }
        ~BSTree(){};
};

void BSTree::insert_h(Person person, Node *curr){ //Inserting new person node into the database
    if(person.name <= curr->person.name){
        if(curr->left != NULL)
            insert_h(person, curr);
        else{
            curr->left = new Node;
            curr->left->person = person;
            curr->left->left = NULL;
            curr->left->right = NULL;
        }
    }

    else{
        if(curr->right != NULL)
            insert_h(person, curr->right);
        else{
            curr->right = new Node;
            curr->right->person = person;
            curr->right->left = NULL;
            curr->right->right = NULL;
        }
    }
}

void BSTree::insert(Person person){
    if(root != NULL)
        insert_h(person,root);
    else{
        root = new Node;
        root->person = person;
        root->left = NULL;
        root->right = NULL;
    }
}

void BSTree::generateBST(std::vector<Person> v){ //Creating database (binary search tree)
    for(auto x = v.begin(); x != v.end(); ++x)
        insert(*x);
}

void BSTree::findName_h(Node* curr, std::string name, bool& exist){
    if (curr != NULL){
        if (curr->person.name == name){
            std::cout << "Name: " << curr->person.name  << ", Age: " << curr->person.age << ", State: " << curr->person.state << std::endl;
            exist = true;
        }
        findName_h(curr->left, name, exist);
        findName_h(curr->right, name, exist); //Continue searching throughout the database to find all persons that match the given name
    }
}

void BSTree::findName(std::string name){
    std::cout << "Person(s) with the name: " << name << std::endl;
    bool exist = false;
    findName_h(root, name, exist);
    if(!exist){
        std::cout << "No matches found.\n"; //Using boolean to return an error message if the name does not exist within the database
    }
}

void BSTree::findAge_h(Node* curr, std::string age, bool& exist){
    if (curr != NULL){
        if (curr->person.age == age){
            std::cout << "Name: " << curr->person.name  << ", Age: " << curr->person.age << ", State: " << curr->person.state << std::endl;
            exist = true;
        }
        findAge_h(curr->left, age, exist);
        findAge_h(curr->right, age, exist); //Continue searching throughout the database to find all person(s) that match the given age
    }
}

void BSTree::findAge(std::string age){
    std::cout << "Person(s) with the age: " << age << std::endl;
    bool exist = false;
    findAge_h(root, age, exist);
    if(!exist){ 
        std::cout << "No matches found.\n"; //Using boolean to return an error message if the age does not exist within the database
    }
}

void BSTree::findState_h(Node* curr, std::string state, bool& exist){
    if (curr != NULL){
        if (curr->person.state == state){
            std::cout << "Name: " << curr->person.name << ", Age: " << curr->person.age << ", state: " << curr->person.state << std::endl;
            exist = true;
        }
        findState_h(curr->left, state, exist);
        findState_h(curr->right, state, exist); //Continue searching throughout the database to find all persons that match the given state
    }
}

void BSTree::findState(std::string state){
    std::cout << "Person(s) living in: " << state << std::endl;
    bool exist = false;
    findState_h(root, state, exist);
    if(!exist){
        std::cout << "No matches found.\n"; //Using boolean to return an error message if the state does not exist within the database
    }
}


void BSTree::inorder_h(Node* node){
    if (node != NULL){
        inorder_h(node->left);
        std::cout << "Name: " << node->person.name << ", Age: " << node->person.age << ", State: " << node->person.state << std::endl;
        inorder_h(node->right);
    }
}

void BSTree::inorderTraverse(){
    inorder_h(root);
}

bool BSTree::isEmpty(){ //Checking to see if the database is empty (case 5 in main function)
    return root == NULL;
}

void addPerson(BSTree& database){ //Allowing user to add new person to database
    std::string name;
    std::string age;
    std::string state;

    std::cout << "Enter the person name: ";
    std::getline(std::cin, name);

    std::cout << "Enter the age: ";
    std::getline(std::cin, age);

    while(true){
        std::cout << "Enter the state (do not abbreviate): ";
        std::getline(std::cin, state);
        
        if(checkState::stateExists(state)){
            break;
        }
        else{
            std::cout << "Please enter a valid state.\n";
        }
    
    }
    Person newPerson{name, age, state};
    database.insert(newPerson);

    std::cout << "Adding person: "<< name <<", " << age <<", " << state << "\n";
    std::cout << "Person added successfully.\n";
}

int main(){
    BSTree database;
    int choice;

    do{ //Everything below handles the functionality of the database management system
        std::cout << "Database Management System:\n";
        std::cout << "1. Add a Person\n";
        std::cout << "2. Search by Name\n";
        std::cout << "3. Search by Age\n";
        std::cout << "4. Search by State of Residence\n";
        std::cout << "5. Display Person(s)\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice){
            case 1:
                addPerson(database);
                break;

            case 2:{
                std::string name;
                std::cout << "Search by name: ";
                std::getline(std::cin, name);
                database.findName(name);
                break;
            }

            case 3:{
                std::string age;
                std::cout << "Search by age: ";
                std::getline(std::cin, age);
                database.findAge(age);
                break;
            }

            case 4:{
                std::string state;
                std::cout << "Search by state: ";
                std::getline(std::cin, state);
                database.findState(state);
                break;
            }

            case 5:{
                if(database.isEmpty()){
                    std::cout << "No matches found.\n"; //Returning an error if the database is empty
                }
                else{
                    std::cout << "All Persons in Database:\n";
                    database.inorderTraverse();
                }
                
                break;
            }

            case 6:{
                std::cout << "Exiting database...\n";
                break;
            }

            default:
                std::cout << "Invalid input.\n";
        }
    }
    while (choice != 6); //Rejecting any inputs other than integers 1-6

    return 0;
}