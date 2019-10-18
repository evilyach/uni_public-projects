#ifndef LIST_H
#define LIST_H

#define EXIT_OK         0   //! Успешный выход
#define EXIT_FAILURE    1   //! Неизвестная ошибка
#define EXIT_VALERROR  -1   //! Ошибка значения
#define EXIT_POSERROR  -2   //! Ошибка расположения
#define EXIT_USEERROR  -3   //! Ошибка использования
#define EXIT_DELEMPTY  -4   //! Ошибка удаления из пустого списка
#define EXIT_DELNFOUND -5   //! Ошибка поиска удаляемого элемента
#define EXIT_ITEREND   -10  //! Конец работы итератора


/*!
 * \brief Узел списка
 *
 * Описание класса Node для связанного списка.
 */
class Node
{
public:
    int value;
    Node *next;

    //! Конструктор без указания значения
    Node(): value(0), next(nullptr) {}
    //! Конструктор с указанием значения переменной типа int
    Node(int x): value(x), next(nullptr) {}
};


/*!
 * \brief Односвязный кольцевой список
 *
 * Описание класса List для односвязного кольцевого списка.
 */
class CircularSinglyLinkedList
{
public:
    //! Конструктор
    CircularSinglyLinkedList(): Head(nullptr), Tail(nullptr), size(0) {}
    //! Деструктор
    ~CircularSinglyLinkedList() { clear(); }

    /*!
     * \brief Метод очищения списка
     *
     * \return EXIT_OK
     */
    int clear();

    /*!
     * \brief Метод добавления элемента в конец списка
     *
     * \param x - значение нового элемента
     *
     * \return EXIT_OK
     */
    int addAtEnd(int x);

    /*!
     * \brief Метод добавление элемента вслед за k-ым
     *
     * \param position - позиция, вслед за которой необходимо вставить элемент
     * \param x - значение нового элемента
     *
     * \return EXIT_OK в случае успеха
     * \return EXIT_POSERROR в случае недопустимого значения pos
     */
    int addAfter(int position, int x);

    /*!
     * \brief Метод удаления элемента из списка
     *
     * \param x - значение удаляемого элемента
     *
     * \return EXIT_OK
     */
    int remove(int x);

    //! Метод получения размера списка
    int getSize() const { return size; }
    //! Метод изменения размера списка
    void setSize(int new_size) { size = new_size; }
    //! Метод проверки списка на пустоту
    bool isEmpty() const { return (size == 0); }
    //! Метод проверки списка на цикличность
    bool isCircular();
    //! Метод получания головы списка
    Node *begin() const { return Head; }
    //! Метод получения хвоста списка
    Node *end() const { return Tail; }

private:
    Node *Head; /*! Указатель на голову списка */
    Node *Tail; /*! Указатель на хвост списка */
    int size;         /*! Размер списка */
};

#endif // LIST_H
