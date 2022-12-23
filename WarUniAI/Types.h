#pragma once
#include <string>
#include <map>

//enums
enum class EErrorCode
{
    OK,
    CLIENT_WINDOW_ERROR
};

enum class EServer
{
    EUROPE,
    TEST,
    TURK
};

enum class ELang
{
    CS,
    EN
};


//structs
struct SPoint
{
    int x;
    int y;
};

//functions
std::string GetNameOfError(EErrorCode error);


//constants
const wchar_t CLIENT_WINDOW_NAME[] = L"WarUniverse";
const int LOGIN_SAVED_INCREMENT = 20;
const int WINDOWS_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;
const int Y_OFFSET = 30;
const std::map<std::string, SPoint> CLIENT_COORDINATIONS
{
    //-------- login menu -------
    {"lang_button", {40, 735}},
    {"login_name_textarea", {320, 347}},
    {"login_pass_textarea", {500, 347}},
    {"login_button", {700, 400}},
    {"server_button", {96, 735}},
    {"login_saved", {404, 502}},

    // --------  game ------
    //rocket menu
    {"rocket_menu", {932, 457}},
    {"rocket_menu_shot", {905, 302}},
    {"rocket_menu_autofire", {908, 589}},
    {"rocket_menu_x1", {809, 557}},
    {"rocket_menu_x2", {779, 451}},
    {"rocket_menu_x3", {800, 353}},

    //laser menu
    {"laser_menu", {932, 457}},
    {"laser_menu_x1", {924, 697}},
    {"laser_menu_x2", {830, 680}},
    {"laser_menu_x3", {786, 612}},
    {"laser_menu_x4", {781, 523}},
    {"laser_menu_x5", {831, 437}},  //shield ammo
    {"laser_menu_x6", {917, 422}},

    //controls
    {"attack", {901, 694}},
    {"configuraiton_switch", {836, 623}},


    {"ingame_menu", {492, 731}},
    {"ingame_menu_close", {951, 128}},
    {"logout", {82, 635}},


};