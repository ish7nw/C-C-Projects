/*
 Name: Ishan 
 Version: 9
 */

// all the header files
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>

// declaring array column and row size using constants
const int ARRAY_ROWS = 5;
const int ARRAY_COLUMNS = 5;

// array declaration
int randomNumberArray[ARRAY_ROWS][ARRAY_COLUMNS];

// because of differences of OS, using this to give pauses in the system
std::string resume;


// function prototyping
void runMenu();
void displayText(std::string fileName);
void stringAnalyser();
void generateArray();
void fillArray();
void printArray();
void largestCorner();
void resetAntiDiagonal();
void flipDie();
void saveData();
std::string getData();
void saveDataToFile(std::string message);
void bonus();



int main(){

    runMenu();

    return 0;

}



// function to call all the other functions
void runMenu(){


    int userOpt;

    do
    {


        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "\tProgramming Fundamental Concepts\n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "\n";
        std::cout << "[1].  Display  Information\n";
        std::cout << "[2].  String Analyser\n";
        std::cout << "[3].  Generate Random Array, Dispay The Mean And Reset Anti-Diagonal\n";
        std::cout << "[4].  Flip A Die Game\n";
        std::cout << "[5].  Save Message To File\n";
        std::cout << "[6].  Bonus\n";
        std::cout << "[7].  Exit\n";
        std::cout << "\n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "\n";
        std::cout << "Which option would you like (1-7): ";
        std::cin >> userOpt;
        std::cin.clear();
        std::cin.ignore();

        if (userOpt == 1)
        {
            std::string fileName = "About.txt";

            displayText(fileName);
        }

        else if(userOpt == 2)
        {
            stringAnalyser();
        }

        else if(userOpt == 3)
        {
            generateArray();
        }

        else if(userOpt == 4)
        {
            flipDie();
        }

        else if(userOpt == 5)
        {
            saveData();
        }
        else if(userOpt == 6)
        {
            bonus();
        }

        else if(userOpt == 7)
        {
            std::cout << "Thank you for testing our program\n";
            break;
        }

        else
        {
            std::cout << "There is no option such as " << userOpt << " please try again!\n";
        }


    }
    while(userOpt!=7);






}



// function that will read from the file and output to the terminal
void displayText(std::string fileName){

    // objects used to perform file operations
    std::ifstream  fileManager;
    std::string fileReader;

    // opening the file
    fileManager.open(fileName);

    // checking if it worked

    if(fileManager.is_open() == true)
    {
        // looping untill the file ends and copying the data from the file to the object
        while(fileManager.eof() == false)
        {
            // printing the data in the terminal
            std::getline(fileManager, fileReader);
            std::cout << fileReader << std::endl;
        }
    }
    else
    {
        std::cout << "Can not find the file that you are looking for.\n";
    }

    // closing the file
    fileManager.close();

    // substitute of system pause because of mac
    std::cout << "\nPress enter to continue...\n";
    std::getline(std::cin, resume);



}


// string analyser function to perform the actions on the string

