#!/bin/bash
echo hi
echo huh

f1r6s9% ./mini_shell
Minishell:    
Minishell:
Minishell:                                                                                           
Minishell:
Minishell:
Minishell:
Minishell:           
Minishell:           
Minishell:





Minishell:
Minishell:
Minishell:
Minishell:
Minishell:|
Syntax error;
Minishell:echo |
syntax error to the right of token '|'
Minishell:echo | |
syntax error near unexpected token '|'
Minishell:echo | | cat
syntax error near unexpected token '|'
Minishell:echo || cat
Syntax error;
Minishell:echo >< cat
syntax error near unexpected token '<'
Minishell:echo >
syntax error to the right of token '>'
Minishell:echo <
syntax error to the right of token '<'
Minishell:<<
Syntax error;
Minishell:>>
Syntax error;
Minishell:>
Syntax error;
Minishell:<
Syntax error;
Minishell:echo >><
syntax error near unexpected token '<'
Minishell:echo >>>
syntax error near unexpected token '>'
Minishell:echo >>>>>>>>>>>>>>>>>
syntax error near unexpected token '>>'
Minishell:echo >> >
syntax error near unexpected token '>'
Minishell:echo >> > cat
syntax error near unexpected token '>'
Minishell:echo < < cat
syntax error near unexpected token '<'
Minishell:echo < cat
No permissions to open file. filename: 'cat'
Minishell:echo -n
Minishell:echo -n asd
asdMinishell:echo -n asd asd
asd asdMinishell:echo -nnnnnnn asd asd
asd asdMinishell:echo -nnnnnnna asd asd
asd asdMinishell:echo -na asd asd
asd asdMinishell:echo -a asd asd
-a asd asd
Minishell:echo -na asd asd
asd asdMinishell:echo -n-a asd asd
asd asdMinishell:echo -n-a -n asd asd
-n asd asdMinishell:echo -n -n 
-nMinishell:echo -n -n asd
-n asdMinishell:echo

