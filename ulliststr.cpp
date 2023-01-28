#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
	
	//is dat list empty
	if(empty()){
		
		head_ = new Item;
		head_->val[9] = val;

		head_->first = 9;
		head_->last = 10;
		size_++;

		tail_ = head_;

	}else{

		//room at the end?
		if(tail_->last == 10){
			//nope
			Item* ptr = new Item;

			tail_->next = ptr;
			ptr->prev = tail_;
			tail_ = ptr;

			tail_->first = 0;
			tail_->val[tail_->first] = val;
			tail_->last = 1;

			size_++;

			return;

		}else{
			//yep

			tail_->val[tail_->last] = val;
			size_++;
			tail_->last++;

			return;
		}
	}
}

void ULListStr::pop_back(){
  
  if(empty()){
    //the list is empty, nothing to pop
    return;
  }else{
    //the list still has data

		//checking last node
		if(tail_->last != 0){
			//as long as its not empty just pop the last thing
			tail_->last--;
			size_--;

			//did that make the node empty?
			if(tail_->last == 0 && tail_->first == 0){
				//if it is get rid of it
				
				if(head_ == tail_){
					delete head_;
					head_ = NULL;
					tail_ = NULL;
					return;

				}else{
					tail_ = tail_->prev;

					delete tail_->next;

					//bye felicia 
					return;
				}
			}
		}
  }

}

void ULListStr::push_front(const std::string& val){
	if(empty()){
		head_ = new Item;
		head_->val[9] = val;

		head_->last = 10;
		head_->first = 9;
		size_++;

		tail_ = head_;		
	}else{
		if(head_->first == 0){
			Item* ptr = new Item;
			ptr->val[9] = val;
			ptr->last = 10;
			ptr->first = 9;

			ptr->next = head_;
			head_->prev = ptr;
			head_ = ptr;

			size_++;
		}else{
			head_->first--;
			head_->val[head_->first] = val;

			size_++;
		}
	}
}

void ULListStr::pop_front(){
	if(empty()){
		return;
	}else{
		head_->first++;
		size_--;

		if(head_->first == head_->last){
			if(head_->next == NULL){
				delete head_;
				head_ = NULL;
				tail_ = NULL;
			}else{
				head_ = head_->next;
				delete head_->prev;
			}
		}
	}
}

std::string const & ULListStr::back() const{
	return (tail_->val[tail_->last - 1]);
}

std::string const & ULListStr::front() const{
	 return (head_->val[head_->first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
	if(empty()){

		return NULL;
		
	}else{

		if((int)loc >= (int)size_){
			return NULL;
		}else{
			int search = loc;
			Item* walker = head_;

			while(walker->next != NULL && (search - ((int)walker->last - (int)walker->first)) > 0){
				search = search - ((int)walker->last - (int)walker->first);
				walker = walker->next;
			}	

			if((int)walker->first + search > 9){
				search = search - ((int)walker->last - (int)walker->first);
				walker = walker->next;

				return &walker->val[(int)walker->first + search];

			}else{

				return &walker->val[(int)walker->first + search];
			}
		}
	}
}