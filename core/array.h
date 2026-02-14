#ifndef ARRAY_H
#define ARRAY_H

#include "typedefs.h"
class Variant;
class ArrayPrivate;
class Object;
class StringName;

class Array
{

  mutable ArrayPrivate *_p;
  void _ref(const Array &p_from) const;
  void _unref() const;

public:
  Variant &operator[](int p_idx);
  const Variant &operator[](int p_idx) const;

  void set(int p_idx, const Variant &p_value);
  const Variant &get(int p_idx) const;

  int size() const;
  bool empty() const;
  void clear();

  bool is_shared() const;

  bool operator==(const Array &p_array) const;

  uint32_t hash() const;
  void operator=(const Array &p_array);

  void push_back(const Variant &p_value);
  _FORCE_INLINE_ void append(const Variant &p_value) { push_back(p_value); } // for python compatibility
  Error resize(int p_new_size);

  void insert(int p_pos, const Variant &p_value);
  void remove(int p_pos);

  void sort();
  void sort_custom(Object *p_obj, const StringName &p_function);
  void invert();

  int find(const Variant &p_value) const;

  void erase(const Variant &p_value);

  Array(const Array &p_from);
  Array(bool p_shared = false);
  ~Array();
};

#endif // ARRAY_H
