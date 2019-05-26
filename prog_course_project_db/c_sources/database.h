#ifndef курсовой_проект_database_h
#define курсовой_проект_database_h

#include "main.h"

// Вспомогательные типы данных
enum gender_t               // Перечисление "Пол"
{
    male = 0,               // Мужской
    female = 1              // Женский
};

typedef struct date_t       // Структура "Дата"
{
    unsigned day;           // День
    unsigned month;         // Месяц
    unsigned year;          // Год
} date;


// Основные структуры
typedef struct employee_t   // Структура "Сотрудники"
{
    int employee_id;		// Код сотрудника
    int position_id;		// Код должности

    char name[255];         // ФИО
    unsigned age;           // Возраст
    enum gender_t gender;   // Пол
    char address[255];      // Адрес
    char phone[20];         // Телефон
    char passport[20];      // Паспортные данные
} employee_struct;

typedef struct position_t   // Структура "Должности"
{
    int position_id;		// Код должности

    char name[255];         // Наименование
    unsigned salary;		// Оклад
    char duties[255];       // Обязанности
    char requirements[255]; // Требования
} position_struct;

typedef struct brand_t		// Структура "Марки автомобилей"
{
    int brand_id;			// Код марки

    char name[255];			// Наименование
    char specs[255];		// Технические характеристики
    char description[255];	// Описание
} brand_struct;

typedef struct service_t	// Структура "Дополнительные услуги"
{
    int service_id;			// Код услуги

    char name[255];			// Наименование
    char description[255];	// Описание
    int price;				// Цена
} service_struct;

typedef struct car_t		// Структура "Автомобили"
{
    int car_id;				// Код автомобиля
    int brand_id;			// Код марки
    int employee_id;		// Код сотрудника-механика

    unsigned reg_number;	// Регистрационный номер
    unsigned body_number;	// Номер кузова
    unsigned engine_number;	// Номер двигателя
    unsigned release_year;	// Год выпуска
    unsigned mileage;		// Пробег
    int price;				// Цена автомобиля
    int rent_price;			// Цена дня проката
    date maintenance_date;	// Дата последнего ТО
    char special_marks[255];// Специальные отметки
    char return_mark[255];	// Отметка о возврате
} car_struct;

typedef struct client_t		// Структура "Клиенты"
{
    int client_id;			// Код клиента

    char name[255];			// ФИО
    enum gender_t gender;	// Пол
    date birth_date;		// Дата рождения
    char address[255];		// Адрес
    char phone[20];			// Телефон
    char passport[20];		// Паспортные данные
} client_struct;

typedef struct rent_t		// Структура "Прокат"
{
    int car_id;				// Код автомобиля
    int client_id;			// Код клиента
    int employee_id;		// Код сотрудника
    int service1_id;		// Код услуги 1
    int service2_id;		// Код услуги 2
    int service3_id;		// Код услуги 3

    date delivery_date;		// Дата выдачи
    unsigned rent_time;		// Срок проката
    date return_date;		// Дата возврата
    int rent_price;			// Цена проката
    char payment_mark[255];	// Пометка об оплате
} rent_struct;

// Таблицы базы данных
employee_struct	*employee_table;
position_struct	*position_table;
brand_struct	*brand_table;
service_struct	*service_table;
car_struct		*car_table;
client_struct	*client_table;
rent_struct		*rent_table;

#endif //курсовой_проект_database_h