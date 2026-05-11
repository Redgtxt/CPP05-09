#include "../inc/BitcoinExchange.hpp"

/*
    [X]• Your program must take a file as an argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.


Your program will use the value in your input file.
Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your databas
*/

int main(int argc,char *argv[])
{
    try
    {
        if(argc != 2)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        //Vou verificar se e um ficheiro
        /*
            Verificar se e um ficheiro
            Se tem permissoes para abrir
            Se nao esta vazio
        */

        BitcoinExchange btc;

        btc.CheckFile(argv[1]);

    }
    catch(const std::exception& e)    {
            std::cerr << e.what() << '\n';
        } 
}