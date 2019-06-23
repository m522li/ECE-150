//
//  main.cpp
//  project3
//
//  Created by Mervin Li on 2018-11-22.
//  Copyright © 2018 Mervin Li. All rights reserved.
//

#include <iostream>
#include "Message.h"
#ifndef MARMOSET_TESTING
int main()
{
    int command{0};
    std::string str{};
    Message mes;
    unsigned int num{0};
    while (command != -2)  //program ends when -2 entered
    {
        std::cout<<"enter a command ";
        std::cin>>command;
        if (command>=0)
        {
            num=command;
            std::cin>>str;
            mes.insert(command, str);       //calls insert to create node and put in right place
        }
        if (command==-1)
        {
            mes.print_message();          //print message if command is -1
        }
    }
    //mes.~Message();
                             //add the deallocation here
    return 0;
}

#endif
Node::Node( unsigned int id, std::string frag )
{
    identifier=id;        //creates node with inputed parameters
    fragment=frag;
    p_next=nullptr;
}

std::string Node::get_fragment()
{
    return fragment;
}

Node *Node::get_next()
{
    return p_next;
}


Message::Message()
{
    head=nullptr;
}

Message::~Message()
{
    
    Node *p{head};
    while ( p != nullptr )
    {
        Node *q{p};
        p = p->p_next;
        delete q;
    }
    head=nullptr;
}


void Message::insert(unsigned int id, std::string fragment)
{
    Node *new_node{};         //creates new node
    if (head==nullptr)
    {
        Node *new_node{new Node{id, fragment}};
        head=new_node;           //sets head to point to new node if its the first one created
        
    }
    else if (head->identifier!=0 && id<head->identifier) //place new node at the head if ID is less than previous head
    {
        new_node=new Node{id, fragment};
        new_node->p_next=head;
        head=new_node;
    }
    else         //otherwise place in proper order after head
    {
        Node *temp{};
        temp=head;
        int spot{0};
        int spot2{0};
        bool end{false};
        spot=temp->identifier;
        if (temp->p_next!=nullptr)   //if there is a next node
        {
            spot2=temp->p_next->identifier;  //sets spot to the id of the next node
            if(spot<id && id<spot2)       //if the new node id is inbetween the previous and next nodes
            {
                end=true;
            }
        }
        else                // also sets end if there are no next nodes.
        {
            end=true;
        }
        new_node= new Node{id, fragment};
     
        while (end!=true)  //loops until you either find the right spot or it reaches end of the linked list
        {
            if (temp->p_next!=nullptr)
            {
                temp=temp->p_next;
                spot=temp->identifier;      //gets spot of node before the one that should be added
                if (temp->p_next!=nullptr)
                {
                    spot2=temp->p_next->identifier;      //gets the spot of the node after the one added
                    if(spot<id && id<spot2)  //ends if new node is in between the two
                    {
                        end=true;
                    }
                }
            }
            else      //ends if the end of list is reached
            {
                end=true;
            }
        }
        new_node->p_next=temp->p_next;        //adds the new node in the spot and points it to the one after it
        temp->p_next=new_node;      //sets the previous node to point to the new one
        
    }
}

void Message::print_message()
{
    if (head==nullptr)
    {
        std::cout<<"???"<<std::endl;
    }
    else if (head->fragment=="EOT" && head->identifier==0)
    {
        std::cout<<"\n";    //prints nothing if empty node
    }
    else
    {
        int spot{0};
        int spot2{0};
        int a{0};
        spot=head->identifier;
        Node *p{head};
        Node *q{head};
        
        while (p!=nullptr)  //gets the ID of the last element
        {
            spot=p->identifier;
            p=p->p_next;
        }
        while (q!=nullptr)  //repeats until end of list
        {
            spot2=q->identifier;    //gets spot of first element
            while (a<spot2)
            {
                std::cout<<"... ";     //prints out ... until first element is reached
                a++;
            }
            a++;
            if (q->fragment!="EOT")
            {
                std::cout<<q->fragment<<" ";
            }
            q=q->p_next;
        }
        while (a<spot2)  //you might not need this while here...
        {
            std::cout<<"... ";
            a++;
        }
        p=head;
        while (p->p_next!=nullptr)
        {
            p=p->p_next;               //goes to last element
        }
        if (p->fragment!="EOT")
        {
            std::cout<<"???";       //if no EOT received prints ???
        }
        else
        {
            while (a<spot2)       //you only need this once you get the EOT
            {
                std::cout<<"... ";    //fills with ... until the EOT element
                a++;
            }
        }
        std::cout<<std::endl;
    }
}


