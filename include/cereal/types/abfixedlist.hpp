#ifndef CEREAL_TYPES_ABFIXEDLIST_HPP_
#define CEREAL_TYPES_ABFIXEDLIST_HPP_

#include "ab/fixedlist.hpp"
#include "cereal/cereal.hpp"

namespace cereal {
//! Saving
template <class Archive, class T, ab::size_t C>
inline void CEREAL_SAVE_FUNCTION_NAME(Archive& ar,
                                      ab::TFixedList<T, C> const& list) {
  ar(make_size_tag(static_cast<size_type>(list.size())));

  for (auto const& i : list) ar(i);
}

//! Loading
template <class Archive, class T, ab::size_t C>
inline void CEREAL_LOAD_FUNCTION_NAME(Archive& ar, ab::TFixedList<T, C>& list) {
  size_type size;
  ar(make_size_tag(size));

  list.resize(static_cast<size_t>(size));

  for (auto& i : list) ar(i);
}
}  // namespace cereal

#endif  // CEREAL_TYPES_ABFIXEDLIST_HPP_
