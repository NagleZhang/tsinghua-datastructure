#pragma once

template <typename T> void Vector<T>::copyFrom( T const* A, Rank lo, Rank hi )
{
  _elem = new T[ _capacity = 2*(hi-lo)];
  for( _size = 0; lo < hi; _size++, lo++ )
    _elem[ _size ] = A[ lo ];
}

template <typename T> Vector<T>& Vector<T>::operator= ( Vector<T> const& V )
{
 if (_elem) delete [] _elem;
 copyFrom(V._elem, 0, V.size());
 return *this;
}

template <typename T> void Vector<T>::expand()
{
 if ( _size < _capacity ) return;
 if ( _capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
 T* oldElem = _elem;
 _elem = new T[_capacity <<= 1];
 for ( int i = 0; i < _size; i++ ) {
   _elem[i] = oldElem[i];
 }
 delete [] oldElem;
}

template <typename T> void Vector<T>::shrink()
{
 if ( _capacity < DEFAULT_CAPACITY << 1 ) return;
 if ( _size << 2 > _capacity ) return; // 如果 _size (当前的量)的 4 倍大于 _capacity(当前能够容纳的量).
 T* oldElem = _elem;
 _elem = new T[_capacity >>= 1];
 for (int i = 0; i < _size; i++) {
   _elem[i] = oldElem[i];
 }
 delete [] oldElem;
}

template <typename T> Rank Vector<T>::insert(Rank r, T const& e)
{
  expand();
  for( int i = _size; i < r; i--) {
    _elem[i] = _elem[i-1];
  }
  _elem[r] = e;
  _size ++;
  return r;
}

template <typename T> Rank Vector<T>::insert( T const& e)
{
  return insert(_size, e);
}

template <typename T> int Vector<T>::remove(Rank lo, Rank hi)
{
  // 1112221111 , 要刪除 222, 实际上就是把 222 移到最末端.
  if (lo == hi) return 0;
  while(hi < _size) {
    _elem[lo++] = _elem[hi++];
  }
  _size = lo;
  shrink();
  return hi - lo;
}

//  课程似乎没有讲解到书中提到的置乱的算法.
//  其中置乱的算法, 用到了 operator [] 的覆盖.
//  但是尝试使用 operator[] 的 set 方法, 似乎没有生效. 想请问这个是需要自己去实现么?

template <typename T> T Vector<T>::remove(Rank r)
{
  T e = _elem[r];
  remove(r, r+1);
  return e;
}

template <typename T> T& Vector<T>::operator[] (Rank r) {
  return _elem[r];
}

template <typename T> const T& Vector<T>::operator[] ( Rank r ) const
{
  return _elem[r];
}

template <typename T> void Vector<T>::unsort(Rank lo, Rank  hi)
{
  for (int i = hi; i > lo ; i--) {
    swap(_elem[i],_elem[rand() % i]);
  }
}
