#include "PmergeMe.hpp"

// ─── Timer ───────────────────────────────────────────────────────────────────

//Returns o tempo em microsegundos
unsigned long timer()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000UL) + tv.tv_usec;
}

// ─── Erro ────────────────────────────────────────────────────────────────────

PmergeMe::PmergeMeError::PmergeMeError(Type type) : _type(type) {}

const char *PmergeMe::PmergeMeError::what() const throw()
{
    switch (_type)
    {
        case EmptyInput:     return "Error: input empty.";
        case NegativeNumber: return "Error: negative number.";
        case InvalidLiteral: return "Error: literal invalid.";
        case Digits:         return "Error: only digits allowed.";
        case Dublicated:         return "Error: Duplicated number.";
        default:             return "Error: unknown.";
    }
}

// ─── Construtores ─────────────────────────────────────────────────────────────

PmergeMe::PmergeMe() : _comparisonsCount(0) {}

PmergeMe::~PmergeMe() {}


PmergeMe::PmergeMe(const PmergeMe &obj) : _vecNums(obj._vecNums),_deqNums(obj._deqNums),_comparisonsCount(obj._comparisonsCount)
{
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
       _vecNums = other._vecNums;
       _deqNums = other._deqNums;
       _comparisonsCount = other._comparisonsCount;
    }
    return *this;
}

// ─── parseInput ───────────────────────────────────────────────────────────────

bool PmergeMe::parseInput(char *argv[])
{
    for (int i = 1; argv[i]; ++i)
    {
        if (!argv[i][0])
            throw PmergeMeError(PmergeMeError::EmptyInput);

        size_t j = 0;
        if (argv[i][0] == '-')
            throw PmergeMeError(PmergeMeError::NegativeNumber);
        if (argv[i][0] == '+')
            j = 1;

        for (; argv[i][j]; ++j)
            if (!isdigit((unsigned char)argv[i][j]))
                throw PmergeMeError(PmergeMeError::Digits);

        long num = std::strtol(argv[i], NULL, 10);
        if (num > std::numeric_limits<int>::max())
            throw PmergeMeError(PmergeMeError::InvalidLiteral);

        if (std::find(_vecNums.begin(), _vecNums.end(), (int)num) != _vecNums.end())
            throw PmergeMeError(PmergeMeError::Dublicated);

        _vecNums.push_back((int)num);
        _deqNums.push_back((int)num);
    }
    return true;
}

// ─── buildJacobsthalSequence ──────────────────────────────────────────────────

std::vector<int> PmergeMe::buildJacobsthalSequence(int size_pendentes)
{
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    for (int i = 2; ; ++i)
    {
        int next = seq[i - 1] + 2 * seq[i - 2];
        seq.push_back(next);
        if (next >= size_pendentes + 1)
            break;
    }
    return seq;
}

// ─── DoPmergeMe ──────────────────────────────────────────────────────────────

void PmergeMe::DoPmergeMe()
{
    std::cout << "Before: ";
    printContainer(_vecNums);
    std::cout << "\n";

    // ── Vector ────────────────────────────────────────────────────────────────
    {
        _comparisonsCount = 0;
        unsigned long start = timer();
        doSort(_vecNums, "vector");
        double elapsed = (timer() - start) / 1000.0;
        std::cout << "TIme to process a range of " << _vecNums.size() <<   elapsed << " µs\n\n";
    }

    // ── Deque ─────────────────────────────────────────────────────────────────
    {
        _comparisonsCount = 0;
        unsigned long start = timer();
        doSort(_deqNums, "deque");
        double elapsed = (timer() - start) / 1000.0;
        std::cout << "TIme to process a range of " << _deqNums.size() <<   elapsed << " µs\n\n";
    }
}