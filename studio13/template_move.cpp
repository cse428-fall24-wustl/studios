#include "template_move.h"

template <typename T>
typename std::remove_reference<T>::type&& my_move(T&& param)
{
    return static_cast<typename std::remove_reference<T>::type&&>(param);
}