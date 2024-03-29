 nhaplenh[30];
    int id, parent, child;
    while(1)
    {
        scanf("%s", nhaplenh);
        if(!strcmp(nhaplenh,"*")) break;
        if (!strcmp(nhaplenh, "MakeRoot"))
        {
            id = Data();
            root = MakeRoot(id);
        }

        if (!strcmp(nhaplenh, "Insert"))
        {
            child = Data();
            parent = Data();
            Insert_Tree(parent, child);
        }

        if (!strcmp(nhaplenh, "PreOrder"))
        {
            PreOder(root);
            printf("\n");
        }
        if (!strcmp(nhaplenh, "InOrder"))
        {
            InOrder(root);
            printf("\n");
        }
        if (!strcmp(nhaplenh, "PostOrder"))
        {
            PostOrder(root);
            printf("\n");
        }
    }