Minishell:echo asd
asd
Minishell:echo echo
echo
Minishell:echo -nnnnnna
Minishell:echo -nnnnnna asd
asdMinishell:cd
Minishell:pwd
/home/diwang
Minishell:cd -
no such path: No such file or directory
Minishell:
f1r6s9% ./mini_shell
Minishell:pwd
/home/diwang/Projects/MS1
Minishell:cd ..
Minishell:pwd
/home/diwang/Projects
Minishell:cd MS1
Minishell:ls
includes  Makefile  mini_shell	src  trash
Minishell:pwd
/home/diwang/Projects/MS1
Minishell:cd src/
Minishell:ls
main.c	main_j.o  main.o  minishell  testing_functions
Minishell:cd //////////////////////////////////////////////////////////////////
Minishell:pwd
/
Minishell:
f1r6s9% ./mini_shell
Minishell:cd ../../../.././././..././../
no such path: No such file or directory
Minishell:cd ../../../.././././.././../
Minishell:pwd
/
Minishell:
f1r6s9% ./mini_shell
Minishell:cd asd
no such path: No such file or directory
Minishell:echo $?
0
Minishell:cd asd
no such path: No such file or directory
Minishell:$?
Command '0' not found.
Minishell:unset HOME
Minishell:cd
no such path: Bad address
Minishell:echo $?
127
Minishell:
f1r6s9% ./mini_shell
Minishell:env | grep PWD
PWD=/home/diwang/Projects/MS1
OLDPWD=/home/diwang/Projects
Minishell:cd
Minishell:env | grep PWD
PWD=/home/diwang
OLDPWD=/home/diwang/Projects/MS1
Minishell:cd
Minishell:env | grep PWD
PWD=/home/diwang
OLDPWD=/home/diwang
Minishell:unset OLDPWD
Minishell:cd
Minishell:unset OLDPWD
Minishell:cd /
Minishell:env | grep PWD
PWD=/
Minishell:unset PWD
Minishell:cd
Minishell:cd /
Minishell:unset PWD
Minishell:cd
Minishell:env | grep PWD
Minishell:
f1r6s9% ./mini_shell
Minishell:mkdir test
Minishell:cd tes
no such path: No such file or directory
Minishell:cd test
Minishell:rmdir ../test/
Minishell:pwd
Minishell:cd ..
Minishell:pwd
/home/diwang/Projects/MS1
Minishell:mkdir test
Minishell:cd test
Minishell:mkdir test1
Minishell:cd test1
Minishell:rm -rf ../../test/
Minishell:pwd
Minishell:pwd
Minishell:cd ..
Minishell:pwd
Minishell:cd ..
Minishell:pwd
/home/diwang/Projects/MS1
Minishell:ls
includes  Makefile  mini_shell	src  trash
Minishell:env
LC_TELEPHONE=nl_NL.UTF-8
DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
GDMSESSION=ubuntu
DESKTOP_SESSION=ubuntu
PWD=
LC_COLLATE=en_US.UTF-8
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LOGNAME=diwang
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
LC_MEASUREMENT=nl_NL.UTF-8
XDG_SESSION_TYPE=x11
SYSTEMD_EXEC_PID=39811
SSH_AGENT_LAUNCHER=gnome-keyring
HOME=/home/diwang
QT_IM_MODULE=ibus
KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
USER=diwang
DISPLAY=:0
FT_HOOK_NAME=login-user
PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
LANG=en_US.UTF-8
LC_NAME=nl_NL.UTF-8
FEH_PID=39236
XAUTHORITY=/home/diwang/.Xauthority
LC_PAPER=nl_NL.UTF-8
LANGUAGE=en
SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
XDG_RUNTIME_DIR=/run/user/162600
LC_MESSAGES=en_US.UTF-8
XDG_SESSION_DESKTOP=ubuntu
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
VTE_VERSION=6800
XDG_CURRENT_DESKTOP=ubuntu:GNOME
LIBVIRT_DEFAULT_URI=qemu:///system
XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
GNOME_TERMINAL_SERVICE=:1.116
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
LC_ALL=
LC_ADDRESS=nl_NL.UTF-8
SHELL=/bin/zsh
GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
GTK_IM_MODULE=ibus
XDG_SESSION_CLASS=user
GTK_MODULES=gail:atk-bridge
XMODIFIERS=@im=ibus
YAD_PID=39652
LC_IDENTIFICATION=nl_NL.UTF-8
LC_CTYPE=en_US.UTF-8
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
FT_HOOK_PATHNAME=login-user.d
LC_NUMERIC=nl_NL.UTF-8
TERM=xterm-256color
XDG_MENU_PREFIX=gnome-
COLORTERM=truecolor
LC_TIME=nl_NL.UTF-8
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
QT_ACCESSIBILITY=1
SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
LC_MONETARY=nl_NL.UTF-8
SHLVL=1
OLDPWD=
DOCKER_HOST=unix:///run/user/162600/docker.sock
_=/home/diwang/Projects/MS1/./mini_shell
Minishell:unset LC_TELEPHONE 
Minishell:env
DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
GDMSESSION=ubuntu
DESKTOP_SESSION=ubuntu
PWD=
LC_COLLATE=en_US.UTF-8
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LOGNAME=diwang
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
LC_MEASUREMENT=nl_NL.UTF-8
XDG_SESSION_TYPE=x11
SYSTEMD_EXEC_PID=39811
SSH_AGENT_LAUNCHER=gnome-keyring
HOME=/home/diwang
QT_IM_MODULE=ibus
KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
USER=diwang
DISPLAY=:0
FT_HOOK_NAME=login-user
PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
LANG=en_US.UTF-8
LC_NAME=nl_NL.UTF-8
FEH_PID=39236
XAUTHORITY=/home/diwang/.Xauthority
LC_PAPER=nl_NL.UTF-8
LANGUAGE=en
SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
XDG_RUNTIME_DIR=/run/user/162600
LC_MESSAGES=en_US.UTF-8
XDG_SESSION_DESKTOP=ubuntu
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
VTE_VERSION=6800
XDG_CURRENT_DESKTOP=ubuntu:GNOME
LIBVIRT_DEFAULT_URI=qemu:///system
XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
GNOME_TERMINAL_SERVICE=:1.116
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
LC_ALL=
LC_ADDRESS=nl_NL.UTF-8
SHELL=/bin/zsh
GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
GTK_IM_MODULE=ibus
XDG_SESSION_CLASS=user
GTK_MODULES=gail:atk-bridge
XMODIFIERS=@im=ibus
YAD_PID=39652
LC_IDENTIFICATION=nl_NL.UTF-8
LC_CTYPE=en_US.UTF-8
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
FT_HOOK_PATHNAME=login-user.d
LC_NUMERIC=nl_NL.UTF-8
TERM=xterm-256color
XDG_MENU_PREFIX=gnome-
COLORTERM=truecolor
LC_TIME=nl_NL.UTF-8
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
QT_ACCESSIBILITY=1
SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
LC_MONETARY=nl_NL.UTF-8
SHLVL=1
OLDPWD=
DOCKER_HOST=unix:///run/user/162600/docker.sock
_=/home/diwang/Projects/MS1/./mini_shell
Minishell:export asd=asd
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd=asd
Minishell:export asd1=asd
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd=asd
declare -x asd1=asd
Minishell:export asd=as asddd=asd
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd=as
declare -x asd1=asd
Minishell:export asd===============================as
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd===============================as
declare -x asd1=asd
Minishell:export asd=export asd====asd
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd====asd
declare -x asd1=asd
Minishell:unset asd
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd1=asd
Minishell:export sad=
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd1=asd
declare -x sad=
Minishell:echo $sad

