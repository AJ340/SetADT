//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.
//  MODIFIED TO SET INTERFACE BY ANDRES QUINONES

/** Listing 1-1.
    @file setInterface.h */
#ifndef TEACH_CSCI235_SetADT_SetINTERFACE_H_
#define TEACH_CSCI235_SetADT_SetINTERFACE_H_

#include <vector>
#include <iostream>
using namespace std;

template<class ItemType>
class SetInterface
{
public:
   /** Gets the current number of entries in this set.
    @return The integer number of entries currently in the set. */
   virtual int GetCurrentSize() const = 0;
   
   /** Sees whether this set is empty.
    @return True if the set is empty, or false if not. */
   virtual bool IsEmpty() const = 0;
   
   /** Adds a new entry to this set.
    @post  If successful, newEntry is stored in the set and
       the count of items in the set has increased by 1.
    @param new_entry  The object to be added as a new entry.
    @return  1 if addition was successful, 0 if the set is full, 
      0 if the item attempting to add is already in the set. */
   virtual bool Add(const ItemType& new_entry) = 0;
   
   /** Removes one occurrence of a given entry from this set,
       if possible.
    @post  If successful, anEntry has been removed from the set
       and the count of items in the set has decreased by 1.
    @param an_entry  The entry to be removed.
    @return  True if removal was successful, or false if not. */
   virtual bool Remove(const ItemType& an_entry) = 0;
   
   /** Removes all entries from this set.
    @post  set contains no items, and the count of items is 0. */
   virtual void Clear() = 0;
  
   
   /** Tests whether this set contains a given entry.
    @param an_entry  The entry to locate.
    @return  True if set contains anEntry, or false otherwise. */
   virtual bool Contains(const ItemType& an_entry) const = 0;
   
   /** Empties and then fills a given vector with all entries that
       are in this set.
    @return  A vector containing all the entries in the set. */
   virtual vector<ItemType> ToVector() const = 0;
}; // end setInterface
#endif  // TEACH_CSCI235_setADT_setINTERFACE_H_
