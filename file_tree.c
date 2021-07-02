struct myfile
{
    char name[50];
    struct value
    {
        char name[50];
        char type[10];
        int var_line;
        char filename[50];
    };

    struct func {
        char name[50];
        vector <struct value>par;
        vector<struct value>var;
        struct func* p_infunc;
        int fuc_line;

        
    };
    vector<struct value>value_list;
    vector<struct my_file*>file_list_tree;
};
