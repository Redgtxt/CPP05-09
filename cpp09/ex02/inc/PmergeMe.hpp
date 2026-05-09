#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <exception>
#include <cstdlib>
#include <sys/time.h>


struct MyPair
{
    int a;
    int b;
};


class PmergeMe
{
private:
    std::vector<int> nums; 
    size_t comparisonsCount;
public:
    PmergeMe();
    ~PmergeMe();

    bool populateVector(char *argv[]);

    std::vector<int> getNums() const;


    void printVec(const std::vector<int>& vec);
    void printVecPair(const std::vector<MyPair>& vec);
    void sortA(std::vector<MyPair>& vec);
    

    std::vector<int> buildJacobsthalSequence(int size_pendentes);

    int binarySearchPosition(const std::vector<int>& mainChain, int target, int high);

    void  createPairs(size_t init,std::vector<int>&nums,std::vector<MyPair>&pares,int &last);

    void DoPmergeMe();

    class PmergeMeError : public std::exception {
    public:
        enum Type { EmptyInput, NegativeNumber, InvalidLiteral, Digits };
        PmergeMeError(Type type);
        virtual const char* what() const throw();
    private:
        Type _type;
    };
    
};
unsigned long	timer(void);
/*

ATTENCION HUGO FUTURO:
Talvez seja inteligente passar a funcao que printa um vector para uma template que printa um container !!!

*/

unsigned long	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}



PmergeMe::PmergeMe() : comparisonsCount(0)
{
}

PmergeMe::~PmergeMe()
{
}


PmergeMe::PmergeMeError::PmergeMeError(Type type) : _type(type) {}

const char* PmergeMe::PmergeMeError::what() const throw()
{
    switch (_type) {
        case EmptyInput:          return "Error: input empty.";
        case NegativeNumber:      return "Error: Negative Number";
        case InvalidLiteral:      return "Error: literal invalid.";
        case Digits:              return "Error: should only be digits";
        default:                  return "Error Unknowned.";
    }
}



void PmergeMe::printVec(const std::vector<int>& vec)
{
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}

// Ordena um vector de pares usando Merge Sort recursivo (ordenação pelo maior elemento do par)
void PmergeMe::sortA(std::vector<MyPair>& vec)
{
    // Caso base: um único elemento já está ordenado, termina a recursão
    if (vec.size() <= 1)
        return;

    // Divide o vector ao meio para conquistar cada metade independentemente
    size_t mid = vec.size() / 2;
    std::vector<MyPair> left(vec.begin(), vec.begin() + mid);
    std::vector<MyPair> right(vec.begin() + mid, vec.end());

    // Ordena recursivamente cada metade antes de as fundir
    sortA(left);
    sortA(right);

    // Índices de iteração: i → left, j → right, k → posição de escrita em vec
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    // compara o maior elemento de cada par e intercala por ordem crescente
    while (i < left.size() && j < right.size())
    {
        this->comparisonsCount++;


        if (left[i].a <= right[j].a)
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }

    // Copia os elementos restantes da metade esquerda
    while (i < left.size())
        vec[k++] = left[i++];

    // Copia os elementos restantes da metade direita 
    while (j < right.size())
        vec[k++] = right[j++];
}


void PmergeMe::printVecPair(const std::vector<MyPair>& vec)
{
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
    {
        std::cout << "b: " << vec[i].b << " ";      
        std::cout << "a: " << vec[i].a << " ";      
        std::cout << "" << std::endl;
    }

}

std::vector<int> PmergeMe::getNums() const
{
    return this->nums;
}

bool PmergeMe::populateVector(char *argv[])
{
    int i = 1;
    //Percorre argv para salvar os valores dentro do vector
    while (argv[i])
    {
        if (!argv[i][0])
            throw PmergeMeError(PmergeMeError::EmptyInput);

        // rejeita '-' explicitamente (e permite '+' opcional)
        size_t j = 0;
        if (argv[i][0] == '-')
            throw PmergeMeError(PmergeMeError::NegativeNumber);
        if (argv[i][0] == '+')
            j = 1;

        //vamos verificar se e um numero (so digitos)
        for (; argv[i][j]; j++)
        {
            if (!isdigit((unsigned char)argv[i][j]))
                throw PmergeMeError(PmergeMeError::Digits);
        }

        long num = std::strtol(argv[i], NULL, 10);

        // Verifica overflow de int
        if (num > std::numeric_limits<int>::max())
            throw PmergeMeError(PmergeMeError::InvalidLiteral);

        ///Verifica duplicados
        if (std::find(nums.begin(), nums.end(), (int)num) != nums.end())
            return false;

        nums.push_back((int)num);
        i++;
    }
    return true;
}

void  PmergeMe::createPairs(size_t init,std::vector<int>&nums,std::vector<MyPair>&pares,int &last)
{
    if(init >= nums.size())
       return;
    
    MyPair newPar;
    // sou impar
    if(init == nums.size() - 1)
    {
        last = nums.back();
        return;
    }
    
    this->comparisonsCount++;

    if(nums[init] > nums[init + 1])
    {
        newPar.b = nums[init + 1];
        newPar.a = nums[init];
    }else{
        newPar.a = nums[init + 1];
        newPar.b = nums[init];
    }

    pares.push_back(newPar);

    createPairs(init + 2,nums,pares,last);
    
}

