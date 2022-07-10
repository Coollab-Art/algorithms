#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithms/algorithms.hpp>
#include <array>
#include <vector>

// Check out doctest's documentation: https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md

// Allow doctest to print std::vectors

template<typename Container>
doctest::String toString(const Container& values)
{
    std::stringstream output{};
    for (const auto& value : values)
    {
        output << value << ", ";
    }
    return doctest::String{output.str().c_str()};
}

TYPE_TO_STRING(std::vector<int>);
TYPE_TO_STRING(std::array<int, 5>);

// TODO templatized test on vecor, list etc.
TEST_CASE_TEMPLATE("translocate_element() moves one element from one place to another in a container", Container, std::vector<int>, std::array<int, 5>)
{
    auto container = Container{0, 1, 2, 3, 4};

    SUBCASE("When moving backward")
    {
        algorithms::translocate(
            std::next(container.begin(), 3),
            std::next(container.begin(), 1)
        );

        CHECK(container == Container{0, 3, 1, 2, 4});
    }

    SUBCASE("When moving forward")
    {
        algorithms::translocate(
            std::next(container.begin(), 2),
            std::next(container.begin(), 3)
        );

        CHECK(container == Container{0, 1, 3, 2, 4});
    }

    SUBCASE("When moving to the beginning")
    {
        algorithms::translocate(
            std::next(container.begin(), 4),
            container.begin()
        );

        CHECK(container == Container{4, 0, 1, 2, 3});
    }

    SUBCASE("When moving the first element")
    {
        algorithms::translocate(
            container.begin(),
            std::next(container.begin(), 3)
        );

        CHECK(container == Container{1, 2, 3, 0, 4});
    }

    SUBCASE("When moving to the end")
    {
        algorithms::translocate(
            std::next(container.begin(), 3),
            std::prev(container.end(), 1)
        );

        CHECK(container == Container{0, 1, 2, 4, 3});
    }

    SUBCASE("When moving the last element")
    {
        algorithms::translocate(
            std::prev(container.end(), 1),
            std::next(container.begin(), 2)
        );

        CHECK(container == Container{0, 1, 4, 2, 3});
    }

    SUBCASE("When staying at the same location")
    {
        algorithms::translocate(
            std::next(container.begin(), 2),
            std::next(container.begin(), 2)
        );

        CHECK(container == Container{0, 1, 2, 3, 4});
    }

    SUBCASE("When moving the first element to the same location")
    {
        algorithms::translocate(
            container.begin(),
            container.begin()
        );

        CHECK(container == Container{0, 1, 2, 3, 4});
    }

    SUBCASE("When moving the last element to the same location")
    {
        algorithms::translocate(
            std::prev(container.end(), 1),
            std::prev(container.end(), 1)
        );

        CHECK(container == Container{0, 1, 2, 3, 4});
    }

    SUBCASE("When moving the last element to the beginning")
    {
        algorithms::translocate(
            std::prev(container.end(), 1),
            container.begin()
        );

        CHECK(container == Container{4, 0, 1, 2, 3});
    }

    SUBCASE("When moving the first element to the end")
    {
        algorithms::translocate(
            container.begin(),
            std::prev(container.end(), 1)
        );

        CHECK(container == Container{1, 2, 3, 4, 0});
    }
}
