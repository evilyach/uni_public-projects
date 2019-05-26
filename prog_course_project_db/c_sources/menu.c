#include "database.h"

void menu(int mode)
{
    /*
	 * Подготовительный этап
	 */
	int *cursor = calloc( menu_count, sizeof(int) );
	int position = 0;		// Позиция курсора
	char input;
	cursor[position] = '>';	// Установка позиции курсора

	/*
	 * Селектор прорисовки меню
	 */ 
	switch (mode)
	{
		case (MAIN_MENU_MODE):
			show_main_menu(cursor);
			break;
		case (PRINT_LIST_MENU_MODE):
			show_print_list_menu(cursor);
			break;
		case (FILL_LIST_MENU_MODE):
			show_fill_list_menu(cursor);
			break;
		case (ADD_LIST_MENU_MODE):
			show_add_list_menu(cursor);
			break;
		case (DELETE_LIST_MENU_MODE):
			show_delete_list_menu(cursor);
			break;
		case (REQUEST_HRD_LIST_MENU_MODE):
			show_request_hrd_list_menu(cursor);
			break;
		case (REQUEST_AUTOPARK_LIST_MENU_MODE):
			show_request_autopark_list_menu(cursor);
			break;
	}

	/*
	 * Цикл меню
	 */
	while (1)
	{
		input = getch();
		switch (input)
		{
			/*
			 * Кнопки перемещения вверх
			 */ 
			case (UP_ARROW_KEY):
			case (K_KEY):
				if( !position )
				{
					cursor[position] = '\0';
					position = menu_count;
					cursor[position] = '>';
				}
				cursor[position] = '\0';
				position--;
				cursor[position] = '>';
				fflush(stdin);
				break;
			/*
			 * Кнопки перемещения вниз
			 */ 
			case (DOWN_ARROW_KEY):
			case (J_KEY):
				if( position == menu_count - 1 )
				{
					cursor[position] = '\0';
					position = 0 - 1;
					cursor[position] = '>';
				}
				cursor[position] = '\0';
				position++;
				cursor[position] = '>';
				fflush(stdin);
				break;
			/*
			 * Кнопки перемещения назад по меню
			 */ 
			case (LEFT_ARROW_KEY):
			case (H_KEY):
			case (ESC_KEY):
				switch (mode)
				{
					case (MAIN_MENU_MODE):
						break;
					default:
						return;
				}
			/*
			 * Кнопки выбора пункта меню
			 */ 
			case (RIGHT_ARROW_KEY):
			case (L_KEY):
			case (ENTER_KEY):
				switch (mode)
				{
					/*
					 * Главное меню
					 */
					case (MAIN_MENU_MODE):
						// Выбор пунктов активированного меню
						if( activated )
							switch (position)
							{
								// "1. Вывод таблицы"
								case (0):
									menu_count = PRINT_LIST_MENU_COUNT;
									menu(PRINT_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "2. Заполнение таблицы"
								case (1):
									menu_count = FILL_LIST_MENU_COUNT;
									menu(FILL_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "3. Добавление элементов в таблицу"
								case (2):
									menu_count = ADD_LIST_MENU_COUNT;
									menu(ADD_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "4. Удаление элементов из таблицы"
								case (3):
									menu_count = DELETE_LIST_MENU_COUNT;
									menu(DELETE_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "5. Запрос "Отдел кадров"
								case (4):
									menu_count = REQUEST_HRD_LIST_MENU_COUNT;
									menu(REQUEST_HRD_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "6. Запрос "Автопарк"
								case (5):
									menu_count = REQUEST_AUTOPARK_LIST_MENU_COUNT;
									menu(REQUEST_AUTOPARK_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "7. Запрос "Автомобили в прокате"
								case (6):
									rent_request();
									go_back();
									break;
								// "8. Сохранение в файл"
								case (7):
									save_file();
									go_back();
									break;
								// "9. Загрузка из файла"
								case (8):
									load_file();
									go_back();
									break;
								// "i. Справка"
								case (9):
									show_info();
									break;
								// "0. Выход"
								case (10):
									return;
							}
						// Выбор пунктов неактивированного меню
						else
							switch (position)
							{
								// "1. Заполнение таблицы"
								case (0):
									menu_count = FILL_LIST_MENU_COUNT;
									menu(FILL_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "2. Загрузка из файла"
								case (1):
									load_file();
									go_back();
									break;
								// "i. Справка"
								case (2):
									show_info();
									break;
								// "0. Выход"
								case (3):
									return;
							}
						break;
					/*
					 * Селектор перед выводом таблицы на экран
					 */
					case (PRINT_LIST_MENU_MODE):
						switch (position)
						{
						case (0):
							print_employee_table();
							go_back();
							break;
						case (1):
							print_position_table();
							go_back();
							break;
						case (2):
							print_brand_table();
							go_back();
							break;
						case (3):
							print_service_table();
							go_back();
							break;
						case (4):
							print_car_table();
							go_back();
							break;
						case (5):
							print_client_table();
							go_back();
							break;
						case (6):
							print_rent_table();
							go_back();
							break;
						}
						break;
					/*
					 * Селектор перед заполнением таблицы
					 */
					case (FILL_LIST_MENU_MODE):
						switch (position)
						{
							case (0):
								fill_employee_table(table_row[EMPLOYEE_TABLE]);
								go_back();
								break;
							case (1):
								fill_position_table(table_row[POSITION_TABLE]);
								go_back();
								break;
							case (2):
								fill_brand_table(table_row[BRAND_TABLE]);
								go_back();
								break;
							case (3):
								fill_service_table(table_row[SERVICE_TABLE]);
								go_back();
								break;
							case (4):
								fill_car_table(table_row[CAR_TABLE]);
								go_back();
								break;
							case (5):
								fill_client_table(table_row[CLIENT_TABLE]);
								go_back();
								break;
							case (6):
								fill_rent_table(table_row[RENT_TABLE]);
								go_back();
								break;
						}
						break;
					/*
					 * Селектор перед изменением элементов
					 */
					case (ADD_LIST_MENU_MODE):
					case (DELETE_LIST_MENU_MODE):
						switch (position)
						{
							case (0):
								edit_employee_table();
								go_back();
								break;
							case (1):
								edit_position_table();
								go_back();
								break;
							case (2):
								edit_brand_table();
								go_back();
								break;
							case (3):
								edit_service_table();
								go_back();
								break;
							case (4):
								edit_car_table();
								go_back();
								break;
							case (5):
								edit_client_table();
								go_back();
								break;
							case (6):
								edit_rent_table();
								go_back();
								break;
						}
						break;
					/*
					 * Селектор перед запросом "Отдел кадров"
					 */
					case (REQUEST_HRD_LIST_MENU_MODE):
						switch (position)
						{
							case (0):
								hrd_request();
								go_back();
								break;
							case (1):
								hrd_filter_specific_position();
								go_back();
								break;
						}
						break;

					case (REQUEST_AUTOPARK_LIST_MENU_MODE):
						switch (position)
						{
							case (0):
								autopark_request();
								go_back();
								break;
							case (1):
								autopark_filter_specific_brand();
								go_back();
								break;
							case (2):
								autopark_filter_in_and_off_rent();
								go_back();
								break;
							case (3):
								autopark_filter_specific_delivery_and_return_date();
								go_back();
								break;
							case (4):
								autopark_filter_paid_and_unpaid_rented_cars();
								go_back();
								break;
						}
						break;
				}
		}

		/*
		 * Перерисовка меню
		 */
		switch (mode)
		{
			case (MAIN_MENU_MODE):
				show_main_menu(cursor);
				break;
			case (PRINT_LIST_MENU_MODE):
				show_print_list_menu(cursor);
				break;
			case (FILL_LIST_MENU_MODE):
				show_fill_list_menu(cursor);
				break;
			case (ADD_LIST_MENU_MODE):
				show_add_list_menu(cursor);
				break;
			case (DELETE_LIST_MENU_MODE):
				show_delete_list_menu(cursor);
				break;
			case (REQUEST_HRD_LIST_MENU_MODE):
				show_request_hrd_list_menu(cursor);
				break;
			case (REQUEST_AUTOPARK_LIST_MENU_MODE):
				show_request_autopark_list_menu(cursor);
				break;
		}
	}
}

void show_main_menu(int *cur)
{
	system("cls");

	// Вывод шапки
    printf(
		"\t\t _____   _____   _____   _   _   _____   _____\n"
		"\t\t|     | |     \\ /     \\ | | | | /     \\ |__ __|\n"
		"\t\t| | | | | <=> | | | | | | |/ /  | <=> |   | |\n"
		"\t\t| | | | |  ___/ | | | | |    |  |  _  |   | |\n"
		"\t\t| | | | | |     | | | | | |\\ \\  | | | |   | |\n"
		"\t\t|_| |_| |_|     \\_____/ |_| |_| |_| |_|   |_|\n\n"
		"\t\t         _____   _____   _____   _____\n"
		"\t\t        /     \\ |     \\ |__ __| /     \\\n"
		"\t\t        | <=> | | <=> |   | |   | | | |\n"
		"\t\t        |  _  | |    <    | |   | | | |\n"
		"\t\t        | | | | | <=> |   | |   | | | |\n"
		"\t\t        |_| |_| |_____/   |_|   \\_____/\n\n\n");

	if( activated )
	{
		printf("\t\t      %c 1. Вывод таблицы\n",					cur[0]);
		printf("\t\t      %c 2. Заполнение таблицы\n",				cur[1]);
		printf("\t\t      %c 3. Добавление элементов в таблицу\n",	cur[2]);
		printf("\t\t      %c 4. Удаление элементов из таблицы\n",	cur[3]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c 5. Запрос: Отдел кадров\n",			cur[4]);
		printf("\t\t      %c 6. Запрос: Автопарк\n",				cur[5]);
		printf("\t\t      %c 7. Запрос: Автомобили в прокате\n",	cur[6]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c 8. Сохранение в файл\n",				cur[7]);
		printf("\t\t      %c 9. Загрузка из файла\n",				cur[8]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c i. Справка\n",							cur[9]);
		printf("\t\t      %c 0. Выход\n",							cur[10]);
	}
	else
	{
		printf("\t\t      %c 1. Заполнение таблицы\n",				cur[0]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c 2. Загрузка из файла\n",				cur[1]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c i. Справка\n",							cur[2]);
		printf("\t\t      %c 0. Выход\n",							cur[3]);
	}
}


void show_print_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\tКакую таблицу Вы хотите вывести:\n");
	printf("\t\t %c Сотрудники\n",				cur[0]);
	printf("\t\t %c Должности\n",				cur[1]);
	printf("\t\t %c Марки автомобилей\n",		cur[2]);
	printf("\t\t %c Дополнительные услуги\n",	cur[3]);
	printf("\t\t %c Автомобили\n",				cur[4]);
	printf("\t\t %c Клиенты\n",					cur[5]);
	printf("\t\t %c Прокат\n",					cur[6]);
}

void show_fill_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\tКакую таблицу Вы хотите заполнить:\n");
	printf("\t\t %c Сотрудники\n",				cur[0]);
	printf("\t\t %c Должности\n",				cur[1]);
	printf("\t\t %c Марки автомобилей\n",		cur[2]);
	printf("\t\t %c Дополнительные услуги\n",	cur[3]);
	printf("\t\t %c Автомобили\n",				cur[4]);
	printf("\t\t %c Клиенты\n",					cur[5]);
	printf("\t\t %c Прокат\n",					cur[6]);
}

void show_add_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\tВ какую таблицу Вы хотите добавить элемент:\n");
	printf("\t\t %c Сотрудники\n",				cur[0]);
	printf("\t\t %c Должности\n",				cur[1]);
	printf("\t\t %c Марки автомобилей\n",		cur[2]);
	printf("\t\t %c Дополнительные услуги\n",	cur[3]);
	printf("\t\t %c Автомобили\n",				cur[4]);
	printf("\t\t %c Клиенты\n",					cur[5]);
	printf("\t\t %c Прокат\n",					cur[6]);
}

void show_delete_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\tВыберите таблицу, из которой Вы хотете удалить\n");
	printf("\t\t(чтобы удалить целую строку, удалите код данной таблицы):\n");
	printf("\t\t %c Сотрудники\n",				cur[0]);
	printf("\t\t %c Должности\n",				cur[1]);
	printf("\t\t %c Марки автомобилей\n",		cur[2]);
	printf("\t\t %c Дополнительные услуги\n",	cur[3]);
	printf("\t\t %c Автомобили\n",				cur[4]);
	printf("\t\t %c Клиенты\n",					cur[5]);
	printf("\t\t %c Прокат\n",					cur[6]);
}


void show_request_hrd_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\tВыберите режим:\n");
	printf("\t\t %c Запрос \"Отдел кадров\"\n", cur[0]);
	printf("\t\t %c Фильтр для отображения сотрудников отдельных должностей\n", cur[1]);
}

void show_request_autopark_list_menu(int *cur)
{
	system("cls");
	
	printf("\n\n\t\tВыберите режим:\n");
	printf("\t\t %c Запрос \"Автопарк\"\n", cur[0]);
	printf("\t\t %c Фильтр отображения автомобилей отдельных марок\n", cur[1]);
	printf("\t\t %c Фильтр отображения автомобилей, находящихся и не находящихся в прокате\n", cur[2]);
	printf("\t\t %c Фильтр для отображения автомобилей выданных и возвращённых в определённую дату\n", cur[3]);
	printf("\t\t %c Фильтр оплаченных и не оплаченных автомобилей в прокате", cur[4]);
}

void show_info()
{
	system("cls");
	printf(
		"\n\n\t\tСправка:\n\n"
		"\t\tДля управления меню используются клавиатурные стрелки\n"
		"\t\tлибо vi-подобные клавиши управления:\n"
		"\t\t^ или k -- перемещение вверх\n"
		"\t\tv или j -- перемещение вниз\n"
		"\t\t< или h или Esc -- перемещение назад по меню\n"
		"\t\t> или l или Enter -- выбор пункта меню\n\n"
		"\t\tВыполнил курсовой проект: Чесалин И.Е., группа 641, 2018 год\n\n"
		"\t\tНажмите < или h или Esc, чтобы выйти в главное меню.\n");
	go_back();
}

void go_back()
{
	char input;

	while (1)
	{
		input = getch();
		// "Стрелка влево", "h", "Esc"
		if( (input == LEFT_ARROW_KEY) || 
			(input == H_KEY) || 
			(input == ESC_KEY) )	
		{
			fflush(stdin);
			return;
		}
	}
}