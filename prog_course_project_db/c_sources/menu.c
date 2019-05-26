#include "database.h"

void menu(int mode)
{
    /*
	 * ���������������� ����
	 */
	int *cursor = calloc( menu_count, sizeof(int) );
	int position = 0;		// ������� �������
	char input;
	cursor[position] = '>';	// ��������� ������� �������

	/*
	 * �������� ���������� ����
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
	 * ���� ����
	 */
	while (1)
	{
		input = getch();
		switch (input)
		{
			/*
			 * ������ ����������� �����
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
			 * ������ ����������� ����
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
			 * ������ ����������� ����� �� ����
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
			 * ������ ������ ������ ����
			 */ 
			case (RIGHT_ARROW_KEY):
			case (L_KEY):
			case (ENTER_KEY):
				switch (mode)
				{
					/*
					 * ������� ����
					 */
					case (MAIN_MENU_MODE):
						// ����� ������� ��������������� ����
						if( activated )
							switch (position)
							{
								// "1. ����� �������"
								case (0):
									menu_count = PRINT_LIST_MENU_COUNT;
									menu(PRINT_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "2. ���������� �������"
								case (1):
									menu_count = FILL_LIST_MENU_COUNT;
									menu(FILL_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "3. ���������� ��������� � �������"
								case (2):
									menu_count = ADD_LIST_MENU_COUNT;
									menu(ADD_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "4. �������� ��������� �� �������"
								case (3):
									menu_count = DELETE_LIST_MENU_COUNT;
									menu(DELETE_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "5. ������ "����� ������"
								case (4):
									menu_count = REQUEST_HRD_LIST_MENU_COUNT;
									menu(REQUEST_HRD_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "6. ������ "��������"
								case (5):
									menu_count = REQUEST_AUTOPARK_LIST_MENU_COUNT;
									menu(REQUEST_AUTOPARK_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "7. ������ "���������� � �������"
								case (6):
									rent_request();
									go_back();
									break;
								// "8. ���������� � ����"
								case (7):
									save_file();
									go_back();
									break;
								// "9. �������� �� �����"
								case (8):
									load_file();
									go_back();
									break;
								// "i. �������"
								case (9):
									show_info();
									break;
								// "0. �����"
								case (10):
									return;
							}
						// ����� ������� ����������������� ����
						else
							switch (position)
							{
								// "1. ���������� �������"
								case (0):
									menu_count = FILL_LIST_MENU_COUNT;
									menu(FILL_LIST_MENU_MODE);
									menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
									break;
								// "2. �������� �� �����"
								case (1):
									load_file();
									go_back();
									break;
								// "i. �������"
								case (2):
									show_info();
									break;
								// "0. �����"
								case (3):
									return;
							}
						break;
					/*
					 * �������� ����� ������� ������� �� �����
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
					 * �������� ����� ����������� �������
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
					 * �������� ����� ���������� ���������
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
					 * �������� ����� �������� "����� ������"
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
		 * ����������� ����
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

	// ����� �����
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
		printf("\t\t      %c 1. ����� �������\n",					cur[0]);
		printf("\t\t      %c 2. ���������� �������\n",				cur[1]);
		printf("\t\t      %c 3. ���������� ��������� � �������\n",	cur[2]);
		printf("\t\t      %c 4. �������� ��������� �� �������\n",	cur[3]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c 5. ������: ����� ������\n",			cur[4]);
		printf("\t\t      %c 6. ������: ��������\n",				cur[5]);
		printf("\t\t      %c 7. ������: ���������� � �������\n",	cur[6]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c 8. ���������� � ����\n",				cur[7]);
		printf("\t\t      %c 9. �������� �� �����\n",				cur[8]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c i. �������\n",							cur[9]);
		printf("\t\t      %c 0. �����\n",							cur[10]);
	}
	else
	{
		printf("\t\t      %c 1. ���������� �������\n",				cur[0]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c 2. �������� �� �����\n",				cur[1]);
		printf("\t\t      ___________________________________\n\n");
		printf("\t\t      %c i. �������\n",							cur[2]);
		printf("\t\t      %c 0. �����\n",							cur[3]);
	}
}


void show_print_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\t����� ������� �� ������ �������:\n");
	printf("\t\t %c ����������\n",				cur[0]);
	printf("\t\t %c ���������\n",				cur[1]);
	printf("\t\t %c ����� �����������\n",		cur[2]);
	printf("\t\t %c �������������� ������\n",	cur[3]);
	printf("\t\t %c ����������\n",				cur[4]);
	printf("\t\t %c �������\n",					cur[5]);
	printf("\t\t %c ������\n",					cur[6]);
}

void show_fill_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\t����� ������� �� ������ ���������:\n");
	printf("\t\t %c ����������\n",				cur[0]);
	printf("\t\t %c ���������\n",				cur[1]);
	printf("\t\t %c ����� �����������\n",		cur[2]);
	printf("\t\t %c �������������� ������\n",	cur[3]);
	printf("\t\t %c ����������\n",				cur[4]);
	printf("\t\t %c �������\n",					cur[5]);
	printf("\t\t %c ������\n",					cur[6]);
}

void show_add_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\t� ����� ������� �� ������ �������� �������:\n");
	printf("\t\t %c ����������\n",				cur[0]);
	printf("\t\t %c ���������\n",				cur[1]);
	printf("\t\t %c ����� �����������\n",		cur[2]);
	printf("\t\t %c �������������� ������\n",	cur[3]);
	printf("\t\t %c ����������\n",				cur[4]);
	printf("\t\t %c �������\n",					cur[5]);
	printf("\t\t %c ������\n",					cur[6]);
}

void show_delete_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\t�������� �������, �� ������� �� ������ �������\n");
	printf("\t\t(����� ������� ����� ������, ������� ��� ������ �������):\n");
	printf("\t\t %c ����������\n",				cur[0]);
	printf("\t\t %c ���������\n",				cur[1]);
	printf("\t\t %c ����� �����������\n",		cur[2]);
	printf("\t\t %c �������������� ������\n",	cur[3]);
	printf("\t\t %c ����������\n",				cur[4]);
	printf("\t\t %c �������\n",					cur[5]);
	printf("\t\t %c ������\n",					cur[6]);
}


void show_request_hrd_list_menu(int *cur)
{
	system("cls");

	printf("\n\n\t\t�������� �����:\n");
	printf("\t\t %c ������ \"����� ������\"\n", cur[0]);
	printf("\t\t %c ������ ��� ����������� ����������� ��������� ����������\n", cur[1]);
}

void show_request_autopark_list_menu(int *cur)
{
	system("cls");
	
	printf("\n\n\t\t�������� �����:\n");
	printf("\t\t %c ������ \"��������\"\n", cur[0]);
	printf("\t\t %c ������ ����������� ����������� ��������� �����\n", cur[1]);
	printf("\t\t %c ������ ����������� �����������, ����������� � �� ����������� � �������\n", cur[2]);
	printf("\t\t %c ������ ��� ����������� ����������� �������� � ������������ � ����������� ����\n", cur[3]);
	printf("\t\t %c ������ ���������� � �� ���������� ����������� � �������", cur[4]);
}

void show_info()
{
	system("cls");
	printf(
		"\n\n\t\t�������:\n\n"
		"\t\t��� ���������� ���� ������������ ������������ �������\n"
		"\t\t���� vi-�������� ������� ����������:\n"
		"\t\t^ ��� k -- ����������� �����\n"
		"\t\tv ��� j -- ����������� ����\n"
		"\t\t< ��� h ��� Esc -- ����������� ����� �� ����\n"
		"\t\t> ��� l ��� Enter -- ����� ������ ����\n\n"
		"\t\t�������� �������� ������: ������� �.�., ������ 641, 2018 ���\n\n"
		"\t\t������� < ��� h ��� Esc, ����� ����� � ������� ����.\n");
	go_back();
}

void go_back()
{
	char input;

	while (1)
	{
		input = getch();
		// "������� �����", "h", "Esc"
		if( (input == LEFT_ARROW_KEY) || 
			(input == H_KEY) || 
			(input == ESC_KEY) )	
		{
			fflush(stdin);
			return;
		}
	}
}