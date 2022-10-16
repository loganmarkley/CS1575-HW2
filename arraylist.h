/* @file: arraylist.h
 * Definition of templated class ArrayList
 * Implementation of the List ADT
 * @C - Galaxy Express Softworks
 *
 * Version 22.3.0
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

/* _________________
  /                 \
  | ArrayList Class |
  \_________________/

    Purpose: Implements a List ADT using a dynamically allocated array to
        store the elements of the list

    Error Handling: Whenever a function is given invalid parameter values
        the message "!!! ERROR : PANIC in ARRAYLIST !!! " and an explanation
        is displayed,
        The list remains unchanged,
        and the dummy member object 'm_errobj' is returned when necessary.
*/


// --------------- Forward Declarations ---------------
template <typename T>                  // the ArrayList class
class ArrayList;

template <typename T>                 // a friend function for output
std::ostream& operator<< (std::ostream& out, const ArrayList<T>& alist);



// ---------------  Class ArrayList Declarations ---------------
template <typename T>
class ArrayList
{
private:
  int m_size;                          // current number of elements
  int m_max;                           // maximum capacity of array m_data
  T* m_data;                           // array to store the elements

  T m_errobj;                          // dummy object to return in case of error


  /*
   * ----- Auxiliary Functions -----
   */

  // Purpose: Increases size of storage array
  // Postconditions: a new array of size m_max*2 is allocated,
  //     and m_data is copied to it.
  //     m_max is set to the size of this new storage array
  void grow();


  // Purpose: Decreases size of storage array
  // Postconditions: a new array of size m_max/2 is allocated,
  //     and m_data is copied to it.
  //     m_max is set to the size of this new storage array
  void shrink();


  /*
   * ---- Constructors ---
   */
public:
  // Purpose: Default Constructor
  // Postconditions: Current size and maximum size set to 0,
  // and data set to NULL.
  // -- PREDEFINED HERE
  ArrayList(): m_size(0), m_max(4) { m_data = new T[m_max]; };

  // Purpose: Parameterized Constructor
  // Parameters:  s : the requested size of the list
  //              x : the initial values in the list
  // Postconditions:  the list is constructed as a list of 's' copies of 'x'
  ArrayList(int s, const T& x);


  /*
   * ---- Big 3 Member Functions ---
   */

  // Purpose: Destructor
  // Postconditions: current size and maximum size set to 0,
  //                 data deallocated and set to NULL
  ~ArrayList();

  // Purpose: Operator=, performs a deep copy of 'rhs' into 'this' ArrayList
  // Parameters: rhs : ArrayList to be copied
  // Returns: *this
  // Postconditions: rhs == this
  ArrayList<T>& operator=(const ArrayList<T>& rhs);

  // Purpose: Copy Constructor
  // Parameters: cpy = ArrayList to be copied
  // Postconditions: current size, maximum size, and elements same as cpy
  ArrayList(const ArrayList<T>& cpy);


  /*
   * ----- Basic Accessor Operations -----
   */

  // Purpose: Accessor function for the number of elements in the list
  // Returns: number of elements in the list
  int size() const;

  // Purpose: Accessor function for the max capacity of elements
  // Returns: max capacity of this list
  // -- PREDEFINED HERE  ( used for grading purposes )
  int max() const { return m_max; };

  // Purpose: Accessor function for the first element of the list
  // Returns: the first element in the list
  const T& first() const;

  // Purpose: return a read-and-write reference to the element at
  // the specified position
  // Parameters: i is 0-based index into the ArrayList
  // Returns: the element at position i in the ArrayList
  T& operator[](int i);

  // Purpose: return a read-only reference to the element at
  // the specified position
  // Parameters: i is 0-based index into the ArrayList
  // Returns: the element at position i in the ArrayList
  const T& operator[](int i) const;

  // Purpose: finds an element in the ArrayList
  // Parameters: 'x' is value to be found in the ArrayList
  // Returns: the position of the first occurrance of 'x' in the list,
  //          or -1  if 'x' is not found.
  int search(const T& x) const;


  /*
   * ----- Basic Mutator Operations -----
   */
  // Purpose: Clears the ArrayList
  // Postconditions: storage array is deallocated, 
  //                 and a new storage array of size 4 is allocated.
  //                 max size is set to 4,
  //                 list size is set to 0.
  //                 ( same as default constructor )
  void clear();

  // Purpose: puts the value x at the end of an ArrayList
  // Parameters: x is value to be added to ArrayList
  // Postconditions: current size is incremented by 1
  //     If max size is reached, the storage wrray is grown.
  void insert_back(const T& x);

  // Purpose: puts the value x at the position i in the  ArrayList
  // Parameters: x is value to be added to ArrayList
  //             i is the position to insert x at
  // Postconditions: current size is incremented by 1
  //     If max size is reached, the storage array is grown().
  void insert(const T& x, int i);

  // Purpose: Removes the element at index i in the array
  // Parameters: i, the index of the element to remove
  // Postconditions: if the size of the list is greater than 0
  //     size is decremented by one.
  //     if the size of the list less than 1/4 the max size,
  //     the storage array is shrunk.
  void remove(int i);


  /*
   * ----- Complex Mutator Operations -----
   */

  // Purpose: swaps two elements of the array
  // Parameters: i, k, two positions on the Arraylist
  // Postconditions: the elements at positions i and k swap positions
  void swap(int i, int k);

  // Purpose: removes duplicates from an Arraylist
  // Postconditions: all duplicate elements are removed from the list.
  //    the first occurance of an element is kept.
  void purge();

  // Purpose: Reverses an ArrayList
  // Postconditions: the elements in the list are now reversed.
  void reverse();


  /*
   * ----- Complex Accessors Operations -----
   */

  // Purpose: prints the ArrayList
  friend std::ostream& operator<< <> (std::ostream& out,
                                      const ArrayList<T>& alist);
};



// FREE FUNCTION FOR YOU !!!
// This is the function to pretty print the lists
// -----------------  Friend Function to Print  -----------------
// Purpose: prints an ArrayList
template <typename T>
std::ostream& operator<< (std::ostream& out, const ArrayList<T>& alist)
{
  out << "[ ";
  for (int i=0; i < alist.m_size; i++){
    out << alist.m_data[i] << ", ";
  }
  out << "]";
  return out;
}


#include "arraylist.hpp"
#endif
