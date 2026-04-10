#include <iostream>
#include "Array.hpp"

#define PASS "\033[32m[PASS]\033[0m "
#define FAIL "\033[31m[FAIL]\033[0m "
#define SECTION(x) std::cout << "\n\033[1;34m== " << x << " ==\033[0m\n"

int main()
{
    SECTION("1 · Default constructor");
    {
        Array<int> a;
        std::cout << (a.size() == 0 ? PASS : FAIL) << "size() == 0  ->  " << a.size() << "\n";
    }

    SECTION("2 · Array(n) + inicializacao por defeito");
    {
        Array<int> a(5);
        std::cout << (a.size() == 5 ? PASS : FAIL) << "size() == 5  ->  " << a.size() << "\n";
        bool allZero = true;
        for (unsigned int i = 0; i < a.size(); i++)
            if (a[i] != 0) { allZero = false; break; }
        std::cout << (allZero ? PASS : FAIL) << "Todos os elementos inicializados a 0\n";
    }

    SECTION("3 · operator[] leitura/escrita");
    {
        Array<int> a(3);
        a[0] = 10; a[1] = 20; a[2] = 30;
        std::cout << (a[0]==10 && a[1]==20 && a[2]==30 ? PASS : FAIL)
                  << a[0] << " " << a[1] << " " << a[2] << "\n";
    }

    SECTION("4 · Copy constructor (deep copy)");
    {
        Array<int> original(3);
        original[0] = 1; original[1] = 2; original[2] = 3;
        Array<int> copy(original);
        copy[0] = 99;
        std::cout << (original[0] == 1 ? PASS : FAIL)
                  << "copy[0]=99 nao afecta original[0]  ->  " << original[0] << "\n";
        original[1] = 88;
        std::cout << (copy[1] == 2 ? PASS : FAIL)
                  << "original[1]=88 nao afecta copy[1]  ->  " << copy[1] << "\n";
    }

    SECTION("5 · Assignment operator (deep copy)");
    {
        Array<int> a(3);
        a[0] = 7; a[1] = 8; a[2] = 9;
        Array<int> b;
        b = a;
        b[0] = 42;
        std::cout << (a[0] == 7 ? PASS : FAIL) << "b[0]=42 nao afecta a[0]  ->  " << a[0] << "\n";
        a[2] = 55;
        std::cout << (b[2] == 9 ? PASS : FAIL) << "a[2]=55 nao afecta b[2]  ->  " << b[2] << "\n";
    }

    SECTION("6 · Self-assignment");
    {
        Array<int> a(2);
        a[0] = 3; a[1] = 4;
        a = a;
        std::cout << (a[0]==3 && a[1]==4 ? PASS : FAIL) << a[0] << " " << a[1] << "\n";
    }

    SECTION("7 · Out-of-bounds lanca std::exception");
    {
        Array<int> a(3);
        try { a[3]; std::cout << FAIL "sem excepcao para index==size\n"; }
        catch (const std::exception &e) { std::cout << PASS "index==size: " << e.what() << "\n"; }

        try { a[1000]; std::cout << FAIL "sem excepcao para index grande\n"; }
        catch (const std::exception &e) { std::cout << PASS "index grande: " << e.what() << "\n"; }

        Array<int> empty;
        try { empty[0]; std::cout << FAIL "sem excepcao em array vazio\n"; }
        catch (const std::exception &e) { std::cout << PASS "array vazio: " << e.what() << "\n"; }
    }

    SECTION("8 · Template com double");
    {
        Array<double> d(4);
        d[0]=1.1; d[1]=2.2; d[2]=3.3; d[3]=4.4;
        bool ok = (d[0]==1.1 && d[1]==2.2 && d[2]==3.3 && d[3]==4.4);
        std::cout << (ok ? PASS : FAIL) << d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<"\n";
    }

    SECTION("9 · Template com std::string");
    {
        Array<std::string> s(3);
        s[0]="ola"; s[1]="mundo"; s[2]="!";
        std::cout << (s[0]=="ola" ? PASS : FAIL) << s[0]<<" "<<s[1]<<" "<<s[2]<<"\n";
        Array<std::string> copia(s);
        copia[0] = "alterado";
        std::cout << (s[0]=="ola" ? PASS : FAIL) << "deep copy string original[0]=" << s[0] << "\n";
    }

    SECTION("10 · size() e operator[] em instancia const");
    {
        const Array<int> ca(7);
        std::cout << (ca.size()==7 ? PASS : FAIL) << "const size()==7  ->  " << ca.size() << "\n";
        bool ok = true;
        for (unsigned int i = 0; i < ca.size(); i++)
            if (ca[i] != 0) { ok = false; break; }
        std::cout << (ok ? PASS : FAIL) << "const operator[] le 0 por defeito\n";
    }

    std::cout << "\nTodos os testes concluidos.\n";
    return 0;
}