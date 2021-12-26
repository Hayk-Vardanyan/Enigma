#include "cub2.h"

void Cube::incode (std::string input_str) {
    
    std::string tmp;
    for(int i = 0; i < input_str.size(); ++i)
    {
        separator.push_back(input_str.substr(0, Constants::vertex));
        input_str.erase(0, 8);
    }
    separator.push_back(input_str);
}

std::string Cube::code() {
     
    std::string tmp;
    for(int i = 0; i < separator.size(); ++i) {
        rotate_left(i);
        rotate_up(i);
        tmp += std::to_string(i) + "D:R ";
    } 
   std::cout << "HERE IS YOUR ENCRYPED TEXT -> ";
   for(int i = 0; i < separator.size(); ++i){
        std::cout << separator[i];
    }
    std::cout << '\n';
    return tmp;
}   

std::string Cube::decode(const std::string& key) {
    
    std::string return_value;
    int index = 0;
    for(int i = 0; i < key.size(); ++i) {
      

    if(key[i]  >= '0' && key[i]  <= '9')
    {
        index = key[i] - '0';  // "casting" char to int 
    }

    else if(key[i] == Constants::down)
    {
        rotate_down(index);
    }

    else if(key[i] == Constants::up)
    {
        rotate_up(index);
    }
       
        else if(key[i] == Constants::right)
    {
        rotate_right(index);
    }

        else if(key[i] == Constants::left)
    {
        rotate_left(index);
    }
    

    }  

    
    std::cout << "HERS IS YOUR DECODED TEXT ->  ";

    for(int i = 0; i < separator.size(); ++i) {
        return_value += separator[i];
        std::cout << separator[i];
    }
    return return_value;
}

void Cube::rotate_left(int current_cube) {
    
    char tmp = separator[current_cube][0];
    char tmpp = separator[current_cube][3];
    separator[current_cube][0] = separator[current_cube][1];
    separator[current_cube][1] = separator[current_cube][5];
    separator[current_cube][5] = separator[current_cube][4];
    separator[current_cube][4] = tmp;
    separator[current_cube][3] = separator[current_cube][2];
    separator[current_cube][2] = separator[current_cube][6];
    separator[current_cube][6] = separator[current_cube][7];
    separator[current_cube][7] = tmpp;
}

void Cube::rotate_right(int current_cube) {
    
    char tmp = separator[current_cube][0];
    char tmpp = separator[current_cube][3];
    separator[current_cube][0] = separator[current_cube][4];
    separator[current_cube][4] = separator[current_cube][5];
    separator[current_cube][5] = separator[current_cube][1];
    separator[current_cube][1] = tmp;
    separator[current_cube][3] = separator[current_cube][7];
    separator[current_cube][7] = separator[current_cube][6];
    separator[current_cube][6] = separator[current_cube][2];
    separator[current_cube][2] = tmpp;
}

void Cube::rotate_up(int current_cube) {
    
    char tmp = separator[current_cube][0];
    char tmpp = separator[current_cube][1];
    separator[current_cube][0] = separator[current_cube][3];
    separator[current_cube][3] = separator[current_cube][7];
    separator[current_cube][7] = separator[current_cube][4];
    separator[current_cube][4] = tmp;
    separator[current_cube][1] = separator[current_cube][2];
    separator[current_cube][2] = separator[current_cube][6];
    separator[current_cube][6] = separator[current_cube][5];
    separator[current_cube][5] = tmpp;
}

void Cube::rotate_down(int current_cube) {
    
    char tmp = separator[current_cube][0];
    char tmpp = separator[current_cube][1];
    separator[current_cube][0] = separator[current_cube][4];
    separator[current_cube][4] = separator[current_cube][7];
    separator[current_cube][7] = separator[current_cube][3];
    separator[current_cube][3] = tmp;
    separator[current_cube][1] = separator[current_cube][5];
    separator[current_cube][5] = separator[current_cube][6];
    separator[current_cube][6] = separator[current_cube][2];
    separator[current_cube][2] = tmpp;
} 


int main()
{
   Cube c;
   c.incode("New Year");
   c.decode(c.code());
}



