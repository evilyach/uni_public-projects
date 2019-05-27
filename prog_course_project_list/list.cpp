#include "list.h"
#include <limits>

int CircularSinglyLinkedList::clear()
{
    if (Head != nullptr) {
        Node *temp = Head;
        for (int i = 0; i < getSize(); i++) {
            Node *help = temp;
            temp = temp->next;
            delete help;
        }
        Head = nullptr;
        Tail = nullptr;
        setSize(0);
    }

    return EXIT_OK;
}

int CircularSinglyLinkedList::addAtEnd(int x)
{
    Node *temp = new Node;
    temp->next = Head;      // Замыкание контура
    temp->value = x;

    if (Head != nullptr) {  // Если список не пустой
        Tail->next = temp;
        Tail = temp;
    } else {                // Если список пустой
        Head = temp;
        Tail = temp;
    }

    size++;

    return EXIT_OK;
}

int CircularSinglyLinkedList::addAfter(int position, int x)
{
    if (position < 0 or position > getSize())
        return EXIT_POSERROR;

    Node *temp = new Node;
    temp->value = x;

    if (Head == nullptr) {          // Если список пустой
        Head = temp;
        Tail = Head;
        Head->next = Head;
    } else {                        // Если не пустой
        if (position == 0) {        // Если в начале
            temp->next = Head;
            Tail->next = temp;
            Head = temp;
        } else {                    // Если не в конце
            if (position < getSize()) {
                Node *help = Head;

                for (int i = 0; i < position-1; i++)
                    help = help->next;
                temp->next = help->next;
                help->next = temp;
            } else {                // Если в конце
                Tail->next = temp;
                temp->next = Head;
                Tail = temp;
            }
        }
    }
    size++;

    return EXIT_OK;
}

int CircularSinglyLinkedList::remove(int x)
{
    if (Head == nullptr)
        return EXIT_DELEMPTY;

    // Поиск узла
    Node *current = Head;
    Node *prev = new Node;

    while (current->value != x) {
        if (current->next == Tail)
            return EXIT_DELNFOUND;

        prev = current;
        current = current->next;
    }

    // Если в списке один элемент
    if (current->next == Head) {
        Head = nullptr;
        size--;
        return EXIT_OK;
    }

    // Если в списке больше одного элемента
    if (current == Head) {          // Если это первый узел
        prev = Tail;
        Head = current->next;
        size--;
        return EXIT_OK;
    } else if (current == Tail) {   // Если это последний узел
        prev->next = Tail;
        size--;
        return EXIT_OK;
    } else {
        prev->next = current->next;
        size--;
        return EXIT_OK;
    }

    return EXIT_FAILURE;
}

bool CircularSinglyLinkedList::isCircular()
{
    if (Head == nullptr)
        return true;

    Node *node = Head->next;

    while (node != nullptr and node != Head)
        node = node->next;

    return node == Head;
}
