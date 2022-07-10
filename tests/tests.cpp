#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <algorithms/algorithms.hpp>

// Check out doctest's documentation: https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md

// Allow doctest to print std::vectors
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

// TODO templatized test on vecor, list etc.
TEST_CASE("translocate_element() moves one element from one place to another in a container")
{
    auto vec = std::vector<int>{0, 1, 2, 3, 4};

    SUBCASE("When moving backward")
    {
        algorithms::translocate(
            vec.begin() + 3,
            vec.begin() + 1
        );

        CHECK(vec == std::vector{0, 3, 1, 2, 4});
    }

    SUBCASE("When moving forward")
    {
        algorithms::translocate(
            vec.begin() + 2,
            vec.begin() + 3
        );

        CHECK(vec == std::vector{0, 1, 3, 2, 4});
    }

    SUBCASE("When moving to the beginning")
    {
        algorithms::translocate(
            vec.begin() + 4,
            vec.begin()
        );

        CHECK(vec == std::vector{4, 0, 1, 2, 3});
    }

    SUBCASE("When moving the first element")
    {
        algorithms::translocate(
            vec.begin(),
            vec.begin() + 3
        );

        CHECK(vec == std::vector{1, 2, 3, 0, 4});
    }

    SUBCASE("When moving to the end")
    {
        algorithms::translocate(
            vec.begin() + 3,
            vec.end() - 1
        );

        CHECK(vec == std::vector{0, 1, 2, 4, 3});
    }

    SUBCASE("When moving the last element")
    {
        algorithms::translocate(
            vec.end() - 1,
            vec.begin() + 2
        );

        CHECK(vec == std::vector{0, 1, 4, 2, 3});
    }

    SUBCASE("When staying at the same location")
    {
        algorithms::translocate(
            vec.begin() + 2,
            vec.begin() + 2
        );

        CHECK(vec == std::vector{0, 1, 2, 3, 4});
    }

    SUBCASE("When moving the first element to the same location")
    {
        algorithms::translocate(
            vec.begin(),
            vec.begin()
        );

        CHECK(vec == std::vector{0, 1, 2, 3, 4});
    }

    SUBCASE("When moving the last element to the same location")
    {
        algorithms::translocate(
            vec.end() - 1,
            vec.end() - 1
        );

        CHECK(vec == std::vector{0, 1, 2, 3, 4});
    }

    SUBCASE("When moving the last element to the beginning")
    {
        algorithms::translocate(
            vec.end() - 1,
            vec.begin()
        );

        CHECK(vec == std::vector{4, 0, 1, 2, 3});
    }

    SUBCASE("When moving the first element to the end")
    {
        algorithms::translocate(
            vec.begin(),
            vec.end() - 1
        );

        CHECK(vec == std::vector{1, 2, 3, 4, 0});
    }
}
