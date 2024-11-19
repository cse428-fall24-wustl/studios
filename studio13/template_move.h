# ifndef TEMPLATE_MOVE_H
# define TEMPLATE_MOVE_H

#include <type_traits> 


template <typename T>
typename std::remove_reference<T>::type&& my_move(T&& param);

# include "template_move.cpp"

# endif