void stringAnalyser(){


    std::cin.clear();
    // variables that will be needed
    std::string userName;
    std::string userString;
    std::string userUpperString;
    char userCharacter;
    int indexOfUserCharacter;
    int userStringLength;
    int userStringMiddleIndex;


    // getting the name of the user and displaying it
    std::cout << "Hi there! What is your name: ";
    std::getline(std::cin, userName);

    std::cout << "Hi! " << userName << std::endl;


    // getting the string from the user on which the operations will be performed
    std::cout << "Please enter the string: ";
    std::getline(std::cin, userString);


    // getting the character from the user that will be found inside the string
    std::cout << "Please enter the character: ";
    std::cin >> userCharacter;


    // just to make the output look clean
    std::cout << std::endl;

    std::cout << "The string you entered was: " << userString << std::endl;


    // checking if the character exists in the string or not

    if(userString.find(userCharacter)< userString.length())
    {
        indexOfUserCharacter = userString.find(userCharacter);
        std::cout << "\t\ta.The index of the first occurence of " << userCharacter << " is: " << indexOfUserCharacter << std::endl;
    }
    else
    {
        std::cout << "\t\ta. Character not found." << std::endl;
    }

    // replacing all the letters to uppercase using ascii and for loop (small char - 32 = upper)
    for(int character = 0; character < userString.length(); character++)
    {
        // checking if the character is a lower alphabet
        if(userString[character] >= 97 && userString[character]<=  122)
        {
            userString[character] -= 32;
        }

        // if the character is a space
        if(userString[character] == 32)
        {
            userString[character] -= 0;
        }
    }

    std::cout << "\t\tb. The string after replacing all the letters to uppercase is: " << userString << std::endl;


    // replacing the middle character of the string with the first character of the name of user

    userStringLength = userString.length();
    userStringMiddleIndex = userStringLength / 2;
    userString[userStringMiddleIndex] = userName[0];

    std:: cout << "\t\tc. The string after replacing the middle letter is: " << userString << std::endl
               << "\t\tand the length of the string is: " << userStringLength << std::endl << std::endl;




    // substitute of system pause because of mac
    std::cout << "\nPress enter to continue...\n";
    std::getline(std::cin, resume);
}

// function to perform the array operations

void generateArray(){

    fillArray();
    printArray();
    largestCorner();
    resetAntiDiagonal();


}


// function to fill the array with random values between 10 and 50

void fillArray(){

    // seeding random
    srand(unsigned(time(NULL)));

    // looping through each element of the array to fill it with random values between 10 and 50

    for(int rowCounter = 0; rowCounter < ARRAY_ROWS; rowCounter++)
    {
        for(int columnCounter = 0; columnCounter < ARRAY_COLUMNS; columnCounter++)
        {
            randomNumberArray[rowCounter][columnCounter] = rand()%41 +10;
        }
    }

}


// function to print the array

void printArray(){

    std::cout << "The elements of the array are:\n";

    for(int i = 0; i < ARRAY_ROWS; i++)
    {
        for(int j = 0; j < ARRAY_COLUMNS; j++)
        {
            std::cout << randomNumberArray[i][j] << "\t";
        }
        std::cout << std::endl;

    }
}


// function to find the biggest corner

void largestCorner(){

    // it is a 5x5 array so the corners will be

    int firstCorner = randomNumberArray[0][0];
    int secondCorner = randomNumberArray[0][4];
    int thirdCorner = randomNumberArray[4][0];
    int fourthCorner = randomNumberArray[4][4];


    // setting the maximum corner to first one and then comparing the other corners to find the max corner

    int largestCorner = firstCorner;

    if(secondCorner > largestCorner)
    {
        largestCorner = secondCorner;
    }

    else if(thirdCorner > largestCorner)
    {
        largestCorner = thirdCorner;
    }

    else if(fourthCorner > largestCorner)
    {
        largestCorner = fourthCorner;
    }

    else
    {
        largestCorner = firstCorner;
    }


    std::cout << "The maximum value among the four corners is: " << largestCorner << std::endl;

}


// function to reset the array's anti diagonal

void resetAntiDiagonal(){

    // the elements of the anti-diagonal will always be having the sum of their indices as length of array - 1, 4 in this case

    for(int rowCounter = 0; rowCounter < ARRAY_ROWS; rowCounter++)
    {
        for(int columnCounter = 0; columnCounter < ARRAY_COLUMNS; columnCounter++)
        {
            if(rowCounter + columnCounter == 4)
            {
                randomNumberArray[rowCounter][columnCounter] = 0;
            }
        }
    }

    std::cout << std::endl << "After resetting the anti-diagonal, ";
    printArray();

    // substitute of system pause because of mac
    std::cin.clear();
    std::cout << "\nPress enter to continue...";
    std::getline(std::cin, resume);

}


