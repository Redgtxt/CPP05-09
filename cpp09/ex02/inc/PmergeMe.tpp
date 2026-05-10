// ─── printContainer ──────────────────────────────────────────────────────────

template <typename Container>
void PmergeMe::printContainer(const Container &c) const
{
    for (typename Container::size_type i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
}

// ─── createPairs ─────────────────────────────────────────────────────────────

template <typename Container, typename PairContainer>
void PmergeMe::createPairs(size_t init, Container &nums, PairContainer &pares, int &last)
{
    if (init >= nums.size())
        return;

    // elemento ímpar sobrante
    if (init == nums.size() - 1)
    {
        last = nums[init];
        return;
    }

    ++_comparisonsCount;

    MyPair p;
    if (nums[init] > nums[init + 1])
    {
        p.a = nums[init];
        p.b = nums[init + 1];
    }
    else
    {
        p.a = nums[init + 1];
        p.b = nums[init];
    }
    pares.push_back(p);

    createPairs(init + 2, nums, pares, last);
}

// ─── sortA ───────────────────────────────────────────────────────────────────

template <typename PairContainer>
void PmergeMe::sortA(PairContainer &container)
{
    if (container.size() <= 1)
        return;

    size_t mid = container.size() / 2;
    PairContainer left(container.begin(), container.begin() + mid);
    PairContainer right(container.begin() + mid, container.end());

    sortA(left);
    sortA(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        ++_comparisonsCount;
        if (left[i].a <= right[j].a)
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }
    while (i < left.size())  container[k++] = left[i++];
    while (j < right.size()) container[k++] = right[j++];
}

// ─── binarySearchPosition ────────────────────────────────────────────────────

template <typename Container>
int PmergeMe::binarySearchPosition(const Container &mainChain, int target, int high)
{
    int low = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        ++_comparisonsCount;
        if (mainChain[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// ─── doSort ──────────────────────────────────────────────────────────────────

template <typename Container>
void PmergeMe::doSort(Container &nums, const std::string &label)
{
    typedef std::vector<MyPair> PairContainer;

    // 1. Criar e ordenar pares
    PairContainer pares;
    int last = -1;
    createPairs(0, nums, pares, last);
    sortA(pares);

    // 2. Construir mainChain e pendentes
    Container mainChain;
    Container pendentes;

    mainChain.push_back(pares[0].b);
    mainChain.push_back(pares[0].a);

    for (size_t i = 1; i < pares.size(); ++i)
    {
        mainChain.push_back(pares[i].a);
        pendentes.push_back(pares[i].b);
    }
    if (last != -1)
        pendentes.push_back(last);

    // 3. Inserçao por ordem de Jacobsthal
    std::vector<int> jacobSeq = buildJacobsthalSequence((int)pendentes.size());

    int lastJacob = 1;
    int max_b     = (int)pendentes.size() + 1;
    int nInserted = 0;

    for (size_t i = 3; i < jacobSeq.size(); ++i)
    {
        int curJacob = jacobSeq[i];
        if (curJacob > max_b)
            curJacob = max_b;

        for (int j = curJacob; j > lastJacob; --j)
        {
            int numToInsert    = pendentes[j - 2];
            int maxSearchIndex = j + nInserted - 1;

            if (maxSearchIndex >= (int)mainChain.size())
                maxSearchIndex = (int)mainChain.size() - 1;

            int pos = binarySearchPosition(mainChain, numToInsert, maxSearchIndex);
            mainChain.insert(mainChain.begin() + pos, numToInsert);
            ++nInserted;
        }
        lastJacob = curJacob;
    }

    // 4. Output
    std::cout << "[" << label << "] Result:   ";
    printContainer(mainChain);
    std::cout << "\n[" << label << "] Comparisons: " << _comparisonsCount << "\n";
    std::cout << (isSorted(mainChain) ? "OK" : "ERRO") << "\n";
}

template <typename Container>
bool isSorted(const Container &c)
{
    if (c.size() <= 1)
        return true;
    for (typename Container::size_type i = 0; i < c.size() - 1; ++i)
    {
        if (c[i] > c[i + 1])
            return false;
    }
    return true;
}