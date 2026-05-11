#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <limits>
#include <exception>
#include <cstdlib>
#include <sys/time.h>

// ─── Tipos auxiliares ─────────────────────────────────────────────────────────

struct MyPair
{
    int a; // maior elemento do par
    int b; // menor elemento do par
};

unsigned long timer();

// ─── Classe ───────────────────────────────────────────────────────────────────

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(char *argv[]);
    void DoPmergeMe();

    class PmergeMeError : public std::exception
    {
    public:
        enum Type { EmptyInput, NegativeNumber, InvalidLiteral, Digits,Dublicated };
        explicit PmergeMeError(Type type);
        virtual const char *what() const throw();
    private:
        Type _type;
    };

private:
    std::vector<int> _vecNums;
    std::deque<int>  _deqNums;
    size_t           _comparisonsCount;

    std::vector<int> buildJacobsthalSequence(int size_pendentes);

    template <typename Container>
    void printContainer(const Container &c) const;

    template <typename Container, typename PairContainer>
    void createPairs(size_t init, Container &nums, PairContainer &pares, int &last);

    template <typename PairContainer>
    void sortA(PairContainer &container);

    template <typename Container>
    int binarySearchPosition(const Container &mainChain, int target, int high);

    template <typename Container>
    void doSort(Container &nums, const std::string &label);
};

template <typename Container>
bool isSorted(const Container &c);

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP