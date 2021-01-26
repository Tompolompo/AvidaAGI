#include <iostream>
#include <unistd.h>

using namespace std;

int str2int(const char *s){
    int res = 0;
    while (*s) {
        res *= 10;
        res += *s++ - '0';
    }
    return res;
}

int main(int argc, char **argv)  {

    // Parse cmd-line arguments
    int universe_settings[4];
    int opt; 
    
    cout << "***** 1" << endl;
    while((opt = getopt(argc, argv, "n:m:u:d:")) != -1)
    {  
        switch(opt) {   
            case 'n':
                universe_settings[0] = atoi(optarg); // must be even number
                break;  
            case 'm':  
                universe_settings[1] = atoi(optarg);
                break; 
            case 'u':  
                universe_settings[2] = atoi(optarg);
                break; 
            case 'd':  
                universe_settings[3] = atoi(optarg);
                break;
            case '?':  
                printf("'%c': Not a valid option\n",optopt); 
                abort();
        }
    }
    cout << "**** 2" << endl;
    for (int index = optind, i = 0; index < argc; index++, i++)   {
        printf ("Non-option argument %s\n", argv[index]);
        argv[i] = argv[index];
    }

    char * argv_new[1];
    argv_new[0] = argv[0];
    argc = 1;
    cout << "**** 3" << endl;


    cout << "argv_new = " << argv_new[0] << endl;
    cout << "set_0 = " << universe_settings[0] << endl;
    cout << "set_1 = " << universe_settings[1] << endl;
    cout << "set_2 = " << universe_settings[2] << endl;
    cout << "set_3 = " << universe_settings[3] << endl;

    universe_settings[0] = str2int(argv[1]); // Number of worlds, even number
    universe_settings[1] = str2int(argv[2]); // N meta generations
    universe_settings[2] = str2int(argv[3]); // Number of updates
    universe_settings[3] = 9; // dangerous op
    cout << "**** 4" << endl;




}