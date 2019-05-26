# -*- coding: utf-8 -*-

# Подключение модулей
import main
import const
import database
import menu
import out
import fill

def edit_employee_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_employee_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))

    for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
        if database.employee_table[i].employee_id == id:
            row = i
    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
         "\t1 - Код сотрудника\n"
         "\t2 - Код должности\n"
         "\t3 - ФИО\n"
         "\t4 - Возраст\n"
         "\t5 - Пол\n"
         "\t6 - Адрес\n"
         "\t7 - Телефон\n"
         "\t8 - Паспортные данные\n"
         "\t -> ", end="")

    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            database.employee_table[row].employee_id = int(input("Введите код сотрудника (больше нуля) -> "))
            print("", end="\n")
            if database.employee_table[row].employee_id < 0:
                raise fill.BadIdError
        elif temp == 2:
            out.print_position_info()
            database.employee_table[row].position_id = int(input("Введите код должности (больше нуля) -> "))
            print("", end="\n")
            if database.employee_table[row].position_id < 0:
                raise fill.BadIdError
        elif temp == 3:
            database.employee_table[row].name = input("Введите ФИО -> ")
            print("", end="\n")
        elif temp == 4:
            database.employee_table[row].age = int(input("Введите возраст -> "))
            print("", end="\n")
            if database.employee_table[row].age < 0:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не возраст")
        elif temp == 5:
            database.employee_table[row].gender = fill.input_gender("Введите пол -> ")
            print("", end="\n")
        elif temp == 6:
            database.employee_table[row].address = input("Введите адрес -> ")
            print("", end="\n")
        elif temp == 7:
            database.employee_table[row].phone = input("Введите телефон -> ")
            print("", end="\n")
        elif temp == 8:
            database.employee_table[row].passport = input("Введите паспортные данные -> ")
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.GenderError:
        print("ОШИБКА: не удалось распознать пол")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def edit_position_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_position_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))

    for i in range(0, main.table_row[const.POSITION_TABLE]):
        if database.position_table[i].position_id == id:
            row = i

    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
         "\t1 - Код должности\n"
         "\t2 - Наименование\n"
         "\t3 - Оклад\n"
         "\t4 - Обязанности\n"
         "\t5 - Требования\n"
         "\t -> ", end="")

    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            database.position_table[row].position_id = int(input("Введите код должности (больше нуля) -> "))
            print("", end="\n")
            if database.position_table[row].position_id < 0:
                raise fill.BadIdError
        elif temp == 2:
            database.position_table[row].name = input("Введите наименование -> ")
            print("", end="\n")
        elif temp == 3:
            database.position_table[row].salary = int(input("Введите оклад -> "))
            print("", end="\n")
        elif temp == 4:
            database.position_table[row].duties = input("Введите обязанности -> ")
            print("", end="\n")
        elif temp == 5:
            database.position_table[row].requirements = input("Введите требования -> ")
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def edit_brand_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_brand_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))

    for i in range(0, main.table_row[const.BRAND_TABLE]):
        if database.brand_table[i].brand_id == id:
            row = i

    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
         "\t1 - Код марки\n"
         "\t2 - Наименование\n"
         "\t3 - Технические характеристики\n"
         "\t4 - Описание\n"
         "\t -> ", end="")

    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            database.brand_table[row].brand_id = int(input("Введите код марки (больше нуля) -> "))
            print("", end="\n")
            if database.brand_table[row].brand_id <= 0:
                raise fill.BadIdError
        elif temp == 2:
            database.brand_table[row].name = input("Введите наименование -> ")
            print("", end="\n")
        elif temp == 3:
            database.brand_table[row].specs = input("Введите технические характеристики -> ")
            print("", end="\n")
        elif temp == 4:
            database.brand_table[row].description = input("Введите описание -> ")
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def edit_service_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_service_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))

    for i in range(0, main.table_row[const.SERVICE_TABLE]):
        if database.service_table[i].service_id == id:
            row = i

    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
          "\t1 - Код марки\n"
          "\t2 - Наименование\n"
          "\t3 - Технические характеристики\n"
          "\t4 - Описание\n"
          "\t -> ", end="")
    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            database.service_table[row].service_id = int(input("Введите код услуги (больше нуля) -> "))
            print("", end="\n")
            if database.service_table[row].service_id <= 0:
                raise fill.BadIdError
        elif temp == 2:
            database.service_table[row].name = input("Введите наименование -> ")
            print("", end="\n")
        elif temp == 3:
            database.service_table[row].description = input("Введите описание -> ")
            print("", end="\n")
        elif temp == 4:
            database.service_table[row].price = int(input("Введите цену -> "))
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def edit_car_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_car_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))
    for i in range(0, main.table_row[const.CAR_TABLE]):
        if database.car_table[i].car_id == id:
            row = i

    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
          "\tВведите, какой элемент Вы хотите изменить или удалить\n"
          "\t1 - Код автомобиля\n"
          "\t2 - Код марки\n"
          "\t3 - Код механика\n"
          "\t4 - Регистрационный номер\n"
          "\t5 - Номер кузова\n"
          "\t6 - Номер двигателя\n"
          "\t7 - Год выпуска\n"
          "\t8 - Пробег\n"
          "\t9 - Цена автомобиля\n"
          "\t10 - Цена дня проката\n"
          "\t11 - День даты последнего ТО\n"
          "\t12 - Месяц даты последнего ТО\n"
          "\t13 - Год даты последнего ТО\n"
          "\t14 - Специальные отметки\n"
          "\t15 - Отметка о возврате"
          "\t -> ", end="")

    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            database.car_table[row].car_id = int(input("Введите код автомобиля (больше нуля) -> "))
            print("", end="\n")
            if database.car_table[row].car_id <= 0:
                raise fill.BadIdError
        elif temp == 2:
            out.print_brand_info()
            database.car_table[row].brand_id = int(input("Введите код марки (больше нуля) -> "))
            print("", end="\n")
            if database.car_table[row].brand_id <= 0:
                raise fill.BadIdError
        elif temp == 3:
            out.print_employee_info()
            database.car_table[row].employee_id = int(input("Введите код сотрудникамеханика (больше нуля) -> "))
            print("", end="\n")
            if database.car_table[row].employee_id <= 0:
                raise fill.BadIdError
        elif temp == 4:
            database.car_table[row].reg_number = int(input("Введите регистрационный номер -> "))
            print("", end="\n")
        elif temp == 5:
            database.car_table[row].body_number = int(input("Введите номер кузова -> "))
            print("", end="\n")
        elif temp == 6:
            database.car_table[row].engine_number = int(input("Введите номер двигателя -> "))
            print("", end="\n")
        elif temp == 7:
            database.car_table[row].release_year = int(input("Введите год выпуска -> "))
            print("", end="\n")
        elif temp == 8:
            database.car_table[row].mileage = int(input("Введите пробег -> "))
            print("", end="\n")
        elif temp == 9:
            database.car_table[row].price = int(input("Введите цену автомобиля -> "))
            print("", end="\n")
        elif temp == 10:
            database.car_table[row].rent_price = int(input("Введите цену дня проката -> "))
            print("", end="\n")
        elif temp == 11:
            database.car_table[row].maintenance_date.day = int(input("Введите день даты последнего ТО -> "))
            print("", end="\n")
            if database.car_table[row].maintenance_date.day < 0 or \
               database.car_table[row].maintenance_date.day > 31:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не день даты последнего ТО")
        elif temp == 12:
            database.car_table[row].maintenance_date.month = int(input("Введите месяц даты последнего ТО -> "))
            print("", end="\n")
            if database.car_table[row].maintenance_date.month < 0 or \
            database.car_table[row].maintenance_date.month > 12:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не месяц даты последнего ТО")
        elif temp == 13:
            database.car_table[row].maintenance_date.year = int(input("Введите год даты последнего ТО -> "))
            print("", end="\n")
            if database.car_table[row].maintenance_date.year < 0:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год даты последнего ТО")
        elif temp == 14:
            database.car_table[row].special_marks = input("Введите специальные отметки -> ")
            print("", end="\n")
        elif temp == 15:
            database.car_table[row].return_mark = input("Введите отметку о возврате -> ")
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def edit_client_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_client_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))

    for i in range(0, main.table_row[const.CLIENT_TABLE]):
        if database.client_table[i].client_id == id:
            row = i

    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
          "\t1 - Код клиента\n"
          "\t2 - ФИО\n"
          "\t3 - Пол\n"
          "\t4 - День даты рождения\n"
          "\t5 - Месяц даты рождения\n"
          "\t6 - Год даты рождения\n"
          "\t7 - Адрес\n"
          "\t8 - Телефон\n"
          "\t9 - Паспортные данные"
          "\t -> ", end="")
    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            database.client_table[row].client_id = int(input("Введите код клиента (больше нуля) -> "))
            print("", end="\n")
            if database.client_table[row].client_id <= 0:
                raise fill.BadIdError
        elif temp == 2:
            database.client_table[row].name = input("Введите ФИО -> ")
            print("", end="\n")
        elif temp == 3:
            database.client_table[row].gender = fill.input_gender("Введите пол -> ")
            print("", end="\n")
        elif temp == 4:
            database.client_table[row].birth_date.day = int(input("Введите день даты рождения -> "))
            print("", end="\n")
            if database.car_table[row].birth_date.day < 0 or \
               database.car_table[row].birth_date.day > 31:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не день даты рождения")
        elif temp == 5:
            database.client_table[row].birth_date.month = int(input("Введите месяц даты рождения -> "))
            print("", end="\n")
            if database.car_table[row].birth_date.month < 0 or \
               database.car_table[row].birth_date.month > 12:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не месяц даты рождения")
        elif temp == 6:
            database.client_table[row].birth_date.year = int(input("Введите год даты рождения -> "))
            print("", end="\n")
            if database.car_table[row].birth_date.year < 0:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год даты рождения")
        elif temp == 7:
            database.client_table[row].address = input("Введите адрес -> ")
            print("", end="\n")
        elif temp == 8:
            database.client_table[row].phone = input("Введите телефон -> ")
            print("", end="\n")
        elif temp == 9:
            database.client_table[row].passport = input("Введите паспортные данные -> ")
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.GenderError:
        print("ОШИБКА: не удалось распознать пол")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def edit_rent_table():
    row = -1

    # Вывод таблицы для наглядности
    out.print_rent_table()

    # Запрос пользователю выбрать нужную запись
    id = int(input("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> "))

    for i in range(0, main.table_row[const.RENT_TABLE]):
        if database.rent_table[i].car_id == id:
            row = i
    if row == -1:
        print("ОШИБКА: Невозможно найти запись с таким кодом\n")
        return

    # Запрос пользователю выбрать нужный элемент записи и изменить его
    print("\tВведите, какой элемент Вы хотите изменить или удалить\n"
          "\t1 - Код автомобиля\n"
          "\t2 - Код клиента\n"
          "\t3 - Код сотрудника\n"
          "\t4 - Код услуги 1\n"
          "\t5 - Код услуги 2\n"
          "\t6 - Код услуги 3\n"
          "\t7 - День даты выдачи"
          "\t8 - Месяц даты выдачи"
          "\t9 - Год даты выдачи"
          "\t10 - Срок проката"
          "\t11 - День даты возврата"
          "\t12 - Месяц даты возврата"
          "\t13 - Год даты возврата"
          "\t14 - Цена проката"
          "\t15 - Пометка об оплате"
          "\t -> ", end="")

    try:
        temp = input()
    except ValueError:
        print("ОШИБКА: Не удалось распознать номер записи")
        menu.go_back()
    print("", end="\n")

    # В зависимости от выбора пользователя происходит запрос пользователю
    # на изменение необходимого поля, либо выход из функции
    try:
        if temp == 1:
            out.print_car_info()
            database.rent_table[row].car_id = int(input("Введите код автомобиля (больше нуля) -> "))
            print("", end="\n")
            if database.rent_table[row].car_id <= 0:
                raise fill.BadIdError
        elif temp == 2:
            out.print_client_info()
            database.rent_table[row].client_id = int(input("Введите код клиента (больше нуля) -> "))
            print("", end="\n")
            if database.rent_table[row].client_id <= 0:
                raise fill.BadIdError
        elif temp == 3:
            out.print_employee_info()
            database.rent_table[row].employee_id = int(input("Введите код сотрудника (больше нуля) -> "))
            print("", end="\n")
            if database.rent_table[row].employee_id <= 0:
                raise fill.BadIdError
        elif temp == 4:
            out.print_service_info()
            database.rent_table[row].service1_id = int(input("Введите код услуги 1 (больше нуля) -> "))
            print("", end="\n")
            if database.rent_table[row].service1_id <= 0:
                raise fill.BadIdError
        elif temp == 5:
            out.print_service_info()
            database.rent_table[row].service2_id = int(input("Введите код услуги 2 (больше нуля) -> "))
            print("", end="\n")
            if database.rent_table[row].service2_id <= 0:
                raise fill.BadIdError
        elif temp == 6:
            out.print_service_info()
            database.rent_table[row].service3_id = int(input("Введите код услуги 3 (больше нуля) -> "))
            print("", end="\n")
            if database.rent_table[row].service3_id <= 0:
                raise fill.BadIdError
        elif temp == 7:
            database.rent_table[row].delivery_date.day = int(input("Введите день даты выдачи -> "))
            print("", end="\n")
            if database.rent_table[row].delivery_date.day < 0 or \
               database.rent_table[row].delivery_date.day > 31:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не день даты выдачи")
        elif temp == 8:
            database.rent_table[row].delivery_date.month = int(input("Введите месяц даты выдачи -> "))
            print("", end="\n")
            if database.rent_table[row].delivery_date.month < 0 or \
               database.rent_table[row].delivery_date.month > 12:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не месяц даты выдачи")
        elif temp == 9:
            database.rent_table[row].delivery_date.year = int(input("Введите год даты выдачи -> "))
            print("", end="\n")
            if database.rent_table[row].delivery_date.year < 0:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год даты выдачи")
        elif temp == 10:
            database.rent_table[row].rent_time = int(input("Введите срок проката -> "))
            print("", end="\n")
        elif temp == 11:
            database.rent_table[row].return_date.day = int(input("Введите день даты возврата -> "))
            print("", end="\n")
            if database.rent_table[row].return_date.day < 0 or \
               database.rent_table[row].return_date.day > 31:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не день даты возврата")
        elif temp == 12:
            database.rent_table[row].return_date.month = int(input("Введите месяц даты возврата -> "))
            print("", end="\n")
            if database.rent_table[row].return_date.month < 0 or \
               database.rent_table[row].return_date.month > 12:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не месяц даты возврата")
        elif temp == 13:
            database.rent_table[row].return_date.year = int(input("Введите год даты возврата -> "))
            print("", end="\n")
            if database.rent_table[row].return_date.year < 0:
                print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год даты возврата")
        elif temp == 14:
            database.rent_table[row].rent_price = int(input("Введите цену проката -> "))
            print("", end="\n")
        elif temp == 15:
            database.rent_table[row].payment_mark = input("Введите отметку об оплате -> ")
            print("", end="\n")
        else:
            print("ОШИБКА: Невозможно найти в записи такой элемент")
    except ValueError:
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except fill.BadIdError:
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")