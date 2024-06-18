#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "windows.h"

struct vector_2d
{
    int x;
    int y;
    vector_2d()
    {
        this->x = -1;
        this->y = -1;
    }
    vector_2d(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Checkers
{
public:
    std::string game_name =
        "\
█████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗█████╗\n\
██║══╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══██║\n\
██║                ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ ███████╗     ██████╗  █████╗ ███╗   ███╗███████╗               ██║\n\
██║               ██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝               ██║\n\
██║               ██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝███████╗    ██║  ███╗███████║██╔████╔██║█████╗                 ██║\n\
██║               ██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗╚════██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝                 ██║\n\
██║               ╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║███████║    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗               ██║\n\
██║                ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝               ██║\n\
█████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗█████╗\n\
╚════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚════╝";
    std::string congratulation_1 =
        "\
\t\t\t██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗ ██████╗ ███╗   ██╗    ██╗██╗██╗\n\
\t\t\t██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██╔═══██╗████╗  ██║    ██║██║██║\n\
\t\t\t██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║   ██║██╔██╗ ██║    ██║██║██║\n\
\t\t\t██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║   ██║██║╚██╗██║    ╚═╝╚═╝╚═╝\n\
\t\t\t██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝╚██████╔╝██║ ╚████║    ██╗██╗██╗\n\
\t\t\t╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝    ╚═╝╚═╝╚═╝\n\
";
    std::string congratulation_2 =
        "\
\t\t\t██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗ ██████╗ ███╗   ██╗    ██╗██╗██╗\n\
\t\t\t██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██╔═══██╗████╗  ██║    ██║██║██║\n\
\t\t\t██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║   ██║██╔██╗ ██║    ██║██║██║\n\
\t\t\t██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║   ██║██║╚██╗██║    ╚═╝╚═╝╚═╝\n\
\t\t\t██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝╚██████╔╝██║ ╚████║    ██╗██╗██╗\n\
\t\t\t╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝    ╚═╝╚═╝╚═╝\n\
";
    std::vector<std::vector<std::string>> nums = {
        {"   ██╗    ",
         "  ███║    ",
         "  ╚██║    ",
         "   ██║    ",
         "   ██║    "},

        {" ██████╗  ",
         " ╚════██╗ ",
         "  █████╔╝ ",
         " ██╔═══╝  ",
         " ███████╗ "},

        {" ██████╗  ",
         " ╚════██╗ ",
         "  █████╔╝ ",
         "  ╚═══██╗ ",
         " ██████╔╝ "},

        {" ██╗  ██╗ ",
         " ██║  ██║ ",
         " ███████║ ",
         " ╚════██║ ",
         "      ██║ "},
        {
            " ███████╗ ",
            " ██╔════╝ ",
            " ███████╗ ",
            " ╚════██║ ",
            " ███████║ ",
        },
        {
            "  ██████╗ ",
            " ██╔════╝ ",
            " ███████╗ ",
            " ██╔═══██╗",
            " ╚██████╔╝",
        },
        {
            " ███████╗ ",
            " ╚════██║ ",
            "     ██╔╝ ",
            "    ██╔╝  ",
            "    ██║   ",
        },
        {
            "  █████╗  ",
            " ██╔══██╗ ",
            " ╚█████╔╝ ",
            " ██╔══██╗ ",
            " ╚█████╔╝ ",
        }};

    std::string bord = "          ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────";
    std::string wall = "║";
    std::string space = "               ";
    std::vector<std::string> white_bord = {
        "───────────────",
        "───────────────",
        "───────────────",
        "───────────────",
        "───────────────"};
    std::vector<std::string> black = {
        "────▄───▄──────",
        "────░▀░▀░──────",
        "────░▄░▄░──────",
        "─────░░░──▄▄───",
        "─────░░░░░░─░──"};
    std::vector<std::string> black_2 = {
        "─────(° ͜ʖ°)───",
        "──╚═(░░░░░░)═╝─",
        "─╚═(░░░░░░)═╝──",
        "─╚═(░░░░░░)═╝──",
        "──╚═(░░░░░░)═╝─"};
    std::vector<std::string> black_3 = {
        "┈┈╭┻┻┻┻┻┻┻┻┻╮┈┈",
        "┈┈┃╱╲╱╲╱╲╱╲╱┃┈┈",
        "┈╭┻━━━━━━━━━┻╮┈",
        "┈┃╱╲╱╲╱╲╱╲╱╲╱┃┈",
        "┈┗━━━━━━━━━━━┛┈"};
    std::vector<std::string> white = {
        "────▄───▄──────",
        "────▓▀█▀▓──────",
        "────█▄█▄█──────",
        "─────███──▄▄───",
        "─────████▐█─█──"};
    std::vector<std::string> white_2 = {
        "─────(° ͜ʖ°)───",
        "──╚═(██████)═╝─",
        "─╚═(██████)═╝──",
        "─╚═(██████)═╝──",
        "──╚═(██████)═╝─"};
    std::vector<std::vector<int>> cheakers{
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, 0, 1, 0, 1, 0, 1, 0, 1, -1},
        {-1, 1, 0, 1, 0, 1, 0, 1, 0, -1},
        {-1, 0, 1, 0, 1, 0, 1, 0, 1, -1},
        {-1, 0, 0, 0, 0, 0, 0, 0, 0, -1},
        {-1, 0, 0, 0, 0, 0, 0, 0, 0, -1},
        {-1, 2, 0, 2, 0, 2, 0, 2, 0, -1},
        {-1, 0, 2, 0, 2, 0, 2, 0, 2, -1},
        {-1, 2, 0, 2, 0, 2, 0, 2, 0, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};

    int count_ckeackers_p_1 = 12;
    int count_ckeackers_p_2 = 12;

    vector_2d checker_player_1;
    vector_2d checker_player_2;

    vector_2d player_1_pos;
    vector_2d player_2_pos;
    std::vector<vector_2d> all_pos_to_move_1;

    std::vector<int> players_first_active_checker = {-1, -1};
    std::vector<int> players_second_active_checker = {-1, -1};

    std::vector<int> players_first_pos = {-1, -1};
    std::vector<int> players_second_pos = {-1, -1};

public:
    bool can_select(int player, int enemy, vector_2d &checker_position, int delta)
    {
        if (this->cheakers[checker_position.x][checker_position.y] == player)
        {
            if (this->cheakers[checker_position.x + delta][checker_position.y - 1] == 0)
                return 1;
            if (this->cheakers[checker_position.x + delta][checker_position.y + 1] == 0)
                return 1;
            if ((this->cheakers[checker_position.x + delta][checker_position.y - 1] == enemy) ||
                (this->cheakers[checker_position.x + delta][checker_position.y - 1] == enemy + 2))
                if (this->cheakers[checker_position.x + 2 * delta][checker_position.y - 2] == 0)
                    return 1;
            if ((this->cheakers[checker_position.x + delta][checker_position.y + 1] == enemy) ||
                (this->cheakers[checker_position.x + delta][checker_position.y + 1] == enemy + 2))
                if (this->cheakers[checker_position.x + 2 * delta][checker_position.y + 2] == 0)
                    return 1;
        }
        else if (this->cheakers[checker_position.x][checker_position.y] == player + 2)
        {
            if (this->cheakers[checker_position.x - delta][checker_position.y - 1] == 0)
                return 1;
            if (this->cheakers[checker_position.x - delta][checker_position.y + 1] == 0)
                return 1;
            if (this->cheakers[checker_position.x + delta][checker_position.y - 1] == 0)
                return 1;
            if (this->cheakers[checker_position.x + delta][checker_position.y + 1] == 0)
                return 1;
            if ((this->cheakers[checker_position.x - delta][checker_position.y - 1] == enemy) ||
                (this->cheakers[checker_position.x - delta][checker_position.y - 1] == enemy))
                if (this->cheakers[checker_position.x - 2 * delta][checker_position.y - 2] == 0)
                    return 1;
            if ((this->cheakers[checker_position.x - delta][checker_position.y + 1] == enemy) ||
                (this->cheakers[checker_position.x - delta][checker_position.y + 1] == enemy))
                if (this->cheakers[checker_position.x - 2 * delta][checker_position.y + 2] == 0)
                    return 1;
            if ((this->cheakers[checker_position.x + delta][checker_position.y - 1] == enemy) ||
                (this->cheakers[checker_position.x + delta][checker_position.y - 1] == enemy))
                if (this->cheakers[checker_position.x + 2 * delta][checker_position.y - 2] == 0)
                    return 1;
            if ((this->cheakers[checker_position.x + delta][checker_position.y + 1] == enemy) ||
                (this->cheakers[checker_position.x + delta][checker_position.y + 1] == enemy))
                if (this->cheakers[checker_position.x + 2 * delta][checker_position.y + 2] == 0)
                    return 1;
        }
        return false;
    }
    bool can_move(int own, int enemy, vector_2d &checker_position, vector_2d &position_to_move, int delta)
    {
        if (this->cheakers[checker_position.x][checker_position.y] == own)
        {
            int count = 0;
            if (position_to_move.x - checker_position.x == delta)
                count++;
            if ((position_to_move.y - checker_position.y == 1) ||
                (position_to_move.y - checker_position.y == -1))
                count++;
            if (count != 2)
                return 0;
            if (this->cheakers[position_to_move.x][position_to_move.y] == 0)
                return 1;
            if ((this->cheakers[position_to_move.x][position_to_move.y] == enemy) ||
                (this->cheakers[position_to_move.x][position_to_move.y] == enemy + 2))
            {
                if (position_to_move.y - 1 < 0)
                    return 0;
                if (position_to_move.y + 1 > 7)
                    return 0;
                if (this->cheakers[position_to_move.x + delta][position_to_move.y + (position_to_move.y - checker_position.y)] == 0)
                    return 1;
            }
        }
        else if (this->cheakers[checker_position.x][checker_position.y] == own + 2)
        {
            delta = 1;
            int count = 0;
            if (abs(position_to_move.x - checker_position.x) < 8)
                count++;
            if ((abs(position_to_move.y - checker_position.y) < 8))
                count++;
            if (count != 2)
                return 0;
            if (abs(position_to_move.x - checker_position.x) != abs(position_to_move.y - checker_position.y))
                return 0;
            int sign_x = 0;
            int sign_y = 0;
            if (checker_position.x - position_to_move.x < 0)
            {
                if (checker_position.y - position_to_move.y < 0)
                {
                    sign_y = 1;
                    sign_x = 1;
                }
                else if (checker_position.y - position_to_move.y >= 0)
                {
                    sign_y = -1;
                    sign_x = 1;
                }
            }
            else if (checker_position.x - position_to_move.x >= 0)
            {
                if (checker_position.y - position_to_move.y < 0)
                {
                    sign_y = 1;
                    sign_x = -1;
                }
                if (checker_position.y - position_to_move.y >= 0)
                {
                    sign_y = -1;
                    sign_x = -1;
                }
            }
            if (this->cheakers[position_to_move.x][position_to_move.y] == 0)
            {
                int together = 0;
                int count_enemy = 0;
                for (int count_pos = 1; count_pos <= abs(checker_position.x - position_to_move.x); count_pos++)
                {
                    std::cout << checker_position.x + sign_x * count_pos << ' ' << checker_position.y + sign_y * count_pos << '\n';
                    if ((this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == own) ||
                        (this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == own + 2))
                        return 0;

                    if ((this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy) ||
                        (this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy + 2))
                    {
                        count_enemy++;
                        together++;
                        if (together == 2)
                            return 0;
                    }
                    else
                    {
                        together = 0;
                    }
                }
            }
            else if ((this->cheakers[position_to_move.x][position_to_move.y] == enemy) ||
                     (this->cheakers[position_to_move.x][position_to_move.y] == enemy + 2))
            {
                int together = 0;
                int count_enemy = 0;
                for (int count_pos = 1; count_pos <= abs(checker_position.x - position_to_move.x); count_pos++)
                {
                    if ((this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy) ||
                        (this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy + 2))
                    {
                        count_enemy++;
                        together++;
                        if (together == 2)
                            return 0;
                    }
                    else
                    {
                        together = 0;
                    }
                }
                if (this->cheakers[position_to_move.x + sign_x][position_to_move.y + sign_y] == 0)
                    return 1;
                return 0;
            }
            return 1;
        }
        return 0;
    }
    void move_checker(vector_2d &checker_position, vector_2d &position_to_move, int own, int enemy, int delta, int &count_enemy)
    {
        if (this->cheakers[checker_position.x][checker_position.y] == own)
        {
            if (this->cheakers[position_to_move.x][position_to_move.y] == 0)
            {
                if ((own == 1) && (position_to_move.x == 8))
                {
                    this->cheakers[checker_position.x][checker_position.y] = 0;
                    this->cheakers[position_to_move.x][position_to_move.y] = own + 2;
                }
                else if ((own == 2) && (position_to_move.x == 1))
                {
                    this->cheakers[checker_position.x][checker_position.y] = 0;
                    this->cheakers[position_to_move.x][position_to_move.y] = own + 2;
                }
                else
                {
                    this->cheakers[checker_position.x][checker_position.y] = 0;
                    this->cheakers[position_to_move.x][position_to_move.y] = own;
                }
            }
            if ((this->cheakers[position_to_move.x][position_to_move.y] == enemy) ||
                (this->cheakers[position_to_move.x][position_to_move.y] == enemy + 2))
            {
                if ((own == 1) && (position_to_move.x + 1 == 8))
                {
                    this->cheakers[checker_position.x][checker_position.y] = 0;
                    this->cheakers[position_to_move.x][position_to_move.y] = 0;
                    this->cheakers[position_to_move.x + delta][position_to_move.y + (position_to_move.y - checker_position.y)] = own + 2;
                    count_enemy--;
                }
                else if ((own == 2) && (position_to_move.x - 1 == 1))
                {
                    this->cheakers[checker_position.x][checker_position.y] = 0;
                    this->cheakers[position_to_move.x][position_to_move.y] = 0;
                    this->cheakers[position_to_move.x + delta][position_to_move.y + (position_to_move.y - checker_position.y)] = own + 2;
                    count_enemy--;
                }
                else
                {
                    this->cheakers[checker_position.x][checker_position.y] = 0;
                    this->cheakers[position_to_move.x][position_to_move.y] = 0;
                    this->cheakers[position_to_move.x + delta][position_to_move.y + (position_to_move.y - checker_position.y)] = own;
                    count_enemy--;
                }
            }
        }
        else if (this->cheakers[checker_position.x][checker_position.y] == own + 2)
        {
            delta = 1;
            int sign_x = 0;
            int sign_y = 0;
            if (checker_position.x - position_to_move.x < 0)
            {
                if (checker_position.y - position_to_move.y < 0)
                {
                    sign_y = 1;
                    sign_x = 1;
                }
                else if (checker_position.y - position_to_move.y >= 0)
                {
                    sign_y = -1;
                    sign_x = 1;
                }
            }
            else if (checker_position.x - position_to_move.x >= 0)
            {
                if (checker_position.y - position_to_move.y < 0)
                {
                    sign_y = 1;
                    sign_x = -1;
                }
                if (checker_position.y - position_to_move.y >= 0)
                {
                    sign_y = -1;
                    sign_x = -1;
                }
            }
            if (this->cheakers[position_to_move.x][position_to_move.y] == 0)
            {
                bool enemy_die = false;
                for (int count_pos = 1; count_pos <= abs(checker_position.x - position_to_move.x); count_pos++)
                {
                    if ((this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy) ||
                        (this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy + 2))
                    {
                        this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] = 0;
                        count_enemy--;
                    };
                }
                this->cheakers[position_to_move.x][position_to_move.y] = own + 2;
                this->cheakers[checker_position.x][checker_position.y] = 0;
            }
            else if ((this->cheakers[position_to_move.x][position_to_move.y] == enemy) ||
                     (this->cheakers[position_to_move.x][position_to_move.y] == enemy + 2))
            {
                bool enemy_die = false;
                for (int count_pos = 1; count_pos <= abs(checker_position.x - position_to_move.x); count_pos++)
                {
                    std::cout << checker_position.x + sign_x * count_pos << ' ' << checker_position.y + sign_y * count_pos << '\n';
                    if ((this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy) ||
                        (this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] == enemy + 2))
                    {
                        this->cheakers[checker_position.x + sign_x * count_pos][checker_position.y + sign_y * count_pos] = 0;
                        count_enemy--;
                    };
                }
                this->cheakers[checker_position.x][checker_position.y] = 0;
                this->cheakers[position_to_move.x][position_to_move.y] = 0;
                this->cheakers[position_to_move.x + sign_x][position_to_move.y + sign_y] = own + 2;
                count_enemy--;
            }
        }
    }
    void input_first_player()
    {
        std::cout << "Player 1: ";
    start_1:
        std::cout << "Pick checker: ";
        vector_2d checker_position;
        std::cin >> checker_position.x >> checker_position.y;
        if (Checkers::can_select(1, 2, checker_position, 1))
        {
            this->checker_player_1.x = checker_position.x;
            this->checker_player_1.y = checker_position.y;
        }
        else
        {
            std::cout << "\nYou don't select this checkerTRY again\n";
            goto start_1;
        }
        std::cout << "Checker: " << this->checker_player_1.x << 'x' << this->checker_player_1.y;
    start_2:
        std::cout << "\nPick move position: ";
        vector_2d position_to_move;
        std::cin >> position_to_move.x >> position_to_move.y; // 2 1
        if (Checkers::can_move(1, 2, this->checker_player_1, position_to_move, 1))
        {
            this->player_1_pos.x = position_to_move.x;
            this->player_1_pos.y = position_to_move.y;
        }
        else
        {
            std::cout << "\nYou don't move  this position again\n";
            goto start_2;
        }
        Checkers::move_checker(checker_player_1, player_1_pos, 1, 2, 1, this->count_ckeackers_p_2);
    }
    void input_second_player()
    {
        std::cout << "Player 2: ";
    start_1:
        vector_2d checker_position;
        checker_position.x = rand() % 8 + 1;
        checker_position.y = rand() % 8 + 1;

        if (Checkers::can_select(2, 1, checker_position, -1))
        {
            this->checker_player_2.x = checker_position.x;
            this->checker_player_2.y = checker_position.y;
        }
        else
        {
            goto start_1;
        }
        std::cout << "Checker: " << this->checker_player_2.x << 'x' << this->checker_player_2.y;
        std::vector<vector_2d> mb_positions;

        vector_2d checker_move_1;
        checker_move_1.x = checker_position.x - 1;
        checker_move_1.y = checker_position.y - 1;
        vector_2d checker_move_2;
        checker_move_2.x = checker_position.x + 1;
        checker_move_2.y = checker_position.y + 1;
        vector_2d checker_move_3;
        checker_move_3.x = checker_position.x - 1;
        checker_move_3.y = checker_position.y + 1;
        vector_2d checker_move_4;
        checker_move_4.x = checker_position.x + 1;
        checker_move_4.y = checker_position.y - 1;

        mb_positions.push_back(checker_move_1);
        mb_positions.push_back(checker_move_2);
        mb_positions.push_back(checker_move_3);
        mb_positions.push_back(checker_move_4);

    start_2:
        int variant = rand() % 4;

        if (Checkers::can_move(2, 1, this->checker_player_2, mb_positions[variant], -1))
        {
            this->player_2_pos.x = mb_positions[variant].x;
            this->player_2_pos.y = mb_positions[variant].y;
        }
        else
        {
            goto start_2;
        }
        Checkers::move_checker(checker_player_2, player_2_pos, 2, 1, -1, this->count_ckeackers_p_1);
    }
    void Clear_window()
    {
        system("cls");
    }
    void Sleep_()
    {
        std::cin.get();
        std::cin.get();
        std::cin.get();
    }
    void Print_bord()
    {
        std::cout
            << this->game_name << "\n\n\n";
        for (int i_x = 0; i_x < 5; i_x++)
        {
            std::cout << "       ";
            for (int i_y = 0; i_y < 8; i_y++)
            {
                std::cout << "      " << nums[i_y][i_x];
            }
            std::cout << '\n';
        }
        std::cout << this->bord << '\n';
        int x = 1;
        for (int i = 0; i <= 39; i++)
        {
            int y = x;
            if ((i % 5 == 0) && (i != 0))
            {
                std::cout << this->bord << '\n';
                x++;
            }
            std::cout << nums[x - 1][i % 5];
            std::cout << this->wall;
            for (int j = 1; j < 9; j++)
            {
                if (this->cheakers[x][j] == 1)
                    std::cout << this->black[i % 5] << this->wall;
                else if (this->cheakers[x][j] == 2)
                    std::cout << this->white[i % 5] << this->wall;
                else if (this->cheakers[x][j] == 3)
                    std::cout << this->black_2[i % 5] << this->wall;
                else if (this->cheakers[x][j] == 4)
                    std::cout << this->white_2[i % 5] << this->wall;
                else
                {
                    if ((x + j) % 2 == 1)
                        std::cout << this->white_bord[i % 5] << this->wall;
                    else
                        std::cout << this->space << this->wall;
                }
                y++;
            }
            std::cout << '\n';
        }
        std::cout << this->bord << '\n';
    }

public:
    void Start()
    {
        int n = 0;
        while (1)
        {
            if (this->count_ckeackers_p_1 <= 0)
            {
                std::cout << "\n\n\n\n"
                          << this->congratulation_2;
                break;
            }
            if (this->count_ckeackers_p_2 <= 0)
            {
                std::cout << "\n\n\n\n"
                          << this->congratulation_1;
                break;
            }
            Checkers::Print_bord();
            if (n % 2 == 0)
                Checkers::input_first_player();
            else
            {
                Sleep(1000);
                Checkers::input_second_player();
            }
            Checkers::Clear_window();
            n++;
        }
        Checkers::Sleep_();
    }
};
int main()
{
    Checkers checkers;
    srand(time(0));
    checkers.Start();
    return 0;
}