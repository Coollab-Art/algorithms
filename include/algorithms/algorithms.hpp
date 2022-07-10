#pragma once
// inspired from : https://stackoverflow.com/a/57399634
namespace algorithms {

template<typename Iterator>
void translocate(
    Iterator current_location,
    Iterator new_location
)
{
    if (current_location > new_location)
    {
        std::rotate(
            new_location,
            current_location,
            std::next(current_location)
        );
    }
    else
    {
        std::rotate(
            std::prev(std::make_reverse_iterator(new_location)),
            std::prev(std::make_reverse_iterator(current_location)),
            std::make_reverse_iterator(current_location)
        );
    }
}

} // namespace algorithms
