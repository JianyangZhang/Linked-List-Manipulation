/*  Name: Jianyang Zhang
 *  loginid: jianyanz
 *  CS 455 Spring 2016, Extra Credit assignment
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>
#include <cassert>
#include "ecListFuncs.h"

using namespace std;

bool isInOrder(ListType list) {
  if(list != NULL){
  	while(list->next != NULL){
  		if(list->next->data >= list->data){
  			list = list->next;
		}else{
			return false;
		}
	  }
  } 
  return true;
}

void insertInOrder(ListType & list, Node *itemP) {
	//checks the preconditions
	assert(isInOrder(list)); 
	assert(itemP->next == NULL); 
	assert(itemP != NULL); 
	
	//empty list
	if(list == NULL){ 
		list = itemP;
		return;
	}

	//at least one data in the list
	if(list->data >= itemP->data){ //itemP's data is the smallest
		itemP->next = list;
		list = itemP;
		return;
	}
	
	Node * iterator = list; //itemP's data is neither the smallest nor the largest
	while(iterator->next !=NULL){ 
  		if(iterator->next->data >= itemP->data){ 
  			itemP->next = iterator->next;
  			iterator->next = itemP;
  			return;
		}		
		iterator = iterator->next;		 	  	
	}	
	
	iterator->next = itemP; //itemP's data is the largest
}

void insertionSort(ListType &list) {
	// if list size <= 1
	if(list == NULL || list->next == NULL){ 
		return;
	}
	
	// list has at least two data
	Node * listHead = list;
	Node * previous = NULL;
	while(!isInOrder(list)){
		while(list->next != NULL){
			if(list->data > list->next->data){
				if(list == listHead){ // if the listHead needs to be relinked
					listHead = list->next; // set the head
					//swap:
					Node * temp = list->next; 				
					list->next = temp->next;					
					temp->next = list;
					
				}else{ // if the listHead needs not to be relinked
					//swap:
					Node * temp = list->next; 
					list->next = temp->next;
					temp->next = list;
					previous->next = temp;
				}
			}	
			
			if(list->next != NULL){	
				previous = list;		
				list = list->next;	
			}else{
				break;
			}
		}
		list = listHead;
	}	
}

void splitEvenOdd(ListType &list, ListType &a, ListType &b){
	//clean up sub-list a and b
	a = NULL;
	b = NULL;
	
	// list is empty
	if(list == NULL){
		return;
	}
	
	//list is not empty
	Node * aHead = NULL; // the head node of a
	Node * bHead = NULL; // the head node of b
	while(list != NULL){
		
		// give this node to "a"
		if(aHead == NULL){ 
			aHead = list;
			a = list;			
		}else{			
			a->next = list;
			a = a->next;
		}	
		
		// give the next node(if it's not NULL) to "b"
		list = list->next;
		a->next = NULL;				
		if(list != NULL){
			if(bHead == NULL){
				bHead = list;
				b = list; 							
			}else{				
				b->next = list;
				b = b->next;							
			}		
			list = list->next;	
			b->next = NULL;
		}
	}
	
	a = aHead; 
	b = bHead;
}






