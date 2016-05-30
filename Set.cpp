// Bag.cpp Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos
/** @file Set.cpp| 
   Bag.cpp adapted to Set.cpp by Andres Quinones */

#include "Set.h"
#include <cstddef>

template<class ItemType>
Set<ItemType>::Set() : item_count_(0), max_items_(kDefaultSetSize_)
{
}  // end default constructor



template<class ItemType>
int Set<ItemType>::GetCurrentSize() const
{
  return item_count_;
}  // end getCurrentSize

template<class ItemType>
bool Set<ItemType>::IsEmpty() const
{
  return item_count_ == 0;
}  // end isEmpty


template<class ItemType>
bool Set<ItemType>::Remove(const ItemType& an_entry)
{
  int located_index = GetIndexOf(an_entry);
  bool can_remove_item = !IsEmpty() && (located_index > -1);
  if (can_remove_item)
    {
      item_count_--;
      items_[located_index] = items_[item_count_];
    }  // end if
  return can_remove_item;
}  // end remove

template<class ItemType>
void Set<ItemType>::Clear()
{
  item_count_ = 0;
}  // end clear

template<class ItemType>
bool Set<ItemType>::Contains(const ItemType& an_entry) const
{
  return GetIndexOf(an_entry) > -1;
}  // end contains

template<class ItemType>
bool Set<ItemType>::Add(const ItemType& new_entry)
{
  bool has_room_to_add = item_count_ < max_items_;

  if(item_count_ !=0)
   if (Contains(new_entry))
    return 0;

  if (has_room_to_add)
    {
      items_[item_count_] = new_entry;
      item_count_++;
    }  // end if
  return has_room_to_add;
}  // end add

template<class ItemType>
Set<ItemType>::Set(const ItemType &an_item) : item_count_(1), max_items_(kDefaultSetSize_)
{
  Add(an_item);
}  // end overloaded constructor

template<class ItemType>
vector<ItemType> Set<ItemType>::ToVector() const
{
  vector<ItemType> Set_contents;
  for (int i = 0; i < item_count_; i++)
    Set_contents.push_back(items_[i]);
  return Set_contents;
}  // end toVector

template<class ItemType>
int Set<ItemType>::GetIndexOf(const ItemType& target) const
{
  bool found = false;
  int result = -1;
  int search_index = 0;
  // if the Set is empty, item_count is zero, so loop is skipped
  while (!found && (search_index < item_count_))
    {
      if (items_[search_index] == target)
	{
	  found = true;
	  result = search_index;
	} 
      else
	{
	  search_index++;
	}  // end if
    }  // end while
  return result;
}  // end getIndexOf

template <class ItemType>
void DisplaySet(const Set<ItemType> &a_set) 
{
  vector<ItemType> theSet = a_set.ToVector();
  for(int i=0;i<theSet.size();i++)
    cout << theSet[i] << " ";
}

template <class ItemType>
     Set<ItemType> UniteSets(const Set<ItemType> &set1,const Set<ItemType> &set2) 
     {
      Set<ItemType> set3,temp;
      temp=set1;
      vector<ItemType> vect1 = temp.ToVector();
      temp =set2;
      vector<ItemType> vect2 = temp.ToVector();
      for(int i=0;i<vect1.size();i++)
        set3.Add(vect1[i]);
      for(int i=0;i<vect2.size();i++)
        set3.Add(vect2[i]);
      return set3;
     }

