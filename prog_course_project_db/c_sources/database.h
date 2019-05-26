#ifndef ��������_������_database_h
#define ��������_������_database_h

#include "main.h"

// ��������������� ���� ������
enum gender_t               // ������������ "���"
{
    male = 0,               // �������
    female = 1              // �������
};

typedef struct date_t       // ��������� "����"
{
    unsigned day;           // ����
    unsigned month;         // �����
    unsigned year;          // ���
} date;


// �������� ���������
typedef struct employee_t   // ��������� "����������"
{
    int employee_id;		// ��� ����������
    int position_id;		// ��� ���������

    char name[255];         // ���
    unsigned age;           // �������
    enum gender_t gender;   // ���
    char address[255];      // �����
    char phone[20];         // �������
    char passport[20];      // ���������� ������
} employee_struct;

typedef struct position_t   // ��������� "���������"
{
    int position_id;		// ��� ���������

    char name[255];         // ������������
    unsigned salary;		// �����
    char duties[255];       // �����������
    char requirements[255]; // ����������
} position_struct;

typedef struct brand_t		// ��������� "����� �����������"
{
    int brand_id;			// ��� �����

    char name[255];			// ������������
    char specs[255];		// ����������� ��������������
    char description[255];	// ��������
} brand_struct;

typedef struct service_t	// ��������� "�������������� ������"
{
    int service_id;			// ��� ������

    char name[255];			// ������������
    char description[255];	// ��������
    int price;				// ����
} service_struct;

typedef struct car_t		// ��������� "����������"
{
    int car_id;				// ��� ����������
    int brand_id;			// ��� �����
    int employee_id;		// ��� ����������-��������

    unsigned reg_number;	// ��������������� �����
    unsigned body_number;	// ����� ������
    unsigned engine_number;	// ����� ���������
    unsigned release_year;	// ��� �������
    unsigned mileage;		// ������
    int price;				// ���� ����������
    int rent_price;			// ���� ��� �������
    date maintenance_date;	// ���� ���������� ��
    char special_marks[255];// ����������� �������
    char return_mark[255];	// ������� � ��������
} car_struct;

typedef struct client_t		// ��������� "�������"
{
    int client_id;			// ��� �������

    char name[255];			// ���
    enum gender_t gender;	// ���
    date birth_date;		// ���� ��������
    char address[255];		// �����
    char phone[20];			// �������
    char passport[20];		// ���������� ������
} client_struct;

typedef struct rent_t		// ��������� "������"
{
    int car_id;				// ��� ����������
    int client_id;			// ��� �������
    int employee_id;		// ��� ����������
    int service1_id;		// ��� ������ 1
    int service2_id;		// ��� ������ 2
    int service3_id;		// ��� ������ 3

    date delivery_date;		// ���� ������
    unsigned rent_time;		// ���� �������
    date return_date;		// ���� ��������
    int rent_price;			// ���� �������
    char payment_mark[255];	// ������� �� ������
} rent_struct;

// ������� ���� ������
employee_struct	*employee_table;
position_struct	*position_table;
brand_struct	*brand_table;
service_struct	*service_table;
car_struct		*car_table;
client_struct	*client_table;
rent_struct		*rent_table;

#endif //��������_������_database_h