/*
Author: Ishan
Date: 30th June 2024
Description: Simple guess the password game using selections and iteration.
Ver: 0.2
*/



#include<iostream>
#include<string>

int main(){

    std::string password = "hahayouwillneverguessthepasswordandifyoudidthencongrats!";
    std::string guess;
    int attempt = 1;

    std::cout << "GUESS THE PASSWORD GAME!" << std::endl<< std::endl<< std::endl;
    std::cout << "You get only five lives"<< std::endl<< std::endl<< std::endl;


    std::cout << "What is the password: ";
    std::cin >> guess;

    do
    {
    std::cout << "Wrong Password Counter: " << attempt  << std::endl << std::endl;
    std::cout << "What is the password: ";
    std::cin >> guess;
    attempt++;

    if(attempt == 4)
    {
        std::cout << "You have entered the wrong password " << attempt << " times! This is your last chance or system will be locked." 
        << std::endl;
    }

    if(attempt == 5)
    {
        std::cout << "SYSTEM LOCKED!" << std::endl;
    }

    if(guess == password)
    {
        std::cout << "CORRECT! You have guessed the password after " << attempt <<  " tries" << std::endl;
    }

   
 }
 while(guess!= password && attempt<5);

    return 1;


}