# -*- coding: utf-8 -*-

# Встроенные библиотеки
import os
import sys

# Подключение модулей
import main
import const
import out
import fill
import edit
import request
import file


def menu(mode, menu_count):
    # Подготовка
    position = 0
    cursor = [" "] * menu_count
    cursor[position] = ">"

    # Прорисовка
    if mode == const.MAIN_MENU_MODE:
        show_main_menu(cursor)
    elif mode == const.PRINT_LIST_MENU_MODE:
        show_print_list_menu(cursor)
    elif mode == const.FILL_LIST_MENU_MODE:
        show_fill_list_menu(cursor)
    elif mode == const.ADD_LIST_MENU_MODE:
        show_add_list_menu(cursor)
    elif mode == const.DELETE_LIST_MENU_MODE:
        show_delete_list_menu(cursor)
    elif mode == const.REQUEST_HRD_LIST_MENU_MODE:
        show_request_hrd_list_menu(cursor)
    elif mode == const.REQUEST_AUTOPARK_LIST_MENU_MODE:
        show_request_autopark_list_menu(cursor)

    # Цикл меню
    while True:
        # Получение прямого ввода на Linux
        os.system("stty raw -echo")
        c = sys.stdin.read(1)
        os.system("stty -raw echo")
        print(c, ord(c))

        # Нажатие стрелки вверх или k
        if c == 'k':
            if position == 0 - 1:
                cursor[position] = ' '
                position = menu_count - 1
                cursor[position] = '>'
            cursor[position] = ' '
            position -= 1
            cursor[position] = '>'
        # Нажатие стрелки вниз или j
        elif c == 'j':
            if position == menu_count - 1:
                cursor[position] = ' '
                position = 0 - 1
                cursor[position] = '>'
            cursor[position] = ' '
            position += 1
            cursor[position] = '>'
        # Нажатие стрелки влево или h
        elif c == 'h':
            if mode == const.MAIN_MENU_MODE:
                break
            else:
                return
        # Нажатие стрелки вправо или l
        elif c == 'l':
            if mode == const.MAIN_MENU_MODE:
                if main.activated == 1:
                    # "1. Вывод таблицы"
                    if position == 0:
                        menu_count = const.PRINT_LIST_MENU_COUNT
                        menu(const.PRINT_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "2. Заполнение таблицы"
                    elif position == 1:
                        menu_count = const.FILL_LIST_MENU_COUNT
                        menu(const.FILL_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "3. Добавление элементов в таблицу"
                    elif position == 2:
                        menu_count = const.ADD_LIST_MENU_COUNT
                        menu(const.ADD_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "4. Удаление элементов из таблицы"
                    elif position == 3:
                        menu_count = const.DELETE_LIST_MENU_COUNT
                        menu(const.DELETE_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "5. Запрос: Отдел кадров"
                    elif position == 4:
                        menu_count = const.REQUEST_HRD_LIST_MENU_COUNT
                        menu(const.REQUEST_HRD_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "6. Запрос: Автопарк"
                    elif position == 5:
                        menu_count = const.REQUEST_AUTOPARK_LIST_MENU_COUNT
                        menu(const.REQUEST_AUTOPARK_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "7. Запрос: Автомобили в прокате"
                    elif position == 6:
                        request.rent_request()
                        go_back()
                    # "8. Сохранение в файл"
                    elif position == 7:
                        file.save_file()
                        go_back()
                    # "9. Загрузка из файла"
                    elif position == 8:
                        file.load_file()
                        go_back()
                    # "i. Справка"
                    elif position == 9:
                        show_info()
                        go_back()
                    # "0. Выход"
                    elif position == 10:
                        return 0
                else:
                    # "1. Заполнение таблицы"
                    if position == 0:
                        menu_count = const.FILL_LIST_MENU_COUNT
                        menu(const.FILL_LIST_MENU_MODE, menu_count)
                        menu_count = main.main_menu_switcher(main.activated)
                    # "2. Загрузка из файла"
                    elif position == 1:
                        file.load_file()
                        go_back()
                    # "i. Справка"
                    elif position == 2:
                        show_info()
                        go_back()
                    # "0. Выход"
                    elif position == 3:
                        return 0

            elif mode == const.PRINT_LIST_MENU_MODE:
                if position == 0:
                    out.print_employee_table()
                    go_back()
                elif position == 1:
                    out.print_position_table()
                    go_back()
                elif position == 2:
                    out.print_brand_table()
                    go_back()
                elif position == 3:
                    out.print_service_table()
                    go_back()
                elif position == 4:
                    out.print_car_table()
                    go_back()
                elif position == 5:
                    out.print_client_table()
                    go_back()
                elif position == 6:
                    out.print_rent_table()
                    go_back()

            elif mode == const.FILL_LIST_MENU_MODE:
                if position == 0:
                    fill.fill_employee_table(main.table_row[const.EMPLOYEE_TABLE])
                    go_back()
                elif position == 1:
                    fill.fill_position_table(main.table_row[const.POSITION_TABLE])
                    go_back()
                elif position == 2:
                    fill.fill_brand_table(main.table_row[const.BRAND_TABLE])
                    go_back()
                elif position == 3:
                    fill.fill_service_table(main.table_row[const.SERVICE_TABLE])
                    go_back()
                elif position == 4:
                    fill.fill_car_table(main.table_row[const.CAR_TABLE])
                    go_back()
                elif position == 5:
                    fill.fill_client_table(main.table_row[const.CLIENT_TABLE])
                    go_back()
                elif position == 6:
                    fill.fill_rent_table(main.table_row[const.RENT_TABLE])
                    go_back()

            elif mode == const.ADD_LIST_MENU_MODE or mode == const.DELETE_LIST_MENU_MODE:
                if position == 0:
                    edit.edit_employee_table()
                    go_back()
                elif position == 1:
                    edit.edit_position_table()
                    go_back()
                elif position == 2:
                    edit.edit_brand_table()
                    go_back()
                elif position == 3:
                    edit.edit_service_table()
                    go_back()
                elif position == 4:
                    edit.edit_car_table()
                    go_back()
                elif position == 5:
                    edit.edit_client_table()
                    go_back()
                elif position == 6:
                    edit.edit_rent_table()
                    go_back()

            elif mode == const.REQUEST_HRD_LIST_MENU_MODE:
                if position == 0:
                    request.hrd_request()
                    go_back()
                elif position == 1:
                    request.hrd_filter_specific_position()
                    go_back()

            elif mode == const.REQUEST_AUTOPARK_LIST_MENU_MODE:
                if position == 0:
                    request.autopark_request()
                    go_back()
                elif position == 1:
                    request.autopark_filter_specific_brand()
                    go_back()
                elif position == 2:
                    request.autopark_filter_in_and_off_rent()
                    go_back()
                elif position == 3:
                    request.autopark_filter_specific_delivery_and_return_date()
                    go_back()
                elif position == 4:
                    request.autopark_filter_paid_and_unpaid_rented_cars()
                    go_back()

            # Перерисовка
        if mode == const.MAIN_MENU_MODE:
            show_main_menu(cursor)
        elif mode == const.PRINT_LIST_MENU_MODE:
            show_print_list_menu(cursor)
        elif mode == const.FILL_LIST_MENU_MODE:
            show_fill_list_menu(cursor)
        elif mode == const.ADD_LIST_MENU_MODE:
            show_add_list_menu(cursor)
        elif mode == const.DELETE_LIST_MENU_MODE:
            show_delete_list_menu(cursor)
        elif mode == const.REQUEST_HRD_LIST_MENU_MODE:
            show_request_hrd_list_menu(cursor)
        elif mode == const.REQUEST_AUTOPARK_LIST_MENU_MODE:
            show_request_autopark_list_menu(cursor)


def show_main_menu(cur):
    os.system("clear")
    print("\t\t _____ _____ _____ _ _ _____ _____")
    print("\t\t| | | \\ / \\ | | | | / \\ |__ __|")
    print("\t\t| | | | | <=> | | | | | | |/ / | <=> | | |")
    print("\t\t| | | | | ___/ | | | | | | | _ | | |")
    print("\t\t| | | | | | | | | | | |\\ \\ | | | | | |")
    print("\t\t|_| |_| |_| \\_____/ |_| |_| |_| |_| |_|\n")
    print("\t\t _____ _____ _____ _____")
    print("\t\t / \\ | \\ |__ __| / \\")
    print("\t\t | <=> | | <=> | | | | | | |")
    print("\t\t | _ | | < | | | | | |")
    print("\t\t | | | | | <=> | | | | | | |")
    print("\t\t |_| |_| |_____/ |_| \\_____/\n\n")

    if main.activated:
        print("\t\t %s 1. Вывод таблицы" % (cur[0]))
        print("\t\t %s 2. Заполнение таблицы" % (cur[1]))
        print("\t\t %s 3. Добавление элементов в таблицу" % (cur[2]))
        print("\t\t %s 4. Удаление элементов из таблицы" % (cur[3]))
        print("\t\t ___________________________________\n")
        print("\t\t %s 5. Запрос: Отдел кадров" % (cur[4]))
        print("\t\t %s 6. Запрос: Автопарк" % (cur[5]))
        print("\t\t %s 7. Запрос: Автомобили в прокате" % (cur[6]))
        print("\t\t ___________________________________\n")
        print("\t\t %s 8. Сохранение в файл" % (cur[7]))
        print("\t\t %s 9. Загрузка из файла" % (cur[8]))
        print("\t\t ___________________________________\n")
        print("\t\t %s i. Справка" % (cur[9]))
        print("\t\t %s 0. Выход" % (cur[10]))
    else:
        print("\t\t %s 1. Заполнение таблицы" % (cur[0]))
        print("\t\t ___________________________________\n")
        print("\t\t %s 2. Загрузка из файла" % (cur[1]))
        print("\t\t ___________________________________\n")
        print("\t\t %s i. Справка" % (cur[2]))
        print("\t\t %s 0. Выход" % (cur[3]))


def show_print_list_menu(cur):
    os.system("clear")
    print("\n\n\t\tКакую таблицу Вы хотите вывести:")
    print("\t\t %s 1. Сотрудники" % (cur[0]))
    print("\t\t %s 2. Должности" % (cur[1]))
    print("\t\t %s 3. Марки автомобилей" % (cur[2]))
    print("\t\t %s 4. Дополнительные услуги" % (cur[3]))
    print("\t\t %s 5. Автомобили" % (cur[4]))
    print("\t\t %s 6. Клиенты" % (cur[5]))
    print("\t\t %s 7. Прокат" % (cur[6]))


def show_fill_list_menu(cur):
    os.system("clear")
    print("\n\n\t\tКакую таблицу Вы хотите заполнить:")
    print("\t\t %s 1. Сотрудники" % (cur[0]))
    print("\t\t %s 2. Должности" % (cur[1]))
    print("\t\t %s 3. Марки автомобилей" % (cur[2]))
    print("\t\t %s 4. Дополнительные услуги" % (cur[3]))
    print("\t\t %s 5. Автомобили" % (cur[4]))
    print("\t\t %s 6. Клиенты" % (cur[5]))
    print("\t\t %s 7. Прокат" % (cur[6]))


def show_add_list_menu(cur):
    os.system("clear")
    print("\n\n\t\tВ какую таблицу Вы хотите добавить элемент:")
    print("\t\t %s 1. Сотрудники" % (cur[0]))
    print("\t\t %s 2. Должности" % (cur[1]))
    print("\t\t %s 3. Марки автомобилей" % (cur[2]))
    print("\t\t %s 4. Дополнительные услуги" % (cur[3]))
    print("\t\t %s 5. Автомобили" % (cur[4]))
    print("\t\t %s 6. Клиенты" % (cur[5]))
    print("\t\t %s 7. Прокат" % (cur[6]))


def show_delete_list_menu(cur):
    os.system("clear")
    print("\n\n\t\tВ какую таблицу Вы хотите добавить элемент:")
    print("\t\t %s 1. Сотрудники" % (cur[0]))
    print("\t\t %s 2. Должности" % (cur[1]))
    print("\t\t %s 3. Марки автомобилей" % (cur[2]))
    print("\t\t %s 4. Дополнительные услуги" % (cur[3]))
    print("\t\t %s 5. Автомобили" % (cur[4]))
    print("\t\t %s 6. Клиенты" % (cur[5]))
    print("\t\t %s 7. Прокат" % (cur[6]))


def show_request_hrd_list_menu(cur):
    os.system("clear")
    print("\n\n\t\tВыберите режим:")
    print("\t\t %s Запрос \"Отдел кадров\"" % (cur[0]))
    print("\t\t %s Фильтр для отображения сотрудников отдельных должностей" % (cur[1]))


def show_request_autopark_list_menu(cur):
    os.system("clear")
    print("\n\n\t\tВыберите режим:")
    print("\t\t %s Запрос \"Автопарк\"" % (cur[0]))
    print("\t\t %s Фильтр отображения автомобилей отдельных марок" % (cur[1]))
    print("\t\t %s Фильтр отображения автомобилей, находящихся и не находящихся в прокате" % (cur[2]))
    print("\t\t %s Фильтр для отображения автомобилей выданных и возвращённых в определённую дату" % (cur[3]))
    print("\t\t %s Фильтр оплаченных и не оплаченных автомобилей в прокате" % (cur[4]))


def show_info():
    os.system("clear")
    print("\n\n\t\tСправка:\n")
    print("\t\tДля управления меню используются клавиатурные стрелки")
    print("\t\tлибо vi-подобные клавиши управления:")
    print("\t\t^ или k -- перемещение вверх")
    print("\t\tv или j -- перемещение вниз")
    print("\t\t< или h или Esc -- перемещение назад по меню")
    print("\t\t> или l или Enter -- выбор пункта меню\n")
    print("\t\tВыполнил курсовой проект: блаблабла\n") # TODO: поставь сюда свое имя
    print("\t\tНажмите < или h или Esc, чтобы выйти в главное меню.")


def go_back():
    while True:
        os.system("stty raw -echo")
        c = sys.stdin.read(1)
        os.system("stty -raw echo")

        if c == 'h':
            return