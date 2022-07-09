#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithms/algorithms.hpp>

// Check out doctest's documentation: https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md

namespace std {
template<typename T>
std::ostream& operator<<(std::ostream& output, std::vector<T> const& values)
{
    for (auto const& value : values)
    {
        output << value << ", ";
    }
    return output;
}
} // namespace std

TEST_CASE("translocate_element() moves one element from one place to another in a container")
{
    SUBCASE("When moving backward")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin() + 3,
            vect_translocate.begin() + 1
        );

        CHECK(vect_translocate == std::vector{1, 4, 2, 3, 5});
    }
    SUBCASE("When moving forward")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin() + 1,
            vect_translocate.begin() + 3
        );

        CHECK(vect_translocate == std::vector{1, 3, 4, 2, 5});
    }
    SUBCASE("When moving at the beginning")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin() + 3,
            vect_translocate.begin()
        );

        CHECK(vect_translocate == std::vector{4, 1, 2, 3, 5});
    }
    SUBCASE("When moving at the first element")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin(),
            vect_translocate.begin() + 2
        );

        CHECK(vect_translocate == std::vector{2, 3, 1, 4, 5});
    }
    SUBCASE("When moving at the end")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin() + 1,
            vect_translocate.end() - 1
        );

        CHECK(vect_translocate == std::vector{1, 3, 4, 5, 2});
    }
    SUBCASE("When moving at the last element")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.end() - 1,
            vect_translocate.begin() + 3
        );

        CHECK(vect_translocate == std::vector{1, 2, 3, 5, 4});
    }
    SUBCASE("When moving on itself")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin() + 1,
            vect_translocate.begin() + 1
        );

        CHECK(vect_translocate == std::vector{1, 2, 3, 4, 5});
    }
    SUBCASE("When moving on itself at the beginning")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin(),
            vect_translocate.begin()
        );

        CHECK(vect_translocate == std::vector{1, 2, 3, 4, 5});
    }
    SUBCASE("When moving on itself at the end")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.end() - 1,
            vect_translocate.end() - 1
        );

        CHECK(vect_translocate == std::vector{1, 2, 3, 4, 5});
    }
    SUBCASE("When moving the last element at the beginning")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.end() - 1,
            vect_translocate.begin()
        );

        CHECK(vect_translocate == std::vector{5, 1, 2, 3, 4});
    }
    SUBCASE("When moving the first element at the end")
    {
        std::vector<int> vect_translocate = std::vector<int>{1, 2, 3, 4, 5};

        algorithms::translocate_element(
            vect_translocate,
            vect_translocate.begin(),
            vect_translocate.end() - 1
        );

        CHECK(vect_translocate == std::vector{2, 3, 4, 5, 1});
    }
}
