#include "shell.h"
/**
 * add_node - adds the node to start the list
 * @head: will address the pointer of the head node
 * @str: string the field of the node
 * @num: node ind uses by the histories
 *
 * Return: sizes of the list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
        list_t *new_d;
        if (!head)
                return (NULL);
        new_d = malloc(sizeof(list_t));
        if (!new_d)
                return (NULL);
        _memset((void *)new_d, 0, sizeof(list_t));
        new_d->num = num;
        if (str)
        {
                new_d->str = _strdup(str);
                if (!new_d->str)
                {
                        free(new_d);
                        return (NULL);
                }
        }
        new_d->next = *head;
        *head = new_d;
        return (new_d);
}
/**
 * add_node_end – adds the node of the end of list
 * @head: this addresses the pointer of the head node
 * @str: string field of the node
 * @num: node ind used the history
 *
 * Return: sizes of the list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
        list_t *new_e, *e;
        if (!head)
                return (NULL);
        e = *head;
        new_e = malloc(sizeof(list_t));
        if (!new_e)
                return (NULL);
        _memset((void *)new_e, 0, sizeof(list_t));
        new_e->num = num;
        if (str)
        {
                new_e->str = _strdup(str);
                if (!new_e->str)
                {
                        free(new_e);
                        return (NULL);
                }
        }
        if (e)
        {
                while (e->next)
                        e = e->next;
                e->next = new_e;
        }
        else
                *head = new_e;
        return (new_e);
}
/**
 * print_list_str – prints this if only the string elem of the  list_t list
 * @h: pointers of the first node
 *
 * Return: sizes of the list
 */
size_t print_list_str(const list_t *h)
{
        size_t y = 0;
        while (h)
        {
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                y++;
        }
        return (y);
}
/**
 * delete_node_at_index – deletes the nodes at a given ind
 * @head: addresses the pointer of first node
 * @index: ind of the node to be deleted
 *
 * Return: one if successful, else zero 
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
        list_t *de, *prev_node;
        unsigned int y = 0;
        if (!head || !*head)
                return (0);
        if (!index)
        {
                node = *head;
                *head = (*head)->next;
                free(node->str);
                free(de);
                return (1);
        }
        node = *head;
        while (de)
        {
                if (y == index)
                {
                        prev_node->next = node->next;
                        free(node->str);
                        free(de);
                        return (1);
                }
                y++;
                prev_node = de;
                de = node->next;
        }
        return (0);
}
/**
 * free_list - frees the nodes of the list
 * @head_ptr: addresses the pointer to the head node
 *
 * Return: null
 */
void free_list(list_t **head_ptr)
{
        list_t *ne, *next_node, *hd;
        if (!head_ptr || !*head_ptr)
                return;
        hd = *head_ptr;
        ne = hd;
        while (ne)
        {
                next_node = node->next;
                free(node->str);
                free(ne);
                ne = next_node;
        }
        *head_ptr = NULL;
}