void flipDie(){

    // seeding random
    srand(unsigned(time(NULL)));

    int randInt = rand()%8 +1;
    std::string userGuess;

    std::cout << "A die of 8 sides has been rolled - - Guess the side: \n";
    std::cout << "Is it even or odd [o/e]: ";
    std::cin >> userGuess;


    // converting the user input to lowercase
    for(int character = 0; character < userGuess.length(); character++)
    {
        if(userGuess[character] >= 65 && userGuess[character] <= 90)
        {
            userGuess[character] += 32;
        }
        else
        {
            userGuess[character] += 0;
        }
    }

    // checking if the user got the correct guess or not

    if(randInt % 2 == 0 && (userGuess == "even" || userGuess == "e"))
    {
        std::cout << "Well done! That is correct, you guessed it even and it was even, the value was: " << randInt << std::endl;
    }

    else if(randInt % 2 == 0 && (userGuess == "odd" || userGuess == "o"))
    {
        std::cout << "Wrong! You guessed it odd, it was even, the value was: " << randInt << std::endl;
    }
    else if(randInt % 2 != 0 && (userGuess == "odd" || userGuess == "o"))
    {
        std::cout << "Well done! That is correct, you guessed it odd and it was odd, the value is: " << randInt << std::endl;
    }
    else if(randInt % 2 != 0 && (userGuess == "even" || userGuess == "e"))
    {
        std::cout << "Wrong! You guessed it even, it was odd, the value was: " << randInt << std::endl;
    }
    else
    {
        std::cout << "Invalid argument!\n";
    }


    // substitute of system pause because of mac
    std::cin.ignore();
    std::cin.clear();
    std::cout << "\nPress enter to continue...";
    std::getline(std::cin, resume);

}

// fucntion to get info from user, summarise it and store it in a file accorsing to user choice

void saveData(){

    std::string message = getData();
    saveDataToFile(message);

}


std::string getData(){

    std::string userTitle;
    std::string userName;
    std::string userLocation;
    int userLivingSince;
    std::string userOption;

    std::cout << "Preferred Title: ";
    std::cin >> userTitle;
    std::cin.ignore(); // To clear the newline character from the input buffer

    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);

    std::cout << "Where do you live: ";
    std::getline(std::cin, userLocation);

    std::cout << "For how many years have you been in " << userLocation << ": ";
    std::cin >> userLivingSince;
    std::cin.ignore(); // To clear the newline character from the input buffer

    int yearOfArrival = 2024 - userLivingSince;

    std::string message = "Hi " + userTitle + " " + userName + ", you live in " + userLocation + " since " +
                          std::to_string(yearOfArrival) + ". It is a beautiful city.\n";

    std::cout << "\nThis is the message: \n" << message << std::endl;

    return message;
}

void saveDataToFile(std::string message){


    std::string userOption;

    std::cout << "Do you want to save this message to a file (y/n): ";
    std::cin >> userOption;

    // converting the user input to lowercase
    for(int character = 0; character < userOption.length(); character++)
    {
        if(userOption[character] >= 65 && userOption[character] <= 90)
        {
            userOption[character] += 32;
        }
        else
        {
            userOption[character] += 0;
        }
    }


    // if the user wants to save this message in this file, then we will create the file stream object
    if(userOption == "yes" || userOption == "y")
    {
        std::string fileName = "savedMessages.txt";
        std::ofstream fileManager;

        // create a file called savedMessages.txt
        fileManager.open(fileName, std::ios::app);

        //checking if the file got open and then performing the action
        if(fileManager.is_open() == true)
        {
            fileManager << message;
            std::cout << "The message is saved in: " << fileName << std::endl;
        }

        else
        {
            std::cout << "Can not find the file that you are looking for!\n";

            // closing the file
            fileManager.close();
        }
    }

    else if(userOption == "no" || userOption == "n")
    {
        std::cout << "You opted not to save the message.\n";
    }

    else
    {
        std::cout << "Invalid Argument!\n";
    }



}

void bonus(){
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
}

