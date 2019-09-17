Project Discription
*********************************************************
This project is a tweet conversion application. 
Using this application, you can import a string which is converted into an acceptable tweet(string with no more than 140 characters) from a set of pre-defined dictionary stored in the file "Words.txt".
After conversion, the application will ask the user if he wants to log the conversion. A conversion log file, "Conversion Log.txt" has been created which shows the previous logged conversions.

This application can also be used to add new words to the dictionary. 
After adding to the dictionary, the user can save it and then load the contents of the dictionary to be used during the conversion of further conversations.





Building the application
*********************************************************
Follow these steps to run the application:
1. Run 'make' on the command line. This will build the project and produce an executable file "main.exe".
2. Run 'main.exe Words.txt' on the command line. This will run the application along with importing the tweet dictionary.
3. To re-build the application, run 'make clean'. This will clear the executable file and all the object(.o) files created. Run 'make' again.




Project Dependencies
*********************************************************
Here is a list of functions and libraries used to create the application:
1. Source code(src)- main.c,Tweet.c
2. Header files(include)- dict.h, string.h, struct.h, Tweet.h
3. Libraries(lib)- lib_dictionary, lib_string
4. txt- Conversion Log.txt, Words.txt