#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m; 
  int s;
  PComparator c;
  std::vector<T> heap;
  void heapifyUp(int index); 
  void heapifyDown(int index); 
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(int index){
  //get index of parent 
  int parent = (index-1)/m; 
  //compare parent vs child
  if(c(heap[index], heap[parent])){
    //swap parent and child
    T temp= heap[index];
    heap[index] = heap[parent];
    heap[parent] = temp;
    //heapify parent 
    heapifyUp(parent);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>:: heapifyDown(int index){
  //create array to store children indices
  int children[m+1];
  while(true){
    for(int i=1; i<=m; i++){
      //add index to children if valid 
      if(m*index+i<s){
        children[i] = m*index+i;
      }
      //otherwise use negative 1 
      else{
        children[i] = -1;
      }
    }
    T max;
    int maxIndex = -1; 
    for(int i=1; i<=m; i++){
      //if valid child 
      if(children[i]!= -1){
        //compare child to max or set if no max has been hit yet
        if(c(heap[children[i]], max) || maxIndex ==-1){
          maxIndex = children[i];
          max = heap[children[i]];
        }
      }
    } 
    //no max children, so heapify process can stop
    if(maxIndex == -1){
      break;
    }
    //swap max with current if comparator says to 
    if(c(heap[maxIndex], heap[index])){
      T temp = heap[maxIndex];
      heap[maxIndex] = heap[index];
      heap[index]= temp; 
    }
    index = maxIndex;
  } 
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  this->m= m;
  this->c= c;
  s = 0;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  heap.clear();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  //add item to heap vector and heapify starting at the end
  heap.push_back(item);
  s++;
  heapifyUp(s-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }
  //set first item to back and remove back and heapify starting at the front
  heap[0] = heap.back();
  heap.pop_back(); 
  s--;
  heapifyDown(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return s == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return heap.size();
}

#endif

