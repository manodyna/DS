
void initlist(list *p)
{
    p->head = NULL;
}
void initlistm(listmove *p)
{
    p->head = NULL;
}
Node *getnode(int ele, int r, int c)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = ele;
    temp->link = NULL;
    temp->row_position = r;
    temp->column_postion = c;
    return temp;
}
Nodemove *getnodem(int r, int c)
{

    Nodemove *temp = (Nodemove *)malloc(sizeof(Nodemove));
    temp->rlink = NULL;
    temp->llink = NULL;
    temp->row_position = r;
    temp->column_postion = c;
    return temp;
}
void createMatrix(list *spm, int ele, int row, int column)
{

    Node *temp, *cur;
    cur = spm->head;
    temp = getnode(ele, row, column);

    if (spm->head == NULL)
    {
        spm->head = temp;
    }
    else
    {
        while (cur->link != NULL)
            cur = cur->link;
        cur->link = temp;
    }
}
void create(listmove *spm, int row, int column)
{

    Nodemove *temp = getnodem(row, column);
    Nodemove *cur = spm->head;
    if (cur == NULL)
    {
        spm->head = temp;
    }
    else if (cur->rlink == NULL)
    {
        temp->llink = cur;
        cur->rlink = temp;
    }
    else
    {
        while (cur->rlink != NULL)
            cur = cur->rlink;
        temp->llink = cur;
        cur->rlink = temp;
    }
}
void read(list *spm)
{
    FILE *ptr;
    ptr = fopen("input.txt", "r");
    if (ptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fscanf(ptr, "%d%d%d%d", &sr, &sc, &er, &ec);
    for (int i = 0; i < er + 1; i++)
    {
        for (int j = 0; j < ec + 1; j++)
        {
            char c;
            if (fscanf(ptr, " %c", &c) != 1)
                printf("…report read failure and exit…");
            else if (isdigit((unsigned char)c))
                sparseMatrix[i][j] = c - '0';
            else
                sparseMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < er + 1; i++)
    {
        for (int j = 0; j < ec + 1; j++)
        {

            if (sparseMatrix[i][j] != 0)
            {
                createMatrix(spm, 1, i, j);
            }
        }
    }
    fclose(ptr);
}
void delete_key(listmove *p, int r, int c)
{
    Nodemove *cur = p->head;

    if (p->head == NULL)
        printf("Empty list\n");
    else
    {
        while (cur != NULL)
        {
            if (cur->row_position == r && cur->column_postion == c)
            {
                Nodemove *temp = cur->rlink;
                if (cur == p->head)
                {
                    p->head = cur->rlink;
                    cur->rlink = NULL;
                    free(cur);
                }
                else if (cur->rlink == NULL)
                {
                    cur->llink->rlink = NULL;
                    cur->llink = NULL;
                    free(cur);
                }
                else
                {
                    cur->llink->rlink = cur->rlink;
                    cur->rlink->llink = cur->llink;
                    cur->llink = NULL;
                    cur->rlink = NULL;
                    free(cur);
                }
                cur = temp;
            }
            else
                cur = cur->rlink;
        }
    }
}
void movement(list *spm, listmove *move)
{
    int posr = 0, posc = 0;
    create(move, 0, 0);
    Nodemove *m = move->head;
    Node *t = spm->head;
    while (posr < (er + 1) && posc < (ec + 1))
    {
        if (posr == t->row_position && (posc + 1) == t->column_postion)
        {
            posr = posr + 1;
            while (t->row_position != posr)
            {
                t = t->link;
            }
            while (t->column_postion < posc)
            {
                t = t->link;
            }
            if ((t->row_position == posr) && (t->column_postion == posc))
            {
                m = m->llink;
                delete_key(move, posr - 1, posc);
                posc = m->column_postion - 1;
            }
            else
            {
                posc = posc - 1;
            }
        }
        else if ((posc + 1) == ec && posr != t->row_position)
        {
            posr = posr + 1;
            while (t->row_position != posr)
            {
                t = t->link;
            }
            while (t->column_postion < posc)
            {
                t = t->link;
            }
            posc = t->column_postion - 1;
        }
        posc = posc + 1;
        create(move, posr, posc);
        m = move->head;
        while (m->rlink != NULL)
        {
            m = m->rlink;
        }
        if (posr == er && posc == ec)
        {
            display(move);
            break;
        }
    }
    if (posr > er && posc > ec)
    {
        FILE *ptr = fopen("out.txt", "w");
        fprintf(ptr, "%d", -1);
        fclose(ptr);
    }
}
void display(listmove *spm)
{
    Nodemove *cur = spm->head;
    FILE *ptr = fopen("out.txt", "w");
    while (cur != NULL)
    {
        fprintf(ptr, "%d %d\n", cur->row_position, cur->column_postion);
        cur = cur->rlink;
    }
    fclose(ptr);
}
