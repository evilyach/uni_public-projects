#include "database.h"

int main()
{
	int i;

	/*
	 * ���������������� ����
	 */
	SetConsoleCP(1251);			// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	// ��������� ������� �������� win-cp 1251 � ����� ������
	system("mode con cols=200 lines=50");	// ��������� �������� ���� ������� (200�40)
	system("color F0");			// ��������� ������ ����
	table_row = calloc( 7, sizeof(int) );

	/*
	 * ����� ����
	 */
	activated = 1;	// � ������ ������ ��������� �� ��� ������ ���� ������������
	menu_count = activated ? MAIN_MENU_COUNT_ACTIVATED : MAIN_MENU_COUNT_NON_ACTIVATED;
	current_mode = MAIN_MENU_MODE;
	menu(current_mode);

	/*
	 * �������� ������ ��-��� �������� ��������
	 */
	free(employee_table);
	free(position_table);
	free(brand_table);
	free(service_table);
	free(car_table);
	free(client_table);
	free(rent_table);
	
    return 0;
}