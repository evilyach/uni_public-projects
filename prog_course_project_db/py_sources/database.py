# -*- coding: utf-8 -*-

# Встроенные библиотеки
import enum


# Перечисление "Пол"
class Gender(enum.Enum):
    male = 0
    female = 1


# Структура "Дата"
class Date:
    day = 0                     # День
    month = 0                   # Месяц
    year = 0                    # Год


# Структура "Сотрудники"
class EmployeeT:
    employee_id = 0             # Код сотрудника
    position_id = 0             # Код должности
    name = ""                   # ФИО
    age = 0                     # Возраст
    gender = Gender.male        # Пол
    address = ""                # Адрес
    phone = ""                  # Телефон
    passport = ""               # Паспортные данные


# Структура "Должности"
class PositionT:
    position_id = 0             # Код должности
    name = ""                   # Наименование
    salary = 0                  # Оклад
    duties = ""                 # Обязанности
    requirements = ""           # Требования


# Структура "Марки автомобилей"
class BrandT:
    brand_id = 0                # Код марки
    name = ""                   # Наименование
    specs = ""                  # Технические характеристики
    description = ""            # Описание


# Структура "Дополнительные услуги"
class ServiceT:
    service_id = 0              # Код услуги
    name = ""                   # Наименование
    description = ""            # Описание
    price = 0                   # Цена


# Структура "Автомобили"
class CarT:
    car_id = 0                  # Код автомобиля
    brand_id = 0                # Код марки
    employee_id = 0             # Код сотрудника-механика
    reg_number = 0              # Регистрационный номер
    body_number = 0             # Номер кузова
    engine_number = 0           # Номер двигателя
    release_year = 0            # Год выпуска
    price = 0                   # Цена автомобиля
    rent_price = 0              # Цена дня проката
    maintenance_date = Date()   # Дата последнего ТО
    special_marks = ""          # Специальные отметки
    return_mark = ""            # Отметка о возврате


# Структура "Клиенты"
class ClientT:
    client_id = 0               # Код клиента
    name = ""                   # ФИО
    gender = Gender.male        # Пол
    birth_date = Date()         # Дата рождения
    address = ""                # Адрес
    phone = ""                  # Телефон
    passport = ""               # Паспортные данные


# Структура "Прокат"
class RentT:
    car_id = 0                  # Код автомобиля
    client_id = 0               # Код клиента
    employee_id = 0             # Код сотрудника
    service1_id = 0             # Код услуги 1
    service2_id = 0             # Код услуги 2
    service3_id = 0             # Код услуги 3
    delivery_date = Date()      # Дата выдачи
    rent_time = 0               # Срок проката
    return_date = Date()        # Дата возврата
    rent_price = 0              # Цена проката
    payment_mark = ""           # Пометка об оплате


# Таблицы базы данных
employee_table = []
position_table = []
brand_table = []
service_table = []
car_table = []
client_table = []
rent_table = []