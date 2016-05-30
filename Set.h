//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.
//  ORIGINALLY BAG.H, MODIFIED TO SET.H BY ANDRES QUINONES

/** ADT Set: Array-based implementation.
 @file Set.h */


#ifndef Programming_Project_1_235_AQ
#define Programming_Project_1_235_AQ

#include "SetInterface.h"

template<class ItemType>
class Set : public SetInterface<ItemType>
{
 public:
  Set();
Set(const ItemType &an_item);
  int GetCurrentSize() const;
  bool IsEmpty() const;
  bool Add(const ItemType& new_entry);
  bool Remove(const ItemType& an_entry);
  void Clear();
  bool Contains(const ItemType& an_ntry) const;
  vector<ItemType> ToVector() const; 
  
 private:
  static const int kDefaultSetSize_ = 20;  
  ItemType items_[kDefaultSetSize_]; // array of set items
  int item_count_;                    // current count of set items 
  int max_items_;                 // max capacity of the set
  
  // Returns either the index of the element in the array items that
  // contains the given target or -1, if the array does not contain 
  // the target.
  int GetIndexOf(const ItemType& target) const;   
};  // end Set

#include "Set.cpp"

#endif  /* defined Programming_Project_1_235_AQ */
