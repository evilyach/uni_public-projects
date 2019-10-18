#ifndef курсовой_проект_main_h
#define курсовой_проект_main_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

/*
 * Прототипы и объявления общие
 */
// Глобальные переменные
int *table_row;	// Количество строк каждой таблицы

// Коды таблиц
#define EMPLOYEE_TABLE	0
#define POSITION_TABLE	1
#define BRAND_TABLE		2
#define SERVICE_TABLE	3
#define CAR_TABLE		4
#define CLIENT_TABLE	5
#define RENT_TABLE		6

// Коды клавиш
#define UP_ARROW_KEY	0x48
#define DOWN_ARROW_KEY	0x50
#define RIGHT_ARROW_KEY	0x4d
#define LEFT_ARROW_KEY	0x4b
#define K_KEY		0x6b
#define J_KEY		0x6a
#define L_KEY		0x6c
#define H_KEY		0x68
#define ENTER_KEY	0x0d
#define ESC_KEY		0x1b

/*
 * Прототипы и объявления для файла main.c
 */

/*
 * Прототипы и объявления для файла menu.c
 */
// Режимы меню
#define MAIN_MENU_MODE 1
#define PRINT_LIST_MENU_MODE 2
#define FILL_LIST_MENU_MODE 3
#define ADD_LIST_MENU_MODE 4
#define DELETE_LIST_MENU_MODE 5
#define REQUEST_HRD_LIST_MENU_MODE 6
#define REQUEST_AUTOPARK_LIST_MENU_MODE 7

// Количество пунктов меню
#define MAIN_MENU_COUNT_NON_ACTIVATED 4
#define MAIN_MENU_COUNT_ACTIVATED 11
#define PRINT_LIST_MENU_COUNT 7
#define FILL_LIST_MENU_COUNT 7
#define ADD_LIST_MENU_COUNT 7
#define DELETE_LIST_MENU_COUNT 7
#define REQUEST_HRD_LIST_MENU_COUNT 2
#define REQUEST_AUTOPARK_LIST_MENU_COUNT 5

// Глобальные переменные для меню
int activated;
int menu_count;
int current_mode;

// Функции и процедуры
void menu(int);
void show_main_menu(int *); 
void show_print_list_menu(int *);
void show_fill_list_menu(int *);
void show_add_list_menu(int *);
void show_delete_list_menu(int *);
void show_request_hrd_list_menu(int *);
void show_request_autopark_list_menu(int *);
void show_info();
void go_back();

/*
 * Прототипы и объявления для файла print.c
 */
void print_employee_table();
void print_position_table();
void print_brand_table();
void print_service_table();
void print_car_table();
void print_client_table();
void print_rent_table();

void print_employee_info();
void print_position_info();
void print_brand_info();
void print_service_info();
void print_car_info();
void print_client_info();

/*
 * Прототипы и объявления для файла fill.c
 */
int input_string(char *, const int, char *);
int input_int(int, const int, char *);
int input_gender(enum gender_t *, const int, char *);
int input_date(struct date *, const int, char *);
int fill_employee_table(int);
int fill_position_table(int);
int fill_brand_table(int);
int fill_service_table(int);
int fill_car_table(int);
int fill_client_table(int);
int fill_rent_table(int);

/*
 * Прототипы и объявления для файла edit.c
 */
int edit_employee_table();
int edit_position_table();
int edit_brand_table();
int edit_service_table();
int edit_car_table();
int edit_client_table();
int edit_rent_table();

/*
 * Прототипы и объявления для файла request.c
 */
// Запросы
void hrd_request();
void autopark_request();
void rent_request();

// Фильтры
void hrd_filter_specific_position();
void autopark_filter_specific_brand();
void autopark_filter_in_and_off_rent();
void autopark_filter_specific_delivery_and_return_date();
void autopark_filter_paid_and_unpaid_rented_cars();

/*
 * Прототипы и объявления для файла file.c
 */
FILE *f;
void save_file();
void load_file();


#endif //курсовой_проект_main_h
