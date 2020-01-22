#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{
    for(int j = 0; j <= 5; ++j)
    {
        int check = std::pow(2,j);
        std::cout << "Das Paritätsbit " << check << " prüft die Bits: \n\t";
        for(int i = 1; i < 60; ++i)
        {
            if((i & check) != 0) std::cout << i << ", ";
        }
        std::cout << "\n";
    }
}
