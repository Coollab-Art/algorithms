#pragma once
// inspired from : https://stackoverflow.com/a/57399634
namespace algorithms {

template<typename Container>
void translocate_element(Container&, typename Container::iterator current_location, typename Container::iterator new_location)
{
    if (current_location > new_location)
    {
        std::rotate(
            new_location,
            current_location,
            current_location + 1
        );
    }
    else
    {
        std::rotate(
            std::make_reverse_iterator(new_location) - 1,
            std::make_reverse_iterator(current_location) - 1,
            std::make_reverse_iterator(current_location)
        );
    }
}

} // namespace algorithms
