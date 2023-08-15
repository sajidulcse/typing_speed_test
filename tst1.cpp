#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Clock starts running, user is prompted to enter the text on-screen
    clock_t start, end;
    start = clock(); // Captures the current clock time and clock starts

    cout << "Enter the following text as much as you can and as fast as you can: \n\n";

    string user_input_string; // user input string
    string text_from_file;    // string loaded from file
    ifstream myfile("test.txt"); // reads data from test.txt and puts in myfile.

    if (myfile.is_open()) // checks if the file is open or not open
    {
        while (getline(myfile, text_from_file)) // read the entire line from the file
        {
            cout << text_from_file << endl; // shows the text from file
        }
        myfile.close(); // close the input file

        // Code for data input, clock still running, this and above are visible to user from the start-up of the program
        cout << "\n";
        getline(cin, user_input_string); // takes input from user

        end = clock(); // Clock ends running, data gathered is displayed to user

        double seconds = (double)(end - start) / CLOCKS_PER_SEC; // calculating how many seconds by dividing the clock time by cpu clock per second
        cout << "\nTyping the text took " << seconds << " seconds.\n\n";

        // Calculate typing speed and words per minute
        double typing_speed = (user_input_string.size() / 5.0) / (seconds / 60.0);
        cout << "Your typing speed is " << typing_speed << " words per minute.\n\n";

        int error = 0;
        for (int i = 0; i < user_input_string.size(); i++)
        {
            if (i >= text_from_file.size() || text_from_file[i] != user_input_string[i])
                error++;
        }

        float accuracy = ((user_input_string.size() - error) / static_cast<float>(user_input_string.size())) * 100.0;
        cout << fixed << setprecision(2); // to show 2 decimal points
        cout << "Your typing accuracy is " << accuracy << " %\n\n";
    }
    else
    {
        cout << "Unable to open the file.\n";
    }

    system("PAUSE"); // pause for a character input
    return EXIT_SUCCESS; // program terminated successfully
}