Minishell:export sad
Minishell:export r
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd1=asd
declare -x sad=
Minishell:export []r=asd
Export variable has to start with alphabetical characters.
Minishell:echo $?
0
Minishell:export 1asd=asd
Export variable has to start with alphabetical characters.
Minishell:ec
Command 'ec' not found.
Minishell:echo $?
127
Minishell:export 1asd=asd
Export variable has to start with alphabetical characters.
Minishell:echo $?
127
Minishell:
Minishell:
Minishell:echo $?
127
Minishell:echo

Minishell:echo $?
127
Minishell:cat
Minishell:echo $?
0
Minishell:export [=asd
Export variable has to start with alphabetical characters.
Minishell:export =asd
Export variable has to start with alphabetical characters.
Minishell:export 1=asd
Export variable has to start with alphabetical characters.
Minishell:export as1=asd
Minishell:export
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd1=asd
declare -x sad=
declare -x as1=asd
Minishell:
f1r6s9% ./mini_shell
Minishell:unset PATH
Minishell:cd
Minishell:echo

Minishell:[wd
Command '[wd' not found.
Minishell:pwd
/home/diwang
Minishell:export sad=sad
Minishell:env
LC_TELEPHONE=nl_NL.UTF-8
DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
GDMSESSION=ubuntu
DESKTOP_SESSION=ubuntu
PWD=/home/diwang
LC_COLLATE=en_US.UTF-8
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LOGNAME=diwang
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
LC_MEASUREMENT=nl_NL.UTF-8
XDG_SESSION_TYPE=x11
SYSTEMD_EXEC_PID=39811
SSH_AGENT_LAUNCHER=gnome-keyring
HOME=/home/diwang
QT_IM_MODULE=ibus
KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
USER=diwang
DISPLAY=:0
FT_HOOK_NAME=login-user
LANG=en_US.UTF-8
LC_NAME=nl_NL.UTF-8
FEH_PID=39236
XAUTHORITY=/home/diwang/.Xauthority
LC_PAPER=nl_NL.UTF-8
LANGUAGE=en
SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
XDG_RUNTIME_DIR=/run/user/162600
LC_MESSAGES=en_US.UTF-8
XDG_SESSION_DESKTOP=ubuntu
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
VTE_VERSION=6800
XDG_CURRENT_DESKTOP=ubuntu:GNOME
LIBVIRT_DEFAULT_URI=qemu:///system
XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
GNOME_TERMINAL_SERVICE=:1.116
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
LC_ALL=
LC_ADDRESS=nl_NL.UTF-8
SHELL=/bin/zsh
GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
GTK_IM_MODULE=ibus
XDG_SESSION_CLASS=user
GTK_MODULES=gail:atk-bridge
XMODIFIERS=@im=ibus
YAD_PID=39652
LC_IDENTIFICATION=nl_NL.UTF-8
LC_CTYPE=en_US.UTF-8
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
FT_HOOK_PATHNAME=login-user.d
LC_NUMERIC=nl_NL.UTF-8
TERM=xterm-256color
XDG_MENU_PREFIX=gnome-
COLORTERM=truecolor
LC_TIME=nl_NL.UTF-8
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
QT_ACCESSIBILITY=1
SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
LC_MONETARY=nl_NL.UTF-8
SHLVL=1
OLDPWD=/home/diwang/Projects/MS1
DOCKER_HOST=unix:///run/user/162600/docker.sock
_=/home/diwang/Projects/MS1/./mini_shell
sad=sad
Minishell:unset sad
Minishell:env
LC_TELEPHONE=nl_NL.UTF-8
DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
GDMSESSION=ubuntu
DESKTOP_SESSION=ubuntu
PWD=/home/diwang
LC_COLLATE=en_US.UTF-8
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LOGNAME=diwang
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
LC_MEASUREMENT=nl_NL.UTF-8
XDG_SESSION_TYPE=x11
SYSTEMD_EXEC_PID=39811
SSH_AGENT_LAUNCHER=gnome-keyring
HOME=/home/diwang
QT_IM_MODULE=ibus
KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
USER=diwang
DISPLAY=:0
FT_HOOK_NAME=login-user
LANG=en_US.UTF-8
LC_NAME=nl_NL.UTF-8
FEH_PID=39236
XAUTHORITY=/home/diwang/.Xauthority
LC_PAPER=nl_NL.UTF-8
LANGUAGE=en
SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
XDG_RUNTIME_DIR=/run/user/162600
LC_MESSAGES=en_US.UTF-8
XDG_SESSION_DESKTOP=ubuntu
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
VTE_VERSION=6800
XDG_CURRENT_DESKTOP=ubuntu:GNOME
LIBVIRT_DEFAULT_URI=qemu:///system
XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
GNOME_TERMINAL_SERVICE=:1.116
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
LC_ALL=
LC_ADDRESS=nl_NL.UTF-8
SHELL=/bin/zsh
GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
GTK_IM_MODULE=ibus
XDG_SESSION_CLASS=user
GTK_MODULES=gail:atk-bridge
XMODIFIERS=@im=ibus
YAD_PID=39652
LC_IDENTIFICATION=nl_NL.UTF-8
LC_CTYPE=en_US.UTF-8
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
FT_HOOK_PATHNAME=login-user.d
LC_NUMERIC=nl_NL.UTF-8
TERM=xterm-256color
XDG_MENU_PREFIX=gnome-
COLORTERM=truecolor
LC_TIME=nl_NL.UTF-8
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
QT_ACCESSIBILITY=1
SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
LC_MONETARY=nl_NL.UTF-8
SHLVL=1
OLDPWD=/home/diwang/Projects/MS1
DOCKER_HOST=unix:///run/user/162600/docker.sock
_=/home/diwang/Projects/MS1/./mini_shell
Minishell:exit
f1r6s9% ./mini_shell
Minishell:exit asd
f1r6s9% ./mini_shell
Minishell:exit 12
f1r6s9% echo $?
0
f1r6s9% ./mini_shell
Minishell:exit 
f1r6s9% echo $?     
0
f1r6s9% ./mini_shell
Minishell:exit 12 12
f1r6s9% echo $?     
0
f1r6s9% ./mini_shell
Minishell:cate
Command 'cate' not found.
Minishell:echo $?
127
Minishell:cate
Command 'cate' not found.
Minishell:exit
f1r6s9% echo $?
0
f1r6s9% ./mini_shell
Minishell:exit | cat
f1r6s9% ./mini_shell
Minishell:exit | cat
f1r6s9% ./mini_shell
Minishell:export asd=asd | cat
Minishell:export
declare -x LC_TELEPHONE=nl_NL.UTF-8
declare -x DOTNET_BUNDLE_EXTRACT_BASE_DIR=/home/diwang/.cache/dotnet_bundle_extract
declare -x GDMSESSION=ubuntu
declare -x DESKTOP_SESSION=ubuntu
declare -x PWD=/home/diwang/Projects/MS1
declare -x LC_COLLATE=en_US.UTF-8
declare -x GNOME_DESKTOP_SESSION_ID=this-is-deprecated
declare -x LOGNAME=diwang
declare -x MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
declare -x LC_MEASUREMENT=nl_NL.UTF-8
declare -x XDG_SESSION_TYPE=x11
declare -x SYSTEMD_EXEC_PID=39811
declare -x SSH_AGENT_LAUNCHER=gnome-keyring
declare -x HOME=/home/diwang
declare -x QT_IM_MODULE=ibus
declare -x KRB5CCNAME=FILE:/tmp/krb5cc_162600_zEZjhD
declare -x USER=diwang
declare -x DISPLAY=:0
declare -x FT_HOOK_NAME=login-user
declare -x PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
declare -x LANG=en_US.UTF-8
declare -x LC_NAME=nl_NL.UTF-8
declare -x FEH_PID=39236
declare -x XAUTHORITY=/home/diwang/.Xauthority
declare -x LC_PAPER=nl_NL.UTF-8
declare -x LANGUAGE=en
declare -x SESSION_MANAGER=local/f1r6s9.codam.nl:@/tmp/.ICE-unix/39793,unix/f1r6s9.codam.nl:/tmp/.ICE-unix/39793
declare -x XDG_RUNTIME_DIR=/run/user/162600
declare -x LC_MESSAGES=en_US.UTF-8
declare -x XDG_SESSION_DESKTOP=ubuntu
declare -x XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/diwang/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share:/var/lib/snapd/desktop
declare -x VTE_VERSION=6800
declare -x XDG_CURRENT_DESKTOP=ubuntu:GNOME
declare -x LIBVIRT_DEFAULT_URI=qemu:///system
declare -x XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
declare -x GNOME_TERMINAL_SERVICE=:1.116
declare -x XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
declare -x XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/diwang
declare -x LC_ALL=
declare -x LC_ADDRESS=nl_NL.UTF-8
declare -x SHELL=/bin/zsh
declare -x GPG_AGENT_INFO=/run/user/162600/gnupg/S.gpg-agent:0:1
declare -x GTK_IM_MODULE=ibus
declare -x XDG_SESSION_CLASS=user
declare -x GTK_MODULES=gail:atk-bridge
declare -x XMODIFIERS=@im=ibus
declare -x YAD_PID=39652
declare -x LC_IDENTIFICATION=nl_NL.UTF-8
declare -x LC_CTYPE=en_US.UTF-8
declare -x DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/162600/bus
declare -x DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
declare -x GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/ee8da322_0c60_4315_a0ad_3bfe997dc4e7
declare -x FT_HOOK_PATHNAME=login-user.d
declare -x LC_NUMERIC=nl_NL.UTF-8
declare -x TERM=xterm-256color
declare -x XDG_MENU_PREFIX=gnome-
declare -x COLORTERM=truecolor
declare -x LC_TIME=nl_NL.UTF-8
declare -x XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
declare -x QT_ACCESSIBILITY=1
declare -x SSH_AUTH_SOCK=/run/user/162600/keyring/ssh
declare -x LC_MONETARY=nl_NL.UTF-8
declare -x SHLVL=1
declare -x OLDPWD=/home/diwang/Projects
declare -x DOCKER_HOST=unix:///run/user/162600/docker.sock
declare -x _=/home/diwang/Projects/MS1/./mini_shell
declare -x asd=asd
Minishell:echo hi | cat
hi
Minishell:echo hi | wc
      1       1       3
Minishell:cd | cat
Minishell:pwd
/home/diwang
Minishell:
f1r6s9% ./mini_shell
Minishell:echo hi | cat | echo hu
hu
Minishell:echo hi | cat | echo hu | pwd | pwd | wc
      1       1      26
Minishell:cat | cat |ls
includes  Makefile  mini_shell	src  trash


Minishell:
Minishell:
Minishell:
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Minishell:ds
Command 'ds' not found.
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:asd
Minishell:asd
Minishell:asd
Minishell:asd
Minishell:asd
Minishell:asd
Minishell:asd
Minishell:asd
Command 'asd' not found.
Minishell:
f1r6s9% echo $?
1
f1r6s9% ./mini_shell
Minishell:
f1r6s9% echo $?     
1
f1r6s9% ./mini_shell
Minishell:echo

Minishell:
f1r6s9% echo $?     
1
f1r6s9% ./mini_shell
Minishell:echo $?
0
Minishell:
f1r6s9% ./mini_shell
Minishell:
f1r6s9% echo $?     
1
f1r6s9% ./mini_shell
Minishell:cat | ls
includes  Makefile  mini_shell	src  trash

Minishell:cat | lsMinishell:cat | wc
      0       0       0
Minishell:cat | wc

Minishell:cat | wcMinishell:cat | wc

Minishell:cat | wcMinishell:cat

Minishell:catMinishell:cat



Minishell:catMinishell:
Minishell:
Minishell:
Minishell:cat














asd
asd

Minishell:catMinishell:cat









Minishell:catMinishell:
Minishell:
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:
f1r6s9% ./mini_shell
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:Minishell:./mini_shell 

Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:



Minishell:./mini_shell Minishell:Minishell:./mini_shell Minishell:./mini_shell 

Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 

Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 

Minishell:./mini_shell 
Minishell:./mini_shell Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:
Minishell:./mini_shell 
Minishell:./mini_shell 
Minishell:
Minishell:
Minishell:
f1r6s9% ./mini_shell
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:cate
Command 'cate' not found.
Minishell:echo $?
127
Minishell:touch temp
Minishell:chmod -r temp
Minishell:cat < temp
No permissions to open file. filename: 'temp'
Minishell:echo $?
0
Minishell:rm temp
Minishell:/
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:/
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:/
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:/
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:/
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:
f1r6s9% ./mini_shell
Minishell:/
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:asd
Command 'asd' not found.
Minishell:src
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:Makefile 
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:./asd
Command './asd' not found.
Minishell:echo | echoa
Command 'echoa' not found.
Minishell:echo $?
127
Minishell:echoa | ecjp
Command 'echoa' not found.
Command 'ecjp' not found.
Minishell:echoa | echo
Command 'echoa' not found.

Minishell:echo $?
127
Minishell:echoa | cat
Command 'echoa' not found.

Minishell:echo | cat

Minishell:echoa | cat
Command 'echoa' not found.






Minishell:echo "|"
|
Minishell:echo ">"
>
Minishell:echo "<"
<
Minishell:echo " "
 
Minishell:echo " a"
 a
Minishell:echo "$HOME"
/home/diwang
Minishell:echo '$HOME'
$HOME
Minishell:echo "'$HOME'"
'/home/diwang'
Minishell:echo '"$HOME"'
"$HOME"
Minishell:echo *
*
Minishell:echo *
*
Minishell:echo *
*
Minishell:"echo"

Minishell:echo $HOME$HOME"$HOME"'$HOME'
/home/diwang/home/diwang/home/diwang$HOME
Minishell:echo $HOME$HOME"$HOME"'$HOME'''$HOME
/home/diwang/home/diwang/home/diwang$HOME/home/diwang
Minishell:echo $HOME$HOME"$HOME"'$HOME'''$HOME"'"
/home/diwang/home/diwang/home/diwang$HOME/home/diwang'
Minishell:echo $HOME$
Minishell:"
Syntax error, mismatched quotes
Minishell:echo $HOM

Minishell:echo $
$
Minishell:echo $$
$
Minishell:echo $$$$$$$$
$
Minishell:echo $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$
Minishell:echo $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$as

Minishell:echo $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$a

Minishell:echo $[asd
[asd
Minishell:echo $1sad

Minishell:echo $s2ad

Minishell:echo $*
*
Minishell:echo $/*
/*
Minishell:export asd=""
Minishell:echo $asd

Minishell:export asd='$HOME'
Minishell:echo $asd
$HOME
Minishell:export asd="'"
Minishell:echo $asd
'
Minishell:export asd="'    '"
Minishell:echo $asd
'    '
Minishell:export asd="asd '   asd ' asd'"
Minishell:echo $asd
asd '   asd ' asd'
Minishell:cat $asd
cat: "asd '   asd ' asd'": No such file or directory
Minishell:
f1r6s9% ./mini_shell
Minishell:export asd="-n"
Minishell:echo $asd asd
asdMinishell:export a='$b'
Minishell:export b='$a'
Minishell:echo $a
$b
Minishell:echo "$HOME$HOME $HOME"$HOME' $HOME$HOM $HOME$HOM'
/home/diwang/home/diwang /home/diwang/home/diwang $HOME$HOM $HOME$HOM
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:echo > tmp
Minishell:echo hi > tmp
Minishell:echo hi >> tmp
Minishell:cat tmp
hi
hi
Minishell:echo hi >> tmp
Minishell:cat tmp
hi
hi
hi
Minishell:echo hi >> tmp > tmp2 > tmp3
Minishell:cat tmp2
Minishell:cat tmp3
hi
Minishell:cat tmp1
cat: tmp1: No such file or directory
Minishell:cat tmp
hi
hi
hi
Minishell:>>tmp4
Syntax error;
Minishell:>> tmp4
Syntax error;
Minishell:> tmp4
Syntax error;
Minishell:> tmp4 echo
Syntax error;
Minishell: > tmp4 echo
Syntax error;
Minishell:> tmp4 echo
Syntax error;
Minishell:< Makefile echo
Syntax error;
Minishell:< Makefile cat | cat > tmp
Syntax error;
Minishell:cat | <tmp | cat
syntax error near unexpected token '<'
Minishell:cat | < tmp | cat
syntax error near unexpected token '<'
Minishell:cat | > tmp | cat
syntax error near unexpected token '>'
Minishell:cat | cat  > tmp | cat




Minishell:cat tmp




Minishell:> tmp
Syntax error;
Minishell:touch tmp
Minishell:touch tmp
Minishell:touch tmp
Minishell:touch tmp
Minishell:rm tmp
Minishell:echo >tmp hi huh > tmp2 lol > tmp5
Minishell:cat tmp5

Minishell:cat tmp
Minishell:cat tmp2
Minishell:echo >tmp hi huh > tmp2 lol > tmp5
Minishell:echo >tmp hcat | cat  > tmp | cat
Minishell:cat | cat  > tmp | cat


Minishell:
f1r6s9% rm tmp*
f1r6s9% ./mini_shell 
Minishell:echo >tmp > tmp2 >tmp5 jhi > tmp6
Minishell:
f1r6s9% rm tmp*
f1r6s9% ./mini_shell
Minishell:echo >tmp hji
Minishell:cat tmp

Minishell:pwd > tmp
Minishell:cat tmp
/home/diwang/Projects/MS1
Minishell:
f1r6s9% ./mini_shell
Minishell:< Makefile cat | cat > temp | <Makefile wc
Syntax error;
Minishell:cat < Makefile | cat > temp |wc <Makefile
  64  124 1443
Minishell:cat temp
SOURCES_DIR = src/

SOURCES_FLS	=	main.c \
				minishell/ft_itoa.c \
				minishell/wildcard.c \
				minishell/wildcard1.c \
				minishell/wildcard2.c \
				minishell/ft_clean_exit.c \
				minishell/heredoc.c \
				minishell/quotes.c \
				minishell/utils.c \
				minishell/signal_handlers.c \
				minishell/builtins.c \
				minishell/disable_echo_ctrl.c \
				minishell/builtin_programs1.c \
				minishell/builtin_programs2.c \
				minishell/builtin_programs3.c \
				minishell/parse_stdin.c \
				minishell/env_vars.c \
				minishell/teardown.c \
				minishell/ft_memcpy.c \
				minishell/tokenization.c \
				minishell/tokenization1.c \
				minishell/tokenization2.c \
				minishell/tokenization_write.c \
				minishell/tokenization_calc.c \
				minishell/initialization.c \
				minishell/execution.c \
				minishell/execution1.c \
				minishell/parsing1.c \
				minishell/parsing2.c \
				minishell/linked_list/ft_lstnew.c	\
				minishell/linked_list/ft_lstsize.c	\
				minishell/linked_list/ft_lstadd_back.c	\
				minishell/linked_list/ft_lstlast.c	\


SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_FLS))
OBJS	=	$(SOURCES:%.c=%.o)
NAME = mini_shell

CFLAGS	=	-Wall	-Wextra	-Werror -g -I ./includes/ 

$(NAME): $(OBJS)
	cc $(OBJS) -D_DEFAULT_SOURCE -std=c99 -lreadline -o $(NAME)

all:	$(NAME)
	

re: clean all

clean:
	rm	-f	$(OBJS) $(NAME)

fclean:
	rm	-f	$(OBJS) $(NAME)

fcleanobj:
	rm	-f	$(OBJS)

.phony: make re clean run fclean



Minishell:ls
includes  Makefile  mini_shell	src  temp  tmp	trash
Minishell:rm temp
Minishell:rm tmp
Minishell:<< hi cat
Syntax error;
Minishell:cat << hi 
> 
> 
> 
> 
> 
> 
> 
> 
> hi








Minishell:cat << hi 
> 
Minishell:cat << hi 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
Minishell:cat << hi 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
> 
Minishell:cat << hi 
> $HOME
> "$HOME"
> '$HOME'
> hi
/home/diwang
"/home/diwang"
'/home/diwang'
Minishell:cat << hi"" 
> $HOME
> 
/home/diwang
Minishell:export asd=asd
Minishell:cat > $asd




Minishell:rm asd
Minishell:cat << $asd
> 
> 
> 
> asd



Minishell:cat << $HOME
> $HOME
> /home/diwang
/home/diwang
Minishell:cat << asd << as << dre
> 
> 
> 
> 
> asd
> 
> 
> 
> 
> w
> dre
> as
> 
> pppp
> dre

pppp
Minishell:cat << asd | wc << p
> 
> 
> asd
> 
> 
> 
> 
> wwww
> p
5 1 9
Minishell:cat << asd > tmp | wc << p
> www
> asd
> hhh
> hhh
> p
2 2 8
Minishell:cat tmp
hhh
hhh
Minishell:cat << asd 
> 
> 
> 
> sad
> asd
No permissions to open file. filename: 'asd'
Minishell:rm tmp
Minishell:cat << asd 
> sad
> asd
sad
Minishell:cat << asd 
> asd
Minishell:cat << asd 
> sad
> asd
No permissions to open file. filename: 'asd'
Minishell:cat << asd 
> 
> 
> 
> asd



Minishell:cat << asd | cat << asd
> s
> asd
> www
> asd
s
Minishell:cat << asd | cat << asd
> s
> asd
> www
> asd
www
Minishell:cat << asd | cat << asd
> s
> asd
> www
> asd
s
Minishell:cat | cat |ls
includes  Makefile  mini_shell	src  trash


Minishell:wc | sleep 5



Minishell:sleep 2 | sleep 2
Minishell:sleep 5 | sleep 5
Minishell:echo hi | cat | ls
includes  Makefile  mini_shell	src  trash
Minishell:
Minishell:expr 4? + 4?
expr: non-integer argument
Minishell:expr $? + $?
1024
Minishell:expr $? + $?
0
Minishell:expr $? + $?
512
Minishell:expr $? + $?
0
Minishell:expr $? + $?
512
Minishell:expr $? + $?
0
Minishell:expr $? + $?
512
Minishell:expr $? + $?
0
Minishell:expr $? + $?
512
Minishell:expr $? + $?
0
Minishell:expr $? + $?
512
Minishell:echoa | echoa | echoa
Command 'echoa' not found.
Command 'echoa' not found.
Command 'echoa' not found.
Minishell:echoa | echo $? | echoa
Command 'echoa' not found.
Command 'echoa' not found.
Minishell:echoa | echo $? | cat
Command 'echoa' not found.
127
Minishell:echoa | echo $? | cat
Command 'echoa' not found.
0
Minishell:echoa | echo $? | cat
Command 'echoa' not found.
0
Minishell:echoa | echo $? | cat
Command 'echoa' not found.
0
Minishell:cat | cat                                                                                                 | ca| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat




Minishell:cat | cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| ccat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| catat| cat| cat| cat| cat| cat| cat| cat| cat| 




Minishell:cat | cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat|| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| catat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat| cat










Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
Minishell:
f1r6s9% ./mini_shell
Minishell:touch lo.sh
Minishell:./lo.sh 
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:chmod +x lo.sh 
Minishell:./lo.sh 
hi
Minishell:src
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:mak
Command 'mak' not found.
Minishell:Makefile 
child execve: Permission denied
free(): double free detected in tcache 2
Minishell:
f1r6s9% make
cc -Wall	-Wextra	-Werror -g -I ./includes/    -c -o src/minishell/execution.o src/minishell/execution.c
cc src/main.o src/minishell/ft_itoa.o src/minishell/wildcard.o src/minishell/wildcard1.o src/minishell/wildcard2.o src/minishell/ft_clean_exit.o src/minishell/heredoc.o src/minishell/quotes.o src/minishell/utils.o src/minishell/signal_handlers.o src/minishell/builtins.o src/minishell/disable_echo_ctrl.o src/minishell/builtin_programs1.o src/minishell/builtin_programs2.o src/minishell/builtin_programs3.o src/minishell/parse_stdin.o src/minishell/env_vars.o src/minishell/teardown.o src/minishell/ft_memcpy.o src/minishell/tokenization.o src/minishell/tokenization1.o src/minishell/tokenization2.o src/minishell/tokenization_write.o src/minishell/tokenization_calc.o src/minishell/initialization.o src/minishell/execution.o src/minishell/execution1.o src/minishell/parsing1.o src/minishell/parsing2.o src/minishell/linked_list/ft_lstnew.o src/minishell/linked_list/ft_lstsize.o src/minishell/linked_list/ft_lstadd_back.o src/minishell/linked_list/ft_lstlast.o -D_DEFAULT_SOURCE -std=c99 -lreadline -o mini_shell
f1r6s9% ./mini_shell
Minishell:Makefile 
child execve: Permission denied
Minishell:./lo.sh 
hi
Minishell:/bin/cat








Minishell:mv lo.sh cat
Minishell:cat




Minishell:./cat


Minishell:mv cat  lo.sh
Minishell:./lo.sh 
hi
Minishell:./cat






Minishell:./wc





      5       0       5
Minishell:/bin/wc



      3       0       3
Minishell:./wc



      3       0       3
Minishell:unset PATH
Minishell:
Minishell:
Minishell:cat
child execve: Permission denied
Minishell:
Minishell:
Minishell:cat
child execve: Permission denied
Minishell:cat
hi
huh
Minishell:
f1r6s9% ./mini_shell
Minishell:cat


Minishell:lo.sh
hi
huh
Minishell:
f1r6s9% ./mini_shell
Minishell:lo.sh
hi
huh
Minishell:
f1r6s9% ./mini_shell
Minishell:los.sh
Command 'los.sh' not found.
Minishell:lo.sh
hi
huh
Minishell:unset PATH
Minishell:lo.sh 
hi
huh
Minishell:
f1r6s9% ./mini_shell
Minishell:export PATH=
Minishell:cat
hi
huh
Minishell:wc
Command 'wc' not found.
Minishell:
f1r6s9% ./mini_shell
Minishell:rm cat
Minishell:unset PATH
Minishell:cat
Command 'cat' not found.
Minishell:
f1r6s9% ./mini_shell
Minishell:touch cat
Minishell:chmod +x cat
Minishell:unset PATH
Minishell:cat
child execve: Exec format error
Minishell:cat
hi
huh
Minishell:env | grep PATH
Command 'grep' not found.
Minishell:
f1r6s9% ./mini_shell
Minishell:env | grep PATH
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
FT_HOOK_PATHNAME=login-user.d
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
Minishell:unset PATH
Minishell:export PATH=/home/PATH=/home/diwang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/diwang/.dotnet/tools
Minishell:cat




Minishell:cd src/
Minishell:../lo.sh 
hi
huh
Minishell:
Minishell:
Minishell:

