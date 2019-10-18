#!/usr/bin/python
# -*- coding: utf-8 -*-

# Подключение модулей
import const
import menu


table_row = [0] * 7
activated = 1


def main():
    menu_count = main_menu_switcher(activated)
    menu.menu(const.MAIN_MENU_MODE, menu_count)


def main_menu_switcher(act):
    if act == 0:
        return const.MAIN_MENU_COUNT_NON_ACTIVATED
    else:
        return const.MAIN_MENU_COUNT_ACTIVATED


if __name__ == "__main__":
    main()