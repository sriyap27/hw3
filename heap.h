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
  std::vector<T> data;
  int m_ary;
  PComparator comp;

  void bubbleUp(int idx);
  void bubbleDown(int idx);

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_ary(m), comp(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if (data.size() == 0) {
    return true;
  }
  return false;
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return data.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::bubbleUp(int idx) {
  while (idx > 0) {
    int parent = (idx - 1) / m_ary;
    if (comp(data[idx], data[parent])) {
      std::swap(data[idx], data[parent]);
      idx = parent;
    }
    else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::bubbleDown(int idx) {
  while (m_ary * idx + 1 < data.size()) {
    int best = idx;
    // comparing children
    for (int i = 1; i <= m_ary; i++) {
      int child = m_ary * idx + i;
      if (child < data.size()) {
        if (comp(data[child], data[best])) {
          best = child;
        }
      }

    }
    if (best == idx) {
      break;
    }
    std::swap(data[idx], data[best]);
    idx = best;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  int idx = data.size();
  data.push_back(item);
  bubbleUp(idx);
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
    throw std::underflow_error("Empty Heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();


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
    throw std::underflow_error("Empty Heap");

  }
  std::swap(data[0], data[data.size() - 1]);
  data.pop_back();
  if (!empty()) bubbleDown(0);

}





#endif

