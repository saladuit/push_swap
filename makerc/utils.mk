# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    utils.mk                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/03/21 14:57:08 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/21 18:00:45 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

#print functions
print_prefix = printf "$(CYAN_FG)%-$(PROJECT_SPACING)s$(RESET_COLOR) $(GREEN_FG)%-$(RULE_SPACING)s$(RESET_COLOR) : " "[$(1)]" "$(2)"
exec_no_nl = printf "$(1)$(CLEAR_REST_OF_LINE)\n"; $(1) && printf "\e[A"
