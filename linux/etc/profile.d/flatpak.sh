# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:26 CST. 
# /etc/profile.d/flatpak.sh - set XDG_DATA_DIRS

flatpak_dirs=$HOME/.local/share/flatpak/exports/share/:/var/lib/flatpak/exports/share/

if [ -z "${XDG_DATA_DIRS}" ]; then
    XDG_DATA_DIRS="$flatpak_dirs:/usr/local/share/:/usr/share/"
elif [ "${XDG_DATA_DIRS#*flatpak}" == ${XDG_DATA_DIRS} ]; then
    XDG_DATA_DIRS="$XDG_DATA_DIRS:$flatpak_dirs"
fi

export XDG_DATA_DIRS