std::vector<int> PmergeMe::buildJacobsthalSequence(int size_pendentes)
{
    std::vector<int> jacobSeq;
    
    // Os dois primeiros números base
    jacobSeq.push_back(0); // J(0)
    jacobSeq.push_back(1); // J(1)
    

    /*
    0, 1, 1, 3, 5, 11, 21

    0,1,1,3
    2x1 + 1=  3
    1x2 + 3 = 5
    3x2 + 5 = 11
    5x2 + 11 = 21
    */
    int i = 2;
    while (true)
    {
        // J(n) = J(n-1) + 2 * J(n-2)
        int nextJacob = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
        jacobSeq.push_back(nextJacob);
        
        // Se o numero de Jacobsthal já e maior que o numero de pendentes que temos,
        // nao precisamos de calcular mais nenhum!
        if (nextJacob >= size_pendentes + 1)
            break;
            
        i++;
    }
    
    return jacobSeq;
}


// Retorna o indice onde o 'target' deve ser inserido na 'mainChain'
int PmergeMe::binarySearchPosition(const std::vector<int>& mainChain, int target, int high)
{
    int low = 0;
    
    // O ciclo corre enquanto a nossa area de pesquisa for valida
    while (low <= high)
    {

        //li que isto ajuda a nao dar overflow com sequencias gigantes
        int mid = low + (high - low) / 2;

        this->comparisonsCount++;


        if (mainChain[mid] < target)
        {
            // Se o alvo e MAIOR que o meio, ignoramos a metade esquerda
            low = mid + 1;
        }
        else if (mainChain[mid] > target)
        {
            // Se o alvo e MENOR que o meio, ignoramos a metade direita
            high = mid - 1;
        }
    }

    //Aponta para a posicao onde o target vai ser colocado
    return low;
}


void PmergeMe::DoPmergeMe()
{
    //A representa os maiores numeros
    std::vector<MyPair> pares;

    int last = -1;
    createPairs(0,this->nums,pares,last);

    std::cout << "-----------------------Vector Pares -----------------" << std::endl;
    this->printVecPair(pares);

    std::cout << "-----------------------Vector after sorted Pares -----------------" << std::endl;

    this->sortA(pares);
    this->printVecPair(pares);
    std::cout << std::endl;


    std::vector<int> mainChain;
    std::vector<int> pendentes;

    mainChain.push_back(pares[0].b);
    mainChain.push_back(pares[0].a);

    for (size_t i = 1; i < pares.size(); i++)
    {
        mainChain.push_back(pares[i].a);
        pendentes.push_back(pares[i].b);
    }

    if(last != -1)
    {
        std::cout << "Pendente " << last << std::endl;
        pendentes.push_back(last);
    }

    std::cout << "----------------------- Main Chain Inicial -----------------" << std::endl;
    this->printVec(mainChain);
    std::cout << std::endl;

    std::cout << "----------------------- Pendentes (Para inserir) -----------------" << std::endl;
    this->printVec(pendentes);
    std::cout << std::endl;

    std::cout << "----------------------- JacobSequence -----------------" << std::endl;
    std::vector<int> JacobSequence = this->buildJacobsthalSequence(pendentes.size());
    this->printVec(JacobSequence);
    std::cout << std::endl;

// O B1 já esta na lista dos 'A's, por isso o ultimo Jacob que processámos foi o 1.
    int lastJacob = 1;
    
    // O numero maximo real de Bs que temos na nossa posse
    int max_b = pendentes.size() + 1;

    int countBInserted = 0;
    // Começamos o indice a 3, porque jacobSeq[3] é o número '3' 
    // (ignoramos os 0, 1, 1 do início)
    for (size_t i = 3; i < JacobSequence.size(); i++)
    {
        int currentJacob = JacobSequence[i];

        // Proteçao: se o Jacobsthal pedir um salto maior do que os numeros que temos
        if (currentJacob > max_b) {
            currentJacob = max_b;
        }
        
        // Volta para tras inserindo
        int j = currentJacob;
        while (j > lastJacob)
        {
            // Traduz o B atual para o índice no vetor de pendentes (B3 -> índice 1)
            int indexNoPendentes = j - 2;

            int NumberToInsert = pendentes[indexNoPendentes];

            //Conta para perceber ate onde vou procurar
            /*
            maxSeachIndex = j + counterDeBInserido - 1

            colocamos -1 porque como o b e menor do que A entao nao precisamos de contar com A na pesquisa

            j = Nuemro do b que representa

            maxSeachIndex = 3 + 0 - 1 = 2 B3

            */
            int maxSeachIndex = j + countBInserted - 1;

            if(maxSeachIndex >= (int)mainChain.size())
            {
                maxSeachIndex = mainChain.size() - 1;
            }

            // 🍌#grrrr 
            int pos = binarySearchPosition(mainChain,NumberToInsert,maxSeachIndex);
            
            mainChain.insert(mainChain.begin() + pos, NumberToInsert);            
            countBInserted++;
            // Insere o numero na posiçao exata
            j--;
        }

        lastJacob = currentJacob;
    }
    
    std::cout << "----------------------- MAIN CHAIN FINAL -----------------" << std::endl;
    this->printVec(mainChain);
    std::cout << std::endl;
    
    std::cout << "Number of comparisons: " << this->comparisonsCount << std::endl;

    /*

    [X] descobrir porque e que estou a perder numeros
    [X] Incrementar sempre que houver uma comparaçao
    

    [] Usar o deck
    [] time stamp
    */

}

#endif