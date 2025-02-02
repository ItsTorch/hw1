#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

void ULListStr::push_back(const std::string& val) {
  // if current tail is full, create new item, or if
  // no tail exists, create new item
  if ((tail_ == NULL) || (tail_->last == ARRSIZE)) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 0;
    newItem->prev = tail_;
    newItem->next = NULL;

    if (tail_) {
      tail_->next = newItem;
    }
    tail_ = newItem;
    
    if (!head_) {
    head_ = tail_;
    }
  }
  // insert value at the end of tail
  tail_->val[tail_->last++] = val;
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  // if no room before the first item, or no head, create
  //new item
  if((head_ == NULL) || (head_->first == 0)) {
    Item* newItem = new Item();
    newItem->first = ARRSIZE;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    newItem->prev = NULL;

    if (head_) {
      head_->prev = newItem;
    }
    head_ = newItem;

    if(!tail_) {
      tail_ = head_;
    }
  }
  // insert value at beginning of head
  head_->val[--head_->first] = val;
  size_++;
}

void ULListStr::pop_back() {
  // does nothing to empty string
  if (empty()) {
    return;
  }

  // removes last element, decrease size
  tail_->last--;
  size_--;

  // if tail is empty, remove item there
  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_) {
      tail_->next = NULL;
    }
    else {
      head_ = NULL;
    }
    delete temp;
  }
}

void ULListStr::pop_front() {
  // does nothing to empty string
  if (empty()) {
    return;
  }
  
  // removes first element and decrease size
  head_->first++;
  size_--;

  // if head is empty, remove it
  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    if (head_) {
      head_->prev = NULL;
    }
    else {
      tail_ = NULL;
    }
    delete temp;
  }
}

std::string const& ULListStr::back() const {
  // checks if list is empty
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  // returns reference to last element
  return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const {
  // checks if list is empty
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  // returns reference to first element
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // if searched location is outside of string, return nothing
  if (loc >= size_) {
    return NULL;
  }

  // create a pointer at the head
  Item* current = head_;

  // goes through the list
  while (current) {
    size_t counter = current->last - current->first;
    if (loc < counter) {
      return &current->val[current->first + loc];
    }
    loc -= counter;
    current = current->next;
  }
  
  return NULL;
}

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
